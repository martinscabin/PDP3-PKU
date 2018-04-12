# 第3周 类和对象基础

## 1. 返回什么才好呢

**描述**

程序填空，使其按要求输出

```C++
#include <iostream>
using namespace std;
class A {
public:
	int val;

	A(int
// 在此处补充你的代码
};
int main()
{
	int m,n;
	A a;
	cout << a.val << endl;
	while(cin >> m >> n) {
		a.GetObj() = m;
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val<< endl;
	}
	return 0;
}
```

**输入**

多组数据，每组一行，是整数 m 和 n

**输出**

先输出一行： 

123 

然后，对每组数据，输出两行，第一行是m,第二行是n

**样例输入**

2 3
4 5

**样例输出**

123
2
3
4
5 

**来源**

Guo Wei

## 2. Big & Base 封闭类问题

**描述**

程序填空，输出指定结果

```C++
#include <iostream>
#include <string>
using namespace std;
class Base {
public:
	int k;
	Base(int n):k(n) { }
};
class Big
{
public:
	int v;
	Base b;
// 在此处补充你的代码
};
int main()
{
	int n;
	while(cin >>n) {
		Big a1(n);
		Big a2 = a1;
		cout << a1.v << "," << a1.b.k << endl;
		cout << a2.v << "," << a2.b.k << endl;
	}
}
```

**输入**

多组数据，每组一行，是一个整数

**输出**

对每组数据，输出两行，每行把输入的整数打印两遍

**样例输入**

3
4

**样例输出**

3,3
3,3
4,4
4,4	

**来源**

Guo Wei

## 3. 编程填空：统计动物数量

**描述**

代码填空，使得程序能够自动统计当前各种动物的数量

```C++
#include <iostream>
using namespace std;
// 在此处补充你的代码
void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}
```

**输入**

无

**输出**

0 animals in the zoo, 0 of them are dogs, 0 of them are cats
3 animals in the zoo, 2 of them are dogs, 1 of them are cats
6 animals in the zoo, 3 of them are dogs, 3 of them are cats
3 animals in the zoo, 2 of them are dogs, 1 of them are cats

**样例输入**

None

**样例输出**

0 animals in the zoo, 0 of them are dogs, 0 of them are cats
3 animals in the zoo, 2 of them are dogs, 1 of them are cats
6 animals in the zoo, 3 of them are dogs, 3 of them are cats
3 animals in the zoo, 2 of them are dogs, 1 of them are cats

## 4. 这个指针哪来的

**描述**

填空，按要求输出

```C++
#include <iostream>
using namespace std;

struct A
{
	int v;
	A(int vv):v(vv) { }
// 在此处补充你的代码
};

int main()
{
	const A a(10);
	const A * p = a.getPointer();
	cout << p->v << endl;
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

## 5. 魔兽世界之一：备战

**描述**

魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。 
红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。 

双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。 

武士在刚降生的时候有一个生命值。 

在每个整点，双方的司令部中各有一个武士降生。 

红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。 

蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。 

制造武士需要生命元。 

制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。 

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下： 

1) 武士降生 
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在10点整，红方司令部停止制造武士

输出事件时： 

首先按时间顺序输出； 

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数，代表测试数据组数。

每组测试数据共两行。 

第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。

**输出**

对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

**样例输入**

1
20
3 4 5 6 7

**样例输出**

Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors

