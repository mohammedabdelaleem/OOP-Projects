#include "User.h"
int User::count=0;
//////////////////
User::User()
{
    name="";
    age=0;
    password="";
    email="";
    id=++count;
    //cout<<id<<endl;
}
///////////////
User::User(string name,int age,string email,string password)
{
    this->name=name;
    this->age=age;
    this->email=email;
    this->password=password;
    id=++count;
    //   cout<<id<<endl;
}
///////////
User::User(const User&user)
{
    name=user.name;
    age=user.age;
    password=user.password;
    email=user.email;
    id=user.id;// remember it ,you assign not initialize
}
///////////////
User::~User()
{
    //dtor
}
////////
void User::setName(string name)
{
    this->name=name;
}
//////////
string User::getName()const
{
    return name;
}
////////////
void User::setPassword(string password)
{
    this->password=password;
}
/////////////
string User::getPassword()const
{
    return password;
}
///////////////
void User::setEmail(string email)
{
    this->email=email;
}
//////////////
string User::getEmail()const
{
    return email;
}
/////////////
void User::setAge(int age)
{
    this->age=age;
}
//////////////
int User::getAge()const
{
    return age;
}
//////////////
void User::setId(int id)
{
    this->id=id;
}
/////////////??
int User::getId()const
{
    return (this->id);//
}
/////////////
void User::Display ()const
{
    cout<<"**********************\n\a";
    cout<<"Name :"<<getName()<<endl;
    cout<<"Id :"<<getId()<<endl;
    cout<<"Age :"<<getAge()<<endl;
    cout<<"Email :"<<getEmail()<<endl;
    cout<<"\n**********************\n";
}
//////////////
bool User:: operator==(const User& u)//== ! =
{
    return (name==u.name &&  age==u.age && email==u.email && password==u.password);
}
///////
void User::operator=(const User& user)
{
     name=user.name;
    age=user.age;
    password=user.password;
    email=user.email;
}
/////////////
istream &operator>>( istream &input, User &user)
{
   cout<<"Enter User"<<user.id<<" Information in this Order\n"<<
        "NAME AGE EMAIL PASSWORD"<<"(Separate By Space)\n";
    input>>user.name>>user.age>>user.email>>user.password;
    return input; //Don't forget//cin is Ok but not a clean code
}
/////////////////
ostream &operator<<(ostream &output, const User &user)
{
    output<<"==========User"<<user.id<<"=========Information\n";
    output<<"Name: "<<user.name<<"\tID: "<<user.id<<endl<<
          "Age: "<<user.age<<"\t Email:"<<user.email<<endl;
    output<<"==================================\n";
    return output;
}
