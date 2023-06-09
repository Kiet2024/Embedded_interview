#include <stdio.h>
#include "calculateDayOfWeek.h"


int main()
{

    int day, month, year, totalDays;
    do
    {
        printf("Please enter a valid date: ");
        scanf("%d%d%d",&day, &month, &year);
    } while (day < 1 || day > calculateNumberDayOfMonth(month, year) || month < 1 || month > 12 || year < 1 );
   totalDays = calculateNumberOfDays(day, month, year);
   dayOfWeek(totalDays);

   return 0;

}


   /*
    //Tìm thứ của một ngày bằng công thức
        printf("Ngay %d Thang %d Nam %d la ",day, month, year);
        year -= (14 - month)/12;
        month += 12*((14 - month)/12) - 2;
        weekday = (day + year + year/4 - year/100 + year/400 + (31 * month)/12)%7;
        if (weekday == 0) {
            printf("chu nhat\n");
        }
        else{
            printf("thu %d\n ",weekday + 1);
        }
    */