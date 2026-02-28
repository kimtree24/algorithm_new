#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    while (b != 0){
        long long temp = a % b;
        a = b;
        b = temp;
    }
    
    return a;
}

long lcm(long a, long b){
    return a / gcd(a, b) * b;
}

vector<int> solution(int n, int m){
    vector<int> ans;
    
    ans.push_back(gcd(n, m));
    ans.push_back(lcm(n, m));
    
    return ans;
}