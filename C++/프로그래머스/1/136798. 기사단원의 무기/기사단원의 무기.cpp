#include <vector>
#include <iostream>

using namespace std;

void get_yaksu(vector<int> &yaksu, int number){
    for(int i = 1; i <= number; i++){
        for(int j = i; j <= number; j+=i){
            yaksu[j] += 1;
        }
    }
}

int solution(int number, int limit, int power){
    int result = 0;
    
    // 최대 숫자까지 약수 개수 구하기
    vector<int> yaksu(number + 1, 0);
    get_yaksu(yaksu, number);
    
    for(int i = 1; i <= number; i++){
        if(yaksu[i] > limit){
            result += power;
        }else{
            result += yaksu[i];
        }
    }
    
    return result;
}