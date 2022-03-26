#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void run(vector<int> &A, vector<int> &B) {
        // core code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        long long ans = 0;
        for(long long i = 0; i < A.size(); i++) {
            long long temp = A[i] - B[i];
            temp = temp * temp;
            ans += temp;
        }
        cout << ans << endl;
    }

};

int main() {
    Solution s;
    // input here
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < n; i++)
        cin >> B[i];

    s.run(A, B);
    return 0;
}
