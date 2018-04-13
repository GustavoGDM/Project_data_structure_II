 void romoveUserTree(tree ** nodeRemove,tree ** nodeSeach){
	if( (*nodeSeach)->right != NULL){
		romoveUserTree(&(*nodeRemove),&(*nodeSeach)->right);
	}else{
		if( (*nodeSeach)->left == NULL){
			(*nodeRemove)->user = (*nodeSeach)->user;
			free(*nodeSeach);
			(*nodeSeach) = NULL;
		}else{
			(*nodeRemove)->user = (*nodeSeach)->user;
			(*nodeSeach) = (*nodeSeach)->left;
		}
	}
}

int romoveUser(tree **root,infUser user){ // Exclude Node
	if(*root == NULL)
	{
		return ;
	}
	else if((*root)->user.username < user.username )
	{
		romoveUser(&(*root)->right,user);
	}
	else if((*root)->user.username > user.username)
	{
		romoveUser(&(*root)->left,user);
	}
	else
	{
		if((*root)->right == NULL)
		{
			*root = (*root)->left;
		}
		else if((*root)->left == NULL)
		{
			*root = (*root)->right;
		}
		// handling nodes for exclusion
		else

		{
			romoveUserTree(&(*root),&(*root)->left);
		}

	}
}


