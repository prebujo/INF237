#include <iostream>

void dfs(int x, int y);

using namespace std;

    int W;
    int H;
    int gold = 0;
    char map[50][50];

int main() {
    cin >> W;
    cin >> H;
    int x, y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> map[j][i];
            if (map[j][i] == 'P') {
                y = i;
                x = j;
            }
        }
    }
    dfs(x, y);
    cout << gold;
    return 0;
}

void dfs(int x, int y) {
    //check if we are at a wall:
    if (x <= 0 || y <= 0) return;
    if (x >= W || y >= H) return;
    if (map[x][y] == '#') return;

    if (map[x][y] == 'G') gold++;
    map[x][y] = '#'; //mark this node as visited

    //check if there is danger:
    if (map[x + 1][y] == 'T'
        || map[x - 1][y] == 'T'
        || map[x][y + 1] == 'T'
        || map[x][y - 1] == 'T') return; // we can go no further!

    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}