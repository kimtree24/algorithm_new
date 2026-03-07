#include <vector>
#include <cmath>
#include <string>

using namespace std;

int dist(vector<int> cur, vector<int> &tar){
    return abs(cur[0] - tar[0]) + abs(cur[1] - tar[1]);
}

string solution(vector<int> numbers, string hand){
    vector<int> cur_l = {3, 0};
    vector<int> cur_r = {3, 2};
    
    vector<vector<int>> loca = {{3,1}, {0,0}, {0,1}, {0,2},
                                     {1,0}, {1,1}, {1,2},
                                     {2,0}, {2,1}, {2,2}};
    
    string ans;
    
    for(int n:numbers){
        if(n == 1 || n == 4 || n == 7){
            ans += "L";
            cur_l = loca[n];
        }else if(n == 3 || n == 6 || n == 9){
            ans += "R";
            cur_r = loca[n];
        }else{
            // 나머지는 비교
            // 거리계산
            vector<int> target = loca[n];
            int dist_l = dist(cur_l, target);
            int dist_r = dist(cur_r, target);
            if(dist_l == dist_r){
                if(hand == "left"){
                    ans += "L";
                    cur_l = loca[n];
                }else{
                    ans += "R";
                    cur_r = loca[n];
                }
            }else if(dist_l < dist_r){
                ans += "L";
                cur_l = loca[n];
            }else{
                ans += "R";
                cur_r = loca[n];
            }
        }
    }
    
    return ans;
    
}