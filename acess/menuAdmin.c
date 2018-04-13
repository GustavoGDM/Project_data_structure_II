node seach(node* root,int value);
int menuAdm(){

	int option;
	printf("|---------- MENU -----------|\n");
	printf("|-Inserir Usuario -------- [1] \n");
	printf("|-Alterar Usuario -------- [2] \n");
	printf("|-Exibir  Usuario -------- [3] \n");
	printf("|-Buscar  Usuario -------- [4] \n");
	printf("|-Inserir Sites ---------- [5] \n");
	printf("|-Alterar Sites ---------- [6] \n");
	printf("|-Exibir  Sites ---------- [7] \n");
	printf("|-Buscar  Sites ---------- [8] \n");
	printf("|-Sair ------------------- [0] \n");
	printf("|-------------------------|");
	scanf("%d",&option);
	return option;

}


void showusers(tree **root){	// Exibindo osusarios cadastrados
	if(*root != NULL){
		showusers(&(*root)->left);
		printf("NAME %s || USERNAME : %d || PASSWORD %s \n",(*root)->user.name,(*root)->user.username,(*root)->user.password );
		showusers(&(*root)->right);
	}
}
int generateUsername(tree** root){ 		// Gerar username
	node aux = NULL;
	int username=0;
	srand(time(NULL));
	do
	{
		username = rand() % 99999;
		aux = seach(&(*root),username);
	}
	while(aux !=NULL );

	 return username;
}

infUser insertUser(tree **root){		// Cadastro
	infUser user;
	printf("|---------- CADASTRO -----------|\n");
	printf("|--Insira o nome  \n|--");
	scanf("%s",user.name);
	user.username = generateUsername(&(*root));
	printf("|--O seu username : \n|-- %d\n",user.username);
	printf("|--Insira sua senha  \n|--");
	scanf("%s",user.password);
	user.permission = 1;
	switch(user.permission){
		case 1:
		printf("|--Voce esta autorizado \n");
		break;
		case 0:
		printf("|--Voce nao esta autorizado \n");
		break;
	}
	insert(&(*root),user);
}

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

seachUser(tree **root){
	int username;
	node temp;
	printf("|---------- Buscar -----------|\n");
	printf("|--Insira o username  \n|-- ");
	scanf("%d",&username);
	temp = seach(&(*root),username);
	if (temp != NULL)
		printf("|-- NAME %s || USERNAME : %d || PASSWORD %s \n",temp->user.name,temp->user.username,temp->user.password );
	else
		printf("|-- Usuario Invalido\n");
}
