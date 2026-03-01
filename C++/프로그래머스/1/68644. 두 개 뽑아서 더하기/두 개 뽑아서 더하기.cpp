#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

void dfs(
    const vector<int> &target,
    vector<vector<int>> &combi,
    vector<int> &path,
    int n,
    int start,
    int r
        )    
{
    if(path.size() == r){
        combi.push_back(path);
        return;
    }
    
    for(int i = start; i <= n - (r - path.size()); i++){
        path.push_back(target[i]);
        dfs(target, combi, path, n, i + 1, r);
        path.pop_back();
    }
    return;
}


vector<int> solution(vector<int> numbers){
    vector<int> ans;
    set<int> s_num;
    
    // 조합 만들기
    vector<vector<int>> combi;
    vector<int> path;
    int n = numbers.size();
    
    dfs(numbers, combi, path, n, 0, 2);
    
    for(const vector<int> &e_combi:combi){
        int each_sum = accumulate(e_combi.begin(), e_combi.end(), 0);
        s_num.insert(each_sum);
    }
    
    for(const int each_sum: s_num){
        ans.push_back(each_sum);
    }
    
    sort(ans.begin(), ans.end());
    
    return ans;
}