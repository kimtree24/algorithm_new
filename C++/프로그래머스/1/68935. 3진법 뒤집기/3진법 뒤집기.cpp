#include <vector>
#include <algorithm>

using namespace std;

vector<int> make_three(int n){
    vector<int> result;
    
    while(n > 0){
        int remain = n % 3;
        n /= 3;
        result.push_back(remain);
    }
    
    return result;
    
}

long long solution(int n){
    
    vector<int> three = make_three(n);
    
    reverse(three.begin(), three.end());
    
    long long ans = 0;
    long long power = 1;
    
    for(int i = 0; i < three.size(); i++){
        ans += power * three[i];
        power *= 3;
    }
    
    return ans;
    
}