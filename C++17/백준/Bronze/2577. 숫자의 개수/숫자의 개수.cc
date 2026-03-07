#include <string>
#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int result = a * b * c;
    
    string s = to_string(result);
    
    int cnt[10] = {0};
    
    for(char c:s){
        cnt[c - '0']++;
    }
    for(int i = 0; i < 10; i++){
        cout << cnt[i] << "\n";
    }
    
    return 0;
}