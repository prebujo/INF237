#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

//koordinater for et punkt
struct point {
    double x;
    double y;
};

//en node eller item
struct item {
    int v;
    double w;
};

//gjør om rekkefølgen på pq til MinPQ
bool operator<(const item &a, const item &b) { return a.w > b.w; }

//pytagoras formel som regner ut avstanden fra et punkt til et annet
double w(point a, point b) { return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2)); }

//metode som returnerer kostnaden av MST
double solve(int n) {
    double cost = 0.;

    //Vector med punkter
    std::vector<point> V;
    V.reserve(n);

    //tar input av punkter
    for (int i = 0; i < n; i++) {
        point p;
        std::cin >> p.x;
        std::cin >> p.y;
        V.push_back(p);
    }

    //initialiserer tabell for kostnad og visited
    double d[n];
    bool visited[n];
    for (int i = 1; i < n; i++) {
        d[i] = std::numeric_limits<double>::max();
        visited[i] = false;
    }

    //begynner med den første noden 0
    d[0] = 0;

    //oppretter pq
    std::priority_queue<item> q;

    //pusher første element
    q.push(item{0, 0});

    //mens pq ikke er tom
    while (!q.empty()) {
        //popper minste element
        auto it = q.top();
        q.pop();
        auto v = it.v;
        //hvis den ikke er besøkt øker jeg kostnaden
        if(!visited[v])
            cost += it.w;
        visited[v] = true; //markerer som besøkt
        //og gjennomgår alle andre noder siden alle kan være connected
        for (int u = 0; u < n; u++) {
            if (!visited[u] && d[u] > w(V[v], V[u])) { //hvis noden ikke er besøkt og avstanden er mindre enn
                d[u] = w(V[v], V[u]);                  // den vi har oppdaterer jeg den
                q.push(item{u, d[u]});              //og pusher den nye noden på queuen.
            }
        }
    }
    return cost; //returnerer kostnaden  for utskrift.
}
int main(int ac, char *av[]) {

    int c;
    std::cin >> c;

    while (c != 0) {
        int n;
        std::cin >> n;
        std::printf("%10.6f\n",  solve(n));
        c--;
    }
    return 0;
}