#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stack>
#include <map>

using namespace std;

struct Node {
    char symbol;
    bool nullable;
    set<int> firstpos;
    set<int> lastpos;
    Node* left;
    Node* right;

    Node(char sym) : symbol(sym), nullable(false), left(nullptr), right(nullptr) {}
};

class RegexTree {
private:
    Node* root;
    map<int, set<int>> followpos;
    int position;

public:
    RegexTree(string regex) : root(nullptr), position(1) {
        root = buildTree(regex);
        if (!root) {
            cout << "Error building syntax tree." << endl;
            return;
        }
        computeNullableFirstLast(root);
        computeFollowpos(root);
    }

    // Function to build the syntax tree from the regular expression
    Node* buildTree(string regex) {
        stack<Node*> nodeStack;
        stack<char> operatorStack;

        for (char c : regex) {
            if (isalpha(c)) {
                Node* node = new Node(c);
                node->firstpos.insert(position);
                node->lastpos.insert(position);
                position++;
                nodeStack.push(node);
            } else if (c == '(') {
                operatorStack.push(c);
            } else if (c == ')') {
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                    char op = operatorStack.top();
                    operatorStack.pop();
                    if (op == '.' || op == '+') {
                        if (nodeStack.size() < 2) {
                            cout << "Error: Invalid regular expression structure." << endl;
                            return nullptr;
                        }
                        Node* right = nodeStack.top(); nodeStack.pop();
                        Node* left = nodeStack.top(); nodeStack.pop();
                        Node* node = new Node(op);
                        node->left = left;
                        node->right = right;
                        nodeStack.push(node);
                    }
                }
                if (!operatorStack.empty() && operatorStack.top() == '(') {
                    operatorStack.pop();
                }
            } else if (c == '.' || c == '+') {
                while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c)) {
                    char op = operatorStack.top();
                    operatorStack.pop();
                    if (nodeStack.size() < 2) {
                        cout << "Error: Invalid regular expression structure." << endl;
                        return nullptr;
                    }
                    Node* right = nodeStack.top(); nodeStack.pop();
                    Node* left = nodeStack.top(); nodeStack.pop();
                    Node* node = new Node(op);
                    node->left = left;
                    node->right = right;
                    nodeStack.push(node);
                }
                operatorStack.push(c);
            } else if (c == '*') {
                if (nodeStack.empty()) {
                    cout << "Error: Invalid regular expression structure." << endl;
                    return nullptr;
                }
                Node* child = nodeStack.top(); nodeStack.pop();
                Node* node = new Node(c);
                node->left = child;
                nodeStack.push(node);
            }
        }

        while (!operatorStack.empty()) {
            char op = operatorStack.top();
            operatorStack.pop();
            if (nodeStack.size() < 2 && (op == '.' || op == '+')) {
                cout << "Error: Invalid regular expression structure." << endl;
                return nullptr;
            }
            Node* right = nodeStack.top(); nodeStack.pop();
            Node* left = nodeStack.top(); nodeStack.pop();
            Node* node = new Node(op);
            node->left = left;
            node->right = right;
            nodeStack.push(node);
        }

        return nodeStack.top();
    }

    int precedence(char c) {
        if (c == '*') return 3;
        if (c == '.') return 2;
        if (c == '+') return 1;
        return 0;
    }

    void computeNullableFirstLast(Node* node) {
        if (!node) return;

        computeNullableFirstLast(node->left);
        computeNullableFirstLast(node->right);

        if (isalpha(node->symbol)) {
            node->nullable = false;
        } else if (node->symbol == '*') {
            node->nullable = true;
            node->firstpos = node->left->firstpos;
            node->lastpos = node->left->lastpos;
        } else if (node->symbol == '.') {
            node->nullable = node->left->nullable && node->right->nullable;
            node->firstpos = node->left->firstpos;
            if (node->left->nullable) {
                node->firstpos.insert(node->right->firstpos.begin(), node->right->firstpos.end());
            }
            node->lastpos = node->right->lastpos;
            if (node->right->nullable) {
                node->lastpos.insert(node->left->lastpos.begin(), node->left->lastpos.end());
            }
        } else if (node->symbol == '+') {
            node->nullable = node->left->nullable || node->right->nullable;
            node->firstpos = node->left->firstpos;
            node->firstpos.insert(node->right->firstpos.begin(), node->right->firstpos.end());
            node->lastpos = node->left->lastpos;
            node->lastpos.insert(node->right->lastpos.begin(), node->right->lastpos.end());
        }
    }

    void computeFollowpos(Node* node) {
        if (!node) return;

        computeFollowpos(node->left);
        computeFollowpos(node->right);

        if (node->symbol == '.') {
            for (int i : node->left->lastpos) {
                followpos[i].insert(node->right->firstpos.begin(), node->right->firstpos.end());
            }
        } else if (node->symbol == '*') {
            for (int i : node->lastpos) {
                followpos[i].insert(node->firstpos.begin(), node->firstpos.end());
            }
        }
    }

    void printFirstLastPos() {
        if (!root) {
            cout << "No syntax tree root found." << endl;
            return;
        }

        cout << "firstpos(root) = { ";
        for (int pos : root->firstpos) {
            cout << pos << " ";
        }
        cout << "}\n";

        cout << "lastpos(root) = { ";
        for (int pos : root->lastpos) {
            cout << pos << " ";
        }
        cout << "}\n";
    }

    void printFollowpos() {
        if (followpos.empty()) {
            cout << "No followpos found." << endl;
        } else {
            for (const auto& entry : followpos) {
                cout << "followpos(" << entry.first << ") = { ";
                for (int pos : entry.second) {
                    cout << pos << " ";
                }
                cout << "}\n";
            }
        }
    }
};

int main() {
    string regex;
    cout << "Enter Regular Expression: ";
    cin >> regex;

    RegexTree regexTree(regex);

    regexTree.printFirstLastPos();
    regexTree.printFollowpos();

    return 0;
}
