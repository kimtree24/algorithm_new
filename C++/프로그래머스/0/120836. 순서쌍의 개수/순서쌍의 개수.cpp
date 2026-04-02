#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int mid = sqrt(n);
    
    for(int i = 1; i <= mid; i++){
        if(n%i == 0){
            answer += 1;
        }
    }
    
    answer *= 2;
    
    if(mid * mid == n){
        answer -= 1;
    }
    
    
    return answer;
}