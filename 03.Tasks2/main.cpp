#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include "Animal.h"
#include "Leopard.h"
#include "Turtle.h"

std::vector<std::string> ReverseText(const std::string& text)
{
    std::istringstream iss(text);
    std::vector<std::string> v;
    std::string word;
    
    while(iss >> word) {
        v.push_back(word);
    }
    std::reverse(v.begin(),v.end());
    return v;
}
//task 1
bool isValidSymbol(const char& c){
    return c != ' ' 
        && c != ',' 
        && c != '.' 
        && c != '\n' 
        && c != '\t' 
        && c != '\0';
}
void wordCounter(const std::string& text){
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
    void deleteTree(Node* node){
        if(!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
public:
    SimpleBST() : root(nullptr){}
    SimpleBST(Node* ptr) : root(ptr){}
    ~SimpleBST(){ deleteTree(root); }

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
    nums = std::move(temp);
}

void SortOddNums(std::vector<int>& nums){
    auto newEnd = std::remove_if(nums.begin(), nums.end(), 
    [](int x) { return x % 2 == 0; });

    nums.erase(newEnd, nums.end());

    std::sort(nums.begin(), nums.end());
}

int main() 
{
    Leopard leo("Simba", 100);
    Turtle turtle("Franklin", 5);
    Leopard leo2("Leo", 80);
    
    // Print info
    std::cout << "Leopard: " << leo.GetName() << " - " << leo.GetSpeed() << " km/h\n";
    std::cout << "Turtle: " << turtle.GetName() << " - " << turtle.GetSpeed() << " km/h\n\n";
    
    // Race over 100 km
    std::cout << "Race over 100 km:\n";
    leo.Print(100);
    turtle.Print(100);
    
    // Change speeds
    leo.SetSpeed(120);
    turtle.SetSpeed(8);
    
    std::cout << "\nAfter speed change:\n";
    leo.Print(100);
    turtle.Print(100);
    
    // Test invalid speed
    try {
        leo.SetSpeed(150);
    } catch(std::invalid_argument& e) {
        std::cout << "\nError: " << e.what() << '\n';
    }
     std::cout << "\n=== Polymorphism with Pointers ===\n\n";
    
    std::vector<Animal*> zoo;
    zoo.push_back(&leo);
    zoo.push_back(&turtle);
    zoo.push_back(&leo2);

    std::cout << "All animals traveling 200 km:\n";
    for(Animal* animal : zoo) {
        animal->Print(200);
    }
    return 0;
}

// int main(){
//     std::vector<int> v = {5,6,1,7,11,1,3};
//     SortOddNums(v);
//     for(int x : v) std::cout<<x << ' ';
// }