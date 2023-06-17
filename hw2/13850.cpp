#include<iostream>
using namespace std;
class ChainNode{
    friend class Chain;
    public:
        ChainNode(int macaron = 0, ChainNode* left = NULL, ChainNode* right = NULL){
            macaron = macaron;
            left = left;
            right = right;
        }
    private:
        int macaron,index;
        ChainNode* left,* right;
};
class Chain{
    public:
        void Init();
        void FindCur(){current = target%10+1;};
        void Remove();
        void GetTarget();
        void PutBack();
        void display();
    private:
        ChainNode* head,* cursor;
        int count; // for plate's number
        int current,re_head,re_tail,target;
};
// global
ChainNode* pos[15];
int main(void){
    Chain chain1;
    chain1.Init();
    for(int i=0;i<100;i++){
        chain1.Remove();
        chain1.GetTarget();
        chain1.PutBack();
        chain1.FindCur();
        //chain1.display();
        //cout << "-----------" << endl;
    }
    chain1.display();
    return 0;
}
void Chain::Init(){
    count = 1;target=1,current=1;
    head = new ChainNode;cursor = head;
    pos[count] = head;
    head->index = count;
    count++;
    cin >> head->macaron;
    for(int i=0;i<9;i++){
        cursor->right = new ChainNode;
        cursor = cursor->right;
        pos[count] = cursor;
        cursor->index = count;
        count++;
        cin >> cursor->macaron;
    }
    cursor->right = head;
    head->left = cursor;
}
void Chain::Remove(){
    //cout << "remove start" << endl;
    ChainNode* tmp1 = pos[current],* tmp2 = tmp1->right;
    re_head = tmp2->index;
    for(int i=0;i<2;i++) tmp2 = tmp2->right;
    re_tail = tmp2->index;
    tmp2 = tmp2->right;
    // remove three plates
    tmp1->right = tmp2;
    tmp2->left = tmp1;
    //cout << "remove end" << endl;
}
void Chain::GetTarget(){
    //cout << "gettarget start" << endl;
    ChainNode* tmp = pos[current];
    int cur_num = tmp->macaron,num = 0,id=0,step=7;
    int max = cur_num,max_id = tmp->index,step_max=7;; // for maximum
    for(int i=1;i<=7;i++){
        tmp = tmp->right;
        if(tmp->macaron<cur_num && tmp->macaron>=num){
            if(tmp->macaron==num && ((7-i)<step || i<step)){
                num = tmp->macaron;
                step = (i<7-i)?i:7-i;
                id = tmp->index;
            }
            else if(tmp->macaron>num){
                num = tmp->macaron;
                step = (i<7-i)?i:7-i;
                id = tmp->index;
            }
        }
        if(tmp->macaron>max){
            max = tmp->macaron;
            max_id = tmp->index;
            step_max = (i<7-i)?i:7-i;
        }
        else if(tmp->macaron==max && ((7-i)<step_max || i<step_max)){
            max = tmp->macaron;
            max_id = tmp->index;
            step_max = (i<7-i)?i:7-i;
        }
    }
    if(num==0){target = max_id;}
    else target = id;
    // eat
    if(pos[target]->macaron<pos[target]->index) pos[target]->macaron+=(50-pos[target]->index);
    else pos[target]->macaron-=pos[target]->index;
    //cout << "gettarget end" << endl;
}
void Chain::PutBack(){
    //cout << "putback start" << endl;
    ChainNode* tmp = pos[target]->right;
    pos[target]->right = pos[re_head];
    pos[re_head]->left = pos[target];
    tmp->left = pos[re_tail];
    pos[re_tail]->right = tmp;
    // change
    int itmp = pos[re_head]->index;
    pos[re_head]->index = pos[re_tail]->index;
    pos[re_tail]->index = itmp;
    itmp = pos[re_head]->macaron;
    pos[re_head]->macaron = pos[re_tail]->macaron;
    pos[re_tail]->macaron = itmp;
    tmp = pos[re_head];
    pos[re_head] = pos[re_tail];
    pos[re_tail] = tmp;
    //cout << "putback end" << endl;
}
void Chain::display(){
    ChainNode* tmp = pos[target];
    for(int i=0;i<10;i++){
        cout << tmp->index << " / " << tmp->macaron << endl;
        tmp = tmp->right;
    }
}