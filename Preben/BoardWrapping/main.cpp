#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long double PI = 3.141592653589793238L;

//making a vector class to calculate values
class vec {
private:

public:
    //using doubles for positions
    double x,y;
    int t;

    vec(double, double);

    vec minus(vec);

    vec add(vec);

    vec rotate(double);

    vec rotateLeft();

    vec middle(vec);

    double area(vec);

    vec vec45CC();


};
//costructor
vec::vec(double x1, double y1){
    x = x1;
    y = y1;
}

//method to deduct one vector from another
vec vec::minus(vec v){
    return vec(x-v.x, y-v.y);
}

vec vec::add(vec v){
    return vec(x+v.x, y+v.y);
}

vec vec::rotate(double v){
    v *= -2*PI/360;
    return vec(x*cos(v)-y*sin(v), x*sin(v)+y*cos(v));
}

//method to rotate a vector 90 degrees
vec vec::rotateLeft(){
    return vec(y, -x);
}

//method to get the vector in the middle of two other vectors
vec vec::middle(vec v){
    return vec((x+v.x)/2, (y+v.y)/2);
}

//method to get a 45 degree increase of a vector
vec vec::vec45CC(){
    return vec((x-y), (x+y));
}

//method to calculate the area from the x-axis between two vectors
double vec::area(vec v){
    return ((v.y+y)*(v.x-x))/2;
}

int main() {
    int N;
    cin >> N;

    vector<vec> vectors;
    vectors.reserve(N);

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        long boardSpace;
        for (int j = 0; j < n; ++j) {
            double x, y, w, h, v;
            cin >> x >> y >> w >> v;

            vec corner = vec(1/2*w,1/2*h).rotate(v);

            

            boardSpace += w*h;



        }

    }

}