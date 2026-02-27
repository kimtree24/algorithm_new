# include <string>
# include <vector>

using namespace std;

string solution(vector<string> seoul){
    int idx = 0;
    for(string loca: seoul){
        if(loca == "Kim"){
            return "김서방은 " + to_string(idx) + "에 있다";
        }
        idx += 1;
    }
}