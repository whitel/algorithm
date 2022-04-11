#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        string str;
        cin >> str;
        stack<char> S;
        int result = 0;
        for(char c : str) {
            if(S.empty()){
                S.push(c);
            }
            else if(c == '(' || c == '[' || c == '{') {
                S.push(c);
            } else if(c == ')' && S.top() == '(') {
                S.pop();
                result += 1;
            } else if(c == ']' && S.top() == '[') {
                S.pop();
                result += 2;
            } else if(c == '}' && S.top() == '{') {
                S.pop();
                result += 3;
            } else {
                while(!S.empty())   S.pop();
            }
        }
        cout << result << endl;
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

