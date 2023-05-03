#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
typedef long double ld;
ll MAX = 1e+17;
ll MOD = 1e9+7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
 //   freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    vector<ll> dr = {-1, 0, 0, 1};
    vector<ll> dc = {0, -1, 1, 0};

    ll tc; cin >> tc;
    while (tc--) {
        vector<P> ssd(1);
        ll n, m; cin >> n >> m;
        vector<vector<ll>> vec(n + 1, vector<ll>(n + 1, 0));
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++)
                cin >> vec[i][j];
        }

        ll t1, t2;
        for (ll i = 1; i <= m; i++) {
            cin >> t1 >> t2;
            ssd.emplace_back(make_pair(t1, t2));
        }

        function<P(ll, ll)> bfs = [&](ll stR, ll stC) -> P {
            vector<vector<ll>> visited(n + 1, vector<ll>(n + 1, false));
            queue<P> q;
            q.emplace(make_pair(stR, stC));
            while (!q.empty()) {
                auto [curR, curC] = q.front();
                q.pop();
                if (vec[curR][curC] == 1) {
                    vec[curR][curC] = -1;
                    return make_pair(curR, curC);
                }

                for (ll i = 0; i < 4; i++) {
                    ll nextR = curR + dr[i], nextC = curC + dc[i];
                    if (!(nextR < 1 || nextC < 1 || nextR > n || nextC > n)) {
                        if (!visited[nextR][nextC] && vec[nextR][nextC] != -1) {
                            visited[nextR][nextC] = true;
                            q.emplace(make_pair(nextR, nextC));
                        }
                    }
                }
            }

            // should not happen
            return make_pair(-1, -1);
        };

        function<P(ll, ll, ll)> togo = [&](ll stR, ll stC, ll idx) -> P {
            vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
            queue<tuple<ll, ll, ll, ll>> q;
            q.emplace(make_tuple(stR, stC, -1, -1));
            visited[stR][stC] = true;

            while (!q.empty()) {
                auto [curR, curC, returnR, returnC] = q.front();
                q.pop();

                if (curR == ssd[idx].first && curC == ssd[idx].second)
                    return make_pair(returnR, returnC);

                for (ll i = 0; i < 4; i++) {
                    ll nextR = curR + dr[i], nextC = curC + dc[i];
                    if (!(nextR < 1 || nextC < 1 || nextR > n || nextC > n)) {
                        if (vec[nextR][nextC] != -1 && !visited[nextR][nextC]) {
                            if (returnR == -1 && returnC == -1) {
                                visited[nextR][nextC] = true;
                                q.emplace (make_tuple (nextR, nextC, dr[i], dc[i]));
                            }
                            else {
                                visited[nextR][nextC] = true;
                                q.emplace (make_tuple (nextR, nextC, returnR, returnC));
                            }
                        }
                    }
                }
            }

            // should not happen
            return make_pair(-1, -1);
        };

        vector<bool> finished(m + 1, false);
        vector<P> location(m + 1, make_pair(-1, -1));
        ll left = m, time = 0;
        while (left > 0) {
            time++;
            vector<ll> two, three;

            for (ll i = 1; i <= min(m, time); i++) {
                if (finished[i])
                    continue;

                auto [curR, curC] = location[i];
                if (curR == -1 && curC == -1)
                    three.emplace_back(i);

                else {
                    auto [curR, curC] = location[i];
                    auto [dR, dC] = togo(curR, curC, i);
                    curR += dR, curC += dC;
                    location[i] = make_pair(curR, curC);
                    if (location[i] == ssd[i])
                        two.emplace_back(i);
                }
            }

            for (ll i = 0; i < two.size(); i++) {
                ll idx = two[i];
                left--;
                finished[idx] = true;
                vec[location[idx].first][location[idx].second] = -1;
            }

            for (ll i = 0; i < three.size(); i++) {
                ll idx = three[i];
                location[idx] = bfs(ssd[idx].first, ssd[idx].second);
                vec[location[idx].first][location[idx].second] = -1;
            }
        }

        cout << time << endl;
    }
    return 0;
}