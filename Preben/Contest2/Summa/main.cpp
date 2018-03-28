#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long sumA = 0;
    long sumB = 0;

    long A[n];
    long B[n];

    for (int i = 0; i < n ; ++i) {
        cin >>A[i];
        sumA += A[i];
    }

    for (int j = 0; j < n; ++j) {
        cin >> B[j];
        sumB += B[j];
    }

    long diff = sumA - sumB;

    double closestDiff = 99999;
    int idxA, idxB;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if(abs(abs(A[k] - B[i]) - abs((diff+1)/2)) < closestDiff) {
                closestDiff = abs(abs(A[k] - B[i]) - abs((diff+1) / 2));
            }
        }
    }
    cout << (int) (2*closestDiff) << endl;

}