#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void dfs(vector<int> &nums,
         vector<int> &path,
         int n,
         int m,
         int start){
    // 탈출조건
    if(path.size() == m){
        for(int x : path){
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = start; i < n; i++){
        path.push_back(nums[i]);
        dfs(nums, path, n, m, i);
        path.pop_back();
    }
}

int main(){
    int n, m;
    
    cin >> n >> m;
    vector<int> nums;
    
    for(int t = 0; t < n; t++){
        int k;
        cin >> k;
        nums.push_back(k);
    }
    
    sort(nums.begin(), nums.end());
    
    vector<int> path;
    
    dfs(nums, path, n, m, 0);
    
}