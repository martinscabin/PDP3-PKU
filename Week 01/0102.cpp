#include <iostream>
using namespace std;

void swap(
// Add your code here
int * &a, int * &b
// End
        )
{
    int * tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 3, b = 5;
    int * pa = &a;
    int * pb = &b;
    swap(pa, pb);
    cout << *pa << "," << *pb << endl;
    return 0;
}
