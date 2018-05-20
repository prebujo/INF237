#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

const long double PI = 3.141592653589793238L;

//making a vector class to calculate values
class vec {
private:

public:
    vec();

    //using doubles for positions
    double x,y;

    vec(double, double);

    vec add(vec);

    vec rotate(double);

    vec flip();

    double area(vec);

    bool operator < (const vec &p) const { return y < p.y || (y == p.y && x < p.x); }

};
// empty constructor
vec::vec(){
    x = 0;
    y = 0;
}

//costructor
vec::vec(double x1, double y1){
    x = x1;
    y = y1;
}

double GSArea(vec *vectors, int n);

vec vec::add(vec v){
    return vec(x+v.x, y+v.y);
}

vec vec::rotate(double v){
    v *= -2*PI/360;
    return vec(x*cos(v)-y*sin(v), x*sin(v)+y*cos(v));
}

//method to calculate the area from the x-axis between two vectors
double vec::area(vec v){
    return ((v.y+y)*(v.x-x))/2;
}

vec vec::flip(){
    return vec(-x,-y);
}

//starting point of graham scan and index
int si = 0;
vec start(10001,10001);

int counterClockW(vec a, vec b, vec c) {
    double ar = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (ar > 0)
        return 1; //counter clockwise
    else if (ar < 0)
        return -1; //clockwise
    else
        return 0; //collinear
}

//the square distance from vector a to vector b
double sqrDist(vec a, vec b)  {
    double dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

//sorting vectors in polar order. If counterClockW returns -1 a comes before b
bool ord(vec a, vec b)  {
    int order = counterClockW(start, a, b);
    if (order == 0)
        return sqrDist(start, a) < sqrDist(start, b);
    return (order == 1);
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        vec vectors[n*4];
        long boardSpace = 0;
        int f = 0;

        for (int j = 0; j < n; ++j) {
            double x, y, w, h, v;
            cin >> x >> y >> w >> h >> v;

            //adding all corner vectors to the vector selection and updating start of graham scan
            //if I add a smaller vector
            vec corner = vec(w/2,h/2).rotate(v);
            vec vector = vec(x,y).add(corner);
            vectors[f] = vector;
            if(vector < start) {
                start = vector;
                si = f;
            }
            f++;
            corner = vec(-w/2,h/2).rotate(v);
            vector = vec(x,y).add(corner);
            vectors[f] = vector;
            if(vector < start) {
                start = vector;
                si = f;
            }
            f++;
            corner = vec(-w/2,-h/2).rotate(v);
            vector = vec(x,y).add(corner);
            vectors[f] = vector;
            if(vector < start) {
                start = vector;
                si = f;
            }
            f++;
            corner = vec(w/2,-h/2).rotate(v);
            vector = vec(x,y).add(corner);
            vectors[f] = vector;
            if(vector < start) {
                start = vector;
                si = f;
            }
            f++;

            //calc area
            boardSpace += w*h;
        }
        int c = sizeof(vectors)/sizeof(vectors[0]);
        double hullArea = GSArea(vectors, c);

       printf("%.1f %s\n", abs(boardSpace/hullArea*100.0), "%");
    }

}

double GSArea(vec *vectors, int n) {
    stack<vec> hull;

    //moving starting vector to position 0
    vec tem = vectors[0];
    vectors[0] = vectors[si];
    vectors[si] = tem;

    // sort the remaining point according to polar order about the start
    sort(vectors + 1, vectors + n, ord);

//    for (int j = 0; j < n; ++j) {
//        cout << vectors[j].x<<" " << vectors[j].y<<endl;
//    }

    //pushing start to hull
    hull.push(start);
    //pushing first and second point to hull
    hull.push(vectors[1]);
    hull.push(vectors[2]);

    for (int i = 3; i < n; i++) {
        vec top = hull.top();
        hull.pop();
        while (counterClockW(hull.top(), top, vectors[i]) != 1)   {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(vectors[i]);
    }

    hull.push(start);

    double area = 0;

//    cout << "hull: "<<endl;
    while(hull.size()>1) {
         vec first = hull.top();
//         cout << first.x << " " << first.y << endl;
         hull.pop();
         vec secnd = hull.top();
         area += first.area(secnd);
    }
    return area;
}