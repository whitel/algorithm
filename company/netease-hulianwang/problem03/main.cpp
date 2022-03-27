#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
private:
    vector<vector<int> > result;
    vector<int> path;
    int n;
public:
    void run() {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            path.push_back(i + 1);
        }
        backtracking(0);
        // vector<int> temp = {2, 4, 3, 1};
        // check(temp);
    }

    bool check(vector<int> &nums) {
        for(int i = n - 1; i > 0; --i) {
            if(i % 2 == 0) {
                if(nums[(i - 1) / 2] * nums[i] % 2 != 0)
                    return false;
            } else {
                if(nums[i / 2] * nums[i] % 2 != 0)
                    return false;
            }

        }
        return true;
    }

    void backtracking(int times) {
        if(times == n) {
            if(check(path)) {
                for(auto num : path) {
                    cout << num << " ";
                }
                cout << endl;
                exit(0);
            }
        }
        for(int i = times; i <= n; ++i) {
            swap(path[times], path[i]);
            backtracking(i + 1);
            swap(path[times], path[i]);
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

