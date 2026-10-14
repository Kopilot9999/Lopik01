#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle() : width(0), height(0) {}

    void input() {
        cout << "  Ширина: ";
        cin >> width;
        cout << "  Висота: ";
        cin >> height;
    }

    double area() const { return width * height; }

    void print() const {
        cout << "Ширина = " << width << ", висота = " << height
             << ", площа = " << area() << endl;
    }
};

int main() {
    const int N = 5;
    Rectangle rects[N];

    for (int i = 0; i < N; i++) {
        cout << "Прямокутник " << i + 1 << ":" << endl;
        rects[i].input();
    }

    int maxIdx = 0;
    for (int i = 1; i < N; i++) {
        if (rects[i].area() > rects[maxIdx].area())
            maxIdx = i;
    }

    cout << "\nНайбільша площа у прямокутника " << maxIdx + 1 << ":" << endl;
    rects[maxIdx].print();
    return 0;
}
