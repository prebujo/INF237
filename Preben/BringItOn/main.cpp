#include <iostream>

using namespace std;

bool prefix(const string& a, const string& b);

int compare(const string&

int main() {
    const string t1 = "test";
    const string t2 = "testing";
    const string t3 = "hel";
    const string t4 = "hello world";
    cout << prefix(t1,t2) << "," << prefix(t2,t1) << endl;
    cout << prefix(t3,t4) << "," << prefix(t4,t3) << endl;
    cout << prefix(t1,t4) << "," << prefix(t4,t1) << endl;
    cout << prefix(t1,t3) << "," << prefix(t3,t1) << endl;

}

bool prefix(const std::string& a, const std::string& b) {
    if (a.size() > b.size()) {
        return a.substr(0,b.size()) == b;
    }
}