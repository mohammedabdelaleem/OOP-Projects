#pragma once
#pragma warning(disable : 4996) 

//We Implemented Lots Of "General" Functions In Our Faced Problem Which We Can Use
// All Of Them In Our Life So We Wrapping Them Inside A Class To Use What I Need.
//I Will Put What I Think It's Usefull

#include <iostream>
#include <climits>
#include <string>
#include <windows.h>
#include<time.h>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include <ctime>
#include <iomanip>
#include <algorithm>

#include"clsDate.h"

using namespace std;

#define ll long long
const short Row = 3;
const short Col = 3;


class clsUtil
{
public:

    static int ReadPositiveNumber(string Message)
    {
        int Number = 0;
        do
        {
            cout << Message << endl;
            cin >> Number;
        } while (Number <= 0);
        return Number;
    }

    static int ReadNumber(string Message)
    {
        int Number = 0;
            cout << Message << endl;
            cin >> Number;
       
        return Number;
    }

    static float ReadFloatPositiveNumber(string Message)
    {
        float Num;
        do
        {
            cout << Message << endl;
            cin >> Num;
        } while (Num < 0);

        return Num;
    }

    static short ReadNumberInRange(short From, short To)
    {
        short NumberOfQuestions = 1;
        bool validInput = true;
        do
        {
            if (!validInput) {
                // If input was invalid, clear the error flag and ignore any remaining input in the stream
                cin.clear();
               // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //We Can't Use This Line Because max() conflict with Windows.h
                cin.ignore(INT_MAX, '\n');
                cout << "Invalid input. Please enter a number between " << From << " and " << To << "." << endl;
            }
            cout << "Enter A Number [" << From << "-" << To << "] ? ";
            cin >> NumberOfQuestions;
            validInput = cin.good() && NumberOfQuestions >= From && NumberOfQuestions <= To;
        } while (!validInput);

        return NumberOfQuestions;
    }

    static char ReadCharacter(string Message)
    {
        char Ch = 'x';
        cout << Message;
        cin >> Ch;

        return Ch;
    }

    static  string ReadString(string Message)
    {
        string Str = "";
        cout << Message;
        getline(cin >> ws, Str); //White space To Clean The Buffer

        return Str;
    }

    //Load And Move Cursor
   static void moveCursor(int row, int col) {/////////////
        cout << "\033[" << row << ";" << col << "H"; //33 Escape character
    }

   static void load(int time)
    {
        moveCursor(25, 48);
        cout << "\t--->Loading";
        for (int i = 0; i < time; i++)
        {
            if ((i + 1) != time)
            {
                Sleep(3);
                cout << ".";
            }
            else
            {
                Sleep(3);
                cout << ":-)";
                Sleep(3);
            }
        }
        system("cls");
    }

    //ODD Or Even
    enum enNumberType { Odd = 1, Even = 2 };

  static enNumberType CheckNumberType(int Num)
    {
        return (Num % 2 == 0)?enNumberType::Even : enNumberType::Odd;
    }

  static void PrintNumberType(enNumberType NumType)
    {
        (NumType == enNumberType::Even) ? cout << "Number Is Even\n" : cout << "Number Is Odd\n";
    }

  static int Max(int Number1, int Number2)
  {
      return (Number1 >= Number2) ? Number1 : Number2;
  }

  static int Min(int Number1, int Number2)
  {
      return (Number1 <= Number2) ? Number1 : Number2;
  }
   
 static bool ValidateNumberInRange(int Num, int from, int to)
  {
      return(Num >= from && Num <= to);
  }

 //summation of all numbers between A and B (inclusive).
//summation of even numbers between A and B(inclusive).
//summation of odd numbers between A and B(inclusive).
 static ll EvenSumFaster(ll Num) //  ==>num / 2
 {
     return (Num * (Num + 1));
 }

 static ll OddSumFaster(ll Num) //
 {
     ll res = (Num + 1) / 2;
     return res * res;
 }

 static ll SumFromZeorToNumFaster(ll Num)
 {
     return (Num * (Num + 1)) / 2;
 }


//Prime Or Not
 enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

 static enPrimeNotPrime PrimeChecker(int Num)
 {
     if (Num == 0 || Num == 1)
         return enPrimeNotPrime::NotPrime;

     for (int i = 2; i * i <= Num; i++)//Time: sqrt ==> log n , so we Squaring the parties [ i*i<Number]
     {
         if (Num % i == 0)
             return enPrimeNotPrime::NotPrime;
     }

     return enPrimeNotPrime::Prime;
 }

