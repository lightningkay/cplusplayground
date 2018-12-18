#include <cstdio>

using namespace std;

int n, maxd, res[13];

bool DFS(int d) {
  if (d == maxd) return res[d - 1] == n;
  if (res[d - 1] * (1 << (maxd - d)) < n) return false;
  for (int i = d - 1; i >= 0; --i) {
    res[d] = res[d - 1] + res[i];
    if (DFS(d + 1)) return true;
    res[d] =
        res[d - 1] - res[i] > 0 ? res[d - 1] - res[i] : res[i] - res[d - 1];
    if (DFS(d + 1)) return true;
  }
  return false;
}

int main() {
  while (res[0] = 1, maxd = 1, scanf("%d", &n), n) {
    while (!DFS(1)) maxd++;
    printf("%d\n", maxd - 1);
  }
  return 0;
}
