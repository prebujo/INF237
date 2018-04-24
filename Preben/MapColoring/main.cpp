
// Created by preben on 17.04.18.
//
#include <iostream>
#include <sstream>

using namespace std;

int C;

int colors(int C, int B);

//laget en backtracking algoritme for å sjekke om et gitt antall farger er mulig
int dfsCol(bool (*G)[16][16], int col[], int n, int v){
    //base case, if all vertices have a color then I will return 1.
    if(v >= C)
        return 1;
    //checking each possible color
    for (int i = 1; i <n+1 ; ++i) {
        //checking if this color is valid
        bool valid = 1;
        for (int j = 0; j < C; ++j) { //checking all adjecent vertexes
            if ((*G)[v][j] == 1 && i == col[j])
                valid = 0;
        }
        //if the color is valid I assign the color and check next vertex
        if (valid){
            col[v] = i;
            if(dfsCol(G, col, n, v + 1))
                return 1;//returning result from "dfs" graph colors
        }
        //if color doesnt work changing color back to 0
        col[v] = 0;
    }
    return 0;
}

int main() {
    int T;
    cin >> T;

    for (int m = 0; m < T; ++m) {
        int B;
        cin >> C;
        cin >> B;
        int result = colors(C, B);
        if (result > 0)
            cout << result << endl;
        else
            cout << "many" << endl;
    }
}

int colors(int C, int B){

    //generating empty graph array
    bool G[16][16];

    for (int j = 0; j < C; ++j) {
        for (int i = 0; i < C; ++i) {
            G[j][i] = 0;
        }
    }

    for (int m = 0; m < B; ++m) {
        int from, to;
        cin >> from;
        cin >> to;
        G[from][to] = 1;
        G[to][from] = 1;
    }

    //initialising empty color table
    int col[C];
    for (int i = 0; i < C; ++i) {
        col[i] = 0;
    }

    col[0]=1;

    //starting with checking if one color is possible until i find minimum possible colors
    for (int k = 1; k <= 4; ++k) { //O(n^n)
        bool working = true;
        if(dfsCol(&G, col, k, 1) == 1){ //running recursive graphCol backtracking algorithm
            return k;
        }
    }
    return -1;
};