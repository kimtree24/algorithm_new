#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> num_list(n, 0);
    for(int i = 0; i < n; i++){
        cin >> num_list[i];
    }
    
    vector<int> s;
    vector<char> ans;
    int pointer = 0;
    for(int i = 1; i <= n; i++){
        s.push_back(i);
        ans.push_back('+');
        
        while(!s.empty() && s.back() == num_list[pointer]){
            s.pop_back();
            ans.push_back('-');
            pointer++;
        }
    }
    
    if(!s.empty()){
        cout << "NO";
    }else{
        for(char c:ans){
            cout << c << "\n";
        }
    }
    
}