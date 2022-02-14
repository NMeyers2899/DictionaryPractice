#include <iostream>
#include "Dictionary.h"

int main()
{
    Dictionary<char, int> dictionary = Dictionary<char, int>();
    dictionary.clear();
    dictionary.addItem('c', 6);
    dictionary.addItem('a', 3);
    dictionary.remove('a');
    dictionary.remove('a');
    dictionary.addItem('v', 15);
    int value = 0;
    dictionary.remove('a', value);
    std::cout << value << std::endl;
}