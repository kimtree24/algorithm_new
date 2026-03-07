#include <vector>
#include <iostream>

using namespace std;

int catched(vector<vector<int>> &board, int line){
    int cur = 0;
    int idx = 0;
    int len = board.size();
    
    while(cur == 0 && idx < len){
        cur = board[idx][line - 1];
        if(cur != 0){
            board[idx][line - 1] = 0;
        }
        idx += 1;
    }
    
    return cur;
}

int solution(vector<vector<int>> board, vector<int> moves){
    int ans = 0;
    vector<int> st;
    
    for(int move:moves){
        int cur = catched(board, move);
        if(cur == 0){
            continue;
        }
        // 터뜨릴지 판단
        if(st.size() > 0 && st.back() == cur){
            ans += 2;
            st.pop_back();
        }else{
            st.push_back(cur);
        }
    }
    
    return ans;
}