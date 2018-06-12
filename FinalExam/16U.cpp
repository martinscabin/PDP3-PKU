#include <set>
#include <iostream>
#include <string>

using namespace std;

// Starts here
template <typename T1, typename T2>
class myComp
{
public:
    bool operator () (pair<T1, T2> & a, pair<T1, T2> & b)
    {
        if(b.second == -1)
        {
            return a.first == b.first;
        }
        else if(b.first == -1)
        {
            return a.second == b.second;
        }
    }
};
// Ends here

int main() {
    string cmd;
    set<pair<int, int>, myComp> S;
    while (cin >> cmd) {
        if (cmd == "A") {
            int x, y;
            cin >> x >> y;
            S.insert(make_pair(x, y));
        } else if (cmd == "Qx") {
            int x;
            cin >> x;
            cout << S.lower_bound(make_pair(x, -1))->second << endl;
        } else if (cmd == "Qy") {
            int y;
            cin >> y;
            cout << S.lower_bound(make_pair(-1, y))->first << endl;
        } else {
            int x, y;
            cin >> x >> y;
            S.erase(make_pair(x, y));
        }
    }
    return 0;
}