#include <vector>
#include <map>
#include <set>

using namespace std;

int solution(vector<int> topping){
    int ans = 0;
    map<int, int> right;
    
    for(int t:topping){
        right[t]++;
    }
    set<int> left;
    for(int i = 0; i < topping.size(); i++){
        int cur = topping[i];
        
        right[cur]--;
        if(right[cur] == 0){
            right.erase(cur);
        }
        
        left.insert(cur);
        
        if(left.size() == right.size()){
            ans++;
        }
    }
    
    return ans;
}