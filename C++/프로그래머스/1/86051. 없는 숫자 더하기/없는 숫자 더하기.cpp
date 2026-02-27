# include <vector>

using namespace std;

int solution(vector<int> numbers){
    int ans = 0;
    
    vector<bool> is_ex(10, false);
    
    for(int num: numbers){
        is_ex[num] = true;
    }
    
    for(int i = 0; i < 10; i++){
        if (!is_ex[i]){
            ans += i;
        }
    }
    
    return ans;
}