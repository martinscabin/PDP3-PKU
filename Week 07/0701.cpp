#include <iostream>
#include <string>
using namespace std;

template <class T>
T SumArray
(
    // Starts here
    T * s, T * e
)
{
    T result = T();
    while(s != e)
    {
        result += (*s);
        s++;
    }
    return result;
    // Ends here
}

int main()
{
    string array[4] = {"Tom", "Jack", "Mary", "John"};
    cout << SumArray(array, array + 4) << endl;
    int a[4] = {1, 2, 3, 4};
    cout << SumArray(a, a + 4) << endl;
    return 0;
}
