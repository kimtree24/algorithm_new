#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(vector<string> babbling){
    int ans = 0;
    
    vector<string> words = {"aya", "ye", "woo", "ma"};
    
    for(const string &babbl : babbling){
        int cur = 0;
        string before = "";
        while (cur < babbl.size()){
            bool flag = false;
            for(const string &word : words){
                int word_len = word.size();
                
                string this_word = babbl.substr(cur, word_len);
                
                if(this_word == word && before != this_word){
                    cur += word_len;
                    flag = true;
                    before = this_word;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        
        if(cur == babbl.size()){
            ans += 1;
        }
        
    }
    
    return ans;
}