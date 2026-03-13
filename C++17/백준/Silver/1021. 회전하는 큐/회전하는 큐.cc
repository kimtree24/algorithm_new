#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    deque<int> dq;

    for(int i = 1; i <= n; i++){
        dq.push_back(i);
    }

    int cnt = 0;

    while(m--){
        int target;
        cin >> target;

        int idx = find(dq.begin(), dq.end(), target) - dq.begin();

        if(idx <= dq.size()/2){
            while(idx--){
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }else{
            int k = dq.size() - idx;
            while(k--){
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }

        dq.pop_front();
    }

    cout << cnt;

}