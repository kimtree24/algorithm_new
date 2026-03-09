#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n = 0;
    int k = 0;
    cin >> n >> k;
    
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    
    int cnt = 0;
    vector<int> ans;
    while(!q.empty()){
        cnt++;
        if(cnt == k){
            ans.push_back(q.front());
            cnt = 0;
            q.pop();
        }else{
            q.push(q.front());
            q.pop();
        }
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