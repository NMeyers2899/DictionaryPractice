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
	~Dictionary<TKey, TValue>() {};

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
	bool tryGetValue(const TKey key, const TValue& value) const;

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
	Dictionary<TKey, TValue>& operator=(const Dictionary<TKey, TValue> other) const;

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
inline void Dictionary<TKey, TValue>::clear()
{
	for (int i = 0; i < m_count; i++)
		delete m_items[i];

	m_count = 0;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	for (int i = 0; i < m_count; i++) 
	{
		if (m_items[i].TKey == object)
			return true;
	}

	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	for (int i = 0; i < m_count; i++) 
	{
		if (m_items[i].TValue == object)
			return true;
	}

	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, const TValue& value) const
{
	for (int i = 0; i < m_count; i++) 
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
	Item* tempArray = new Item[m_count + 1];

	for (int i = 0; i < m_count; i++) 
	{
		if (m_items[i].TKey == key)
			return;

		tempArray[i] = m_items[i];
	}

	tempArray[m_count].TKey = key;
	tempArray[m_count].TValue = value;

	m_items = tempArray;
	m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	Item* tempArray = new Item[m_count - 1];
	int j = 0;
	bool isItemRemoved = false;

	for (int i = 0; i < m_count; i++) 
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
	Item* tempArray = new Item[m_count - 1];
	int j = 0;
	bool isItemRemoved = false;

	for (int i = 0; i < m_count; i++)
	{
		if (m_items[i].TKey != key && m_items[i].TValue != value)
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
inline int Dictionary<TKey, TValue>::getCount() const
{
	return m_count;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other) const
{
	for (int i = 0; i < other.m_count; i++)
		m_items[i] = other.m_items[i];

	m_count = other.m_count;

	return this;
}