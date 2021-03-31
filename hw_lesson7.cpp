#include <iostream>
#include <memory>
#include <cstdint>

//Task 1

class Date {

    int16_t m_day = 0;
    int16_t m_month = 0;
    int16_t m_year = 0;

public:

    Date(int16_t day, int16_t month, int16_t year)
    : m_day(day), m_month(month), m_year(year) {};

    int16_t getDay() {return m_day;}
    int16_t getMonth() {return m_month;}
    int16_t getYear() {return m_year;}

    friend std::ostream& operator<<(std::ostream& out, const std::unique_ptr<Date>& date);

};

std::ostream& operator<<(std::ostream& out, const std::unique_ptr<Date>& date) {
    out << "Day: " << date->getDay() << std::endl <<
    "Month: " << date->getMonth() << std::endl <<
    "Year: " << date->getYear() << "\n\n";
    return out;
}

//Task 2

int16_t compare (const std::unique_ptr<Date>& date1, const std::unique_ptr<Date>& date2) {

    if (date1->getYear() > date2->getYear()) {std::cout << date1; return 0;}
    else if (date1->getYear() < date2->getYear()) {std::cout << date2; return 0;}

    if (date1->getMonth() > date2->getMonth()) {std::cout << date1; return 0;}
    else if (date1->getMonth() < date2->getMonth()) {std::cout << date2; return 0;}

    if (date1->getDay() > date2->getDay()) {std::cout << date1; return 0;}
    else if (date1->getDay() < date2->getDay()) {std::cout << date2; return 0;}

}

void smart_ptr_swap(std::unique_ptr<Date>& date1, std::unique_ptr<Date>& date2) {

    // Best practice: std::swap(date1, date2);

    std::unique_ptr<Date> temp;

    temp = std::move(date1);
    date1 = std::move(date2);
    date2 = std::move(temp);

}


int main() {

    std::cout << "\n***Task 1***\n\n";

    std::unique_ptr<Date> today(new Date(31, 3,2021));
    std::unique_ptr<Date> date;

    std::cout << "Today is: " << today->getDay() << "." <<
    today->getMonth() << "." << today->getYear() << "\n\n";

    std::cout << today;

    date = std::move(today);

    if (today == nullptr) {std::cout << "'today' is nullptr";}
    if (date == nullptr) {std::cout << "'date' is nullptr\n";}

    std::cout << "\n\n***Task 2***\n\n";

    std::unique_ptr<Date> date1 = std::make_unique<Date>(20,10,1995);
    std::unique_ptr<Date> date2 = std::make_unique<Date>(15,12, 2002);

    std::cout << "Latest date is: \n";
    compare(date1, date2);

    std::cout << "Dates before swap:\n\nDate 1\n" << date1 << "Date 2\n" << date2;
    smart_ptr_swap(date1, date2);
    std::cout << "Dates after swap:\n\nDate 1\n" << date1 << "Date 2\n" << date2;

    return 0;
}
