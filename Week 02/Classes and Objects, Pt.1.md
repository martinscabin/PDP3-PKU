# 第2周 类和对象基础

## 1.编程填空：学生信息处理程序

**描述**

实现一个学生信息处理程序，计算一个学生的四年平均成绩。

要求实现一个代表学生的类，并且类中所有成员变量都是【私有的】。

补充下列程序中的 Student 类以实现上述功能。

```C++
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
// 在此处补充你的代码
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
```

**输入**

输入数据为一行，包括：
姓名,年龄,学号,第一学年平均成绩,第二学年平均成绩,第三学年平均成绩,第四学年平均成绩。
其中姓名为由字母和空格组成的字符串（输入保证姓名不超过20个字符，并且空格不会出现在字符串两端），年龄、学号和学年平均成绩均为非负整数。信息之间用逗号隔开。

**输出**

输出一行数据，包括：
姓名,年龄,学号,四年平均成绩。
信息之间用逗号隔开。

**样例输入**

Tom Hanks,18,7817,80,80,90,70

**样例输出**

Tom Hanks,18,7817,80

**提示**

必须用类实现，其中所有成员变量都是私有的。
输出结果中，四年平均成绩不一定为整数。


## 2.奇怪的类复制

**描述**

程序填空，使其输出9 22 5

```C++
#include <iostream>
using namespace std;
class Sample {
public:
	int v;
// 在此处补充你的代码
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
```

**输入**

无

**输出**

9
22
5

**样例输入**

None

**样例输出**

9
22
5

**来源**

Guo Wei


## 3.超简单的复数类

**描述**

下面程序的输出是：

3+4i 
5+6i

请补足Complex类的成员函数。不能加成员变量。

```C++
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
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
```

**输入**

无

**输出**

3+4i
5+6i

**样例输入**

无

**样例输出**

3+4i
5+6i

**来源**

Guo Wei

## 4.哪来的输出

**描述**

程序填空，输出指定结果 

```C++
#include <iostream>
using namespace std;
class A {
	public:
		int i;
		A(int x) { i = x; }
// 在此处补充你的代码
};
int main()
{
	A a(1);
	A * pa = new A(2);
	delete pa;
	return 0;
}
```

**输入**

无

**输出**

2
1

**样例输入**

无

**样例输出**

2
1

**来源**

Guo Wei
