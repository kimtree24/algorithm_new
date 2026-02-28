#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    
    string line(a, '*');
    
    for(int i = 0; i < b; i++){
        cout << line << "\n";
    }
    
    return 0;
}