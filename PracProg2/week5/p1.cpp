#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T, L;
    char temp;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &L);
        vector<char> calculater;
        vector<int> brace_locations;

        for (int i = 0; i < L; i++)
        {
            scanf("%c", &temp);
            calculater.push_back(temp);
            if (temp == '(')
                brace_locations.push_back(i);
        }

        while (!brace_locations.empty())
        {
            int curr_location = brace_locations.back();
            brace_locations.pop_back();
            int curr_calculate = 0;
            while (calculater[curr_location] == ')')
            {
                if (calculater[curr_location] == '(')
                    continue;
            }
        }
    }
}