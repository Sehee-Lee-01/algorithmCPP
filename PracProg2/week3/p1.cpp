#include <iostream>
using namespace std;

int main()
{
    int t, n, p, result;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &p);
        if (p % 2 != 0)
        {
            if (n % 2 == 0)
                result = n / 2;
            else
                result = n / 2 + 1;
        }
        else
        {
            result = n / 2 + 1;
        }
        printf("%d\n", result);
    }
}