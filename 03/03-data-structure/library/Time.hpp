#pragma once
#include <boost/date_time.hpp>
#include <iostream>

using boost::posix_time::ptime;

class Time
{
private:
    ptime time;
    std::string str_time;
    int day;

public:
    Time(){};
    Time now();
    std::string to_iso_string();
    Time from_iso_string(std::string &str);
    int day_differ(Time &gtime);
    std::string to_string();
};
