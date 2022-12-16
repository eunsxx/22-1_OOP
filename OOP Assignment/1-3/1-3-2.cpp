#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string array1;
    string array2;
    ofstream fout;

    cout << "Array1 : ";
    cin >> array1;
    fout.open("array1.txt");
    fout << array1 << endl;
    fout.close();

    cout << "Array2 : ";
    cin >> array2;
    fout.open("array2.txt");
    fout << array2 << endl;
    fout.close();

    string s1, s2;
    ifstream fin;
    fin.open("array1.txt");
    fin >> s1;
    fin.close();

    fin.open("array2.txt");
    fin >> s2;
    fin.close();
    int size1 = s1.size();
    int size2 = s2.size();
    int minSize;
    if (size1 <= size2)
        minSize = size1;
    else
        minSize = size2;

//  'a' - 'A' == 32
    string str1, str2;
    for (int i = 0; i < size1; i++) {
        if (s1[i] < 'a')
            str1[i] = char(s1[i] + 32);
        else
            str1[i] = char(s1[i]);
    }
    for (int i = 0; i < size2; i++) {
        if (s2[i] < 'a')
            str2[i] = char(s2[i] + 32);
        else
            str2[i] = char(s2[i]);
    }

    for (int i = 0; i < minSize; i++) {
        if (str1[i] < str2[i]) {
            swap(s1[i], s2[i]);
        }
    }

    cout << "Exchanged Array 1 :" << s1 << endl;
    cout << "Exchanged Array 2 :" << s2 << endl;
    return 0;
}
