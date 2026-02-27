# include <string>

using namespace std;

string solution(string s){
    
    int len = s.size();
    
    if (len == 1){
        return s;
    }else if(len % 2 == 0){
        int mock = len / 2;
        return s.substr(mock - 1, 2);
    }else{
        int mock = len / 2;
        return s.substr(mock, 1);
    }
}