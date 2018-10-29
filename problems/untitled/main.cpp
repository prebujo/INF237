#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct point {
    double x;
    double y;
};

struct item {
    int v;
    double w;
};

bool operator<(const item &a, const item &b) { return a.w > b.w; }

double w(point a, point b) { return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2)); }

double solve(int n) {
    double cost = 0.;
    std::vector<point> V;
    V.reserve(n);
    for (int i = 0; i < n; i++) {
        point p;
        std::cin >> p.x;
        std::cin >> p.y;
        V.push_back(p);
    }

    double d[n];
    bool visited[n];
    for (int i = 1; i < n; i++) {
        d[i] = std::numeric_limits<double>::max();
        visited[i] = false;
    }
    d[0] = 0;

    std::vector<item> q;
    q.push_back(item{0, 0});
    while (!q.empty()) {
        std::sort(q.begin(),q.end());
        auto &it = q.back();
        q.pop_back();
        auto v = it.v;
        if(!visited[v])
            cost += it.w;
        visited[v] = true;
        for (int u = 0; u < n; u++) {
            if (!visited[u] && d[u] > w(V[v], V[u])) {
                d[u] = w(V[v], V[u]);
                q.push_back(item{u, d[u]});
            }

        }
    }
    return cost;
}
int main(int ac, char *av[]) {

    int c;
    std::cin >> c;

    while (c != 0) {
        int n;
        std::cin >> n;
        std::cout <<  solve(n) << std::endl;
        c--;
    }
    return 0;
}