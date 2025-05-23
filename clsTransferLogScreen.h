#pragma once
#include "clsScreen.h"

class clsTransferLogScreen : protected clsScreen
{
private:
    static void _PrintTransferLogRecord(clsBankClient::stTransferLogRecord TransferLogRecord)
    {
        cout << left;
        cout << setw(2) << "";
        cout << "| " << setw(23) << TransferLogRecord.DateTime;
        cout << "| " << setw(7) << TransferLogRecord.SenderAccountNumber;
        cout << "| " << setw(7) << TransferLogRecord.ReceiverAccountNumber;
        cout << "| " << setw(7) << TransferLogRecord.TransferAmount;
        cout << "| " << setw(15) << TransferLogRecord.SenderBalanceAfter;
        cout << "| " << setw(17) << TransferLogRecord.ReceiverBalanceAfter;
        cout << "| " << setw(11) << TransferLogRecord.UserName;
    }


public:
	static void ShowTransferLogScreen()
	{
        vector<clsBankClient::stTransferLogRecord> vTransferLogRecords = clsBankClient::GetTransferLogList();

        string Title = "       Transfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecords.size()) + ") Record(s).";
		_DrawScreenHeader(Title, SubTitle);


        cout << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";
        cout << left;
        cout << setw(2) << "";
        cout << "| " << setw(23) << "Date/Time";
        cout << "| " << setw(7) << "From";
        cout << "| " << setw(7) << "To";
        cout << "| " << setw(7) << "Amount";
        cout << "| " << setw(15) << "Sender Balance";
        cout << "| " << setw(17) << "Receiver Balance";
        cout << "| " << setw(11) << "User";
        cout << "\n" << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";


        if (vTransferLogRecords.size() == 0) {
            cout << "\t\t\t\tNo Transfer Records Are Available In The System!\n";
        }
        else
        {
            for (clsBankClient::stTransferLogRecord& TransferRecord : vTransferLogRecords)
            {
                _PrintTransferLogRecord(TransferRecord);
                cout << "\n";
            }
        }

        cout << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";

	}
};

