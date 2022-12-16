#include <iostream>
#include <cstring>

using namespace std;

class ���� {
private:
	char U_Name[20]; // �б�
	int year; // �г�
	char U_StuID[20]; // �й�
public:
	����(char* name, int year, char* ID) {
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

	void printInfo() { // �б�, �й�, �г� ��
		cout << "�б� : " << U_Name << endl;
		cout << "�й� : " << U_StuID << endl;
		cout << "�г� : " << year << endl;
	}

	~����() {}
};

class ��ǻ���������� : public ���� {
private:
	char Object_Oriented_Programing;
	char Digital_Logic_Circuit;
public:
	��ǻ����������(char* name, int year, char* ID, char OOP_score, char DLC_score) : ����(name, year, ID) {
		Object_Oriented_Programing = OOP_score;
		Digital_Logic_Circuit = DLC_score;
	}

	void printScore() { // OOP ����, DLC ���� ��
		cout << "��ü�������α׷��� ���� : " << Object_Oriented_Programing << endl;
		cout << "�����г�ȸ�� ���� : " << Digital_Logic_Circuit << endl;
	}

	~��ǻ����������() {}
};

class �л����� : public ��ǻ���������� {
private:
	char Name[10];
	int age;
public:
	�л�����(char* name, int year, char* ID, char OOP_score, char DLC_score, char* myname, int age) : ��ǻ����������(name, year,
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

	~�л�����() {}
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
	�л�����** info = new �л����� * [100];

	string command;
	do {
		cin >> command;
		if (command == "INSERT") {
			if (people > 100) {
				cout << "FULL" << endl;
			}
			else {
				cout << "�б� : ";
				cin >> univ;
				cout << "�й� : ";
				cin >> u_id;
				cout << "�г� : ";
				cin >> grade;
				cout << "��ü�������α׷��� ���� : ";
				cin >> oop_score;
				cout << "�����г�ȸ�� ���� : ";
				cin >> dlc_score;
				cout << "�̸� : ";
				cin >> name;
				cout << "���� : ";
				cin >> age;
				info[people] = new �л�����(univ, grade, u_id, oop_score, dlc_score, name, age);
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