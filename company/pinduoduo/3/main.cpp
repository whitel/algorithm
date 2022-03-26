#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
private:
    vector<vector<int> > result;
    vector<int> path;

public:
    void run() {
        /*
            A:  001011
            B:	101110
        */
        int k;
        cin >> k;
        string A, B;
        cin >> B;
        int n = B.size();
        for(int i = 0; i < n; i++)
            A.push_back('0');
        
        for(int i = 0; i < n; ++i) {
            if(B[i] == '1') {
                // 先排除掉已经有1的情况
                bool flagA = false;
                bool flagB = false;
                if(i - k >= 0 && A[i-k] == '1')
                    flagA = true;
                if(i + k < n && A[i+k] == '1')
                    flagB = true;
                if(flagA || flagB)
                    continue;
                // 剩下情况都是没有1的，准备填充1，分3种情况（不可能都碰不到，因为那样B[i]不可能为1）
                // 左边碰得到，右边碰不到：填到左边
                if(i - k >= 0 && i + k >= n) {
                    A[i-k] = '1';
                }
                // 左边碰不到，右边碰得到：填到右边
                else if(i - k < 0 && i + k < n) {
                    A[i+k] = '1';
                }
                // 左边碰得到，右边碰得到：填到右边
                else if(i - k >= 0 && i + k < n) {
                    A[i+k] = '1';
                }
            }
        }
        cout << "A : " << A << endl;
        cout << "B : " << B << endl;
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


