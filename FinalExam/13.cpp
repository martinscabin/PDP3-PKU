#include<iostream>
#include<cstring>
#include<list>
#include<algorithm>

using namespace std;

class TV_Drama {
public:
    char name[100];
    int actor;
    int story;
    int acting_skill;

// Starts here
    TV_Drama(char * n, int a, int s, int as): actor(a), story(s), acting_skill(as) {
        int i;
        for(i = 0; n[i] != '\0'; i++) {
            name[i] = n[i];
        }
        name[i] = '\0';
    }

    bool operator < (TV_Drama & t) {
        return actor > t.actor;
    }
};

void Printer(TV_Drama & t) {
    cout << t.name << ";";
}

bool comparator_1(TV_Drama & a, TV_Drama & b) {
    return a.story > b.story;
}

class comparator_2
{
public:
    bool operator () (TV_Drama & a, TV_Drama & b) {
        return a.acting_skill > b.acting_skill;
    }
};
// Ends here

int main() {
    list<TV_Drama> lst;
    int n;

    cin >> n;
    char _name[100];
    int _actor, _story, _acting_skill;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin.getline(_name, 100);
        cin >> _actor >> _story >> _acting_skill;
        lst.push_back(TV_Drama(_name, _actor, _story, _acting_skill));
    }

    lst.sort();
    for_each(lst.begin(), lst.end(), Printer);
    cout << endl;

    lst.sort(comparator_1);
    for_each(lst.begin(), lst.end(), Printer);
    cout << endl;

    lst.sort(comparator_2());
    for_each(lst.begin(), lst.end(), Printer);
    cout << endl;

    return 0;
}