#include <iostream>
#include <vector>

using namespace std;

vector<bool> isUsed;
vector<int> nums{};

void solve(int N, int M, int last) {
    if (0 == M) {
        for (const auto& v : nums)
        {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = last + 1; i <= N; ++i)
    {
        if (isUsed[i - 1])
            continue;

        nums.push_back(i);
        isUsed[i - 1] = true;

        solve(N, M - 1, i);

        nums.pop_back();
        isUsed[i - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    isUsed = vector<bool>(N, false);
    solve(N, M, 0);

    return 0;
}