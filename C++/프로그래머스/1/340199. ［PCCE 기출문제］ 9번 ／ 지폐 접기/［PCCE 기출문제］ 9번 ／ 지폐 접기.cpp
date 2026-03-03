#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill){
    int ans = 0;
    
    int max_w = max(wallet[0], wallet[1]);
    int min_w = min(wallet[0], wallet[1]);
    int max_b = max(bill[0], bill[1]);
    int min_b = min(bill[0], bill[1]);
    
    while(max_w < max_b || min_w < min_b){
        ans += 1;
        // 반 접을 것
        max_b /= 2;
        
        // 갱신
        int new_max = max(max_b, min_b);
        int new_min = min(max_b, min_b);
        
        max_b = new_max;
        min_b = new_min;
        
    }
    
    return ans;
}