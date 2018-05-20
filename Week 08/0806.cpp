#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class T1, class T2>
void Copy(T1 s, T1 e, T2 x)
{
    for(; s != e; ++s, ++x)
    {
        *x = *s;
    }
}

template <class T>
class myostream_iterator
{
    // Starts here
    private:
        ostream & os;
        string delim;
        T val;
    public:
        myostream_iterator(ostream & o, const string & s): os(o), delim(s) {}

        myostream_iterator & operator ++ ()
        {
            os << val << delim;
            return * this;
        }

        T & operator * ()
        {
            return val;
        }
    // Ends here
};

int main() 
{
    const int SIZE = 5;
    int a[SIZE] = {5, 21, 14, 2, 3};
    double b[SIZE] = {1.4, 5.56, 3.2, 98.3, 3.3};
    list<int> lst(a, a + SIZE);
    myostream_iterator<int> output(cout, ",");
    Copy(lst.begin(), lst.end(), output);
    cout << endl;
    myostream_iterator<double> output2(cout, "--");
    Copy(b, b + SIZE, output2);
    return 0;
}
