#pragma once

#include<iostream>
using namespace std;

class clsPerson
{

private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;


public:

    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    //Property Set
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    //Property Get
    string GetFirstName()
    {
        return _FirstName;
    }
    __declspec(property(put = SetFirstName, get = GetFirstName)) string FirstName;


    //Property Set
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    //Property Get
    string GetLastName()
    {
        return _LastName;
    }
    __declspec(property(put = SetLastName, get = GetLastName)) string LastName;


    //Property Set
    void SetEmail(string Email)
    {
        _Email = Email;
    }

    //Property Get
    string GetEmail()
    {
        return _Email;
    }
    __declspec(property(put = SetEmail, get = GetEmail)) string Email;


    //Property Set
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    //Property Get
    string GetPhone()
    {
        return _Phone;
    }
    __declspec(property(put = SetPhone, get = GetPhone)) string Phone;


    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    /*void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
        cout << "\n___________________\n";

    }*/
};
