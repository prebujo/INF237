//#include <iostream>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    int a[n+2];
//    for (int i = 1; i < n+1; ++i) {
//        cin >> a[i];
//    }
//    //making a max and min value
//    a[0]= 0;
//    a[n+1]= 999999999;
//
//    //initialising N and offset for sum Array
//    int N = 2;
//    int offs = 2;
//
//    //finding N and offset for sum array
//    while(2*n + 3 > N)
//        N *=2;
//    while(n + 2 >offs)
//        offs *= 2;
//
//    //arrays for min og max a,
//    //hver node i treet inneholder index til minste verdi
//    //index - pos = swaps
//    int maxA[N+1];
//    int minA[N+1];
//
//
//    //initializing A
//    for (int j = 1; j <N+1 ; ++j) {
//        maxA[j] = 0;
//        minA[j] = n+1;
//    }
//
//    for (int k = 1; k < n+1 ; ++k) {
//        int pos = k + offs;
//        do{
//            if(a[k] > a[maxA[pos]])
//                maxA[pos] = k;
//            if(a[k] < a[minA[pos]])
//                minA[pos] = k;
//            pos /=2;
//        } while(pos>0);
//    }
//
//    //value to indicate
//    int lower = 1;
//    int higher = n;
//    int phase = 1;
//
//    //for each phase
//    for (int m = 1; m <=n ; ++m) {
//        bool minPhase = m%2==1;
//        if(minPhase){
//            int l = lower + offs -1;
//            int r = higher + offs +1;
//            while(true){
//                l/=2;
//                r/=2;
//                if(l==r) break;
//            }
//            int minIdx = minA[l];
//            cout << minIdx - lower<<endl;
//            while(minIdx>lower){
//                int temp = a[minIdx];
//                a[minIdx] = a[minIdx -1];
//                a[minIdx-1] = temp;
//                minIdx--;
//            }
//            for (int i = 0; i < n ; ++i) {
//                cout << a[i+1]<<" ";
//            }
//            cout<<endl;
//            //oppdaterer max og min tabell
//            for (int k = lower; k < higher+1 ; ++k) {
//                int pos = k + offs;
//                do{
//                    if(a[k] > a[maxA[pos]])
//                        maxA[pos] = k;
//                    if(a[k] < a[minA[pos]])
//                        minA[pos] = k;
//                    pos /=2;
//                } while(pos>0);
//            }
//            lower++;
//        }
//        else {
//            int l = lower + offs - 1;
//            int r = higher + offs + 1;
//            while(true){
//                l/=2;
//                r/=2;
//                if(l==r) break;
//            }
//            int maxIdx = maxA[l];
//            cout << higher - maxIdx << endl;
//            while(maxIdx<higher){
//                int temp = a[maxIdx];
//                a[maxIdx] = a[maxIdx +1];
//                a[maxIdx+1] = temp;
//                maxIdx++;
//            }
//            for (int i = 0; i < n ; ++i) {
//                cout << a[i+1]<<" ";
//            }
//            cout<<endl;
//            //oppdaterer max og min tabell
//            for (int k = lower; k < higher+1 ; ++k) {
//                int pos = k + offs;
//                maxA[pos] = k;
//                do{
//                    if(a[k] > a[maxA[pos]])
//                        maxA[pos] = k;
//                    if(a[k] < a[minA[pos]])
//                        minA[pos] = k;
//                    pos /=2;
//                } while(pos>0);
//            }
//            higher--;
//        }
//    }
//
//
//
//    //running update for each number in a[]
//
////        string op;
////        cin >> op;
////        if(op == "F"){
////            //if F, updating the value in position pos;
////            int pos;
////            cin >> pos;
////            long diff; //difference is either 1 or -1
////            if(a[pos]) { //updating the bit array to opposite of 1 and diff
////                diff = -1;
////                a[pos] = !a[pos];
////            }
////            else {  //updating position if 0 and diff
////                diff = 1;
////                a[pos] = !a[pos];
////            }
////            int pos2 = pos+offs; //position of sum (offset) in A
////            do{
////                A[pos2] += diff; //adding difference to all underlying A in the tree stucture
////                pos2 /= 2; //runtime of update is O(logN)
////            }while(pos2>0); //when pos2 is less than 0 stop.
////        }
////        else { //hvis input er noe annet enn F altså C
////            //tar input for nedre og øvre intervall
////            long l, r;
////            cin >> l;
////            cin >> r;
////            //initialiserer l og r ved hjelp av offset
////            l = l + offs - 1;
////            r = r + offs +1;
////            long ans = 0;
////
////            //kjører while til l og r møtes
////            while(true){
////                //initialiserer boolske verdier
////                bool lright = (l%2) ==0;
////                bool rleft = (r%2) == 1;
////                //dekrementerer l og r
////                l/=2;   //kjøretid blir dermed O(logN)
////                r/=2;
////                if(l==r) break; //hvis r == l er jeg ferdig
////                if(lright) ans += A[2*l +1]; //hvis ikke skal jeg legge til alt som er til høyre for l hvis l går til høyre
////                if(rleft) ans += A[2*r];    // og alt til venstre for r hvis r går til venstre
////            }
////            //skriver output
////            cout << ans << endl;
////        }
////    }
//
//}