# include <vector>
# include <numeric>

using namespace std;

double solution(vector<int> arr){
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int len = arr.size();
    
    return (double)sum / len;
}