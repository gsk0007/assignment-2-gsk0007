#include <iostream>
#include <string>
// Import all needed user defined functions for finding the day of the week
#include "q1_funcs.h"
using namespace std;

int main(){ 
    // initialize variables needed for calculations
    string dateString;
    int month;
    int day;
    int year;
    int MonthVal;
    int YearVal;
    int CenturyVal;
    int dayResult;
    string dayResultString;
    
    // get the date using the getDate Function. This also calls
    // the dateCheck function to make sure (lazily) that the date is valid.
    getDate(dateString);

    // parse the values needed for calculations out of the string
    month = stoi(dateString.substr(0,2));
    day = stoi(dateString.substr(3,2));
    year = stoi(dateString.substr(6,4));

    // Using the parsed values from above, call the functions specific for
    // calculating the day of the week
    MonthVal = getMonthValue(month, year);
    YearVal = getYearValue(year);
    CenturyVal = getCenturyValue(year);

    // Calculate number for determining the day of the week
    dayResult = (day + MonthVal + YearVal + CenturyVal)%7;
    
    // Call a function to get the day as a string
    dayResultString = getDayString(dayResult);
    // output day that is the date
    cout << dayResultString;
    return 0;
};


