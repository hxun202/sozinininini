#include <iostream>

using namespace std;

template <typename T>
class Set
{
private:
	struct Node
	{
		T data;

		Node* left = nullptr;
		Node* right = nullptr;

		Node(T data)
		{
			this->data = data;
		}
	};

	Node* root;
public:
	Set()
	{
		root = nullptr;
	}

	void insert(T data)
	{
		if (root == nullptr)
		{
			root = new Node(data);
		}
		else
		{
			Node* currentNode = root;

			while (true)
			{
				if (data < currentNode->data)
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = new Node(data);

						break;
					}
					else
					{
						currentNode = currentNode->left;
					}
				}
				else if (data > currentNode->data)
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = new Node(data);

						break;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
				else
				{
					break;
				}
			}
		}
	}

	void erase(T data)
	{
		Node* currentNode = root;
		Node* parentNode = nullptr;

		while (currentNode != nullptr && currentNode->data != data)
		{
			parentNode = currentNode;

			if (currentNode->data > data)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}

		if (currentNode == nullptr)
		{
			cout << "the data does not exist" << endl;

			return;
		}
		else if (currentNode->left == nullptr && currentNode->right == nullptr)
		{
			if (parentNode != nullptr)
			{
				if (parentNode->left == currentNode)
				{
					parentNode->left = nullptr;
				}
				else
				{
					parentNode->right = nullptr;
				}
			}
			else
			{
				root = nullptr;
			}

			delete currentNode;
		}
		else if (currentNode->left == nullptr || currentNode->right == nullptr)
		{
			if (currentNode == root)
			{
				if (currentNode->left != nullptr)
				{
					root = currentNode->left;
				}
				else
				{
					root = currentNode->right;
				}
			}
			else
			{
				Node* childNode = nullptr;

				if (currentNode->left != nullptr)
				{
					childNode = currentNode->left;
				}
				else
				{
					childNode = currentNode->right;
				}

				if (parentNode->left == currentNode)
				{
					parentNode->left = childNode;
				}
				else
				{
					parentNode->right = childNode;
				}
			}

			delete currentNode;
		}
		else
		{
			Node* childNode = currentNode->right;
			Node* traceNode = currentNode;

			while (childNode->left != nullptr)
			{
				traceNode = childNode;

				childNode = childNode->left;
			}

			currentNode->data = childNode->data;

			if (traceNode == currentNode)
			{
				traceNode->right = childNode->right;
			}
			else
			{
				traceNode->left = childNode->right;
			}

			delete childNode;
		}
	}

	void indoor(Node* root)
	{
		if (root != nullptr)
		{
			indoor(root->left);

			cout << root->data << "";

			indoor(root->right);
		}
	}

	void render()
	{
		indoor(root);
	}

	void release(Node* root)
	{
		if (root != nullptr)
		{
			release(root->left);

			release(root->right);

			delete root;
		}
	}

	~Set()
	{
		release(root);
	}
};

int main()
{
	Set<int> set;

	set.insert(10);
	set.insert(15);
	set.insert(7);
	set.insert(6);
	set.insert(2);
	set.insert(3);
	set.insert(1);
	set.insert(14);
	set.insert(15);

	set.erase(20);

	set.render();

	return 0;
}