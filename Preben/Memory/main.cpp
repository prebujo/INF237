#include <iostream>
#include <algorithm>

using namespace std;

double memory(int n);


int main() {
    int n;
    cin >> n;
    printf("%10.12f", memory(n));
    return 0;
}

double memory(int n) {
    double dp_mem[n+1][2*n+1];
    for (int k = 0; k <n+1 ; ++k) {
        for (int i = 0; i <2*n+1 ; ++i) {
            dp_mem[k][i]= 0;
        }
    }
    for (int i = 0; i <= 2*1; ++i) { //base case for n pairs og m kjente kort
        dp_mem[1][i] = 1;
    }

    for (int j = 2; j <= n; ++j) {
        // recurrance case: gjennomgår for alle kombinasjoner av n og m kjente kort forventet antall trekk.
        // kan dele opp forventet verdi i 4 forskjellige tilfeller av utfall for trekk:
        // Tilfelle 1: man trekker et ukjent kort, og trekker så et kort som matcher dette ukjente kortet.
        // Tilfelle 2: man trekker et ukjent kort og deretter et kjent kort, fører til at man bruker et ekstra trekk på å bli kvitt det kjente paret
        // Tilfelle 3: man trekker et ukjent kort og deretter enda et ukjent kort. antall match går opp men antall par blir det samme
        // Tilfelle 4: man trekker et kjent kort og matcher da dette med det andre kjente kortet. kjente kort går ned med 1 og par går ned med 1
        for (int i = j; i >= 0; --i) {
            double m = (double)i;
            double p = (double)j;

            double uknwn_match_prob = ((2*p-2*m)/(2*p-m))*(1/(2*p-1-m));    //forventet antall trekk ved tilfelle 1
            double uknwn_match_case = (dp_mem[j-1][i] + 1);
            double uknwn_match = uknwn_match_prob*uknwn_match_case;

            double uknwn_known_prob = ((2*p-2*m)/(2*p-m))*(m/(2*p-1-m));  //forventet antall trekk ved tilfelle 2
            double uknwn_known_case = (dp_mem[j-1][i] + 1 + 1);
            double uknwn_known = uknwn_known_prob*uknwn_known_case;

            double uknwn_uknwn_prob = ((2*p-2*m)/(2*p-m))*((2*p-2-2*m)/(2*p-1-m));  //forventet antall trekk ved tilfelle 3
            double uknwn_uknwn_case = (dp_mem[j][i+2] + 1);
            double uknwn_uknwn = uknwn_uknwn_prob*uknwn_uknwn_case;

            double known_match_prob = (m/(2*p-m));                        //forventet antall trekk ved tilfelle 4
            double known_match_case = (dp_mem[j-1][i-1] + 1);
            double known_match = known_match_prob*known_match_case;

            dp_mem[j][i] = uknwn_match + uknwn_known + uknwn_uknwn + known_match; //setter forventet verdi av dette tilfellet i tabellen
        }
    }
    return dp_mem[n][0]; //returnerer forventet verdi ved n antall pairs og 0 kjente kort.
}