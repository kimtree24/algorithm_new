#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    vector<int> ans(2,0);
    
    for(int i = yellow; i >= sqrt(yellow); i--){
        
        if(yellow % i != 0){
            continue;
        }else{
            int bx = i + 2;
            int by = yellow / i + 2;
            int bcount = bx * by - yellow;
            
            if(bcount == brown){
                ans[0] = bx;
                ans[1] = by;
            }
        }
    }
    
    return ans;
    
}