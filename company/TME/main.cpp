#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
private:
    int directions[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };
public:
    void run() {
        int n;
        cin >> n;
        vector<vector<int> > mat(n, vector<int>(n));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> mat[i][j];
            }
        }

        vector<vector<bool> > visited(n, vector<bool>(n, false));
        int x = 0;
        int y = 0;
        int directionIndex = 0;
        for(int i = 0; i < n * n; ++i) {
            cout << mat[x][y] << " ";
            visited[x][y] = true;
            int nextX = x + directions[directionIndex][0];
            int nextY = y + directions[directionIndex][1];
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n || visited[nextX][nextY])
                directionIndex = (directionIndex + 1) % 4;
            x = x + directions[directionIndex][0];
            y = y + directions[directionIndex][1];
        }
        cout << endl;
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

