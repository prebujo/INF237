//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <stack>
//
//using namespace std;
//
//const long double PI = 3.141592653589793238L;
//
////making a vector class to calculate values
//class vec {
//private:
//
//public:
//    vec();
//
//    //using doubles for positions
//    double x,y;
//
//    vec(double, double);
//
//    vec add(vec);
//    vec minus(vec);
//    double dot(vec);
//
//    vec rotate(double);
//
//    vec flip();
//
//    double area(vec);
//
//    bool operator < (const vec &p) const { return x < p.x || (x == p.x && y < p.y); }
//
//};
//// empty constructor
//vec::vec(){
//    x = 0;
//    y = 0;
//}
//
////costructor
//vec::vec(double x1, double y1){
//    x = x1;
//    y = y1;
//}
//
//double GSArea(vector<vec> p, int n);
//
//vec vec::add(vec v){
//    return vec(x+v.x, y+v.y);
//}
//
//vec vec::minus(vec v){
//    return vec(x-v.x, y-v.y );
//}
//
//double vec::dot(vec v) {
//    return x*v.x + y*v.y;
//}
//
//vec vec::rotate(double v){
//    v *= -2*PI/360;
//    return vec(x*cos(v)-y*sin(v), x*sin(v)+y*cos(v));
//}
//
////method to calculate the area from the x-axis between two vectors
//double vec::area(vec v){
//    return ((v.y+y)*(v.x-x))/2;
//}
//
//vec vec::flip(){
//    return vec(-x,-y);
//}
//
//bool leftTurn(vec a,vec b, vec c){
//    vec v1 = b.minus(a);
//    vec v2 = c.minus(b);
//    v2 = v2.rotate(90);
//    double ans =v1.dot(v2);
//    return (ans >0.00000001);
//}
//
//int counterClockW(vec a, vec b, vec c) {
//    double ar = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
//    if (ar < 0)
//        return -1; //clockwise
//    else if (ar > 0)
//        return 1; //counter-clockwise
//    else
//        return 0; //collinear
//}
//
//int main() {
//    int N;
//    cin >> N;
//
//    for (int i = 0; i < N; ++i) {
//        int n;
//        cin >> n;
//        vector<vec> vectors(n*4);
//        long boardSpace = 0;
//        double x, y, w, h, v, f=0;
//        for (int j = 0; j < n; ++j) {
//            cin >> x >> y >> w >> h >> v;
//            //adding all corner vectors to the vector selection
//            vec midP = vec(x,y);
//            vectors[f++] = midP.add(vec(w/2,h/2).rotate(v));
//            vectors[f++] = midP.add(vec(-w/2,h/2).rotate(v));
//            vectors[f++] = midP.add(vec(-w/2,-h/2).rotate(v));
//            vectors[f++] = midP.add(vec(w/2,-h/2).rotate(v));
//
//            //calc area
//            boardSpace += w*h;
//        }
//        double hullArea = GSArea(vectors, vectors.size());
//
//        printf("%.1f %s\n", abs(boardSpace/hullArea*100.0), "%");
//    }
//
//}
//
//double GSArea(vector<vec> vectors, int n) {
//    vector<vec> upper_wrap(n);
//    vector<vec> lower_wrap(n);
//
//    // sort the remaining point according to x and secondary to y.
//    sort(vectors.begin(), vectors.end());
//
//    //pushing start to hull
//    upper_wrap[0] = vectors[0];
//    //pushing first and second, point to upper_wrap
//    upper_wrap[1] = vectors[1];
//
//    int ui = 0;
//
//    for (int i = 0; i < n; i++) { //runtime O(n)
//        //checing if first second and third element of stack form a countercl or left turn
//        while (ui>=2 && counterClockW(upper_wrap[ui-2], upper_wrap[ui-1], vectors[i]) == 1)   {
//            ui--;
//        }
//        upper_wrap[ui++] = vectors[i];
//    }
//
//    upper_wrap.resize(ui);
//
//    //pushing end point
//    int li = 0;
//
//    for(int j = n-1; j>=0;j--){
//
//        while(li>=2 && counterClockW(lower_wrap[li-2].flip(), lower_wrap[li-1].flip(), vectors[j].flip()) == 1){
//            li--;
//        }
//        lower_wrap[li++] = vectors[j];
//    }
//
//    lower_wrap.resize(li);
//
//    double area = 0;
//
//    for (int k = 0; k < upper_wrap.size()-1; ++k) {
//        area += upper_wrap[k].area(upper_wrap[k+1]);
//    }
//
//    for (int l = 0; l < lower_wrap.size()-1; ++l) {
//        area += lower_wrap[l].area(lower_wrap[l+1]);
//    }
//    return area;
//}
//
