#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;
list<int> lst[10005];
template<class T>
void Print(T b,T e)
{
    while (b != e)
        cout << *b++ << " ";
    cout << endl;
}
int main()
{
    int n, id, id_1, id_2, num;
    cin >> n;
    string s;

    while (n--)
    {
        cin >> s;
        if (s == "new") {   cin >> id; }
        else if (s == "add") {  
            cin >> id >> num;
            lst[id].push_back(num);
        }
        else if (s == "out") {
            cin >> id;
            lst[id].sort();
            Print(lst[id].begin(), lst[id].end());
        }
        else if (s == "merge") {
            cin >> id_1 >> id_2;
            lst[id_1].merge(lst[id_2]);
        }
        else if (s == "unique") {
            cin >> id;
            lst[id].sort();
            lst[id].unique();
        }
    }
    return 0;
}
