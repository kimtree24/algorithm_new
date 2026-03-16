#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ans = 0;
    
    string s;
    cin >> s;
    
    vector<char> st;
    
    char before = '.';
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push_back('(');
            before = '(';
        }else{
            st.pop_back();
            // 레이저
            if(before == '('){
                ans += st.size();
                before = ')';
            }
            // 막대의 끝
            else{
                ans += 1;
                before = ')';
            }
        }
        
    }
    
    cout << ans;
    
    return 0;
}