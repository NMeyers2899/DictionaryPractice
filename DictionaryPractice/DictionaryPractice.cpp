#include <iostream>
#include "Dictionary.h"

int main()
{
    // Creating an empty dictionary.
    Dictionary<int, char> dictionary = Dictionary<int, char>();
    Dictionary<int, char> dictionary2 = Dictionary<int, char>();

    // Proof of adding keys and values.
    dictionary.addItem(1, 'a');
    dictionary.addItem(2, 'c');

    // Should print out a.
    std::cout << dictionary[1] << std::endl;

    // Can remove elements and removing something that is not there will not break the list.
    char value;
    dictionary.remove(2, value);
    // Should print out "Removed value was c".
    std::cout << "Removed value was " << value << std::endl;
    dictionary.remove(2);
}