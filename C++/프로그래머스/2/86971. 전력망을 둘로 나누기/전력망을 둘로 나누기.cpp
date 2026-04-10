#include <string>
#include <vector>
#include <deque>

using namespace std;

int bfs(int start, int a, int b, vector<vector<int>> &graph, int n){
    vector<bool> visited(n+1, false);
    deque<int> dq;
    
    dq.push_back(start);
    visited[start] = true;
    
    int cnt = 1;
    
    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_front();
        
        for(int next : graph[cur]){
            if((cur == a && next == b) || (cur == b && next == a)){
                continue;
            }
            
            if(!visited[next]){
                visited[next] = true;
                dq.push_back(next);
                cnt++;
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    
    vector<vector<int>> graph(n + 1);
    
    for(auto &w : wires){
        graph[w[0]].push_back(w[1]);
        graph[w[1]].push_back(w[0]);
    }
    
    int ans = n;
    
    for(auto &w : wires){
        int cnt = bfs(1, w[0], w[1], graph, n);
        
        int diff = abs(cnt - (n - cnt));
        
        ans = min(ans, diff);
    }
    
    return ans;
    
}