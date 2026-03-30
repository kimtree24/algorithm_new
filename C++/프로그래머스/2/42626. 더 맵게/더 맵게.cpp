#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int each:scoville){
        pq.push(each);
    }
    
    while(pq.top() < K){
        if(pq.size() >= 2){
            int pq_first = pq.top();
            pq.pop();
            int pq_second = pq.top();
            pq.pop();
        
            int new_food = pq_first + (pq_second * 2);
        
            pq.push(new_food);
            answer += 1;
        }
        else{
            return -1;
        }

    }
    
    return answer;
}