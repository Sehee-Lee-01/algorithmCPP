#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getGroupedAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY words as parameter.
 */

int getGroupedAnagrams(vector<string> words)
{
    set<string> sort_word;
    for (auto word : words)
    {
        sort(word.begin(), word.end());
        sort_word.insert(word);
    }
    return sort_word.size();
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

    int result = getGroupedAnagrams(words);

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
