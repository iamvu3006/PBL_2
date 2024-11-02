#ifndef EVENT_H
#define EVENT_H

#include "time.h"
#include <string>

class Event 
{
private:
    string tieude;
    string mota;
    thoigian startTime;
    thoigian endTime;
    bool operator==(const Event &);
public:
    const string gettieude();
    const string getmota();
    thoigian getstt();
    const thoigian getet();
    void settieude();
    void setmota();
    void setstt();
    void setet();
    Event() : tieude(""), mota(""), startTime(), endTime() {}
    Event(string &t, string &m, thoigian &s, thoigian &e) : tieude(t), mota(m), startTime(s), endTime(e) {}
};

#endif  // EVENT_H