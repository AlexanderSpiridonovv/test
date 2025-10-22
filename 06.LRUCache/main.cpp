#include <iostream>
#include "LRUCache.h"

using namespace std;
int main(int argc, const char** argv) 
{
    cout<<"Input capacity"<<endl;
    unsigned n;
    cin >> n;
    LRUCache cache(n);
    while(true)
    {
        cout<<"Press 'p' for putting, 'g' for getting and 'q' for quitting"<<endl;
        char input;
        cin >> input;
        if(input == 'q') 
        {
            break;
        }
        else if(input == 'p')
        {
            cout<< "Input key and val"<<endl;
            int key,val;
            cin>> key >> val;
            cache.put(key,val);
            cache.printAllValues();
        }
        else if(input == 'g')
        {
            cout<< "Input key"<<endl;
            int key;
            cin>> key;
            cache.get(key);
            cache.printAllValues();
        }
    }
}
