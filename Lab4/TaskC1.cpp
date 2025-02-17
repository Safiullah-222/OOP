#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    double** data;

public:
    Matrix() : rows(0), cols(0), data(nullptr) {}

    Matrix(int r, int c) : rows(r), cols(c) {
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols]{0};
        }
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(other.data) {
        other.data = nullptr;
        other.rows = other.cols = 0;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
    }

    int getRows() { return rows; }
    int getCols() { return cols; }

    double& at(int r, int c) { return data[r][c]; }

    void fill(double value) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = value;
    }

    Matrix transpose() {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                transposed.data[j][i] = data[i][j];
        return transposed;
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix mat1(3, 3);
    mat1.fill(5.0);
    cout << "Original Matrix:\n";
    mat1.display();

    Matrix transposed = mat1.transpose();
    cout << "\nTransposed Matrix:\n";
    transposed.display();

    return 0;
}
