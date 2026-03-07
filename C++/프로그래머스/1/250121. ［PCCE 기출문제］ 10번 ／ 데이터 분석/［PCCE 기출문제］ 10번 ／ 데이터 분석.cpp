#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    // 걸러낼 기준
    int stand = 0;
    if(ext == "code"){
        stand = 0;
    }else if(ext == "date"){
        stand = 1;
    }else if(ext == "maximum"){
        stand = 2;
    }else{
        stand = 3;
    }
    
    // 걸러내기
    vector<vector<int>> filter;
    for(vector<int> d:data){
        if(d[stand] <= val_ext){
            filter.push_back(d);
        }
    }
    
    // 정렬기준
    int sort_s = 0;
    if(sort_by == "code"){
        sort_s = 0;
    }else if(sort_by == "date"){
        sort_s = 1;
    }else if(sort_by == "maximum"){
        sort_s = 2;
    }else{
        sort_s = 3;
    }    
    
    // 정렬
    sort(filter.begin(), filter.end(),
         [sort_s](const auto &a, const auto &b){
             return a[sort_s] < b[sort_s];
         });
    
    return filter;
}