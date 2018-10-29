#include <iostream>
using namespace std;

//Oppdaterer verdien i et tre
void update(int i, int v,int sT[]){//O(logn) kjøretid
    int pos = i; //position
    int diff = v - sT[pos]; //verdi som skal endres for alle verdier over i treet
    do {//endrer verdiene helt til jeg når toppen av treet.
        sT[pos]+=diff;
        pos /= 2;
    } while (pos > 0);
}

//metode som summerer tall i et intervall i et Tre
int sum(int i, int j, int sT[]){ //O(logn) kjøretid
    int L = i; //venstre grense
    int R = j; //høyre grense for intervall
    int ans = 0; //sum mellom grenser

    while(true) {
        bool lRight = (L%2) == 0; //sjekker om jeg kommer fra høyre
        bool rLeft = (R%2) == 1; //eller venstre
        L/=2; //vandrer opp treet fra venstre
        R/=2; //vandrer opp treet fra høyre
        if (L >= R) break; //stopper hvis L og R blir lik
        if(lRight) ans +=sT[2*L+1]; //summerer alle verdier ned til høyre for venstre grense
        if(rLeft) ans +=sT[2*R]; //summerer alle verdier ned til venstre for høyre grense
    }
    //returnerer summen mellom de to grensene
    return ans;
}

int main() {
    int n;
    cin >> n;
    int a[n + 2];
    for (int i = 1; i < n + 1; ++i) {
        int inp;
        cin >> inp;
        a[inp] = i; //using the input as index and index as value
    }

    //initialising N and offset for sum Array
    int N = 2;
    int offs = 2;

    //finding N and offset for sum array
    while (2 * n + 3 > N)
        N *= 2;
    while (n + 2 > offs)
        offs *= 2;

    //arrays that keep track of which numbers have been moved and not
    int swaps[n+1];
    int swapsT[N + 1];


    //initializing swaps Tree to 0
    for (int j = 1; j < N + 1; ++j) {
        swapsT[j] = 0;
    }

    //updating swaps Tree accoring to initial swaps
    for (int k = 1; k < n + 1; ++k) {
        update(k+offs, 1, swapsT);
    }

    //value to indicate
    int lower = 1;
    int higher = n;
    int phase = 1;

    //gjennomgår hver phase
    for (int m = 1; m <= n; ++m) { //kjøretid O(nLogn)
        bool minPhase = m % 2 == 1; //bestemmer om det er minphase eller maxphase
        if (minPhase) {
            //Min phase skal jeg ta hittil minste verdi og flytte dette forbi alle andre
            //tall til venstre som ikke allerede er flyttet.
            int pos = a[lower]; //henter ut indexen til tallet jeg skal swappe
            cout << sum(offs, pos+offs, swapsT)<<endl; //O(logn) finner antall swaps (intervall til venstre for der tallet står)
            update(pos+offs,0,swapsT); //O(logn) oppdaterer tabellen med 0 slik at andre tall ikke kan swappe denne
            lower++; //øker minste tall til neste minPhase
        } else {
            //Max Phase skal jeg ta hittil største verdi og flytte dette forbi alle tall til høyre
            //som ikke allerede er flyttet.
            int pos = a[higher]; //finner index til max verdi
            cout << sum(pos+offs, n+offs+1, swapsT)<<endl; //O(logn) summerer alle swaps til høyre for index
            update(pos+offs,0,swapsT); //O(logn) Oppdaterer verdien til "flyttet" altså 0
            higher--; //minsker høyeste verdi til neste maxphase.
        }
    }
}