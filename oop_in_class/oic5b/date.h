#include <iostream>

using namespace std;

class date
{
private:
    int ngay, thang, nam;

public:
    void check(const date & dt);
    date(int, int, int);
    ~date();
    friend  ostream &operator<<(ostream &, date &);
    friend istream &operator>>(istream &, date &);
    date operator++();
    const date operator++(int);
    const date operator+=(int );
    date operator--();
    const date operator--(int);
};