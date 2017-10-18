#include "Geburtstagsparty.h"

int randomInt(int lower, int upper)             // helper function
{                                               // using <cstdlib> rand()
    return rand() % (upper - lower) + lower;    // for pseudo randomness
}

Date::Date()                                    // default constructor
{
    setRandomDate();
}

void Date::setRandomDate()
{
    dayInYear = randomInt(1, 365);
    year = randomInt(1950, 2007);
}

int Date::getDayInYear() const
{
    return dayInYear;
}

int Date::getYear() const
{
    return year;
}

int Date::getMonth() const
{
    if(dayInYear <= jan) return 1;
    if(dayInYear <= feb) return 2;
    if(dayInYear <= mar) return 3;
    if(dayInYear <= apr) return 4;
    if(dayInYear <= may) return 5;
    if(dayInYear <= jun) return 6;
    if(dayInYear <= jul) return 7;
    if(dayInYear <= aug) return 8;
    if(dayInYear <= sep) return 9;
    if(dayInYear <= oct) return 10;
    if(dayInYear <= nov) return 11;
    if(dayInYear <= dec) return 12;
}

int Date::getDayInMonth() const
{
    if(dayInYear <= jan) return dayInYear;
    if(dayInYear <= feb) return dayInYear - jan;
    if(dayInYear <= mar) return dayInYear - feb;
    if(dayInYear <= apr) return dayInYear - mar;
    if(dayInYear <= may) return dayInYear - apr;
    if(dayInYear <= jun) return dayInYear - may;
    if(dayInYear <= jul) return dayInYear - jun;
    if(dayInYear <= aug) return dayInYear - jul;
    if(dayInYear <= sep) return dayInYear - aug;
    if(dayInYear <= oct) return dayInYear - sep;
    if(dayInYear <= nov) return dayInYear - oct;
    if(dayInYear <= dec) return dayInYear - nov;
}



std::string Date::toString()
{
    std::string res = "";
    std::ostringstream os;
    if (getDayInMonth() < 10) os << 0;         // füge 0 zu einstelligem Tag hinzu
    os << getDayInMonth() << ".";               
    if (getMonth() < 10) os << 0;              // füge 0 zu einstelliger Monatsnummer hinzu
    os << getMonth() << "." << year;
    res = os.str();
    return res; 
}

Group::Group(int n)
{
    if(n > 1 && n < numberOfBirthdays)
        size = n;
    else size = numberOfBirthdays;   
}



bool Group::birthdayOnTheSameDay() 
{
    for(int i = 0; i < size - 1; ++i){
        for(int j = i + 1; j < size; ++j)
            if (birthdays[i] == birthdays[j]) return true;
            //if (birthdays[i].getDayInYear() == birthdays[j].getDayInYear()) return true;
    }
    return false;
}


bool operator<(Date const& a, Date const &b)
{
    if(a.getYear() == b.getYear()) return a.getDayInYear() < b.getDayInYear();
    return a.getYear() < b.getYear();
}

bool operator==(Date const &a, Date const &b)
{
    return a.getDayInYear() == b.getDayInYear();
}

void Group::sort()
{
    std::sort(birthdays.begin(), birthdays.begin() + size);
}

void printer(Group &a)
{
    /*for(int i = 0; i < a.size; ++i) {
        if(i != 0 && i % 5 == 0) std::cout << "\n";
        std::cout << a.birthdays[i].toString() << "\t";
    }
    std::cout << "\n\n";
    */
    a.sort();
        for(int i = 0; i < a.size; ++i) {
        if(i != 0 && i % 5 == 0) std::cout << "\n";
        std::cout << a.birthdays[i].toString() << "\t";
    }
    std::cout << "\n\n";
}

void printday(Group &a)
{
    for(int i = 0; i < a.size; ++i) {
        if(i != 0 && i % 5 == 0) std::cout << "\n";
        std::cout << a.birthdays[i].getDayInYear() << "\t";
    }
    std::cout << "\n\n";
}