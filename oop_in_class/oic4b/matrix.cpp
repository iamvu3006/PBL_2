#include <matrix.h>

matrix::matrix(int x, int y)
{
    this->col = x;
    this->row=y;
    if(this->col==0 && this->row ==0 )
    {
        this->p=NULL;
    }
    else
    {
        this->p = new int *[this->row];
        for(int i=0;i<this->row;i++)
        {
            *(this->p+i)=new int [this->col];
        }
    }
}

ostream &operator<<(ostream &os, const matrix &ma)
{
    for(int i=0;i<ma.row;i++)
    {
        for(int j=0;j<ma.col;j++)
        {
            os<<*(*(ma.p+i)+j);
        }
        cout<<endl;
    }
    return os;
}

istream &operator>>(istream &is, matrix &ma)
{
    for(int i=0;i<ma.row;i++)
    {
        for(int j=0;j<ma.col;j++)
        {
            is>>*(*(ma.p+i)+j);
        }
    }
    return is;
}

int& matrix::operator()(int &c,int & r)
{
    int temp = 0;
    if(r>0 && r<this->row && c>0 && c<this->col)
    {
        return *(*(this->p+r)+c);
    }
    else
    return temp;
}