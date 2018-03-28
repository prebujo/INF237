#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int nested (int N);
bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return (b.second < a.second);
}
bool sortnorm(const pair<int,int> &a, const pair<long,long> &b){
    return (a.first < b.first);
}

int main() {
    int N;
    int T;

    cin >> T;

    for (int i = 0; i < T; ++i) { //kjører en nested for hver runde
        cin >> N;
        cout<< nested(N) <<endl;
    }
    return 0;
}

int nested (int N) {    //metode som tar input for hvert sett med dukker og finner ut hvor mange nye dukker man minst trenger
    vector<pair<long, long>> dolls;
    pair<long,long> bdolls[N];
    for (int i = 0; i < N; ++i) {   //tar input og lagrer den i vector som et par
        int w;
        int h;
        cin >> w;
        cin >> h;
        dolls.push_back(make_pair(w, h));
    }

    stable_sort(dolls.begin(), dolls.end(), sortinrev);  //sorterer input etter synkende høyde

    stable_sort(dolls.begin(), dolls.end(), sortnorm);  //sorterer input etter stigente bredde

    int min_dolls = 1;  //til å begynne med har jeg kun en dukke, denne økes for hver nye dukke og returneres til slutt

    for (int j = 1; j < N ; ++j) {  //gjennomgår en og en dukke fra input og sammenligner med den som står før i den sorterte rekken.
        long w = dolls[j].first; // bredde for denne dukken
        long h = dolls[j].second; //høyde for denne dukken
        long w1 = dolls[j-1].first;  //bredde for dukken før denne
        long h1 = dolls[j-1].second;  //høyde for dukken før denne

        if (!(w > w1 && h > h1)){
            //for hver dukke sjekker jeg om den før er mindre enn denne ellers flytter jeg denne ut

            bool add_doll = true;  //bestemmer om jeg skal legge til en ny dukke eller ikke.
            int hi = min_dolls+1;
            int lo = 2;
            int mid = (lo+hi)/2;
            while(lo<hi){    //gjør binary search på de største dokkene utenfor stabelen for å finne hvor denne passer
                if (w>bdolls[mid].first && h > bdolls[mid].second){
                    add_doll = false;
                    hi = mid;
                }
                else
                    lo = mid+1;
                mid = (lo+hi)/2;
            }

            if (add_doll) {  // hvis jeg skal legge til en ny dukke øker jeg min_dolls og legger til en ny på riktig indeks
                min_dolls++;
                bdolls[min_dolls] = dolls[j];
            }
            else
                bdolls[mid] = dolls[j];  //hvis ikke skal jeg bare overskrive den største dukken for denne "stabelen"

            dolls[j] = dolls[j-1]; //setter dukken lik den forrige dukken for neste sammenligning.
        }
    }
    return min_dolls; //returnerer min_dolls
}