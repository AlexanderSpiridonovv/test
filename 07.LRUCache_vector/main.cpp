#include <iostream>
#include "LRUCacheVector.h"

using namespace std;

int main() 
{
    cout << "Enter cache capacity: ";
    unsigned n;
    cin >> n;
    LRUCache cache(n);

    cout << "\nCommands:\n"
         << "  p - put key and value\n"
         << "  g - get value by key\n"
         << "  q - quit\n\n";

    while (true) 
    {
        cout << "> ";
        char cmd;
        cin >> cmd;

        if (cmd == 'q') 
            break;

        if (cmd == 'p') 
        {
            int key, val;
            cout << "Enter key and value: ";
            cin >> key >> val;
            cache.put(key, val);
        } 
        else if (cmd == 'g') 
        {
            int key;
            cout << "Enter key: ";
            cin >> key;
            int result = cache.get(key);
            if (result == -1)
                cout << "Key not found.\n";
            else
                cout << "Value: " << result << '\n';
        } 
        else 
        {
            cout << "Invalid command.\n";
        }

        cout << "Cache state: ";
        cache.printAllValues();
        cout << '\n';
    }

    cout << "Goodbye!\n";
    return 0;
}
