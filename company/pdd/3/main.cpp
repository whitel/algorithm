#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void run(string B, int k, int left, int right) {
        if(left == right) {
            cout << A << endl;
        }
        if(B[left] == '0') {
            // 无事可做，进入下一个判断
            run(B, k, left+1, right);
            return ;
        }
        if(B[left] == '1') {
            // 看看左右是不是1
            // 如果1 1
            // 直接进入下一个循环
            bool flag = false;
            if(i-k >= 0 && A[i-k] == '1') {
                    flag = true;
            }
            if(i+k < right && A[i+k] == '1') {
                    flag = true;
            }
            // 如果1 0
            // 如果0 1
            // 如果0 0
        }

    }

};

int main() {
    Solution s;
    // input here
    int k;
    cin >> k;
    string B;
    cin >> B;
    string A;
    for(int i = 0; i < B.size(); ++i)
        A += '0';

    for(int i = 0; i < B.size(); ++i) {
        if(B[i] == '1') {
            if(i - k >= 0) {
                A[i-k] = '1';
            }
            if(i + k < B.size()) {
                A[i+k] = '1';
            }
        }
    }


    cout << A << endl;
    s.run();
    return 0;
}
