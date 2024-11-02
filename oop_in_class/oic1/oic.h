#include <iostream>

using namespace std;

class point
{
    public:
        static int n;
        const static int t = 5;
    private:
        point(int = 1, int = 1);
        point(const point&);
        ~point();
        void show();
        static void count();
        friend void change(point &p);
};