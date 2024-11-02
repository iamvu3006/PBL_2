#include"event.h"

using namespace std;

bool Event::operator==(const Event &ev)
{
    return (this->startTime == ev.startTime &&
            this->endTime == ev.endTime);
}

const string Event::gettieude()
{
    return this->tieude;
}

const string Event::getmota()
{
    return this->mota;
}

const thoigian Event::getstt()
{
    return this->startTime;
}

const thoigian Event::getet()
{
    return this->endTime;
}

void Event::settieude()
{
    string tmp;
    cin.ignore();
    getline(cin,tmp);
    this->tieude = tmp;
}

void Event::setmota()
{
    string tmp;
    cin.ignore();
    getline(cin,tmp);
    this->mota = tmp;
}

void Event::setstt()
{
    thoigian tmp;
    cin>>tmp;
    this->startTime = tmp;    
}

void Event::setet()
{
    thoigian tmp;
    cin>>tmp;
    this->endTime == tmp;
}



