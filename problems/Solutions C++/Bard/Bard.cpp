//
// Created by preben on 22.01.18.
//

#include <iostream>
#include <bitset>

using namespace std;

int main() {
    //oppretter variabler og tar input
    int n;
    int e;
    cin >> n;
    cin >> e;
    //bruker et bitset for å holde styr på hvilke sanger hver villager kan.
    bitset<50> villagers[n+1];
    //gjennomgår hver evening og tar først input for antall personer tilstede og lagrer deretter disse i en liste
    for (int j = 0; j < e; ++j) {
        int a;
        cin >> a;
        bool bard = false;//settes til true hvis bard'en er tilstede
        int tilstede[a+1];
        for (int i = 1; i <= a; ++i) { //andre lagrer personene i en array og setter bard til true hvis han er en av de
            int person;
            cin >> person;
            tilstede[i] = person;
            if (person == 1) {
                bard = true;
            }
        }
	//hvis bard'en er tilstede skal alle lære en ny sang
        if (bard) {
            for (int k = 1; k <= a; ++k)
                villagers[tilstede[k]].set(j, true);
        }
        else { //hvis ikke skal alle utveksle sanger. bruker to for løkker hvor først den ene som er tilstede lærer alle sangene
            for (int i = 2; i <= a; ++i) {
                villagers[tilstede[1]] = villagers[tilstede[1]]|=villagers[tilstede[i]]; //bruker operator for "or" (|=) for å utgjevne bitsettet
            }	//og så lærer resten sangene av han som kan alt
            for (int l = 2; l <= a; ++l) { 
                villagers[tilstede[l]] = villagers[tilstede[l]]|=villagers[tilstede[1]];
            }
        }
    }
    //bard'en kan uansett alle sangene
    int bardsongs = villagers[1].count();
    //sjekker hvem andre som kan like mange sanger og skriver dem ut til terminalen
    for (int m = 1; m <= n; ++m) {
        if (villagers[m].count() == bardsongs)
            cout << endl << m;
    }
    return 0;
}
