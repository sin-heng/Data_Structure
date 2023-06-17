// must compile with c++17 and above
#include <iostream>
#include<string>
#include<cmath>
#define INT_MAX 2147483647
using namespace std;
int main()
{
    string* name;
    int** arr;
    long long n,m;

    cin >> n >> m;
    //dynamic allocate
    arr = new int*[m];
    for(long long i=0;i<m;i++) arr[i] = new int[n];
    name = new string[m];
    //input data
    for(long long i=0;i<m;i++){
        cin >> name[i];
    }
    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++)
            cin >> arr[i][j];
    }
    long long index=0,min=INT_MAX;
    for(long long i=0;i<m;i++){
        int total=0;
        for(long long j=0;j<n-1;j++){
            total+=abs(arr[j+1][i]-arr[j][i]);
        }
        //cout << "i: " << i << " ,total: " << total << endl;
        if(total<min){
            min = total;
            index=i;
        }
    }
    cout << name[index] << endl;
    //free dynamic array
    for(long long i=0;i<m;i++) delete [] arr[i];
    delete [] arr;
    delete [] name;
    return 0;
}