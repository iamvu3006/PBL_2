#include <iostream>
#include "event.h"
#include <string>
#include "qltg.h"

using namespace std;

void qltg::print(const vector<Event> &ev)
{
    for (int i = 0; i < ev.size() - 1; i++)
    {
        cout << "Tieu de: " << ev[i].tieude << endl;
        cout << "Mo ta: " << ev[i].mota << endl;
        cout << "Thoi gian bat dau: " << ev[i].startTime << endl;
        cout << "Thoi gian ket thuc: " << ev[i].endTime << endl;
        cout << "-----------------------------" << endl;
    }
}

void qltg::add(vector<Event> &ev)
{
    string tmtieude, tmmota;
    thoigian tmstartime, tmendtime;
    cout << "Hay them mot su kien moi" << endl;
    cout << "Nhap tieu de: ";
    getline(cin, tmtieude);
    cout << endl;
    cout << "Nhap mo ta: ";
    getline(cin, tmmota);
    cout << endl;
    cout << "Nhap thoi gian bat dau: ";
    cin >> tmstartime;
    cout << "Nhap thoi gian ket thuc: ";
    cin >> tmendtime;
    Event tmp;
    tmp.tieude = tmtieude;
    tmp.mota = tmmota;
    tmp.startTime = tmstartime;
    tmp.endTime = tmendtime;
    ev.push_back(tmp);
}

void qltg::erase(vector<Event> &ev)
{
    Event tmp;
    int cnt;
    vector<Event> temp;
    cout << "Nhap tieu de cua su kien can xoa: ";
    getline(cin, tmp.tieude);
    cout << endl;
    for (int i = 0; i < ev.size() - 1; i++)
    {
        if (ev[i].tieude == tmp.tieude)
        {
            cnt++;
            temp.push_back(ev[i]);
        }
    }
    if (cnt < 0)
    {
        cout << "Khong tim thay su kien" << endl;
    }
     else if (cnt == 1)
    {
        auto it = find_if(ev.begin(), ev.end(), [tieude = tmp.tieude](const Event& event)
                          { return event.tieude == tieude; });
        if (it != ev.end())
        {
            ev.erase(it);
            cout << "Da xoa su kien." << endl;
        }
    }
     else if (cnt > 1)
    {
        cout << "Nhap thoi gian bat dau cua su kien can xoa: ";
        cin >> tmp.startTime;
        
        auto it = find_if(ev.begin(), ev.end(), [ sttTime = tmp.startTime](Event& event)
                          { return event.startTime == sttTime; });
        if (it != ev.end())
        {
            ev.erase(it);
            cout << "Da xoa su kien." << endl;
        }
        else
        {
            cout << "Khong tim thay su kien voi thoi gian bat dau nhu da nhap." << endl;
        }
    }
}

void qltg::fix(vector<Event> &v)
{
    Event tmp;
   cout<<"Nhap tieu de va thoi gian bat dau cua su kien can chinh sua: ";
   cin>>tmp.tieude>>tmp.startTime;
   for(int i = 0; i<v.size()-1;i++)
   {
        if(v[i].tieude == tmp.tieude && v[i].startTime==tmp.startTime)
        {
            cout<<"Nhap tieu de moi: ";
            cin>>v[i].tieude;
            cout<<"Nhap mo ta moi: ";
            cin>>v[i].mota;
            cout<<"Nhap thoi gian bat dau moi: ";
            cin>>v[i].startTime;
            cout<<"Nhap thoi gian ket thuc moi: ";
            cin>>v[i].endTime;
        }
   } 
}
