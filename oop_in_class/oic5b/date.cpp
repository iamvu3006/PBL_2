#include "date.h"

void date::check(const date & dt)
{
    if (dt.ngay > 24 || dt.ngay < 0 || dt.thang > 12 || dt.thang< 0 || dt.nam < 0)
        {
            cout<<"doi tuong duoc khoi tao khong hop le";
            dt.~date();
        }
}

date::date(int day, int month, int year):ngay(day),thang(month),nam(year)
{
}

date::~date()
{
}

ostream &operator<<(ostream &os, date &dt)
{
    return os << dt.ngay<<dt.thang<<dt.nam;
}

istream &operator>>(istream &is, date &dt)
{
    return is >> dt.ngay>>dt.thang>>dt.nam;
}

date date::operator++()
{
    if (this->thang == 1 || this->thang == 3 || this->thang == 5 || this->thang == 7 || this->thang == 8 || this->thang == 10)
    {
        if (this->ngay == 31)
        {
            this->ngay = 1;
            this->thang++;
        }
    }
    else if (this->thang == 2 || this->thang == 4 || this->thang == 6 || this->thang == 9 || this->thang == 11)
    {
        if (this->ngay == 30)
        {
            this->ngay = 1;
            this->thang++;
        }
    }
    else if (this->thang == 12 && this->ngay == 31)
    {
        this->ngay = 1;
        this->thang = 1;
        this->nam++;
    }
    else
    {
        this->ngay++;
    }
    return (*this);
}

const date date::operator++(int)
{
    date bef = (*this);
    if (this->thang == 1 || this->thang == 3 || this->thang == 5 || this->thang == 7 || this->thang == 8 || this->thang == 10)
    {
        if (this->ngay == 31)
        {
            this->ngay = 1;
            this->thang++;
        }
    }
    else if (this->thang == 2 || this->thang == 4 || this->thang == 6 || this->thang == 9 || this->thang == 11)
    {
        if (this->ngay == 30)
        {
            this->ngay = 1;
            this->thang++;
        }
    }
    else if (this->thang == 12 && this->ngay == 31)
    {
        this->ngay = 1;
        this->thang = 1;
        this->nam++;
    }
    else
    {
        this->ngay++;
    }
    return (*this);
}

const date date::operator+=(int x)
{
    while(x--)
    {
        this->ngay++;
        if (this->thang == 1 || this->thang == 3 || this->thang == 5 || this->thang == 7 || this->thang == 8 || this->thang == 10)
            {
                if(this->ngay>31)
                {
                    this->ngay=1;
                    this->thang++;
                    if(this->thang==12)
                    {
                        this->thang=1;
                        this->nam++;
                    }
                }
            }
        else if (this->thang == 2 || this->thang == 4 || this->thang == 6 || this->thang == 9 || this->thang == 11)
        {
            if(this->ngay>30)
            {
                this->ngay=1;
                this->thang++;
            }
        }
    }
    return (*this);
}

date date::operator--()
{
    if (this->thang == 12 || this->thang == 3 || this->thang == 5 || this->thang == 7 || this->thang == 8 || this->thang == 10)
    {
        if (this->ngay == 1)
        {
            this->ngay = 31;
            this->thang--;
        }
    }
    else if (this->thang == 2 || this->thang == 4 || this->thang == 6 || this->thang == 9 || this->thang == 11)
    {
        if (this->ngay == 30)
        {
            this->ngay = 30;
            this->thang--;
        }
    }
    else if (this->thang == 1 && this->ngay == 1)
    {
        this->ngay = 31;
        this->thang = 12;
        this->nam--;
    }
    else
    {
        this->ngay--;
    }
    return (*this);
}

const date date::operator--(int)
{
    date bef = (*this);
    if (this->thang == 12 || this->thang == 3 || this->thang == 5 || this->thang == 7 || this->thang == 8 || this->thang == 10)
    {
        if (this->ngay == 1)
        {
            this->ngay = 31;
            this->thang--;
        }
    }
    else if (this->thang == 2 || this->thang == 4 || this->thang == 6 || this->thang == 9 || this->thang == 11)
    {
        if (this->ngay == 30)
        {
            this->ngay = 30;
            this->thang--;
        }
    }
    else if (this->thang == 1 && this->ngay == 1)
    {
        this->ngay = 31;
        this->thang = 12;
        this->nam--;
    }
    else
    {
        this->ngay--;
    }
    return bef;
}