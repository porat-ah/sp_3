#include "doctest.h"
#include "NumberWithUnits.hpp"

using namespace ariel;

TEST_CASE("same unit +"){
    NumberWithUnits km1 = {10,"km"};
    NumberWithUnits km2 = {20,"km"};
    NumberWithUnits res = km1 + km2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "km");

    NumberWithUnits m1 = {10,"m"};
    NumberWithUnits m2 = {20,"m"};
    res = m1 + m2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "m");

    NumberWithUnits cm1 = {10,"cm"};
    NumberWithUnits cm2 = {20,"cm"};
    res = cm1 + cm2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "cm");

    NumberWithUnits kg1 = {10,"kg"};
    NumberWithUnits kg2 = {20,"kg"};
    res = kg1 + kg2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "kg");

    NumberWithUnits g1 = {10,"g"};
    NumberWithUnits g2 = {20,"g"};
    res = g1 + g2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "g");

    NumberWithUnits t1 = {10,"ton"};
    NumberWithUnits t2 = {20,"ton"};
    res = t1 + t2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "ton");

    NumberWithUnits h1 = {10,"hour"};
    NumberWithUnits h2 = {20,"hour"};
    res = h1 + h2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "hour");

    NumberWithUnits mn1 = {10,"min"};
    NumberWithUnits mn2 = {20,"min"};
    res = mn1 + mn2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "min");

    NumberWithUnits s1 = {10,"sec"};
    NumberWithUnits s2 = {20,"sec"};
    res = s1 + s2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "sec");

    NumberWithUnits d1 = {10,"USD"};
    NumberWithUnits d2 = {20,"USD"};
    res = d1 + d2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "USD");

    NumberWithUnits i1 = {10,"ILS"};
    NumberWithUnits i2 = {20,"ILS"};
    res = i1 + i2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "ILS");
}

TEST_CASE("multiunit +"){
    NumberWithUnits km1 = {10,"km"};
    NumberWithUnits m2 = {20*1000,"m"};
    NumberWithUnits res = km1 + m2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "km");

    NumberWithUnits m1 = {10,"m"};
    NumberWithUnits cm2 = {20*100,"cm"};
    res = m1 + cm2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "m");

    NumberWithUnits kg1 = {10,"kg"};
    NumberWithUnits g2 = {20*1000,"g"};
    res = kg1 + g2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "kg");

    NumberWithUnits t1 = {10,"ton"};
    NumberWithUnits kg2 = {20*1000,"kg"};
    res = t1 + kg2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "ton");

    NumberWithUnits h1 = {10,"hour"};
    NumberWithUnits mn2 = {20*60,"min"};
    res = h1 + mn2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "hour");

    NumberWithUnits mn1 = {10,"min"};
    NumberWithUnits s2 = {20*60,"sec"};
    res = mn1 + s2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "min");

    NumberWithUnits d1 = {10,"USD"};
    NumberWithUnits i2 = {20*3.33,"ILS"};
    res = d1 + i2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "USD");

}

TEST_CASE("different units + "){
    NumberWithUnits km = {10,"km"};
    NumberWithUnits m = {10,"m"};
    NumberWithUnits cm = {10,"cm"};
    NumberWithUnits d = {10,"USD"};
    NumberWithUnits i = {10,"ILS"};
    NumberWithUnits t = {10,"ton"};
    NumberWithUnits kg = {10,"kg"};
    NumberWithUnits g = {10,"g"};
    NumberWithUnits h = {10,"hour"};
    NumberWithUnits mn = {10,"min"};
    NumberWithUnits s = {10,"sec"};
    
    //km
    CHECK_THROWS(km+d);
    CHECK_THROWS(km+i);
    CHECK_THROWS(km+t);
    CHECK_THROWS(km+kg);
    CHECK_THROWS(km+g);
    CHECK_THROWS(km+h);
    CHECK_THROWS(km+s);
    CHECK_THROWS(km+mn);

    //m
    CHECK_THROWS(m+d);
    CHECK_THROWS(m+i);
    CHECK_THROWS(m+t);
    CHECK_THROWS(m+kg);
    CHECK_THROWS(m+g);
    CHECK_THROWS(m+h);
    CHECK_THROWS(m+s);
    CHECK_THROWS(m+mn);

    //cm
    CHECK_THROWS(cm+d);
    CHECK_THROWS(cm+i);
    CHECK_THROWS(cm+t);
    CHECK_THROWS(cm+kg);
    CHECK_THROWS(cm+g);
    CHECK_THROWS(cm+h);
    CHECK_THROWS(cm+s);
    CHECK_THROWS(cm+mn);

    //usd
    CHECK_THROWS(d+km);
    CHECK_THROWS(d+m);
    CHECK_THROWS(d+cm);
    CHECK_THROWS(d+t);
    CHECK_THROWS(d+kg);
    CHECK_THROWS(d+g);
    CHECK_THROWS(d+h);
    CHECK_THROWS(d+s);
    CHECK_THROWS(d+mn);

    //ils
    CHECK_THROWS(i+km);
    CHECK_THROWS(i+m);
    CHECK_THROWS(i+cm);
    CHECK_THROWS(i+t);
    CHECK_THROWS(i+kg);
    CHECK_THROWS(i+g);
    CHECK_THROWS(i+h);
    CHECK_THROWS(i+s);
    CHECK_THROWS(i+mn);
    
    //kg
    CHECK_THROWS(kg+d);
    CHECK_THROWS(kg+i);
    CHECK_THROWS(kg+km);
    CHECK_THROWS(kg+m);
    CHECK_THROWS(kg+cm);
    CHECK_THROWS(kg+h);
    CHECK_THROWS(kg+s);
    CHECK_THROWS(kg+mn);

    //g
    CHECK_THROWS(g+d);
    CHECK_THROWS(g+i);
    CHECK_THROWS(g+km);
    CHECK_THROWS(g+m);
    CHECK_THROWS(g+cm);
    CHECK_THROWS(g+h);
    CHECK_THROWS(g+s);
    CHECK_THROWS(g+mn);

    //g
    CHECK_THROWS(t+d);
    CHECK_THROWS(t+i);
    CHECK_THROWS(t+km);
    CHECK_THROWS(t+m);
    CHECK_THROWS(t+cm);
    CHECK_THROWS(t+h);
    CHECK_THROWS(t+s);
    CHECK_THROWS(t+mn);

    //h
    CHECK_THROWS(h+d);
    CHECK_THROWS(h+i);
    CHECK_THROWS(h+km);
    CHECK_THROWS(h+m);
    CHECK_THROWS(h+cm);
    CHECK_THROWS(h+kg);
    CHECK_THROWS(h+g);
    CHECK_THROWS(h+t);

    //mn
    CHECK_THROWS(mn+d);
    CHECK_THROWS(mn+i);
    CHECK_THROWS(mn+km);
    CHECK_THROWS(mn+m);
    CHECK_THROWS(mn+cm);
    CHECK_THROWS(mn+kg);
    CHECK_THROWS(mn+g);
    CHECK_THROWS(mn+t);

    //sec
    CHECK_THROWS(s+d);
    CHECK_THROWS(s+i);
    CHECK_THROWS(s+km);
    CHECK_THROWS(s+m);
    CHECK_THROWS(s+cm);
    CHECK_THROWS(s+kg);
    CHECK_THROWS(s+g);
    CHECK_THROWS(s+t);
}
