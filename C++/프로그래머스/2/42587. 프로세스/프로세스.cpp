#include <vector>
#include <queue>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location){
    int ans = 0;
    priority_queue<int> pq;
    // 처음 타겟 기억
    deque<pair<int, int>> tdq;
    
    for(int priority : priorities){
        pq.push(priority);
    }
    
    for(int i = 0; i < priorities.size(); i++){
        if(i == location){
            tdq.push_back({priorities[i], 1});
        }else{
            tdq.push_back({priorities[i], 0});
        }
    }
    
    while(true){
        if(pq.top() == tdq.front().first){
            if(tdq.front().second == 1){
                return ans+1;
            }
            else{
                pq.pop();
                tdq.pop_front();
                ans+=1;
            }
        }
        else{
            auto temp = tdq.front();
            tdq.push_back(temp);
            tdq.pop_front();
        }
    }
    
    return ans;
}