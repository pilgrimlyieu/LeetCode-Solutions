#include <iostream>

template<typename T>
void printVector(const vector<T>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}
