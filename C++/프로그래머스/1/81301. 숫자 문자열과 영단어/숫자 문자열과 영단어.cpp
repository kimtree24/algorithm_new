#include <vector>
#include <string>
#include <map>
#include <cctype>

using namespace std;

long long solution(string s){
    map<string, int> m = {
        {"zero", 0}, {"one", 1}, {"two", 2},
        {"three",3}, {"four", 4}, {"five", 5},
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };
    
    string temp;
    string result;
    
    for(char c:s){
        if(isdigit(c)){
            result += c;
        }else{
            temp += c;
            if(m.find(temp) != m.end()){
                result += char('0' + m[temp]);
                temp = "";
            }
        }
    }
    
    return stoll(result);
    
}