#include <stdio.h>
#include <stdlib.h>


int sort (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int main() {
    int n, k;
    int i, j;
    while(scanf("%d %d", &n, &k) == 2) {
        if(n == 0 && k == 0)
            break;
        if(k == 0 || n == 1) {
            printf("1\n");
            continue;
        }
        int row1[20] = {}, row2[20] = {};
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++)
                if((i+j)%2)
                    row1[(i+j)/2]++;
                else
                    row2[(i+j)/2]++;
        }
        qsort(row1, sizeof(row1)/sizeof(*row1), sizeof(*row1), sort);
        qsort(row1, sizeof(row2)/sizeof(*row2), sizeof(*row2), sort);
        int dp1[20][20] = {}, dp2[20][20] = {};
        dp1[0][0] = 1, dp1[0][1] = row1[0];
        dp2[0][0] = 1, dp2[0][1] = row2[0];
        for(i = 1; i < n-1; i++) {
            dp1[i][0] = 1;
            for(j = 1; j <= row1[i]; j++)
                dp1[i][j] = dp1[i-1][j] + dp1[i-1][j-1]*(row1[i]-(j-1));
        }
        for(i = 1; i < n; i++) {
            dp2[i][0] = 1;
            for(j = 1; j <= row2[i]; j++)
                dp2[i][j] = dp2[i-1][j] + dp2[i-1][j-1]*(row2[i]-(j-1));
        }
        int ans = 0;
        for(i = 0; i <= k; i++)
            ans += dp1[n-2][i]*dp2[n-1][k-i];
        printf("%d\n", ans);
    }
    return 0;
}
