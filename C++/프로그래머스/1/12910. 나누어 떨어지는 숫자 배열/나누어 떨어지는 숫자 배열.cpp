# include <vector>
# include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor){
    vector<int> ans;
    
    for(int element : arr){
        if(element % divisor == 0){
            ans.push_back(element);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    if(ans.empty()){
        return {-1};
    }
    
    return ans;
}