#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        int k;
        cin >> k;
        int cnt = 0;
        for(int i = 0; i < n && k > 0; ) {
            if(i + nums[i] >= n) {
                cout << cnt + 1 << endl;
                return ;
            }
            if(nums[i] == 0) {
                cout << -1 << endl;
                return ;
            }
            int maxNum = INT_MIN;
            int index = i + 1;
            for(int j = i + 1; j <= i + nums[i]; j++) {
                if(nums[j] + j > maxNum) {
                    index = j;
                    maxNum = max(maxNum, nums[j]);
                }
            }
            i = index;
            k--;
            cnt++;
        }
        cout << -1 << endl;
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

