#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int ans = 0;
    
    for(char c : my_string){
        if(isdigit(c)){
            ans += c - '0';
        }
    }
    
    return ans;
}