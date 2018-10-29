#include <iostream>
using namespace std;

long r[1000][1000];

int main() {
    int N,S,T;
    cin >> N;
    cin >> S;
    cin >> T;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> r[i][j];
        }
    }

    long dp[1000][1000];

    //base case
    for (int k = 0; k < N; ++k) {
        long val = r[S][k];
        dp[0][k] = val;
    }

    long value = 0;

    for (int l = 1; l < N; ++l) {
        long value = 0;
        for (int i = 0; i < N; ++i) {
            long min = 9200000000000000000;
            for (int j = 0; j < N; ++j) {
                value = dp[l - 1][j] + r[j][i];
                if (value < min)
                    min = value;
            }
            dp[l][i] = min;
        }
    }
    cout << dp[N-1][T];
}