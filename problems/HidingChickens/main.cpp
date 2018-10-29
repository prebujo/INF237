#include <iostream>
#include <vector>

using namespace std;

struct pos{
    double x;
    double y;
};

int main() {
    pos fox;
    cin >> fox.x;
    cin >> fox.y;

    int N;
    cin >> N;

    vector<pos> hSpot;
    hSpot.reserve(N);
    for (int i = 0; i < N ; ++i) {
        pos p;
        cin >> p.x;
        cin >> p.y;
        hSpot.push_back(p);
    }


}