 static void PrintNumberType(int Num)
 {
     switch (PrimeChecker(Num))
     {
     case enPrimeNotPrime::Prime:
         cout << Num << " is Prime \n";
         break;

     case enPrimeNotPrime::NotPrime:
         cout << Num << " is Not Prime \n";
         break;
     }
 }

 //Print All Primes From 1 To N
 static void PrintAllPrimesFrom1ToNumber(short Number)
 {
     for (short i = 1; i <= Number; i++)
         (PrimeChecker(i) == enPrimeNotPrime::Prime) ? cout << i << " Is Prime" << endl : cout << i << " is Not Prime" << endl;
 }

 //To Increase Bill With 16% -> TotalBill=Bill*1.16  
 static float BillAfterIncreacingPercent(float Percent, float Bill)
 {
     Percent = stof(to_string(1) + "." + to_string(Bill));
     return Bill * Percent;
}

 //Conversion
 static float HoursToDays(float NumberOfHours)
 {
     return NumberOfHours / 24;
 }

 static float HoursToWeeks(float NumberOfHours)
 {
     return NumberOfHours / 168;
 }

 static float DaysToWeeks(float NumberOfDays)
 {
     return NumberOfDays / 7;
 }

 static float SecondsInHours(float Hours)
 {
     return Hours * (60 * 60);
 }

 static float SecondsInMintues(float Mins)
 {
     return Mins * 60;
 }

 static float SecondsInDays(float Days)
 {
     return Days * (24 * 60 * 60);
 }

 static float CalculateNumberOfSeconds(float NumberOfDays, float NumberOfHours, float NumberOfMintues, float NumberOfSeconds)
 {
     float TotalNumberOfSeconds = SecondsInDays(NumberOfDays) +
         SecondsInHours(NumberOfHours) + SecondsInMintues(NumberOfMintues) +
         NumberOfSeconds;

     return TotalNumberOfSeconds;
 }

 //Duration In Seconds

 struct stTaskDuration { float NumberOfDays, NumberOfHours, NumberOfMintues, NumberOfSeconds; };

 static stTaskDuration ReadTaskDuration()
 {
     stTaskDuration TaskDuration;

     TaskDuration.NumberOfDays =    ReadFloatPositiveNumber("Please Enter Number Of Days? ");
     TaskDuration.NumberOfHours =   ReadFloatPositiveNumber("Please Enter Number Of Hours? ");
     TaskDuration.NumberOfMintues = ReadFloatPositiveNumber("Please Enter Number Of Minitues? ");
     TaskDuration.NumberOfSeconds = ReadFloatPositiveNumber("Please Enter Number Of Seconds? ");

     return TaskDuration;
 }

 static float TaskDurationInSeconds(stTaskDuration TaskDuration)
 {
     float DurationInSeconds = 0;
     DurationInSeconds += TaskDuration.NumberOfDays * 24 * 60 * 60;
     DurationInSeconds += TaskDuration.NumberOfHours * 60 * 60;
     DurationInSeconds += TaskDuration.NumberOfMintues * 60;
     DurationInSeconds += TaskDuration.NumberOfSeconds;

     return DurationInSeconds;
 }

 //static stTaskDuration SecondsToTaskDurations(int TotalSeconds)
 //{
 //    stTaskDuration TaskDuration;
 //    const int SecondsPerDay = 24 * 60 * 60;
 //    const int SecondsPerHour = 60 * 60;
 //    const int SecondsPerMinute = 60;


 //    TaskDuration.NumberOfDays = TotalSeconds / SecondsPerDay;
 //    TotalSeconds = fmod(TotalSeconds, SecondsPerDay);
 //    TaskDuration.NumberOfHours = TotalSeconds / SecondsPerHour;
 //    TotalSeconds = fmod(TotalSeconds, SecondsPerHour);
 //    TaskDuration.NumberOfMintues = TotalSeconds / SecondsPerMinute;
 //    TotalSeconds = fmod(TotalSeconds, SecondsPerMinute);
 //    TaskDuration.NumberOfSeconds = TotalSeconds;

 //    return TaskDuration;
 //}

