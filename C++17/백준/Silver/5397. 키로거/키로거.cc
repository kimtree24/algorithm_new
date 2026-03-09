#include <string>
#include <iostream>
#include <deque>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    for(int k = 0; k < t; k++){
        // 커서 기준 오 왼
        deque<char> ldq;
        deque<char> rdq;
        // 입력
        string line;
        cin >> line;
        
        for(char c:line){
            // '<' 처리 -> 왼쪽이동
            if(c == '<'){
                // 이동 가부
                if(!ldq.empty()){
                    char temp = ldq.back();
                    ldq.pop_back();
                    rdq.push_front(temp);
                }
            }else if(c == '>'){
                // 이동 가부
                if(!rdq.empty()){
                    char temp = rdq.front();
                    rdq.pop_front();
                    ldq.push_back(temp);
                }
            }else if(c == '-'){
                if(!ldq.empty()){
                    ldq.pop_back();
                }
            }else{
                ldq.push_back(c);
            }
        }
        string ans;
        
        for(char c:ldq){
            ans += c;
        }
        for(char c:rdq){
            ans += c;
        }
        
        cout << ans << "\n";
        
    }
    
    return 0;
}