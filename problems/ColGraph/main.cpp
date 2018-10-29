//#include <iostream>
//#include <vector>
//#include <sstream>
//#include <cmath>
//#include <bitset>
//
//using namespace std;
//int N;
//
//class G{
//    int V; //no of verticies
//
//public:
//    G(int V){ //constructor
//        this-> V = V;
//        adj = new vector<int> [V];
//    }
//    vector<int> *adj; //adj list
//
//    void addE(int v, int w);
//    void remN(int n);
//};
//
//void G::addE(int v, int w){ //since i get input for both verticies i only use a "digraph" here.
//    adj[v].push_back(w);
//}
//
//void G::remN( int n){
//    for (int i = 0; i <N ; ++i) {
//        adj[V].pop_back();
//    }
//
//}
//
//int removeCurr(G g, bitset<11> bit){
//    for (int i = 0; i < bit.size() ; ++i) {
//        if(bit[i])
//            g.remN(i);
//    }
//
//    int minCol = N;
//    for (int m = 0; m < pow(2, N); ++m) {
//        bitset<11> curr(m);
//
//        int marked[N];
//        bool ind = true;
//        for (int n = 0; n < N; ++n) {
//            marked[n] = 0;
//        }
//        for (int k = 0; k < N; ++k) {
//            if (curr[k]) {
//                marked[k] = 1;
//                for (auto const &i: g.adj[k]) { //O(E)
//                    if (marked[i] == 1)
//                        ind = 0;
//                }
//            }
//        }
//        int min;
//        if (ind){
//            min = removeCurr(g, curr);
//        }
//        if(min<minCol)
//            minCol = min;
//    }
//    return minCol;
//
//
//}
//
//int main() {
//    cin >> N;
//
//    //moving to next line
//    string l;
//    getline(cin, l);
//
//    //generating graph
//    G G(N);
//
//    //going through each line of input
//    for (int i = 0; i < N; ++i) {
//        char c;
//        string line;
//        getline(cin, line);
//        istringstream iss(line);
//        while (iss >> c){ //adding each edge
//            G.addE(i,(int)c-48);
//        }
//    }
//
//    int minCol = N;
//    for (int j = 0; j < N; ++j) {
//
//        bitset<11> max(0);
//        for (int m = 0; m < pow(2, N); ++m) {
//            bitset<11> curr(m);
//
//            int marked[N];
//            bool ind = true;
//            for (int n = 0; n < N; ++n) {
//                marked[n] = 0;
//            }
//            for (int k = 0; k < N; ++k) {
//                if (curr[k]) {
//                    marked[k] = 1;
//                    for (auto const &i: G.adj[k]) { //O(E)
//                        if (marked[i] == 1)
//                            ind = 0;
//                    }
//                }
//            }
//            int min;
//            if (ind){
//                min = removeCurr(G, curr);
//            }
//            if(min<minCol)
//                minCol = min;
//        }
//        cout << minCol;
//    }
//}
