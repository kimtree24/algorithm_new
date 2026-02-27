bool solution(int x){
    
    int sum = 0;
    int cur = x;
        
    while (cur > 0){
        sum += cur % 10;
        cur /= 10;
    }
    return x % sum == 0;
}