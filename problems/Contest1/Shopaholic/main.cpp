#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortinrev(const int &a,
               const int &b)
{
    return (b < a);
}

int main() {
    int N;
    cin >> N;
    vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end(), sortinrev);
    long discount = 0;
    for (int j = 1; j < N+1; ++j) {
        if(j%3 == 0)
            discount += prices[j-1];
    }
    cout << discount;

}