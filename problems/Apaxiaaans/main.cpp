#include <iostream>

using namespace std;

int main() {
    string str;
    string res;
    char prev;
    cin >> str;
    for (char i:str) {
        if(i != prev){
            res = res+i;
            prev = i;
        }

    }
    cout << res << endl;
    return 0;
}