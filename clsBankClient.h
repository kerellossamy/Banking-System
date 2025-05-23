#pragma once
#include"clsPerson.h";
#include"clsString.h"
#include<string>
#include<vector>
#include<fstream>

class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdatedMode = 1, AddNewMode = 2 };

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;


	static clsBankClient _ConvertLineToClientObject(string Line, string Delim = "#//#") 
	{
		vector<string> vClientData = clsString::Split(Line, Delim);

		return clsBankClient(enMode::UpdatedMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Delim = "#//#")
	{
		string ClientRecord = "";
		ClientRecord += Client.FirstName + Delim;
		ClientRecord += Client.LastName + Delim;
		ClientRecord += Client.Email + Delim;
		ClientRecord += Client.Phone + Delim;
		ClientRecord += Client.AccountNumber + Delim;
		ClientRecord += Client.PinCode + Delim;
		ClientRecord += to_string(Client.AccountBalance);

		return ClientRecord;
	}
	
	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		
		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}

			MyFile.close();
		}
		
		return vClients;
	}

	static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClients)
			{
				if (C.MarkedForDelete() == false)
				{
					string DataLine;
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber) 
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	//Append DataLine To File
	static void _AddDataLineToFile(string DateLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DateLine << endl;

			MyFile.close();
		}
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord TransferLogRecord;

		vector<string> vTransferLogLine = clsString::Split(Line, Seperator);
		TransferLogRecord.DateTime = vTransferLogLine[0];
		TransferLogRecord.SenderAccountNumber = vTransferLogLine[1];
		TransferLogRecord.ReceiverAccountNumber = vTransferLogLine[2];
		TransferLogRecord.TransferAmount = stod(vTransferLogLine[3]);
		TransferLogRecord.SenderBalanceAfter = stod(vTransferLogLine[4]);
		TransferLogRecord.ReceiverBalanceAfter = stod(vTransferLogLine[5]);
		TransferLogRecord.UserName = vTransferLogLine[6];

		return TransferLogRecord;
	}


	string _PrepareTransferLogRecord(double TransferAmount, clsBankClient ReceiverClient, string Username, string Seperator = "#//#")
	{
		string TransferLogRecord = "";

		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += AccountNumber + Seperator;
		TransferLogRecord += ReceiverClient.AccountNumber + Seperator;
		TransferLogRecord += to_string(TransferAmount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(ReceiverClient.AccountBalance) + Seperator;
		TransferLogRecord += Username;

		return TransferLogRecord;
	}

	void _RegisterTransferLog(double TransferAmount, clsBankClient ReceiverClient, string Username)
	{
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			string DataLine = _PrepareTransferLogRecord(TransferAmount, ReceiverClient, Username);
			MyFile << DataLine << endl;

			MyFile.close();
		}
	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string Pincode, float AccountBalance) 
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = Pincode;
		_AccountBalance = AccountBalance;
	}

	struct stTransferLogRecord
	{
		string DateTime;
		string SenderAccountNumber;
		string ReceiverAccountNumber;
		double TransferAmount;
		double SenderBalanceAfter;
		double ReceiverBalanceAfter;
		string UserName;
	};


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber)) string AccountNumber;


	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


	/*
		No UI related code inside the object.
	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";
	}*/


	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) 
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				
				if (Client.AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		/*fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
		*/

		//An Easier way (From Comments)
		clsBankClient Client = Find(AccountNumber);
		return (Client.PinCode == PinCode ? Client : _GetEmptyClientObject());
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
			case clsBankClient::EmptyMode:
			{
				if (IsEmpty())
					return enSaveResults::svFailedEmptyObject;
			}

			case clsBankClient::UpdatedMode:
			{
				_Update();
				return enSaveResults::svSucceeded;
			}

			case clsBankClient::AddNewMode:
			{
				//additional check
				if (clsBankClient::IsClientExist(AccountNumber))
				{
					return enSaveResults::svFailedAccountNumberExists;
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

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	bool Delete()
	{
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(vClients);
		*this = _GetEmptyClientObject();
	
		return true;
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	void Deposit(double Amount)
	{
		AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
			return false;
		else 
		{
			AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient& C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}

		return TotalBalances;
	}

	bool Transfer(double TransferAmount, clsBankClient& ReceiverClient, string Username)
	{
		//check that the two accounts are not the same
		if (AccountNumber == ReceiverClient.AccountNumber)
			return false;

		if (TransferAmount > AccountBalance)
		{
			return false;
		}
		else 
		{
			Withdraw(TransferAmount);
			ReceiverClient.Deposit(TransferAmount);
			_RegisterTransferLog(TransferAmount, ReceiverClient, Username);
			return true;
		}
	}
	
	static vector<stTransferLogRecord> GetTransferLogList()
	{
		vector<stTransferLogRecord> vTransferLogRecords;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string DataLine;
			stTransferLogRecord TransferLogRecord;

			while (getline(MyFile, DataLine))
			{
				TransferLogRecord = _ConvertTransferLogLineToRecord(DataLine);
				vTransferLogRecords.push_back(TransferLogRecord);
			}

			MyFile.close();
		}

		return vTransferLogRecords;
	}

};

