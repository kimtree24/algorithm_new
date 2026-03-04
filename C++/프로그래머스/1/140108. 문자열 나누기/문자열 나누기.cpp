#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    
    int same = 0;
    int diff = 0;
    
    int ans = 0;
    char f_ch = s[0];
    
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch == f_ch){
            same += 1;
        }else{
            diff += 1;
        }
        
        if(same == diff){
            ans += 1;
            same = diff = 0;
            f_ch = s[i+1];
        }
    }
    
    if(same != diff){
        ans += 1;
    }
    return ans;
    
}