#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int ans = 0;
    
    // 직원 수
    int p_num = schedules.size();
    
    // 기준시간 변경
    for(int i = 0; i < p_num; i++){
        schedules[i] += 10;
        // 분단위 변경
        int hour = schedules[i] / 100;
        int min = schedules[i] % 100;
        if(min >= 60){
            min = min - 60;
            hour += 1;
        }
        schedules[i] = hour * 100 + min;
    }
    
    // timelogs 판단
    // p_idx : 사원번호
    for(int p_idx = 0; p_idx < p_num; p_idx++){
        int cnt = 0; // 통과 날짜 -> 5되어야 함
        
        // d_idx : timelog 인덱스
        for(int d_idx = 0; d_idx < 7; d_idx++){
            // 요일판단
            int w_idx = (startday + d_idx) % 7;
            
            // 토, 일 pass
            if(w_idx < 1 || w_idx > 5){
                continue;
            }else{
                // 시간 내에 왔다.
                if(timelogs[p_idx][d_idx] <= schedules[p_idx]){
                    cnt += 1;
                }
            }
        }
        
        if(cnt == 5){
            ans += 1;
        }
        
    }
    
    return ans;
    
}