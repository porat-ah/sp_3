#include "NumberWithUnits.hpp"
namespace ariel{
    NumberWithUnits::NumberWithUnits(double number , string type)
    {num = number; u_type = std::move(type);}

    istream& NumberWithUnits::read_units(istream& os)
    {return os;}

    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits& other)
    {return NumberWithUnits(0,"m");}
    NumberWithUnits NumberWithUnits::operator+()
    {return NumberWithUnits(0,"m");}
    NumberWithUnits& NumberWithUnits::operator += (const NumberWithUnits& other)
    {return *this;}

    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& other)
    {return NumberWithUnits(0,"m");}
    NumberWithUnits NumberWithUnits::operator-()
    {return NumberWithUnits(0,"m");}
    NumberWithUnits& NumberWithUnits::operator -= (const NumberWithUnits& other)
    {return *this;}

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
    {return *this;}
    NumberWithUnits NumberWithUnits::operator++(int dummy)
    {return NumberWithUnits(0,"m");}
    
    NumberWithUnits& NumberWithUnits::operator -- ()
    {return *this;}
    NumberWithUnits NumberWithUnits::operator--(int dummy)
    {return NumberWithUnits(0,"m");}

    NumberWithUnits NumberWithUnits::operator*(double d)
    {return NumberWithUnits(0,"m");}
    NumberWithUnits operator*(double d,const NumberWithUnits& n)
    {return NumberWithUnits(0,"m");}

    istream& operator >> (istream& os , const NumberWithUnits& n)
    {return os;}
    ostream& operator << (ostream& os , const NumberWithUnits& n)
    {return os;}
}
