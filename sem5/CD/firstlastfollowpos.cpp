#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<stack>

using namespace std;

struct Node {
    char symbol;
    int pos;
    bool nullable;
    set<int> firstpos;
    set<int> lastpos;
    Node* left;
    Node* right;

    Node(char sym, int p = 0) : symbol(sym), pos(p), nullable(false), left(nullptr), right(nullptr) {
        if (p > 0) {
            firstpos.insert(p);
            lastpos.insert(p);
        }
    }
};

set<int> setUnion(const set<int>& a, const set<int>& b) {
    set<int> result = a;
    result.insert(b.begin(), b.end());
    return result;
}

// Utility function to check if a character is an operator
bool isOperator(char c) {
    return c == '*' || c == '.' || c == '+';
}

// Utility function to check precedence of operators
int precedence(char c) {
    if (c == '*') return 3;
    if (c == '.') return 2;
    if (c == '+') return 1;
    return 0;
}

// Convert infix regular expression to postfix notation
string infixToPostfix(const string& re) {
    stack<char> opStack;
    string postfix;

    for (char c : re) {
        if (c == 'a' || c == 'b' || c == 'c') {
            postfix += c;
        } else if (c == '(') {
            opStack.push(c);
        } else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Remove '(' from stack
        } else if (isOperator(c)) {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

Node* buildSyntaxTree(const string& re) {
    string postfix = infixToPostfix(re);
    vector<Node*> stack;
    int pos = 1;

    for (char ch : postfix) {
        if (ch == 'a' || ch == 'b' || ch == 'c') {
            stack.push_back(new Node(ch, pos++));
        } else if (ch == '.') {
            Node* right = stack.back();
            stack.pop_back();
            Node* left = stack.back();
            stack.pop_back();

            Node* node = new Node('.', 0);
            node->left = left;
            node->right = right;
            node->nullable = left->nullable && right->nullable;
            node->firstpos = left->nullable ? setUnion(left->firstpos, right->firstpos) : left->firstpos;
            node->lastpos = right->nullable ? setUnion(left->lastpos, right->lastpos) : right->lastpos;
            stack.push_back(node);
        } else if (ch == '+') {
            Node* right = stack.back();
            stack.pop_back();
            Node* left = stack.back();
            stack.pop_back();

            Node* node = new Node('+', 0);
            node->left = left;
            node->right = right;
            node->nullable = left->nullable || right->nullable;
            node->firstpos = setUnion(left->firstpos, right->firstpos);
            node->lastpos = setUnion(left->lastpos, right->lastpos);
            stack.push_back(node);
        } else if (ch == '*') {
            Node* child = stack.back();
            stack.pop_back();
            Node* node = new Node('*', 0);
            node->left = child;
            node->nullable = true;
            node->firstpos = child->firstpos;
            node->lastpos = child->lastpos;
            stack.push_back(node);
        }
    }

    if (stack.size() != 1) {
        cerr << "Invalid regular expression" << endl;
        return nullptr;
    }
    return stack.back();
}

void computeFollowPos(Node* node, map<int, set<int>>& followpos) {
    if (!node) return;
    if (node->symbol == '.') {
        for (int i : node->left->lastpos) {
            followpos[i] = setUnion(followpos[i], node->right->firstpos);
        }
    } else if (node->symbol == '*') {
        for (int i : node->lastpos) {
            followpos[i] = setUnion(followpos[i], node->firstpos);
        }
    }

    computeFollowPos(node->left, followpos);
    computeFollowPos(node->right, followpos);
}

void printPositions(Node* root, map<int, set<int>>& followpos) {
    if (!root) return;
    printPositions(root->left, followpos);
    if (root->pos > 0) {
        cout << "Position " << root->pos << ": symbol = " << root->symbol << endl;
        cout << "Firstpos: ";
        for (int i : root->firstpos) cout << i << " ";
        cout << endl;
        cout << "Lastpos: ";
        for (int i : root->lastpos) cout << i << " ";
        cout << endl;
        cout << "Followpos: ";
        for (int i : followpos[root->pos]) cout << i << " ";
        cout << endl;
    }
    printPositions(root->right, followpos);
}

int main() {
    string re = "((a+b)*.(a.c)*)";
    Node* root = buildSyntaxTree(re);
    if (root == nullptr) {
        cerr << "Failed to build syntax tree" << endl;
        return 1;
    }
    map<int, set<int>> followpos;
    computeFollowPos(root, followpos);
    printPositions(root, followpos);
    return 0;
}
