#include <iostream>

template<typename T>
void printVector(const vector<T>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

template<typename T>
void printMatrix(const vector<vector<T>>& mat) {
    cout << "[" << endl;
    for (const auto& row : mat) {
        cout << "  ";
        printVector(row);
    }
    cout << "]" << endl;
}
