#include <iostream>
#include <cmath>

using namespace std;

class Polygon {
private:
    int Area;
    int Perimeter;
public:
    void print_Perimeter() {
        cout << "Perimeter is " << Perimeter << endl;
    };
    void print_Area() {
        cout << "Area is " << Area << endl;
    };
    Polygon(int A, int B) {
        Area = A * B;
        Perimeter = 2 * (A + B);
    }
    Polygon(int A, int B, int C) {
        Perimeter = A + B + C;
        Area = sqrt((Perimeter/2)*((Perimeter/2)-A)*((Perimeter/2)-B)*((Perimeter/2)-C));
    }
};


class Triangle : public Polygon {
private:
    int A;
    int B;
    int C;
public:
    Triangle(int n1, int n2, int n3) : Polygon(n1, n2, n3) { }
};

class Square : public Polygon {
private:
    int A;
    int B;
public:
    Square(int num1, int num2) : Polygon(num1, num2){ }
};


int main(){
    class Square A(5,4);
    class Triangle B(13, 14, 15);

    cout << "--------Square--------" << endl;
    A.print_Area();
    A.print_Perimeter();
    cout << "----------------------" << endl;
    cout << "-------Triangle-------" << endl;
    B.print_Area();
    B.print_Perimeter();
    cout << "----------------------" << endl;
}