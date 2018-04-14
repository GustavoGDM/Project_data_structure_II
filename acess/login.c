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

infUser loginUser(tree** root){
	infUser user;
	node userNode;
	begin:
	system("cls");
	printf("|---------- Login -----------|\n");
	printf("|-- Para sair digite 0/0|\n");
	printf("|--Insira seu username  \n|--");
	scanf("%d",&user.username);
	printf("|--Insira sua senha  \n|--");
	scanf("%s",user.password);
	if (user.username == 0 && strcmp(user.password,"0") == 0){
		return user;
	}
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
		return userNode->user;
	}

}

void login(tree** root){
	node aux;
	infUser user;
	do{
		aux = (*root);
		user = loginUser( &aux );
		if (user.username == 0 && strcmp(user.password,"0") == 0)
			return;
		else
		{
			switch( user.permition){
				case noAcess:
				break;
				case basicUser:
				menuUser();
				break;
				case adimin:
				menuAdm( &aux );
				break;

			}
		}
	}while(1);
}
