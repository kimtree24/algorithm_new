#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index){
    vector<bool> cant(26, false);
    for(char ch:skip){
        cant[ch - 'a'] = true;
    }
    
    string allowed;
    for(char c = 'a'; c <= 'z'; c++){
        if(!cant[c-'a']){
            allowed.push_back(c);
        }
    }
    
    int len = allowed.size();
    
    vector<int> pos(26, -1);
    for(int i = 0; i < len; i++){
        pos[allowed[i] - 'a'] = i;
    }
    
    for(char &c : s){
        int p = pos[c - 'a'];
        int np = (p + index) % len;
        c = allowed[np];
    }
    return s;
}