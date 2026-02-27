long long solution(int price, int money, int count){
    
    long long total = 0;
    
    for(int i = 1; i <= count; i++){
        total += i*price;
    }
    
    if((total - money) <= 0){
        return 0;
    }
    
    return total - money;
}