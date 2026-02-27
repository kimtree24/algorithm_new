long long task(long long num){
    if(num % 2 == 0)
        return num / 2;
    else
        return num * 3 + 1;
}

int solution(int num){
    if(num == 1)
        return 0;

    int cnt = 0;
    
    long long n_num = (long long)num;

    while(cnt < 500){
        n_num = task(n_num);
        cnt++;

        if(n_num == 1)
            return cnt;
    }

    return -1;
}