#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> str_num;
    
    for(int num:numbers){
        str_num.push_back(to_string(num));
    }
    
    sort(str_num.begin(),
         str_num.end(),
         [](string a, string b){
             return a + b > b + a;
         });
    
    
    for(int i = 0; i < numbers.size(); i++){
        answer += str_num[i];
    }
    
    if(answer[0] == '0'){
        return "0";
    }
    
    return answer;
}