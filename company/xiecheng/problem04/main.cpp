#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class square {
public:
    int x1, y1;
    int x2, y2;
};

class Solution {
public:
    void run() {
        int n, m, q;
        cin >> n >> m >> q;
        vector<string> matrix(n);
        for(int i = 0; i < n; ++i) {
            cin >> matrix[i];
        }
        int x1, y1, x2, y2;
        vector<square> all(q);
        for(int times = 0; times < q; ++times) {
            cin >> x1 >> y1 >> x2 >> y2;
            all[times].x1 = x1;
            all[times].x2 = x2;
            all[times].y1 = y1;
            all[times].y2 = y2;
        }

        vector<vector<bool> > reversable(n, vector<bool>(m, false));
        for(int times = 0; times < q; ++times) {
            for(int i = all[times].x1-1; i <= all[times].x2-1; ++i) {
                for(int j = all[times].y1-1; j <= all[times].y2-1; ++j) {
                    reversable[i][j] = !reversable[i][j];
                }
            }
        }
        // printReversable(reversable);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(reversable[i][j]) {
                    cout << converse(matrix[i][j]);
                } else {
                    cout << matrix[i][j];
                }
            }
            cout << endl;
        }
    }

    char converse(char c) {
        if(c >= 'a') {
            c = c - 'a' + 'A';
            return c;
        }
        c = c - 'A' + 'a';
        return c;
    }

    void printReversable(vector<vector<bool> > reversable) {
        for(int i = 0; i < reversable.size(); ++i) {
            for(int j = 0; j < reversable[0].size(); ++j) {
                if(reversable[i][j])
                    cout << 1 << " ";
                else
                    cout << 0 << " "; 
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

