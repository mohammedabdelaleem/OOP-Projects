#include "clsPeriod.h"

int main()
{

    clsDate Date1;
    clsDate Date2(13,1,2003);
    clsDate Date3("12/5/2000");
    clsDate Date4(111, 2000);

   /* Date1.Print();
    Date2.Print();
    Date3.Print();
    Date4.Print();*/


   //cout<< clsDate::CalculateMyAgeInDays(Date2);
   


  
    clsPeriod Period1(Date1,Date4);
    clsPeriod Period2(Date3, Date2);
  
    Period1.Print();
    Period2.Print();





    system("Pause>0");
    return 0;
}
