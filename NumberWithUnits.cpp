#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel{


        //Edge

// constaractors
        //NumberWithUnits::Edge::Edge(){};

        NumberWithUnits::Edge::Edge(double c , Unit* up ){
        change = c;
        to = up;
        }

        NumberWithUnits::Edge::~Edge(){};



        //Unit

// constaractors
        NumberWithUnits::Unit::Unit(){
            visited = false;
        }

        NumberWithUnits::Unit::Unit(string t ){
        type = move(t);
        visited = false;
        }

//public
        bool NumberWithUnits::Unit::search(const string& u){
            bool out = _search(u);
            reset();
            return out;
        }

        double NumberWithUnits::Unit::convert_num(const string& u){
            double conv = _convert_num(u);
            double out = 1 / conv;
            if (conv == 0){
                out = 0;
            }
            reset();
            return out;
        }

// private
        bool NumberWithUnits::Unit::_search(const string& u){
            if(visited){
                return false;
            }
            visited = true;
            if (u == type)
            {
                return true;
            }
            bool b = false;
            for(const auto & e : edges){
                b |= e.to->_search(u);
            }
            return b;
        }

        double NumberWithUnits::Unit::_convert_num(const string& u){
            if(visited){
                return 0;
            }
            visited = true;
            if (u == type)
            {
                return 1;
            }
            double b = 0;
            for(const auto & e : edges){
                b +=  e.change*e.to->_convert_num(u);
            }
            
            return b;
        }

        void NumberWithUnits::Unit::reset(){
            if(!visited){
                return;
            }
            visited = false;
            for(const auto & e : edges){
            e.to->reset();
            }
        }

    

    // NumberWithUnits

// graph initiator
    unordered_map<string,NumberWithUnits::Unit> NumberWithUnits::units;
// constaractors
    NumberWithUnits::NumberWithUnits(double number , string type){
        if(units.find(type) == units.end()){
            throw invalid_argument{"unit type invalid"};
        }
        num = number; 
        u_type = std::move(type);    
    }

// static 
    void NumberWithUnits::read_units(ifstream& os){
        string unit ;
        string change;
        string  unit2; 
        string in;
        while (os.good())
        {
            os >> in;
            if (in == "1")
            {
                os>>unit;
                os>>in;
                os>>change;
                os>>unit2;
                if(units.find(unit) == units.end()){
                units.insert({unit,Unit(unit)});
                }
                if(units.find(unit2) == units.end()){
                    units.insert({unit2,Unit(unit2)});
                }
                Unit* f = &(units.at(unit));
                Unit* s = &(units.at(unit2));
                double chan = stod(change);
                Edge e1 {chan , s};
                Edge e2 {1/chan , f};
                if(chan == 0){
                    e2.change = 0;
                }
                
                f->edges.insert(f->edges.end(),e1);
                s->edges.insert(s->edges.end(),e2);
            }
        }
        os.close();
    }

//private
    NumberWithUnits NumberWithUnits::convert(const NumberWithUnits& other)const{
        Unit * unit = NULL ;
        try{
         unit = &(units.at(u_type));
        }
        catch(const exception& e)
        {
            
        }

        if(unit->search(other.u_type)){
            return NumberWithUnits{unit->convert_num(other.u_type) * (other.num),u_type};
        }
        string message = "Units do not match - ";
        message += ("[" + other.u_type +"]");
        message += " cannot be converted to";
        message += (" [" + u_type + "]");
        throw invalid_argument{message}; 
    }


// arithmatic operators

// + 
    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits& other)
    {
        NumberWithUnits n = convert(other);
        NumberWithUnits out (n.num + num,u_type);
        return out;
    }

    NumberWithUnits NumberWithUnits::operator+() const
    { 
        NumberWithUnits out (num,u_type);
        return out;
    }

    NumberWithUnits& NumberWithUnits::operator += (const NumberWithUnits& other)
    {
        NumberWithUnits temp = *this + other;
        num = temp.num;
        return *this;
    }


// - 
    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& other)
    {
        NumberWithUnits n = convert(other);
        NumberWithUnits out (-n.num + num,u_type);
        return out;
    }

    NumberWithUnits NumberWithUnits::operator-() const
    {
        NumberWithUnits out (-num,u_type);
        return out;
    }
    
    NumberWithUnits& NumberWithUnits::operator -= (const NumberWithUnits& other)
    {
        NumberWithUnits temp = *this - other;
        num = temp.num;
        return *this;
    }


// boolean operators

// >
    bool NumberWithUnits::operator>(const NumberWithUnits& other)
    {
        {
        NumberWithUnits n = convert(other);
        bool b = num > n.num;
        return b;
    }
    }

    bool NumberWithUnits::operator>=(const NumberWithUnits& other)
    {
      {
        NumberWithUnits n = convert(other);
        bool b = num >= n.num;
        return b;
    }
    }

// <
    bool NumberWithUnits::operator<(const NumberWithUnits& other)
    {
       {
        NumberWithUnits n = convert(other);
        bool b = num < n.num;
        return b;
    }
    }

    bool NumberWithUnits::operator<=(const NumberWithUnits& other)
    {
       {
        NumberWithUnits n = convert(other);
        bool b = num <= n.num;
        return b;
    }
    }

// = / !
    bool NumberWithUnits::operator==(const NumberWithUnits& other)
    {
        NumberWithUnits n = convert(other);
        bool b = num == n.num;
        return b;
    }
    
    bool NumberWithUnits::operator!=(const NumberWithUnits& other)
    {
        NumberWithUnits n = convert(other);
        bool b = num != n.num;
        return b;
    }


// inner arithmatic operators

// +
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
    
//-
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

// * operators
    NumberWithUnits NumberWithUnits::operator*(double d)const
    {
        NumberWithUnits out(num*d,u_type);
        return out;
    }


    NumberWithUnits operator*(double d,const NumberWithUnits& n)
    {
        NumberWithUnits out(n.num*d,n.u_type);
        return out;
    }


// io operators
    istream& operator >> (istringstream& os ,  NumberWithUnits& n)
    {
        string s;
        string temp;
        while (os.good())
        {
            os>> temp;
            s += temp;
        }
        size_t i = 0;
        char c =s.at(0);
        string number ;
        while (c != '[')
        {
            number += c;
            c = s.at(++i);
        }
        c = s.at(++i);
        string type ;
        while (c != ']')
        {
            type += c;
            c = s.at(++i);
        }
        if(NumberWithUnits::units.find(type) == NumberWithUnits::units.end()){
            throw invalid_argument{"unit type invalid"};
        }
        n.num = stod(number);
        n.u_type = type;
        return os;
    }
    
    ostream& operator << (ostream& os , const NumberWithUnits& n)
    {return (os <<n.num << "[" << n.u_type<<"]");}
}