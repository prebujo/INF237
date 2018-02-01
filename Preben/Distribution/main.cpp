#include <iostream>
#include <algorithm>

void assignBox(long n, long i);

using namespace std;

int main() {
    long n;
    long b;

    while(true){
        cin >> n;
        cin >> b;
        if(n==-1 && b == -1)
            break;
        assignBox(n,b);
    }
    return 0;
}

void assignBox(long n, long i) {

    double tot = 0;
    long input[n];
    double maxim = 0;
    for (int j = 0; j < n ; ++j) {
        cin >> input[j];
        tot += input[j];
        if (input[j]>maxim)
            maxim = input[j];
    }
    sort(input, input + n);

    long maxperbox = 0;
    long perbox = tot/i;
    for (int k = 0; k < n; ++k) {
        if(perbox>input[k]) {
            i -= 1;
            tot -= input[k];
            perbox = tot/i;
        } else {
            double andelBokser;
            andelBokser = i*input[k]/tot;
            long antallBokser = round(andelBokser);
            maxperbox = max(maxperbox, input[k]/antallBokser);
        }
    }
    cout << maxperbox << endl;
}