#include <iostream>
#include <cmath>

using namespace std;


int main() {
    int T;
    cin >> T;
    long N = 1000000007; //module number

    while(T>0){
        long d;//decimal number
        cin >> d;
        long ans = 8;
        for (int i = 1; i < d; ++i) {
            ans *=9;
            if (ans>=N) //have to take module if number is too big
                ans = ans%N;
        }

        cout << ans << endl;

        T--;
    }

}