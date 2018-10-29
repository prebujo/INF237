#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    long sum = 0;
    for (int i = 0; i < T; ++i) {
        int num;
        cin >> num;
        sum = (long) pow(2, num);
    }

}