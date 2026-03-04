#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets){
    map<char, int> m;
    vector<int> ans;
    for(const string key:keymap){
        int cnt = 1;
        for(char c:key){
            if(m.find(c) != m.end()){
                m[c] = min(cnt, m[c]);
            }else{
                m[c] = cnt;
            }
            cnt += 1;
        }
    }
    
    for(const string &target:targets){
        bool cant = false;
        int cnt = 0;
        for(char c:target){
            if(m.find(c) == m.end()){
                ans.push_back(-1);
                cant = true;
                break;
            }else{
                cnt += m[c];
            }
        }
        if(!cant){
            ans.push_back(cnt);
        }
    }
    return ans;
}