//
// Created by preben on 24.01.18.
//

#include <array>
#include "iostream"
using namespace std;

//lager feltvariabler av retning, og motsatt retning, og oppretter markert listen
string direction[4] = {"up", "right", "down", "left"};
int opposite[4] = {2, 3, 0, 1};
bool marked[202][202]; //vet ikke hvor jeg begynner i labyrinten dermed dobbelt så stor som mulig 100x100

//funksjon som kalles rekursivt lignende dfs
void dfs(int lastmove, int posx, int posy){
    //sjekker først om retningen jeg ønsker å bevege meg er markert (oppdaterer dermed først retningen)
    if (lastmove == 0)
        posy += 1;
    else if (lastmove == 1)
        posx += 1;
    else if (lastmove == 2)
        posy -= 1;
    else
        posx -= 1;
    if (marked[posx][posy])
        return;
    else
        marked[posx][posy] = true;

    //hvis ikke markert skal jeg "bevege meg" dit og dermed skrive ut 
    cout << direction[lastmove] << endl;
    cout << flush;

    //tar imot input og sjekker og utfører passende respons
    string answ;
    cin >> answ;
    if (answ == "solved")
        exit(0);
    if (answ == "wrong")
        exit(0);
    if (answ == "wall") {
        marked[posx][posy] = false;
        return;
    }

    //oppretter en retning tabell slik at jeg ikke beveger meg i samme retning to ganger
    bool posMoves[4] = {true,true,true,true};
    //markerer der jeg kom ifra
    posMoves[opposite[lastmove]] = false;
    //for hver mulige retning skal jeg gjøre et rekursivt kall
    for (int i = 0; i < 4 ; ++i) {
        if (posMoves[i]) {
            posMoves[i] = false;
            dfs(i, posx, posy);
        }
    }
    //når jeg har gått alle retninger og siden det ikke finnes flere riktige retninger å gå så skal jeg gå tilbake og returnere.
    cout << direction[opposite[lastmove]] << endl;
    cout << flush;
    cin >> answ;
    return;
}

int main() {
    //up == 0, right == 1, down == 2, left == 3
    //begynner meg å gå i alle mulige retninger fra startpunkt og sender med koordinater for startpunkt i marked.
    for (int i = 0; i < 4 ; ++i) {
        marked[101][101] = true;
        dfs(i, 101,101);
    }
    cout << "no way out";
    exit(0);
}
