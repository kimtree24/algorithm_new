#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr){
    vector<int> ans;
    
    for(int num : arr){
        if(ans.empty()){
            ans.push_back(num);
        }else{
            int back = ans[ans.size() - 1];
            if(back == num){
                continue;
            }else{
                ans.push_back(num);
            }
        }
    }
    
    return ans;
}