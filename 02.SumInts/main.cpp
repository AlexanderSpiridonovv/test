#include <iostream>
int sumInts(int* arr, int size){
    int sum = 0;
    for(int i= 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}
int main(){
    int arr[] = {3, 6, -1, 2};
    std::cout<<sumInts(arr, 4)<<std::endl;
}