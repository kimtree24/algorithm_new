#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    int n;
    cin >> n;
    int ans = 0;
    for(int k = 0; k < n; k++){
        vector<char> st;
        string line;
        cin >> line;
        for(char c:line){
            if(!st.empty()){
                if(st.back() == c){
                    st.pop_back();
                }else{
                    st.push_back(c);
                }
            }else{
                st.push_back(c);
            }
        }
        if(st.empty()){
            ans+=1;
        }
    }
    cout << ans;
    return 0;
}