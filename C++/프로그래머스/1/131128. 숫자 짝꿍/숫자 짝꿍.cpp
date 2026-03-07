#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string X, string Y){
    string ans;
    map<char, int> xc;
    map<char, int> yc;
    
    for(char x:X){
        xc[x] += 1;
    }
    for(char y:Y){
        yc[y] += 1;
    }
    
    string digit = "0123456789";
    map<char, int> p;
    for(char d:digit){
        if(xc.find(d) != xc.end() && yc.find(d) != yc.end()){
            int cnt = min(xc[d], yc[d]);
            ans += string(cnt, d);
        }
    }
    
    if(ans == ""){
        return "-1";
    }
    
    reverse(ans.begin(), ans.end());
    
    if(ans[0] == '0'){
        return "0";
    }
    
    return ans;
}