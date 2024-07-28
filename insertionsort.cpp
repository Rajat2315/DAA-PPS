//https://www.programiz.com/online-compiler/5WvFIJAnY3mX7


#include<iostream>
using namespace std;
int n,i,j=0;
void insertionSort(int n, int arr[])
{
    for (int i=1;i<n;i++)
    {
        int j=i-1;
        int x=arr[i];
        while (j>-1 && arr[j]>x)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n]={};
    for (int k=0;k<n;k++)
    {
        cin>>arr[k];
    }
    insertionSort(n,arr);
    for (int k=0;k<n;k++)
    {
        cout<<arr[k]<<"\t";
    }
}
