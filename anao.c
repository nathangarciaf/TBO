#include <stdio.h>

int main() {
    int n=0, m=0;
    scanf("%d %d", &n, &m);

    for(int i = n; i <= m; i++){
        for(int multiplicador = 1; multiplicador<=10; multiplicador++){
            printf("%d x %d = %d\n", i, multiplicador, i * multiplicador);
        }
    }

    return 0;
}