#include <iostream>
#include <bitset>

using namespace std;
int main() {
    //initialising and taking input for n and k
    long n,k;
    cin >> n;
    cin >> k;

    //initialising N and offset for sum Array
    long N = 2;
    long offs = 2;

    //finding N sudoand offset for sum array
    while(2*n + 3 > N)
        N *=2;
    while(n + 2 >offs)
        offs *= 2;

    //bit array
    long a[n+1];

    //initialising bit array
    for (int j = 1; j < n+1; ++j)
        a[j] = 0;

    //array with the sum of bits
    long A[N+1];
    //initialising array to 0
    for (int i = 1; i < N+1 ; ++i)
        A[i] = 0;

    //looping through opertations
    for (int l = 0; l < k; ++l) {
        string op;
        cin >> op;
        if(op == "F"){
            //if F, updating the value in position pos;
            int pos;
            cin >> pos;
            long diff; //difference is either 1 or -1
            if(a[pos]) { //updating the bit array to opposite of 1 and diff
                diff = -1;
                a[pos] = !a[pos];
            }
            else {  //updating position if 0 and diff
                diff = 1;
                a[pos] = !a[pos];
            }
            int pos2 = pos+offs; //position of sum (offset) in A
            do{
                A[pos2] += diff; //adding difference to all underlying A in the tree stucture
                pos2 /= 2; //runtime of update is O(logN)
            }while(pos2>0); //when pos2 is less than 0 stop.
        }
        else { //hvis input er noe annet enn F altså C
            //tar input for nedre og øvre intervall
            long l, r;
            cin >> l;
            cin >> r;
            //initialiserer l og r ved hjelp av offset
            l = l + offs - 1;
            r = r + offs +1;
            long ans = 0;

            //kjører while til l og r møtes
            while(true){
                //initialiserer boolske verdier
                bool lright = (l%2) ==0;
                bool rleft = (r%2) == 1;
                //dekrementerer l og r
                l/=2;   //kjøretid blir dermed O(logN)
                r/=2;
                if(l==r) break; //hvis r == l er jeg ferdig
                if(lright) ans += A[2*l +1]; //hvis ikke skal jeg legge til alt som er til høyre for l hvis l går til høyre
                if(rleft) ans += A[2*r];    // og alt til venstre for r hvis r går til venstre
            }
            //skriver output
            cout << ans << endl;
        }
    }
}