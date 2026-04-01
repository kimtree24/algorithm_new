#include <string>
#include <vector>
#include <map>

using namespace std;

int toDays(string date){
    int y = stoi(date.substr(0,4));
    int m = stoi(date.substr(5,2));
    int d = stoi(date.substr(8,2));
    
    return y * 12 * 28 + m * 28 + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    
    vector<int> answer;
    
    int todayDays = toDays(today);
    
    map<string,int> termMap;
    
    for(auto &t : terms){
        termMap[t.substr(0,1)] = stoi(t.substr(2));
    }
    
    for(int i = 0; i < privacies.size(); i++){
        
        string date = privacies[i].substr(0,10);
        string type = privacies[i].substr(11,1);
        
        int start = toDays(date);
        int expire = start + termMap[type] * 28;
        
        if(expire <= todayDays){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}