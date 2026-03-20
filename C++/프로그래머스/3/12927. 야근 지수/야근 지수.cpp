#include <queue>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works){
    long long ans = 0;
    
    // 큐에 넣기
    priority_queue<int> pq;
    for(int work:works){
        pq.push(work);
    }
    
    while(n > 0){
        if(pq.top() <= 0){
            break;
        }
        int target = pq.top() - 1;
        pq.pop();
        pq.push(target);
        n -= 1;
    }
    
    while(!pq.empty()){
        ans += pq.top() * pq.top();
        pq.pop();
    }
    
    return ans;
}