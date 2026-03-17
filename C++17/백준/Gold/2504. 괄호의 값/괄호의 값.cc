#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    int multi = 1;
    int ans = 0;
    vector<char> st;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            multi *= 2;
            st.push_back('(');
        }
        else if(s[i] == '['){
            multi *= 3;
            st.push_back('[');
        }
        else if(s[i] == ')'){
            if(st.empty() || st.back() != '('){
                cout << 0;
                return 0;
            }
            if(s[i - 1] == '('){
                ans += multi;
            }
            st.pop_back();
            multi /= 2;
        }
        else if(s[i] == ']'){
            if(st.empty() || st.back() != '['){
                cout << 0;
                return 0;
            }
            if(s[i - 1] == '['){
                ans += multi;
            }
            st.pop_back();
            multi /= 3;
        }
    }
    
    if(!st.empty()){
        cout << 0;
    }else{
        cout << ans;
    }
    
    return 0;
}