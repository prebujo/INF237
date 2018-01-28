package SevenWonders;

import java.util.Scanner;

public class SevenWonders {
    public static void main(String[] args) {
        int t = 0;
        int c = 0;
        int g = 0;
        Scanner scan = new Scanner(System.in);
        String cards = scan.nextLine();
        char[] ccards = cards.toCharArray();
        for (int i = 0; i < ccards.length; i++) {
            switch (ccards[i]) {
                case 'T':
                    t++;
                    break;
                case 'C':
                    c++;
                    break;
                case 'G':
                    g++;
                    break;
            }
        }
        int sum = (int)Math.pow(t,2) + (int)Math.pow(c,2) + (int)Math.pow(g, 2) + 7*Math.min(t,Math.min(g,c));
        System.out.println(sum);
    }
}
