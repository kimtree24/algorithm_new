#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    double rest = n % 7;
    int ans = n / 7;
    if(rest == 0.0){
        return ans;
    }else{
        return ans + 1;
    }
}