 //Print Multiplication Table
 static void printN_char(int counter = 30, char ch = '-')
 {
     cout << endl;
     for (int i = 0; i < counter; i++)
     {
         cout << ch;
     }
     cout << endl;
 }

 static void PrintTableHeader()
 {
     cout << "\n\n\t\t\tMultiplication Table From 1 To 10 \n\n";
     cout << "\t";

     for (int i = 1; i <= 10; i++)
     {
         cout << i << "\t";
     }

     printN_char(90, '-');
 }

 static string ColumSperator(int i)//1 || 2 digits
 {
     return (i <= 9) ? "   |" : "   |";
 }

 static void PrintMultiplicationTable()
 {
     PrintTableHeader();
     for (int i = 1; i <= 10; i++)
     {
         cout << " " << i << ColumSperator(i) << "\t";
         for (int j = 1; j <= 10; j++)
         {
             cout << i * j << "\t";
         }
         cout << endl;
     }
 }


 //Perfect Or Not
//Perfect ==> 6 ==> (1 + 2 + 3 = 6) 
//sum of its divisors equal it

 enum enPerfectOrNot { Perfect = 1, NotPerfect = 2 };

 static enPerfectOrNot PerfectChecker(int Number)
 {
     short mid = Number / 2, Sum = 0;
     for (short i = 1; i <= mid; i++)
     {
         if (Number % i == 0)
             Sum += i;
     }

     return (Sum == Number) ? enPerfectOrNot::Perfect : enPerfectOrNot::NotPerfect;
 }

 static void PrintNumberPerfectOrNot(int Number)
 {
     (PerfectChecker(Number) == enPerfectOrNot::Perfect) ? cout << Number << " is Perfect" << endl : cout << Number << " is Not Perfect" << endl;
 }

static void PrintPerfectNumbersFrom1ToN(int Number)
 {
     for (int i = 1; i <= Number; i++)
         PrintNumberPerfectOrNot(i);
 }


static void PrintDigits(int Number)
{
    int  Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        cout << Remainder << endl;
    }
}

static int GetSumOfDigits(int Number)
{
    int SumOfDigits = 0;

    while (Number > 0)
    {
        SumOfDigits += Number % 10;
        Number /= 10;
    }

    return SumOfDigits;
}

static void PrintSumOfDigits(int Number)
{
    cout << "\nSum Of Digits For " << Number << " Is " << GetSumOfDigits(Number) << endl;
}

static int ReverseNumber(int Number)
{
    int ReversedNumber = 0;
    while (Number)
    {
        ReversedNumber = ReversedNumber * 10 + Number % 10;
        Number /= 10;
    }
    return ReversedNumber;
}

static short FrequencyOfDigit(int Number, short Digit)
{
    short Freq = 0;
    unsigned short Reminder = 0;

    while (Number)
    {
        Reminder = Number % 10;
        if (Reminder == Digit)Freq++;
        Number /= 10;
    }

    return Freq;
}

static void PrintAllDigitsFrequencey(int Number)
{
    for (int i = 0; i < 10; i++) //explicity digits [0 - 9]
    {
        short DigitFrequency = 0;
        DigitFrequency = FrequencyOfDigit(i, Number);
        (DigitFrequency) ? cout << "\nFrequency Of " << i << " Is " << DigitFrequency << " Time(s)" << endl : cout << "";
    }
}

static void PrintDigitsInEnteredOrder(int Number)
{
    while (Number)
    {
        cout << Number % 10 << endl;
        Number /= 10;
    }
}

static void  PrintDigitsInReversedOrder(int Number)
{
    Number= ReverseNumber(Number);
    while (Number)
    {
        cout << Number % 10 << endl;
        Number /= 10;
    }
}


static bool PalindromeChecker(int Number)
{
    return(Number == ReverseNumber(Number));
}

static void PrintPalindromOrNot(int Number)
{
    (PalindromeChecker(Number)) ?
        cout << Number << " Is Palindrome\n" : cout << Number << " Is NOT Palindrome\n";
}


//Inverted Number Pattern

////3 =>  333 22 1
//void InvertedNumberPattern(int Number)
//{
//    for (int i = Number; i > 0; i--)
//    {
//        for (int j = 1; j <= i; j++)
//        {
//            cout << i << " ";
//        }cout << endl;
//    }
//}

//3  => 1 22 333
static void InvertedNumberPattern(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }cout << endl;
    }
}

