#include <string>
#include <vector>

using namespace std;

string solution(int a, int b){
    string ans;
    
    vector<string> day = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    vector<int> month = {31,29,31,30,31,30,31,31,30,31,30,31};
    
    int total_day = 0;
    
    for(int i = 0; i < a - 1; i++){
        total_day += month[i];
    }
    
    total_day += b - 1;
    
    int start_day = 5;
    
    return day[(start_day + total_day) % 7];
}