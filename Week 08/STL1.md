# 第8周 标准模板库（一）

## 1. goodcopy

**描述**

    编写GoodCopy类模板，使得程序按指定方式输出

```C++
    #include <iostream>
    using namespace std;


    template <class T>
    struct GoodCopy {

// 在此处补充你的代码

    };

    int a[200];
    int b[200];
    string c[200];
    string d[200];

    template <class T>
    void Print(T s,T e) {
    	for(; s != e; ++s)
    		cout << * s << ",";
    	cout << endl;
    }

    int main()
    {
    	int t;
    	cin >> t;
    	while( t -- ) {
    		int m ;
    		cin >> m;
    		for(int i = 0;i < m; ++i)
    			cin >> a[i];
    		GoodCopy<int>()(a,a+m,b);
    		Print(b,b+m);
    		GoodCopy<int>()(a,a+m,a+m/2);
    		Print(a+m/2,a+m/2 + m);

    		for(int i = 0;i < m; ++i)
    			cin >> c[i];
    		GoodCopy<string>()(c,c+m,d);
    		Print(c,c+m);
    		GoodCopy<string>()(c,c+m,c+m/2);
    		Print(c+m/2,c+m/2 + m);
    	}
    	return 0;
    }
```

**输入**

    第一行是整数 t,表示数据组数
    每组数据：
    第一行是整数 n , n < 50
    第二行是 n 个整数
    第三行是 n 个字符串

**输出**

    将输入的整数原序输出两次，用","分隔
    然后将输入的字符串原序输出两次，也用 ","分隔

**样例输入**

    2
    4
    1 2 3 4
    Tom Jack Marry Peking
    1
    0
    Ted

**样例输出**

    1,2,3,4,
    1,2,3,4,
    Tom,Jack,Marry,Peking,
    Tom,Jack,Marry,Peking,
    0,
    0,
    Ted,
    Ted, 

**来源**

    Guo Wei 
    
## 2. 按距离排序

**描述**

    程序填空，输出指定结果

```C++
    #include <iostream>
    #include <cmath>
    #include <algorithm>
    #include <string>
    using namespace std;
    template <class T1,class T2>
    struct Closer {

// 在此处补充你的代码

    };

    int Distance1(int n1,int n2) {
    	return abs(n1-n2);
    }
    int Distance2(const string & s1, const string & s2)
    {
    	return abs((int)s1.length()- (int) s2.length());
    }
    int a[10] = { 0,3,1,4,7,9,20,8,10,15};
    string b[6] = {"American","Jack","To","Peking","abcdefghijklmnop","123456789"};
    int main()
    {
    	int n;string s;
    	while( cin >> n >> s ) {
    		sort(a,a+10,Closer<int ,int (*)(int ,int)> (n,Distance1));
    		for(int i = 0;i < 10; ++i)
    			cout << a[i] << "," ;
    		cout << endl;
    		sort(b,b+6,Closer<string,int (*)(const string &,const string &  )> (s,Distance2)); 
    		for(int i = 0;i < 6; ++i)
    			cout << b[i] << "," ;
    		cout << endl;
    	}
    	return 0;
    }
```

**输入**

    多组数据，每组一行，是一个整数n和一个字符串s

**输出**

    定义两个整数的距离为两个整数差的绝对值
    定义两个字符串的距离为两个字符串长度差的绝对值

    对每组数据：
    对数组a按和n的距离从小到大排序后输出。距离相同的，值小的排在前面。
    然后对数组b，按照和s的距离从小到大输出。距离相同的，字典序小的排在前面

**样例输入**

    2 a123456
    4 a12345

**样例输出**

    1,3,0,4,7,8,9,10,15,20,
    American,Peking,123456789,Jack,To,abcdefghijklmnop,
    4,3,1,7,0,8,9,10,15,20,
    Peking,American,Jack,123456789,To,abcdefghijklmnop,

**来源**

    Guo Wei
    
## 3. 很难蒙混过关的CArray3d三维数组模板类 

**描述**

    实现一个三维数组模版CArray3D，可以用来生成元素为任意类型变量的三维数组，输出指定结果

