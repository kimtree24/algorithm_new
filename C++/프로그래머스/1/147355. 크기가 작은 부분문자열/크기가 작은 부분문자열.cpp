#include <string>
#include <iostream>

using namespace std;

int solution(string t, string p){
    int ans = 0;
    
    int len_t = t.size();
    int len_p = p.size();
    
    long long digit_p = stoll(p);
    
    for(int i = 0; i < len_t - len_p + 1; i++){
        string sub_s = t.substr(i, len_p);
        long long digit_sub_s = stoll(sub_s);
        
        if(digit_sub_s <= digit_p){
            ans += 1;
        }
    }
    
    return ans;
}