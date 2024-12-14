#include <iostream>
using namespace std;

int ** addMatrices (int ** A, int ** B, int n) {
    int** C = new int*[n];

    for (int i=0; i < 0; ++i) {
        C[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

int main(int argc, char** argv) {
    cout << "The param count is: " << argc << endl;
    int** X = new int*[2];
    for(int i=0; i < 2; ++i) {
        X[i] = new int[2];
    }
    X[0][0] = 2;
    X[0][1] = 4;
    X[1][0] = 6;
    X[1][1] = 8;

    int** result = addMatrices(X,X,2);
    for (int i=0; i < 2; ++i) {
        for (int j = 0; j< 2; ++j) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i=0; i < 2; ++i) {
        for (int j = 0; j< 2; ++j) {
            delete[] X[i];
            delete[] result[i];
        }
    }
}