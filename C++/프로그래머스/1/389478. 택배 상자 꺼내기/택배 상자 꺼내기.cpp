#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {

    int target_row = (num - 1) / w;
    int target_col;

    if(target_row % 2 == 0)
        target_col = (num - 1) % w;
    else
        target_col = w - 1 - ((num - 1) % w);

    int count = 1;

    for(int i = num + 1; i <= n; i++){

        int row = (i - 1) / w;
        int col;

        if(row % 2 == 0)
            col = (i - 1) % w;
        else
            col = w - 1 - ((i - 1) % w);

        if(col == target_col)
            count++;
    }

    return count;
}