#include <iostream>
#include <iomanip>
#include <string>

int main(){
    //get inputs
    unsigned int year {};
    unsigned int first_day{};
    std::cout << "Enter a year : ";
    std::cin >> year;
    std::cout << "Enter the first day of they year [1: Monday, ... 7: Sunday]: ";
    std::cin >> first_day;
    std::cout << std::endl;

    std::cout << "Calender for " << year << std::endl;

    //find out if leap year
    bool leap_year;
    if (year%4 == 0 && year%100 !=0){
        leap_year = true;   
    }
    else if (year % 400 == 0){
        leap_year = true;
    }
    else {
        leap_year = false;
    }
    
    //place holderspace

    //MONTHS
    for (int MONTH {1}; MONTH < 13; ++MONTH){
    std::string month_name;
    int number_of_days_in_month;
    const int jan{1}, feb{2}, mar{3}, apr{4}, may{5}, jun{6}, jul{7}, aug{8},sep{9}, 
    oct{10}, nov{11}, dec{12}; 
    int month {MONTH};
    switch (month)
    {
    case jan:
        month_name = "January";
        number_of_days_in_month = 31;
        break;
    case feb:
        month_name = "Febuary";
        if (leap_year){
            number_of_days_in_month = 29;
        }
        else{
            number_of_days_in_month = 28;
        }
        break;

    case mar:
        month_name = "March";
        number_of_days_in_month = 31;
        break;
    case apr:
        month_name = "April";
        number_of_days_in_month = 30;
        break;
    case may:
        month_name = "May";
        number_of_days_in_month = 31;
        break;
    case jun:
        month_name = "June";
        number_of_days_in_month = 30;
        break;
    case jul:
        month_name = "July";
        number_of_days_in_month = 31;
        break;
    case aug:
        month_name = "August";
        number_of_days_in_month = 31;
        break;
    case sep:
        month_name = "September";
        number_of_days_in_month = 30;
        break;
    case oct:
        month_name = "October";
        number_of_days_in_month = 31;
        break;
    case nov:
        month_name = "November";
        number_of_days_in_month = 30;
        break;
    case dec:
        month_name = "December";
        number_of_days_in_month = 31;
        break;
    }
     
    std::cout << "-- " << month_name << " " << year << " --" << std::endl;
    std::cout << std::setw(5) << "Mon" << std::setw(5) << "Tue" << std::setw(5) << "Wed" 
    << std::setw(5) << "Thu"<< std::setw(5) << "Fri"<< std::setw(5) << "Sat"<< std::setw(5) << "Sun" 
    << std::endl;

    int D {1};
    while(D != first_day){
        std::cout << std::setw(5) << "  ";
        D++;
    }
    
    for (int date {1}; date < (number_of_days_in_month+1); ++date){
        std::cout << std::setw(5) << date;
        first_day+= 1;
        if (first_day == 8){
            std::cout << std::endl;
            first_day = 1;
        } 
    }
    std::cout << std::endl; std::cout << std::endl;
    }//MONTH BRACKET
    return 0;
}
