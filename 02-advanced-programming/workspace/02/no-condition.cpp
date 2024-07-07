#include<time.h>
#include<iostream>
#include<string>

using namespace std;




int main()
{
    int seed,stin;
    cin>>seed;
    stin=seed;
    srand(seed);
    seed=rand()%6+1;
    int array[7];
    string arr[7];
    array[1]=stin+1;
    array[4]=stin+1;
    arr[1]="Go to right ";
    arr[4]="Go to right ";
    array[2]=stin-1;
    array[5]=stin-1;
    arr[2]="Go to left ";
    arr[5]="Go to left ";
    array[3]=stin;
    array[6]=stin;
    arr[3]="Do not move ";
    arr[6]="Do not move ";
    cout<<arr[seed]<<array[seed];

}