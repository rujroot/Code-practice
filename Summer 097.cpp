#include <bits/stdc++.h>
using namespace std;

int DP[40][40];
string s;
set<string> ss;

void Print(int L, int R, vector<char> f, vector<char> b) {
  if (L > R) {
    string st;
    for (int i = 0; i < f.size(); ++i) {
      st.push_back(f[i]);
    }
    for (int i = b.size() - 1; i >= 0; --i) {
      st.push_back(b[i]);
    }
    ss.insert(st);
  } else if (L == R) {
    f.push_back(s[L]);
    Print(L + 1, R - 1, f, b);
  } else if (s[L] == s[R]) {
    f.push_back(s[L]);
    b.push_back(s[R]);
    Print(L + 1, R - 1, f, b);
  } else if (DP[L][R - 1] > DP[L + 1][R]) {
    Print(L, R - 1, f, b);
  } else if (DP[L][R - 1] < DP[L + 1][R]) {
    Print(L + 1, R, f, b);
  } else {
    Print(L, R - 1, f, b);
    Print(L + 1, R, f, b);
  }
}

int main() {
  cin >> s;

  int n = s.size(), p = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int L = j, R = j + p;
      if (R >= n)
        break;

      if (L == R)
        DP[L][R] = 1;
      else if (s[L] != s[R])
        DP[L][R] = max(DP[L + 1][R], DP[L][R - 1]);
      else if (s[L] == s[R])
        DP[L][R] = DP[L + 1][R - 1] + 2;
    }
    p++;
  }

  vector<char> f, b;
  Print(0, n - 1, f, b);
  for (auto u : ss) {
    cout << u << "\n";
  }
}
