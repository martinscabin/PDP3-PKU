#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;

class Printer {
// Starts here
public:
    int limit;
    Printer(int x): limit(x) {}

    void operator () (int & i) {
        if(i > limit) {
            cout << i << ",";
        }
    }

    void operator () (string & s) {
        if(s.size() > limit) {
            cout << s << ",";
        }
    }
};

// Ends here

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> x >> n;

        vector<int> intVec;
        for (int i = 0; i < n; ++i) {
            int y;
            cin >> y;
            intVec.push_back(y);
        }
        for_each(intVec.begin(), intVec.end(), Printer(x));
        cout << endl;

        vector<string> strVec;
        for (int i = 0; i < n; ++i) {
            string str;
            cin >> str;
            strVec.push_back(str);
        }
        for_each(strVec.begin(), strVec.end(), Printer(x));
        cout << endl;
    }
    return 0;
}