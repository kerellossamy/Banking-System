#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include<string>
#include<vector>
#include<fstream>
#include"clsUtil.h"


class clsUser : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdatedMode = 1, AddNewMode = 2 };

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;
	

	//this declaration to know we implement the struct publicly so that every class deals with, can access it
	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;
		
		//Login Record Parts
		vector<string> vLoginRegisterDataLine = clsString::Split(Line, Seperator);

		LoginRegisterRecord.DateTime = vLoginRegisterDataLine[0];
		LoginRegisterRecord.Username = vLoginRegisterDataLine[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(vLoginRegisterDataLine[2]);
		LoginRegisterRecord.Permissions = stoi(vLoginRegisterDataLine[3]);

		return LoginRegisterRecord;
	}


	string _PrepareLoginRecord(string Seperator = "#//#")
	{
		string LoginRecord = "";

		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += UserName + Seperator;
		LoginRecord += clsUtil::EncryptText(Password) + Seperator;
		LoginRecord += to_string(Permissions);

		return LoginRecord;
	}

	static clsUser _ConvertLineToUserObject(string Line, string Delim = "#//#")
	{
		vector<string> vUserData = clsString::Split(Line, Delim);

		return clsUser(enMode::UpdatedMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));
	}

	static string _ConvertUserObjectToLine(clsUser User, string Delim = "#//#")
	{
		string UserRecord = "";
		UserRecord += User.FirstName + Delim;
		UserRecord += User.LastName + Delim;
		UserRecord += User.Email + Delim;
		UserRecord += User.Phone + Delim;
		UserRecord += User.UserName + Delim;
		UserRecord += clsUtil::EncryptText(User.Password) + Delim;
		UserRecord += to_string(User.Permissions);

		return UserRecord;
	}

	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector<clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}

			MyFile.close();
		}

		return vUsers;
	}

	static void _SaveUsersDataToFile(vector<clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsUser& U : vUsers)
			{
				if (U.MarkedForDelete() == false)
				{
					string DataLine;
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}
		}

		_SaveUsersDataToFile(vUsers);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	//Append DataLine To File
	static void _AddDataLineToFile(string DateLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DateLine << endl;

			MyFile.close();
		}
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}


public:

	enum enPermissions {
		pAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64, pListLoginRegister = 128
	};

	struct stLoginRegisterRecord 
	{
		string DateTime;
		string Username;
		string Password;
		int Permissions;
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions) :clsPerson(FirstName, LastName, Email, Phone)
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

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(put = SetUserName, get = GetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(put = SetPassword, get = GetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions() 
	{
		return _Permissions;
	}
	__declspec(property(put = SetPermissions, get = GetPermissions)) int Permissions;


	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

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
		/*fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();
		}

		return _GetEmptyUserObject();
		*/

		//An Easier way (From Comments)
		clsUser User = Find(UserName);
		return (User.Password == Password ? User : _GetEmptyUserObject());
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedUserExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
			case clsUser::EmptyMode:
			{
				if(IsEmpty())
					return enSaveResults::svFailedEmptyObject;
			}
			case clsUser::UpdatedMode:
			{
				_Update();
				return enSaveResults::svSucceeded;
			}
			case clsUser::AddNewMode:
			{
				//additional check
				if (clsUser::IsUserExist(UserName))
				{
					return enSaveResults::svFailedUserExists;
				}
				else
				{
					_AddNew();

					_Mode = enMode::UpdatedMode;
					return enSaveResults::svSucceeded;
				}
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
		//Additional Check
		if (_UserName == "Admin")
			return false;

		vector<clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.UserName == _UserName)
			{
				U._MarkedForDelete = true;
				_SaveUsersDataToFile(vUsers);
				*this = _GetEmptyUserObject();
				return true;
			}
		}

		return false;
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (Permissions == enPermissions::pAll)
			return true;

		return ((Permissions & Permission) == Permission);
	}

	void RegisterLogin()
	{
		string LoginRecord = _PrepareLoginRecord();

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << LoginRecord << endl;
			MyFile.close();
		}
	}

	static vector<stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector<stLoginRegisterRecord> vLoginRegisterRecords;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			stLoginRegisterRecord LoginRegisterRecord;

			while (getline(MyFile, Line))
			{
				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);
				vLoginRegisterRecords.push_back(LoginRegisterRecord);
			}

			MyFile.close();
		}

		return vLoginRegisterRecords;
	}

};

