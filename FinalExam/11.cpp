#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;

class MyQueue {

// Starts here
public:
    multiset<int, greater<int> > s;
    int topK;
    MyQueue(int k): topK(k) {}
    friend istream & operator >> (istream & i, MyQueue & q) {
        int t;
        i >> t;
        if(t % 2 == 0) {
            q.s.insert(t);
        }
        return i;
    }
    friend ostream & operator << (ostream & o, MyQueue & q) {
        int i = 0;
        multiset<int, greater<int> >::iterator it = q.s.begin();
        while(i < q.topK) {
            o << *it << " ";
            ++it;
            ++i;
        }
        return o;
    }
// Ends here

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        MyQueue q(k);
        for (int i = 0; i < n; ++i)
            cin >> q;
        cout << q;
        cout << endl;
    }
    return 0;
}