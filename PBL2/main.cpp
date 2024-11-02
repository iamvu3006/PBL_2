#include"event.h"

int main()
{
    vector<Event> time;
    int choice;
    qltg manager;
    do {
        cout << "----------MENU----------\n";
        cout << "1. Them su kien moi\n";
        cout << "2. Chinh sua su kien\n";
        cout << "3. Xoa su kien\n";
        cout << "4. Trinh bay tat ca su kien\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin.ignore();
        cin >> choice;

        switch (choice) {
        case 1:
            manager.add(time);
            break;

        case 2:
            manager.fix(time);
            break;

        case 3:
            manager.erase(time);
            break;

        case 4:
            manager.print(time);
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    
    return 0;
}