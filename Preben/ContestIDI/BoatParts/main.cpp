#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int P, N;
    cin >> P;
    cin >> N;

    vector<string> parts;

    for (int i = 1; i <= N; ++i) {
        string part;
        bool replace = 1;
        cin >> part;
        for (int j = 0; j < parts.size(); ++j) {
            if (parts[j].compare(part) == 0 ) {
                replace = 0;
                break;
            }
        }

        if(replace)
            parts.push_back(part);

        int size = parts.size();
        if(size>=P){
            cout << i;
            return 0;}
    }

    cout << "paradox avoided"<<endl;


}