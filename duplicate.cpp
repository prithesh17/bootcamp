#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(const vector<int>& nums) {
    int n = nums.size() - 1;
    int xorResult = 0;

    for (int i = 0; i <= n; ++i) {
        xorResult ^= nums[i];
    }

    for (int i = 1; i <= n; ++i) {
        xorResult ^= i;
    }

    return xorResult;
}

int main() {
    int size;
    cin >> size;

    vector<int> v;
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        v.push_back(element);
    }

    cout << "The duplicate number is: " << findDuplicate(v) << endl;

    return 0;
}
