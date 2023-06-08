#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
  private:
    string title, author, publisher, ISBN;
  public:
    Book(string title, string author, string publisher, string ISBN){
        this->title = title;
        this->author = author;
        this->publisher = publisher;
        this->ISBN = ISBN;
    }
    string getTitle(){
        return title;
    }
    string getAuthor(){
        return author;
    }
    string getPublisher(){
        return publisher;
    }
    string getISBN(){
        return ISBN;
    }
};

class Member {
  private:
    string name, memberID;
    vector<Book> borrowedBooks;
  public:
    Member(string name, string memberID){
        this->name = name;
        this->memberID = memberID;
    }
    void borrowBook(Book book){
        borrowedBooks.push_back(book);
        cout << "Book successfully borrowed" << endl;
    }
    void returnBook(Book book){
        for(int i = 0; i < borrowedBooks.size(); i++){
            if(borrowedBooks[i].getTitle() == book.getTitle() &&
               borrowedBooks[i].getAuthor() == book.getAuthor()){
                borrowedBooks.erase(borrowedBooks.begin() + i);
                cout << "Book successfully returned" << endl;
                return;
            }
        }
        cout << "Book not found, cannot be returned" << endl;
    }
    void displayBorrowedBooks(){
        if(borrowedBooks.empty()){
            cout << "No books borrowed by this member" << endl;
            return;
        }
        cout << "Books borrowed by " << name << ":" << endl;
        for(int i = 0; i < borrowedBooks.size(); i++){
            cout << i+1 << ". " << borrowedBooks[i].getTitle() << " by "
                 << borrowedBooks[i].getAuthor() << endl;
        }
    }
    string getName(){
        return name;
    }
    string getMemberID(){
        return memberID;
    }
};

class Library {
  private:
    vector<Book> books;
    vector<Member> members;
  public:
    void addBook(Book book){
        books.push_back(book);
        cout << "Book successfully added to library" << endl;
    }
    void addMember(Member member){
        members.push_back(member);
        cout << "Member successfully registered" << endl;
    }
    void displayBooks(){
        if(books.empty()){
            cout << "No books in library catalog" << endl;
            return;
        }
        cout << "Books in library catalog:" << endl;
        for(int i = 0; i < books.size(); i++){
            cout << i+1 << ". " << books[i].getTitle() << " by "
                 << books[i].getAuthor() << endl;
        }
    }
    void displayMembers(){
        if(members.empty()){
            cout << "No members registered" << endl;
            return;
        }
        cout << "Members registered:" << endl;
        for(int i = 0; i < members.size(); i++){
            cout << i+1 << ". " << members[i].getName() << " - "
                 << members[i].getMemberID() << endl;
        }
    }
    void borrowBook(string memberID, string bookTitle, string bookAuthor){
        Book book = findBook(bookTitle, bookAuthor);
        if(book.getTitle().empty()){
            cout << "Book not found, cannot be borrowed" << endl;
            return;
        }
        Member member = findMember(memberID);
        if(member.getName().empty()){
            cout << "Member not found, cannot borrow book" << endl;
            return;
        }
        member.borrowBook(book);
    }
    void returnBook(string memberID, string bookTitle, string bookAuthor){ 
        Book book = findBook(bookTitle, bookAuthor); 
        if(book.getTitle().empty()){
             cout << "Book not found, cannot be returned" << endl; return; 
        } 
        Member member = findMember(memberID); 
        if(member.getName().empty())
        { 
            cout << "Member not found, cannot return book" << endl; return; 
        } 
        member.returnBook(book); 
    } 
        
    private: 
        Book findBook(string title, string author){ 
            for(int i = 0; i < books.size(); i++){ 
                if(books[i].getTitle() == title && books[i].getAuthor() == author){
                        return books[i]; 
                } 
            } 
            return Book("", "", "", ""); 
        } 
        
        Member findMember(string memberID){ 
            for(int i = 0; i < members.size(); i++){ 
                if(members[i].getMemberID() == memberID){ 
                    return members[i]; 
                } 
            } 
            return Member("",""); 
        } 
};
int main(){
    Library library;
    bool quit = false;
    while(!quit){
        cout << "Welcome to the library management system" << endl;
        cout << "Select an option:" << endl;
        cout << "1. Add a new book" << endl;
        cout << "2. Add a new member" << endl;
        cout << "3. Display all books" << endl;
        cout << "4. Display all members" << endl;
        cout << "5. Borrow a book" << endl;
        cout << "6. Return a book" << endl;
        cout << "7. Quit" << endl;
        int choice;
        cin >> choice;
        switch(choice){
            case 1:{
                string title, author, publisher, ISBN;
                cout << "Enter book details:" << endl;
                cout << "Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Author: ";
                getline(cin, author);
                cout << "Publisher: ";
                getline(cin, publisher);
                cout << "ISBN: ";
                getline(cin, ISBN);
                Book book(title, author, publisher, ISBN);
                library.addBook(book);
                break;
            }
            case 2:{
                string name, memberID;
                cout << "Enter member details:" << endl;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Member ID: ";
                getline(cin, memberID);
                Member member(name, memberID);
                library.addMember(member);
                break;
            }
            case 3:{
                library.displayBooks();
                break;
            }
            case 4:{
                library.displayMembers();
                break;
            }
            case 5:{
                string memberID, bookTitle, bookAuthor;
                cout << "Enter member ID: ";
                cin.ignore();
                getline(cin, memberID);
                cout << "Enter book details:" << endl;
                cout << "Title: ";
                getline(cin, bookTitle);
                cout << "Author: ";
                getline(cin, bookAuthor);
                library.borrowBook(memberID, bookTitle, bookAuthor);
                break;
            }
            case 6:{
                string memberID, bookTitle, bookAuthor;
                cout << "Enter member ID: ";
                cin.ignore();
                getline(cin, memberID);
                cout << "Enter book details:" << endl;
                cout << "Title: ";
                getline(cin, bookTitle);
                cout << "Author: ";
                getline(cin, bookAuthor);
                library.returnBook(memberID, bookTitle, bookAuthor);
                break;
            }
            case 7:{
                quit = true;
                break;
            }
            default:{
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
