#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book
{
public:
 

     Book(Book &o) = delete;

     Book( string title) :  title(title) {}

     string getTitre()
     {
          return title;
     }


private:
     string title;
};

class Copy
{
public:
     Copy(Book &o) : book(o) { cout << "new copy from a book" << endl; }
     Copy( Copy &e) : book(e.book) { cout << "Copy from another copy" << endl; }
   
     const Book & getBook()
     {
          return book;
     }

private:
     Book& book;
};

