#include <iostream>
#include <string>
#include <deque>
#include <cctype>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        string p;
        cin >> p;
        deque<int> dq;
        int n;
        cin >> n;
        string line;
        cin >> line;
        
        string num = "";
        
        for(char c:line){
            if(isdigit(c)){
                num += c;
            }else{
                if(!num.empty()){
                    dq.push_back(stoi(num));
                    num.clear();
                }
            }
        }
        
        bool reverse = false;
        bool error = false;
        for(char c:p){
            if(c == 'R'){
                reverse = !reverse;
            }else if(c == 'D'){
                if(dq.empty()){
                    cout << "error";
                    error = true;
                    break;
                }
                
                if(reverse){
                    dq.pop_back();
                }else{
                    dq.pop_front();
                }
            }
        }

        if(error){
            cout << '\n';
            continue;
        }
        cout << '[';
        
        if(!dq.empty() && !reverse){
            for(int i =0; i < dq.size(); i++){
                if(i != dq.size() - 1){
                    cout << dq[i] << ',';
                }else{
                    cout << dq[i];
                }
            }
        }else if(!dq.empty() && reverse){
            for(int i = dq.size() - 1; i >= 0; i--){
                if(i != 0){
                    cout << dq[i] << ',';
                }else{
                    cout << dq[i];
                }
            }
        }

        cout << "]\n";
    }
    cout << "\n";

}