#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    int times = 0;
    cin >> times;
    multiset<int> ms;
    set<int> histSet;
    while(times--)
    {
        string command;
        cin >> command;
        if(command == "add")
        {
            int number;
            cin >> number;
            ms.insert(number);
            histSet.insert(number);
            cout << ms.count(number) << endl;
        }
        else if(command == "del")
        {
            int number;
            cin >> number;
            cout << ms.count(number) << endl;
            ms.erase(number);
        }
        else if(command == "ask")
        {
            int number;
            cin >> number;
            if(histSet.find(number) != histSet.end()) cout << "1 ";
            else cout << "0 ";
            cout << ms.count(number) << endl;
        }
    }
    return 0;
}
