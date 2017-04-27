#include <iostream>

int main(void)
{
    int a = 1;

    // int &r = 3;             // L-value Reference must be L-value
    const int &cra = 3;    // OK? Why?
    int &ra = a;   //

    int b = 10;
    int &&rb = 20;
    rb = b;

    return 0;
}
