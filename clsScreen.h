#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t" << "_____________________________________\n\n";
        cout << "\t\t\t\t" << Title << "\n";

        if (SubTitle != "")
        {
            cout << "\t\t\t\t" << SubTitle << "\n";
        }

        cout << "\t\t\t\t" << "_____________________________________\n\n";

        _DrawUserAndDate();
    }

    static bool _CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            //we don't use this, becuase it will display the User and date also
            /*_DrawScreenHeader("  Access Denied! Contact your Admin.");*/

            cout << "\t\t\t\t" << "_____________________________________\n\n";
            cout << "\t\t\t\t" << "  Access Denied! Contact your Admin." << "\n";
            cout << "\t\t\t\t" << "_____________________________________\n\n";

            return false;
        }
        else
        {
            return true;
        }
    }

    static void _DrawUserAndDate()
    {
        /*only in the login screen, the username is not set yet
        so doing this will show username and date in any screen except the login screen
        and that we need to do.*/

        if (!CurrentUser.IsEmpty())
        {
            cout << "\t\t\t\t" << "User: " << CurrentUser.UserName << "\n";

            //to get the system date
            clsDate Date = clsDate::clsDate();

            string SystemDate = clsDate::FormatDate(Date, "mm dd, yyyy");
            string DayName = clsDate::DayShortName(Date.Day, Date.Month, Date.Year);
            string Time = clsDate::GetSystemTimeString(true);
            
            cout << "\t\t\t\t" << "Date: " << SystemDate << " - " << DayName << " - " << Time << "\n\n";
        }
    }
};

