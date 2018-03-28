////#include <iostream>
////#include <algorithm>
////
////using namespace std;
////
////long maxi;
////long mini = 2^31-1;
////long r[50][50];
////int n;
////int t;
////
////
////void make_mat(int n);
////
////void dp_max(int t, int i, long s);
////void dp_min(int t, int i, long s);
////
////int main() {
////    cin >> n;
////    while (n != 0){
////        make_mat(n);
////        cin >> n;
////    }
////    return 0;
////}
////
////void make_mat(int n) {
////    for (int i = 0; i < n; ++i) {
////        for (int j = 0; j <n ; ++j) {
////            cin >> r[i][j];
////        }
////    }
////    cin >> t;
////
////    dp_max(t,0,0);
////    cout << maxi<<endl;
////
////    dp_min(t,0,0);
////    cout << mini << endl;
////}
//
//void dp_max(int t, int i, long s) {
//    long value;
//    if(t==1) {
//        for (int j = 0; j < n; ++j) {
//            value = r[i][j] + s;
//            if (value > maxi) {
//                maxi = value;
//            }
//        }
//    }
//    else {
//        for (int j = 0; j < n; ++j) {
//            dp_max(t-1, j, s+r[i][j]);
//        }
//    }
//}
//void dp_min(int t, int i, long s) {
//    long value;
//    if(t==1) {
//        for (int j = 0; j < n; ++j) {
//            value = r[i][j] + s;
//            if (value < mini) {
//                mini = value;
//            }
//        }
//    }
//    else {
//        for (int j = 0; j < n; ++j) {
//            dp_min(t-1, j, s+r[i][j]);
//        }
//    }
//}