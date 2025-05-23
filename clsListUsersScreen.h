#pragma once
#include<iostream>
#include<iomanip>
#include "clsUser.h";
#include "clsScreen.h";
using namespace std;

class clsListUsersScreen : protected clsScreen
{
private:
    static void _PrintUserRecordLine(clsUser User)
    {
        cout << left;
        cout << setw(2) << "";
        cout << "| " << setw(12) << User.UserName;
        cout << "| " << setw(18) << User.FullName();
        cout << "| " << setw(22) << User.Email;
        cout << "| " << setw(15) << User.Phone;
        cout << "| " << setw(10) << User.Password;
        cout << "| " << setw(5) << User.Permissions;
    }


public:
	static void ShowUsersListScreen()
	{
		vector<clsUser> vUsers = clsUser::GetUsersList();

		string Title = "\t  Users List Screen";
		string SubTitle = "\t   ( " + to_string(vUsers.size()) + " ) User(s).";
		_DrawScreenHeader(Title, SubTitle);

        cout << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";

        cout << left;
        cout << setw(2) << "";
        cout << "| " << setw(12) << "User Name";
        cout << "| " << setw(18) << "Full Name";
        cout << "| " << setw(22) << "Email";
        cout << "| " << setw(15) << "Phone Number";
        cout << "| " << setw(10) << "Password";
        cout << "| " << setw(5) << "Permissions";
        cout << "\n" << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Are Available In The System!\n";

        for (clsUser& U : vUsers)
        {
            _PrintUserRecordLine(U);
            cout << "\n";
        }

        cout << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";
	}

};

