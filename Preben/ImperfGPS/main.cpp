#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//making a vector class to calculate values
class vec {
private:

public:
    //using doubles for positions and int for time
    double x,y;
    int t;

    vec(double, double, int);

    vec minus(vec);

    double dot_prod(vec);

    vec vecAt(vec, vec, int);
};

vec::vec(double x1, double y1, int t1){
    x = x1;
    y = y1;
    t = t1;
}

//method to deduct one vector from another
vec vec::minus(vec v){
    return vec(x-v.x, y-v.y,t);
}

//method to take dot product of a vector
double vec::dot_prod(vec v){
    return (x*v.x + y*v.y);
}

//method to calculate distance between to vectors as input
double dist(vec p, vec q){ //runtime depends on sqrt but should be constant
    vec temp = q.minus(p);
    return sqrt(temp.dot_prod(temp));
}

//method to calculate a vector at time tt between a start vector s
//and a target vector p.
vec vecAt(vec s,vec p, int tt){//Constant runtime
    vec temp = p.minus(s);
    return {s.x+(temp.x/(p.t-s.t)*(tt-s.t)), s.y+(temp.y/(p.t-s.t)*(tt-s.t)), tt};
}

int main() {

    //starting by taking input values for n and t
    int n,t;
    cin >> n;
    cin >> t;

    //making a vector of our vector class called points
    vector<vec> points;
    points.reserve(n); //reserving memory

    //taking input
    for (int i = 0; i < n ; ++i) {
        double x,y,tt;
        cin >> x; cin >> y; cin >> tt;
        points.push_back(vec(x,y,tt));
    }

    //variables for start and distance
    double realDist = 0.;
    vec start = points.front();
    //calculating the distance from start to finish of travel distance
    for (auto const& it : points) {
        realDist += dist(start,it);
        start = it;
    }

    //variables for end time, time start and gps distance and gps start
    int end = points.back().t;
    int time = 0;
    start = points.front();
    double gpsDist = 0;
    vec gpsCur = points.front();

    //for each point i check if there are stops between and calculate
    //the gps distance and add it to the total distance
    for (auto const& it : points) { //runtime n
        //skipping first point
        if(it.t == 0) {
            time += t;//updating time intervall
            continue;
        }
        //adding all gps intervals until i reach next actual stop
        while(time<=it.t){ //runtime max ti/t
            vec stop = vecAt(start,it,time);
            gpsDist += dist(gpsCur,stop);
            gpsCur = stop;
            time+=t;
        }
        start = it;
    } // total runtime O(n*ti/t) where ti is the average time interval
    // of the actual run distance

    //adding distance to final destination.
    vec stop = points.back();
    gpsDist += dist(gpsCur,stop);
    gpsCur = stop;

    //printing percentage difference.
    printf("%10.7f\n", (realDist-gpsDist)/realDist*100);

}