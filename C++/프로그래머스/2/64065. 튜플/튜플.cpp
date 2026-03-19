#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string s){
    map<int, int> m;
    
    string num = "";
    
    for(char c : s){
        if(isdigit(c)){
            num += c;
        }
        else{
            if(!num.empty()){
                m[stoi(num)] += 1;
                num = "";
            }
        }
    }
    
    vector<pair<int, int>> v;
    
    for(auto p : m){
        v.push_back({p.first, p.second});
    }
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.second > b.second;
    });
    
    vector<int> ans;
    
    for(auto p:v){
        ans.push_back(p.first);
    }
    
    return ans;
    
    
}