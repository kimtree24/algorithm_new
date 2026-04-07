#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int ans = 0;
    
    string s_n = to_string(n);
    
    for(char c : s_n){
        ans += c - '0';
    }
    
    return ans;
    
}