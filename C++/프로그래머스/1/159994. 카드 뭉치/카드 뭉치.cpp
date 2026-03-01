#include <string>
#include <vector>
#include <deque>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal){
    bool ans = true;
    
    deque<string> dc1(cards1.begin(), cards1.end());
    deque<string> dc2(cards2.begin(), cards2.end());
    
    for(string st : goal){
        if(dc1.front() == st){
            dc1.pop_front();
        }else if(dc2.front() == st){
            dc2.pop_front();
        }else{
            ans = false;
            break;
        }
    }
    return ans ? "Yes" : "No";
}