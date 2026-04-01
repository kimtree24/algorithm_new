#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    
    int ans = n / slice;
    double rest = n % slice;
    
    if(rest != 0.0){
        return ans += 1;
    }
    return ans;
    
}