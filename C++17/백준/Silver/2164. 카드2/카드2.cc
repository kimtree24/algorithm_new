#include <deque>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    deque<int> dq;
    
    for(int i = n; i > 0; i--){
        dq.push_back(i);
    }
    
    while(dq.size() > 1){
        dq.pop_back();
        int move = dq.back();
        dq.push_front(move);
        dq.pop_back();

    }
    
    cout << dq.back();
    
    return 0;
}