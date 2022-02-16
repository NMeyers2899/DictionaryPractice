#pragma once

template<typename TKey, typename TValue>
class Dictionary
{
public:
	/// <summary>
	/// A basic constructor for a dictionary.
	/// </summary>
	Dictionary<TKey, TValue>() {};

	/// <summary>
	/// A constructor that makes a copy of an established dictionary.
	/// </summary>
	/// <param name="other"> The dictionary being copied. </param>
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);

	/// <summary>
	/// A deconstructor for a dictionary.
	/// </summary>
	~Dictionary<TKey, TValue>();

	/// <summary>
	/// Deletes all items in the dictionary.
	/// </summary>
	void clear();

	/// <summary>
	/// Checks the dictionary to see if it contains a particular key.
	/// </summary>
	bool containsKey(const TKey object) const;

	/// <summary>
	/// Checks the dictionary to see if it contains a particular value.
	/// </summary>
	bool containsValue(const TValue object) const;

	/// <summary>
	/// Attempts to find a value with a given key.
	/// </summary>
	bool tryGetValue(const TKey key, TValue& value) const;

	/// <summary>
	/// Attempts to add an item to the dictionary.
	/// </summary>
	/// <param name="key"> The key that will point to the new value. </param>
	/// <param name="value"> The value that the key will point to. </param>
	void addItem(const TKey& key, const TValue& value);

	/// <summary>
	/// Attempts to remove an item from the dictionary by using its associated key.
	/// </summary>
	bool remove(const TKey key);

	/// <summary>
	/// Attempts to remove an item that has both the given key and value.
	/// </summary>
	bool remove(const TKey key, TValue& value);

	/// <summary>
	/// Gets the amount of items in the dictionary.
	/// </summary>
	int getCount() const;

	/// <summary>
	/// An operator that checks to see if two dictionaries are equal.
	/// </summary>
	const Dictionary<TKey, TValue>& operator=(Dictionary<TKey, TValue>& other);

	/// <summary>
	/// Takes in a key and returns the value of that key if it could be found.
	/// </summary>
	TValue operator[](const TKey key);

private:
	struct Item
	{
	public:
		TKey TKey;
		TValue TValue;
	};

	Item* m_items = nullptr;
	int m_count = 0;
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(const Dictionary<TKey, TValue>& other)
{
	m_items = other.m_items;
	m_count = other.m_count;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::~Dictionary()
{
	clear();
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	// Goes through the list and removes each element within.
	for (int i = 0; i < getCount(); i++)
		remove(m_items[i].TKey);

	m_count = 0;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	// Searches through the list.
	for (int i = 0; i < getCount(); i++) 
	{
		// If the key is the same as the object...
		if (m_items[i].TKey == object)
			// ...return that the item has been found.
			return true;
	}

	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	// Searches through the list.
	for (int i = 0; i < getCount(); i++) 
	{
		// If the value is the same as the object...
		if (m_items[i].TValue == object)
			// ...return that the item has been found.
			return true;
	}

	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value) const
{
	// Searches through the list.
	for (int i = 0; i < getCount(); i++) 
	{
		// If the value is the same as the object...
		if (m_items[i].TKey == key) 
		{
			// ...sets the value equal to the value associated with the key.
			value = m_items[i].TValue;
			return true;
		}
	}

	return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	// Creates a temporary array with one more indicies than the original items list.
	Item* tempArray = new Item[getCount() + 1];

	for (int i = 0; i < getCount(); i++) 
	{
		// If there is a key in the list with the same value as the given key...
		if (m_items[i].TKey == key)
			// ...return from the list.
			return;

		// Copies each value from the old list into the new one.
		tempArray[i] = m_items[i];
	}

	// Sets the last element of the new array equal to the given key and value.
	tempArray[getCount()].TKey = key;
	tempArray[getCount()].TValue = value;

	// Sets the old items array equal to the temporary array and increments the count.
	m_items = tempArray;
	m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	// If there are no items in the list...
	if (getCount() <= 0)
		// ...return false.
		return false;

	// Creates a temporary array, a variable to track the iteration of the second list, and a bool
	// to keep track of if an item was removed or not.
	Item* tempArray = new Item[getCount() - 1];
	int j = 0;
	bool isItemRemoved = false;

	for (int i = 0; i < getCount(); i++) 
	{
		// As long as the item is not the same as the given key...
		if (m_items[i].TKey != key)
		{
			// ...copy the elements of the original list into the temporary array and increment j.
			tempArray[j] = m_items[i];
			j++;
		}
		// If it is the same...
		else
			// ...skips incrementing j and sets isItemRemoved to true.
			isItemRemoved = true;
	}

	// Sets the items array to the temporary array and decrements the count.
	m_items = tempArray;
	m_count--;

	return isItemRemoved;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	// If there are no items in the list...
	if (getCount() <= 0)
		// ...return false.
		return false;

	// Creates a temporary array, a variable to track the iteration of the second list, and a bool
	// to keep track of if an item was removed or not.
	Item* tempArray = new Item[getCount() - 1];
	int j = 0;
	bool isItemRemoved = false;

	for (int i = 0; i < getCount(); i++)
	{
		// As long as the item is not the same as the given key...
		if (m_items[i].TKey != key)
		{
			// ...copy the elements of the original list into the temporary array and increment j.
			tempArray[j] = m_items[i];
			j++;
		}
		// If it is the same...
		else 
		{
			// ...skips incrementing j, sets isItemRemoved to true and sets the given value to be
			// the value at that key.
			value = m_items[i].TValue;
			isItemRemoved = true;
		}
	}

	// Sets the items array to the temporary array and decrements the count.
	m_items = tempArray;
	m_count--;

	return isItemRemoved;
}

template<typename TKey, typename TValue>
inline int Dictionary<TKey, TValue>::getCount() const
{
	return m_count;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(Dictionary<TKey, TValue>& other)
{
	// Clears the list to add the new elements into it.
	clear();

	// For each element of the other's list, it adds those items to this one's list.
	for (int i = 0; i < other.getCount(); i++)
		addItem(other.m_items[i].TKey, other.m_items[i].TValue);

	// Sets this one's count equal to the other's count.
	m_count = other.getCount();

	return other;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	TValue value;
	// If the key can be found...
	if (tryGetValue(key, value))
		// ...return the value found at that key.
		return value;
	// If it cannot be found...
	else 
		// ...return an empty value.
		return TValue();
}