#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(vector<int> food){
    string half;
    
    for(int i = 1; i < food.size(); i++){
        int half_food = (int)food[i] / 2;
        half += string(half_food, char('0' + i));
    }
    string reversed = half;
    reverse(reversed.begin(), reversed.end());
    
    
    return half + "0" + reversed;
}