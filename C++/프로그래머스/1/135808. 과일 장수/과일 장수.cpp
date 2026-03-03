#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score){
    int result = 0;
    // score 정렬
    sort(score.rbegin(), score.rend());
    
    for(int i = m - 1; i < score.size(); i += m){
        result += score[i] * m;
    }
    
    return result;
}