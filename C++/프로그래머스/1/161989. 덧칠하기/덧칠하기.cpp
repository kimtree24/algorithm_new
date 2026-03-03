#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section){
    int ans = 0;
    
    int cur = 1;
    for(int e_sec:section){
        if(cur <= e_sec){
            ans += 1;
            cur = max(cur, e_sec + m);
        }
    }
    
    return ans;
}