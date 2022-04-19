#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        int n, k, x;
        cin >> n >> k >> x;
        if(k < n) {
            cout << -1 << endl;
            return ;
        }
        vector<int> result(n);
        backtracking(result, n, k, x, 1);
        cout << -1 << endl;
    }

    void backtracking(vector<int> &nums, int n, int k, int x, int step) {
        if(step == n + 1) {
            int sum = 0;
            for(int i = 1; i <= nums.size(); ++i) {
                sum += nums[i];
            }
            if(sum == x) {
                for(int i = 1; i <= nums.size(); ++i) {
                    cout << nums[i] << " ";
                }
                cout << endl;
                exit(0);
            }
            return ;
        }
        for(int i = step; i < k; ++i) {
            nums[step] = i;
            backtracking(nums, n, k, x, step + 1);
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

