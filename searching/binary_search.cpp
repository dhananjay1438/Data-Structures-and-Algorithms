#include <iostream>

int binary_search(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binary_search(arr, l, mid - 1, x);

        return binary_search(arr, mid + 1, r, x);
    }

    return -1;
}

int main(void) {


	int arr[] = { 1, 4, 8, 9, 11, 15 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int x;
	std::cin >> x;
	std::cout << binary_search(arr, 0, length, x);

	return 0;
}
