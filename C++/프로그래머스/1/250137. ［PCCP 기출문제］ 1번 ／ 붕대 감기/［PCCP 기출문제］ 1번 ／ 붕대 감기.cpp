#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    
    int btime = 0;
    int cur_health = health;
    
    for(int i = 0; i < attacks.size(); i++){
        int healtime = attacks[i][0] - btime - 1;
        int heal = healtime * bandage[1];
        
        
        if(healtime >= bandage[0]){
            heal += healtime / bandage[0] * bandage[2];
        }
            
        if((cur_health + heal) >= health){
            cur_health = health;
        }else{
            cur_health += heal;
        }
        
        cur_health -= attacks[i][1];
        
        if(cur_health <= 0){
            return -1;
        }
        
        btime = attacks[i][0];
        
    }
    
    
    
    return cur_health;
    
}