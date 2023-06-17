#include<iostream>
#include<string>
using namespace std;
class Node{
    friend class Tree;
    friend void preorder(Node* root);
    public:
        Node(){
            star = 0;
            left = NULL;
            right = NULL;
        }
        Node(int n):star(n){
            left = NULL;
            right = NULL;
        }
    private:
        Node* left,* right;
        int star;
};
class Tree{
    public:
        Tree(){
            root = new Node(-1);
            total=0;
        }
        ~Tree(){
            delete root;
        }
        void summon(int n){
            Node* newOne = NULL;
            if(n<=4){
                newOne = new Node(n);
                if(root->left==NULL) root->left = newOne; // left is empty
                else if(root->right==NULL) root->right = newOne; // left is full, but right is empty
                else if(root->right->star < root->left->star){ // both left and right are full, but right is lower than left
                    newOne->right = root->right;
                    root->right = newOne;
                }
                else{ // both left and right are full, but left is equal or lower than right
                    newOne->left = root->left;
                    root->left = newOne;
                }
            }
            else if(5<=n && n<=6){
                // don't have any monster
                if(root->left==NULL && root->right==NULL) return;
                newOne = new Node(n);
                if(root->left==NULL){ //only has right one
                    newOne->right = root->right;
                    root->right = newOne;
                }
                else if(root->right==NULL){ // only has left one
                    newOne->left = root->left;
                    root->left = newOne;
                }
                else if(root->right->star < root->left->star){ // both exist, sacrifice right
                    newOne->right = root->right;
                    root->right = newOne;
                }
                else{ // both exist, sacrifice left
                    newOne->left = root->left;
                    root->left = newOne;
                }
            }
            else if(7<=n && n<=8){
                // don't have two monsters
                if(root->left==NULL || root->right==NULL) return;
                newOne = new Node(n);
                newOne->left = root->left;
                newOne->right = root->right;
                root->left = newOne;
                root->right = NULL;
            }
        }
        void attack(){
            if(root->left!=NULL)
                total += root->left->star;
            if(root->right!=NULL)
                total += root->right->star;
        }
        void display(){
            preorder(root);
            cout << "\n" << total << "\n";
        }
    private:
        Node* root;
        int total;
};
// global
bool is_first = true;
void preorder(Node* root){
    if(root!=NULL){
        if(root->star!=-1 && is_first!=true) cout << " " << root->star << "*";
        else if(root->star!=-1 && is_first==true){
            is_first = false;
            cout << root->star << "*";
        }
        preorder(root->left);
        preorder(root->right);
    }
}
int main(void){
    Tree tree;
    int star;
    char ch;
    while(true){
        ch = getchar();
        if(ch=='S'){
            while(ch!='>') ch = getchar();
            getchar();
            cin >> star;
            tree.summon(star);
        }
        else if(ch=='A') tree.attack();
        else if(ch=='T') break;
        while(ch!='\n') ch = getchar();
    }
    tree.display();
    return 0;
}