#include <iostream>
using namespace std;

class A
{
    public:
        int x;
        int getX()
        {
            return x;
        }
};

void swap(
// Add your codes here
A & a, A & b
// End
        )
{
    int tmp = a.x;
    a.x = b.x;
    b.x = tmp;
}

int main()
{
    A a, b;
    a.x = 3;
    b.x = 5;
    swap(a, b);
    cout << a.getX() << "," << b.getX() << endl;
    return 0;
}
