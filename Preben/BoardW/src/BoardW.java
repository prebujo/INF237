import java.util.*;

public class BoardW {
    private static class vec implements Comparable<vec>{
        private double x,y;
        //kontrsuktør
        private vec(double x, double y){
            this.x = x;
            this.y = y;
        }

        @Override //sorting first by y then by x
        public int compareTo(vec vec) {
            if(y>vec.y || (y == vec.y && x > vec.x))
                return 1;
            else if(y < vec.y || (y == vec.y && x < vec.x))
                return -1;
            else
                return 0;
        }

        private vec rotate(double v){
            double r = -Math.toRadians(v);
            return new vec(x*Math.cos(r) - y*Math.sin(r),
                    x*Math.sin(r)+y*Math.cos(r));
        }

        private vec add(vec vec){
            return new vec(x+vec.x,y+vec.y);
        }

        private double area(vec vec){
            return ((vec.y+y)*(vec.x-x))/2;
        }
    }

    private static vec start = new vec(10001,10001);
    private static int si = 0;

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        for(int i = 0; i<N;i++){
            boardWrap(scan);
        }
    }

    static class SortbyPol implements Comparator<vec>
    {
        // Used for sorting in ascending polinominal order
        // with respect to start
        public int compare(vec a, vec b)
        {
            int order = counterClockW(start, a, b);
            if(order ==0) {
                return sqrDist(a,b);
            }
            else return order;
        }
    }

    //calculating the square distance from start to a and b and returning 1 if a is closer than b
    private static int sqrDist(vec a, vec b) {
        double adx = start.x -a.x;
        double ady = start.y-a.y;
        double ad = adx * adx + ady * ady;

        double bdx = start.x -b.x;
        double bdy = start.y-b.y;
        double bd = bdx * bdx + bdy * bdy;
        if(ad<bd)
            return 1;
        else if (bd<ad)
            return -1;
        else
            return 0;
    }

    private static void boardWrap(Scanner scan) {
        int n = scan.nextInt();
        vec[] vectors=new vec[n*4];

        double boardSpace= 0;
        for (int i = 0;i<n;i++){
            double x = scan.nextDouble(), y = scan.nextDouble(),w=scan.nextDouble(),
                    h = scan.nextDouble(), v = scan.nextDouble();

            vec corner = new vec(w/2, h/2).rotate(v);
            vec toCor = new vec(x,y).add(corner);
            vectors[i*4] = toCor;
            if(toCor.compareTo(start) <0) {
                start = toCor;
                si = i*4;
            }
            corner = new vec(-w/2, h/2).rotate(v);
            toCor = new vec(x,y).add(corner);
            double x1 = toCor.x;
            double y1 = toCor.y;
            vectors[i*4+1] = toCor;
            if(toCor.compareTo(start) <0) {
                start = toCor;
                si = i*4+1;
            }
            corner = new vec(-w/2, -h/2).rotate(v);
            toCor = new vec(x,y).add(corner);
            vectors[i*4+2] = toCor;
            if(toCor.compareTo(start) <0) {
                start = toCor;
                si = i*4+2;
            }
            corner = new vec(w/2, -h/2).rotate(v);
            toCor = new vec(x,y).add(corner);
            vectors[i*4+3] = toCor;
            if(toCor.compareTo(start) <0) {
                start = toCor;
                si = i*4+3;
            }
            boardSpace += w*h;
        }
        double hullArea = GSArea(vectors, n*4);
        System.out.printf("%.1f %s\n", Math.abs(boardSpace/hullArea*100), "%");
    }

    private static double GSArea(vec[] vectors, int i) {
        Stack<vec> hull = new Stack();

        //moving the lowest point to 0 index
        vec tmp = vectors[si];
        double x1 = tmp.x;
        double y1 = tmp.y;
        double x2 = vectors[0].x;
        double y2 = vectors[0].y;
        vectors[si] = vectors[0];
        vectors[0] = tmp;

        Arrays.sort(vectors, 1,i, new SortbyPol());

//        for (int j = 0;j<i; j++){
//            System.out.println(vectors[j].x+" " + vectors[j].y);
//        }

        hull.push(vectors[0]);
        hull.push(vectors[1]);
        hull.push(vectors[2]);
        for (int k = 3; k< i;k++) {
            vec top = hull.pop();
            while (counterClockW(hull.peek(), top, vectors[k]) != -1){
                top = hull.pop();
            }
            hull.push(top);
            hull.push(vectors[k]);
        }

        hull.push(start);

//        System.out.println("hull:");
//        for (vec vec:hull){
//            System.out.println(vec.x +" "+ vec.y);
//        }
        double area = 0;

        while(hull.size()>1) {
            vec first = hull.pop();
            vec secnd = hull.peek();
            area += first.area(secnd);
        }
        return area;
    }

    private static int counterClockW(vec a, vec b, vec c) {
        double ar = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        if(ar > 0)
            return 1; //counterclockwise
        else if(ar < 0)
            return -1; //clockwise
        else
            return 0; //collinear
    }
}
