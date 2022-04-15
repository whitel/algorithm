#include<bits/stdc++.h>
using namespace std;

#define DEBUG

class Solution {
private:
    bool comp(string A, string B) {
        if(A.size() != B.size())
            return false;
        for(int i = 0; i < A.size(); ++i) {
            if(A[i] >= 'a' && A[i] <= 'z') {
                A[i] = A[i] - 'a' + 'A';
            }
            if(B[i] >= 'a' && B[i] <= 'z') {
                B[i] = B[i] - 'a' + 'A';
            }
        }
        return A == B;
    }
public:
    void run() {
        string prev_word;
        string curr_word;
        string result;
        while(cin >> curr_word) {
            if(comp(prev_word, curr_word)) {
                // 
            } else {
                result += curr_word;
                result += " ";
                prev_word = curr_word;
            }
        }
        result.erase(result.size() - 1, result.size());
        cout << result << endl;
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

