#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getCelebrity(vector<vector<int>> arr) {
    int n = arr.size();
    stack<int> s;

    // Step 1: Push all people
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Eliminate non-celebrities
    while (s.size() > 1) {
        int i = s.top(); s.pop();
        int j = s.top(); s.pop();

        if (arr[i][j] == 1) {
            // i knows j → i not celebrity
            s.push(j);
        } else {
            // i doesn't know j → j not celebrity
            s.push(i);
        }
    }

    // Step 3: Candidate
    int candidate = s.top();

    // Step 4: Verify candidate
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (arr[candidate][i] == 1 || arr[i][candidate] == 0) {
                return -1;  // Not a celebrity
            }
        }
    }

    return candidate; // ✅
}

int main() {
    vector<vector<int>> arr = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };

    int ans = getCelebrity(arr);
    cout << ans << endl;
}
