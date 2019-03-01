/*
 *
 * 100 3
 * 2 1 2
 * 4 3 4 5 6
 * 3 3 2 5
 *
 * 75
 */
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int memo[210][25];
int M, C, price[20][20];

int shop(int money, int g) {
  if (money < 0) return -100000000;
  if (g == C) return M - money;
  if (memo[money][g] != -1) return memo[money][g];
  int ans = -1;
  for (int i = 1; i <= price[g][0]; ++i) {
    ans = max(ans, shop(money - price[g][i], g + 1));
  }
  return memo[money][g] = ans;
}

int main() {
  int TC;
  scanf("%d", &TC);
  while (TC--) {
    int score;
    scanf("%d %d", &M, &C);
    for (int i = 0; i < C; ++i) {
      scanf("%d", &price[i][0]);
      for (int j = 1; j <= price[i][0]; ++j) scanf("%d", &price[i][j]);
    }
    memset(memo, -1, sizeof memo);
    score = shop(M, 0);
    if (score < 0)
      printf("no solution\n");
    else
      printf("%d\n", score);
  }
  return 0;
}
