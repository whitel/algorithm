#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
private:
    int n, m;
    vector<int> path;
    int directions[3][2] = {
        {0, 1},
        {1, 0},
        {0, -1}
    };
    int result;
public:
    void run() {
        result = INT_MAX;
        cin >> n >> m;
        vector<vector<int> > nums(n, vector<int>(m));
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> nums[i][j];
            }
        }
        visited[0][0] = true;
        dfs(nums, visited, 0, 0, 0);
        cout << result << endl;
    }
    
    void dfs(vector<vector<int> > &nums, vector<vector<bool> > &visited, int x, int y, int payment) {
        if(x == n - 1 && y == m - 1) {
            result = min(result, payment);
            return ;
        }
        for(int directionIndex = 0; directionIndex < 2; ++directionIndex) {
            int nextX = x + directions[directionIndex][0];
            int nextY = y + directions[directionIndex][1];
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || visited[nextX][nextY])
                continue;
            // 继续走一步
            visited[nextX][nextY] = true;
            if(nums[x][y] != nums[nextX][nextY])
                dfs(nums, visited, nextX, nextY, payment + 2);
            else
                dfs(nums, visited, nextX, nextY, payment + 1);
            visited[nextX][nextY] = false;
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

