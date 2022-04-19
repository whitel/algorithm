#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        int n, m;
        cin >> n >> m;
        vector<vector<char> > mat(n, vector<char>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> mat[i][j];
            }
        }
        
        time_t timer;
        time(&timer);
        srand((int)timer);
        int result = rand() % 3;
        if(result == 0) {
            cout << "kou" << endl;
        } else if(result == 1) {
            cout << "yukari" << endl;
        }else
            cout << "to be continued" << endl;
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

