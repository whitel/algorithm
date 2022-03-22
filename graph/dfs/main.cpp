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
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(graph, i);
            }
        }
    }

    void dfs(vector<vector<int> > graph, int v) {
        visited[v] = true;
        cout << "visit : " << v << endl;
        for(int i = 0; i < n; ++i) {
            if(graph[v][i] == 1 && !visited[i])
                dfs(graph, i);
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

