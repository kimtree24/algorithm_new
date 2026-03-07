#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(10, 0);
    
    string s;
    s = to_string(n);
    
    for(char c:s){
        if(c == '9'){
            v[6] += 1;
        }else{
            v[c - '0'] ++;
        }
    }
    v[6] = (v[6] + 1) / 2;
    
    int ans = 0;
    ans = *max_element(v.begin(), v.end());
    
    cout << ans;

    return 0;
}