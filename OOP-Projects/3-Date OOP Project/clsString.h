#pragma once
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include <string>
#include <iomanip>
#include<vector>
#include<sstream>

#define Length 4
#define ll long long

using namespace std;


class clsString {
private:
	string _Value;

	short ReadNumberInRange(short From, short To)
	{
		short Number = 1;
		bool validInput = true;
		do
		{
			if (!validInput) {
				// If input was invalid, clear the error flag and ignore any remaining input in the stream
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a number between " << From << " and " << To << "." << endl;
			}
			cout << "Enter A Number [" << From << "-" << To << "] ? ";
			cin >> Number;
			validInput = cin.good() && Number >= From && Number <= To;
		} while (!validInput);

		return Number;
	}

	ll ReadBigPositiveNumber()
	{
		ll Number = 0;
		do
		{
			cout << "Enter A Number: ";
			cin >> Number;
		} while (Number <= 0);

		return Number;
	}


	string ReadString(string Message)
	{
		string Str = "";
		cout << Message;
		getline(cin, Str);

		return Str;
	}

	char ReadCharacter(string Message)
	{
		char Ch = 'x';
		cout << Message;
		cin >> Ch;

		return Ch;
	}

	//For Key Generation
	enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

	short ReadPositiveNumber()
	{
		short Number = 0;
		do
		{
			cout << "Please Enter Number Of Keys You Wanna Generate?  " << endl;
			cin >> Number;
		} while (Number <= 0);
		return Number;
	}

	static	int RandomNumber(int From, int To)   //Function to generate a random number
	{
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}


	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SamallLetter:
		{
			return char(RandomNumber(97, 122));
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
		}
		}
	}

	static	string GenerateWord(enCharType CharType)  //DFGE
	{
		string Word = "";

		for (int i = 1; i <= Length; i++)
		{
			Word += GetRandomCharacter(CharType);
		}

		return Word;
	}

	static string GenerateKey()
	{
		string Key = "";

		Key += (GenerateWord(enCharType::CapitalLetter) + '-');
		Key += (GenerateWord(enCharType::CapitalLetter) + '-');
		Key += (GenerateWord(enCharType::CapitalLetter) + '-');
		Key += (GenerateWord(enCharType::CapitalLetter));

		return Key;
	}

	//This Fun For CountLeter Function
	enum enWhatToCount { CapitalLetters = 1,  SmallLetters = 2, _Digit = 3, Punctuatuion = 4, All = 5 };

	short PerformChoice(enWhatToCount Choice)
	{
		switch (Choice)
		{
		case enWhatToCount::SmallLetters:
			return CountLetters(_Value, enWhatToCount::SmallLetters);

		case enWhatToCount::CapitalLetters:
			return CountLetters(_Value, enWhatToCount::CapitalLetters);

		case  enWhatToCount::_Digit:
			return CountLetters(_Value, enWhatToCount::_Digit);

		case  enWhatToCount::Punctuatuion:
			return CountLetters(_Value, enWhatToCount::Punctuatuion);

		case  enWhatToCount::All:
			return CountLetters(_Value, enWhatToCount::All);

		}
	}

	static char InvertCharacterCase(char Ch)
	{
		return (islower(Ch)) ? toupper(Ch) : tolower(Ch);
	}

	static bool IsVowel(char Ch)
	{
		Ch = tolower(Ch);
		return(Ch == 'a' || Ch == 'e' || Ch == 'i' || Ch == 'o' || Ch == 'u');
	}


	
	static string JoinString(vector<string> vWords, string Delimite = " ")
	{
		string JoinedString = "";

		for (string& str : vWords)
		{
			JoinedString += (str + Delimite);
		}

		return JoinedString.substr(0, JoinedString.length() - Delimite.length());
	}


