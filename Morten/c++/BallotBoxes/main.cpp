#include <iostream>
#include <algorithm>

using namespace std;

int N; //number of villages
int B; //number of ballot boxes
int *a;

void constructor(int *a) {
    a = (int*) malloc(N*sizeof(int));
    a[0] = 1;
    N= 20;
}

void push(int a) {
    //put at last index:

}

void pop(int a) {

}

int main() {
    constructor(a);
    //cout << a[0];

    //vector<vector<int>> a (N, vector<int>(B)); can initialize vvi this way! :P


    for (int i = 0; i < N; ++i) {
        int a;
        //cin >> a;
    }


    return 0;
}