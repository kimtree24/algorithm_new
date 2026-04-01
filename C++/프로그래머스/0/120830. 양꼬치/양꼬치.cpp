#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int k) {
    
    int dum = n / 10;
    cout << dum;
    return 12000 * n + 2000*(k-dum);
    
}