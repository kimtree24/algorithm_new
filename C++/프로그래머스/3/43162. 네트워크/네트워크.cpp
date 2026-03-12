#include <vector>

using namespace std;

void dfs(vector<vector<int>> &computers, vector<bool> &visited, int node){
    visited[node] = true;
    
    for(int i = 0; i < computers.size(); i++){
        if(computers[node][i] == 1 && !visited[i]){
            dfs(computers, visited, i);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers){
    vector<bool> visited(n, false);
    int ans = 0;
    
    for(int i = 0; i < computers.size(); i++){
        if(!visited[i]){
            dfs(computers, visited, i);
            ans++;
        }
    }
    return ans;
}