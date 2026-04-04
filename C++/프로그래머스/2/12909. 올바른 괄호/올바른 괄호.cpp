#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s){
    vector<char> st;
    
    for(char c : s){
        // 비어있다면 그냥 넣음
        if(st.empty()){
            st.push_back(c);
        }else{
            char back = st.back();
            // pop할 조건
            if(back == '(' && c == ')'){
                st.pop_back();
            }else{
                st.push_back(c);
            }
        }
    }
    
    return st.empty();
    
}