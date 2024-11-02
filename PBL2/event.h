#include "qltg.h"
class Event 
{

public:
    string tieude;
    string mota;
    thoigian startTime;
    thoigian endTime;
    bool operator==(const Event &);

    const string gettieude();
    const string getmota();
    const thoigian getstt();
    const thoigian getet();
    void settieude();
    void setmota();
    void setstt();
    void setet();
    Event() : tieude(""), mota(""), startTime(), endTime() {}
    Event(string &t, string &m, thoigian &s, thoigian &e) : tieude(t), mota(m), startTime(s), endTime(e) {}
};