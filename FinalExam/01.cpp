#include <iostream>
#include <string>

using namespace std;

string dec2bin(int x) {
    // Starts here
    int a[31], b[31];
    for(int i = 0; i < 31; i++)
    {
        a[i] = b[i] = 0;
    }
    int idx = 30;
    int flag = 0;
    do
    {
        a[idx] = x % 2;
        x = x / 2;

        idx--;
    } while (x != 0);
    string s;
    for(int i = 0; i < 31; i++)
    {
        s += to_string(a[i]);
    }
    return s;
    // Ends here
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << dec2bin(x) << endl;
    }
    return 0;
}