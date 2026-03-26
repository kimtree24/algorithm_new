#include <vector>

using namespace std;

void dfs(vector<int> &numbers, int target, int cur, vector<int> &ans, int idx){
    // 탈출
    if(idx == numbers.size() && cur == target){
        ans[0] += 1;
        return;
    }

    
    if(idx < numbers.size()){
        // 다음 마이너스 가지 수행
        cur -= numbers[idx];
        dfs(numbers, target, cur, ans, idx + 1);
        cur += numbers[idx];
    
        // 다음 플러스 가지 수행
        cur += numbers[idx];
        dfs(numbers, target, cur, ans, idx + 1);
        cur -= numbers[idx];
    }
    
    return;
    
}

int solution(vector<int> numbers, int target){
    int cur = 0;
    vector<int> ans = {0};
    
    dfs(numbers, target, cur, ans, 0);
    
    return ans[0];
        
}