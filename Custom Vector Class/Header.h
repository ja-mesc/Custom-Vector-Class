//#include <array>

#pragma once
class Vector {
	int* data;
	size_t size;
	size_t capacity;

public:
	Vector(); //constructor
	Vector(const Vector& other); //copy constructor
	Vector(Vector&& other) noexcept; //move constructor
	Vector& operator=(const Vector& other); // copy assignment operator
	Vector& operator=(Vector&& other) noexcept; // move assignment operator

	//getter functions
	size_t get_size(const Vector& vec);
	size_t get_capacity(const Vector& vec);

	int& operator[](size_t index); //using vec[i] for element access

	~Vector(); //destructor

	//member functions
	void push_back(int value);
	void pop_back();

};