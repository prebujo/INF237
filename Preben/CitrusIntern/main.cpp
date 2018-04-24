#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

long In[1000000];
long OutD[100000];
long OutU[100000];
int N;


long delt(int n, vector<vector<int>> ch){
    long null = 0;
    long t = numeric_limits<long int>::max();
    for (int i = 0; i < ch[n].size(); ++i) {
        long diff = In[ch[n][i]]-OutD[ch[n][i]];
        long t1 = max(diff, null);
        t = min(t1, t);
    }
    return t;
};

void dfsBribe(int n, vector<vector<int>> ch, long w[]){
    if(ch[n].size() <= 0){
        long v = w[n];
        In[n] = w[n];
        long max = numeric_limits<long int>::max();
        OutD[n] = numeric_limits<long int>::max();
        OutU[n] = 0;
    }
    else{
        for (int j = 0; j <ch[n].size() ; ++j) {
            dfsBribe(ch[n][j], ch, w);
        }
        long v = w[n];
        In[n] = w[n];
        for (int i = 0;i<ch[n].size(); ++i) {
            long in = In[ch[n][i]];
            long ou = OutU[ch[n][i]];
            long ud = OutD[ch[n][i]];
            In[n] += OutU[ch[n][i]];
            long inin = In[n];
            OutU[n] += min(In[ch[n][i]], OutD[ch[n][i]]);
            long ouu = OutU[n];
            OutD[n] += min(In[ch[n][i]], OutD[ch[n][i]]);
            long oud = OutD[n];
            long daa = 0;
        }
        long del = delt(n, ch);
        OutD[n] += del;
    }
}

int main() {
    cin >> N;

    //weights table
    long w[N];

    //initialising adj. list
    vector<vector<int>>adj(N);

    //initialising marked table
    bool marked[N];
    for (int l = 0; l < N; ++l) {
        marked[l] = 0;
    }

    //taking input of organisation map
    for (int i = 0; i < N; ++i) {
        int U;
        cin >> w[i];
        cin >> U;
        for (int j = 0; j < U; ++j) {
            int inp;
            cin >> inp;
            adj[i].push_back(inp);
            marked[inp] = 1;
        }
    }

    //finding top boss of company calling him root
    int root = 0;
    for (int m = 0; m < N; ++m) {
        if(!marked[m])
            root = m;
    }

    dfsBribe(root, adj, w);
    cout << min(In[root], OutD[root])<<endl;
}