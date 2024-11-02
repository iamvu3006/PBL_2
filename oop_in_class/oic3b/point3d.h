#include"point.h"
class point3d : public point
{
    private:
    int zval;
    public:
    point3d(int =0,int =0,int=0);
    void show3d();
    void show();
};