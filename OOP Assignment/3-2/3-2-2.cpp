#include <iostream>
#include <cstring>

using namespace std;

class 대학 {
private:
	char U_Name[20]; // 학교
	int year; // 학년
	char U_StuID[20]; // 학번
public:
	대학(char* name, int year, char* ID) {
		strcpy_s(U_Name, name);
		strcpy_s(U_StuID, ID);
		this->year = year;
	}

	int findID(char* find_id) {
		int result = 0;
		if (strcmp(U_StuID, find_id) == 0)
			result = 1;
		return result;
	}

	void printInfo() { // 학교, 학번, 학년 순
		cout << "학교 : " << U_Name << endl;
		cout << "학번 : " << U_StuID << endl;
		cout << "학년 : " << year << endl;
	}

	~대학() {}
};

class 컴퓨터정보공학 : public 대학 {
private:
	char Object_Oriented_Programing;
	char Digital_Logic_Circuit;
public:
	컴퓨터정보공학(char* name, int year, char* ID, char OOP_score, char DLC_score) : 대학(name, year, ID) {
		Object_Oriented_Programing = OOP_score;
		Digital_Logic_Circuit = DLC_score;
	}

	void printScore() { // OOP 학점, DLC 학점 순
		cout << "객체지향프로그래밍 학점 : " << Object_Oriented_Programing << endl;
		cout << "디지털논리회로 학점 : " << Digital_Logic_Circuit << endl;
	}

	~컴퓨터정보공학() {}
};

class 학생정보 : public 컴퓨터정보공학 {
private:
	char Name[10];
	int age;
public:
	학생정보(char* name, int year, char* ID, char OOP_score, char DLC_score, char* myname, int age) : 컴퓨터정보공학(name, year,
		ID, OOP_score, DLC_score) {
		strcpy_s(Name, myname);
		this->age = age;
	}

	int findName(char* myname) {
		int result = 0;
		if (strcmp(myname, Name) == 0) {
			result = 1;
		}
		return result;
	}

	~학생정보() {}
};

int main() {
	char univ[20];
	char u_id[20];
	int grade = 0;
	char oop_score;
	char dlc_score;
	char name[20];
	int age = 0;
	int people = 0;
	학생정보** info = new 학생정보 * [100];

	string command;
	do {
		cin >> command;
		if (command == "INSERT") {
			if (people > 100) {
				cout << "FULL" << endl;
			}
			else {
				cout << "학교 : ";
				cin >> univ;
				cout << "학번 : ";
				cin >> u_id;
				cout << "학년 : ";
				cin >> grade;
				cout << "객체지향프로그래밍 학점 : ";
				cin >> oop_score;
				cout << "디지털논리회로 학점 : ";
				cin >> dlc_score;
				cout << "이름 : ";
				cin >> name;
				cout << "나이 : ";
				cin >> age;
				info[people] = new 학생정보(univ, grade, u_id, oop_score, dlc_score, name, age);
				people++;
			}
		}
		else if (command == "FIND") {
			cin >> name >> u_id;
			for (int i = 0; i < people; i++) {
				int idx1 = info[i]->findName(name);
				int idx2 = info[i]->findID(u_id);
				if (idx1 == 1 and idx2 == 1) {
					cout << endl << endl;
					info[i]->printInfo();
					info[i]->printScore();
					break;
				}
			}
		}
	} while (command != "EXIT");
	return 0;
}