#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int random;
    int max = 0, min = 10;
    int *maxAdd;
    int *minAdd;
    int *ptr = new int[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        random = rand() % 10;
        ptr[i] = random;
        if (max < ptr[i]) {
            max = ptr[i];
            maxAdd = &ptr[i];
        }
        if (min > *(ptr + i)) {
            min = ptr[i];
            minAdd = &ptr[i];
        }
        cout << "Memory Address is " << &ptr[i] << endl;
        cout << "Value is " << ptr[i] << endl;
    }
    cout << "Max Data is " << max << "(" << maxAdd << ")" << endl;
    cout << "Min Data is " << min << "(" << minAdd << ")" << endl;

    delete[] ptr;
    return 0;
}