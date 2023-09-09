#pragma once
#include<iostream>
#include"Global.h"

using namespace std;

class clsScreen
{

protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
    }

    static void moveCursor(int row, int col) {/////////////
        cout << "\033[" << row << ";" << col << "H"; //33 Escape character
    }

    static bool CheckAccessRights(clsUser::enMainMenuePermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            moveCursor(80, 80);
            cout << "\n\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n\a";
            return false;
        }
        else
        {
            return true;
        }

    }

};

