#include <iostream>
#include <algorithm>

using namespace std;

long r[50][50];




void make_mat(int n);

long dp_max(int t, int n);
long dp_min(int t, int n);

int main() {
    int n;
    cin >> n; //taking input for size of matrix
    while (n != 0){ //if inut is 0 stop
        make_mat(n); //running method to make a matrix for each game
        cin >> n;
    }
    return 0;
}

void make_mat(int n) {
    int t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n ; ++j) { //taking matrix input
            cin >> r[i][j];
        }
    }
    cin >> t;  //taking amount of rounds input

    long maxi = dp_max(t, n);  //applying dynamic programming to find max
    cout << maxi<< " ";

    long mini = dp_min(t, n);  //applying dynamic programming to find min
    cout << mini << endl;
}

long dp_max(int t, int n) {
    long dp_max[t][n];
    long value;
    long maximum;
    for (int i = 0; i < n; ++i) { //base case t = 1 (0)
        maximum = 0;
        for (int j = 0; j < n; ++j) {
            value = r[i][j];
            if (value > maximum)
                maximum = value;
        }
        dp_max[0][i] = maximum; //in the last turn the best solution is to take the maximum value in that room
    }
    for (int tt = 1; tt < t; ++tt) { //runtime is t*n^2
        // recurrance case: for each turn left tt take the max value possible from that room
        for (int i = 0; i < n; ++i) {
            maximum = 0;
            for (int j = 0; j < n; ++j) {
                value = r[i][j] + dp_max[tt - 1][j]; // formula dp[t][i] = max(v(j) + dp[t-1][j])
                if (value > maximum)            //taking the best solution of 3 options
                    maximum = value;        //using memoizing to remember the max value from t-1
            }
            dp_max[tt][i] = maximum; //inserting max value
        }
    }
    return dp_max[t-1][0]; //returning max possible value from room 1 with t turns left
}

long dp_min(int t, int n) {
    long dp_min[t + 1][n];
    long value;
    long minimum;
    for (int i = 0; i < n; ++i) { //base case t = 1
        minimum = 9200000000000000000;
        for (int j = 0; j < n; ++j) {
            value = r[i][j];
            if (value < minimum)
                minimum = value;
        }
        dp_min[0][i] = minimum;
    }
    for (int tt = 1; tt < t; ++tt) {    //runtime is t*n^2
        // recurrance case: for each turn left tt take the min value possible from that room
        for (int i = 0; i < n; ++i) {
            minimum = 9200000000000000000;
            for (int j = 0; j < n; ++j) {
                value = r[i][j] + dp_min[tt - 1][j]; // formula dp[t][i] = min(v(j) + dp[t-1][j]
                if (value < minimum)
                    minimum = value;
            }
            dp_min[tt][i] = minimum; //inserting min value
        }
    }
    return dp_min[t-1][0]; //returning min possible value from room 1 with t turns left
}