#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

vector<string> split(string s){
    vector<string> a;
    string temp = "";
    for(char c : s){
        if(c != ' '){
            temp += c;
        }else{
            a.push_back(temp);
            temp = "";
        }
    }
    
    if(!temp.empty()){
        a.push_back(temp);
    }
    
    return a;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> ans;
    
    // 전체 사람 수
    int n_id = id_list.size();
    // 이름 -> 인덱스 맵
    map<string, int> m_ntoi;
    // 인덱스 -> 이름 맵
    map<int, string> m_iton;
    
    // 맵 초기화
    for(int i = 0; i < id_list.size(); i++){
        m_ntoi[id_list[i]] = i;
        m_iton[i] = id_list[i];
    }
    
    // 신고자 배열
    vector<set<string>> reporter(n_id, set<string>());
    // 신고당한 사람 배열
    vector<int> reported(n_id, 0);
    
    for(string s : report){
        vector<string> splited = split(s);
        string reporter_n = splited[0];
        string reported_n = splited[1];
        
        // 신고자 id
        int reporter_id = m_ntoi[reporter_n];
        // 신고당한 사람 id
        int reported_id = m_ntoi[reported_n];
        
        int b_cnt = reporter[reporter_id].size();
        
        // 신고한 사람 set에 넣기
        reporter[reporter_id].insert(reported_n);
        
        int a_cnt = reporter[reporter_id].size();
        
        if(b_cnt != a_cnt){
            reported[reported_id] += 1;
        }
        
    }
    
    // k 이상 신고 당한 사람 찾기
    vector<string> target;
    for(int i = 0; i < reported.size(); i++){
        if(reported[i] >= k){
            target.push_back(m_iton[i]);
        }
    }
    
    for(int i = 0; i < reporter.size(); i++){
        int cnt = 0;
        
        vector<string> list (reporter[i].begin(), reporter[i].end());
        
        for(string tar : target){
            auto it = find(list.begin(), list.end(), tar);
            if(it == list.end()){
                continue;
            }else{
                cnt += 1;
            }
        }
        
        
        
        ans.push_back(cnt);
        
    }
    
    
    return ans;
    
}