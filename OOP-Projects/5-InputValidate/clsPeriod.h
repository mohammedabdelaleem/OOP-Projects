#pragma once

#include "clsDate.h"

struct clsPeriod {

    static short Ctr;
    short ID;
    clsDate StartDate;
    clsDate EndDate;

public:
  
    clsPeriod() 
    {
        ID = ++Ctr; //1 2 3 ...
        cout << "\nEnter Period Number "<<ID <<"\n";

        cout << "\nEnter Start Date...\n";
        StartDate.ReadFullDate();

        cout << "\nEnter End Date...\n";
        EndDate.ReadFullDate();
    }

    clsPeriod(clsDate StartDate, clsDate EndDate) : StartDate(StartDate) , EndDate(EndDate)
    {
        ID = ++Ctr;
        ////We Can Use This->//////
    }



    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After
            )
            return false;
        else
            return true;

    }


    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }


 static  int GetPeriodLenthInDays(clsPeriod Period, bool IncludeEndDay = false)
   {

       return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);

   }

 int GetPeriodLenthInDays( bool IncludeEndDay = false)
 {
     return GetPeriodLenthInDays(*this, IncludeEndDay);
 }


 static bool IsDateWithInAPeriod(clsPeriod& Period, clsDate& Date)
 {
     return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::enDateCompare::Before
         || clsDate::CompareDates(Date, Period.EndDate) == clsDate::enDateCompare::After);
 }


 bool IsDateWithInAPeriod( clsDate& Date)
 {
     return IsDateWithInAPeriod(*this, Date);
 }

 //cout << max(l1, l2) << " " << min(r1, r2)
 static int CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
 {
     if (IsOverlapPeriods(Period1, Period2))  //what is the wrong?
     {

         clsDate BigDate = clsDate:: GetBigDate(Period1.StartDate, Period2.StartDate);
         clsDate SmallDate = clsDate::GetSmallDate(Period1.EndDate, Period2.EndDate);

         return abs(clsDate::GetDifferenceInDays(BigDate, SmallDate));
     }
     return 0;
 }

 int CountOverlapDaysWith( clsPeriod Period2)
 {
     return CountOverlapDays(*this, Period2);
 }


 void Print()
 {
     cout << "\nPeriod Number " << ID << endl;
     cout << "Period Start: ";
     StartDate.Print();


     cout << "Period End: ";
     EndDate.Print();

 }

};

short clsPeriod::Ctr = 0;