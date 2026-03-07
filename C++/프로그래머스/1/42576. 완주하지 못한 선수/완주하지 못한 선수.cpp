#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    
    for(string p:participant){
        m[p] += 1;
    }
    
    for(string c:completion){
        m[c] -= 1;
    }
    
    for(const auto &p:m){
        if(p.second != 0){
            return p.first;
        }
    }
}