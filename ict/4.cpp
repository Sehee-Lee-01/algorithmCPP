#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getTheGroups' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY queryType
 *  3. INTEGER_ARRAY students1
 *  4. INTEGER_ARRAY students2
 */

vector<int> getTheGroups(int n, vector<string> queryType, vector<int> students1, vector<int> students2)
{
    vector<int> res;
    vector<vector<int>> friend_list(n + 1);

    for (int i = 0; i < queryType.size(); i++)
    {
        if (queryType[i] == "Friend")
        {
            friend_list[students1[i]].push_back(students2[i]);
            friend_list[students2[i]].push_back(students1[i]);
        }
        else // Total
        {
            // student 1 group
            int num_visit = 0;
            vector<bool> visit(n + 1, false);

            vector<int> to_visit;
            to_visit.push_back(students1[i]);
            to_visit.push_back(students2[i]);
            while (!to_visit.empty())
            {
                int curr = to_visit.back();
                to_visit.pop_back();
                if (!visit[curr])
                {
                    visit[curr] = true;
                    num_visit++;

                    if (friend_list[curr].size() != 0)
                        for (int j = 0; j < friend_list[curr].size(); j++)
                            to_visit.push_back(friend_list[curr][j]);
                }
            }
            res.push_back(num_visit);
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string queryType_count_temp;
    getline(cin, queryType_count_temp);

    int queryType_count = stoi(ltrim(rtrim(queryType_count_temp)));

    vector<string> queryType(queryType_count);

    for (int i = 0; i < queryType_count; i++)
    {
        string queryType_item;
        getline(cin, queryType_item);

        queryType[i] = queryType_item;
    }

    string students1_count_temp;
    getline(cin, students1_count_temp);

    int students1_count = stoi(ltrim(rtrim(students1_count_temp)));

    vector<int> students1(students1_count);

    for (int i = 0; i < students1_count; i++)
    {
        string students1_item_temp;
        getline(cin, students1_item_temp);

        int students1_item = stoi(ltrim(rtrim(students1_item_temp)));

        students1[i] = students1_item;
    }

    string students2_count_temp;
    getline(cin, students2_count_temp);

    int students2_count = stoi(ltrim(rtrim(students2_count_temp)));

    vector<int> students2(students2_count);

    for (int i = 0; i < students2_count; i++)
    {
        string students2_item_temp;
        getline(cin, students2_item_temp);

        int students2_item = stoi(ltrim(rtrim(students2_item_temp)));

        students2[i] = students2_item;
    }

    vector<int> result = getTheGroups(n, queryType, students1, students2);

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
