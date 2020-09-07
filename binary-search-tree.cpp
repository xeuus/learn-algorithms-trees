#include <iostream>
#include <queue>

template <class E>
struct Node {
	E value;
	Node<E> *parent;
	Node<E> *left;
	Node<E> *right;

	Node(E val, Node<E> *par){
		this->value = val;
		this->parent = par;
		this->left = nullptr;
		this->right = nullptr;
	}
	Node<E> *AddLeft(E val){
		this->left = new Node(val, this);
		return this->left;
	}
	Node<E> *AddRight(E val){
		this->right = new Node(val, this);
		return this->right;
	}
	void Visit() {
		std::cout << this->value << " ";
	}
};

struct BinarySearch {
	Node<int> *root;

	bool Add(int value) {
		if(this->root == nullptr) {
			this->root = new Node<int>(value, nullptr);
			return true;
		}
		Node<int> *curr = this->root;
		int comp = value - curr->value;
		while((comp > 0 && curr->right != nullptr) || (comp < 0 && curr->left != nullptr)) {
			if(comp < 0)
				curr = curr->left;
			else
				curr = curr->right;
			comp = value - curr->value;
		}
		if(comp < 0)
			curr->AddLeft(value);
		else if(comp > 0)
			curr->AddRight(value);
		return true;
	}

	bool Find(int value) {
		Node<int> *curr = this->root;
		while(curr != nullptr) {
			int comp = value - curr->value;
			if(comp > 0)
				curr = curr->right;
			else if(comp < 0)
				curr = curr->left;
			else
				return true;
		}
		return false;
	}

	bool Delete(int value) {
		Node<int> *curr = this->root;
		while(curr != nullptr) {
			int comp = value - curr->value;
			if(comp > 0)
				curr = curr->right;
			else if(comp < 0)
				curr = curr->left;
			else {
				if(curr->left != nullptr && curr->right != nullptr) {

				} else {

				}
			}
		}
		return false;
	}

	void PreOrder(Node<int> *node) {
		if(node != nullptr) {
			this->PreOrder(node->left);
			node->Visit();
			this->PreOrder(node->right);
		}
	}

	void PreOrder() {
		this->PreOrder(this->root);
	}
	void LevelOrder() {
		std::queue<Node<int>*> q;
		q.push(this->root);
		while(!q.empty()) {
			auto node = q.front();
			q.pop();
			if (node != nullptr) {
				node->Visit();
				q.push(node->left);
				q.push(node->right);
			}
		}
	}
};

int main(int argv, char* args[]) {

	BinarySearch *bt = new BinarySearch();
	bt->Add(60);
	bt->Add(20);
	bt->Add(30);
	bt->Add(11);
	bt->Add(78);
	bt->PreOrder();
	std::cout << std::endl;

	std::cout << bt->Find(33) << std::endl;



	return 0;
}