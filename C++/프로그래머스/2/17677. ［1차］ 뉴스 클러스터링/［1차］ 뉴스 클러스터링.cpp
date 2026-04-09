#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string> make(string s){
    vector<string> res;
    
    for(int i = 0; i < s.size() - 1; i++){
        char a = tolower(s[i]);
        char b = tolower(s[i + 1]);
        
        if(isalpha(a) && isalpha(b)){
            string temp = "";
            temp += a;
            temp += b;
            res.push_back(temp);
        }
    }
    
    return res;
}

int solution(string str1, string str2) {
    
    vector<string> v1 = make(str1);
    vector<string> v2 = make(str2);
    
    map<string, int> m1, m2;
    
    for(auto &s : v1){
        m1[s]++;
    }
    for(auto &s: v2){
        m2[s]++;
    }
    
    int inter = 0;
    int uni = 0;
    
    map<string, int> all = m1;
    
    for(auto &p : m2) all[p.first]++;
    
    for(auto &p : all){
        string key = p.first;
        
        int c1 = m1[key];
        int c2 = m2[key];
        
        inter += min(c1, c2);
        uni += max(c1, c2);
    }
    
    if(uni == 0) return 65536;
    
    return (int)((double)inter / uni * 65536);
    
}