#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int ans = 0;
    deque<int> bridge(bridge_length, 0);
    
    int fin = 0;
    int cur_bw = 0; // 지금 다리 위 무게
    int truck_idx = 0;
    
    while(fin < truck_weights.size()){
        int out = bridge.front();
        bridge.pop_front();
        
        if(out != 0){
            cur_bw -= out;
            fin += 1;
        }
        
        if(truck_idx < truck_weights.size()){
            int next = truck_weights[truck_idx];
            if(cur_bw + next <= weight){
                bridge.push_back(next);
                cur_bw += next;
                truck_idx += 1;
            }else{
                bridge.push_back(0);
            }
        }
        ans += 1;
    }
    return ans;
}