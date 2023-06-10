#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;

class Paper {
    string title;
    string author;
    int publicationYear;
    string keywords[MAX];
    int numKeywords;

public:
    void InputDetails() {
        cout << "Enter the title of the paper: ";
        cin >> title;

        cout << "Enter the author name: ";
        cin >> author;

        cout << "Enter the publication year: ";
        cin >> publicationYear;

        cout << "Enter the number of keywords (up to 5): ";
        cin >> numKeywords;

        for (int i = 0; i < numKeywords; i++) {
            cout << "Enter keyword " << i + 1 << ": ";
            cin >> keywords[i];
        }
    }

    void SearchByTitle(string searchTitle) {
        if (title == searchTitle) {
            DisplayDetails();
        }
    }

    void SearchByAuthor(string searchAuthor) {
        if (author == searchAuthor) {
            DisplayDetails();
        }
    }

    void SearchByYear(int searchYear) {
        if (publicationYear == searchYear) {
            DisplayDetails();
        }
    }

    void SearchByKeyword(string searchKeyword) {
        for (int i = 0; i < numKeywords; i++) {
            if (keywords[i] == searchKeyword) {
                DisplayDetails();
                break;
            }
        }
    }

private:
    void DisplayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "Keywords: ";
        for (int i = 0; i < numKeywords; i++) {
            cout << keywords[i] << " ";
        }
        cout << endl;
        cout << "----------------------" << endl;
    }
};

int main() {
    Paper papers[MAX];
    int numPapers;

    cout << "Enter the number of research papers: ";
    cin >> numPapers;
    

    // Input details of research papers
    for (int i = 0; i < numPapers; i++) {
        cout << "Enter details for paper " << i + 1 << ":" << endl;
        papers[i].InputDetails();
        cout << endl;
    }

    // Perform search operations
    string searchTitle;
    string searchAuthor;
    string searchKeyword;
    int searchYear;
    int choice = 1;

    while (choice != 0){
        cout << "Enter 1 to search papers by title\nEnter 2 to search papers by author\nEnter 3 to search papers by year\nEnter 4 to search papers by keyword\nEnter 0 to exit search\nYour choice: ";
        cin >> choice;
        if (choice == 0)
            break;
            
        switch(choice){
            case 1:
                cout << "Search papers by title: ";
                cin >> searchTitle;
                cout << endl << "Search results:" << endl;
                for (int i = 0; i < numPapers; i++)
                    papers[i].SearchByTitle(searchTitle);
                break;

            case 2:
                cout << "Search papers by author: ";
                cin >> searchAuthor;
                cout << endl << "Search results:" << endl;
                for (int i = 0; i < numPapers; i++)
                    papers[i].SearchByAuthor(searchAuthor);
                break;

            case 3:
                cout << "Search papers by year: ";
                cin >> searchYear;
                cout << endl << "Search results:" << endl;
                for (int i = 0; i < numPapers; i++)
                    papers[i].SearchByYear(searchYear);
                break;

            case 4:
                cout << "Search papers by keyword: ";
                cin >> searchKeyword;
                cout << endl << "Search results:" << endl;
                for (int i = 0; i < numPapers; i++)
                    papers[i].SearchByKeyword(searchKeyword);
                break;

            default: 
                cout << "Invalid choice";
                break;
        }
    }

    return 0;
}
