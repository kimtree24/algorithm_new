#include <vector>
#include <iostream>

using namespace std;

void div(vector<int> &cnt, vector<vector<int>> &target){
    int std = target[0][0];
    int n = target.size();
    
    bool same = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(target[i][j] != std){
                same = false;
                break;
            }
        }
        if(!same){
            break;
        }
    }
    
    if(same){
        cnt[std + 1]++;
        return;
    }
    
    //나누기
    int size = n / 3;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            vector<vector<int>> sub(size, vector<int>(size));
            
            for(int r = 0; r < size; r++){
                for(int c = 0; c < size; c++){
                    sub[r][c] = target[i * size + r][j * size + c];
                }
            }
            
            div(cnt, sub);
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(n,vector<int>(n,0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    
    vector<int> cnt(3,0);
    
    div(cnt, matrix);
    
    cout << cnt[0] << "\n" << cnt[1] << "\n" << cnt[2] << "\n";
    
    return 0;
}