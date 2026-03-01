#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> solution(string s){
    vector<int> ans;
    map<char, int> m;
    
    for(int i = 0; i < s.size(); i++){
        // 이전에 나온게 있는지 찾기
        // 없으면 -1 출력 + index 갱신
        if(m.find(s[i]) == m.end()){
            ans.push_back(-1);
            m[s[i]] = i;
        }else{
            // 있으면 인덱스 계산후 갱신
            ans.push_back(i - m[s[i]]);
            m[s[i]] = i;
        }
    }
    
    return ans;
    
}