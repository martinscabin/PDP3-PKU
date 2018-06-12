# 第9周 标准模板库（二）

## 1. Set

**描述**

    现有一整数集（允许有重复元素），初始为空。我们定义如下操作：
    add x 把x加入集合
    del x 把集合中所有与x相等的元素删除
    ask x 对集合中元素x的情况询问
    对每种操作，我们要求进行如下输出。
    add 输出操作后集合中x的个数
    del 输出操作前集合中x的个数
    ask 先输出0或1表示x是否曾被加入集合（0表示不曾加入），再输出当前集合中x的个数，中间用空格格开。

**输入**

    第一行是一个整数n，表示命令数。0<=n<=100000。
    后面n行命令，如Description中所述。

**输出**

    共n行，每行按要求输出。

**样例输入**

    7
    add 1
    add 1
    ask 1
    ask 2
    del 2
    del 1
    ask 1

**样例输出**

    1
    2
    1 2
    0 0
    0
    2
    1 0

**提示**

    Please use STL’s set and multiset to finish the task

## 2. 热血格斗场

**描述**

    为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家热血格斗场。格斗场实行会员制，但是新来的会员不需要交入会费，而只要同一名老会员打一场表演赛，证明自己的实力。

    我们假设格斗的实力可以用一个正整数表示，成为实力值。另外，每个人都有一个唯一的id，也是一个正整数。为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，即比赛双方的实力值之差的绝对值越小越好，如果有两个人的实力值与他差别相同，则他会选择比他弱的那个（显然，虐人必被虐好）。

    不幸的是，Facer一不小心把比赛记录弄丢了，但是他还保留着会员的注册记录。现在请你帮facer恢复比赛纪录，按照时间顺序依次输出每场比赛双方的id。
输入

    第一行一个数n(0 < n <=100000)，表示格斗场新来的会员数（不包括facer）。以后n行每一行两个数，按照入会的时间给出会员的id和实力值。一开始，facer就算是会员，id为1，实力值1000000000。输入保证两人的实力值不同。

**输出**

    N行，每行两个数，为每场比赛双方的id，新手的id写在前面。

**样例输入**

    3
    2 1
    3 3
    4 2

**样例输出**

    2 1
    3 2
    4 2

## 3. 冷血格斗场

**描述**

    为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家冷血格斗场。格斗场实行会员制，但是新来的会员不需要交入会费，而只要同一名老会员打一场表演赛，证明自己的实力。

    我们假设格斗的实力可以用一个正整数表示，成为实力值，两人的实力值可以相同。另外，每个人都有一个唯一的id，也是一个正整数。为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，即比赛双方的实力值之差的绝对值越小越好，如果有多个人的实力值与他差别相同，则他会选择id最小的那个。

    不幸的是，Facer一不小心把比赛记录弄丢了，但是他还保留着会员的注册记录。现在请你帮facer恢复比赛纪录，按照时间顺序依次输出每场比赛双方的id。

**输入**

    第一行一个数n(0 < n <=100000)，表示格斗场新来的会员数（不包括facer）。以后n行每一行两个数，按照入会的时间给出会员的id和实力值。一开始，facer就算是会员，id为1，实力值1000000000。

**输出**

    N行，每行两个数，为每场比赛双方的id，新手的id写在前面。

**样例输入**

    3
    2 3
    3 1
    4 2

**样例输出**

    2 1
    3 2
    4 2

## 4. 编程填空：数据库内的学生信息

**描述**

    程序填空，使得下面的程序,先输出

    (Tom,80),(Tom,70),(Jone,90),(Jack,70),(Alice,100),

    (Tom,78),(Tom,78),(Jone,90),(Jack,70),(Alice,100),

    (70,Jack),(70,Tom),(80,Tom),(90,Jone),(100,Alice),

    (70,Error),(70,Error),(80,Tom),(90,Jone),(100,Alice),

    ******

    然后，再根据输入数据按要求产生输出数据

```C++
    #include <iostream>
    #include <string>
    #include <map>
    #include <iterator>
    #include <algorithm>
    using namespace std;

// 在此处补充你的代码

    struct Student 
    {
    	string name;
    	int score;
    };
    template <class T>
    void Print(T first,T last) {
    	for(;first!= last; ++ first)
    		cout << * first << ",";
    	cout << endl;
    }
    int main()
    {
    	
    	Student s[] = { {"Tom",80},{"Jack",70},
    					{"Jone",90},{"Tom",70},{"Alice",100} };
    	
    	MyMultimap<string,int> mp;
    	for(int i = 0; i<5; ++ i)
    		mp.insert(make_pair(s[i].name,s[i].score));
    	Print(mp.begin(),mp.end()); //按姓名从大到小输出

    	mp.Set("Tom",78); //把所有名为"Tom"的学生的成绩都设置为78
    	Print(mp.begin(),mp.end());
    	
    	
    	
    	MyMultimap<int,string,less<int> > mp2;
    	for(int i = 0; i<5; ++ i) 
    		mp2.insert(make_pair(s[i].score,s[i].name));
    	
    	Print(mp2.begin(),mp2.end()); //按成绩从小到大输出
    	mp2.Set(70,"Error");          //把所有成绩为70的学生，名字都改为"Error"
    	Print(mp2.begin(),mp2.end());
    	cout << "******" << endl;
    	
    	mp.clear();
    	
    	string name;
    	string cmd;
    	int score;		
    	while(cin >> cmd ) {
    		if( cmd == "A") {
    			cin >> name >> score;
    			if(mp.find(name) != mp.end() ) {
    				cout << "erroe" << endl;
    			}
    			mp.insert(make_pair(name,score));
    		}
    		else if(cmd == "Q") {
    			cin >> name;
    			MyMultimap<string,int>::iterator p = mp.find(name);
    			if( p!= mp.end()) {
    				cout << p->second << endl;
    			}
    			else {
    				cout << "Not Found" << endl; 
    			}		
    		}
    	}
    	return 0;
    }
```

**输入**

    输入数据的每一行，格式为以下之一：

    A name score
    Q name score

    name是个不带个空格的字符串，长度小于 20
    score是个整数，能用int表示

    A name score 表示往数据库中新增一个姓名为name的学生，其分数为score。开始时数据库中一个学生也没有。
    Q name 表示在数据库中查询姓名为name的学生的分数


    数据保证学生不重名。
    输入数据少于200,000行。

**输出**

    对于每个查询，输出学生的分数。如果查不到，则输出 "Not Found"

**样例输入**

    A Tom1 30
    A Tom2 40
    Q Tom3 
    A Tom4 89
    Q Tom1
    Q Tom2

**样例输出**

    (Tom,80),(Tom,70),(Jone,90),(Jack,70),(Alice,100),
    (Tom,78),(Tom,78),(Jone,90),(Jack,70),(Alice,100),
    (70,Jack),(70,Tom),(80,Tom),(90,Jone),(100,Alice),
    (70,Error),(70,Error),(80,Tom),(90,Jone),(100,Alice),
    ******
    Not Found
    30
    40

**提示**

    1) 编写模板的时候，连续的两个 “>”最好要用空格分开，以免被编译器看作是 ">>"运算符。VS可能无此问题，但是Dev C++和服务器上的编译环境会有这个问题。
    比如 vector<vector<int>> 有可能出错，要改成 vector<vector<int> >

    2) 在模板中写迭代器时，最好在前面加上 typename关键字，否则可能会编译错。VS可能无此问题，但是Dev C++和服务器上的编译环境会有这个问题。 
