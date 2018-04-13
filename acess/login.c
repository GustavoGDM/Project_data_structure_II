node authenticateLogin(tree **root,infUser user){
	node validate;
	validate = seach(&(*root),user.username);
	if( validate == NULL){
		return NULL;
	}
	else
	{
		if (!strcmp(user.password , validate->user.password))
		{
			return validate;
		}
	}

}

void directingUser(node root){
	
	switch( root->user.permition){
		case noAcess:

			break;
		case basicUser:
			menuUser();
			break;
		case adimin:
			menuAdm();
			break;

	}

}

node loginUser(tree** root){
	infUser user;
	node userNode;
	begin:
	printf("|---------- Login -----------|\n");
	printf("|--Insira seu username  \n|--");
	scanf("%d",&user.username);
	printf("|--Insira sua senha  \n|--");
	scanf("%s",user.password);
	userNode = authenticateLogin(&(*root),user);
	if (userNode == NULL)
	{
		system("cls");
		printf("|---------- LOGIN INVALIDO -----------|\n");
		system("pause");
		goto begin;
	}
	else
	{
		return userNode;
	}

}

void login(tree** root){
	
}