#include <bits/stdc++.h>
using namespace std;
vector<int> findTwoElement(vector<int> arr, int n) {
    vector<int> ans;
    vector<bool> seen(n+1, false);
    int repeating;

    for (int i = 0; i < n; i++) {
        if (seen[arr[i]]) {
            repeating = arr[i];
        } else {
            seen[arr[i]] = true;
        }
    }

    ans.push_back(repeating);

    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            ans.push_back(i);
            break;
        }
    }

    return ans;
}