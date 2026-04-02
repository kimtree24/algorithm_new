#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2,0);
    int pr_len = park.size();
    int pc_len = park[0].size();
    
    // park 배열 돌면서 스타팅 포인트 잡기 + 장애물포인트잡기
    vector<pair<int, int>> cant;
    pair<int, int> sp;
    for(int r = 0; r < pr_len; r++){
        for(int c = 0; c < pc_len; c++){
            if(park[r][c] == 'S'){
                sp.first = r;
                sp.second = c;
            }
            else if(park[r][c] == 'X'){
                cant.push_back({r, c});
            }
        }
    }
    
    // 방향벡터
    map<char, pair<int, int>> m = {{'E', {0, 1}}, {'S', {1, 0}}, 
                                   {'N', {-1, 0}}, {'W', {0, -1}}};
    
    // 명령어 나누기
    for(string op:routes){
        char dir = op[0];
        int mov = op[2] - '0';
        
        int cr = sp.first;
        int cc = sp.second;
        
        bool flag = false;
        
        while(mov > 0){
            mov -= 1;
            int dx = m[dir].first;
            int dy = m[dir].second;
            int nx = sp.first + dx;
            int ny = sp.second + dy;
            
            if(nx < 0 || nx >= pr_len || ny < 0 || ny >= pc_len || park[nx][ny] == 'X'){
                flag = true;
                break;
            }
            
            sp.first = nx;
            sp.second = ny;
            
        }
        
        if(flag){
            sp.first = cr;
            sp.second = cc;
        }
    }
    
    answer[0] = sp.first;
    answer[1] = sp.second;
    
    return answer;
}