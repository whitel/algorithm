#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
private:
    vector<bool> visited;
    int n, e;
public:
    void run() {
        // n个结点，e条边
        cin >> n >> e;
        vector<vector<int> > graph(n, vector<int>(n));
        visited.resize(n);
        for(int i = 0; i < n; i++)
            visited[i] = false;
        for(int i = 0; i < e; ++i) {
            int from, to;
            cin >> from >> to;
            graph[from][to] = 1;
            graph[to][from] = 1;
        }
        printGraph(graph);
        bfs(graph);
    }

    void bfs(vector<vector<int> > graph) {
        queue<int> Q;
        Q.push(0);
        visited[0] = true;
        cout << "visit : " << 0 << endl;
        while(!Q.empty()) {
            int top = Q.front();
            Q.pop();
            for(int i = 0; i < n; i++) {
                if(graph[top][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    cout << "visit : " << i << endl;
                    Q.push(i);
                }
                    
            }
        }
    }

    void printGraph(vector<vector<int> > graph) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
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

