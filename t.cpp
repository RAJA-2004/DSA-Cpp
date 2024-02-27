#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countPairsWithDifference(const vector<int>& nums, int target) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int count = 0;
    for (int num : nums) {
        if (numSet.find(num - target) != numSet.end()) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> nums {2, 4, 7, 9, 11};
    int target = 2;
    int x = countPairsWithDifference(nums, target);
    cout << x << endl;
    return 0;
}
