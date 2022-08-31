#include<bits/stdc++.h>
using namespace std;

int proximoGap(int gap) {
    gap = (gap*10)/13;
    if (gap < 1)
        return 1;
    return gap;
}
 
void combSort(int a[], int n) {
    int gap = n;
    bool trocado = true;
 
    while (gap != 1 || trocado == true) {
        gap = proximoGap(gap);
        trocado = false;
        
        for (int i=0; i<n-gap; i++) {
            if (a[i] > a[i+gap]) {
                swap(a[i], a[i+gap]);
                trocado = true;
            }
        }
    }
}
 
int main()
{
    int a[] = {9, 2, 1, 99, 3, -99, 23, -14, 28, 0, 13, 49};
    int n = sizeof(a)/sizeof(a[0]);
 
    combSort(a, n);
 
    printf("Array ordenada: \n");
    for (int i=0; i<n; i++)
        printf("%d ", a[i]);
    return 0;
}