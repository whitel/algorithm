#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
private:
    int directions[4][2] = {
        {0, 1},
        {-1, 0},
        {0, -1},
        {1, 0} 
    };
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix int整型vector<vector<>> 
     * @return int整型vector
     */
    vector<int> antiSpiralOrder(vector<vector<int> >& matrix) {
        // write code here
        vector<int> result;
        int n = matrix.size();
        if(n == 0)  return result;
        int m = matrix[0].size();

        int x = n - 1;
        int y = 0;
        int directionIndex = 0;
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        for(int i = 0; i < n * m; ++i) {
            result.push_back(matrix[x][y]);
            visited[x][y] = true;
            int nextX = x + directions[directionIndex][0];
            int nextY = y + directions[directionIndex][1];
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || visited[nextX][nextY])
                directionIndex = (directionIndex + 1) % 4;
            x += directions[directionIndex][0];
            y += directions[directionIndex][1];
        }
        return result;
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
    int n, m;
    cin >> n >> m;
    vector<vector<int> > mat(n, vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }

    Solution s;
    vector<int> go = s.antiSpiralOrder(mat);
    for(int i = 0; i < go.size(); ++i) {
        cout << go[i] << " ";
    }
    cout << endl;

#ifdef DEBUG
    cout << "============END==============" << endl;
#endif
    return 0;
}

