#include <iostream>
using namespace std;

struct node{
    int w; //weight
};

int main() {
    int N;
    cin >> N;
    long w[N];

    int g[N][N];

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            g[k][i] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        int U;
        cin >> w[i];
        cin >> U;
        for (int j = 0; j < U; ++j) {
            int inp;
            cin >> g[i][inp] = 1;
        }
    }

}