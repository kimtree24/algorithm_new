#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer(2,0);
    
    int num = money / 5500;
    int rest = money - (num * 5500);
    
    answer[0] = num;
    answer[1] = rest;
    
    return answer;
}