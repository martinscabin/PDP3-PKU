// https://blog.csdn.net/veniversum/article/details/71512474

#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
// 在此处补充你的代码
public:
    class CArray2D
    {
    private:
        int row;
        int col;
        int size_;
        T *ptr;
    public:
        CArray2D() :row(0), col(0), size_(0)
        {
            ptr = new T[1];
        }
        void init(int r, int c) 
        {
            row = r; col = c; size_ = r * c;
            delete[]ptr;
            ptr = new T[size_ + 1];
        }
        T * operator[](int i)
        {
            return (ptr + i * col);
        }
        operator T*()//only for memset
        {
            return ptr;
        }
    };
    CArray2D * a;
    CArray3D(int level,int row,int col)
    {
        a = new CArray2D[level];
        //这里还是使用无参构造函数的好
        //真正初始化的工作可以在另外的函数体内完成
        for (int i = 0; i < level; ++i)
            a[i].init(row, col);
    }
    CArray2D& operator[](int i)
    {
        //a由于牵扯到赋值和内部类的复制构造函数，返回值类型设定为&是最好的
        return a[i];
    }
// 在此结束补充的代码
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
    //这个是内置类型，就不用处理了
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
