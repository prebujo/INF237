#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
#include <list>

using namespace std;

int p[1000];
vector<pair<int, int>> adj[1010];


struct node {
    int v;  //node
    int d; //diesel i noden
    long w; //cost of reaching node
};

//endrer vurderingen av node slik at minste element kommer på toppen
bool operator<(const node &a, const node &b) { return a.w > b.w; }

//metode som løser hver quiry
long solve(int n) {
    int c,s,e;

    cin >> c;
    cin >> s;
    cin >> e;

    //boolsk visited tabell for hver mulige node/fuel kombinasjon
    bool visited[n][c+1];

    //initierer tabell til false
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <=c; ++j){
            visited[i][j] = false;}
    }

    //oppretter priority queue
    std::priority_queue<node> q;

    //pusher start node med 0 fuel og kostnader til queuen
    q.push(node{s, 0, 0});

    //mens køen inneholder noe
    while (!q.empty()) {
        //popper minste element
        auto it = q.top();
        q.pop();
        auto v = it.v; //node
        auto d = it.d; //fuel
        if(v == e)  //hvis jeg er kommet i mål
            return it.w;//returnerer jeg kostnaden

        if(visited[v][d]){ //hvis noden er marked fortsetter jeg
            continue;}
        visited[v][d] = true; //hvis ikke markerer jeg den


        if(it.d < c) {  // hvis jeg kan fylle mer drivstoff
            q.push(node{it.v, d+1, it.w+p[v]}); //pusher en ny node av seg selv med mer fuel
        }

        //legger til alle noder som er adj til v
        for (auto itr = adj[v].begin(); itr!=adj[v].end(); itr++) {
            int u = itr->first;
            //hvis jeg har nok fuel til å kjøre dit.
            if(itr->second <= it.d) {
                int dn = it.d - itr->second;
                q.push(node{u, dn, it.w});
            }
        }
    }
    return -1; //hvis jeg har gjennomgått alle nodene uten å komme frem til mål returnerer jeg en negativ verdi
}
int main() {

    int n,m;
    cin >> n;
    cin >> m;

    //tar pris input
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    //oppretter adj list
    for (int j = 0; j < m; ++j) {
        int u,v,d;
        cin >> u;
        cin >> v;
        cin >> d;
        adj[u].emplace_back(make_pair(v, d));
        adj[v].emplace_back(make_pair(u, d));
    }

    int q;
    cin >> q;

    //bearbeider hver quiry
    while(q!=0){
        long ans = solve(n);
        //hvis svaret er større ELLER LIK 0 skal jeg skrive ut svaret
        if(ans >=0)
            cout << ans << endl;
        else
            cout << "impossible"<< endl; //negativt er impossible
        q--;
    }
    return 0;
}
