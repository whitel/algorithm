#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int run(vector<int> weight, vector<int> value, int W) {
        int n = weight.size();

        vector<vector<int> > dp(n+1, vector<int>(W+1));
        for(int i = 1; i <= n; i++) {
            for(int k = 1; k <= W; k++) {
                if(k-weight[i] >= 0) {
                    // 放得下
                    dp[i][k] = max(dp[i-1][k], dp[i-1][k-weight[i]] + value[i]);
                } else {
                    // 放不下
                    dp[i][k] = dp[i-1][k];
                }
            }
        }
        return dp[n][W];
    }

};

int main() {
    Solution s;
    int n, W;
    cin >> n >> W;
    vector<int> weight(n+1);
    vector<int> value(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    cout << s.run(weight, value, W) << endl;
    return 0;
}
