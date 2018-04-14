// typedef struct
// {
// 	int username;
// 	char password;
// 	int permission;
// }infUser;

// typedef struct {
// 	infUser user;
// 	struct tree *left; // esquerda 
// 	struct tree *right; // direita
// 	int bal;
// }tree;

// typedef tree* node;

node seach(node* root,int value){
	if( (*root) == NULL)
		return NULL;
	else if((*root)->user.username < value){
		return seach(&(*root)->right,value);
	}else if((*root)->user.username > value){
		return seach(&(*root)->left,value);
	}else if ((*root)->user.username == value){
		return *root;
	}
}

node nodeCreation(infUser user){
	node a;
	a = (tree *)malloc(sizeof(tree));
	if ( a == NULL)
	{
		system("cls");
		printf("ERRO ,não ha memoria \n");
		system("pause");
		return NULL;
	}
	a->user = user;
	a->left = NULL;
	a->right = NULL;
	a->bal = 0;
	return a;
}



int treeHeight(node* root){
	if( (*root) == NULL )
		return -1;
	else
	{
		int heightLeft = treeHeight( &(*root)->left);
		int heightRight = treeHeight( &(*root)->right);
		if( heightLeft < heightRight )
			return heightRight + 1;
		else
			return heightLeft + 1;
	}

}

void rightRotation(node* root){
	node b = *root;
	node a = b->left;
	b->left = a->right;
	a->right = b;
	a->bal = 0;
	b->bal = 0;
	*root = a;
}

void leftRotation( node* root){
	node a = *root;
	node b = a->right;
	a->right = b->left;
	b->left = a;
	a->bal = 0;
	b->bal = 0;
	*root = b;
}

void rotationLeftRight(node* root){
	node c = *root;
	node a = c->left;
	node b = a->right;
	c->left = b->right;
	a->right = b->left;
	b->left = a;
	b->right = c;
	switch(b->bal) 
	{
		case -1:
		a->bal = 0;
		c->bal = 1;
		break;
		case 0:
		a->bal = 0;
		c->bal = 0;
		break;
		case +1:
		a->bal = -1;
		c->bal = 0;
		break;
	}
	b->bal = 0;
	*root = b;
}


void rotationRightLeft(node* root){
	node a = *root;
	node c = a->right;
	node b = c->left;
	c->left = b->right;
	a->right = b->left;
	b->left = a;
	b->right = c;
	switch(b->bal) 
	{
		case -1:
		a->bal = 0;
		c->bal = 1;
		break;
		case 0:
		a->bal = 0;
		c->bal = 0;
		break;
		case +1:
		a->bal = -1;
		c->bal = 0;
		break;
	}
	b->bal = 0;
	*root = b;  
}

void insert(node* root,infUser user){
	if ((*root)!= NULL)
	{
		int increase;
		return insert_AVL(root, user, &increase);
	}
	else
		(*root) = nodeCreation(user);
}

int insert_AVL(node* root,infUser user,int *flag){
	if (*root == NULL) 
	{
		*root = nodeCreation(user);
		*flag = 1;
		return 1;
	}

	if (user.username == (*root)->user.username) 
		return 0;

	if (user.username < (*root)->user.username) 
	{
		if ( insert_AVL( &(*root)->left, user, flag) ) 
		{
			if (*flag) 
			{
				node aux;
				switch ((*root)->bal) 
				{
					case -1:
					aux = (*root)->left;
					if ( aux->bal == -1)
						rightRotation(root);
					else
						rotationLeftRight(root);
					*flag = 0;
					break;
					case 0:
					(*root)->bal = -1;
					*flag = 1;
					break;
					case +1:
					(*root)->bal = 0;
					*flag = 0;
					break;
				}
			}
			return 1;
		}
		else
			return 0;
	}

	if (insert_AVL(&(*root)->right, user, flag)) {
		if (*flag) 
		{
			node aux;
			switch ((*root)->bal) {
				case -1:
				(*root)->bal = 0;
				*flag = 0;
				break;
				case 0:
				(*root)->bal = +1;
				*flag = 1;
				break;
				case +1:
				aux = (*root)->right;
				if (aux->bal == +1)
					leftRotation(root);
				else
					rotationRightLeft(root);
				*flag = 0;
				break;
			}
		}
		return 1;
	}
	else
		return 0;


}
