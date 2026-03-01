#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands){
    vector<int> ans;
    
    for(vector<int> command:commands){
        vector<int> target(
            array.begin() + (command[0] - 1),
            array.begin() + (command[1] - 1) + 1
        );
        
        priority_queue<int, vector<int> ,greater<int>> pq(target.begin(), target.end());
        
        int each_num;
        
        for(int i = 0; i < command[2] - 1; i++ ){
            pq.pop();
        }
        
        ans.push_back(pq.top());
        
    };
    
    return ans;
}