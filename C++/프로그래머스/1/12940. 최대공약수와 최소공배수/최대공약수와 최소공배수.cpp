#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int gcd_num = gcd(n, m);
    int lcm_num = lcm(n, m);
    
    answer.push_back(gcd_num);
    answer.push_back(lcm_num);
    
    return answer;
}