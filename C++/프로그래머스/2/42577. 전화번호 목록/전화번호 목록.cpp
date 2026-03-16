#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book){
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 1; i < phone_book.size(); i++){
        int before_len = phone_book[i - 1].size();
        string target = phone_book[i].substr(0,before_len);
        if(phone_book[i - 1] == target){
            return false;
        }
    }
    
    return true;
}