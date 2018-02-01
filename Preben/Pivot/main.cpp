#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];
    int sortedarray[n];
    for (int i = 0; i < n; ++i) {
        cin>>array[i];
        sortedarray[i] = array[i];
    }
    sort(sortedarray, sortedarray+n);

    int max = 0;
    int output = 0;

    for (int j = 0; j < n; ++j) {
        if (array[j] > max){
            max = array[j];
            if(array[j] == sortedarray[j]) {
                output++;
            }
        }
    }
    cout << output << endl;
    return 0;
}
