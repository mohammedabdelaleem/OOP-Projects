#include "UserList.h"

UserList::UserList()
{
    capacity=0;
    usersCount=0;
//users=new User[capacity]; //capacity=>0  || this line not in Use
}

UserList::UserList(int capacity)
{
    this->capacity=capacity;
    if(capacity<1)
        capacity=1;
    users=new User[capacity]; //this line calls User's empty constructor => number of capacity
    usersCount=0;
}

UserList::~UserList()
{
    delete []users;
}

void UserList::addUser(User &user)
{
    if(usersCount<capacity)
    {
        users[usersCount]=user;//we don't need to make an assignment operator because of pointer
        users[usersCount].setId(usersCount+1);//to solve the problem in prameterise constructor
        usersCount++;
    }

    else
        cout<<"Full Size\n";
    // expanedCapacity();
}

User* UserList::searchUser(string name)
{
    for(int i=0; i<usersCount; i++)
    {
        if(users[i].getName()==name)
            return &users[i];
    }
    return nullptr;
}

User* UserList::searchUser(int id)
{
    for(int i=0; i<usersCount; i++)
    {
        if(users[i].getId()==id)
            return &users[i];
    }
    return nullptr;
}

void UserList::deleteUser(int id)
{
    for(int i=0; i<usersCount; i++)
    {
        if(users[i].getId()==id)
        {
            for(int j=i; j<usersCount-1; j++)
            {
                users[j]=users[j+1];
                users[j].setId(j+1);//1 2 3 4 => (3) 1 2 3 !=> 1 2 4
                //j+1 =>because of array's index
            }
            usersCount--;
            break;
        }
    }
}
//importance note
ostream &operator<<(ostream& output,const UserList &userlist)
{
    for(int i=0; i<userlist.usersCount; i++)
    {
        output<<userlist.users[i];
    }
    return output;
}
