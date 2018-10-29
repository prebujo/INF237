#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string inp;
    int inpInt;
    for (int i = 0; i < n ; ++i) {
        cin >> inp;
        if(inp == "mumble")
            continue;
        else {
            inpInt = stoi(inp);
            if (inpInt != i + 1) {
                cout << "something is fishy";
                return 0;
            }
            else
                continue;
        }
    }
    cout<< "makes sense";
    return 0;
}