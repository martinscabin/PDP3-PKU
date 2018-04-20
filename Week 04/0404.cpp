#include <iostream>
#include <cstring>
using namespace std;

class Array2
{
    // Starts here
    private:
        int row, col;
        int arr[10][10];
    public:
        Array2()
        {
            row = 0;
            col = 0;
        }
        Array2(int r, int c): row(r), col(c)
        {
            
        }
        Array2(const Array2 & b)
        {
            row = b.row;
            col = b.col;
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    arr[i][j] = b.arr[i][j];
                }
            }
        }
        int operator () (int i, int j)
        {
            return arr[i][j];
        }
        int * operator [] (int i)
        {
            return arr[i];
        }
    // Ends here
};

int main()
{
    Array2 a(3, 4);
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            a[i][j] = i * 4 + j;
        }
    }
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
