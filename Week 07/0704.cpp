#include <iostream>
using namespace std;

class MyCin
{
    // Starts here
    private:
        bool flag;
        int junk;
    public:
        MyCin()
        {
            flag = true;
        }
        MyCin & operator >> (int & n)
        {
            cin >> n;
            if(n == -1)
            {
                flag = false;
            }
            return * this;
        }
        operator bool()
        {
            return flag;
        }
    // Ends here
};

int main()
{
    MyCin m;
    int n1, n2;
    while(m >> n1 >> n2)
    {
        cout << n1 << " " << n2 << endl;
    }
    return 0;
}

