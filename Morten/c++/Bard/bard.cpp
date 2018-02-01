#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int N; // number of villagers
    int E; // number of evenings
    std::cin >> N;
    std::cin >> E;

    bitset<50> bitsets[5];

    for (int e = 0; e < E; ++e) {
        int K; cin >> K;
        int present[K]; //the villagers present this evening
        bool bard = false;
        for (int k = 0; k < K; ++k) {
            int v;  //villager
            cin >> v;
            if (v == 1) bard = true;
            present[k] = v;
        }
        for (int i = 1; i <= 4; ++i) {
            cout << bitsets[i] << endl;

        }
        cout << "**********";
        if (bard) {
            for (int k = 0; k < K; ++k) {
                int v = present[k];
                bitsets[v].set(e, true); //teach the song of this evening
            }
        } else {
            bitset<50> acc; //accumulator for the songs any present villager knows
            for (int k = 0; k < K; ++k) {
                int v = present[k];
                cout << bitsets[v] << endl;
                //acc |= bitsets[v];    //add songs known by villager v to accumulator
            }
            cout << "acc: ";
            cout << acc;
        }


    }
    return 0;
}