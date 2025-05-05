//
// Created by Martini on 5. 05. 2025.
//
#include <iostream>
#include "LinearQueue.h"
#include "Point.h"

using namespace std;

int main() {
    cout << "\n=== TEST INT ===" << endl;
    try {
        LinearQueue<int> q;

        cout << "Polnjenje z naključnimi vrednostmi (3):" << endl;
        fillDefault(q, 3);
        cout << "Vrsta: " << q.toString()<< " | Velikost: " << q.size() << " | Prvi: " << q.element()<< " | Max: " << q.getMax() << endl;
        cout << "\nDodajanje 150:" << endl;

        q.add(150);
        cout << "Vrsta: " << q.toString()<< " | Novi max: " << q.getMax() << endl;
        cout << "\nPostopno praznjenje:" << endl;
        while(q.remove()) {
            cout << "Stanje: " << q.toString() << " | Velikost: " << q.size() << endl;
        }
        cout << "Poskus brisanja prazne: " << boolalpha << q.remove() << endl;

        cout << "\nPoskus dostopa do prazne vrste:" << endl;
        cout << "Prvi element: " << q.element() << endl; // Sproži izjemo

    } catch (const exception& e) {
        cout << "NAPAKA: " << e.what() << endl;
    }

    cout << "\n=== TEST FLOAT ===" << endl;
    try {
        LinearQueue<float> q;

        cout << "Polnjenje z default vrednostmi (2):" << endl;
        fillDefault(q, 2);
        q.add(3.14f);
        q.add(2.71f);
        cout << "Vrsta: " << q.toString()<< " | Max: " << q.getMax() << endl;

        cout << "\nPo enem brisanju:" << endl;
        q.remove();
        cout << "Vrsta: " << q.toString() << endl;

    } catch (const exception& e) {
        cout << "NAPAKA: " << e.what() << endl;
    }

    cout << "\n=== TEST POINT ===" << endl;
    try {
        LinearQueue<Point> q;

        cout << "Privzeto polnjenje (2):" << endl;
        fillDefault(q, 2);
        cout << "Vrsta: " << q.toString() << endl;

        cout << "\nDodajanje točk (3,4) in (5,12):" << endl;
        q.add(Point(3,4));
        q.add(Point(5,12));
        cout << "Vse točke: " << q.toString()
             << "\nNajbolj oddaljena: " << q.getMax() << endl;

        cout << "\nPostopno praznjenje:" << endl;
        while(q.size() > 0) {
            q.remove();
            cout << "Trenutno: " << q.toString() << endl;
        }

        cout << "\nPoskus iskanja max v prazni vrsti:" << endl;
        cout << q.getMax() << endl; // Sproži izjemo

    } catch (const exception& e) {
        cout << "NAPAKA: " << e.what() << endl;
    }

    return 0;
}