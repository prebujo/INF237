#include <iostream>

using namespace std;


int main() {
    int n,m;
    cin >> m >> n;

    int values[21][4];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> values[i][j];
        }
    }

    bool literals[21][21];
    for (int k = 0; k < m; ++k) {
        for (int i = 0; i < n; ++i) {
            literals[k][i] = true;
        }
    }

    bool val[m][n];

    for (int l = 0; l < m; ++l) {
        for (int i = 0; i < n; ++i) {
            val[l][i] = false;
        }
    }

    for (int l = 0; l < m; ++l) {
        for (int i = l; i < n; ++i) {
            val[l][i] = true;
        }
    }


    bool satisfactory = false;
    for (int j = 1; j < m; ++j) {
        bool satisfactCombo = true;
        for (int k = 0; k < m; ++k) {
            bool satisfClause = true;
            for (int i = 0; i < n; ++i) {
                if (values[k][i] > 0 && val[k][i] == false ) {
                    satisfClause = false;
                }
                else if (values[k][i] < 0 && val[k][i] == true){
                    satisfClause = false;
                }
            }
            if(!satisfClause){
                satisfactCombo = false;
                continue;
            }
        }
        if(satisfactCombo)
            satisfactory = true;
    }

    if(satisfactory)
        cout << "satisfactory" << endl;
    else
        cout << "unsatisfactory" << endl;
    return 0;
}