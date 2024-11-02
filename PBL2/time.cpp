#include "time.h"

thoigian::thoigian() : year(0), month(0), day(0), hour(0), minute(0), second(0) {};

thoigian::thoigian(int y = 0, int m = 0, int d = 0, int h = 0, int mi = 0, int s = 0) : year(y), month(m), day(d), hour(h), minute(mi), second(s) {};

istream &operator>>(istream &is, thoigian &t)
{
    return is >> t.second >> t.minute >> t.hour >> t.day >> t.month >> t.year;
}

ostream &operator<<(ostream &os, const thoigian &t)
{
    return os << t.second << t.minute << t.hour << t.day << t.month << t.year;
}

bool thoigian::operator==(const thoigian &dt1)
{
    return (this->second == dt1.second &&
           this->minute == dt1.minute &&
           this->hour == dt1.hour &&
           this->day == dt1.day &&
           this->month == dt1.month &&
           this->year == dt1.year);
}
