#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> sides) {
    
    int sum = accumulate(sides.begin(), sides.end(), 0);
    int max_value = *max_element(sides.begin(), sides.end());
    
    if(max_value < sum - max_value){
        return 1;
    }
    
    return 2;
    
}