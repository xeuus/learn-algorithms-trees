#include <iostream>
#include <queue>
#include <string.h>

template <class E>
struct Node {
	E key;
	Node<E> *parent;
	Node<E> *left;
	Node<E> *right;

	Node(E val, Node<E> *par){
		this->key = val;
		this->parent = par;
		this->left = nullptr;
		this->right = nullptr;
	}
	~Node(){
		delete parent;
		delete left;
		delete right;
	}
	void Visit() {
		std::cout << this->key << " ";
	}

	virtual int Compare(E other) {return 0;};
	virtual void Dispose() {};
};
template<>
int Node<int>::Compare(int key) {
	return key - this->key;
}

template<>
int Node<const char *>::Compare(const char* key) {
	return strcmp(key, this->key);
}

template <class E>
struct BinarySearch {
	Node<E> *root;

	bool Add(E key) {
		if(this->root == nullptr) {
			this->root = new Node<E>(key, nullptr);
			return true;
		}
		Node<E> *curr = this->root;
		int comp = curr->Compare(key);
		while((comp > 0 && curr->right != nullptr) || (comp < 0 && curr->left != nullptr)) {
			if(comp < 0)
				curr = curr->left;
			else
				curr = curr->right;
			comp = curr->Compare(key);
		}
		if(comp < 0)
			curr->left = new Node<E>(key, curr);
		else if(comp > 0)
			curr->right = new Node<E>(key, curr);
		return true;
	}

	bool Find(E key) {
		Node<E> *curr = this->root;
		while(curr != nullptr) {
			int comp = curr->Compare(key);
			if(comp > 0)
				curr = curr->right;
			else if(comp < 0)
				curr = curr->left;
			else
				return true;
		}
		return false;
	}

	Node<E>* MinValueNode(Node<E> *node) {
		auto current = node;
	    while (current && current->left != nullptr) 
	        current = current->left; 
	    return current; 
	}

	Node<E>* Delete(Node<E>* root, E key) {
		if(root == nullptr)
			return root;
		int comp = root->Compare(key);
	    if (comp < 0)
	        root->left = this->Delete(root->left, key); 
	    else if (comp > 0) 
	        root->right = this->Delete(root->right, key); 
	    else {
	        if (root->left == nullptr) {
	            auto temp = root->right;
	            root->Dispose();
	            free(root);
	            return temp; 
	        } 
	        else if (root->right == nullptr) { 
	            auto temp = root->left;
	            root->Dispose();
	            free(root);
	            return temp;
	        } 
        	auto temp = this->MinValueNode(root->right);
        	root->key = temp->key;
    		root->right = this->Delete(root->right, temp->key); 
	    }
    	return root;
	}

	bool Delete(E key) {
		return this->Delete(this->root, key) != nullptr;
	}


	void InOrder(Node<E> *node) {
		if(node != nullptr) {
			this->InOrder(node->left);
			node->Visit();
			this->InOrder(node->right);
		}
	}
	void InOrder() {
		this->InOrder(this->root);
		std::cout << std::endl;
	}


	void LevelOrder() {
		std::queue<Node<E>*> q;
		q.push(this->root);
		while(!q.empty()) {
			auto node = q.front();
			q.pop();
			if(node != nullptr) {
				node->Visit();
				q.push(node->left);
				q.push(node->right);
			}
		}
		std::cout << std::endl;
	}
};

int main(int argv, char* args[]) {

	auto bt = new BinarySearch<int>();
	bt->Add(20);
	bt->Add(10);
	bt->Add(30);
	bt->Add(8);
	bt->Add(17);
	bt->Add(25);
	bt->Add(60);
	bt->Add(4);
	bt->Add(9);
	bt->Add(23);
	bt->Add(26);
	bt->Add(40);
	bt->Add(80);
	bt->Add(28);
	bt->InOrder();
	bt->Delete(28);
	bt->InOrder();
	auto bt2 = new BinarySearch<const char *>();
	bt2->Add("Aryan");
	bt2->Add("Name");
	bt2->Add("Arash");
	bt2->Add("Hello");
	bt2->Add("World");
	bt2->InOrder();
	return 0;
}