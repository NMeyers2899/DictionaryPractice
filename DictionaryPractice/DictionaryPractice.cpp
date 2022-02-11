#include <iostream>
#include "Dictionary.h"

int main()
{
    Dictionary<char, int> dictionary = Dictionary<char, int>();
    dictionary.addItem('a', 3);
    char key = 'a';
    if (dictionary.containsKey(key))
        std::cout << key << std::endl;
    if (dictionary.remove(key))
        std::cout << "Item Removed" << std::endl;
}