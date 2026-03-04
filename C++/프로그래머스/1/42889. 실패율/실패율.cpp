#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> cnt(N + 2, 0);
    for(int s:stages){
        cnt[s] += 1;
    }
    
    int remaining = stages.size();
    vector<pair<double, int>> fail;
    
    for(int i = 1; i <= N; i++){
        double rate = 0.0;
        if(remaining > 0){
            rate = (double)cnt[i] / remaining;
        }
        fail.push_back({rate, i});
        remaining -= cnt[i];
    }
    
    sort(fail.begin(), fail.end(), [](const auto &a, const auto &b){
        if(a.first == b.first){
            return a.second < b.second;
        } return a.first > b.first;
    });
    
    vector<int> ans;
    for(const auto & p:fail){
        ans.push_back(p.second);
    }
    
    return ans;
}