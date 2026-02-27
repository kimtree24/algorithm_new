# include <vector>
# include <string>

using namespace std;

string solution(string phone_number){
    
    int len_s = phone_number.size();
    
    for(int i = 0; i < len_s - 4; i++){
        phone_number[i] = '*';
    }
    
    return phone_number;
}