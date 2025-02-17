#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* data;
    size_t length;

public:
    DynamicArray() : data(nullptr), length(0) {}

    DynamicArray(size_t n) : data(new int[n]()), length(n) {}

    DynamicArray(const DynamicArray& other) : data(new int[other.length]), length(other.length) {
        std::copy(other.data, other.data + length, data);
    }

    DynamicArray(DynamicArray&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new int[length];
            std::copy(other.data, other.data + length, data);
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] data;
    }

    size_t size() const {
        return length;
    }

    int& at(size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const int& at(size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    void resize(size_t newSize) {
        int* newData = new int[newSize]();
        size_t minSize = (newSize < length) ? newSize : length;
        std::copy(data, data + minSize, newData);
        delete[] data;
        data = newData;
        length = newSize;
    }
};

int main() {
    DynamicArray arr(5);
    for (size_t i = 0; i < arr.size(); i++) {
        arr.at(i) = static_cast<int>(i + 1);
    }

    DynamicArray copyArr = arr;
    DynamicArray moveArr = std::move(arr);
    
    copyArr.resize(7);
    
    for (size_t i = 0; i < copyArr.size(); i++) {
        std::cout << copyArr.at(i) << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
