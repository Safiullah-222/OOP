#include <iostream>
#include <string>
using namespace std;

int* resizeArray(int* arr, int& capacity, int count) {
    if (count > capacity) {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < count; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        return newArr;
    }
    return arr;
}