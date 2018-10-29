import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;



public class NestedDolls {
    public static void main(String[] args){
        int N = 0;
        int T = 0;

        Scanner scan = new Scanner;
        T = scan.nextInt();

        for (int i = 0; i < T;i++ ){
            N = scan.nextInt();
            System.out.println(nested(N));
        }

    }

    private static long nested(int n) {
        List<Pair<Integer, Integer>> dolls;   // list for input of dolls
        List<Pair<Integer, Integer>> bdolls;  //list of dolls (only biggest doll) outside the main doll
        Scanner scan = new Scanner;
        for (int i = 0; i < n;i++){
            int a = scan.nextInt();
            int b = scan.nextInt();
            Pair<Integer,Integer> doll = new Pair<>(a, b);
            dolls.add(doll);
        }
        dolls.sort(comparator);

    }
}

class Pair<A extends Comparable<A>, B extends Comparable<B>> {
    private A a;
    private B b;

    public Pair(A a, B b) {
        this.a = a;
        this.b = b;
    }
    public A getA() {return a;}
    public B getB() {return b;}
    @Override
//    public int compareTo(A a, A b){
//        return (a>b);
    }
}