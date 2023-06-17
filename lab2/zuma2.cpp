#include<iostream>
using namespace std;
class ChainNode{
    friend class Chain;
    public:
        ChainNode(int n,char c):index(n),color(c){
            left = NULL;right = NULL;
        };
    private:
        ChainNode* left,* right;
        int index,used;
        char color;
};
class Chain{
    public:
        Chain(char c);
        void Insert(char c);
        void Double(int count);
        void Eliminate();
        void Reverse();
        void display();
        void func();
        void throwBead(int n,char c);
    private:
        ChainNode* head,* cursor,* start,* end;
        int index;
};
int main(void){
    int N,m;
    char C,ctmp;
    cin >> N >> m;
    getchar(); // space;
    cin >> C;
    getchar(); // '\n'
    cin >> ctmp;
    Chain chain1(ctmp);
    for(int i=0;i<N-1;i++){
        getchar(); // '\n'
        cin >> ctmp;
        chain1.Insert(ctmp);
    }
    //chain1.display();
    chain1.throwBead(m,C);
    chain1.display();
    return 0;
}
Chain::Chain(char c){
    index=1;
    head = new ChainNode(index,c);
    cursor = head;
    head->used=0;
    index++;
}
void Chain::Insert(char c){
    cursor->right = new ChainNode(index,c);
    cursor->right->left = cursor;
    cursor = cursor->right;
    cursor->used = 0;
    index++;
}
void Chain::Double(int count){
    //cout << "double start\n";
    //cout << "start: " << start->index << ", end: " << end->index << endl;
    ChainNode* left = start->left,* right = end->right;
    cursor->right = start;
    start->left = cursor;
    cursor = end;
    for(int i=0;i<count;i++) Insert('G');
    // reconnect
    left->right = right;
    right->left = left;
    ChainNode* tmp = start;
    while(tmp!=cursor){
        tmp->used = 1;
        tmp = tmp->right;
    }
    tmp->used = 1;
    start = left;end = right;
    //cout << "double end\n";
    //this->display();
    this->func();
}
void Chain::Eliminate(){
    //cout << "eliminate start\n";
    ChainNode* before = start->left,* after = end->right;
    before->right = after;
    after->left = before;
    ChainNode* tmp = head;
    // renew cursor
    while(tmp->right!=NULL) tmp = tmp->right;
    cursor = tmp;
    // eliminate
    tmp = start->right;
    while(tmp!=end){
        delete tmp->left;
        tmp = tmp->right;
    }
    delete tmp->left;
    delete tmp;
    start = before;end = after;
    //cout << "eiliminate end\n";
    //this->display();
    this->func();
}
void Chain::Reverse(){
    //cout << "reverse start\n";
    ChainNode* re_l = start->left,* re_r = end->right;
    // to head
    //cout << "start: " << start->index << ", end: " << end->index << endl;
    start->left->right = end->right;
    end->right->left = start->left;
    end->right = head;
    head->left = end;
    head = start;
    head->left = NULL;
    // reverse
    ChainNode* tmp = head,* tmp2 = NULL;
    while(tmp!=NULL){
        tmp2 = tmp->left;
        tmp->left = tmp->right;
        tmp->right = tmp2;
        tmp = tmp->left; 
    }
    tmp2 = head;
    head = cursor;
    cursor = tmp2;
    ChainNode* tmp3 = start;
    while(tmp3!=end){
        tmp3->used = 1;
        tmp3 = tmp3->left;
    }
    tmp3->used = 1;
    tmp3 = start;
    start = end;
    end = tmp3;
    start = re_r;
    end = re_l;
    //cout << "start: " << start->index << ", end: " << end->index << endl;
    //cout << "reverse end\n";
    //this->display();
    this->func();
}   
void Chain::display(){
    ChainNode* tmp = head->right;
    int count=1;
    if(head==NULL){
        cout << "\n" << count << endl;
        return;
    }
    cout << head->color;
    while(tmp!=NULL){
        count++;
        cout << " " << tmp->color;
        tmp = tmp->right;
    }
    cout << "\n" << count << endl;
}
void Chain::func(){
    int count_l = 0,count_r = 0;
    ChainNode* tmp = start;
    while(tmp!=NULL && tmp->color==start->color && tmp->used!=1){
        count_l++;
        tmp = tmp->left; 
    }
    start = tmp->right;
    tmp = end;
    while(tmp!=NULL && tmp->color==end->color && tmp->used!=1){
        count_r++;
        tmp = tmp->right; 
        //cout << "index: " << tmp->index << endl;
    }
    end = tmp->left;
    //cout << "flag\n";
    //cout << count_l + count_r -1 << endl;
    if(count_l + count_r>=3){
        if(start->color == 'G') this->Double(count_l + count_r);
        else if(start->color == 'R') this->Eliminate();
        else if(start->color == 'B') this->Reverse();
        //else cout << "nothing matched\n";
    }
    //else cout << "count not matched\n";
}
void Chain::throwBead(int n,char c){
    ChainNode* tmp = head,* tmp2 = cursor,* next = NULL;
    while(tmp->index!=n) tmp = tmp->right;
    cursor = tmp;
    next = tmp->right;
    this->Insert(c);
    next->left = cursor;
    cursor->right = next;
    cursor = tmp2;
    start = tmp;
    end = tmp->right;
    //cout << "throwbead end\n";
    this->func();
}