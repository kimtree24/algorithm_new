#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    
    int pr = park.size();
    int pc = park[0].size();
    
    sort(mats.rbegin(), mats.rend());
    

    
    for(int size : mats){
        for(int r = 0; r + size <= pr; r++){
            for(int c = 0; c + size <= pc; c++){
                
                bool flag = true;
                
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size; j++){
                        if(!flag || park[r + i][c + j] != "-1"){
                            flag = false;
                            break;
                        }
                    }
                }
                
                if(flag){
                    return size;
                }
                
            }
        }
    }
    
    return -1;
    
}