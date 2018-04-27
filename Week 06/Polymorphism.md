# 第6周 多态

## 1. 看上去像多态

**描述**

程序填空产生指定输出

```C++
#include <iostream>
using namespace std;
class B { 
	private: 
		int nBVal; 
	public: 
		void Print() 
		{ cout << "nBVal="<< nBVal << endl; } 
		void Fun() 
		{cout << "B::Fun" << endl; } 
		B ( int n ) { nBVal = n;} 
};
// 在此处补充你的代码
int main() { 
	B * pb; D * pd; 
	D d(4); d.Fun(); 
	pb = new B(2); pd = new D(8); 
	pb -> Fun(); pd->Fun(); 
	pb->Print (); pd->Print (); 
	pb = & d; pb->Fun(); 
	pb->Print(); 
	return 0;
}
```

**输入**

无

**输出**

D::Fun
B::Fun
D::Fun
nBVal=2
nBVal=24
nDVal=8
B::Fun
nBVal=12

**样例输入**

无

**样例输出**

D::Fun
B::Fun
D::Fun
nBVal=2
nBVal=24
nDVal=8
B::Fun
nBVal=12

**来源**

Guo Wei

## 2. Fun和Do

**描述**

程序填空输出指定结果

```C++
#include <iostream> 
using namespace std;
class A { 
	private: 
	int nVal; 
	public: 
	void Fun() 
	{ cout << "A::Fun" << endl; }; 
	void Do() 
	{ cout << "A::Do" << endl; } 
}; 
class B:public A { 
	public: 
	virtual void Do() 
	{ cout << "B::Do" << endl;} 
}; 
class C:public B { 
	public: 
	void Do( ) 
	{ cout <<"C::Do"<<endl; } 
	void Fun() 
	{ cout << "C::Fun" << endl; } 
}; 
void Call(
// 在此处补充你的代码
) { 
	p.Fun(); p.Do(); 
} 
int main() { 
	C c; 
	Call( c); 
	return 0;
}
```

**输入**

无

**输出**

A::Fun 
C::Do

**样例输入**

None

**样例输出**

A::Fun 
C::Do 

**来源**

Guo Wei

## 3. 这是什么鬼delete

**描述**

程序填空输出指定结果

```C++
#include <iostream> 
using namespace std;
class A 
{ 
public:
	A() { }
// 在此处补充你的代码
}; 
class B:public A { 
	public: 
	~B() { cout << "destructor B" << endl; } 
}; 
int main() 
{ 
	A * pa; 
	pa = new B; 
	delete pa; 
	return 0;
}
```

**输入**

无

**输出**

destructor B
destructor A

**样例输入**

无

**样例输出**

destructor B
destructor A

**来源**

Guo Wei

## 4. 怎么又是Fun和Do

**描述**

程序填空输出指定结果

```C++
#include <iostream>
using namespace std;
class A {
	private:
	int nVal;
	public:
	void Fun()
	{ cout << "A::Fun" << endl; };
	virtual void Do()
	{ cout << "A::Do" << endl; }
};
class B:public A {
	public:
	virtual void Do()
	{ cout << "B::Do" << endl;}
};
class C:public B {
	public:
	void Do( )
	{ cout <<"C::Do"<<endl; }
	void Fun()
	{ cout << "C::Fun" << endl; }
};
void Call(
// 在此处补充你的代码
) {
	p->Fun(); p->Do();
}
int main() {
	Call( new A());
	Call( new C());
	return 0;
}
```

**输入**

无

**输出**

A::Fun
A::Do
A::Fun
C::Do

**样例输入**

无

**样例输出**

A::Fun
A::Do
A::Fun
C::Do

**来源**

Guo Wei
