#include <string>

using namespace std;

string solution(string s){
    
    int flag = 0;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            flag = 0;
            continue;
        }
        
        if(flag % 2 == 0){
            s[i] = toupper(s[i]);
        }else{
            s[i] = tolower(s[i]);
        }
        
        flag += 1;
        
    }
    
    return s;
}