//
// Created by preben on 06.02.18.
//

#include <iostream>
#include <algorithm>

void assignBox(double n, double i);

bool workingSolution(double guess, double input[]);

using namespace std;

double n;
double b;

int main() {

    while(true){
        cin >> n;
        cin >> b;
        if(n==-1 && b == -1) //breaker når input er -1 -1
            break;
        assignBox(n,b); //kaller assignboks funksjonen til input blir -1 -1
    }
    return 0;
}

void assignBox(double n, double b){
//    double tot = 0;
    double input[(int)n];
//    double maxim = 0;
//    double minim = 99999999999.0;
    for (int j = 0; j < n ; ++j) { // tar input fra terminalen i array input[]
        cin >> input[j];
//        tot += input[j];    //oppdaterer total antall mennesker
//        if (input[j]>maxim)  //oppdaterer maximum verdi. trenger egentlig ikke denne...
//            maxim = input[j];
//        if(input[j]<minim)
//            minim = input[j];
    }
    sort(input, input + (int)n);


    double can_do = b/n;     //i want to find some solution between what i can do (distribute evenly) and
    double cant_do = b;      //what i cant do, give all boxes to the highest populated city

    while(cant_do - can_do > 1){
        double guess = round((can_do+cant_do)/2);
        if (workingSolution(guess, input))
            can_do = guess;
        else
            cant_do = guess;
    }
    cout << round(input[(int)(n-1)] / can_do) << endl;

}

bool workingSolution(double guess, double input[]) {
    long r = b-guess;
    for (int i = 0; i < n-1; ++i) {
        long t = 1; //det skal tildeles minst en fra reststabelen så lenge til hver av de mindre byene
        while (true) {
            r -= 1; //trekker ifra en på reststabelen
            if (input[(int)(n - 1.0)] / guess >= input[i] / t) //må være høyere gjennomsnitt i den største byen enn resten, ellers kan jeg fordele bedre.
                break;
            else
                t++; //øker t som blir tildelt hvis resultatet er værre enn i største by.
        }
        if (r<0)
            break;
    }
    return (r >= 0);
}
