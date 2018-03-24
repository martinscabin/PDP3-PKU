#include <iostream>
using namespace std;

// Add your code here
int &
// End
getElement(int * a, int i)
{
    return a[i];
}

int main()
{
    int a[] = {1, 2, 3};
    getElement(a, 1) = 10;
    cout << a[1] << endl;
    return 0;
}
