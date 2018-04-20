#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString
{
    char * p;
    public:
        MyString(const char * s)
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
        ~MyString()
        {
            if(p)
            {
                delete[] p;
            }
        }
        // Starts here
        MyString(const MyString & b)
        {
        //    if(p) delete[] p;
            if(b.p)
            {
                p = new char[strlen(b.p) + 1];
                strcpy(p, b.p);
            }
            else
            {
                p = NULL;
            }
        }

        void Copy(const char * w)
        {
        //    if(p) delete[] p;
            if(w)
            {
                p = new char[strlen(w) + 1];
                strcpy(p, w);
            }
            else 
            {
                p = NULL;
            }
        }

        MyString & operator = (const MyString & s)
        {
            if(this != &s)
            {
            //    if(p) delete[] p;
                if(s.p)
                {
                    p = new char[strlen(s.p) + 1];
                    strcpy(p, s.p);
                }
                else 
                {
                    p = NULL;
                }
            }
            return * this;
        }

        friend ostream & operator << (ostream & o, const MyString & s)
        {
            o << s.p;
            return o;
        }
        // Ends here
};

int main() 
{
    char w1[200], w2[200];
    while(cin >> w1 >> w2)
    {
        MyString s1(w1), s2 = s1;
        MyString s3(NULL);
        s3.Copy(w1);
        cout << s1 << "," << s2 << "," << s3 << endl;
        s2 = w2;
        s3 = s2;
        s1 = s3;
        cout << s1 << "," << s2 << "," << s3 << endl;
    }
    return 0;
}
