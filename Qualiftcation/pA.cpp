#include <cstdio>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d-%d-%d\n", &a, &b, &c);
    if((b == 9 && c <= 16) || b < 9)
        printf("GOOD\n");
    else
        printf("TOO LATE\n");
    return 0;
}