#include <string>
#include <vector>
#include <set>

using namespace std;

bool is_prime(int num){
    if(num < 2){
        return false;
    }
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0) return false;
    }
    
    return true;
}

void dfs(string &numbers, vector<bool> &visited, set<int> &tar_nums, string cur){
    if(!cur.empty()){
        tar_nums.insert(stoi(cur));
    }
    
    for(int i = 0; i < numbers.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(numbers, visited, tar_nums, cur + numbers[i]);
            visited[i] = false;
        }
    }   
}

int solution(string numbers) {
    int answer = 0;
    
    vector<bool> visited(numbers.size(), false);
    set<int> tar_nums;
    
    dfs(numbers, visited, tar_nums, "");
    
    for(int num:tar_nums){
        if(is_prime(num)){
            answer += 1;
        }
    }
    
    return answer;
}