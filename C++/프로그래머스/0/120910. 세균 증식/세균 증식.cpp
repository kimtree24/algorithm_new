#include <string>
#include <vector>

using namespace std;

int solution(int n, int t) {
    
    int ans = n;
    
    while(t > 0){
        ans *= 2;
        t--;
    }
    
    return ans;
    
}