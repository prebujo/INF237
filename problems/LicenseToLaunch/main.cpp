#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    int junk;
    int minjunk = 1000000000;
    int launch = 0;
    for (int i = 0; i < n; ++i) {

        cin >> junk;
        if (junk < minjunk) {
            launch = i;
            minjunk = junk;
        }
    }


    cout << launch << endl;
    return 0;
}