#include <iostream>
#include <map>

using namespace std;


int main() {
    int n;
    cin >> n;

    std::map<std::string, int> strMap;
    for (int i = 0; i < n; ++i) { //O(n) kjøretid.
        string s;
        cin >> s;
        if(strMap.find(s) == strMap.end())
            cout << 0 << endl;
        else
            cout << strMap.find(s)->second << endl;

        for (int j = 1; j <= s.length(); ++j) { //O(32) kjøretid
            string sub = s.substr(0,j);
            if(strMap.find(sub)!=strMap.end())
                strMap.find(sub)->second +=1;
            else
                strMap.insert(make_pair(sub, 1));
        }

    }
}