static void InvertedLetterPattern(int Number)
{
    for (short i = (Number - 1) + 'A'; i >= 'A'; i--)
    {
        for (short j = 'A'; j <= i; j++)
        {
            cout << char(i) << " ";
        }cout << endl;
    }
}

static void PrintLetterPattern(int Number)
{
    cout << "\n";
    for (int i = 'A'; i <= (Number - 1) + 'A'; i++)
    {
        for (int j = 'A'; j <= i; j++)
        {
            cout << char(i) << " ";
        }cout << endl;
    }
}


//All Words Possible From AAA To ZZZ
static void AllWordsPossibleFromAAAToZZZ()
{
    for (int i = 'A'; i <= 'Z'; i++)
    {
        cout << "---------------------------" << endl;
        // cout<<char(i)<<": "<<endl;
        for (int j = 'A'; j <= 'Z'; j++)
        {
            for (int k = 'A'; k <= 'Z'; k++)
            {
                cout << char(i) << " " << char(j) << " " << char(k) << "\n";
            }
        }
    }
}

//Encryption & Decription
static string EncryptText(string Text, short EncryptionKey=2)
{
    for (int i = 0; i < Text.size(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }

    return Text;
}

static string DecryptText(string Text, short EncryptionKey=2)
{
    for (int i = 0; i < Text.size(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}

static string Tabs(short TabsNumber)
{
    string sTabs = "";
    for (short i = 0; i < TabsNumber; i++)
        sTabs += "\t";

    return sTabs;
}

static void Srand()
{
    //seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));
}

static int RandomNumber(short From, short To)
{
    //function To Generate Random Number
    return (rand() % (To - From + 1) + From);
}

enum enCharType { SamallLetter = 1, CapitalLetter = 2,Digit = 3, SpecialCharacter = 4 ,MixChars=5};
static char GetRandomCharacter(enCharType CharType)
{
    //updated this method to accept mixchars
    if (CharType == MixChars)
    {
        //Capital/Samll/Digits only
        CharType = (enCharType)RandomNumber(1, 3);

    }

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


//Generate Keys
//write a program to read how many key to generate and print them on the screen
//like MKRS-LFEF-FSCW-EDST 4 4 4 4
//4 words , each word consists of 4 random characters and a dash between them

static string GenerateWord(enCharType CharType,short WordLength=4)  //DFGE
{
    string Word = "";

    for (int i = 1; i <= WordLength; i++)
    {
        Word += GetRandomCharacter(CharType);
    }

    return Word;
}

static string GenerateKey(enCharType CharType)
{
    string Key = "";

    Key += (GenerateWord(CharType) + '-');
    Key += (GenerateWord(CharType) + '-');
    Key += (GenerateWord(CharType) + '-');
    Key += (GenerateWord(CharType));

    return Key;
}

static void GenerateKeys(short NumberOfKeys, enCharType CharType)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "] : " << GenerateKey(CharType) << endl;
    }
}


//Number Repeated In Array
static void ReadArray(int* Arr, short size)
{
    for (short i = 0; i < size; i++)
    {
        cout << "Enter Element [" << i + 1 << "] : ";
        cin >> Arr[i];
    }
}

static void PrintArray(int* Arr, short size)
{
    for (short i = 0; i < size; i++)
    {
        cout << "Element [" << i + 1 << "] : "<<Arr[i]<<"\n";
    }
}

template<class Type, size_t size>
static void PrintArray_V2(Type(&Array)[size])
{
    int counter = 0;
    cout << "Array Elements:\n";

    for (auto Item : Array)
    {
        cout << "Element [" << ++counter << "] : " << Item << endl;
    }
}

template<class Type, size_t arrLength>
static size_t ArrayLength(Type(&Array)[arrLength])
{
    return arrLength;
}

static short TimesRepeated(int Number, int* Array, short size)
{
    short counter = 0;
    for (short i = 0; i < size; i++)
    {
        if (Array[i] == Number)
            counter++;
    }

    return counter;
}

//fill array with random numbers from,to 
static void FillArrayWithRandomNumbers(int *Arr, short arrLength,short From , short To)
{
    for (int i = 0; i < arrLength; i++)
    {
        Arr[i] = RandomNumber(From, To);
    }
}

//Min Max In Array
static int MaxOfArray(int *Arr, short arrLength)
{
    int Max = Arr[0];
    for (int i = 1; i < arrLength; i++)
    {
        if (Arr[i] > Max)
            Max = Arr[i];
    }
    return Max;
}

static int MinOfArray(int* Arr, int arrLength)
{
    int Min = Arr[0];
    for (int i = 1; i < arrLength; i++)
    {
        if (Arr[i] < Min)
            Min = Arr[i];
    }
    return Min;
}

static vector<int>MinMaxInArray(int* Arr, short arrLength)
{
    return { MinOfArray(Arr, arrLength) , MaxOfArray(Arr, arrLength) };
}

static int SumOfArray(int* Arr, short arrLength)
{
    int sum = 0;
    for (int i = 0; i < arrLength; i++)
    {
        sum += Arr[i];
    }
    return sum;
}

static float AverageOfArray(int *Arr, short arrLength)
{
    return (float)SumOfArray(Arr, arrLength) / arrLength;
}

//Copy Array
static void CopyArray(int *SourceArray, short arrLength, int* CopiedArray)
{
    for (int i = 0; i <= arrLength - 1; i++)
        CopiedArray[i] = SourceArray[i];
}

static void CopyArrayPrimes(int *SourceArray, short arrLength, int *DestinationArray, short& DestenationLen)
{
    DestenationLen = 0;
    for (int i = 0; i <= arrLength - 1; i++)
    {
        if (PrimeChecker(SourceArray[i]) == enPrimeNotPrime::Prime)
        {
            DestinationArray[DestenationLen++] = SourceArray[i];
        }
    }
}


static void Sum2Arrays(int *arr, int *arr2, short arrLength, int *arr3)
{
    for (short i = 0; i < arrLength; i++)
        arr3[i] = arr[i] + arr2[i];
}

template<class Type>
static void Swap(Type& a, Type& b)
{
        Type temp = a;
        a = b;
        b = temp;
}

static void SwapDates(clsDate& Date1, clsDate& Date2)
{
    clsDate::SwapDates(Date1, Date2);
}

template<class Type>
static void ShuffleOrderArray(Type* Array, short size)
{
    for (short i = 0; i < size; i++)
    {
        Swap(Array[RandomNumber(1, size) - 1], Array[RandomNumber(1, size) - 1]);///////////Monster
    }
}

static void CopyArrayInReverseOrder(int* arr1, int* arr2, short size)
{
    for (int i = 0; i < size; i++)
        arr2[i] = arr1[size - i - 1];
}

static void FillArrayWithRandomWords(string* arr, short size, enCharType CharType)
{
    for (short i = 0; i < size; i++)
        arr[i] = GenerateWord(CharType);
}

static void FillArrayWithRandomKeys(string* arr, short size, enCharType CharType)
{
    for (short i = 0; i < size; i++)
        arr[i] = GenerateKey(CharType);
}

static short SearchForIndex(int* arr, int size, int Goal)
{
    for (short i = 0; i < size; i++)
    {
        if (arr[i] == Goal)
            return i;
    }
    return -1;
}

static bool CheckNumberInArray(int* arr, short size, int Goal)
{
    return (SearchForIndex(arr, size, Goal) != -1);
}

static void AddArrayElement(int Number, int *arr, int& arrLength)
{
    arr[arrLength++] = Number;
}

static void CopyOddOnly(int *arr, int arrLength, int *arr2, int& arrLength2)
{
    for (int i = 0; i < arrLength; i++)
    {
        if ((CheckNumberType(arr[i])) == enNumberType::Odd)//we can do (arr[i]%2!=0)
            AddArrayElement(arr[i], arr2, arrLength2);
    }
}

static void CopyEvenOnly(int arr[100], int arrLength, int* arr2, int& arrLength2)
{
    for (int i = 0; i < arrLength; i++)
    {
        if ((CheckNumberType(arr[i])) == enNumberType::Even)//we can do (arr[i]%2!=0)
            AddArrayElement(arr[i], arr2, arrLength2);
    }
}

static void CopyPrimesOnly(int arr[100], int arrLength, int arr2[100], int& arrLength2)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (PrimeChecker(arr[i]) == enPrimeNotPrime::Prime)
            AddArrayElement(arr[i], arr2, arrLength2);
    }
}

