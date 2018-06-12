#include <iostream>
#include <set>
using namespace std;

// Starts here
class Rectangle {
public:
    int a, b;

    Rectangle(int _a, int _b) : a(_a), b(_b) {}

    friend ostream & operator << (ostream & o, const Rectangle & r) {
        o << r.area() <<" " <<  r.circumference();
        return o;
    }

    int circumference() const {
        return 2 * (a + b);
    }

    int area() const {
        return a * b;
    }

    friend bool operator < (const Rectangle & r1, const Rectangle & r2) {
        if(r1.area() > r2.area())
            return true;
        else if(r1.area() == r2.area())
        {
            if(r1.circumference() > r2.circumference())
                return true;
        }
        return false;
    }
};

class Comp {
public:
    bool operator()(const Rectangle &r1, const Rectangle &r2) {
        if(r1.circumference() < r2.circumference())
            return true;
        else if(r1.circumference() == r2.circumference()) {
            if(r1.area() < r2.area())
                return true;
        }
        return false;
    }
};
// Ends here

int main() {
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}