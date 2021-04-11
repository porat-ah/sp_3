#include "doctest.h"
#include "NumberWithUnits.hpp"

using namespace ariel;

TEST_CASE("good plus"){
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

TEST_CASE("multiunit"){
    NumberWithUnits km1 = {10,"km"};
    NumberWithUnits m2 = {20,"m"};
    NumberWithUnits res = km1 + m2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "km");

    NumberWithUnits m1 = {10,"m"};
    NumberWithUnits cm2 = {20,"cm"};
    res = m1 + cm2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "m");

    NumberWithUnits kg1 = {10,"kg"};
    NumberWithUnits g2 = {20,"g"};
    res = kg1 + g2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "kg");

    NumberWithUnits t1 = {10,"ton"};
    NumberWithUnits kg2 = {20,"kg"};
    res = t1 + kg2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "ton");

    NumberWithUnits h1 = {10,"hour"};
    NumberWithUnits mn2 = {20,"min"};
    res = h1 + mn2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "hour");

    NumberWithUnits mn1 = {10,"min"};
    NumberWithUnits s2 = {20,"sec"};
    res = mn1 + s2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "min");

    NumberWithUnits d1 = {10,"USD"};
    NumberWithUnits i2 = {20,"ILS"};
    res = d1 + i2;
    CHECK(res.num  == 30);
    CHECK(res.u_type == "USD");

}

