#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int MAX = 110;

class CHugeInt
{
    // Starts here
    private:
        char * p;

    public:
        CHugeInt()
        {
            p = NULL;
        }
        
        CHugeInt(const char * s)
        {
            if(s)
            {
                p = new char[strlen(s) + 1];
                strcpy(p, s);
            }
            else 
            {
                p = NULL;
            }
        }

        CHugeInt(int n)
        {
            // TODO: Convert integer to char *
        }

        CHugeInt & operator + (const CHugeInt & b)
        {

        }

        CHugeInt & operator + (int n)
        {

        }

        CHugeInt & operator ++ ()
        {

        }

        CHugeInt & operator ++ (int z)
        {

        }

        friend ostream & operator << (ostream & o, const CHugeInt & c)
        {
            o << c.p;
            return o;
        }

    // Ends here
};

int main()
{
    char s[210];
    int n;
    while(cin >> s >> n)
    {
        CHugeInt a(s);
        CHugeInt b(n);

        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout << ++b << endl;
        cout << b++ << endl;
        cout << b << endl;
    }
    return 0;
}
