#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool dirtyDay[366];
    for (int i = 0; i <= 365; ++i) {
        dirtyDay[i] = 0;
    }
    int day;
    cin >> day;
    int dayone = day;
    for (int j = 0; j < n-1; ++j) {
        dirtyDay[day] = true;
        cin >> day;
    }
    dirtyDay[day] = true;

    int count = 0;
    bool dirtyEnd = true;
    for (int k = dayone+1; k <= 365; ++k) {
        int dirty = 0;
        for (int i = k-1; i >= dayone; --i) {
            if(dirtyDay[i]){
                dirty += k - i;
                if(dirty >= 20){
                    count+=1;
                    dirtyEnd = false;
                    dayone = 366;
                    for (int j = k; j < 366; ++j) {
                        if(dirtyDay[j]){
                            dayone = j;
                            dirtyEnd = true;
                            break;}
                    }
                }
            }
        }
    }
    if(dirtyEnd)
        count++;
    cout << count;


}