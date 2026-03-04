#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult){
    vector<int> score;
    
    for(int i = 0; i < dartResult.size(); i++){
        int num;
        
        if(dartResult[i] == '1' && dartResult[i + 1] == '0'){
            num = 10;
            i++;
        } else{
            num = dartResult[i] - '0';
        }
        
        char bonus = dartResult[++i];
        
        if(bonus == 'S') num = pow(num, 1);
        if(bonus == 'D') num = pow(num, 2);
        if(bonus == 'T') num = pow(num, 3);
        
        if(i + 1 < dartResult.size()){
            if(dartResult[i + 1] == '*'){
                num *= 2;
                
                if(!score.empty()){
                    score.back() *= 2;
                }
                
                i++;
            }else if(dartResult[i + 1] == '#'){
                num *= -1;
                i++;
            }
        }
        score.push_back(num);
    }
    return score[0] + score[1] + score[2];
}