#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
	// Start your code here
	private:
		char name[20];
		char c;
		int age;
		int number;
		int scores[4];
		float average;
	public:
		void input()
		{
			cin.getline(name, 20, ',');
			cin >> age >> c >> number >> c;
			for(int i = 0; i < 3; i++) 
			{
			    cin >> scores[i] >> c;
			}
			cin >> scores[3];
		}
		void calculate()
		{
			float sum = 0;
			for(int i = 0; i < 4; i++)
			{
				sum += scores[i];
			}
			average = sum / 4.0;
		}
		void output()
		{
			cout << name << "," << age << "," << number << "," << average << endl;
		}
	// Ends here
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
