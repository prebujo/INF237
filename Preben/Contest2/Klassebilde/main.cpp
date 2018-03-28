#include <iostream>
using namespace std;



int main() {
    int n, k;
    cin >> n;
    cin >> k;
    long dp[n+1][n+1];
    for (int i1 = 0; i1 < n+1 ; ++i1) {
        for (int i = 0; i < n+1 ; ++i) {
            dp[i1][i] = 0;
        }

    }

    int oppst[n];
    for (int i = 0; i < k ; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> oppst[j];
        }
        for (int l = 0; l < n; ++l) {
            for (int j = 0; j < n; ++j) {
                dp[oppst[l]][oppst[j]] += abs(j - l);
                dp[oppst[j]][oppst[l]] += abs(j - l);
            }
        }
    }

    int maxX, maxY;
    int maxV = 0;

    for (int m = 1; m < n+1 ; ++m) {
        for (int i = m+1; i < n+1 ; ++i) {
            if(dp[m][i] > maxV){
                maxX = m;
                maxY = i;
                maxV = dp[m][i];
            }
        }
    }
    cout << maxX << " ";
    cout << maxY << " ";

}