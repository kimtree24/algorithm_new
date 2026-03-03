#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 암호 해동 -> 이진수 만들기
string bin(int n, int arr_n){
    string s(n, ' ');
    // 이진수 변환
    int idx = 0;
    for(int i = n - 1; i >= 0; i--){
        if(arr_n % 2 == 1){
            s[i] = '#';
        }
        arr_n /= 2;
    }
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2){
    vector<string> ans;
    
    vector<string> tarr1;
    vector<string> tarr2;
    
    for(int i = 0; i < n; i++){
        tarr1.push_back(bin(n, arr1[i]));
        tarr2.push_back(bin(n, arr2[i]));
    }
    
    for(int i = 0; i < n; i++){
        string ans_line(n, ' ');
        for(int j = 0; j < n; j++){
            if(tarr1[i][j] == '#' | tarr2[i][j] == '#'){
                ans_line[j] = '#';
            }
        }
        ans.push_back(ans_line);
    }
    
    return ans;
}