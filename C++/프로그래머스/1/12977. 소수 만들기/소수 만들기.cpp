#include <cmath>
#include <vector>

using namespace std;

bool is_prime(int num){
    for(int i = 2; i <= sqrt(num); i++ ){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums){
    int ans = 0;
    int len = nums.size();
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            for(int k = j + 1; k < len; k++){
                if(is_prime(nums[i] + nums[j] + nums[k])){
                    ans += 1;
                }
            }
        }
    }
    
    return ans;
}