```C++
    #include <iostream>
    #include <iomanip> 
    #include <cstring>
    using namespace std;
    template <class T>
    class CArray3D
    {

// 在此处补充你的代码

    };

    CArray3D<int> a(3,4,5);
    CArray3D<double> b(3,2,2);
    void PrintA()
    {
    	for(int i = 0;i < 3; ++i) {
    		cout << "layer " << i << ":" << endl;
    		for(int j = 0; j < 4; ++j) {
    			for(int k = 0; k < 5; ++k) 
    				cout << a[i][j][k] << "," ;
    			cout << endl;
    		}
    	}
    }
    void PrintB()
    {
    	for(int i = 0;i < 3; ++i) {
    		cout << "layer " << i << ":" << endl;
    		for(int j = 0; j < 2; ++j) {
    			for(int k = 0; k < 2; ++k) 
    				cout << b[i][j][k] << "," ;
    			cout << endl;
    		}
    	}
    }

    int main()
    {

    	int No = 0;
    	for( int i = 0; i < 3; ++ i ) {
    		a[i];
    		for( int j = 0; j < 4; ++j ) {
    			a[j][i];
    			for( int k = 0; k < 5; ++k )
    				a[i][j][k] = No ++;
    			a[j][i][i];	
    		}
    	}
    	PrintA();
    	memset(a[1],-1 ,20*sizeof(int));	
    	memset(a[1],-1 ,20*sizeof(int));
    	PrintA(); 
    	memset(a[1][1],0 ,5*sizeof(int));	
    	PrintA();

    	for( int i = 0; i < 3; ++ i )
    		for( int j = 0; j < 2; ++j )
    			for( int k = 0; k < 2; ++k )
    				b[i][j][k] = 10.0/(i+j+k+1);
    	PrintB();
    	int n = a[0][1][2];
    	double f = b[0][1][1];
    	cout << "****" << endl;
    	cout << n << "," << f << endl;
    		
    	return 0;
    }
```

**输入**

    无

**输出**

    等同于样例

**样例输入**

    无

**样例输出**

    layer 0:
    0,1,2,3,4,
    5,6,7,8,9,
    10,11,12,13,14,
    15,16,17,18,19,
    layer 1:
    20,21,22,23,24,
    25,26,27,28,29,
    30,31,32,33,34,
    35,36,37,38,39,
    layer 2:
    40,41,42,43,44,
    45,46,47,48,49,
    50,51,52,53,54,
    55,56,57,58,59,
    layer 0:
    0,1,2,3,4,
    5,6,7,8,9,
    10,11,12,13,14,
    15,16,17,18,19,
    layer 1:
    -1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,
    layer 2:
    40,41,42,43,44,
    45,46,47,48,49,
    50,51,52,53,54,
    55,56,57,58,59,
    layer 0:
    0,1,2,3,4,
    5,6,7,8,9,
    10,11,12,13,14,
    15,16,17,18,19,
    layer 1:
    -1,-1,-1,-1,-1,
    0,0,0,0,0,
    -1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,
    layer 2:
    40,41,42,43,44,
    45,46,47,48,49,
    50,51,52,53,54,
    55,56,57,58,59,
    layer 0:
    10,5,
    5,3.33333,
    layer 1:
    5,3.33333,
    3.33333,2.5,
    layer 2:
    3.33333,2.5,
    2.5,2,
    ****
    7,3.33333

**提示**

    建议做法：
    1. a[i][j][k] 这个表达式的第一个[]返回一个内部类的对象，该内部类也重载了[],且返回值为指针。
    2. 必要时需重载对象到指针的强制类型转换运算符

**来源**

    Guo Wei 
    
## 4. 函数对象的过滤器

**描述**

    程序填空输出指定结果

