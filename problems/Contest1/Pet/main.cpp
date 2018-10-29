#include <iostream>
using namespace std;

int main() {
    int N = 5;
    int C = 4;
    int winner = 6;
    int maxpoints = 0;

    for (int i = 0; i < N; ++i) {
        int points = 0;
        for (int j = 0; j < C; ++j) {
            int pointC;
            cin >> pointC;
            points += pointC;
        }
        if(points >= maxpoints){
            maxpoints = points;
            winner = i+1;
        }
    }
    if (winner < 6)
        cout << winner << " " << maxpoints;
}