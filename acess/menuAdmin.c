void showUsers(tree **root);
void insertUser(tree **root);
node seachUser(tree **root);

int menuAdm(tree** root){

	int option;
	node aux;
	do
	{
		system("cls");
		aux = NULL;
		printf("|---------- MENU -----------|\n");
		printf("|-Inserir Usuario ------- [1] \n");
		printf("|-Alterar Usuario ------- [2] \n");
		printf("|-Exibir  Usuario ------- [3] \n");
		printf("|-Buscar  Usuario ------- [4] \n");
		printf("|-Inserir Sites --------- [5] \n");
		printf("|-Alterar Sites --------- [6] \n");
		printf("|-Exibir  Sites --------- [7] \n");
		printf("|-Buscar  Sites --------- [8] \n");
		printf("|-Sair ------------------ [0] \n");
		printf("|-------------------------|");
		scanf("%d",&option);
		switch(option){
			case 1: // Inserir Usuario
			system("cls");
			insertUser(&(*root));
			getch();
			break;
			case 2://Alterar Usuario
			system("cls");
			printf("|---------- ALTERAR USUARIO -----------|\n");
			printf("|-- Buscar Usuario :\n");
			aux = seachUser(&(*root));
			if (aux != NULL)
			{
				show( &(aux->user) );
				alteringUser(aux);
				printf("|-- Alterado Com Sucesso ! \n");
			}
			else
				printf("|-- Usuário nao encontrado\n");
			aux = NULL;
			getch();
			break;
			case 3: //Exibir  Usuario
			system("cls");
			printf("|---------- EXIBIR USUARIOS -----------|\n");
			printf("|--------------------------------------|");
			showUsers(&(*root));
			getch();
			break;
			case 4: // Buscar  Usuario
			system("cls");
			printf("|---------- BUSCA USUARIO -----------|\n");
			aux = seachUser(&(*root));
			if (aux != NULL)
			{
				show(&(aux->user));
				alteringUser(aux);
			}
			else
				printf("|-- Usuário nao encontrado\n");
			getch();
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


void show(infUser *user){
	printf("\n|-- NAME : %s\n|-- USERNAME : %d\n|-- PASSWORD : %s\n",user->name,user->username,user->password);
	switch( user->permition){
				case noAcess:
				printf("|-- PERMITION : Sem Acesso\n");
				break;
				case basicUser:
				printf("|-- PERMITION : Usuario\n");
				break;
				case adimin:
				printf("|-- PERMITION : Administrador\n");
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
