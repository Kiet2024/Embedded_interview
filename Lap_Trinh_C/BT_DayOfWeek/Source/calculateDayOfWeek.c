#include <stdio.h>
#include "calculateDayOfWeek.h"


int calculateNumberDayOfMonth (int month_input, int year_input) {
    switch (month_input)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return ((year_input % 400 == 0) || ((year_input % 4 == 0) && (year_input % 100 != 0)))?29:28;
    default:
        return 0;
    }

}

int calculateRemainingDays (int day_input, int month_input, int year_input) {

    int totalRemainingDays = day_input;
    for (int startMonth = 1; startMonth < month_input; startMonth++){

        totalRemainingDays = totalRemainingDays + calculateNumberDayOfMonth(startMonth, year_input);
    }
    return totalRemainingDays;

}


int calculateNumberOfDays(int day_input, int month_input, int year_input) {

    int totalDays = 0;
    for (int startYear = 1; startYear < year_input; startYear++){

        if ((startYear % 400 == 0) || ((startYear % 4 == 0) && (startYear % 100 != 0))){
            totalDays += 366;
        }
        else{
            totalDays += 365;
        }
    }
    totalDays = totalDays + calculateRemainingDays(day_input, month_input, year_input);
    return totalDays;

}

void dayOfWeek (int totalDays) {

    switch (totalDays % 7) {
    case 0:
        printf ("SUNDAY");
        break;
    case 1:
        printf ("MONDAY");
        break;
    case 2:
        printf ("TUESDAY");
        break;
    case 3:
        printf ("WEDNESDAY");
        break;
    case 4:
        printf ("THURSDAY");
        break;
    case 5:
        printf ("FRIDAY");
        break;
    case 6:
        printf ("SATURDAY");
        break;
    default:
        break;
    }

}