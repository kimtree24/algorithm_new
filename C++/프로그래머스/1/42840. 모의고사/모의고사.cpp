#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers){
    vector<int> ans;
    
    vector<int> one = {1,2,3,4,5};
    vector<int> two = {2,1,2,3,2,4,2,5};
    vector<int> three = {3,3,1,1,2,2,4,4,5,5};
    
    vector<int> score(3, 0);
    
    for(int i = 0; i < answers.size(); i++){
        if(one[i % one.size()] == answers[i]){
            score[0] += 1;
        }
        if(two[i % two.size()] == answers[i]){
            score[1] += 1;
        }
        if(three[i % three.size()] == answers[i]){
            score[2] += 1;
        }
    }
    
    int max_s = *max_element(score.begin(), score.end());
    
    for(int i = 0; i < 3; i++){
        if(score[i] == max_s){
            ans.push_back(i+1);
        }
    }
    
    return ans;
}