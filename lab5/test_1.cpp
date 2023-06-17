// must compile with c++17 and above
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
struct Something {
    int a;
    int b;
    long long c;
};
int main()
{
    std::vector<Something> v;
    vector<string> name;
    string tmp;
    long long n,m;
    cin >> n >> m;
    if(m==0) return 0;
    //input data and initialize
    for(long long i=0;i<m;i++){
        cin >> tmp;
        name.insert(name.end(),tmp);
        Something* s = new Something;
        s->a = s->b = 0;
        s->c = i;
        v.insert(v.end(),*s);
    }
    //get first data
    if(n!=0) for(auto& i:v) cin >> i.b;
    //get other data and process
    for(long long i=1;i<n;i++){
        for(auto& k:v){
            int itmp = 0;
            cin >> itmp;
            k.a += abs(k.b - itmp);
            //cout <<"::" <<  i.a << endl;
            k.b = itmp;
        }
    }
    // sort a vector, use stable_sort if order has to be persisted
    std::sort(v.begin(), v.end(), [](auto& left, auto& right) {
        return left.a < right.a;
    });
    // vector is now sorted in ascending order
    //for(auto& i:v) cout << i.a << endl;
    cout << name[v.cbegin()->c] << endl;
    return 0;
}