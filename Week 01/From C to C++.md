# 第1周 从C到C++

## 1:简单的swap

**描述**

填空，使得程序输出结果是：

5,3

```C++
#include <iostream>
using namespace std;
class A
{
	public:
	int x;
	int getX() { return x; }	
};
void swap(
// 在此处补充你的代码
)
{
	int  tmp = a.x;
	a.x = b.x;
	b.x = tmp;
}
int main()
{
	A a,b;
	a.x = 3;
	b.x = 5;
	swap(a,b);
	cout << a.getX() << "," << b.getX();
	return 0;
}
```

**输入**

无

**输出**

5,3

**样例输入**

无

**样例输出**

5,3

**来源**

Guo Wei

## 2:难一点的swap

**描述**

填空，使得程序输出结果是：

5,3

```C++
#include <iostream>
using namespace std;

void swap(
// 在此处补充你的代码
)
{
	int * tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a = 3,b = 5;
	int * pa = & a;
	int * pb = & b;
	swap(pa,pb);
	cout << *pa << "," << * pb;
	return 0;
}
```

**输入**

无

**输出**

5,3

**样例输入**

无

**样例输出**

5,3

**来源**

Guo Wei

## 3:好怪异的返回值

**描述**

填空，使得程序输出指定结果

```C++
#include <iostream>
using namespace std;
// 在此处补充你的代码
getElement(int * a, int i)
{
	return a[i];
}
int main()
{
	int a[] = {1,2,3};
	getElement(a,1) = 10;
	cout << a[1] ;
	return 0;
}
```

**输入**

无

**输出**

10

**样例输入**

无

**样例输出**

10

**来源**

Guo Wei

## 4:神秘的数组初始化

**描述**

填空，使得程序输出指定结果

```C++
#include <iostream>
using namespace std;

int main()
{
	int * a[] = {
// 在此处补充你的代码
};
	
	*a[2] = 123;
	a[3][5] = 456;
	if(! a[0] ) {
		cout << * a[2] << "," << a[3][5];
	}
	return 0;
}
```

**输入**

无

**输出**

123,456

**样例输入**

无

**样例输出**

123,456

**来源**

Guo Wei

