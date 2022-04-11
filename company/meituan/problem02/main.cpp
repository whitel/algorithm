#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        int n;
        cin >> n;
        if(n <= 2){
            cout << 0 << endl;
            return ;
        }
        vector<int> nums(n);
        for(int i = 0; i < n; ++i)
            cin >> nums[i];
        int left = 0;
        int right = n - 1;
        while(left < right && nums[left] < nums[left + 1])  left++;
        // 单调递增的情况
        if(left == right) {
            cout << nums[n - 1] - nums[n - 2] + 1 << endl;
            return ;
        }
        while(left < right && nums[right] < nums[right - 1]) right--;
        // 单调递减的情况
        if(left == right) {
            cout << nums[0] - nums[1] + 1 << endl;
            return ;
        }
        // 正好合适的情况
        if(left + 1 == right) {
            cout << 0 << endl;
            return ;
        }
        // 不合适的情况
        int sum = 0;
        for(int i = left + 1; i < right; ++i) {
            sum += nums[i];
        }
        int result = (right-left-1) * (nums[left] + 1 + (right - left - 1) / 2) - sum;
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

