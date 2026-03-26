#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times){
    
    long long left = 1;
    long long right = (long long)*max_element(times.begin(), times.end()) * n;
    long long ans = 0;
    
    while(left <= right){
        long long mid = (left + right) / 2;
        
        long long total = 0;
        for(int t : times){
            total += mid / t;
        }
        
        if(total >= n){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
        
    }
    return ans;
}