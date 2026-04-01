#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    int num_p = players.size();
    map<string, int> m;
    
    for(int i = 0; i < num_p; i++){
        m[players[i]] = i;
    }
    
    for(string call:callings){
        int idx = m[call];
        string front = players[idx - 1];
        
        swap(players[idx], players[idx - 1]);
        
        m[call] -= 1;
        m[front] += 1;
    }
    
    return players;
}