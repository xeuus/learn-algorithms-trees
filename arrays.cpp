#include <iostream>

template <class T>
struct Node {
	T value;
	Node<T>* right;
	Node<T>* left;
	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}
	void Visit() {

		std::cout << "[";
		std::cout << this->value;
		std::cout << "] ";
	}
	virtual void Dispose() {};
};

template <class T>
struct List {
	Node<T>* head;
	Node<T>* tail;

	List() {
		this->head = nullptr;
		this->tail = nullptr;
	}


	T GetFront() {
		if(this->head == nullptr)
			throw "list is empty";
		return this->head->value;
	}

	T PushFront(T value) {
		if(this->head == nullptr) {
			this->head = new Node<T>(value);
			if(this->tail == nullptr) {
				this->tail = this->head;
			}
		} else {
			auto temp = this->head;
			this->head = new Node<T>(value);
			this->head->right = temp;
			temp->left = this->head;
			if(this->tail == this->head) {
				this->tail = this->head;
			}
		}
		return value;
	}

	T PopFront() {
		auto temp = this->head;
		this->head = this->head->right;
		this->head->left = nullptr;
		return std::move(temp->value);
	}


	T GetBack() {
		if(this->tail == nullptr)
			throw "list is empty";
		return this->tail->value;
	}

	T PushBack(T value) {
		if(this->tail == nullptr) {
			this->tail = new Node<T>(value);
			if(this->head == nullptr) {
				this->head = this->tail;
			}
		} else {
			auto temp = this->tail;
			this->tail = new Node<T>(value);
			this->tail->left = temp;
			temp->right = this->tail;
			if(this->tail == this->head) {
				this->tail = this->head;
			}
		}
		return value;
	}

	T PopBack() {
		auto temp = this->tail;
		this->tail = this->tail->left;
		this->tail->right = nullptr;
		return std::move(temp->value);
	}



	void Print() {
		auto temp = this->head;
		while(temp != nullptr) {
			temp->Visit();
			temp = temp->right;
		}
		std::cout << std::endl;
	}


};

int main(void) {
	auto lst = new List<int>();
	for(int i=6;i<9;i++) {
		lst->PushFront(i);
		lst->PushBack(i);
	}
	lst->Print();
}