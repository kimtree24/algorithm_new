int solution(int n){
    int ans = 0;
    
    int cur = n;
    
    while (cur > 0){
        ans += cur % 10;
        cur /= 10;
    }
    
    return ans;
}