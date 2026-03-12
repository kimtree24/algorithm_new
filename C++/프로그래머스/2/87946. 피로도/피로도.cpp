#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& dungeons, vector<bool>& visited, int cnt, int& ans, int k){
    // 최대값 갱신
    ans = max(ans, cnt);
    
    for(int i = 0; i < dungeons.size(); i++){
        if(!visited[i] && k >= dungeons[i][0]){
            visited[i] = true;
            dfs(dungeons, visited, cnt+1, ans, k-dungeons[i][1]);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons){
    int ans = 0;
    vector<bool> visited(dungeons.size(), false);
    
    dfs(dungeons, visited, 0, ans, k);
    
    return ans;
}