#include <iostream>
#include <vector>
using namespace std;

// øÏÀŸ≈≈–Ú
void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int i = left, j = right, pivot = nums[left];
    while (i < j) {
        while (i < j && nums[j] >= pivot) j--;
        nums[i] = nums[j];
        while (i < j && nums[i] <= pivot) i++;
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
}

// √∞≈›≈≈–Ú
void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

// ÷±Ω”—°‘Ò≈≈–Ú
void selectionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(nums[i], nums[minIndex]);
        }
    }
}

int main() {
    vector<int> nums = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // øÏÀŸ≈≈–Ú
    vector<int> nums1 = nums;
    quickSort(nums1, 0, nums1.size() - 1);
    cout << "Quick sort: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    // √∞≈›≈≈–Ú
    vector<int> nums2 = nums;
    bubbleSort(nums2);
    cout << "Bubble sort: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    // ÷±Ω”—°‘Ò≈≈–Ú
    vector<int> nums3 = nums;
    selectionSort(nums3);
    cout << "Selection sort: ";
    for (int num : nums3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
