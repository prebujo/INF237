package Oddities;

import java.util.Scanner;

public class Oddities {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        for (int i = 0; i<n;i++){
            int tall = scan.nextInt();
            if ((tall % 2 != 0))
                System.out.println(tall + " is odd");
            else
                System.out.println(tall + " is even");
        }
    }
}

