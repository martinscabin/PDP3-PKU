#include <iostream>
using namespace std;

int main()
{
    int * a[] = {
        // Add your code here
        NULL, NULL, new int[1], new int[6]
        // End
    };
    *a[2] = 123;
    a[3][5] = 456;
    if(!a[0])
    {
        cout << *a[2] << "," << a[3][5];
    }
    return 0;
}