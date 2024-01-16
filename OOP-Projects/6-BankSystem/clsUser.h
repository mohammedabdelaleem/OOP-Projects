#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include"clsDate.h"
#include"clsUtil.h"

using namespace std;

const string UsersFileName = "UsersInfo.txt";
const string RegisterdUsersFileName = "FlieRegister.txt";


class clsUser : public clsPerson
{
private:
    struct stLoginRegisterRecord;
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;



    bool _MarkedForDelete = false;

    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4],clsUtil::DecryptText( vUserData[5]), stoi(vUserData[6]));

    }

    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
    {
        vector<string>vRecord = clsString::Split(Line, Seperator);
        stLoginRegisterRecord UserRecord;
        UserRecord.DateTime = vRecord[0];
        UserRecord.UserName = vRecord[1];
        UserRecord.Password = clsUtil::DecryptText(vRecord[2]);
        UserRecord.Permissions = stoi(vRecord[3]);

        return UserRecord;
    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord +=User.UserName + Seperator;
        UserRecord += clsUtil::EncryptText(User.Password) + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;

    }


    static  vector <clsUser> _LoadUsersDataFromFile(string FileName)
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open(FileName, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static vector<stLoginRegisterRecord> _LoadLoginRegisterDateFromFile(string FileName)
    {
        vector <stLoginRegisterRecord> vUsers;

        fstream MyFile;
        MyFile.open(RegisterdUsersFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {

                 LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                vUsers.push_back(LoginRegisterRecord);
            }

            MyFile.close();

        }

        return vUsers;

    }
 

    static void _SaveUsersDataToFile(string FileName,vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open(FileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser& U : vUsers)
            {
                if (!U.MarkedForDeleted() )
                {
                    //we only write records that are Not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers = _LoadUsersDataFromFile(UsersFileName);

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(UsersFileName,_vUsers);

    }

    void _AddNew()
    {
        _AddDataLineToFile(UsersFileName,_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string FileName,string  sDataLine)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << sDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    string _PrepareLogInRecord(string Separator="#//#")
    {
      string LogInRecord = clsDate::GetSystemDateTimeString();
        LogInRecord += Separator + UserName;
        LogInRecord += Separator + clsUtil::EncryptText(Password);
        LogInRecord += Separator + to_string(Permissions);

        return LogInRecord;
  }


public:
    struct stLoginRegisterRecord {
        string DateTime;
        string UserName;
        string Password;
        int Permissions;
    };

    enum enMainMenuePermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClients = 8,
        pFindClient = 16, pTranactions = 32, pManageUsers = 64,pListLoginRegister=128,pCurrencyExchange=256
    };

    clsUser(enMode Mode=enMode::EmptyMode, string FirstName="", string LastName = "",
        string Email = "", string Phone = "", string UserName = "", string Password = "",
        int Permissions=0) :
        clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open(UsersFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open(UsersFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            clsUser User;
            while (getline(MyFile, Line))
            {
                User= _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(string UserName)
    {
        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers = _LoadUsersDataFromFile(UsersFileName);

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(UsersFileName, _vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile(UsersFileName);
    }


    ////////////////////Permissoins///////////////////
     bool CheckAccessPermission(enMainMenuePermissions Permission)
    {
        return ((this->Permissions == enMainMenuePermissions::eAll) || ((Permission & this->Permissions)==Permission));
    }

     void RegisterLogin()
     {
         string sDateLine = _PrepareLogInRecord();

         fstream MyFile;
         MyFile.open("FlieRegister.txt", ios::app | ios::out);

         if (MyFile.is_open())
         {
             MyFile << sDateLine << endl;

             MyFile.close();
         }
     }

     static vector<stLoginRegisterRecord> GetLoginRegisterList()
     {
         return _LoadLoginRegisterDateFromFile(RegisterdUsersFileName);
     }


};

