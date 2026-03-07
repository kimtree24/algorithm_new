#include <vector>

using namespace std;

int solution(vector<int> ingredient){
    int ans = 0;
    vector<int> st;
    
    for(int i = 0; i < ingredient.size(); i++){
        int len_s = st.size();
        if(len_s < 3){
            st.push_back(ingredient[i]);
        }else if(ingredient[i] == 1 &&
                st[len_s - 1] == 3 &&
                st[len_s - 2] == 2 &&
                st[len_s - 3] == 1){
            ans += 1;
            for(int j = 0; j < 3; j++){
                st.pop_back();
            }
        }else{
            st.push_back(ingredient[i]);
        }
    }
    
    
    return ans;
}