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
	/// <returns> If all elements in the dictionary are the same. </returns>
	const Dictionary<TKey, TValue>& operator=(Dictionary<TKey, TValue> other);

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
	for (int i = 0; i < getCount(); i++)
		remove(m_items[i].TKey, m_items[i].TValue);

	m_count = 0;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	for (int i = 0; i < getCount(); i++) 
	{
		if (m_items[i].TKey == object)
			return true;
	}

	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	for (int i = 0; i < getCount(); i++) 
	{
		if (m_items[i].TValue == object)
			return true;
	}

	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value) const
{
	for (int i = 0; i < getCount(); i++) 
	{
		if (m_items[i].TKey == key) 
		{
			value = m_items[i].TValue;
			return true;
		}
	}

	return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	Item* tempArray = new Item[getCount() + 1];

	for (int i = 0; i < getCount(); i++) 
	{
		if (m_items[i].TKey == key)
			return;

		tempArray[i] = m_items[i];
	}

	tempArray[getCount()].TKey = key;
	tempArray[getCount()].TValue = value;

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
		if (m_items[i].TKey != key)
		{
			tempArray[j] = m_items[i];
			j++;
		}
		else
			isItemRemoved = true;
	}

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
		if (m_items[i].TKey != key)
		{
			tempArray[j] = m_items[i];
			j++;
		}
		else 
		{
			value = m_items[i].TValue;
			isItemRemoved = true;
		}
	}

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
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(Dictionary<TKey, TValue> other)
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
