#include"sv.h"

void show()
{
    cout<<this->id<<" "<<this->gpa<<endl;
}

int sv::getid(sv x)
{
    return x.id;
}

float sv::getgpa(sv x)
{
    return x.gpa;
}

void sv::setgpa(float x)
{
    this->gpa = x;
}

sv::~sv()
{

}