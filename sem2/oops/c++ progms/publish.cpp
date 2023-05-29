#include <iostream>

using namespace std;

class Publication{
    string title;
    float price;

    public:
        void put_data(){
            cout << "Title: " << this->title;
            cout << "Price: " << this->price;
        }

        void get_data(string title, float price){
            this -> title = title;
            this -> price = price;
        }
};

class Book: public Publication{
    int page_count;

    public:
        void put_data(){
            Publication::put_data();
            cout << "Page count: " << this->page_count << endl;
        }   

        void get_data(string title, float price, int page_count){
            Publication::get_data(title, price);
            this -> page_count = page_count;
        }
};

class Tape: public Publication{
    float playing_time_in_minutes;

    public:
        void put_data(){
            Publication::put_data();
            cout << "Playing time: " << this->playing_time_in_minutes << endl;
        }

        void get_data(string title, float price, float playing_time_in_minutes){
            Publication::get_data(title, price);
            this -> playing_time_in_minutes = playing_time_in_minutes;
        }
};

int main(void){
    Book book1;
    book1.get_data("Title one", 234, 400);

    Book book2;
    book2.get_data("Title two", 34, 20);

    Tape tape1;
    tape1.get_data("Tape one", 12.2, 23.5);
    
    Tape tape2;
    tape2.get_data("Tape two", 1.5, 600);

    book1.put_data();
    book2.put_data();

    tape1.put_data();
    tape2.put_data();
}
