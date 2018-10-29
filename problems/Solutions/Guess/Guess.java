package Guess;

import java.util.Scanner;

public class Guess {
    public static void main (String[] args){
        Scanner scan = new Scanner(System.in);
        int guess = 500;
        int hi = 1000;
        int low = 1;
        String ans = "";
        while(ans != "correct") {
            System.out.println(guess);
            ans = scan.nextLine();
            switch (ans) {
                case "lower":
                    hi = guess-1;
                    guess = (hi + low)/2;
                    break;
                case "higher":
                    low = guess + 1;
                    guess = (low + hi)/2;
                    break;
                case "correct":
                    System.exit(0);
                    break;
            }
        }

    }
}
