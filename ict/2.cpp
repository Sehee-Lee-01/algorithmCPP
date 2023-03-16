#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'cardinalitySort' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY nums as parameter.
 */

vector<int> cardinalitySort(vector<int> nums)
{
    // 100000= 0b11000011010100000 => 17
    vector<int> res;
    vector<vector<int>> numofone(20, vector<int>(0));
    for (auto num : nums) // divide by number of 1
    {
        int temp_num = num, cntone = 0;
        // count number of 1's by bit-shift
        while (temp_num) // untill 0
        {
            if (temp_num & 1)
                cntone++;
            temp_num = temp_num >> 1;
        }

        numofone[cntone].push_back(num);
    }

    for (int i = 0; i < numofone.size(); i++) // numner of 1 == i
    {
        if (numofone[i].size() == 1)
        {
            res.push_back(numofone[i][0]);
            cout << i << " " << numofone[i][0] << "\n";
        }
        else if (numofone[i].size() > 1)
        {
            sort(numofone[i].begin(), numofone[i].end());
            for (int j = 0; j < numofone[i].size(); j++)
            {
                res.push_back(numofone[i][j]);
                cout << i << " " << numofone[i][j] << "\n";
            }
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nums_count_temp;
    getline(cin, nums_count_temp);

    int nums_count = stoi(ltrim(rtrim(nums_count_temp)));

    vector<int> nums(nums_count);

    for (int i = 0; i < nums_count; i++)
    {
        string nums_item_temp;
        getline(cin, nums_item_temp);

        int nums_item = stoi(ltrim(rtrim(nums_item_temp)));

        nums[i] = nums_item;
    }

    vector<int> result = cardinalitySort(nums);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i];

        if (i != result.size() - 1)
        {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
