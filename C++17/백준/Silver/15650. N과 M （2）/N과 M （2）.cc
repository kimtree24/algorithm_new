#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> &nums, vector<int> &path, int n, int m, int start){
    if(path.size() == m){
        for(int i:path){
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = start; i <= n-(m-path.size()); i++){
        path.push_back(nums[i]);
        dfs(nums, path, n, m, i + 1);
        path.pop_back();
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> nums;
    for(int i = 1; i <= n; i++){
        nums.push_back(i);
    }
    
    vector<int> path;
    
    dfs(nums, path, n, m, 0);
    
    return 0;
    
}