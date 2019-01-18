#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortbyinc(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return (a.first > b.first);
}

bool sortbyinc(const int &a,
               const int &b)
{
    return (a > b);
}

int main() {
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<int> w(n);
    int w1;
    for (int i = 0; i < n; ++i) {
        cin >> w1;
        w.push_back(w1);
    }

    sort(w.begin(),w.end());
    vector <pair<int,int>> xp(m);
    int x, p;
    for (int j = 0; j < m; ++j) {
        cin >> x;
        cin >> p;
        xp.push_back(make_pair ( p, x));
    }
    sort(xp.begin(), xp.end());

    int moine;
    for (int k = 0; k < n; ++k) {
        pair<int,int> fishmong = xp.back();
        xp.pop_back();
        int fx = fishmong.first;
        int fp = fishmong.second;
        moine += w.back() * fp;
        w.pop_back();
        if(fx > 1){
            xp.push_back(make_pair(fx-1,fp));
        }
    }

    cout << moine;
    return 0;
}