# include <vector>

using namespace std;

int solution(int left, int right){
    vector<int> num_yakso(right + 1, 0);
    
    for(int i = 1; i < right + 1; i++){
        for(int j = i; j < right + 1; j+=i){
            num_yakso[j] += 1;
        }
    }
    
    int ans = 0;
    
    for(int i = left; i <= right; i++){
        if(num_yakso[i] % 2 == 0){
            ans += i;
        }else{
            ans -= i;
        }
    }
    
    return ans;
    
}