#ifndef BOOK_H
#define BOOK_H
#include"User.h"
using namespace std;

class Book
{
private:
    string title;
    string isbn;
    int id;
    string category;
    double averageRating;
    User *author; //aggregation because of leak memory
    bool hasAuthor;
    int numRates;
    double sumRates;
public:
    static int count;
    Book();
    Book(string, string, string );
    Book(const Book& );
    ~Book();
    void setTitle(string );
    string getTitle() const ;
    void setIsbn(string );
    string getIsbn() const;
    void setId(int);
    int getId() const;
    void setCategory(string );
    string getCategory()const;
    void setAuthor(const User & );
    User getAuthor() const;
    void rateBook(double );
    double getAverageRating () const;
    bool operator==(const Book&);
    friend ostream &operator<<(ostream &, const Book &);
    friend istream &operator>>( istream &, Book &);
    Book& operator=(const Book& );
};

#endif // BOOK_H

