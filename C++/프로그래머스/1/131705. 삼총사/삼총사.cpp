#include <vector>

using namespace std;

int ans = 0;

void dfs(vector<int> &number, int start, int depth, int sum){
    if(depth == 3){
        if(sum == 0){
            ans++;
        }
        return;
    }
    for(int i = start; i < number.size(); i++){
        dfs(number, i + 1, depth + 1, sum + number[i]);
    }
}

int solution(vector<int> number){
    ans = 0;
    dfs(number, 0, 0, 0);
    return ans;
}