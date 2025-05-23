#pragma once
#include "clsScreen.h"

class clsLoginRegisterListScreen : protected clsScreen
{
private:
    static void _PrintLoginRecord(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {
        cout << left;
        cout << setw(2) << "";
        cout << "| " << setw(30) << LoginRegisterRecord.DateTime;
        cout << "| " << setw(25) << LoginRegisterRecord.Username;
        cout << "| " << setw(20) << LoginRegisterRecord.Password;
        cout << "| " << setw(15) << LoginRegisterRecord.Permissions;
    }


public:
	static void ShowLoginRegisterScreen()
	{
        if (!_CheckAccessRights(clsUser::enPermissions::pListLoginRegister))
        {
            return;// this will exit the function and it will not continue
        }

        vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecords = clsUser::GetLoginRegisterList();

		string Title = "      Login Register List Screen";
		string SubTitle = "\t    (" + to_string(vLoginRegisterRecords.size()) + ") Record(s).";
        clsScreen::_DrawScreenHeader(Title, SubTitle);


        cout << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";
        cout << left;
        cout << setw(2) << "";
        cout << "| " << setw(30) << "Date/Time";
        cout << "| " << setw(25) << "Username";
        cout << "| " << setw(20) << "Password";
        cout << "| " << setw(15) << "Permissions";
        cout << "\n" << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";

        if (vLoginRegisterRecords.size() == 0) {
            cout << "\t\t\t\tNo Login Records Are Available In The System!\n";
        }
        else 
        {
            for (clsUser::stLoginRegisterRecord& LoginRecord : vLoginRegisterRecords)
            {
                _PrintLoginRecord(LoginRecord);
                cout << "\n";
            }
        }

        cout << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";

	}
};

