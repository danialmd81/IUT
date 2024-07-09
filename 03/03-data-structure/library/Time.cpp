#include "Time.hpp"

using namespace std;

Time Time::now() // save present local time
{
    time = boost::posix_time::second_clock::local_time();
    return *this;
}

string Time::to_iso_string() // convert to iso string
{
    return str_time = boost::posix_time::to_iso_string(time);
}
Time Time::from_iso_string(string &str) // can read time from iso string
{
    time = boost::posix_time::from_iso_string(str);
    return *this;
}
int Time::day_differ(Time &gtime) // different in two time in hour
{
    day = (time - gtime.time).total_seconds();
    return abs(day /= 3600 * 24);
}

string Time::to_string() // convert to simple string
{
    return boost::posix_time::to_simple_string(time);
}