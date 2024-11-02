#include "sv.h"
class qlsv
{
private:
    sv *p;
    int count;
public:
    qlsv();
    qlsv(sv);
    ~qlsv();
    void add(sv);
    void insert(sv, int);
    void show(sv);
    void removeat(int);
    void remove(sv);
    int indexof(sv);
    void update(int,sv);
    void decre(sv);
    void incre(sv);
    void sort(int *a(int,int));
};