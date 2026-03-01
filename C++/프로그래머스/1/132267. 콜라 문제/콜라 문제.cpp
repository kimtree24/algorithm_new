int solution(int a, int b, int n){
    int ans = 0;
    int remain = n;
    
    while(remain >= a){
        int cur_get = ((int) remain / a) * b; // 이번에 새로 받는 콜라
        ans += cur_get; // 새로 받은 콜라 ans에 더해야 해
        remain %= a; // 교환하고 남은 콜라
        remain += cur_get; // 이번에 받은 것도 빈병으로 됨
    }
    
    return ans;
}