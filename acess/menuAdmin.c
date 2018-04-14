void showUsers(tree **root);
infUser insertUser(tree **root);
node seachUser(tree **root);
int menuAdm(tree** root){

	int option;
	infUser *aux;
	do
	{
		system("cls");
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
	//return option;
		switch(option){
			case 1:
			insertUser(&(*root));
			break;
			case 2:
			break;
			case 3:
			showUsers(&(*root));
			break;
			case 4:
			aux = seachUser(&(*root));
			show(aux);
			break;
			case 5:
			break;
			case 6:
			break;
			case 7:
			break;
			case 8:
			break;
			case 0:
			break;
			default:
			break;
		}
	}while(option != 0);
}


show(infUser *user){
	printf("NAME %s || USERNAME : %d || PASSWORD %s \n",user->name,user->username,user->password );
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

infUser insertUser(tree **root){		// Cadastro
	infUser user;
	printf("|---------- CADASTRO -----------|\n");
	printf("|--Insira o nome  \n|--");
	scanf("%s",user.name);
	user.username = generateUsername(&(*root));
	printf("|--O seu username : \n|-- %d\n",user.username);
	printf("|--Insira sua senha  \n|--");
	scanf("%s",user.password);
	printf("|--Insira a permicao de acesso [0]SemAcesso [1]Usuario [2]Administrador\n|--");
	scanf("%d",&user.permition);
	switch(user.permition){
		default:
		case basicUser:
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
	printf("|---------- Buscar -----------|\n");
	printf("|--Insira o username  \n|-- ");
	scanf("%d",&username);
	temp = seach(&(*root),username);
	if (temp != NULL)
		return temp;
	else
		return NULL;
}
