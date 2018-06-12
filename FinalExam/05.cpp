#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

// Starts here

template <class T>
class CMyClass {
public:
    T * arr;
    CMyClass(T * data, int length) {
        arr = new T[length];
        for(int i = 0; i < length; i++) {
            arr[i] = data[i];
        }
    }
    T operator [] (int i) {
        return arr[i];
    }
    ~CMyClass() {
        if(arr) {
            delete [] arr;
        }
    }
};

// Ends here

int a[40];

int main(int argc, char **argv) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
            scanf("%d", a + i);
        char s[100];
        scanf("%s", s);
        CMyClass<int> b(a, m);
        CMyClass<char> c(s, strlen(s));
        printf("%d %c\n", b[5], c[7]);
    }
    return 0;
}