enum enState { Found = 1, NotFound = 2 };
static enState SearchNumberFoundOrNot(int Number, int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (Number == arr[i])
            return enState::Found;
    }
    return enState::NotFound;
}

static bool DistinctOrNot(int Number, int arr[], int arrLength)
{
    return (SearchNumberFoundOrNot(Number, arr, arrLength) == enState::NotFound);
}

static void CopyDistinctNumbers(int *arr, int arrLength, int *arr2, int& arrLength2)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (DistinctOrNot(arr[i], arr2, arrLength2))
            AddArrayElement(arr[i], arr2, arrLength2);
    }
}

static bool PalindromeArrayOrNotFaster(int* arr, int arrLength)///////Without Reversing
{
     for (int LeftSide = 0, RightSide = arrLength - 1; LeftSide < arrLength, LeftSide <= RightSide; LeftSide++, RightSide--)
     {
     if (arr[LeftSide] != arr[RightSide])
         return false;
     }
    return true;
}

static int OddCount(int* arr, int arrLength)
{
    short counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckNumberType(arr[i]) == enNumberType::Odd)
            counter++;
    }
    return counter;
}

static int EvenCount(int* arr, int arrLength)
{
    short counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] % 2 == 0)
            counter++;
    }
    return counter;
}

static int PositiveCount(int* arr, int arrLength)
{
    int counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] >= 0)
            counter++;
    }
    return counter;
}

