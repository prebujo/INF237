////
//// Created by preben on 06.02.18.
////
//
//#include <iostream>
//#include <algorithm>
//
//void assignBox(double n, int i);
//
//using namespace std;
//
//double n;
//double b;
//
//int main() {
//
//    while(true){
//        cin >> n;
//        cin >> b;
//        if(n==-1 && b == -1) //breaker når input er -1 -1
//            break;
//        assignBox(n,b); //kaller assignboks funksjonen til input blir -1 -1
//    }
//    return 0;
//}
//
//void assignBox(double n, int b) {
//    vector<pair<double, int>> pBox(n); //oppretter vector med par av populasjon per boks og bokser.
//    double p;
//    long boxes = b -n;
//
//    for (int i = 0; i < n; ++i) { //for loop som legger til hver by som et par av mennesker per boks og bokser
//        cin >> p;
//        pBox[i] = make_pair(p, 1); //legger til hver populasjon i hver by med 1 boks (minimum)
//        //fjerner en boks for hver by
//    }
//
//    sort(pBox.begin(), pBox.end(), [] (pair<double,int>& a,pair<double, int>b) { return a.first < b.first; }); //gjør om vector til en max-heap
//
//    while(boxes>0) { //kjører til antall bokser er null
//        pair <double,int> maxP; // lager et nytt pair av max pop
//        maxP.first = (pBox.front().first * pBox.front().second)/(pBox.front().second+1); //setter første element av max til seg selv over + 1 boks
//        maxP.second = pBox.front().second + 1;  // setter andre element til seg selv pluss 1.
//        //pop_heap(pBox.begin(),pBox.end()); pBox.pop_back(); //popper max par
//        pBox.pop_back();
//        // finde die position fuer die maxBox mit bin search und dann insert
//
//        //vector mit deque austauschen.
//        pBox.push_back(maxP); push_heap (pBox.begin(),pBox.end()); //pusher det nye max paret
//        boxes--; //dekrementerer boxes
//    }
//    cout << ceil(pBox.front().first) << endl;
//
//}