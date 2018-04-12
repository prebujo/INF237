#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//structure of a matrix
struct m {
    double a1;
    double b1;
    double a2;
    double b2;
};

//making a vector class to calculate values
class vec {
private:

public:
    //using doubles for positions
    double x,y;
    int t;

    vec(double, double);

    vec minus(vec);

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

//method to calculate the determinant of two m matrixes
double det(m m){
    return m.a1*m.b2-m.a2*m.b1;
}

double calcPerc(int n){
    vector<vec> vectors;
    vectors.reserve(n);

    vec first = vec(0,0);
    vec secnd = vec(0,0);

    //taking input
    for (int i = 0; i < n; ++i) {

        double x, y;
        cin >> x;
        cin >> y;
        //saving first and second vector;
        if(i==0)
            first = vec(x,y);
        else if(i==1)
            secnd = vec(x,y);

        vectors.push_back(vec(x,y));
    }

    //vector for camera
    vec cam = first.middle(secnd);

    //calculating area of room
    double areal = 0.;
    for(vector<vec>::size_type i = 1; i != vectors.size(); i++){
        areal += vectors[i].area(vectors[i-1]);
    }
    areal += vectors.front().area(vectors.back());

    //finding 45 degree vectors for camera
    vec camVec1 =secnd.minus(cam).vec45CC();
    vec camVec2 = camVec1.rotateLeft();

    //finding first camera intersection vector
    int intersect = 0;
    vec intSecVec1 = vec(0,0);
    for(vector<vec>::size_type i = 2; i <= vectors.size(); i++) { // O(n)
        vec curVec = vectors[i];
        if(i == vectors.size())
            curVec = vectors[0];
        //calculating vector from previous to current
        vec vecPrevToCur = curVec.minus(vectors[i - 1]);
        //making the Matrix (M & Mt) and calculating the determinant
        m M = m{camVec1.x, -vecPrevToCur.x, camVec1.y, -vecPrevToCur.y};
        double detM = det(M);
        m Mt = m{camVec1.x, vectors[i - 1].x - cam.x, camVec1.y, vectors[i - 1].y - cam.y};
        double detMt = det(Mt);
        //making sure the detM and detMt are within the correct limits
        if(detM !=0)
            if(detMt/detM > 0 && detMt/detM <=1) { //if determinants are within limits i have an intersection
                intersect = i;
                intSecVec1 = vec(vectors[i-1].x+detMt/detM*vecPrevToCur.x,vectors[i-1].y+detMt/detM*vecPrevToCur.y);
                break;
            }
    }

    //finding second camera intersection vector
    int intersect2 = 0;
    vec intSecVec2 = vec(0,0);
    for(vector<vec>::size_type i = intersect; i <= vectors.size(); i++) { //O(n)
        vec curVec = vectors[i];
        if(i == vectors.size())
            curVec = vectors[0];
        //calculating vector from previous to current
        vec vecPrevToCur = curVec.minus(vectors[i - 1]);
        //making the Matrix (M & Mt) and calculating the determinant
        m M = m{camVec2.x, -vecPrevToCur.x, camVec2.y, -vecPrevToCur.y};
        double detM = det(M);
        m Mt = m{camVec2.x, vectors[i - 1].x - cam.x, camVec2.y, vectors[i - 1].y - cam.y};
        double detMt = det(Mt);
        //making sure the detM and detMt are within the correct limits
        if(detM !=0)
            if(detMt/detM > 0 && detMt/detM <=1) { //if determinants are within limits i have an intersection
                intersect2 = i;
                intSecVec2 = vec(vectors[i-1].x+detMt/detM*vecPrevToCur.x,vectors[i-1].y+detMt/detM*vecPrevToCur.y);
                break;
            }
    }

    //area that is not covered by camera
    double notCovered = 0.;

    //starting position of not covered area
    vec fromVec = cam;
    //calculating area until intersection
    int i = 1;
    while (i<intersect) {
        notCovered += fromVec.area(vectors[i]);
        fromVec = vectors[i];
        i++;
    }

    //adding the area from last vector to camera and from intersection back to camera
    notCovered += fromVec.area(intSecVec1);
    notCovered += intSecVec1.area(cam);

    //adding area from camera until second intersection
    notCovered += cam.area(intSecVec2);
    fromVec = intSecVec2;
    //adding area from intersection until last vector.
    i=intersect2;
    while(i<vectors.size()){
        notCovered += fromVec.area(vectors[i]);
        fromVec = vectors[i];
        i++;
    }
    //adding area from last vector until the first vector
    notCovered += fromVec.area(vectors[0]);
    //adding area from start until cam.
    notCovered += vectors[0].area(cam);

    //returnin the area minus not covered area over area (percentage).
    return (areal - abs(notCovered))/areal;
}


int main() {
    int t;
    cin >> t;
    while(t>0){
        int n;
        cin >> n;
        printf("%10.7f\n", calcPerc(n));
        t--;
    }
    return 0;
}