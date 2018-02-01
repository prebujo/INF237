#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *a; bool *b;
    a = (int*) malloc((size_t) n*sizeof(int));
    b = (bool*) malloc((size_t) n*sizeof(bool));

    int max = a[0]; //max value found so far
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= max) {
            //if this is the largest value so far, it is a candidate for pivot
            b[i] = true;
            max = a[i];
        } else b[i] = false; //necessary?
    }
    int min = a[n-1];
    int count = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] <= min) {
            min = a[i];
            if (b[i]) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}