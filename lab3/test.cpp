#include<iostream>
#include<string>
using namespace std;
class Node{
    friend class Tree;
    friend long long traverse(Node* root);
    public:
        Node(char c,int i):type(c),point(i){
            left = NULL;
            right = NULL;
        };
    private:
        char type;
        int point;
        Node* left,* right;
};
class Tree{
    public:
        Tree(){
            root = new Node('r',-1);
            total=0;
        }
        void InsertC(){
            if(root->left==NULL) root->left = new Node('C',1);
            else if(root->right==NULL) root->right = new Node('C',1);
        }
        void InsertD(){
            if(root->left==NULL && root->right==NULL) return;//both NULL
            else if(root->left!=NULL && root->right!=NULL){//both not NULL
                if(root->right->point < root->left->point){
                    Node* tmp = root->right;
                    root->right = new Node('D',3);
                    root->right->right = tmp;
                }
                else{
                    Node* tmp = root->left;
                    root->left = new Node('D',3);
                    root->left->left = tmp;
                }
            }
            else if(root->left!=NULL && root->right==NULL){
                Node* tmp = root->left;
                root->left = new Node('D',3);
                root->left->left = tmp;
            }
            else if(root->right!=NULL && root->left==NULL){
                Node* tmp = root->right;
                root->right = new Node('D',3);
                root->right->right = tmp;
            }
        }
        void InsertH(){
            if(root->left!=NULL && root->right!=NULL){
                int itmp = traverse(root->left) - traverse(root->right);
                Node* tmp = root->left;
                root->left = new Node('H',itmp);
                root->left->left = tmp;
                root->left->right = root->right;
                root->right = NULL;
                total += itmp;
                //cout << total << endl;
            }
        }
        Node* getRoot(){return root;}
        void print(){
            cout << total << endl;
        };
    private:
        Node* root=NULL;
        long long total;
};
long long traverse(Node* root){
    if(root!=NULL){
        long long sum = root->point;
        sum+=traverse(root->left);
        sum+=traverse(root->right);
        return sum;
    }
    else return 0;
}
int main(void){
    Tree tree;
    string str;
    while(getline(cin,str)&&str.compare("Spade")!=0){
        if(str[0]=='C') tree.InsertC();
        else if(str[0]=='D') tree.InsertD();
        else if(str[0]=='H') tree.InsertH();
    }
    tree.print();
    return 0;
}