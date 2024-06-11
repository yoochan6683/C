#include <iostream>

using namespace std;

template<typename T>
class Matrix {
private:
    T** array;
    int row;
    int col;

public:
    Matrix(int r, int c) : row(r), col(c) {
        array = new T*[row];
        for (int i = 0; i < row; ++i) {
            array[i] = new T[col];
            for (int j = 0; j < col; ++j) {
                array[i][j] = 0;
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < row; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }

    T* operator[](int index) {
        return array[index];
    }

    void operator=(const Matrix& newM) {
        for(int i=0; i<newM.row; i++) {
            for(int j=0; j<newM.col; j++) {
                array[i][j] = newM.array[i][j];
            }
        }
    }

    Matrix operator+(const Matrix& newM) {
        Matrix result(row, col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                result[i][j] = array[i][j] + newM.array[i][j];
            }
        }
        return result;
    }


    Matrix operator-(const Matrix& newM) {
        Matrix result(row, col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                result[i][j] = newM.array[i][j] - array[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& newM) {
        Matrix result(row, newM.col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < newM.col; ++j) {
                for (int k = 0; k < col; ++k) {
                    result[i][j] += array[i][k] * newM.array[k][j];
                }
            }
        }
        return result;
    }

    Matrix operator*(int scalar) {
        Matrix result(row, col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                result[i][j] = array[i][j] * scalar;
            }
        }
        return result;
    }

    friend Matrix operator*(int scalar, const Matrix& newM) {
        Matrix result(newM.row, newM.col);
        for (int i = 0; i < newM.row; ++i) {
            for (int j = 0; j < newM.col; ++j) {
                result[i][j] = newM.array[i][j] * scalar;
            }
        }
        return result;
    }

    friend ostream& operator<<(ostream& os, const Matrix& newM) {
        for (int i = 0; i < newM.row; ++i) {
            for (int j = 0; j < newM.col; ++j) {
                os << newM.array[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
};

int main() {
    Matrix<int> m1(3, 3);
    m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
    m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;
    m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;

    Matrix<int> m2(3, 3);
    m2[0][0] = 9; m2[0][1] = 8; m2[0][2] = 7;
    m2[1][0] = 6; m2[1][1] = 5; m2[1][2] = 4;
    m2[2][0] = 3; m2[2][1] = 2; m2[2][2] = 1;

    Matrix<int> m(3, 3);
    
    m = m1 + m2;
    cout << m;

    m = m1 - m2;
    cout << m;

    m = m1 * m2;
    cout << m;

    m = 10 * m1;
    cout << m;

    return 0;
}