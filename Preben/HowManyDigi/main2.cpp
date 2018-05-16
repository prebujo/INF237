//
// Created by preben on 14.05.18.
//
#include <iostream>
#include <cmath>

using namespace std;

double dp[1000001];

int main() {

    // to use the sum of log(1) + log(2) + ... log(n) recursively
    // runtime n*(runtime of log10)
    dp[1] = log10(1);
    for (int i = 2; i < 1000001; ++i) {
        dp[i] = dp[i-1] + log10(i);
    }

    int n;
    while (cin >> n){
        //base case if input is less than 2:
        if(n<2)
            cout << 1 << endl;
        else {
            cout << int(dp[n]+1)<<endl;
        }
    }
}