#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    
    vector<int> ans;
    
    for(int num:numlist){
        if((num % n) == 0){
            ans.push_back(num);
        }
    }
    
    return ans;
    
}