# include <string>
# include <cctype>

using namespace std;

bool solution(string s){
    int len = s.size();
    
    bool nums = true;
    
    for(char c : s){
        if(!isdigit(c)){
            nums = false;
            break;
        }
    }
    
    if((len == 4 || len == 6 ) && nums){
        return true;
    }
    
    return false;
    
}