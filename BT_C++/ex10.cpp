#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookName;
    string authorName;
    int publishYear;
    int numberBook;

public:
    Book(string book_Name, string author_Name, int publish_Year = 0, int number_Book = 0);
    void showBookInformation();
    void borrowBooks();
    void giveBook();
};

Book::Book(string book_Name, string author_Name, int publish_Year, int number_Book) {
        bookName = book_Name;
        authorName = author_Name;
        publishYear = publish_Year;
        numberBook = number_Book;
}

void Book::showBookInformation(){
    printf("INFORMATION\n");
    printf("Name: %s\n",bookName.c_str());
    printf("Author: %s\n",authorName.c_str());
    printf("Year: %d\n",publishYear);
    printf("Number: %d\n",numberBook);
}

void Book::borrowBooks() {
        if (numberBook > 0) {
            numberBook--;
            printf("You borrowed the book: %s\n",bookName.c_str());
            printf("Remaining: %d books %s\n",numberBook,bookName.c_str());
           
        } else {
            printf("Book: %s over \n",bookName.c_str());
        }
} 

void Book::giveBook() {
        numberBook++;
        printf("You have returned the book: %s\n", bookName.c_str());
        printf("Remaining: %d books %s\n",numberBook,bookName.c_str());
}

int main(int argc, char const *argv[]) {
    
    Book book1("Harry Potter", "J.K. Rowling", 2001, 5);
    book1.showBookInformation();
    book1.borrowBooks();
    book1.giveBook();
   
    return 0;
}
