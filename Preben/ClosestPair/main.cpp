#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

struct Point{
    double x, y;
};

struct DoublePoint{
    Point a, b;
    double d;

    bool operator < (const DoublePoint &p) const { return d < p.d; }
};

int compareX (const void * a, const void * b) {
    return ( ((Point *)a)->x - ((Point *)b)->x );
}

int compareY (const void * a, const void * b) {
    return ( ((Point *)a)->y - ((Point *)b)->y );
}

double dist(Point a, Point b){
    return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) );
}

DoublePoint min(DoublePoint a, DoublePoint b){
    if(a.d<b.d)
        return a;
    else
        return b;
}

DoublePoint stripClosest(Point strip[], int size, DoublePoint d)
{
    DoublePoint closest = d;// Initialize the minimum DoublePoint

    qsort(strip, size, sizeof(Point), compareY);

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < closest.d; ++j) {
            double dis = dist(strip[i], strip[j]);
            if (dis < closest.d) {
                closest.a = strip[i];
                closest.b = strip[j];
                closest.d = dis;
            }
        }
    return closest;
}

void printPoints(DoublePoint dp){
    cout  << dp.a.x << " " << dp.a.y << " " << dp.b.x << " " << dp.b.y<<endl;
}

DoublePoint closestPair(Point Px[], Point Py[], int n) {
    DoublePoint closest;
    // If there are 2 or 3 points, then use brute force to find closest point
    if (n <= 3) {
        closest.d = numeric_limits<double>::max();
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j) {
                double dis = dist(Px[i], Px[j]);
                if ( dis < closest.d) {
                    closest.a = Px[i];
                    closest.b = Px[j];
                    closest.d = dis;
                }
            }
        return closest;
    }

    // setting middle point
    int mid = n/2;
    Point midPoint = Px[mid];

    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    Point PyL[mid+1];   // y sorted points on left of vertical line
    Point PyR[n-mid-1];  // y sorted points on right of vertical line
    int li = 0, ri = 0;  // indexes of left and right subarrays
    for (int i = 0; i < n; i++)
    {
        if (Py[i].x > midPoint.x) {
            PyR[ri] = Py[i];
            ri++;
        } else {
            PyL[li] = Py[i];
            li++;
        }
    }


    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    DoublePoint dl = closestPair(Px, PyL, mid);
    DoublePoint dr = closestPair(Px + mid, PyR, n-mid);

    // keeping the smallest doublepoint
    DoublePoint dclosest = min(dr,dl);


    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < dclosest.d)
            strip[j] = Py[i], j++;

    // Find the closest points in strip.  Return the minimum of d and closest
    // distance of strip[]
    return min(dclosest, stripClosest(strip, j, dclosest) );
}

// The main function that finds the smallest distance
DoublePoint closestP(Point P[], int n) {

    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
    int size = sizeof(Point);
    qsort(Px, n, size, compareX);
    qsort(Py, n, size, compareY);

    // recursive call on closestPair
    return closestPair(Px, Py, n);
}

int main() {

    int n;

    while(cin >> n) {
        if (n == 0)
            break;

        Point points[n];
        for (int i = 0; i < n; ++i) {
            double x,y;
            cin>>x>>y;
            points[i] = {x,y};
        }
        int n = sizeof(points) / sizeof(points[0]);
        printPoints(closestP(points, n));
    }
    return 0;
}