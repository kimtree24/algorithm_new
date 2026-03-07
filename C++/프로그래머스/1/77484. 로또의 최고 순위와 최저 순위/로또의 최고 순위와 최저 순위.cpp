#include <vector>
#include <algorithm>

using namespace std;

int get_rank(int match){
    if(match >= 2){
        return 7 - match;
    }
    return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums){
    int zero_cnt = 0;
    int match = 0;
    
    for(int n:lottos){
        if(n == 0){
            zero_cnt += 1;
        }
        else if(find(win_nums.begin(), win_nums.end(), n) != win_nums.end()){
            match += 1;
        }
    }
    
    int best = get_rank(match + zero_cnt);
    int worst = get_rank(match);
    
    return {best, worst};
    
}