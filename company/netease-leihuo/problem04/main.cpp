#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
private:
    int directions[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    int N, M;
    int X, Y;
    int Z, W;
    bool flag;
    int di[8][2] = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, 1},
        {0, -1},
        {1, -1},
        {1, 0},
        {1, 1}
    };
public:
    void run() {
        cin >> N >> M;
        cin >> X >> Y;
        cin >> Z >> W;
        vector<vector<int> > graph(N+1, vector<int>(M+1));
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= M; ++j) {
                cin >> graph[i][j];
            }
        }
        cout << max(check(graph, Z, W), check(graph, X, Y)) << endl;

    }

    int check(vector<vector<int> > &graph, int x, int y) {
        int result = INT_MAX;
        for(int i = 1; i <= 8; ++i) {
            int nextX = x + di[i][0];
            int nextY = y + di[i][1];
            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) {
                continue;
            }
            if(graph[nextX][nextY] < graph[x][y])
                return graph[x][y];
            result = min(result, graph[nextX][nextY]);
        }
        return result;
    }

    void dfs(vector<vector<int> > graph, int x, int y) {
        if(x == Z && y == W) {
            flag = true;
            return ;
        }
        graph[x][y] = 1;
        for(int directionIndex = 0; directionIndex < 4; ++directionIndex) {
            int nextRow = x + directions[directionIndex][0];
            int nextColumn = y + directions[directionIndex][1];
            if(flag || nextRow < 0 || nextRow >= graph.size() || nextColumn < 0 || nextColumn >= graph[0].size() || graph[nextRow][nextColumn] != 0)
                continue;
            dfs(graph, nextRow, nextColumn);
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

