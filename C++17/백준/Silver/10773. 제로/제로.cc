#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int main(){
    int k;
    cin >> k;
    vector<long long> v;
    
    for(int i = 0; i < k; i++){
        long long n;
        cin >> n;
        
        if(n != 0){
            v.push_back(n);
        }else{
            v.pop_back();
        }
    }
    long long ans;
    ans = accumulate(v.begin(), v.end(), 0);
    
    cout << ans;
    
}