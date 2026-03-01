#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score){
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int cur_score: score){
        if(pq.size() < k){
            pq.push(cur_score);
        }else{
            if(cur_score > pq.top()){
                pq.pop();
                pq.push(cur_score);
            }
        }
        ans.push_back(pq.top());
    }
    
    return ans;
}