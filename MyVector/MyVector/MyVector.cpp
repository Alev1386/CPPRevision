#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector
{
private:
	size_t size;
	size_t capacity;
	T* data;

	void resizeCapacity() {
		size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
		T* newData = new T[newCapacity];

		for (size_t i = 0; i < size; i++)
		{
			newData[i] = data[i];
		}

		delete[] data;
		data = newData;
		capacity = newCapacity;
	}

	void shrink_to_fit() {
		if (capacity > size)
		{
			size_t newCapacity = size;
			T* newData = new T[newCapacity];

			for (size_t i = 0; i < size; i++)
			{
				newData[i] = data[i];
			}

			delete[] data;
			data = newData;
			capacity = newCapacity;
		}
	}

public:
	MyVector() : data(nullptr), size(0), capacity(0) {}

	~MyVector() {
		delete[] data;
	}

	void push_back(const T& value) {
		if (size >= capacity)
		{
			resizeCapacity();
		}
		data[size++] = value;
	}

	void pop_back() {
		if (size > 0)
		{
			size--;
		}
		shrink_to_fit();
	}

	T& operator[](size_t index) {
		if (index >= size)
		{
			throw std::out_of_range("Index is out of bounds!");
		}
		return data[index];
	}

	size_t getSize() {
		return size;
	}

	size_t getCapacity() {
		return capacity;
	}

	void insert(const T& value, size_t index) {
		if (index >= size)
		{
			push_back(value);
		}
		else
		{
			while (capacity <= size+1)
			{
				resizeCapacity();
			}
			for (size_t i = size-1; i >= index; i--)
			{
				data[i + 1] = data[i];
			}
			data[index] = value;
			size++;
		}
	}
	void erase(size_t index) {
		if (index >= size)
		{
			return;
		}
		else
		{
			for (size_t i = index; i < size; i++)
			{
				data[i] = data[i + 1];
			}
			size--;
		}
		shrink_to_fit();
	}


};

int main()
{
	MyVector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	for (size_t i = 0; i < vec.getSize(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << vec.getCapacity() << std::endl << std::endl;

	vec.insert(5,1);

	for (size_t i = 0; i < vec.getSize(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
	std::cout << vec.getCapacity() << std::endl << std::endl;

	vec.erase(2);

	for (size_t i = 0; i < vec.getSize(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << vec.getCapacity() << std::endl << std::endl;

}