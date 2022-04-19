#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

class Solution {
public:
    void run() {
        int n;
        cin >> n;
        vector<vector<char> > mat(4 * n, vector<char>(4 * n, '.'));
        // for(int i = 0; i < 2 * n; ++i) {
        // }
        for(int i = 0; i < n; ++i) {
            fillWithStar(mat, i, n - i, 2 * n);
        }
        for(int i = n; i < 2 * n; ++i) {
            fillWithStar(mat, i, 0, n);
        }
        copyLeft(mat);
        copyDown(mat);
        printMat(mat);
    }

    void copyLeft(vector<vector<char> > &mat) {
        int n = mat.size();
        for(int i = 0; i < n; ++i) {
            for(int j = n / 2; j < n; ++j) {
                mat[i][j] = mat[i][n - j - 1];
            }
        }
    }

    void copyDown(vector<vector<char> > &mat) {
        int n = mat.size();
        for(int i = n / 2; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                mat[i][j] = mat[n - i - 1][j];
            }
        }
    }

    void fillWithStar(vector<vector<char> > &mat, int line, int begin, int end) {
        for(int i = begin; i < end; ++i) {
            mat[line][i] = '*';
        }
    }

    void printMat(vector<vector<char> > &mat) {
        for(int i = 0; i < mat.size(); ++i) {
            for(int j = 0; j < mat[i].size(); ++j) {
                cout << mat[i][j];
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

