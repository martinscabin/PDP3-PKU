#include <iostream>
#include <cstring>
#include <string>
using namespace std;

template <class T>
class myclass
{
    // Starts here
    private:
    T * p;
    int size;

    public:
    myclass(T * start, int size)
    {
        p = new T[size];
        this->size = size;
        for(int i = 0; i < size; i++)
        {
            p[i] = start[i];
        }
    }
    // Ends here

    ~myclass()
    {
        delete [] p;
    }

    void Show()
    {
        for(int i = 0; i < size; i++)
        {
            cout << p[i] << ",";
        }
        cout << endl;
    }
};

int a[100];

int main()
{
    char line[100];
    while(cin >> line)
    {
        myclass<char> obj(line, strlen(line));
        obj.Show();
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        myclass<int> obj2(a, n);
        obj2.Show();
    }
    return 0;
}
