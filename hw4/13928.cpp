#include <iostream>
#include <set>
using namespace std;

set<int>* getInter(const set<int>& a, const set<int>& b) {
    set<int>* inter = new set<int>;
    for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
        if (b.find(*it) != b.end()) {
            inter->insert(*it);
        }
    }
    return inter;
}

set<int>* getUnion(const set<int>& a, const set<int>& b) {
    set<int>* uni = new set<int>;
    for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
        uni->insert(*it);
    }
    for (set<int>::iterator it = b.begin(); it != b.end(); it++) {
        uni->insert(*it);
    }
    return uni;
}

set<int>* getCompl(const set<int>& a, const set<int>& b) {
    set<int>* comp = new set<int>;
    for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
        if (b.find(*it) == b.end()) {
            comp->insert(*it);
        }
    }
    return comp;
}

void printSet(const set<int>& a) {
    for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return;
}

int main() {
    int n, m;
    set<int> a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        b.insert(tmp);
    }
    set<int>* inter = getInter(a, b);
    set<int>* uni = getUnion(a, b);
    set<int>* comp = getCompl(a, b);
    printSet(*inter);
    printSet(*uni);
    printSet(*comp);
    delete inter;
    delete uni;
    delete comp;
    return 0;
}
