#include <cstdlib>
#include <iostream>
using namespace std;

int strlen(const char * s)
{
    int i = 0;
    for(; s[i]; ++i);
    return i;
}

void strcpy(char * d, const char * s)
{
    int i = 0;
    for(i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;
}

int strcmp(const char * s1, const char * s2)
{
    for(int i = 0; s1[i] && s2[i]; ++i)
    {
        if(s1[i] < s2[i])
            return -1;
        else 
            return 1;
    }
    return 0;
}

void strcat(char * d, const char * s)
{
    int len = strlen(d);
    strcpy(d + len, s);
}

class MyString
{
    // Starts here
    private:
        char * p;
    public:
        MyString()
        {
            p = new char[1];
            p[0] = 0;
        }
        
        ~MyString()
        {
            if(p)
            {
                delete[] p;
            }
        }

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
        
        MyString(const MyString & b)
        {
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

        friend ostream & operator << (ostream & o, const MyString & b)
        {
            o << b.p;
            return o;
        }

        friend MyString & operator + (const MyString & a, const MyString & b)
        {
            MyString * c = new MyString(a.p);
            if(b.p)
            {
                strcat(c->p, b.p);
            }
            return *c;
        }

        MyString & operator = (const MyString & b)
        {
            if(this != &b)
            {
                if(b.p)
                {
                    if(p) delete[] p;
                    p = new char[strlen(b.p) + 1];
                    strcpy(p, b.p);
                }
                else 
                {
                    p = NULL;
                }
            }
            return *this;
        }

        char & operator [] (int idx)
        {
            return *(p + idx);
        }

        bool operator < (const MyString & b)
        {
            if(strcmp(p, b.p) == -1)
                return true;
            return false;
        }

        bool operator > (const MyString & b)
        {
            if(strcmp(p, b.p) == 1)
                return true;
            return false;
        }

        bool operator == (const MyString & b)
        {
            if(strcmp(p, b.p) == 0)
                return true;
            return false;
        }

        MyString & operator () (int idx, int len)
        {
            char * c = new char[len + 1];
            for(int i = 0; i < len; i++)
            {
                c[i] = p[idx + i];
            }
            c[len] = 0;
            MyString * b = new MyString(c);
            return *b;
        }

        MyString & operator += (const MyString & b)
        {
            if(b.p)
            {
                strcat(p, b.p);
            }
            return *this;
        }
    // Ends here
};

int CompareString(const void * e1, const void * e2)
{
    MyString * s1 = (MyString *)e1;
    MyString * s2 = (MyString *)e2;
    if(*s1 < *s2)
        return -1;
    else if(*s1 == *s2)
        return 0;
    else if(*s1 > *s2)
        return 1;
}

int main()
{
    MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
    MyString SArray[4] = {"big", "me", "about", "take"};
    cout << "1." << s1 << s2 << s3 << s4 << endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2." << s1 << endl;
    cout << "3." << s2 << endl;
    cout << "4." << s3 << endl;
    cout << "5." << s4 << endl;
    cout << "6." << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A';
    cout << "7." << s2 << endl;
    cout << "8." << s1 << endl;
    s1 += "mnop";
    cout << "9." << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10." << s4 << endl;
    s1 = s2 + s4 + "uvw" + "xyz";
    cout << "11." << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for(int i = 0; i < 4; i++)
        cout << SArray[i] << endl;
    // Returns the substring which begins at index 0 with length 4
    cout << s1(0, 4) << endl;
    // Returns the substring which begins at index 5 with length 10
    cout << s1(5, 10) << endl;
    return 0;
}
