// dp로 안풀어도 되는 문제
// 그리디로 접근하는 문제
// 단, 데이터를 한 번 가공을 해야함

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int t, d, n, temp;
vector<int> matryo;

int main()
{
  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    scanf("%d %d", &n, &d);
    // insert matryo in list
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &temp);
      matryo.push_back(temp);
    }

    // sort matryo
    sort(matryo.begin(), matryo.end());

    // find case
    int currentElement = 0, count = 0;
    for (int j = 0; j < matryo.size(); j++)
    {

      // init
      if (j == 0)
      {
        currentElement = matryo[j];
        count++;
        continue;
      }

      // if ok
      if (currentElement + d <= matryo[j])
      {
        currentElement = matryo[j];
        count++;
      }
    }

    // print result
    printf("%d\n", count);
  }
}