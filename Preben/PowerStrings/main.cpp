#include <iostream>
using namespace std;
int main() {
    string s;
    while(cin >> s){
        //stopping if input is equal to .
        if(s[0] == '.')
            break;
        //length of string
        int length = s.size();
        //looping through each character
        for (int i = 1; i <=s.size() ; ++i) { //O(n) running time
            //if the length of the string modulo the characters position is not 0 I continue loop
            if(length%i != 0)
                continue;
            else { //if not I set equal to true
                bool equal = true;
                //checking all characters with an interval of i if they are not equal to each other
                for (int j = i; j <s.size() ; ++j) { //O(n) running time
                    // if at some point they are not equal I will break and try next interval i
                    if(s[j] != s[j-i]){
                        equal = false;
                        break;
                    }
                }
                //If I make it past with all characters of i interval being equal I have found the n = length/i
                // so that a^n = s
                if(equal) {
                    int n = length / i;
                    cout << n << endl;
                    break;
                }
            }
        }
        //Total running time is O(n^2)
    }
}