import java.math.BigInteger;
import java.util.Scanner;

public class Nine {
    private static final BigInteger nin = BigInteger.valueOf(9);
    private static final BigInteger egt = BigInteger.valueOf(8);
    private static final BigInteger m = BigInteger.valueOf(1000000007);

    public static void main(String args[]){
        BigInteger d;

        Scanner scan = new Scanner(System.in);
        int T;
        T = scan.nextInt();

        while(T>0){
            d = BigInteger.valueOf(scan.nextLong()-1);
            System.out.println(egt.multiply(nin.modPow(d,m)).mod(m));
            T--;
        }
    }
}
