#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int ans = 0;
    
    for(int i = 2; i <= n; i++){
        if(i%2 == 0){
            ans += i;
        }
    }
    
    return ans;
    
}