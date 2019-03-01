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

int main() {
  int TC, price[20][20];
  bool reachable[25][250];
  scanf("%d", &TC);
  while (TC--) {
    int M, C;
    scanf("%d %d", &M, &C);
    for (int g = 0; g < C; ++g) {
      scanf("%d", &price[g][0]);
      for (int k = 1; k <= price[g][0]; ++k) scanf("%d", &price[g][k]);
    }

    memset(reachable, false, sizeof reachable);

    for (int k = 1; k <= price[0][0]; ++k) reachable[0][M - price[0][k]] = true;

    for (int g = 1; g < C; ++g) {
      for (int money = 0; money <= M; ++money) {
        if (reachable[g - 1][money]) {
          for (int k = 1; k <= price[g][0]; ++k) {
            if (money - price[g][k] >= 0)
              reachable[g][money - price[g][k]] = true;
          }
        }
      }
    }

    int money;
    for (money = 0; money <= M && !reachable[C - 1][money]; ++money);
    if (money == M + 1)
      printf("no solution\n");
    else
      printf("%d\n", M - money);
  }
  return 0;
}
