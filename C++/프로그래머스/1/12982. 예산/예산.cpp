#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget){
    sort(d.begin(), d.end());
    
    int ans = 0;
    int idx = 0;
    
    while (idx < d.size() && budget >= d[idx]){
        budget -= d[idx];
        ans++;
        idx++;
    }
    
    return ans;
    
}