#include "NumberWithUnits.hpp"
using namespace std;
namespace ariel{
    NumberWithUnits::NumberWithUnits(double number , string type){
        num = number; 
        u_type = std::move(type); 
        // units = new unordered_map<string,Unit>;
    }
    NumberWithUnits::~NumberWithUnits(){
        // delete units;
    }

    void NumberWithUnits::read_units(ifstream& os){
    }

    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits& other)
    {return NumberWithUnits(0,"m");}
    NumberWithUnits NumberWithUnits::operator+()
    {return NumberWithUnits(num,u_type);}
    NumberWithUnits& NumberWithUnits::operator += (const NumberWithUnits& other)
    {
        NumberWithUnits temp = *this + other;
        num = temp.num;
        return *this;}

    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& other)
    {return NumberWithUnits(0,"m");}
    NumberWithUnits NumberWithUnits::operator-()
    {return NumberWithUnits(-num,u_type);}
    NumberWithUnits& NumberWithUnits::operator -= (const NumberWithUnits& other)
    {
        NumberWithUnits temp = *this - other;
        num = temp.num;
        return *this;}

    bool NumberWithUnits::operator>(const NumberWithUnits& other)
    {return false;}
    bool NumberWithUnits::operator>=(const NumberWithUnits& other)
    {return false;}

    bool NumberWithUnits::operator<(const NumberWithUnits& other)
    {return false;}
    bool NumberWithUnits::operator<=(const NumberWithUnits& other)
    {return false;}

    bool NumberWithUnits::operator==(const NumberWithUnits& other)
    {return false;}
    bool NumberWithUnits::operator!=(const NumberWithUnits& other)
    {return false;}

    NumberWithUnits& NumberWithUnits::operator ++ ()
    {
        ++num;
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator++(int dummy)
    {
        NumberWithUnits copy = *this;
        ++num;
        return copy;
    }
    
    NumberWithUnits& NumberWithUnits::operator -- ()
    {
        --num;
        return *this;  
    }

    NumberWithUnits NumberWithUnits::operator--(int dummy)
    { 
        NumberWithUnits copy = *this;
        --num;
        return copy;
    }

    NumberWithUnits NumberWithUnits::operator*(double d)
    {return NumberWithUnits(num*d,u_type);}

    NumberWithUnits operator*(double d,const NumberWithUnits& n)
    {return NumberWithUnits(n.num*d,n.u_type);}

    istream& operator >> (istream& os , const NumberWithUnits& n)
    {return os;}
    ostream& operator << (ostream& os , const NumberWithUnits& n)
    {return (os <<n.num << "[" << n.u_type<<"]");}
}