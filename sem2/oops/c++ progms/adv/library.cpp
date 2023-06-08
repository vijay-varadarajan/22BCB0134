#include <iostream>
#include <string>
#include <vector>

class Book {
public:
    Book(const std::string& title, const std::string& author, int id)
        : title(title), author(author), id(id), borrowed(false) {}

    const std::string& getTitle() const {
        return title;
    }

    const std::string& getAuthor() const {
        return author;
    }

    int getId() const {
        return id;
    }

    bool isBorrowed() const {
        return borrowed;
    }

    void setBorrowed(bool status) {
        borrowed = status;
    }

private:
    std::string title;
    std::string author;
    int id;
    bool borrowed;
};

class LibraryMember {
public:
    LibraryMember(const std::string& name, int id)
        : name(name), id(id) {}

    const std::string& getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

private:
    std::string name;
    int id;
};

class LibraryCatalog {
public:
    void addBook(const std::string& title, const std::string& author, int id) {
        books.emplace_back(title, author, id);
        std::cout << "Added book: " << title << std::endl;
    }

    void registerMember(const std::string& name, int id) {
        members.emplace_back(name, id);
    }

    void borrowBook(int memberId, int bookId) {
        LibraryMember* member = findMemberById(memberId);
        Book* book = findBookById(bookId);

        if (member && book && !book->isBorrowed()) {
            book->setBorrowed(true);
            std::cout << "Book \"" << book->getTitle() << "\" is borrowed by member \"" << member->getName() << "\"" << std::endl;
        } else {
            std::cout << "Unable to borrow the book." << std::endl;
        }
    }

    void returnBook(int memberId, int bookId) {
        LibraryMember* member = findMemberById(memberId);
        Book* book = findBookById(bookId);

        if (member && book && book->isBorrowed()) {
            book->setBorrowed(false);
            std::cout << "Book \"" << book->getTitle() << "\" is returned by member \"" << member->getName() << "\"" << std::endl;
        } else {
            std::cout << "Unable to return the book." << std::endl;
        }
    }

    void displayBookDetails() const {
        std::cout << "Books in the library:" << std::endl;
        for (const auto& book : books) {
            std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor()
                      << ", ID: " << book.getId() << ", Borrowed: " << (book.isBorrowed() ? "Yes" : "No") << std::endl;
        }
    }

    void displayMemberDetails() const {
        std::cout << "Library members:" << std::endl;
        for (const auto& member : members) {
            std::cout << "Name: " << member.getName() << ", ID: " << member.getId() << std::endl;
        }
    }

private:
    std::vector<Book> books;
    std::vector<LibraryMember> members;

    Book* findBookById(int id) {
        for (auto& book : books) {
            if (book.getId() == id) {
                return &book;
            }
        }
        return nullptr;
    }

    LibraryMember* findMemberById(int id) {
        for (auto& member : members) {
            if (member.getId() == id) {
                return &member;
            }
        }
        return nullptr;
    }
};

int main() {
    LibraryCatalog catalog;

    // Add books
    catalog.addBook("The Great Gatsby", "F. Scott Fitzgerald", 1);
    catalog.addBook("To Kill a Mockingbird", "Harper Lee", 2);
    catalog.addBook("1984", "George Orwell", 3);

    // Register members
    catalog.registerMember("John Doe", 1001);
    catalog.registerMember("Jane Smith", 1002);

    // Perform library operations
    catalog.borrowBook(1001, 1);
    catalog.borrowBook(1002, 2);
    catalog.borrowBook(1001, 2);
    catalog.returnBook(1002, 2);
    catalog.returnBook(1001, 1);

    // Display book and member details
    catalog.displayBookDetails();
    catalog.displayMemberDetails();

    return 0;
}
