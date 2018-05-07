#include <iostream>
#include <cmath>

using namespace std;

const long double PI = 3.141592653589793238L;
const long double E =  2.718281828459045235L;

int main() {
    int n;
    while (cin >> n){
        //base case if input is less than 2:
        if(n<2)
            cout << 1 << endl;
        else {  // if input is higher use Kamenetsky’s formula to calculate the number of digits
                // runtime is always approx 2 * runtime of log10.. so if log10 has O(k) runtime
                // our runtime would be 2* O(k) = O(k)..
                // another slower (but more accurate) option would be
                // to use the sum of log(1) + log(2) + ... log(n) recursively which would have a longer
                // runtime n*(runtime of log10) which would give a more exact result for higher input data

            cout << (int)(log10(2*PI*n)/2 + n*(log10(n/E))) +1 <<endl;
        }
    }
}