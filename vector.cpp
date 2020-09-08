#include <iostream>

template <class T>
struct Vector {
	void* pointer;
	unsigned int capacity;
	unsigned int size;

	Vector(int cap) {
		this->size = 0;
		this->capacity = cap;
		this->pointer = (void*)malloc(cap * sizeof(T));
	}
	Vector() : Vector(2) {}
	~Vector() {
		std::cout << "destruct" << std::endl;
		std::cout << sizeof(this->pointer) << std::endl;
		if(this->pointer != nullptr) {
			free(this->pointer);
		}
	}
};

int main(void) {
	auto c = Vector<int>();
}