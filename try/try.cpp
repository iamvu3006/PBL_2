#include <bits/stdc++.h>
#include "try.h"
using namespace std;

sinhvien::sinhvien()
{
    this->id="";
    this->ten="";
    this->gpa=0;
}

int sinhvien::dem = 0;

void sinhvien::nhap()
{
    dem+=1;
    getline(cin,ten);
    cin.ignore();
    this->id = "SV" + string("3" - to_string(dem).length(),'0') + to_string(dem);
    cin>>gpa;
}

void sinhvien::xuat()
{
    cout<<this->id<<" "<<this->ten<<" "<<gpa<<endl;
}