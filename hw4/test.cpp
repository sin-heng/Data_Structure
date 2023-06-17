#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
class Node{
    public:
        string type;
        string name;
        bool operator==(Node& rhs){return this->name == rhs.name;}
};
int** getEdgeArr(int n){
    int** arr = new int*[n+1];
    for(int i=0;i<n+1;i++){
        arr[i] = new int[n];
        for(int j=0;j<n+1;j++) arr[i][j] = INT_MAX;
    }
    return arr;
}
void getEdge(int** arr){
    int i,j,dis;
    cin >> i >> j >> dis;
    arr[i][j] = arr[j][i] = dis;
}
int analyze(vector<Node>& v,int n){
    int mes=0,min=INT_MAX;
    if(!v.empty()) return mes;
    for(auto i:v){

    }

}
void display(vector<Node>& v,int mes){
    auto it = v.begin();
    cout << it->name;
    it++;
    for(;it!=v.cend();it++) cout << " -> " << it->name;
    cout << endl;
    cout << mes << endl;
    double dis = ceil(1000/mes);
    cout << dis << endl;
}
int main(){
    vector<Node> route;
    string cmd;
    int** Mes=NULL;
    int n=0,mes=0;
    while(cin >> cmd){
        if(cmd=="INSERT"){
            Node* n = new Node;
            cin >> n->type >> n->name;
            n++;
            route.insert(route.cend(),*n);
        }
        else if(cmd=="INSERT_EDGE"){
            if(Mes==NULL) getEdgeArr(n);
            getEdge(Mes);
        }
        else if(cmd=="ANALYZE"){
            mes = analyze(route,n);
            display(route,mes);
        }
    }
    return 0;
}