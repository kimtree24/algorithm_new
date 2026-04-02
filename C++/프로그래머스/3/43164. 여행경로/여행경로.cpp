#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(vector<vector<string>> &ans,
    vector<string> &path, 
         vector<vector<string>> &tickets, 
         vector<int> &visited, 
         string cur){
    if(path.size() == tickets.size() + 1){
        ans.push_back(path);
        return;
    }
    
    for(int i = 0; i < tickets.size(); i++){
        if(visited[i] == 0 && tickets[i][0] == cur){
            visited[i] = 1;
            path.push_back(tickets[i][1]);
            dfs(ans, path, tickets, visited, tickets[i][1]);
            path.pop_back();
            visited[i] = 0;
        }
    }
    
    return;
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<vector<string>> ans;
    vector<int> visited(tickets.size(), 0);
    vector<string> path;
    
    // 정렬
    sort(tickets.begin(), tickets.end());
    
    for(int i = 0; i < tickets.size(); i++){
        cout << tickets[i][0] << " : " << tickets[i][1] << "\n";
    }
    
    path.push_back("ICN");
    
    dfs(ans, path, tickets, visited, "ICN");
    
    
    return ans[0];
}