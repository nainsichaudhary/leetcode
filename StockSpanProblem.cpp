#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans(prices.size());
    stack<int> s;

    for (int i = 0; i < prices.size(); i++) {
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans[i] = i + 1;
        } else {
            ans[i] = i - s.top();
        }
        s.push(i);
    }

    // ✅ Print only once
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
