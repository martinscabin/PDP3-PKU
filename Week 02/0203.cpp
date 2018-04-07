#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
	Complex(){}
	Complex(const char * s)
	{
		const char * delim = "+i";
		char * p;
		char * t = (char *)s;
		p = strtok(t, delim);
		while(p)
		{
			p = strtok(NULL, delim);
			double a = atof(p);
			cout << a << endl;
		}
	}
// Ends here
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
