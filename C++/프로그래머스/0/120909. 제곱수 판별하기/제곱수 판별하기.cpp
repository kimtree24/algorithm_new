#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int sq = sqrt(n);
    
    if(sq * sq == n){
        return 1;
    }
    return 2;
}