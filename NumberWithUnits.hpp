#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

using namespace std;
namespace ariel
{
    class NumberWithUnits
{
    private :
        // class Unit
        //  {
        //  public:
        //     string type;
        //     double change;
        //     Unit * to;
        //      Unit();
        //      ~Unit();
        //  };
        // NumberWithUnits convert(NumberWithUnits other);
        // unordered_map<string,Unit>* units;
    public:
        double num ;
        string u_type;
        NumberWithUnits(double number , string type);
        ~NumberWithUnits();

        static void read_units(ifstream& os);
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

