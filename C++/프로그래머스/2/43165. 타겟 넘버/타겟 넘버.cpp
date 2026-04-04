#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> &numbers, int target, int cur, int idx, vector<int> &ans){
    if(idx == numbers.size()){
        if(cur == target){
            ans[0] += 1;
        }
        return;
    }
    
    dfs(numbers, target, cur + numbers[idx], idx + 1, ans);
    dfs(numbers, target, cur - numbers[idx], idx + 1, ans);
    
}

int solution(vector<int> numbers, int target) {
    
    vector<int> ans(1,0);
    
    dfs(numbers, target, 0, 0, ans);
    
    return ans[0];
    
}