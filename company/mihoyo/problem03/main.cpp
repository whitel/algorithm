#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
private:
    int n, m;
    int directions[4][2] = {
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, 0}
    };
    int result;
public:
    void run() {
        cin >> n >> m;
        vector<vector<char> > mat(n, vector<char>(m));
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        int x = 0, y = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> mat[i][j];
                if(mat[i][j] == 'm') {
                    x = i;
                    y = j;
                }
            }
        }
        dfs(mat, x, y, 0, false, false);
    }

    void dfs(vector<vector<char> > &mat, int x, int y, int step, bool flagA, bool flagB) {
        if(mat[x][y] == '^' && flagA && flagB) {
            cout << step << endl;
            exit(0);
        }
        for(int directionIndex = 0; directionIndex < 4; ++directionIndex) {
            int nextX = x + directions[directionIndex][0];
            int nextY = y + directions[directionIndex][1];
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || mat[nextX][nextY] == 'B')
                continue;
            if(mat[x][y] == '#')
                dfs(mat, nextX, nextY, step + 1, true, flagB);
            else if(mat[x][y] == '$')
                dfs(mat, nextX, nextY, step + 1, flagA, true);
            else
                dfs(mat, nextX, nextY, step + 1, flagA, flagB);
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

