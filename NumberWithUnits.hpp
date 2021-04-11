#pragma once 

#include <iostream>
#include <string>

using namespace std;
namespace ariel
{
    class NumberWithUnits
{
public:
    double num ;
    string u_type;
    NumberWithUnits(double number , string type);

    static istream& read_units(istream& os);
    NumberWithUnits operator+(const NumberWithUnits& other) ;
    NumberWithUnits operator+() ;
    NumberWithUnits& operator += (const NumberWithUnits& other);
    NumberWithUnits operator-(const NumberWithUnits& other) ;
    NumberWithUnits operator-() ;
    NumberWithUnits& operator -= (const NumberWithUnits& other);

    bool operator>(const NumberWithUnits& other) ;
    bool operator>=(const NumberWithUnits& other)  ;
    bool operator<(const NumberWithUnits& other) ;
    bool operator<=(const NumberWithUnits& other) ;
    bool operator==(const NumberWithUnits& other) ;
    bool operator!=(const NumberWithUnits& other) ;

    NumberWithUnits& operator ++ ();
    NumberWithUnits operator++(int dummy);
    
    NumberWithUnits& operator -- ();
    NumberWithUnits operator--(int dummy);

    NumberWithUnits operator*(double d) ;
    friend NumberWithUnits operator*(double d,const NumberWithUnits& n);

    friend istream& operator >> (istream& os , const NumberWithUnits& n);
    friend ostream& operator << (ostream& os , const NumberWithUnits& n);

};


} 

