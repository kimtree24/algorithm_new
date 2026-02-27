# include <string>
# include <cctype>

using namespace std;

bool solution(string s){
    int cnt_p = 0;
    int cnt_y = 0;
    
    for (char ch : s){
        ch = tolower(ch);
        if(ch == 'p'){
            cnt_p += 1;
        }else if (ch == 'y'){
            cnt_y += 1;
        }
    }
    
    return cnt_p == cnt_y;
}