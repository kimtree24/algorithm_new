#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    
    int ans = 0;
    
    for(string c1: s1){
        for(string c2 : s2){
            if(c1 == c2){
                ans += 1;
            }
        }
    }
    
    return ans;
    
}