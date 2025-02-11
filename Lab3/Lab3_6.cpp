#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int mat[10][10]; 

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
    }

    int getRows() { return rows; }
    int getCols() { return cols; }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            mat[i][j] = value;
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(Matrix &m) {
        if (rows != m.rows || cols != m.cols) {
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }

    Matrix multiply(Matrix &m) {
        if (cols != m.rows) {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int r1, c1, r2, c2;
    
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    Matrix mat1(r1, c1);

    cout << "Enter values for first matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            int val;
            cin >> val;
            mat1.setElement(i, j, val);
        }
    }

    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;
    Matrix mat2(r2, c2);

    cout << "Enter values for second matrix:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            int val;
            cin >> val;
            mat2.setElement(i, j, val);
        }
    }

    cout << "\nFirst Matrix:\n";
    mat1.display();
    
    cout << "\nSecond Matrix:\n";
    mat2.display();

    cout << "\nAddition Result:\n";
    Matrix sum = mat1.add(mat2);
    sum.display();

    cout << "\nMultiplication Result:\n";
    Matrix product = mat1.multiply(mat2);
    product.display();

    return 0;
}
