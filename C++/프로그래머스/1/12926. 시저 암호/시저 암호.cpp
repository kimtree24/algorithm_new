#include <string>

using namespace std;

string solution(string s, int n){
    string ans = s;
    
    for(int i = 0; i < s.size(); i++){
        // 공백은 그대로
        if(s[i] == ' '){
            continue;
        }
        
        if(s[i] >= 'a' && s[i] <= 'z'){
            ans[i] = (s[i] - 'a' + n) % 26 + 'a';
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            ans[i] = (s[i] - 'A' + n) % 26 + 'A';
        }
    }
    
    return ans;
}