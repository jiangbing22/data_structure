#pragma once
int binary_search(int arr[], int length, int target) {
	int left = 0;
	int right = length - 1;

	while (left <= right) {  
		int index = (left + right) / 2;

		if (arr[index] == target) {
			return index;
		}
		else if (arr[index] < target) {
			left = index + 1;
		}
		else {
			right = index - 1;
		}
	}

	return -1;
}
int binary_search_recursive(int arr[], int target, int left, int right)
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;
		s
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] < target)
		{

			return binary_search_recursive(arr, target, mid + 1, right);
		}
		else
		{

			return binary_search_recursive(arr, target, left, mid - 1);
		}
	}
	return -1;
}
