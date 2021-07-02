#include <iostream>
#include <vector>

void search(std::vector<int>& arr, int x)
{

    auto end = arr.size() - 1;
    int temp = arr[end];

    arr[end] = x;

    int i = 0;
    while (arr.at(i) != x)
    {
        i++;
    }

    arr[end] = temp;
    if (arr[i] == x && i < static_cast<int>(arr.size()))
    {
        std::cout << "Element found!";
    }
    else
    {
        std::cout << "Element not found";
    }
}

int main(void)
{

    std::vector<int> arr { 1, 5, 2, 6, 1, 3, 51, 213 };

    int x;
    std::cin >> x;
    search(arr, x);

    return 0;
}
