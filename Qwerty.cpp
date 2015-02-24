/**\file Qwerty.cpp*/
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

void qs(int* s_arr, int first, int last) ///magic
{
    int i = first, j = last, x = s_arr[(first + last) / 2];
 
    do {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;
 
        if(i <= j) {
			if (s_arr[i] > s_arr[j]) { int t=s_arr[i]; s_arr[i]=s_arr[j]; s_arr[j]=t; }
            i++;
            j--;
        }
    } while (i <= j);
 
    if (i < last)
        qs(s_arr, i, last);
    if (first < j)
        qs(s_arr, first, j);
}

void main()
{
	int n, *arr;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for (int i=0; i<n; i++)
		scanf("%d",arr+i);
	qs(arr,0,n-1);
	for (int i=0; i<n; i++)
		printf("%d ",arr[i]);
	getch();
}