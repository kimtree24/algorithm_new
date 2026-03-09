#include <vector>
#include <iostream>
using namespace std;
int main(){
    int n = 0;
    int k = 0;
    cin >> n >> k;
    
    vector<bool> v(n, false);
    vector<int> ans;
    
    int idx = 0;
    int cnt = 0;
    
    while(ans.size() < n){
        if(!v[idx]){
            cnt++;
            if(cnt == k){
                v[idx] = true;
                ans.push_back(idx+1);
                cnt = 0;
            }
        }
        idx = (idx + 1) % n;
    }
    cout << "<";
    for(int i = 0; i < n; i++){
        cout << ans[i];
        if(i != n - 1){
            cout << ", ";
        }
    }
    cout << ">";
        
}