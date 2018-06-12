#include <iostream>
#include <string>

using namespace std;

// Starts here

template <class T, int SIZE>
class A {
public:
    T * arr;
    A(T * a) {
        arr = new T[SIZE];
        for(int i = 0; i < SIZE; i++) {
            *(arr + i) = a[i];
        }
    }
    T operator [] (int i) {
        return arr[i];
    }
    T sum() {
        T result = T();
        for(int i = 0; i < SIZE; i++) {
            result += arr[i];
        }
        return result;
    }
    ~A() {
        delete [] arr;
    }
};

// Ends here

int main() {

    int t;
    cin >> t;
    while (t--) {
        int b1[10];
        for (int i = 0; i < 10; ++i)

            cin >> b1[i];
        A<int, 10> a1 = b1;
        cout << a1[2] << endl;


        double b2[5];
        for (int i = 0; i < 5; ++i)
            cin >> b2[i];

        A<double, 5> a2 = b2;
        cout << a2.sum() << endl;


        string b3[4];
        for (int i = 0; i < 4; ++i)
            cin >> b3[i];

        A<string, 4> a3 = b3;
        cout << a3.sum() << endl;
    }
    return 0;
}