#include <iostream>
#include <vector>

using namespace std;

//class to build graph
class G{
private:
    int V;
    vector<int> * adj;
    bool matching(bool *hit, int target);

public:
    G(int v);
    void addEdge(int v, int w);
    int matching();
    int *shotBy;
};

//constructor of graph
G::G(int v) {
    this -> V = v;
    this -> adj = new vector<int> [V];
    shotBy = (int*) malloc(V*sizeof(int));
    for (int i = 0; i < V; ++i) {
        shotBy[i] = 0;
    }
}

//adding edge to the graph
void G::addEdge(int v, int w) {
    this -> adj[v].push_back(w);
    this -> adj[w].push_back(v);
}

int G::matching() {
    int shots = 0;
    //for each shooter O(N)
    for (int p = 1; p < V; ++p) {

        //making a new hit (or marked) array.
        bool hit[V];
        for (int j = 0; j < V; ++j) {
            hit[j] = 0;
        }
        //if we have a match for the player we increase amount of shots.
        if(matching(hit, p)) //see below
            shots++;
    }
    //returning in the end the amount of shots
    return shots;
    //total running time is: O(N*M²)
}

//function to find a matching player or target to a shooter.
//taking a hit table to keep track of players hit so far
bool G::matching(bool *hit, int shooter) {
    //for each player in the sights of the shooter O(M)
    for(auto const& sighted: adj[shooter]) {
        //if player is not hit so far
        if (!hit[sighted]) {
            //mark him as hit
            hit[sighted] = true;
            //if the sighted player is not hit by anyone or I find the sigthed player another match
            if (shotBy[sighted] == 0 || matching(hit, shotBy[sighted])) { //running matching again
                shotBy[sighted] = shooter; //i update the shotBy and
                return true;    //return true to update shots
            }
        }
    }
    //if I could not find a match to the player I return false
    return false;
    //total runningtime: O(M²)
}

int main() {
    int N, M;

    cin >> N;
    cin >> M;

    //constructing graph
    G graph(N+1);

    //adding edges from input
    for (int i = 0; i < M; ++i) {
        int v, w;
        cin >> v;
        cin >> w;
        graph.addEdge(v,w);
    }

    //if not all players are shot
    if(graph.matching()!= N) {
        cout << "Impossible" << endl;
        return 0;
    }
    //else i print the solution
    for (int j = 1; j < N+1; ++j) {
        cout << graph.shotBy[j]<< endl;
    }
    return 0;
}
