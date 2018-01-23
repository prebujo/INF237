//
// Created by preben on 22.01.18.
//

#include "Bard.h"
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n;
    int e;
    cin >> n;
    cin >> e;
    bitset<50> villegers[n+1];

    for (int j = 0; j < e; ++j) {
        int a;
        cin >> a;
        bool bard = false;//settes til true hvis bard'en er tilstede
        int tilstede[a+1];
        for (int i = 1; i <= a; ++i) { //første for loop sjekker om bard'en er tilstede og lagrer personene i en array
            int person;
            cin >> person;
            tilstede[i] = person;
            if (person == 1) {
                bard = true;
            }
        }

        if (bard) {
            for (int k = 1; k <= a; ++k)
                villegers[tilstede[k]].set(j, true);
        }
        else {
            for (int i = 2; i <= a; ++i) {
                villegers[tilstede[1]] = villegers[tilstede[1]]|=villegers[tilstede[i]];
            }
            for (int l = 2; l <= a; ++l) {
                villegers[tilstede[l]] = villegers[tilstede[l]]|=villegers[tilstede[1]];
            }
        }
    }
    int bardsongs = villegers[1].count();

    for (int m = 1; m <= n; ++m) {
        if (villegers[m].count() == bardsongs)
            cout << endl << m;
    }
    return 0;
}
