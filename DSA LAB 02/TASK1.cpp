#include <iostream>
using namespace std;

class Matrix {
    int** data;
    int rows, cols;

public:
    Matrix(int r, int c, int val = 0) {
        rows = r; cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) data[i][j] = val;
        }
    }

    void resize(int newRows, int newCols, int val = 0) {
        int** newData = new int*[newRows];
        for (int i = 0; i < newRows; i++) {
            newData[i] = new int[newCols];
            for (int j = 0; j < newCols; j++) {
                if (i < rows && j < cols) newData[i][j] = data[i][j];
                else newData[i][j] = val;
            }
        }
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
        data = newData;
        rows = newRows; cols = newCols;
    }

    void transpose() {
        int** newData = new int*[cols];
        for (int i = 0; i < cols; i++) {
            newData[i] = new int[rows];
            for (int j = 0; j < rows; j++) newData[i][j] = data[j][i];
        }
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
        data = newData;
        int temp = rows;
        rows = cols;
        cols = temp;
    }

    void addTwoOddIndex() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i + j) % 2 == 1) data[i][j] += 2;
            }
        }
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) cout << data[i][j] << " ";
            cout << endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
    }
};

int main() {
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    Matrix m(r, c, 1);

    cout << "Initial Matrix:" << endl;
    m.print();

    m.resize(r + 1, c + 2, 5);
    cout << "After Resize:" << endl;
    m.print();

    m.transpose();
    cout << "After Transpose:" << endl;
    m.print();

    m.addTwoOddIndex();
    cout << "After Adding 2 to Odd Indices:" << endl;
    m.print();

    return 0;
}