static int NegativeCount(int* arr, int arrLength)
{
    int counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] < 0)
            counter++;
    }
    return counter;
}

static float MyABS(float Number)
{
    return (Number >= 0) ? Number : -1 * Number;
}
 
static float GetFraction(float Number)
{
    return Number - (int)Number;
}

static int MyRound(float Number)
{
    int IntPart = (int)Number;
    float FractionPart = GetFraction(Number);

    if (abs(FractionPart) >= .5)
    {
        if (IntPart >= 0)
            return ++IntPart;
        else
            return --IntPart; //-3.5 => -3-1=-4
    }
    else
        return IntPart;
}

static int MyFloor(float Number)//the first int Number less than this number****
{
    return (Number >= 0) ? (int)Number : (int)Number - 1;
}

static int MyCeil(float Number)//the first int Number greater than this number****
{
    return(Number >= 0 && Number != (int)Number) ? (int)Number + 1 : (int)Number;//-3.5=>-3
}

static int MySqrt(float Number)
{
    return pow(Number, 0.5);
}


static void LowerِAllString(string& Str)
{
    for (short i = 0; i < Str.length(); i++)
    {
        if (isupper(Str[i]))
            Str[i] = tolower(Str[i]);
    }

}

static void UpperAllString(string& Str)
{
    for (short i = 0; i < Str.length(); i++)
    {
        if (islower(Str[i]))
            Str[i] = toupper(Str[i]);
    }

}

static short GetNumberOfDigitInsideString(string& Str)
{
    short NumberOfDigit = 0;

    for (short i = 0; i < Str.length(); i++)
    {
        if (isdigit(Str[i]))
            NumberOfDigit++;
    }

    return NumberOfDigit;
}

static short GetNumberOfPunctuationsInsideString(string& Str)
{
    short NumberOfPunctuations = 0;

    for (short i = 0; i < Str.length(); i++)
    {
        if (ispunct(Str[i]))
            NumberOfPunctuations++;
    }

    return NumberOfPunctuations;
}


static void PrintLocalTime()
{
    time_t CurrentTime = time(NULL); // get time now

    char* dt = ctime(&CurrentTime); // convert CurrentTime into string 
    cout << "Local Date And Time Is " << dt << endl;

    tm* GrenithTime = gmtime(&CurrentTime);  // converting now to tm struct for UTC date/time
    dt = asctime(GrenithTime);
    cout << "UTC Date And Time Is " << dt << endl;

}

static void PrintCurrentTime()
{
    /*
int tm_sec;   // seconds of minutes from 0 to 61
int tm_min;   // minutes of hour from 0 to 59
int tm_hour;  // hours of day from 0 to 24
int tm_mday;  // day of month from 1 to 31
int tm_mon;   // month of year from 0 to 11
int tm_year;  // year since 1900
int tm_wday;  // days since sunday
int tm_yday;  // days since January 1st
int tm_isdst; // hours of daylight savings time
*/

    time_t t = time(0);  // get time now

    tm* now = localtime(&t);
    cout << "Today Is : ";
    cout << now->tm_mday << "/"<< now->tm_mon + 1 << "/"<< now->tm_year + 1900 << "\n";
}

