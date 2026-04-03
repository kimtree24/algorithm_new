#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers) {
    priority_queue<int> pq(numbers.begin(), numbers.end());
    
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    
    return first * second;
       
}