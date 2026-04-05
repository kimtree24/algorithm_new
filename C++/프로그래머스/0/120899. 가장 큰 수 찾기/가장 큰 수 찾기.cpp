#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    
    int v = 0;
    int idx = -1;
    
    vector<int> ans(2,0);
    
    for(int i = 0; i < array.size(); i++){
        if(v < array[i]){
            v = array[i];
            idx = i;
        }
    }
    
    ans[0] = v;
    ans[1] = idx;
    
    return ans;
    
}