#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 998424335

int pow2(int x);
float average(int x, int y);
int max(int x, int y);
void displaySteps(int n, char ch);
void displayMultsRows(int n);

char ToUpper(char ch);

bool isPrime[100000];

int main() {
    int N = 3;
    printf("%d\n", pow2(N));
    printf("%f\n", average(8, 3));
    printf("%d\n", max(199, 89));
    displaySteps(6, 'u');

    for(int i = 1; i <= 9; i++) displayMultsRows(i);

    printf("\n");
    char str[100];
    strcat(str, "Hello World!");
    for (int i = 0; i < strlen(str); i++) {
        str[i] = ToUpper(str[i]);
    }
    printf("%s\n", str);

}

int pow2(int x) {
    return (x * x);
}

float average(int x, int y) {
    return ((x + y) / 2);
}

int max(int x, int y) {
    int res;
    if (x < y) res = y;
    else res = x;
    return res;
}

void displaySteps(int n, char ch) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }
}

void displayMultsRows(int n) {
    for (int i = 1; i < 10; i++) {
        printf("%2d ", (i*n));
    }
    printf("\n");
}

char ToUpper(char ch) {
    if ('a' <= ch && ch <= 'z') {
        ch = ch - ('a' - 'A');
    }
    return ch;
}

void divisions(int n) {
    for (int i = 3; i < n; i+=2) {
        if n % i == 0 {
            
        }
    }
}