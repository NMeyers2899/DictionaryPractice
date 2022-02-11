#include <iostream>
#include "Dictionary.h"

int main()
{
    Dictionary<char, int> dictionary = Dictionary<char, int>();
    dictionary.addItem('a', 3);
}