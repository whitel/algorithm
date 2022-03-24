#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
public:
    void run() {
        int n, m, p;
        cin >> n >> m >> p;
        vector<vector<int> > A(n+1, vector<int>(m+1));
        vector<vector<int> > B(m+1, vector<int>(p+1));
        vector<vector<int> > C(n+1, vector<int>(p+1));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cin >> A[i][j];
            }
        }
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= p; ++j) {
                cin >> B[i][j];
            }
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= p; ++j) {
                for(int k = 1; k <= m; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        printMatrix(C);
    }

    void printMatrix(vector<vector<int> > mat) {
        for(int i = 1; i < mat.size(); ++i) {
            for(int j = 1; j < mat[0].size(); ++j) {
                cout << mat[i][j] << " ";
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