public:
	clsString(string Value = "")
	{
		_Value = Value;
	}
	///
	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;
	/// /////////////////////

	static void PrintFirstLettersInString(string Str)
	{
		bool IsFirstLetter = true; //True Initialization To Print First Character

		cout << "\nPrint The First Letter Of The string:\n";
		for (short i = 0; i < Str.length(); i++)
		{
			if (Str[i] != ' ' && IsFirstLetter)
				cout << Str[i] << endl;

			IsFirstLetter = (Str[i] == ' ' ? true : false);
		}
	}

	void PrintFirstLettersInString() {
		PrintFirstLettersInString(_Value);
	}
	///
	static string UpperFirstLetterOfEachWord(string Str)
	{
		bool IsFirstLetter = true;

		for (short Index = 0; Index < Str.size(); Index++)
		{
			if (IsFirstLetter && isalpha(Str[Index]))
			{
				if (islower(Str[Index]))
				{
					Str[Index] = toupper(Str[Index]);
				}
			}

			IsFirstLetter = (!isalpha(Str[Index])) ? true : false;
		}
		return Str;
	}

	void UpperFirstLetterOfEachWord()
	{
		_Value= UpperFirstLetterOfEachWord(_Value);
	}
	///

	static string LowerFirstLetterOfEachWord(string Str)
	{
		bool IsFirstLetter = true; //True Initialization To Print First Character

		for (short i = 0; i < Str.length(); i++)
		{
			if (Str[i] != ' ' && IsFirstLetter)
			{
				if (isupper(Str[i]))
					Str[i] = tolower(Str[i]);
			}

			IsFirstLetter = (Str[i] == ' ' ? true : false);
		}
		return Str;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}
	////////

	static string UpperAllLetterOfTheString(string Str)
	{
		for (short i = 0; i < Str.length(); i++)
		{
			Str[i] = toupper(Str[i]);
		}
		return Str;
	}

	void  UpperAllLetterOfTheString()
	{
		_Value = UpperAllLetterOfTheString(_Value);
	}
	//////

	static string LowerAllString(string Str)
	{
		for (short i = 0; i < Str.length(); i++)
		{
			Str[i] = tolower(Str[i]);
		}
		return Str;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	/////////

	static string InvertAllLettersCase(string Str)
	{
		for (int i = 0; i < Str.length(); i++)
		{
			Str[i] = InvertCharacterCase(Str[i]);
		}
		return Str;
	}

	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	//////

	static short CountLetters(string str, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
			return str.length();

		short Counter = 0;

		for (short i = 0; i < str.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(str[i]))
				Counter++;

			else if (WhatToCount == enWhatToCount::SmallLetters && islower(str[i]))
				Counter++;

			else if (WhatToCount == enWhatToCount::_Digit && isdigit(str[i]))
				Counter++;

			else if (WhatToCount == enWhatToCount::Punctuatuion && ispunct(str[i]))
				Counter++;
		}
		return Counter;
	}

	short CountLetters()
	{
		short Choice;
		cout << "What Do You Want To Count\n"
			<< "1-CapitalLetters \n"
			<< "2-SmallLetters \n"
			<< "3-Digits \n"
			<< "4-Punctuatuion\n"
			<< "5-All\n";
		cout << "\nEnter Your Choice: ";

		cin >> Choice;

		return PerformChoice((enWhatToCount)Choice);
	}
	/////////

	static short CountSpecificLetter(string str, char TargetLetter, bool MatchCase = true) //By Default Count The Entered Letter 
	{
		short Counter = 0;

		for (short i = 0; i < str.length(); i++)
		{
			if (MatchCase) //Count The Entered Letter 
			{
				if (TargetLetter == str[i])
					Counter++;
			}
			else //Count Matched Cases ==> Small + Capital
			{
				if (toupper(str[i]) == toupper(TargetLetter))
					Counter++;
			}
		}
		return Counter;
	}

	short CountSpecificLetter(bool MatchCase = true)
	{
		char Ch = ReadCharacter("Please Enter A Target Character You Wanna Count: ");
		return CountSpecificLetter(_Value, Ch, MatchCase);
	}
	///////////

	

	static short NumberOfVowels(string str)
	{
		short Counter = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (IsVowel(str[i]))
				Counter++;
		}
		return Counter;
	}

	short NumberOfVowels()
	{
		return NumberOfVowels(_Value);
	}
	/////////////

	static void PrintAllVowels(string& str)
	{
		cout << "Vowels In String Are : ";
		for (int i = 0; i < str.length(); i++)
		{
			if (IsVowel(str[i]))
				cout << setw(3) << str[i] << " ";
		}
	}

	void PrintAllVowels()
	{
		PrintAllVowels(_Value);
	}
	/////////

	static void PrintEachWordInString(string str)
	{
		string delim = " ";  //Delimiter فراغ
		short Pos = 0;
		string sWord;

		cout << "\nYour String Words Are:\n\n";

		while ((Pos = str.find(delim)) != std::string::npos)
		{
			sWord = str.substr(0, Pos); //store The Word => From Index 0 , Number Of Characters

			if (sWord != "") //To Handle Spaces
				cout << sWord << endl;
			// 0 1 2  3  4 5
			str.erase(0, Pos + delim.length());// A l i " " O s -> erase(0,3+1) erase 4 Chars From Beginning
		}

		//Print The Last Word
		if (str != "")
			cout << str << endl;
	}

	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	//////////////////

	static short CountWords(string str)
	{
		string delim = " ";  //Delimiter فراغ
		short Pos = 0;
		short Ctr = 0;
		string sWord;


		while ((Pos = str.find(delim)) != std::string::npos)
		{
			sWord = str.substr(0, Pos); //store The Word

			if (sWord != "") //To Handle Spaces
				Ctr++;

			str.erase(0, Pos + delim.length());
		}

		//Print The Last Word
		if (str != "")
			Ctr++;

		return Ctr;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}
	//////////

	//static vector<string> SpiltString(string str, string delim = " ")
	//{
	//	short Pos = 0;
	//	string sWord;
	//	vector<string>vWords;

	//	while ((Pos = str.find(delim)) != std::string::npos)
	//	{
	//		sWord = str.substr(0, Pos); //store The Word

	//		if (sWord != "") //To Handle Spaces"Ali     Mohammed"
	//			vWords.push_back(sWord);

	//		str.erase(0, Pos + delim.length());
	//	}

	//	//Print The Last Word
	//	if (str != "")
	//		vWords.push_back(str);

	//	return vWords;
	//}

	//vector<string> SpiltString()
	//{
	//	return SpiltString(_Value);
	//}

	////////

	static string TrimLeft(string str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
			{
				return str.substr(i, str.length() - i);
			}
		}
		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	///////////


	static string TrimRight(string str)
	{
		for (short i = str.length() - 1; i >= 0; i--)
		{
			if (str[i] != ' ')
			{
				return str.substr(0, i + 1); //if i stopped at index 7 , we need 8 letters 
			}
		}
		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}
	//////////////////

	string Trim()
	{
		return TrimRight(TrimLeft(_Value));
	}
	////////////////////

	//static string JoinString(vector<string> vWords, string Delimite = " ")
	//{
	//	string JoinedString = "";

	//	for (string& str : vWords)
	//	{
	//		JoinedString += (str + Delimite);
	//	}

	//	return JoinedString.substr(0, JoinedString.length() - Delimite.length());
	//}

	//string JoinString()
	//{
	//	return JoinString(SpiltString(_Value));
	//}

	//////////////////


	static vector<string> SpiltString(string str, string delim = " ")
	{
		short Pos = 0;
		string sWord;
		vector<string>vWords;

		while ((Pos = str.find(delim)) != std::string::npos)
		{
			sWord = str.substr(0, Pos); //store The Word

			if (sWord != "") //To Handle Spaces"Ali     Mohammed"
				vWords.push_back(sWord);

			str.erase(0, Pos + delim.length());
		}

		//Print The Last Word
		if (str != "")
			vWords.push_back(str);

		return vWords;
	}


	static void SwapStrings(string& a, string& b)
	{
		string Temp = a;
		a = b;
		b = Temp;
	}

	static void ReverseStringVector(vector<string>& vWords)
	{
		short sLength = vWords.size();
		for (short i = 0; i < (sLength / 2); i++)
		{
			SwapStrings(vWords[i], vWords[sLength - i - 1]);
		}
	}

	static string ReverseWords(string Str)
	{
		vector<string>vWords = SpiltString(Str);
		ReverseStringVector(vWords);
		return JoinString(vWords);
	}

	void ReverseWords()
	{
		//Direct Modified On Obj
		_Value = ReverseWords(_Value);
	}

	//////////////////////////////

	//Replace Every Egypt To Londen As Ex
	static string ReplaceWordInString(string sBase, string sTaget, string ReplacedWord)
	{
		short PosOfTarget = 0;

		while ((PosOfTarget = sBase.find(sTaget)) != std::string::npos)
		{
			//replace(From , Size , " ")
			sBase.replace(PosOfTarget, sTaget.length(), ReplacedWord);
		}
	}

	void ReplaceWordInString()
	{
		string sTaget = ReadString("Enter A Taget Word To Replace It: ");
		string ReplacedWord = ReadString("Enter A New Word: ");
		_Value = ReplaceWordInString(_Value, sTaget, ReplacedWord);
	}

	//////////////

	//Math Case =>case sencetive
	static string ReplaceWordInStringMatchedOrNot(string sBase, string StringToReplace, string ReplaceTo, bool IsMatch = true)
	{
		vector<string>vWords = SpiltString(sBase, " ");

		for (string& Str : vWords)
		{
			if (IsMatch)
			{
				if (Str == StringToReplace)
				{
					Str = ReplaceTo;
				}
			}

			else
			{
				if (LowerAllString(Str) == LowerAllString(StringToReplace))
				{
					Str = ReplaceTo;
				}
			}
		}

		return JoinString(vWords);
	}

	void ReplaceWordInStringMatchedOrNot(bool MatchCase = true)
	{
		string sTaget = ReadString("Enter A Taget Word To Replace It: ");
		string ReplacedWord = ReadString("Enter A New Word: ");
		_Value = ReplaceWordInStringMatchedOrNot(_Value, sTaget, ReplacedWord, MatchCase);
	}

	///////////

	static string RemovePunctuaiton(string str)
	{
		string str2 = "";

		for (short i = 0; i < str.length(); i++)
		{
			if (!ispunct(str[i]))
			{
				str2 += str[i];
			}
		}
		return str2;
	}

	void RemovePunctuaiton()
	{
		_Value = RemovePunctuaiton(_Value);
	}

	////////////////////

	//A PowerFull Recursion Example
	static string NumberToText(ll Num)
	{
		//Base Case
		if (Num == 0)
		{
			return "";
		}

		//One To 99
		if (Num >= 1 && Num <= 19)
		{
			string arr[] = { "One" , "Two" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine" , "Ten" , 
				"Eleven" , "Twelve" , "Therteen" , "Fourteen" , "Fifteen" ,
				"sixteen" , "Seventeen" , "Eighteen" , "Ninteen"
			};

			return arr[Num - 1];  //15 => arr[14]="Fifteen"
		}

		if (Num >= 20 && Num <= 99)
		{
			string arr[] = { "","", "Twenty" , "Thirty" , "Fourty" , "Fifty" , "Sixty" , "Seventy" , "Eighty" , "Ninty" };

			return arr[Num / 10] + " " + NumberToText(Num % 10);      //36 => arr[36/10 = (3)] = Thirty     + " " + NumberToText( (6) => "36%10")
		}

		//100 To 999
		if (Num >= 100 && Num <= 999)
		{
			return NumberToText(Num / 100) + " Hundred " + NumberToText(Num % 100);
		}

		//1000 To 999999
		if (Num >= 1000 && Num <= 999999)
		{
			return NumberToText(Num / 1000) + " Thousand " + NumberToText(Num % 1000);
		}

		//1 000 000 To 999 999 999
		if (Num >= 1000000 && Num <= 999999999)
		{
			return NumberToText(Num / 1000000) + " Milion " + NumberToText(Num % 1000000);
		}

		//1 000 000 000 To 999 999 999 999
		if (Num >= 1000000000 && Num <= 999999999999)
		{
			return NumberToText(Num / 1000000000) + " Billion " + NumberToText(Num % 1000000000);
		}

		//And So On
	}

	string NumberToText()
	{
		ll Number;
		cout << "Enter A Number : ";
		cin >> Number;

		return NumberToText(Number);
	}
/////////////////////

	short GetLength()
	{
		return _Value.length();
	}
	////////////////////////////////////

	static int StringToInt(string sNumber)
	{
		// 1-With Sting Stream
		int Num = 0;
		stringstream S;
		S << sNumber;
		 S >> Num;
		 return Num;

		 // 2-With Built In Function
		// Num = stoi(sNumber);  //stoll stoul
		 
	}
	//////////////////////////

	static void GenerateNumberOfKeys(short Keys)
	{
		for (int i = 1; i <= Keys; i++)
		{
			cout << "Key [" << i << "] : " << GenerateKey() << endl;
		}
	}

	/////////////////////////
	static string EncryptText(string Text, short EncryptionKey=10)
	{
		for (int i = 0; i < Text.size(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}

		return Text;
	}

	string EncryptText()
	{
		return EncryptText(_Value);
	}

	/// ///////////////
	
	static string DecryptText(string Text, short EncryptionKey=10)
	{
		for (int i = 0; i < Text.size(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

	string DecryptText()
	{
		return DecryptText(_Value);
	}




};
