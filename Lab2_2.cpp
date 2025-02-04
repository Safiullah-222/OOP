#include <iostream>
#include <string>
using namespace std;

void* array(void* arr, int size) {
    int* intarr = (int*)arr;
    for (int i = 0; i < size; i++) {
        intaar[i] += 5;
    }
    return arr;
}