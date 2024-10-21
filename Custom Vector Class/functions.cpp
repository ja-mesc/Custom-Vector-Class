#include "Header.h"
#include <iostream>

Vector::Vector()
	: size(0), capacity(10) {
	data = new int[capacity]; //allocate storage for initial array of 10 integers
} //initial capacity is 10 integers

//copy constructor to ensure deep copies are made
Vector::Vector(const Vector& other) { //pass by reference to avoid infinite loops
	capacity = other.capacity; //copy size and capacity
	size = other.size;
	
	data = new int[capacity]; //allocate new memory
	for (size_t i = 0; i < size; i++) { //copy the values over
		data[i] = other.data[i];
	}
}


//copy assignment operator creates a deep copy for when existing objects are assigned to one another
Vector& Vector::operator=(const Vector& other) {
	if (this == &other) {
		return *this; //if the memory addresses are the same, then no need to do anything
		//self -assignment check
	}

	delete[] data; //clear the memory associated to the current object

	size = other.size;
	capacity = other.capacity;

	data = new int[capacity];

	for (size_t i = 0; i < size; i++) {
		data[i] = other.data[i];
	}

	return *this; //returns current object by reference so that operations can be chained (a=b=c)
}

int& Vector::operator[](size_t index) { //using vec[i] to access elements
	if (index >= size) {
		throw std::out_of_range("Index out of bounds");
	}
	return data[index];
}

//move constructor
//this object moves data from an rvalue to a new object, leaving the rvalue in a valid state (usually empty or nullified)
Vector::Vector(Vector&& other) noexcept //takes in a reference to an rvalue and has no exceptions to avoid crashes
	: data(other.data), size(other.size), capacity(other.capacity) { //moves the data
	other.data = nullptr; //leaves object in a valid state.
	other.size = 0;
	other.capacity = 0;
}

//move assignment operator
//like the copy assignment operator, but moves data rather than copies (surprise!)
//return type is a pointer to an object
Vector& Vector::operator=(Vector&& other) noexcept {
	if (this != &other) { //self asignment check
		
		delete[] data; //free the space to move data into

		data = other.data;
		size = other.size;
		capacity = other.capacity; //move the data and values across 

		other.data = nullptr;
		other.size = 0;
		other.capacity = 0; //empty the object but leave it in a valid state.
	}

	return *this; //return the pointer to object.
}


Vector::~Vector() { //destructor
	delete[] data;
}

void Vector::push_back(int value) { //adding an element to the end
	//check if capacity is full
	if (size == capacity) {
		capacity *= 2; //double capacity
		int* newData = new int[capacity]; //create new array of doouble size
		for (int i = 0; i < size; i++) {
			newData[i] = data[i]; //copy over old elements
		}
		delete[] data; //deallocate the storage of the old array
		data = newData; //assign the new array to the name date
	}
	data[size] = value; //add new value to the size'th element of data
	size += 1; //increase the size by 1.
}

void Vector::pop_back() {
	if (size == 0) {
		throw std::underflow_error("Cannot pop from an empty vector.");
	}

	size -= 1;

	if (size < capacity / 2 && capacity >= 10) { //shrink the capacity when size<capacity/2
		capacity = capacity / 2;

		int* newData = new int[capacity];
		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}

	return;

}

//getter functions
size_t Vector::get_size(const Vector& vec) {
	return vec.size;
}

size_t Vector::get_capacity(const Vector& vec) {
	return vec.capacity;
}