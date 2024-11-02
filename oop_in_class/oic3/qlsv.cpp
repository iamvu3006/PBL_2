#include "qlsv.h"
using namespace std;

qlsv::qlsv() : p(nullptr),count(0)
{

}

qlsv::qlsv(sv x) {
    p = new sv[1]; 
    p[0] = x; 
    count = 1;
}

qlsv::~qlsv()
{
    delete[] p;
}

void qlsv::add(sv x)
{
    count++;
    sv *newp = new sv(count);
    for (int i = 0; i < count - 1; i++)
    {
        newp[i] = p[i];
    }
    newp[count] = x;
    delete[] p;
    p = newp;
}

void qlsv::insert(sv x, int n)
{
    for (int i = 0; i < count; i++)
    {
        if (i == n)
        {
            count++;
            for (int i = count; i > n; i++)
            {
                p[i] = p[i - 1];
            }
            p[n] = x;
        }
    }
}

void qlsv::removeat(int n) {
    if (n < 0 || n >= count) return; 

    sv* newp = new sv[count - 1]; 
    for (int i = 0; i < n; i++) {
        newp[i] = p[i]; 
    }
    for (int i = n + 1; i < count; i++) {
        newp[i - 1] = p[i]; 
    }
    delete[] p; 
    p = newp; 
    count--; 
}

void qlsv::remove(sv x)
{
    int tmp = count - 1;
    sv *newp1 = new sv[tmp];
    for (int i = 0; i < tmp; i++)
    {
        newp1[i] = p[i];
    }
    delete [] p;
    p = newp1;
    count = tmp;
}

int qlsv::indexof(sv x)
{
    return x.getid();
}


void qlsv::update(float x, sv s)
{
    s.setgpa(x);
}

void qlsv::incre(sv x)
{
    sv tmp;
    for (int i = 0; i < count; i++)
    {
        if (p[i].gpa > p[i + 1].gpa)
        {
            tmp = p[i + 1];
            p[i + 1] = p[i];
            p[i] = tmp;
        }
    }
}

void qlsv::decre(sv x)
{
    sv tmp;
    for (int i = 0; i < count; i++)
    {
        if (p[i].gpa < p[i + 1].gpa)
        {
            tmp = p[i + 1];
            p[i + 1] = p[i];
            p[i] = tmp;
        }
    }
}

void show(sv x)
{
    cout<<x.id<<" "<<x.gpa<<endl;
}
void sort(int *a())