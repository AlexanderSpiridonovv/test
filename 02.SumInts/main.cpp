#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
//task 1
std::string reverseStr(const std::string& str){
    std::string temp = str;
    int len = temp.length();
    for(int i = 0; i < len/2; i++){
        std::swap(temp[i] , temp[len -i -1]);
    }
    return temp;
}


//task 2
int sumInts(int* arr, size_t size){
    int sum = 0;
    for(size_t i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}
int sumIntsByAccumulate(std::vector<int>& nums){
    return std::accumulate(nums.begin(), nums.end(), 0);
}

//task 3
int sumRandsDivisibleByThree(int* arr, size_t size){
    int sum = 0;
    for(size_t i = 0; i < size; i++){
        if(arr[i] % 3 == 0)
            sum += arr[i];
        else
            arr[i] = 0;
    }
    return sum;
}



//task 4
std::string getWord(const std::string& str, int& pos){
    std::string temp;
    int j = 0;
    for(int i = pos; i < str.length() && str[i] != ' '; i++){
        temp += str[i];
        j++;
    }
    pos += j+1;
    return temp;
}
void reverseText(const std::string& text){
    int pos = 0;
    std::stack<std::string> s;
    while(pos < text.length()){
        std::string temp = getWord(text,pos);
        if(! temp.empty())
        s.push(temp);
    }
    while(!s.empty()){
        std::cout<< s.top();
        s.pop();
        if(!s.empty())
            std::cout<< ' ';
    }
    std::cout<<std::endl;
}
int main(){
    reverseText("Egt is a good company to work for");
    std::cout<<reverseStr("top");
    int arr[] = {3, 6, -1, 2};
    std::cout<<sumInts(arr, 4)<<std::endl;
}