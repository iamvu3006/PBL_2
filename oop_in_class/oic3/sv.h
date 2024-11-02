    #include <iostream>
    using namespace std;

    class sv
    {
    private:
        int id;
        float gpa;

    public:
        sv(int id = 0, float gpa = 0.0);
        int getid(sv);
        float getgpa(sv);
        void setgpa(float);
        ~sv();
        void show();
    };