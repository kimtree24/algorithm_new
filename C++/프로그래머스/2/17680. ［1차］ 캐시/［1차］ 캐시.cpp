#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities){
    int ans = 0;
    deque<string> cache;
    
    if(cacheSize == 0){
        return cities.size() * 5;
    }
    
    for(string b_city:cities){
        string city;
        for(char c:b_city){
            city += tolower(c);
        }
        auto it = find(cache.begin(), cache.end(), city);
        // 캐시에 없는 경우
        if(it == cache.end()){
            ans += 5;
            // 캐시 다 찼는지
            if(cache.size() >= cacheSize){
                cache.pop_front(); // 가장 앞 뻬기
                cache.push_back(city);
            }
            // 캐시 다 안 찼다면
            else{
                cache.push_back(city);
            }
        }
        // 캐시에 있는 경우
        else{
            ans += 1;
            // 캐시 갱신
            cache.erase(it);
            cache.push_back(city);
        }
    }
    return ans;
}