#pragma once
template <typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	/// <summary>
	/// Add a new item to the end of the array
	/// </summary>
	/// <param name="item">The item to add</param>
	void addItem(T* item);

	/// <summary>
	/// Remove a item from the array
	/// </summary>
	/// <param name="item">The item to remove</param>
	bool removeItem(T* item);

	/// <summary>
	/// Insertion sort items
	/// </summary>
	void sortItems();

	/// <summary>
	/// Gets an item at a specific index
	/// </summary>
	/// <param name="index">The index in the array</param>
	/// <returns>The item</returns>
	T* getItem(int index);

	/// <summary>
	/// Gets the length of the array
	/// </summary>
	/// <returns>Array length</returns>
	int getLength() { return m_length; }

private:
	T** m_items;
	int m_length;
};

template<typename T>
inline void DynamicArray<T>::addItem(T* item)
{
	T** newArray = new T * [m_length + 1];

	for (int i = 0; i < m_length; i++)
	{
		newArray[i] = m_items[i];
	}

	newArray[m_length] = item;
	m_items = newArray;
	m_length++;
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T* item)
{
	if (!item || m_length <= 0)
		return false;

	bool itemRemoved = false;

	T** newArray = new T * [m_length - 1];

	int j = 0;

	for (int i = 0; i < m_length; i++)
	{
		if (item != m_items[i])
		{
			newArray[j] = m_items[i];
			j++;
		}
		else
		{
			itemRemoved = true;
		}
	}

	if (itemRemoved)
	{
		m_items = newArray;
		m_length--;
	}

	return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
	T j, key;

	//For each value in array
	for (int i = 1; i < m_length; i++)
	{
		//Set key to value at the current index
		key = m_items[i];
		//Set j to be the previous index
		j = i - 1;

		//While j is greater than or equal to 0 and the value at j is greater than the key
		while (j >= 0 && m_items[j] > key)
		{
			//Set value at the index of j + 1 to be the value at the index of j
			m_items[j + 1] = m_items[j];
			//Decrement j
			j--;
		}
		//Set value at the index of j + 1 to be the key
		m_items[j + 1] = key;
	}
}

template<typename T>
inline T* DynamicArray<T>::getItem(int index)
{
	if (index < 0 || index >= m_length)
		return nullptr;

	return m_items[index];
}
