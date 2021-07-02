#include <iostream>

struct node {
    struct node* prev;
};

int main(void)
{

    node n;
    std::cout << sizeof(n);
    return 0;
}
