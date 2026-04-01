#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    
    vector<string> say = {"aya", "ye", "woo", "ma"};
    
    int ans = 0;
    
    for(string str:babbling){
        int idx = 0;
        bool flag = true;
        
        while(idx < str.size()){
            bool matched = false;
            
            for(string w:say){
                if(str.substr(idx, w.size()) == w){
                    idx += w.size();
                    matched = true;
                    break;
                }
            }
            
            if(!matched){
                flag = false;
                break;
            }
            
        }
        if(flag){
            ans += 1;
        }
    }
    
    return ans;
    
}