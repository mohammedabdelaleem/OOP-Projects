#include "Book.h"
int Book::count=0;

Book::Book()
{
    title="";
    isbn="";
    id=++count;
    category="";
    averageRating=0.0;
    //User author; // auther=new User;
    hasAuthor=false;
    numRates=0;
    sumRates=0.0;
    //    cout<<id<<endl;
}
Book::Book(string  title="", string isbn="", string category="")
{
    this->title=title;
    this->isbn=isbn;
    this->category=category;
    id=++count;
    averageRating=0.0;
    // User author;
    hasAuthor=false;
    numRates=0;
    sumRates=0.0;
    // cout<<id<<endl;
}
Book::Book(const Book& b)
{
    title=b.title;
    id=b.id;
    isbn=b.isbn;
    category=b.category;
    averageRating=b.averageRating;
    // author=b.author;
    if(b.hasAuthor)
    {
        /*author=new User;=>
        hasAuthor=true;
        author=b.author;*/ //لان بالطريقة دي لما ننادي الcopy constructor لل book في ال main => هينادي الempty constructor for User
        setAuthor(*b.author);// this is the best way.
    }
    numRates=b.numRates;
    sumRates=b.sumRates;
}

////////////////////////////////////
Book& Book::operator=(const Book& b)
{
    if (this == &b)
    {
        return *this;
    }
    title = b.title;
    isbn = b.isbn;
    id = b.id;
    category = b.category;
    averageRating = b.averageRating;
   if(hasAuthor)
    {
        delete author;
    }
    if (b.hasAuthor)
    {
        author = new User(*b.author);
        hasAuthor = true;
    }
    else
    {
        author = nullptr;
        hasAuthor = false;
    }
    numRates = b.numRates;
    sumRates = b.sumRates;
    return *this;
}
/////////////////////////////
Book ::~Book()
{
    delete author;
}
void Book::setTitle(string title)
{
    this->title=title;
}
string Book:: getTitle() const
{
    return title;
}

void Book::setIsbn(string )
{
    this->isbn=isbn;
}
string Book::getIsbn() const
{
    return isbn;
}

void Book::setId(int id)
{
    this->id=id;
}

int Book::getId() const
{
    return id;
}

void Book::setCategory(string category)
{
    this->category=category;
}
string Book::getCategory()const
{
    return category;
}

void Book::setAuthor(const User &user)
{
    hasAuthor=true;
    author=new User(user);//copy constructor...//this is the only time that occurs creation for user objet
}

User Book::getAuthor() const
{
    return *author;
}

void Book::rateBook(double rating)
{
    numRates++;
    sumRates+=rating;
    averageRating=sumRates/numRates;
}
double Book::getAverageRating () const
{
    return averageRating;
}
bool Book::operator==(const Book&b2)
{
    return(title==b2.title && isbn==b2.isbn && category==b2.category && id==b2.id && *author==*(b2.author)); //Focus
}

istream &operator>>( istream &input,Book &b)
{
    cout<<"Enter Book "<<b.getId()<<" Information in this Order : \n";
    cout<<"Title Isbn Category(Space Separated)\n";
    input>>b.title>>b.isbn>>b.category;
    //  b.averageRating=0.0;
    return input;
}

ostream &operator<<(ostream &output, const Book &b)
{
    output<<"Books "<<b.getId()<<" information :\n";
    output<<"Title: "<<b.getTitle()
          <<" | isbn: "<<b.getIsbn()
          <<" | Id: "<<b.getId()
          <<" | category: "<<b.getCategory()
          <<" | Avg Rat: "<<b.getAverageRating()<<endl;
    //if book has an author print him/her
    if(b.hasAuthor==true)
    {
         output<<"Book's "<<b.getId()<<" Author: /n"<<b.getAuthor()<<endl;
    }
    else
    {
               output<<"No Authur "<<endl;
    }
    output<<"========================================\n";
    return output;
}


