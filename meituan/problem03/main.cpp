#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
private:
    string path;
    string str;
    string core;
    int result;
public:
    void run() {
        result = 0;
        cin >> str;
        cin >> core;
        backtraking(0);
    }

    void check() {
        if(path.find(core) != path.end()) {
            result++;
        }
    }

    void backtraking(int n) {
        if(n == str.size()) {
            check();
            return ;
        }
        
    }

};

int main() {
#ifdef DEBUG
    freopen("inputdata", "r", stdin);
    cout << "===========INPUT=============" << endl;
    system("cat inputdata");
    cout << endl;
    cout << "===========OUTPUT============" << endl;
#endif

    Solution s;
    s.run();

#ifdef DEBUG
    cout << "============END==============" << endl;
#endif
    return 0;
}

