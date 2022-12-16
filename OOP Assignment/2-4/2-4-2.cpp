#include <iostream>
#include <cstring>
using namespace std;
static int idx = 1;

class Student{
private:
    char name[20];
    int Score;
public:
    Student() = default;
    Student(string name, int score) {
        int i = 0;
        while(name[i] != '\0') {
            this->name[i] = name[i];
            i++;
        }
        Score = score;
    }
    char * GetName();
    int GetScore();
    void GetInfo();
    ~Student() = default;
};

char * Student::GetName() {
    return name;
}

int Student::GetScore() {
    return Score;
}

void Student::GetInfo() {
    cout << name << " " << Score << endl;
}

int main() {
    Student * pStudent = new Student[idx];
    int command;
    string name;
    int score;

    do {
        cout << "Please Enter Command(1.insert, 2.sort by name, 3. sort by score, 4.quit) : ";
        cin >> command;
        switch (command) {
            case 1:
                cout << "Name : ";
                cin >> name;
                cout << "Score : ";
                cin >> score;
                pStudent[idx - 1]=Student(name, score);
                idx++;
                break;
            case 2:
                for (int i = 0; i < idx-1; i++) {
                    for (int j = i+1; j < idx; j++) {
                        if (strcmp(pStudent[i].GetName(), pStudent[j].GetName()) > 0) {
                            string temp_name = pStudent[i].GetName();
                            int temp_score = pStudent[i].GetScore();
                            pStudent[i]=Student(pStudent[j].GetName(), pStudent[j].GetScore());
                            pStudent[j]=Student(temp_name, temp_score);
                        }
                    }
                }
                for (int i = 1; i < idx; i++) {
                    pStudent[i].GetInfo();
                }
                break;
            case 3:
                for (int i = 0; i < idx-1; i++) {
                    for (int j = i+1; j < idx; j++) {
                        if (pStudent[i].GetScore() > pStudent[j].GetScore()) {
                            string temp_name = pStudent[i].GetName();
                            int temp_score = pStudent[i].GetScore();
                            pStudent[i]=Student(pStudent[j].GetName(), pStudent[j].GetScore());
                            pStudent[j]=Student(temp_name, temp_score);
                        }
                    }
                }
                for (int i = 1; i < idx; i++) {
                    pStudent[i].GetInfo();
                }
                break;
            default:
                break;
        }
    } while(command != 4);

    delete[] pStudent;
    return 0;
}