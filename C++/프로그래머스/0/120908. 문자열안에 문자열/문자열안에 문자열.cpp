#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    
    int pt = 0;
    
    for(char c : str1){
        if(c == str2[pt]){
            pt += 1;
            if(pt == str2.size()){
                return 1;
            }
        }else{
            pt = 0;
        }
        
        cout << pt << " ";
    }
    
    return 2;
    
}