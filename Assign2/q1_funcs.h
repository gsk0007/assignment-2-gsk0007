#include <cmath>
#include <iostream>
#include <string>

void dateCheck(std::string dateString);

bool isLeapYear(int year){ 
    // If the year is divisible by 400, or the year is divisible by 4 and not divisible by 100
    // then return true (true that it is a leap year)
    if( year%400 == 0 || ((year%4 == 0) != (year%100 == 0))){
        return true;
    } else {
        return false;
    };
};

int getCenturyValue(int year){ 
    // Initalize variables needed for calculations
    int yearCounter = year;
    int yearRemain;

    // Find the first two digits of the year
    while (yearCounter >= 100 ){
        yearCounter = yearCounter/10;
    };

    // Calculate the remainder of dividing the first two digits of the year by 4 
    yearRemain = yearCounter%4;

    // Return the century value 
    return (3 - yearRemain)*2;
};

int getYearValue(int year){
    // Initalize variables needed for calculations
    int yearCounter = year;
    int yearRemain;
    int n = 0;
    int lastTwo;

    // Find the first two digits of the year
    while (yearCounter >= 100 ){
        yearCounter = yearCounter/10;
        n += 1;
    };

    // Calculate last two by subtracting the value that removes the first two digits
    lastTwo = year - (yearCounter*pow(10,n));

    // Return the year value
    return (lastTwo/4) + lastTwo;
};

int getMonthValue(int month, int year){
    // A function that is really just a table of given values
    // Based on whether it is a leap year or not, two branches are possible
    bool checkLeap = isLeapYear(year);
    if(checkLeap){
        switch (month)
        {
        case 1:
            return 6;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 5;
        default:
            exit(1);
        }
    } else {
        switch (month)
        {
        case 1:
            return 0;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 5;
        default:
            exit(1);
        }
    };
};

std::string getDayString(int dayResult){
    // A function that acts as a translation from an integer returned by an equation 
    // to a day of the week in english    
    switch (dayResult){
        case 0:
            return("Sunday");
        case 1:
            return("Monday");
        case 2:
            return("Tuesday");
        case 3:
            return("Wednesday");
        case 4:
            return("Thursday");
        case 5:
            return("Friday");
        case 6:
            return("Saturday");
        default:
            exit(1);
    };
};

void getDate(std::string &dateString){
    // function for getting a sring that is a date. 
    // It is a function so that it is callable by dateCheck when errors are made
    std::cout << "Input a date in the mm/dd/yyyy format: ";
    std::cin >> dateString;
    dateCheck(dateString);
};

void dateCheck(std::string dateString){
    // halfway input validation since it does not check/know if the day can actually exist 
    // in that month but it doesn't cause errors so oh well
    if(dateString.length() != 10){
        std::cout << "Looks like you may have not followed the date format, try again\n" <<
                    "Remember that if the day or month is a single digit, you need a 0 before it\n";
        getDate(dateString);
    };
    int month = stoi(dateString.substr(0,2));
    int day = stoi(dateString.substr(3,2));
    int year = stoi(dateString.substr(6,4));
    bool leapYear = isLeapYear(year);

    if(month<1 || month>12){
        std::cout << "Please check the month and try again\n";
        getDate(dateString);
    };

    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day<1 || day>31){
            std::cout << "Please check the day and try again\n";
            getDate(dateString);
        };
    } else if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day<1 || day>30){
            std::cout << "Please check the day and try again\n";
            getDate(dateString);
        };
    } else if(month == 2 && leapYear){
        if(day<1 || day>29){
            std::cout << "Please check the day and try again\n";
            getDate(dateString);
        };
    } else if(month == 2 && !leapYear){
        if(day<1 || day>28){
            std::cout << "Please check the day and try again\n";
            getDate(dateString);
        };
    } else{
        exit(1);
    };
    

    if(year<1){
        std::cout << "Please check the year and try again\n";
        getDate(dateString);
    };
};