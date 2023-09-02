#include "BookList.h"
BookList::BookList()
{
    capacity=booksCount=0;
}

BookList::BookList(int capacity)
{
    this->capacity=capacity;
    if(capacity<1)
        capacity=1;
    books=new Book[capacity]; //this line calls Book's empty constructor => number of capacity
    booksCount=0;
}
void BookList::addBook(const Book& book) // at the end of the array.
{
    if(booksCount<capacity)
    {
        books[booksCount]=book;//we need to make an assignment operator because of pointer
        books[booksCount].setId(booksCount+1);//to solve the problem in prameteriz constructor
        booksCount++;
    }

    else
        cout<<"Full Size\n";
    // expanedCapacity();
}

Book* BookList::searchBook(string name)
{
    for(int i=0; i<booksCount; i++)
    {
        if(books[i].getTitle()==name)
            return &books[i];
    }
    return nullptr;
}

Book* BookList::searchBook(int id)//عملنا الreturn * لان ممكن يكون مش موجود
{
    for(int i=0; i<booksCount; i++)
    {
        if(books[i].getId()==id)
            return &books[i];
    }
    return nullptr;
}

void BookList::deleteBook(int id) //delete a book
{
    for(int i=0; i<booksCount; i++)
    {
        if(books[i].getId()==id)
        {
            for(int j=i; j<booksCount-1; j++)
            {
                books[j]=books[j+1];
                books[j].setId(j+1);//1 2 3 4 => (3) 1 2 3 !=> 1 2 4
                //j+1 =>because of array index
            }
            booksCount--;
            break;
        }
    }
}
///////////////////////////////
Book BookList::getTheHighestRatedBook()
{
    int index=0; //number for the first index (by default the max index)
    double highestRate=books[0].getAverageRating();//(by default the max rating)
    for(int i=1; i<booksCount; i++)
    {
        if(books[i].getAverageRating()>highestRate)
        {
            highestRate=books[i].getAverageRating();
            index=i;
        }
    }
    return books[index];
}
///////////////////
///////////////////////////////
Book BookList::getThelowestRatedBook()
{
    int index=0; //number for the first index (by default the max index)
    double lowestRate=books[0].getAverageRating();//(by default the max rating)
    for(int i=1; i<booksCount; i++)
    {
        if(books[i].getAverageRating()<lowestRate)
        {
            lowestRate=books[i].getAverageRating();
            index=i;
        }
    }
    return books[index];
}
/////////////////
void BookList::getBooksForUser(const User &user) // get all books of this author
{
    bool found=false;
    for(int i=0; i<booksCount; i++)
    {
        if(books[i].getAuthor()==user)//==op
        {
            found=true;
            cout<<books[i];
        }
    }
    if(!found)
        cout<<"not found\n\a";
}
/////////////////////////////////////////////////
Book& BookList::operator[] (int position)
{
    if(position>=0 && position<=booksCount)
        return books[position];
    else
    {
        cout<<"not found\n\a";
        exit(0);
    }

    // return;
}
ostream&operator<<(ostream &output,const BookList &bookList ) //to display all books
{
    for(int i=0; i<bookList.booksCount; i++)
        output<<bookList.books[i];
    return output;
}

BookList::~BookList()
{
    delete []books;
}
