#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
namespace ariel
{
    class NumberWithUnits
{
    private :    
        class Unit;

        class Edge
            { 
            public:
                double change;
                Unit * to; 
                //Edge();
                Edge(double c , Unit* up );
                ~Edge();
            };

        class Unit
         {
            private :
                bool _search(const string& u);
                double _convert_num(const string& u);
                void reset();
            public:
                string type;
                bool visited ;
                vector<Edge> edges;
                Unit();
                Unit(string t );
                bool search(const string& u);
                double convert_num(const string& u);
         };

        NumberWithUnits convert(const NumberWithUnits& other)const;
        //static string remove_space(const string& s);
        static double round5(const double& d);

        static unordered_map<string,Unit> units ;
        static constexpr double EPS = 0.001;

    public :
        double num ;
        string u_type;

        NumberWithUnits(double number , string type);

        static void read_units(ifstream& os);

        NumberWithUnits operator+(const NumberWithUnits& other)const;
        //NumberWithUnits operator+(const NumberWithUnits& other);

        NumberWithUnits operator+()const;

        NumberWithUnits& operator += (const NumberWithUnits& other);

        NumberWithUnits operator-(const NumberWithUnits& other)const ;

        NumberWithUnits operator-() const;

        NumberWithUnits& operator -= (const NumberWithUnits& other);

        bool operator>(const NumberWithUnits& other)const ;

        bool operator>=(const NumberWithUnits& other)const ;

        bool operator<(const NumberWithUnits& other)const ;

        bool operator<=(const NumberWithUnits& other) const;

        bool operator==(const NumberWithUnits& other) const;

        bool operator!=(const NumberWithUnits& other) const ;

        NumberWithUnits& operator ++ ();

        NumberWithUnits operator++(int dummy);
    
        NumberWithUnits& operator -- ();

        NumberWithUnits operator--(int dummy);

        NumberWithUnits operator*(double d) const;

        friend NumberWithUnits operator*(double d,const NumberWithUnits& n) ;

        friend istream& operator >> (istream& os ,  NumberWithUnits& n);

        friend ostream& operator << (ostream& os , const NumberWithUnits& n);

};


} 

