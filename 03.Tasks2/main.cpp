#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <unordered_map>
#include <algorithm>

//task 1
bool isValidSymbol(const char c){
    return c != ' ' && c != ',' && c != '.' && c != '\0';
}
void wordCounter(const std::string text){
    std::unordered_map<std::string, int> mp;
    for(int i = 0; i < text.length(); i++){
        if(!isValidSymbol(text[i]))continue;

        std::string currentWord;

        for(int j = i; isValidSymbol(text[j]); j++){
            currentWord += text[j];
            i++;
        }
        mp[currentWord]++;
    }

    for(auto it = mp.begin(); it != mp.end(); it++){
        std::cout << it->first << " : "<<it->second <<std::endl;
    }
}

//task2
class Animal{
public:
    virtual void speed()const = 0;
    virtual ~Animal() = default;
};
class Leopard : public Animal{
public:
    void speed()const override{
        std::cout<<"Leopard runs at 60km/h";
    }
};
class Turtle : public Animal{
public:
    void speed()const override{
        std::cout<<"Turtle runs at 2km/h";
    }
};

//task3
/*

Imah ideq da gi vkarvam v BST, no vposledstvie razbrah che trqbva da se pravqt
promeni po podadeniq vector i taka samo usvozhnqvame neshtata


struct Node{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int n){
        value = n;
    }
};
class SimpleBST{
    Node* root;
    Node* insertHelper(Node* node, int val){
        if(!node)
            return new Node(val);
        
        if(val < node->value)
            node->left = insertHelper(node->left, val);
        else if(val > node->value)
            node->right = insertHelper(node->right, val);
        
        return node;
    }
    void inorder(Node* root)const{
        if(!root)
            return;
        inorder(root->left);
        std::cout<<root->value<< ' ';
        inorder(root->right);
    }
public:
    SimpleBST() : root(nullptr){}
    SimpleBST(Node* ptr) : root(ptr){}
    void insert(int val){
        root = insertHelper(root,val);
        std::cout<<std::endl;
    }
    void inorder(){
        inorder(root);
    }
};*/
void sortOddNums(std::vector<int>& nums){
    std::vector<int>temp;
    for(int x : nums){
        if(x%2 == 1)
            temp.push_back(x);
    }
    sort(temp.begin(), temp.end());
    nums = temp;
    for(int x:nums)
        std::cout<<x << ' ';
}
int main(){
    std::vector<int> nums = {7,8,3,1,9,4};
    sortOddNums(nums);
}