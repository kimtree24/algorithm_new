#include <vector>
#include <string>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations){
    multiset<int> ms;
    
    for(string op:operations){
        if(op[0] == 'I'){
            int num = stoi(op.substr(2));
            ms.insert(num);
        }
        else if(op == "D 1"){
            if(!ms.empty()){
                auto it = prev(ms.end(), 1);
                ms.erase(it);
            }
        }
        else if(op == "D -1"){
            if(!ms.empty()){
                ms.erase(ms.begin());
            }
        }
    }
    
    if(ms.empty()){
        return {0,0};
    }
    
    return {*prev(ms.end()), *ms.begin()};
    
}