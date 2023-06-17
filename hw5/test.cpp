#include<iostream>
#include<vector>
#include<string>
struct Fruit {
    std::string      name;
    std::vector<int> hyperFeatures;
    int last_hyper; // to remember tha last used hyper number
};

struct GradBinHyperWeight {
    int                featureIdx;
    double             gradSlider;
    int                binThreshold;
    GradBinHyperWeight *backwardContinuation = nullptr;
    GradBinHyperWeight *forwardContinuation = nullptr;
    
    bool shouldBackward(Fruit& f) const
    {
        return f.hyperFeatures[featureIdx] < binThreshold;
    }
    void applyGradSlider(Fruit& f) const
    {
        f.hyperFeatures[featureIdx] = (int) ((double) f.hyperFeatures[featureIdx] * gradSlider);
    }
};
// insert node in order to build a tree
void InsertNode(GradBinHyperWeight* root,GradBinHyperWeight* g){
    // to bigger than root
    if(g->binThreshold>=root->binThreshold){
        // if right child already exist than recur again using right child as root
        if(root->forwardContinuation!=NULL) InsertNode(root->forwardContinuation,g);
        // if right child hasn't exist then insert
        else root->forwardContinuation = g;
    }
    // if smaller than root
    else{
        // same as above
        if(root->backwardContinuation!=NULL) InsertNode(root->backwardContinuation,g);
        else root->backwardContinuation = g;
    }
}
std::vector<Fruit> Sort(std::vector<Fruit> f,GradBinHyperWeight* root){
    std::vector<Fruit> left;
    std::vector<Fruit> right;
    // first use garde slider, and split array to left and right part
    for(auto i:f){
        root->applyGradSlider(i);
        if(root->shouldBackward(i)) left.insert(left.end(),i);
        else right.insert(right.end(),i);
    }

    if(left.size()==0) return left; // if empty, then return an empty vector
    else if(left.size()==1){ // if only one elment, then get "last_hyper" 
        left.begin()->last_hyper = left.begin()->hyperFeatures[root->featureIdx];
    }
    else left = Sort(left,root->backwardContinuation); // if more than one element then sort again

    // same as above
    if(right.size()==0) return right;
    else if(right.size()==1){
        right.begin()->last_hyper = right.begin()->hyperFeatures[root->featureIdx];
    }
    else right = Sort(right,root->forwardContinuation);

    // merge right to left
    for(auto i:right) left.insert(left.end(),i);
    return left;
}
int main(){
    int N,M,tmp;
    std::cin >> N >> M;
    std::vector<Fruit> fruit;
    while(N--){
        Fruit f;
        std::cin >> f.name;
        for(int i=0;i<M;i++){
            std::cin >> tmp;
            (f.hyperFeatures).insert(f.hyperFeatures.end(),tmp);
        }
        fruit.insert(fruit.end(),f);
    }
    GradBinHyperWeight* root = new GradBinHyperWeight;
    std::cin >> M;
    std::cin >> root->featureIdx >> root->gradSlider >> root->binThreshold;
    while(M--&&M>=1){
        GradBinHyperWeight* node = new GradBinHyperWeight;
        std::cin >> node->featureIdx >> node->gradSlider >> node->binThreshold;
        InsertNode(root,node);
    }
    fruit = Sort(fruit,root);
    for(auto i:fruit) 
        std::cout << i.name << " " << i.last_hyper << std::endl;
    return 0;
}