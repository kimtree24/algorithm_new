#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> &nums, vector<int> &path, int n, int m){
    if(path.size() == m){
        for(int i = 0; i < path.size(); i++){
            cout << path[i] << " ";
        }
        
        cout << "\n";
        
        return;
    }
    
    for(int i = 0; i < n; i++){
        path.push_back(nums[i]);
        dfs(nums, path, n, m);
        path.pop_back();
    }
    
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> nums;
    for(int i = 1; i <= n; i++){
        nums.push_back(i);
    }
    
    vector<int> path;
    
    dfs(nums, path, n, m);
    
    return 0;
    
}