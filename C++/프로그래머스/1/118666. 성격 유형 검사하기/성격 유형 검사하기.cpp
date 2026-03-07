#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char,int> score;

    for(int i=0;i<survey.size();i++){
        int diff = choices[i] - 4;

        if(diff < 0){
            score[survey[i][0]] += -diff;
        }
        else{
            score[survey[i][1]] += diff;
        }
    }
    
    answer += (score['R'] >= score['T']) ? 'R' : 'T';
    answer += (score['C'] >= score['F']) ? 'C' : 'F';
    answer += (score['J'] >= score['M']) ? 'J' : 'M';
    answer += (score['A'] >= score['N']) ? 'A' : 'N';
    
    return answer;
}