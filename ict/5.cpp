#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'numWays' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY words
 *  2. STRING target
 */

int numWays(vector<string> words, string target)
{
    map<char, int> alpha_target, total_cnt;
    for (char element : target)
    {
        auto it = alpha_target.find(element);
        if (it == alpha_target.end())
        {
            alpha_target.insert(make_pair(element, 1));
            total_cnt.insert(make_pair(element, 0));
        }
        else
            it->second++;
    }

    for (auto word : words)
    {
        for (auto element : word)
        {
            auto it = total_cnt.find(element);
            if (it != total_cnt.end())
                it->second++;
        }
    }
    int res = 1;
    for (auto it = alpha_target.begin(); it != alpha_target.end(); it++)
    {
        char target = it->first;                       // alphabet
        int need_num = it->second;                     // need
        int have_num = total_cnt.find(target)->second; // can use

        int tmp_res = 1;
        for (int i = 1; i < need_num + 1; i++)
        {
            tmp_res *= (have_num - i);
        }
        res = (res * tmp_res) % 1000000007;
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string words_count_temp;
    getline(cin, words_count_temp);

    int words_count = stoi(ltrim(rtrim(words_count_temp)));

    vector<string> words(words_count);

    for (int i = 0; i < words_count; i++)
    {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    string target;
    getline(cin, target);

    int result = numWays(words, target);

    fout << result << "\n";

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
