#include <string>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// 한 자리만 다른지 판단 함수
bool one_diff(string before, string next){
    int len = before.size();
    
    int cnt = 0;
    for(int i = 0; i < len; i++){
        if(before[i] != next[i]){
            cnt++;
        }
    }
    
    if(cnt == 1){
        return true;
    }else{
        return false;
    }
    
}

int solution(string begin, string target, vector<string> words){
    int ans = 0;
    
    // bfs
    deque<pair<string, int>> dq;
    vector<bool> visited(words.size(), false);
    
    // 초기화
    dq.push_back({begin, 0});
    while(!dq.empty()){
        // 이전단어
        auto before = dq.front();
        dq.pop_front();
        
        if(before.first == target){
            return before.second;
        }
        
        for(int i = 0; i < words.size(); i++){
            if(!visited[i] && one_diff(before.first, words[i])){
                visited[i] = true;
                dq.push_back({words[i], before.second + 1});
            }
        }
    }
    return 0;
}