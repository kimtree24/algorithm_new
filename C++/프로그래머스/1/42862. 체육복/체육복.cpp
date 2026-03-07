#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> st(n + 1, 0);
    
    for(int e:lost){
        st[e] -= 1;
    }
    
    for(int e:reserve){
        st[e] += 1;
    }
    
    for(int i = 1; i <= n; i++){
        if(st[i] == -1){
            if(i > 1 && st[i - 1] == 1){
                st[i] += 1;
                st[i - 1] -= 1;
            }else if(i < n && st[i + 1] == 1){
                st[i] += 1;
                st[i + 1] -= 1;
            }
        }
    }
    
    int ans = 0;
    
    for(int i = 1; i <= n; i++){
        if(st[i] >= 0){
            ans += 1;
        }
    }
    
    return ans;
}