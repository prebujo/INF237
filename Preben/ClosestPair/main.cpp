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

    DoublePoint() {}
    DoublePoint(Point a,Point b,double d) : a(a), b(b), d(d) {}

    bool operator < (const DoublePoint &p) const { return d < p.d; }
};

int compareX (const void* a, const void* b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY (const void* a, const void* b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->y - p2->y);
}

double dist(Point p1, Point p2){
    double d1 = (p1.x - p2.x);
    double d2 = (p1.y - p2.y);
    return sqrt( d1*d1 + d2*d2);
}

DoublePoint minD(DoublePoint a, DoublePoint b){
    if(a<b)
        return a;
    else
        return b;
}

DoublePoint splitClosest(Point split[], int size, DoublePoint d){ // O(n)
    DoublePoint closest = d;// Initialize the minimum DoublePoint

    // Check all points one by one until difference of y is less than d
    // only then can the total distance be less than the closest d
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (split[j].y - split[i].y) < closest.d; ++j) {
            double dis = dist(split[i], split[j]);
            if (dis < closest.d) {
                closest = DoublePoint(split[i], split[j], dis);
            }
        }
    return closest;
}

//printing the points in a DoublePoint
void printPoints(DoublePoint dp){
    printf("%.3f %.3f %.3f %.3f\n", dp.a.x, dp.a.y, dp.b.x,dp.b.y);
}

DoublePoint closestPair(Point Px[], Point Py[], int n) {
    // If there are 2 or 3 points, then use brute force to find closest point
    if (n <= 3) {
        Point a,b;
        DoublePoint closest = DoublePoint( a, b,numeric_limits<double>::max());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double dis = dist(Px[i], Px[j]);
                if (dis < closest.d) {
                    closest = DoublePoint(Px[i], Px[j], dis);
                }
            }
        }
        return closest;
    }

    // setting middle/split point
    int mid = n/2;    std::cout << "Hello, World!" << std::endl;
    return 0;
    Point midP = Px[mid];

    // Divide ysorted points left of mid line
    Point PyL[mid];   // left side
    Point PyR[n-mid];  // right side
    int l = 0, r = 0;  // indexes of left and right subarrays
    for (int i = 0; i < n; i++){
        if (Py[i].x > midP.x && r < n-mid) {
            PyR[r] = Py[i];
            r++;
        } else if(l <mid) {
            PyL[l] = Py[i];
            l++;
        } else {
            PyR[r] = Py[i];
            r++;
        }
    }


    //Find the smallest distance DoublePoint on the left side of the split and on the right side
    DoublePoint dl = closestPair(Px, PyL, mid); // O(logn)
    DoublePoint dr = closestPair(Px + mid, PyR, n-mid); //O(logn)

    // keeping the smallest from each side
    DoublePoint dclosest = minD(dr,dl);

    // Build an array split[] that contains points close (closer than closestd)
    // to the line passing through the middle split point
    Point split[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midP.x) < dclosest.d) {
            split[j] = Py[i];
            j++;
        }

    // Find the closest points in the split array.  Return the minimum of dclosest and closest
    // distance of split[]
    return minD(dclosest, splitClosest(split, j, dclosest) );
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
        int N = sizeof(points) / sizeof(points[0]);

        //initiating x and y sorted arrays..
        Point Px[N];
        Point Py[N];
        int i = N-1;
        while(i>=0){
            Px[i] = points[i];
            Py[i] = points[i];
            i--;
        }

        int size = sizeof(Point);
        qsort(Px, N, size, compareX); // sorting according to x value
        qsort(Py, N, size, compareY); // sorting according to y value

        printPoints(closestPair(Px, Py, N)); //tot runtime O(nlogn)
    }
    return 0;
}