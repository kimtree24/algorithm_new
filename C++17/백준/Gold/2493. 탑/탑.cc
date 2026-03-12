#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> tops(n, 0);
    for(int i = 0; i < n; i++){
        cin >> tops[i];
    }
    
    vector<pair<int, int>> st;
    
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.back().first < tops[i]){
            st.pop_back();
        }
        if(st.empty()){
            cout << 0 << " ";
        }else{
            cout << st.back().second << " ";
        }
        st.push_back({tops[i], i+1});
    }
    
    return 0;
    
}