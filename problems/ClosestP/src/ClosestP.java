import java.util.Scanner;

public class ClosestP {
    private class Point{
        double x,y;
        public Point(double x, double y){
            this.x = x;
            this.y = y;
        }
    }

    private class DoublePoint implements Comparable<DoublePoint>{
        private Point a,b;
        private double d;

        public DoublePoint(Point a, Point b){
            this.a = a;
            this.b = b;
        }
        public DoublePoint(Point a, Point b, double d){
            this.a = a;
            this.b = b;
            this.d = d;
        }

        public void setDist(double d){
            this.d = d;
        }

        @Override
        public int compareTo(DoublePoint dp) {
            if(d > dp.d)
                return 1;
            else if(d < dp.d)
                return -1;
            else
                return 0;
        }
    }
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = 0;
        while(scan.hasNext()){
            n = scan.nextInt();
            
        }




    }
}
