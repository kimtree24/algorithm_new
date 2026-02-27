# include<algorithm>

using namespace std;

long long solution(int a, int b){
    long long ans = 0;
    
    int lo = min(a, b);
    int hi = max(a, b);
    
    for(int i = lo; i <= hi; i++){
        ans += i;
    }
    
    return ans;
}