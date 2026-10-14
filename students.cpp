#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    double avg;

    Student() : name(""), avg(0) {}

    void input() {
        cout << "  Прізвище: ";
        cin >> name;
        cout << "  Середній бал: ";
        cin >> avg;
    }

    void print() const {
        cout << name << " - " << avg << endl;
    }
};

int main() {
    int n;
    cout << "Кількість студентів: ";
    cin >> n;
    if (n <= 0) {
        cout << "Некоректна кількість" << endl;
        return 1;
    }

    Student* st = new Student[n];
    for (int i = 0; i < n; i++) {
        cout << "Студент " << i + 1 << ":" << endl;
        st[i].input();
    }

    // сортування бульбашкою за спаданням середнього балу
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (st[j].avg < st[j + 1].avg) {
                Student tmp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = tmp;
            }
        }
    }

    cout << "\nВідсортовано за спаданням:" << endl;
    for (int i = 0; i < n; i++) st[i].print();

    delete[] st;
    return 0;
}
