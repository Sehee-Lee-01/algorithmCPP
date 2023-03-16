#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countOptions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER people
 *  2. INTEGER groups
 */

long countOptions(int people, int groups)
{
    long res = 0;
    // select (groups-1) in (people-1)

    recursion return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string people_temp;
    getline(cin, people_temp);

    int people = stoi(ltrim(rtrim(people_temp)));

    string groups_temp;
    getline(cin, groups_temp);

    int groups = stoi(ltrim(rtrim(groups_temp)));

    long result = countOptions(people, groups);

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
