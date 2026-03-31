#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계 + 2단계 + 3단계
    for(char c : new_id){
        c = tolower(c);

        if(islower(c) || isdigit(c) || c == '-' || c == '_' || c == '.'){
            
            if(!answer.empty() && answer.back() == '.' && c == '.')
                continue;

            answer += c;
        }
    }
    
    // 4단계
    while(!answer.empty() && answer[0] == '.'){
        answer.erase(answer.begin());
    }
    while(!answer.empty() && answer.back() == '.'){
        answer.pop_back();
    }

    // 5단계
    if(answer.empty()){
        answer += 'a';
    }

    // 6단계
    if(answer.size() >= 16){
        answer = answer.substr(0,15);
        if(answer.back() == '.'){
            answer.pop_back();
        }
    }

    // 7단계
    if(answer.size() <= 2){
        char c = answer.back();
        while(answer.size() < 3){
            answer += c;
        }
    }
    
    return answer;
}