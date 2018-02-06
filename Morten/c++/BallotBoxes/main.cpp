#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int N; //number of villages
int B; //number of ballot boxes

class Heap {
public:
    Heap(int N);
    void push(pair<int, double> p);
    pair<int,double> popMax();
    void printHeap();
private:
    pair<int,double>* a;
    int n = 0;
    void swim(int i);
    void sink(int i);
    void swap(int i, int j);
};

Heap::Heap(int N) {
    a = (pair<int,double>*) malloc((N+1)*sizeof(pair<int,double>));
}
void Heap::push(pair<int, double> p) {
    n++;
    a[n] = p;
    swim(n);
}
pair<int, double> Heap::popMax() {
    swap(1, n);
    n--;
    sink(1);
    return a[n+1];
}
void Heap::swim(int i) {
    int j = i/2;
    if (j < 1) return;
    if (a[j].second < a[i].second) {
        swap(i, j);
        swim(j);
    }
}
void Heap::sink(int i) {
    int j = 2*i;
    if (j > n) return;
    if (j < n && a[j].second < a[j+1].second) j++;
    if (a[i].second < a[j].second) {
        swap(i, j);
        sink(j);
    }
}
void Heap::swap(int i, int j) {
    pair<int, double> k = a[i];
    a[i] = a[j];
    a[j] = k;
}
void Heap::printHeap() {
    cout << "heap of size " << n << ":" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << i << ": " << a[i].second << "  " << a[i].first << "\r\n";
    }
    cout << "******\r\n";
}


int main() {
    while (true) {
        cin >> N;
        cin >> B;
        if (N < 0) break;
        int pop; //population in village
        Heap heap = *new Heap(N);
        for (int i = 0; i < N; ++i) {
            cin >> pop;
            heap.push(*new pair<int, double>(1, pop));
        }
        for (int j = N + 1; j <= B; ++j) {
            pair<int, double> curMax = heap.popMax();
            int boxes = curMax.first + 1;
            double ppl = curMax.second * curMax.first / (double) boxes;
            pair<int, double> newMax = *new pair<int, double>(boxes, ppl);
            heap.push(newMax);
        }
        cin;
        cout << (int) ceil(heap.popMax().second) << endl;
    }
    return 0;
}
//vector<vector<int>> a (N, vector<int>(B)); //can initialize vvi this way! :P