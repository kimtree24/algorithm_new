# include <vector>

using namespace std;

long long solution(vector<int> absolutes, vector<bool> signs){
    long long ans = 0;
    
    int nums = absolutes.size();
    
    for(int i = 0; i < nums; i++){
        if (signs[i]){
            ans += absolutes[i];
        }else{
            ans -= absolutes[i];
        }
    }
    
    return ans;
}