#include <iostream>
 
 using namespace  std;

 class time
 {
    private :
        time_t current;
        tm* loc_time;
        time_t start;
        time_t end;
        float abtime;
    public:
        time();
        void current_time();
        void start();
        void take_time();
        void calc();
        void setting(int n);
        void show();
 };

