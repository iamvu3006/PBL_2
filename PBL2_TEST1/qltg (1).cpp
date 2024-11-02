#include <iostream>
#include "event.h"
#include <string>
#include "qltg.h"

using namespace std;

void qltg::print()
{
    if (events.empty()) {
        cout << "Khong co su kien de hien thi.\n";
        return;
    }

    for (auto& ev : events)
    {
        cout << "Tieu de: " << ev.gettieude() << endl;
        cout << "Mo ta: " << ev.gettieude() << endl;
        cout << "Thoi gian bat dau: " << ev.getstt() << endl;
        cout << "Thoi gian ket thuc: " << ev.getet() << endl;
        cout << "-----------------------------" << endl;
    }
}


void qltg::add()
{
    string tmtieude, tmmota;
    thoigian tmstartime, tmendtime;

    cout << "Hay them mot su kien moi" << endl;
    cout << "Nhap tieu de: ";
    getline(cin, tmtieude);
    cout << "Nhap mo ta: ";
    cin.ignore();
    getline(cin, tmmota);
    cout << "Nhap thoi gian bat dau (giay phut gio ngay thang nam): ";
    
    cin >> tmstartime;
    cout << "Nhap thoi gian ket thuc (giay phut gio ngay thang nam): ";
    cin >> tmendtime;
    
    Event tmp(tmtieude, tmmota, tmstartime, tmendtime);
    events.push_back(tmp);
}


void qltg::erase()
{
    if (events.empty()) {
        cout << "Khong co su kien de xoa.\n";
        return;
    }

    string tieude;
    thoigian startTime;

    cout << "Nhap tieu de cua su kien can xoa: ";
    cin.ignore();
    getline(cin, tieude);
    cout << "Nhap thoi gian bat dau cua su kien can xoa: ";
    cin >> startTime;
    cin.ignore();

    auto it = find_if(events.begin(), events.end(),
                      [&tieude, &startTime]( Event& ev) {
                          return ev.gettieude() == tieude && ev.getstt() == startTime;
                      });

    if (it != events.end()) {
        events.erase(it);
        cout << "Da xoa su kien.\n";
    } else {
        cout << "Khong tim thay su kien voi tieu de va thoi gian bat dau nhu da nhap.\n";
    }
}


void qltg::fix()
{
    if (events.empty()) {
        cout << "Khong co su kien de chinh sua.\n";
        return;
    }

    string tieude;
    thoigian startTime;

    cout << "Nhap tieu de cua su kien can chinh sua: ";
    cin.ignore(); 
    getline(cin, tieude);
    cout << "Nhap thoi gian bat dau cua su kien can chinh sua: ";
    cin >> startTime;
    cin.ignore();

    auto it = find_if(events.begin(), events.end(),
                      [&tieude, &startTime](Event& ev) {
                          return ev.gettieude() == tieude && ev.getstt() == startTime;
                      });

    if (it != events.end()) {
        cout << "Nhap tieu de moi: ";
        it->settieude();
        cout << "Nhap mo ta moi: ";
        it->setmota();
        cout << "Nhap thoi gian bat dau moi: ";
        it->setstt();
        cout << "Nhap thoi gian ket thuc moi: ";
        it->setet();
        cin.ignore();
        cout << "Da chinh sua su kien.\n";
    } else {
        cout << "Khong tim thay su kien voi tieu de va thoi gian bat dau nhu da nhap.\n";
    }
}
