# 第4周 运算符重载

## 1. MyString

**描述**

补足MyString类，使程序输出指定结果

```C++
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
// 在此处补充你的代码
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}
```

**输入**

多组数据，每组一行，是两个不带空格的字符串

**输出**

对每组数据，先输出一行，打印输入中的第一个字符串三次
然后再输出一行，打印输入中的第二个字符串三次

**样例输入**

abc def
123 456

**样例输出**

abc,abc,abc
def,def,def
123,123,123
456,456,456

**来源**

Guo Wei

## 2. 看上去好坑的运算符重载

**描述**

程序填空

```C++
#include <iostream> 
using namespace std;
class MyInt 
{ 
	int nVal; 
	public: 
	MyInt( int n) { nVal = n ;}
// 在此处补充你的代码
}; 
int Inc(int n) {
	return n + 1;
}
int main () { 
	int n;
	while(cin >>n) {
		MyInt objInt(n); 
		objInt-2-1-3; 
		cout << Inc(objInt);
		cout <<","; 
		objInt-2-1; 
		cout << Inc(objInt) << endl;
	}
	return 0;
}
```

**输入**

多组数据，每组一行，整数n

**输出**

对每组数据，输出一行，包括两个整数， n-5和n - 8

**样例输入**

20
30

**样例输出**

15,12
25,22

**来源**

Guo Wei

## 3. 惊呆！Point竟然能这样输入输出

**描述**

程序填空

```C++
#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
// 在此处补充你的代码
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}
```

**输入**

多组数据，每组两个整数

**输出**

对每组数据，输出一行，就是输入的两个整数

**样例输入**

2 3
4 5

**样例输出**

2,3
4,5

**来源**

Guo Wei

## 4. 第四周程序填空题3

**描述**

写一个二维数组类 Array2,使得下面程序的输出结果是：

0,1,2,3,

4,5,6,7,

8,9,10,11,

next

0,1,2,3,

4,5,6,7,

8,9,10,11,

程序：

```C++
#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
```

**输入**

无

**输出**

0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,

**样例输入**

None

**样例输出**

0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,

## 5. 别叫，这个大整数已经很简化了!

**描述**

程序填空，输出指定结果

```C++
#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
```

**输入**

多组数据，每组数据是两个非负整数s和 n。s最多可能200位， n用int能表示

**输出**

对每组数据，输出6行，内容分别是：

**样例输入**

99999999999999999999999999888888888888888812345678901234567789 12
6 6

**样例输出**

99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
25
25
26
12
12
12
13
13
14

**来源**

Guo Wei
