#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    map<string, int> mp;
    
    for(string pa : participant){
        mp[pa] += 1;
    }
    
    for(string com : completion){
        mp[com] -= 1;
    }
    
    for(auto &p : mp){
        if(p.second > 0){
            return p.first;
        }
    }
    
    return "";
}