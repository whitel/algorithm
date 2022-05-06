#include<bits/stdc++.h>
using namespace std;
#define MAXN 100

vector<bool> isPrime(MAXN, true);

void init() {
    for(int i = 2; i <= sqrt(MAXN); ++i) {
        if(isPrime[i]) {
            for(int j = i * i; j <= MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void printPrimes() {
    for(int i = 2; i <= MAXN; ++i) {
        if(isPrime[i])
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    init();
    printPrimes();
}
