#include <iostream>
#include <cstring>

using namespace std;

class animal {
private:
    char name[10];
    int year = 0;
    char species[100];

public:
    friend class zoo;
    animal(char* name, int year, char* species) {
        strcpy(this->name, name);
        this->year = year;
        strcpy(this->species, species);
    }
};

class zoo {
private:
    class animal* animal_list[100]{ NULL };
    int size = 0;
public:
    void set_info(char* name, int year, char* species)
    {
        animal_list[size] = new animal(name, year, species);
        size += 1;

    }

    void print_all() {
        for (int i = 0; i < size; i++) {
            cout << "----------" << i << "----------" << endl;
            cout << "Name : " << animal_list[i]->name << endl;
            cout << "Year : " << animal_list[i]->year << endl;
            cout << "Species : " << animal_list[i]->species << endl;
            cout << "---------------------" << endl;
        }
    }

    void print_species(char* s) {
        int number = 0;
        for (int i = 0; i < size; i++) {
            if (!strcmp(animal_list[i]->species, s)) {
                number++;
                cout << "----------" << i << "----------" << endl;
                cout << "Name : " << animal_list[i]->name << endl;
                cout << "Year : " << animal_list[i]->year << endl;
                cout << "Species : " << animal_list[i]->species << endl;
                cout << "---------------------" << endl;
            }
        }
        cout << "Number of Species is " << number << endl;
        cout << "---------------------" << endl;
    }

};

int main(void) {
    char cmd_name[10];
    int cmd_year = 0;
    char cmd_species[100];
    zoo z;
    string command;
    while (true) {
        cout << "Please Enter Command(new_animal, print_all, print_species, exit) : ";
        cin >> command;
        if (command == "exit") {
            break;
        }
        else if (command == "new_animal") {
            cin >> cmd_name >> cmd_year >> cmd_species;
            z.set_info(cmd_name, cmd_year, cmd_species);
        }
        else if (command == "print_all") {
            cout << "------print_all------" << endl;
            z.print_all();
            cout << "---------------------" << endl;
        }
        else if (command == "print_species") {
            cin >> cmd_species;
            cout << "------print_species------" << endl;
            z.print_species(cmd_species);
            cout << "---------------------" << endl;
        }
    }
    return 0;
}