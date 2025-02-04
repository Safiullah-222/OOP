#include <iostream>
#include <string>
using namespace std;

struct Person {
    int id;
    string name;
};

void sortPersons(Person* people, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (people[i].id > people[j].id || 
               (people[i].id == people[j].id && people[i].name[0] > people[j].name[0])) {
                swap(people[i], people[j]);
            }
        }
    }
}