#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string num = to_string(n);
    n=num.length();
    for (int i = 0; i < (n+1)/2 ; ++i) {
        if (!(num.at(i) == num.at(n - 1- i))) {
            cout << "NEI" << endl;
            return 0;
        }
    }
    cout<< "JA" << endl;
}