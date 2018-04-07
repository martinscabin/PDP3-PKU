#include <iostream>
using namespace std;
class Sample {
public:
	int v;
	// Starts here
	Sample()
	{
	    v = 0;
	}
	Sample(int n)
	{
	    v = n;
	}
	Sample(const Sample & s)
	{
	    v = s.v + 2;
	}
	// Ends here
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5);
	Sample b = a;
	PrintAndDouble(b);
	Sample c = 20;
	PrintAndDouble(c);
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}

// 9, 22, 5