//3*3 Random Matrix
static void FillMatrixWithRandomNumbers(short Matrix2D[Row][Col])
{
    for (short i = 0; i < Row; i++)
        for (short j = 0; j < Col; j++)
            Matrix2D[i][j] = RandomNumber(1, 100);
}

static void PrintMatrix(short Matrix2D[Row][Col])
{
    cout << "The Folowing is 3*3 Matrix With Random Numbers[1-100] \n";
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            //for Good Formating
            cout << setw(3) << Matrix2D[i][j] << "   ";///////setwidth
        }
        cout << endl;
    }
}

//3*3 Sum Each Row In Matrix
static short RowSum(short Matrix2D[3][3], short RowNumber)
{
    short Sum = 0;

    for (short j = 0; j < Col; j++)
    {
        Sum += Matrix2D[RowNumber][j];
    }

    return Sum;

}

static void PrintEachRowSum(short Matrix2D[3][3])
{
    cerr << "\n\nThe Following Are The Sum Of Each Row In 3*3 Matrix:\n";
    for (short i = 0; i < Row; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << RowSum(Matrix2D, i) << endl;
    }
}

static void FillMatrixWithOrderedNumbers(short Matrix2D[3][3],short StartOrder = 1)
{   
    for (short i = 0; i < Row; i++)
        for (short j = 0; j < Col; j++)
            Matrix2D[i][j] = StartOrder++;
}

// Transposed Matrix  [i,j]⇒[j,i]
static void TransposeMatrix(short Matrix2D[Row][Col], short ArrTransposed[Row][Col])
{

    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            ArrTransposed[i][j] = Matrix2D[j][i];
        }
    }
}

//swap row X with row Y
//swap column X with column Y
//https://codeforces.com/group/MWSDmqGsZm/contest/223205/submission/211155536


//Myltiply Matrices
// Function to multiply two 2D matrices
static vector<vector<int>> multiplyMatricesWithUsingVector(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    // Check if the matrices can be multiplied
    if (cols1 != rows2) {
        cout << "Error: Matrices cannot be multiplied." << endl;
        return {};
    }

    // Create the resulting matrix with appropriate dimensions
    vector<vector<int>> result(rows1,vector<int>(cols2, 0));

    // Perform matrix multiplication
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

static void PrintMiddleRowOfMatrix(short Matrix2D[Row][Col])
{
    short MiddleRow = Row / 2;

    cout << "\n\nMiddle Row Of Matrix 1 : \n";
    for (short j = 0; j < Col; j++)
    {
        printf("%0*d   ", 2, Matrix2D[MiddleRow][j]);
    }
}

static void PrintMiddleColOfMatrix(short Matrix2D[Row][Col])
{
    short MiddleCol = Col / 2;

    cout << "\n\nMiddle Col Of Matrix 1 : \n";
    for (short i = 0; i < Row; i++)
    {
        printf("%0*d   ", 2, Matrix2D[i][MiddleCol]);
    }
}

static short SumOfMatrix(short Matrix2D[Row][Col])
{
    short Sum = 0;

    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            Sum += Matrix2D[i][j];
        }
    }
    return Sum;
}

//Equivalent Or Not
static bool EquivalentOrNot(short Matrix1[Row][Col], short Matrix2[Row][Col])
{
    return (SumOfMatrix(Matrix1) == SumOfMatrix(Matrix2));
}

static bool AreTypicalMatrices(short Matrix1[Row][Col], short Matrix2[Row][Col])
{
    for (short i = 0; i < 3; i++)
        for (short j = 0; j < 3; j++)
            if (Matrix1[i][j] != Matrix2[i][j])
                return false;

    return true;
}

static bool IdentityOrNot(short Matrix1[Row][Col])
{
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            if (i == j && Matrix1[i][j] != 1)
                return false;

            else if (i != j && Matrix1[i][j] != 0)
                return false;
        }
    }
    return true;
}

static void FillIdentityMatrix(short Matrix2D[Row][Col])
{
    for (short i = 0; i < 3; i++)
        for (short j = 0; j < 3; j++)
            if (i == j)
                Matrix2D[i][j] = 1;
            else
                Matrix2D[i][j] = 0;
}


