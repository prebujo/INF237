#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];	//oppretter to arrays for input verdiene
    int sortedarray[n];
    for (int i = 0; i < n; ++i) {  //looper igjennom n ganger og tar input
        cin>>array[i];
        sortedarray[i] = array[i];
    }

    sort(sortedarray, sortedarray+n); //sorterer input til første array

    int max = 0;		//oppretter variabler for max og en teller for antall pivoter
    int output = 0;

    for (int j = 0; j < n; ++j) {	//looper igjennom og sjekker om 
        if (array[j] > max){		// tallet er større enn største verdi så langt
            max = array[j];		//hvis det er større setter jeg ny max
            if(array[j] == sortedarray[j]) {	// hvis tallet er likt i den sorterte og ikke sorterte er det en mulig pivot.
                output++;
            }
        }
    }
    cout << output << endl; //skriver ut antall pivoter
    return 0;
}
