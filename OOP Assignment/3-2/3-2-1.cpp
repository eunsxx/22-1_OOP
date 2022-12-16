#include <iostream>

using namespace std;

class TwoPoint {
public:
    TwoPoint(double i, double i1, double i2, double i3) {
        x1 = i;
        y1 = i1;
        x2 = i2;
        y2 = i3;
    }
    virtual void print() {
        cout << "Point 1 : " << x1 << "," << y1 << endl;
        cout << "Point 2 : " << x2 << "," << y2 << endl;
    }

protected:
    double x1, y1, x2, y2;
    double y, slope;
};

class Equation : public TwoPoint {
public:
    Equation(double i, double i1, double i2, double i3) : TwoPoint(i, i1, i2, i3) {
        x1 = i;
        y1 = i1;
        x2 = i2;
        y2 = i3;
        slope = (y2 - y1) / (x2 - x1);
        y = y1 - (slope * x1);
    }

    void print() {
        cout << "Equation : y = " << slope << "x ";
        if (y < 0) {
            cout << y << endl;
        }
        else if (y > 0) {
            cout << "+ " << y << endl;
        }
        else return;
    }
    ~Equation() {}

private:

};

int main() {
    class TwoPoint* A = new TwoPoint(2, 4, 7, 8);
    class TwoPoint* B = new Equation(2, 4, 7, 8);
    A->print();
    B->print();
    delete A;
    delete B;
    return 0;
}