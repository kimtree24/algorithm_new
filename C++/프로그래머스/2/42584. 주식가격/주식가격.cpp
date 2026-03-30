#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    vector<pair<int, int>> st;
    
    for(int i = 0; i < prices.size(); i++){
        if(st.empty()){
            st.push_back({prices[i], i});
        }
        else{
            bool flag = true;
            while(flag && !st.empty()){
                if(st.back().first > prices[i]){
                    auto tar = st.back();
                    st.pop_back();
                    answer[tar.second] = i - tar.second;
                }else{
                    flag = false;
                }
            }
            st.push_back({prices[i], i});
        }
    }
    
    while(!st.empty()){
        auto tar = st.back();
        answer[tar.second] = prices.size() - tar.second - 1;
        st.pop_back();
    }
    
    return answer;
}