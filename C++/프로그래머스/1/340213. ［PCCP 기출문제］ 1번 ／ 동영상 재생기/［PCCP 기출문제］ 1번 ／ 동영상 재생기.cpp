#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string ans = "";
    
    // 전부 다 분으로 바꾸기
    int ivideo_len = stoi(video_len.substr(0,2)) * 60 + stoi(video_len.substr(3,2));
    int ipos = stoi(pos.substr(0,2)) * 60 + stoi(pos.substr(3,2));
    int iop_start = stoi(op_start.substr(0,2)) * 60 + stoi(op_start.substr(3,2));
    int iop_end = stoi(op_end.substr(0,2)) * 60 + stoi(op_end.substr(3,2));
    
    // 명령 실행 전 지금 시작이 start-end사이면 end로 보내기
    if(ipos < iop_end && ipos >= iop_start){
        ipos = iop_end;
    }
    
    // 명령 수행
    for(string comm : commands){
        if(comm == "next"){
            ipos += 10;
        }else{
            ipos -= 10;
        }
        
        ipos = max(0, min(ipos, ivideo_len));
        
        if(ipos < iop_end && ipos >= iop_start){
            ipos = iop_end;
        }
    }
    
    // 결과 변환
    string m = to_string(ipos / 60);
    string s = to_string(ipos % 60);
    
    if(m.size() == 1){
        ans += "0";
    }
    ans += m;
    ans += ":";
    if(s.size() == 1){
        ans += "0";
    }
    ans += s;
    
    return ans;
}