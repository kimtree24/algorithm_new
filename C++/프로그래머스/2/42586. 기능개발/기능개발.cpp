#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds){
    vector<int> ans;
    int num_pro = progresses.size();
    
    vector<int> st;
    for(int i = 0; i < num_pro; i++){
        int days = (100-progresses[i]) / speeds[i];
        if((100-progresses[i]) % speeds[i] != 0){
            days += 1;
        }
        int cnt = 0;
        while(!st.empty() && st.front() < days){
            cnt += 1;
            st.pop_back();
        }
        if(cnt != 0){
            ans.push_back(cnt);
        }
        
        st.push_back(days);
        
    }
    
    if(!st.empty()){
        ans.push_back(st.size());
    }
    
    return ans;
}