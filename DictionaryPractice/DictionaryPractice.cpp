#include <iostream>
#include "Dictionary.h"

int main()
{
    // Creating an empty dictionary.
    Dictionary<int, char> dictionary = Dictionary<int, char>();

    // Proof of adding keys and values.
    dictionary.addItem(1, 'a');
    dictionary.addItem(2, 'c');

    // Should print out a.
    std::cout << dictionary[1] << std::endl;

    // Gets the size of the list and displays it to the screen.
    std::cout << "Size of list : " << dictionary.getCount() << std::endl;

    // Demonstrates that the dictionary can find keys.
    if (dictionary.containsKey(1))
        std::cout << "Contains Key : 1" << std::endl;

    // Demonstrates that the dictionary can find keys.
    if (dictionary.containsValue('a'))
        std::cout << "Contains Value : a" << std::endl;

    // Can remove elements and removing something that is not there will not break the list.
    char value;
    dictionary.remove(2, value);
    // Should print out "Removed value was c".
    std::cout << "Removed value was " << value << std::endl;

    // Gets the size of the list again to show the user that it has changed.
    std::cout << "Size of list : " << dictionary.getCount() << std::endl;
}