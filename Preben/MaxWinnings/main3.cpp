////
//// Created by preben on 13.02.18.
////
//#include <iostream>
//
//
//using namespace std;
//
//long r[50][50];
//
//void make_mat(int n);
//
//long dp_max(int t, int n);
//long dp_min(int t, int n);
//
//int main() {
//    int n;
//    cin >> n;
//    while (n != 0){
//        make_mat(n);
//        cin >> n;
//    }
//    return 0;
//}
//
//void make_mat(int n) {
//    int t;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n ; ++j) {
//            cin >> r[i][j];
//        }
//    }
//    cin >> t;
//
//    cout << dp_max(t,n) << " ";
//
//    cout << dp_min(t,n) << endl;
//}
//
//long dp_max(int t, int n){
//
//    long dp_max[t+1][n];
//    long value;
//    long maximum;
//
//    for (int i = 0; i < n; ++i) {
//        dp_max[1][i] = r[0][i];
//    }
//
//
//    for (int tt = 2; tt <= t ; ++tt) {
//        for (int i = 0; i < n ; ++i) {
//            maximum = 0;
//            for (int j = 0; j < n; ++j) {
//                value = r[j][i] + dp_max[tt - 1][j];
//                if (value > maximum)
//                    maximum = value;
//            }
//            dp_max[tt][i] = maximum;
//        }
//    }
//
//    maximum = 0;
//    for (int i = 0; i < n ; ++i) {
//        value = dp_max[t][i];
//        if (value>maximum)
//            maximum = value;
//    }
//    return maximum;
//}
//
//long dp_min(int t, int n){
//
//    long dp_min[t+1][n];
//    long value;
//    long minimum;
//
//    for (int i = 0; i < n; ++i) {
//        dp_min[1][i] = r[0][i];
//    }
//
//
//    for (int tt = 2; tt <= t ; ++tt) {
//        for (int i = 0; i < n ; ++i) {
//            minimum = 9200000000000000000;
//            for (int j = 0; j < n; ++j) {
//                value = r[i][j] + dp_min[tt - 1][i];
//                if (value < minimum)
//                    minimum = value;
//            }
//            dp_min[tt][i] = minimum;
//        }
//    }
//
//    minimum = 9200000000000000000;
//    for (int i = 0; i <n ; ++i) {
//        value = dp_min[t][i];
//        if (value<minimum)
//            minimum = value;
//    }
//    return minimum;
//}
//