```C++
    #include <iostream>
    #include <vector>
    using namespace std;


    struct A {
    	int v;
    	A() { }
    	A(int n):v(n) { };
    	bool operator<(const A & a) const {
    		return v < a.v;
    	}
    };

// 在此处补充你的代码

    template <class T>
    void Print(T s,T e)
    {
    	for(;s!=e; ++s)
    		cout << *s << ",";
    	cout << endl;
    }
    template <class T1, class T2,class T3>
    T2 Filter( T1 s,T1 e, T2 s2, T3 op) 
    {
    	for(;s != e; ++s) {
    		if( op(*s)) {
    			* s2 = * s;
    			++s2;
    		}
    	}
    	return s2;
    }

    ostream & operator <<(ostream & o,A & a)
    {
    	o << a.v;
    	return o;
    }
    vector<int> ia;
    vector<A> aa; 
    int main()
    {
    	int m,n;
    	while(cin >> m >> n) {
    		ia.clear();
    		aa.clear(); 
    		int k,tmp;
    		cin >> k;
    		for(int i = 0;i < k; ++i) {
    			cin >> tmp; 
    			ia.push_back(tmp);
    			aa.push_back(tmp); 
    		}
    		vector<int> ib(k);
    		vector<A> ab(k);
    		vector<int>::iterator p =  Filter(ia.begin(),ia.end(),ib.begin(),FilterClass<int>(m,n));
    		Print(ib.begin(),p);
    		vector<A>::iterator pp = Filter(aa.begin(),aa.end(),ab.begin(),FilterClass<A>(m,n));
    		Print(ab.begin(),pp);
    		
    	}
    	return 0;
    }
```

**输入**

    多组数据
    每组数据两行

    第一行是两个整数 m 和 n
    第二行先是一个整数k ,然后后面跟着k个整数

**输出**

    对每组数据，按原顺序输出第二行的后k个整数中，大于m且小于n的数
    输出两遍
    数据保证一定能找到符合要求的整数

**样例输入**

    1 3
    1 2
    2 8
    5 1 2 3 4 9

**样例输出**

    2,
    2,
    3,4,
    3,4,

**来源**

    Guo Wei 
    
## 5. 白给的list排序

**描述**

    程序填空，产生指定输出

```C++
    #include <cstdio>
    #include <iostream>
    #include <algorithm>
    #include <list>
    using namespace std;
    int main()
    {	
    	double a[] = {1.2,3.4,9.8,7.3,2.6};
    	list<double> lst(a,a+5);
    	lst.sort(

// 在此处补充你的代码

    );
    	
    	for(list<double>::iterator i  = lst.begin(); i != lst.end(); ++i) 
    		cout << * i << "," ;
        return 0;
    }
```

**输入**

    无

**输出**

    9.8,7.3,3.4,2.6,1.2,

**样例输入**

    无

**样例输出**

    同输入 

**来源**

    Guo Wei 
    
## 6. 我自己的 ostream_iterator

**描述**

    程序填空输出指定结果

```C++
    #include <iostream>
    #include <list>
    #include <string>
    using namespace std;

    template <class T1,class T2>
    void Copy(T1 s,T1 e, T2 x)
    {
    	for(; s != e; ++s,++x)
    		*x = *s;
    }

     
    template<class T>
    class myostream_iteraotr
    {

// 在此处补充你的代码

    };


    int main()
    {	const int SIZE = 5;
    	int a[SIZE] = {5,21,14,2,3};
    	double b[SIZE] = { 1.4, 5.56,3.2,98.3,3.3};
    	list<int> lst(a,a+SIZE);
    	myostream_iteraotr<int> output(cout,",");
    	Copy( lst.begin(),lst.end(),output); 
    	cout << endl;
    	myostream_iteraotr<double> output2(cout,"--");
    	Copy(b,b+SIZE,output2);
    	return 0;
    }
```

**输入**

    无

**输出**

    5,21,14,2,3,
    1.4--5.56--3.2--98.3--3.3--

**样例输入**

    无

**样例输出**

    同输入

**来源**

    Guo Wei
    
## 7. List

**描述**

    写一个程序完成以下命令：
    new id ——新建一个指定编号为id的序列(id<10000)
    add id num——向编号为id的序列加入整数num
    merge id1 id2——合并序列id1和id2中的数，并将id2清空
    unique id——去掉序列id中重复的元素
    out id ——从小到大输出编号为id的序列中的元素，以空格隔开

**输入**

    第一行一个数n，表示有多少个命令( n＜＝２０００００)。以后n行每行一个命令。

**输出**

    按题目要求输出。

**样例输入**

    16
    new 1
    new 2
    add 1 1
    add 1 2
    add 1 3
    add 2 1
    add 2 2
    add 2 3
    add 2 4
    out 1
    out 2
    merge 1 2
    out 1
    out 2
    unique 1
    out 1

**样例输出**

    1 2 3 
    1 2 3 4
    1 1 2 2 3 3 4

    1 2 3 4

 