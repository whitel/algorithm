#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
private:
    int x, y;
    int result;
public:
    void run() {
        result = INT_MAX;
        int a, b;
        cin >> a >> b >> x >> y;
        backtracking(a, b, 0);
        cout << result << endl;
    }

    void backtracking(int a, int b, int step) {
        if(a <= 0 && b <= 0) {
            result = min(result, step);
            return ;
        }
        int thisStep = step + 1;
        // 尝试使用单体攻击x对a进行攻击
        if(a > 0)
            backtracking(a - x, b, thisStep);
        // 尝试使用单体攻击x对b进行攻击
        if(b > 0)
            backtracking(a, b - x, thisStep);
        // 尝试使用群体攻击y
        backtracking(a - y, b - y, thisStep);
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

