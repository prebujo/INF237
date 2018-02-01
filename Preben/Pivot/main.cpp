#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) {
        cin>>array[i];
    }
    int max = array[0];
    int output;
    for (int j = 0; j < n; ++j) {
        if (array[j] > max){
            max = array[j];
            bool partition = true;
            for (int i = j+1; i < n; ++i) {
                if (array[i]<array[j]) {
                    partition = false;
                    break;
                }
            }
            if(partition)
                output +=1;
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}