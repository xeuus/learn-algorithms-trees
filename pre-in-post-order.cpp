#include <iostream>
#include <queue>

template <class E>
struct TreeNode {
	E value;
	TreeNode<E> *parent;
	TreeNode<E> *left;
	TreeNode<E> *right;

	TreeNode(E val, TreeNode<E> *par){
		this->value = val;
		this->parent = par;
		this->left = nullptr;
		this->right = nullptr;
	}
	TreeNode<E> *AddLeft(E val){
		this->left = new TreeNode(val, this);
		return this->left;
	}
	TreeNode<E> *AddRight(E val){
		this->right = new TreeNode(val, this);
		return this->right;
	}
	void Visit() {
		std::cout << this->value;
	}
};

template <class E>
struct BinaryTree {
	TreeNode<E> *root;

	BinaryTree(E value) {
		this->root = new TreeNode<E>(value, nullptr);
	}

	void PreOrder(TreeNode<E> *node) {
		if(node != nullptr) {
			node->Visit();
			this->PreOrder(node->left);
			this->PreOrder(node->right);
		}
	}

	void PreOrder() {
		this->PreOrder(this->root);
	}

	void PostOrder(TreeNode<E> *node) {
		if(node != nullptr) {
			this->PostOrder(node->left);
			this->PostOrder(node->right);
			node->Visit();
		}
	}

	void PostOrder() {
		this->PostOrder(this->root);
	}


	void InOrder(TreeNode<E> *node) {
		if(node != nullptr) {
			this->InOrder(node->left);
			node->Visit();
			this->InOrder(node->right);
		}
	}

	void InOrder() {
		this->InOrder(this->root);
	}


	void LevelOrder() {
		std::queue<TreeNode<E>*> q;
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
	auto bt = new BinaryTree<char>('A');

	auto A = bt->root;
	auto B = A->AddLeft('B');
	B->AddLeft('D');
	B->AddRight('E');
	auto C = A->AddRight('C');
	C->AddLeft('F');
	C->AddRight('G');

	std::cout << "performing pre-order > ";
	bt->PreOrder();
	std::cout << " > done! " << std::endl;

	std::cout << "performing post-order > ";
	bt->PostOrder();
	std::cout << " > done! " << std::endl;


	std::cout << "performing in-order > ";
	bt->InOrder();
	std::cout << " > done! " << std::endl;


	std::cout << "performing level-order > ";
	bt->LevelOrder();
	std::cout << " > done! " << std::endl;

	return 0;
}