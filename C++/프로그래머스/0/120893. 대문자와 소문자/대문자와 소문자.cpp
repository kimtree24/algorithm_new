#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string) {
    
    string ans = "";
    
    for(char c : my_string){
        if(islower(c)){
            ans += toupper(c);
        }else{
            ans += tolower(c);
        }
    }
    
    return ans;
    
}