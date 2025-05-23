#pragma once

#include<iostream>
#include<vector>
using namespace std;

class clsString
{
private:
	string _Value;

public:
	clsString() {
		_Value = "";
	}

	clsString(string Value) {
		_Value = Value;
	}

	void SetValue(string Value) {
		_Value = Value;
	}

	string GetValue() {
		return _Value;
	}

	_declspec(property(put = SetValue, get = GetValue)) string Value;

	static short Length(string S)
	{
		return S.length();
	};

	short Length()
	{
		return _Value.length();
	};

	static short CountWords(string S1)
	{
		string delim = " "; // delimiter
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable

		// use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				Counter++;
			}
			//erase() until positon and move to next word.
			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++; // it counts the last word of the string.
		}

		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static void PrintFirstLetterOfEachWord(string S) {

		bool isFirstLetter = true;

		cout << "\nFirst letters of this string: \n";

		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && isFirstLetter) {
				cout << S[i] << endl;
			}

			//Check for the next character if it is first letter or not
			isFirstLetter = (S[i] == ' ' ? true : false);
		}
	}

	void PrintFirstLetterOfEachWord() 
	{
		return PrintFirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S) {

		bool isFirstNumber = true;

		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && isFirstNumber) {
				S[i] = toupper(S[i]);
			}

			isFirstNumber = (S[i] == ' ' ? true : false);
		}

		return S;
	}

	void UpperFirstLetterOfEachWord() 
	{
		// no need to return value , this function will directly update the object value
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S) {

		bool isFirstNumber = true;

		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && isFirstNumber) {
				S[i] = tolower(S[i]);
			}

			isFirstNumber = (S[i] == ' ' ? true : false);
		}

		return S;
	}

	void LowerFirstLetterOfEachWord() 
	{
		// no need to return value , this function will directly update the object value
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string S) {
		for (short i = 0; i < S.length(); i++)
		{
			S[i] = toupper(S[i]);
		}
		return S;
	}

	void UpperAllString() 
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string S) 
	{
		for (short i = 0; i < S.length(); i++)
		{
			S[i] = tolower(S[i]);
		}
		return S;
	}

	void LowerAllString() 
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char Ch) 
	{
		return isupper(Ch) ? tolower(Ch) : toupper(Ch);
	}

	static string InvertAllLettersCase(string S) 
	{
		for (short i = 0; i < S.length(); i++)
		{
			S[i] = InvertLetterCase(S[i]);
		}
		return S;
	}

	void InvertAllLettersCase() 
	{
		_Value = InvertAllLettersCase(_Value);
	}

	enum enWhatToCount { CapitalLetters = 1, SmallLetters = 2, AllLetters = 3 };

	/*
	I Will not make another method like this because it will count AllLetters only 
	and that is like the length method
	*/
	static short CountLetters(string S, enWhatToCount WhatToCount = AllLetters) 
	{
		if (WhatToCount == AllLetters) {
			return S.length();
		}

		short Counter = 0;

		for (short i = 0; i < S.length(); i++)
		{
			if (WhatToCount == CapitalLetters && isupper(S[i])) {
				Counter++;
			}
			else if (WhatToCount == SmallLetters && islower(S[i]))
			{
				Counter++;
			}
		}

		return Counter;
	}

	static short CountCapitalLetters(string S) {

		short NumbersOfCapitalLetters = 0;
		for (short i = 0; i < S.length(); i++)
		{
			if (isupper(S[i])) {
				NumbersOfCapitalLetters++;
			}
		}
		return NumbersOfCapitalLetters;
	}

	short CountCapitalLetters() 
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string S) 
	{
		short NumbersOfSmallLetters = 0;

		for (short i = 0; i < S.length(); i++)
		{
			if (islower(S[i])) {
				NumbersOfSmallLetters++;
			}
		}
		return NumbersOfSmallLetters;
	}

	short CountSmallLetters() 
	{
		return CountSmallLetters(_Value);
	}

	static short CountSpecificLetter(string S, char Letter, bool MatchCase = true) 
	{
		short Counter = 0;

		for (short i = 0; i < S.length(); i++)
		{
			// only the letter (Case Sensitive)
			if (MatchCase) {
				if (S[i] == Letter)
					Counter++;
			}
			// capital and small letter (NOT Case Sensitive)
			else 
			{
				//you can make it toupper in these two statements (two sentences must be the same)
				if (tolower(S[i]) == tolower(Letter))
					Counter++;
			}
		}

		return Counter;
	}

	short CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	static bool isVowel(char Ch) 
	{
		Ch = tolower(Ch);
		return (Ch == 'a' || Ch == 'e' || Ch == 'i' || Ch == 'o' || Ch == 'u');
	}

	static short CountVowels(string S) 
	{
		short Counter = 0;

		for (short i = 0; i < S.length(); i++)
		{
			if (isVowel(S[i]))
				Counter++;
		}

		return Counter;
	}

	short CountVowels() 
	{
		return CountVowels(_Value);
	}

	static vector<string> Split(string S, string Delim) 
	{
		vector<string> vWords;
		string Word;
		short Pos;

		while ((Pos = S.find(Delim)) != string::npos) {

			Word = S.substr(0, Pos);

			//if (Word != "") {
				vWords.push_back(Word);
			//}
			S.erase(0, Pos + Delim.length());
		}

		//Be careful: we push back the S not the Word
		if (S != "") {
			vWords.push_back(S);
		}

		return vWords;

	}

	vector<string> Split(string Delim) {
		return Split(_Value, Delim);
	}

	static string TrimLeft(string S) 
	{
		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ') {
				return S.substr(i, S.length() - i);
			}
		}
		return "";
	}

	void TrimLeft() 
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S) 
	{
		for (short i = S.length() - 1; i >= 0; i--)
		{
			if (S[i] != ' ') {
				return S.substr(0, i + 1);
			}
		}
		return "";
	}
	
	void TrimRight() 
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string S) 
	{
		return TrimLeft(TrimRight(S));
	}

	void Trim() 
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string>& vString, string Delim = " ")
	{
		string S = "";

		for (string& Word : vString) {
			S += (Word + Delim);
		}

		//it was possible to return just the S
		//but we don't need to return the delimeter after the last word
		return S.substr(0, S.length() - Delim.length());
	}

	static string JoinString(string arrString[], short Length, string Delim)
	{
		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string ReverseWords(string S)
	{
		vector<string> vWords = Split(S, " ");
		string S2 = "";

		vector<string>::iterator iter = vWords.end();

		while (iter != vWords.begin())
		{
			--iter;
			S2 += *iter + " ";

		}

		//remove the last space
		return S2.substr(0, S2.length() - 1);
	}

	void ReverseWords() 
	{
		_Value = ReverseWords(_Value);
	}

	static string ReplaceWord(string S, string OldString, string NewString, bool isMatchCase = true) 
	{
		vector<string> vWords = Split(S, " ");

		for (string& Word : vWords)
		{
			if (isMatchCase)
			{
				if (Word == OldString) {
					Word = NewString;
				}
			}
			else
			{
				if (LowerAllString(Word) == LowerAllString(OldString)) {
					Word = NewString;
				}
			}
		}

		return JoinString(vWords, " ");
	}

	void ReplaceWord(string OldString, string NewString, bool isMatchCase = true)
	{
		_Value = ReplaceWord(_Value, OldString, NewString, isMatchCase);
	}

	//I prefer using it to using the ReplaceWord in the case of -> isMatchCase = false
	//ex: replace any date format
	static string Replace(string S, string OldString, string NewString)
	{	
		short pos = 0;
		while ((pos = S.find(OldString)) != string::npos)
		{
			S.replace(pos, OldString.length(), NewString);
		}

		return S;
	}

	string Replace(string OldString, string NewString)
	{
		_Value = Replace(_Value, OldString, NewString);
	}


	static string RemovePunctuations(string S) 
	{
		string S2 = "";

		for (short i = 0; i < S.length(); i++)
		{
			if (!ispunct(S[i]))
				S2 += S[i];
		}
		return S2;
	}

	void RemovePunctuations() 
	{
		_Value = RemovePunctuations(_Value);
	}
};

