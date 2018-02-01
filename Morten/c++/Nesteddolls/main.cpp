#include <iostream>
#include <algorithm>

using namespace std;

void solve(vector<pair<int, int>> *dolls, int N);
bool compare(pair<int, int> p1, pair<int, int> p2);

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        int N;
        cin >> N;
        size_t n = (size_t) N;
        vector<pair<int, int>> *dolls = new vector<pair<int,int>>();
        for (int j = 0; j < N; ++j) {
            int x, y;
            cin >> x; cin >> y;
            dolls->push_back(make_pair(x,y));
        }
        solve(dolls, N);
    }
    return 0;
}

void solve(vector<pair<int, int>> *dolls, int N) {
    sort(*dolls->begin(), *dolls->end(), compare);
    for (int i = 0; i < N; ++i) {
        int first = dolls->at(i).first;
        cout << first;
    }
}
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.first < p2.first )return 0;
    return 1;
}