//Identity But Main Diagonal 1 Or Other 
static void FillScalarMatrix(short Matrix2D[3][3])
{
    short ScalarNumber = RandomNumber(1, 9);

    for (short i = 0; i < 3; i++)
        for (short j = 0; j < 3; j++)
            if (i == j)
                Matrix2D[i][j] = ScalarNumber;
            else
                Matrix2D[i][j] = 0;
}

static bool ScalarOrNot(short Matrix1[Row][Col])
{
    short FirstDiagonalElement = Matrix1[0][0];
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            if (i == j && Matrix1[i][j] != FirstDiagonalElement)
                return false;

            else if (i != j && Matrix1[i][j] != 0)
                return false;
        }
    }
    return true;
}

static short CountNumberInMatrix(short Number, short Matrix2D[Row][Col])
{
    short Counter = 0;
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            if (Number == Matrix2D[i][j])
                Counter++;
        }
    }
    return Counter;
}

static void FillAlmostMatrixWithZero(short Matrix2D[3][3])
{
    for (short i = 0; i < Row; i++)
        for (short j = 0; j < Col; j++)
            if (i == j)
                Matrix2D[i][j] = 5;
            else
                Matrix2D[i][j] = 0;
}

//Sparce Matrix [ Number Of Zeros > Number Of The Rest Elemetns ]
static bool SparceOrNot(short Matrix2D[Row][Col])
{
    short NumberOfZeros = CountNumberInMatrix(0, Matrix2D);
    return NumberOfZeros > (Row * Col / 2); // => 9/2=4 , 0=>5 other=>4 (ok)
}

static bool NumberFoundInMatrixOrNot(short Matrix2D[Row][Col], short Number)
{
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            if (Number == Matrix2D[i][j])
                return true;
        }
    }
    return false;
}

static void GetIntersectedNumbersInMatrices(short Matrix1[Row][Col], short Matrix2[Row][Col], vector<short>& vItersectedNumbers)
{
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            if (NumberFoundInMatrixOrNot(Matrix2, Matrix1[i][j]))
                vItersectedNumbers.push_back(Matrix1[i][j]);
        }
    }
}

static void PrintIntersectedNumbers(vector<short>& vItersectedNumbers)
{
    if (vItersectedNumbers.empty())
    {
        cout << "\nNo Intersected Numbers!!!\n";
        return;
    }

    sort(vItersectedNumbers.begin(), vItersectedNumbers.end(), CompareRight); // 1 1 1 2 3  ==> 1 2 3

    cout << "\nInterseced Numbers : ";
    cout << setw(3) << vItersectedNumbers[0] << " ";
    for (short i = 1; i < vItersectedNumbers.size(); i++)
    {
        if ((vItersectedNumbers[i] != vItersectedNumbers[i - 1]))
            cout << setw(3) << vItersectedNumbers[i] << " ";
    }
    cout << endl;
}

static short FindMinInMatrix(short Matrix2D[3][3])
{
    short Min = Matrix2D[0][0];
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (Matrix2D[i][j] < Min)
            {
                Min = Matrix2D[i][j];
            }
        }
    }
    return Min;
}

static short FindMaxInMatrix(short Matrix2D[Row][Col])
{
    short Max = Matrix2D[0][0];
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (Matrix2D[i][j] > Max)
            {
                Max = Matrix2D[i][j];
            }
        }
    }
    return Max;
}

static vector<short>FindMinMaxInMatrix(short Matrix2D[Row][Col])
{
    return { FindMinInMatrix(Matrix2D) , FindMaxInMatrix(Matrix2D) };
}


static bool PalindromMatrix(short Matrix1[Row][Col]) ///////******
{
    short ReverseMatrix[Row][Col];
    ReversedMatrix(Matrix1, ReverseMatrix);

    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col / 2; j++) //You Don't Need To Go To Col (++ =>) , (<= --) ,Stop When You Reached To The Middle 
        {
            if (Matrix1[i][j] != ReverseMatrix[i][j])
                return false;
        }
    }

    return true;
}

static void ReversedMatrix(short Matrix1[Row][Col], short ReversedMatrix[Row][Col])
{
    for (int i = 0; i < Row; ++i) {
        for (int j = 0; j < Col; ++j) {
            ReversedMatrix[i][j] = Matrix1[Row - 1 - i][Col - 1 - j];
        }
    }

}

private:
    static bool CompareRight(short A, short B)
    {
        return A < B;
    }
};

