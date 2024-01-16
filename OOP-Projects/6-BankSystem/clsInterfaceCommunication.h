
//Abstract Class Revision : 
/*An abstract class in object - oriented programming is a class that cannot be instantiated on its own but serves
as a blueprint for other classes.It acts as a base class from which other classes can be derived.
The purpose of an abstract class is to define common attributes and behaviors that derived classes should implement.

Here are some key characteristics and features of an abstract class :

    *Cannot be instantiated : You cannot create objects of an abstract class directly.It is meant to be subclassed.

    *May contain abstract and non - abstract members : An abstract class can have both abstract and non - abstract members(methods and properties).Abstract members are declared without an implementation and must be implemented in the derived classes.

    *Can have constructors and fields : Like any other class, an abstract class can have constructors and fields(member variables).

   * Can provide default implementations : An abstract class can also provide default implementations for some or all of its members.These implementations can be used by derived classes, which may choose to override them.

    *Serves as a contract : By defining abstract members, an abstract class acts as a contract or an interface that derived classes must adhere to.It ensures that the derived classes provide specific functionality.

    *Allows inheritance : Derived classes inherit the members(both abstract and non - abstract) and behavior of the abstract class.They can extend the abstract class by implementing the abstract members and adding their own specific members and behaviors.
    */


#pragma once
#include<iostream>
#include<string>
using namespace std;

class clsInterfaceCommunication
{

public:
    clsInterfaceCommunication(){}

	virtual void SendEmail(string Title, string Body) = 0;
	virtual void SendFax(string Title, string Body) = 0;
	virtual void SendSMS(string Title, string Body) = 0;


};

