#ifndef GEBURTSTAGSPARTY_H
#define GEBURTSTAGSPARTY_H

#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <array>
#include <algorithm>
#include <ctime>
#include <vector>

using std::cout;

const int jan = 31, feb = 59, mar = 90, apr = 120, may = 151, jun = 181, 
          jul = 212, aug = 243, sep = 273, oct = 304, nov = 334, dec = 365;

class Date {
public:
    Date();
    void setRandomDate();
    int getDayInYear() const;
    int getDayInMonth() const;
    int getMonth() const;
    int getYear() const;
    std::string toString();  
private:
    int dayInYear;
    int year;

};


class Group {
public:
    Group() 
    : size{numberOfBirthdays} {}
    Group(int n);
    static const int numberOfBirthdays = 200;
    void sort();
    std::string toString();
    bool birthdayOnTheSameDay();
    std::array<Date,numberOfBirthdays> birthdays;
    int size;
private:    
    

};

bool operator<(Date const &a, Date const&b);
bool operator==(Date const &a, Date const &b);

void printer(Group &a);
void printday(Group &a);



#endif /* GEBURTSTAGSPARTY_H */

