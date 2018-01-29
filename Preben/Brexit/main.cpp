#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;


class Graph{
private:
    int V;
//    vector<vector<int>> * G;
    vector <int> * adj;
    void GDFS(int v, int t, bool marked[]);
    int *pCount;
    int *aCount;


public:
    Graph(int V);
    void addEdge(int v, int w);
    void removeEdge(int v, int w);
    void DFS(int v, int t);

};

Graph::Graph(int V){
    this -> V = V;
    this -> adj = new vector<int> [V];
    pCount = (int*) malloc(V*sizeof(int));
    aCount = (int*) malloc(V*sizeof(int));
//    for (int i = 0; i < V; ++i) {
//        cout<<pCount[i]<< endl;
//    }
}

void Graph::addEdge(int v, int w){
    pCount[v] += 1;
    pCount[w] += 1;
    aCount[v] += 1;
    aCount[w] += 1;
    this->adj[v].push_back(w);
    this->adj[w].push_back(v);
//    cout << v << endl;
//    cout << w << endl;
}

void Graph::removeEdge(int v, int w) {
//    cout << adj[v].front()<< " er front og " << w << " er motpart" << endl;
//    cout << adj[w].front()<< " er front og " << v << " er motpart" << endl;
//    cout << "removing " << v+1 << "-" << w+1 << endl;
    aCount[v] -= 1;
    aCount[w] -= 1;
    adj[v].erase(std::remove(adj[v].begin(), adj[v].end(), w), adj[v].end());
    adj[w].erase(std::remove(adj[w].begin(), adj[w].end(), v), adj[w].end());
}

void Graph::GDFS(int v, int t, bool marked[]){
    marked[v] = true;
    while(adj[v].size()>0){
        int valueAtI = adj[v].back();
//        cout << valueAtI << " valueat " << endl;
//        cout << v << " v " << endl;
        removeEdge(v, valueAtI);
//        cout << "round "<< valueAtI << ":" <<endl;
//        cout << marked[valueAtI]<<endl;
//        cout << aCount[valueAtI]<<endl;
//        cout << pCount[valueAtI]/2 << endl;
//        cout << i << endl;

        if(!marked[valueAtI] && adj[valueAtI].size() <= ((pCount[valueAtI])/2)){
            if(valueAtI == t){
                cout << "leave";
                exit(0);}
            GDFS(valueAtI, t, marked);
        }
    }

}
void Graph::DFS(int v, int t) {
    bool *marked = new bool[V];
    GDFS(v, t, marked);
}

int main() {
    //declaring variables and taking input
    int c;
    int p;
    int x;
    int l;
    cin >> c;
    cin >> p;
    cin >> x;
    cin >> l;

    if(x == l) {
        cout << "leave";
        exit(0);
    }

    Graph *graph = new Graph(c);
    int a;
    int b;
    for (int i = 0; i < p; ++i) {
        cin >> a;
        cin >> b;
        graph->addEdge(a-1,b-1);
    }
    graph->DFS(l-1, x-1);
    cout << "stay";
    return 0;
}


