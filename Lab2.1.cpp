#include <iostream>
#include <string>
using namespace std;


int sumarr(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}