# include <vector>

using namespace std;

vector<int> solution(long long n){
    vector<int> ans;
    
    long long cur = n;
    
    while (cur > 0){
        ans.push_back(cur % 10);
        cur /= 10;
    }
    
    return ans;
}