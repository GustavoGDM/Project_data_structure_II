
void show(infUser *user){
	printf("\n|-- NAME : %-0.20s|-- USERNAME : %-5d ------------------|\n|-- PASSWORD : %-5s ------------------|\n",user->name,user->username,user->password);
	switch( user->permition){
				case noAcess:
				printf("|-- PERMITION : Sem Acesso ------------|\n");
				break;
				case basicUser:
				printf("|-- PERMITION : Usuario ---------------|\n");
				break;
				case adimin:
				printf("|-- PERMITION : Administrador ---------|\n");
				break;
	}
	printf("|--------------------------------------|");

}

void showUsers(tree **root){	// Exibindo osusarios cadastrados
	if(*root != NULL){
		showUsers(&(*root)->left);
		show(&(*root)->user);
		showUsers(&(*root)->right);
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

void insertUser(tree **root){		// Cadastro
	infUser user;
	printf("|--Insira o nome  \n|--");
	fflush(stdin);
	fgets(user.name,20,stdin);
	user.username = generateUsername(&(*root));
	printf("|--O seu username : \n|-- %d\n",user.username);
	printf("|--Insira sua senha  \n|--");
	scanf("%s",user.password);
	printf("|--Insira a permicao de acesso [0]SemAcesso [1]Usuario [2]Administrador\n|--");
	scanf("%d",&user.permition);
	switch(user.permition){
		default:
		case basicUser:
		user.permition = 1;
		printf("|--Voce esta criando um Usuario \n");
		break;
		case adimin:
		printf("|--Voce esta criando um Administrador \n");
		break;
		case noAcess:
		printf("|--Voce nao esta autorizado \n");
		break;

	}
	insert(&(*root),user);
}

node seachUser(tree **root){
	int username;
	node temp;
	printf("|--Insira o username  \n|-- ");
	scanf("%d",&username);
	temp = seach(&(*root),username);
	if (temp != NULL)
		return temp;
	else
		return NULL;
}

void alteringUser(node root){
	int option;
	infUser aux; // (*root)->user;
	// printf("|-- Digite o campo que sera mudado\n|-- USERNAME [0]\n|-- NAME [1]\n|-- PASSWORD [2]\n|-- PERMITION [3]\n|--");
	printf("\n|-- Digite o campo que sera mudado\n|-- NAME [1]\n|-- PASSWORD [2]\n|-- PERMITION [3]\n|--");
	scanf("%d",&option);
	switch(option){
		// case username:
		// printf("|-- Digite o novo username\n|-- ");
		// scanf("%d",&aux.username);
		// root->user.username = aux.username;
		// break;
		case name:
		printf("|-- Digite o novo nome\n|--");
		scanf("%s",aux.name);
		strcpy(root->user.name,aux.name);
		break;
		case password:
		printf("|-- Digite o novo password\n|--");
		scanf("%s",aux.password);
		strcpy(root->user.password,aux.password);
		break;
		case permition:
		printf("|--Digite a nova permition\n|--[0]SemAcesso\n|--[1]Usuario\n|--[2]Administrador\n|--");
		scanf("%d",&aux.permition);
		root->user.permition = aux.permition;
		break;
	}
}
