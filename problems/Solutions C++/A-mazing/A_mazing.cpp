//
// Created by preben on 24.01.18.
//

#include <array>
#include "iostream"
using namespace std;

string direction[4] = {"up", "right", "down", "left"};
int opposite[4] = {2, 3, 0, 1};

void dfs(int lastmove){
    cout << direction[lastmove] << endl;
    bool posMoves[4] = {true,true,true,true};
    posMoves[opposite[lastmove]];
    string answ;
    cin >> answ;
    if (answ == "solved")
        exit(0);
    if (answ == "wall")
        return;
    for (int i = lastmove+1; i < 4 ; ++i) {
        if (posMoves[i]) {
            cout << direction[i];
            posMoves[i] = false;
            dfs(i);
        }
    }
    cout << direction[lastmove] << endl;
    cin >> answ;
    return;
}

int main() {
    //bool moves[4] = {true,true,true,true}; //up == 0, right == 1, down == 2, left == 3
    for (int i = 0; i < 4 ; ++i) {
        dfs(i);
    }
    cout << "no way out";
    exit(0);
};