int menuAdm(tree** root, Graph** graph ){

	int option;
	node aux;
	do
	{
		system("cls");
		aux = NULL;
		printf(" ______________________________________\n");
		printf("|                                      | \n");
		printf("|                  MENU                | \n");
		printf("|______________________________________| \n");
		printf("|- Inserir Usuario -------------- [01] | \n");// <- Funcionando 
		printf("|- Alterar Usuario -------------- [02] | \n");// <- Funcionando
		printf("|- Exibir  Usuario -------------- [03] | \n");// <- Funcionando
		printf("|- Buscar  Usuario -------------- [04] | \n");// <- Funcionando
		printf("|- Excluir Usuario -------------- [05] | \n");
		printf("|- Inserir Sites ---------------- [06] | \n");// <- Funcionando
		printf("|- Alterar Sites ---------------- [07] | \n");// <- Funcionando
		printf("|- Exibir  Sites ---------------- [08] | \n");// <- Funcionando
		printf("|- Buscar  Sites ---------------- [09] | \n");// <- Funcionando
		printf("|- Excluir sites ---------------- [10] | \n");// <- Funcionando
		printf("|- Inserir Conexao -------------- [11] | \n");// <- Funcionando
		printf("|- Exibir Sites e Conexao ------- [12] | \n");// <- Funcionando
		printf("|- Alterar Conexao -------------- [13] | \n");// <- Funcionando
		printf("|- Excluir Conexao -------------- [14] | \n");// <- Funcionando
		printf("|- Numero de vertices e aresta -- [15] | \n");// <- Funcionando
		printf("|- Busca caminho entre 2 vertices [16] | \n");// <- Funcionando
		printf("|- Sair ------------------------- [00] |\n");
		printf("|------------------------------->");
		scanf("%d",&option);
		switch(option){
			// system("cls");
			// printf(" ______________________________________ \n");
			// printf("|                                      |\n");
			// printf("| - |\n");
			// printf("|______________________________________|\n");
			//->
			// printf("|______________________________________|\n");
			// getch();
			case 1: // Inserir Usuario
			system("cls");
			printf(" ______________________________________ \n");
			printf("|                                      |\n");
			printf("|               CADASTRO               |\n");
			printf("|______________________________________|\n");
			insertUser(&(*root));
			printf("|______________________________________|\n");
			getch();
			break;
			case 2://Alterar Usuario
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|            ALTERAR USUARIO           |\n");
			printf("|______________________________________|\n");
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
			printf("|______________________________________|");
			getch();
			break;
			case 3: //Exibir  Usuario
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|            EXIBIR USUARIOS           |\n");
			printf("|______________________________________|");
			showUsers(&(*root));
			getch();
			break;
			case 4: // Buscar  Usuario
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|             BUSCA USUARIO            |\n");
			printf("|______________________________________|\n");
			aux = seachUser(&(*root));
			if (aux != NULL)
				show(&(aux->user));
			else
				printf("|-- Usuário nao encontrado\n");
			printf("|______________________________________|\n");
			getch();
			break;
			case 5:
			break;
			case 6:
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|             INSERE SITE              |\n");
			printf("|______________________________________|\n");
			insertSite(&(*graph));
			printf("|______________________________________|\n");
			getch();
			break;
			case 7:
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|             ALTERAR SITE             |\n");
			printf("|______________________________________|\n");
			printf("|--------------- sites ----------------|\n");
			showSites(&(*graph));
			changeSite(&(*graph));
			printf("|______________________________________|\n");
			getch();
			break;
			case 8:
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|             EXIBIR SITES             |\n");
			printf("|______________________________________|\n");
			showSites(&(*graph));
			getch();
			break;
			case 9:
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|              BUSCAR SITE             |\n");
			printf("|______________________________________|\n");
			searchSite(&(*graph));
			printf("|______________________________________|\n");
			getch();
			break;
			case 10:
			system("cls");
			printf(" ______________________________________ \n");
			printf("|                                      |\n");
			printf("|             EXCLUIR SITE             |\n");
			printf("|______________________________________|\n");
			printf("|--------------- sites ----------------|\n");
			showSites(&(*graph));
			excludeSite(&(*graph));
			printf("|______________________________________|\n");
			getch();
			break;
			case 11:
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|            INSERIR CONEXAO           |\n");
			printf("|______________________________________|\n");
			printf("|--------------- sites ----------------|\n");
			showSites(&(*graph));
			insertConnection(&(*graph));
			printf("|______________________________________|\n");
			getch();
			break;
			case 12:
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|        EXIBIR SITES E CONEXOES       |\n");
			printf("|______________________________________|\n");
			showSitesAndConnections(&(*graph));
			printf("|______________________________________|\n");
			getch();
			break;
			case 13:
			system("cls");
			printf(" ______________________________________ \n");
			printf("|                                      |\n");
			printf("|            ALTERAR CONEXAO           |\n");
			printf("|______________________________________|\n");
			changeConnection(&(*graph));
			printf("|______________________________________|\n");
			getch();
			break;
			case 14:
			system("cls");
			printf(" ______________________________________ \n");
			printf("|                                      |\n");
			printf("|            EXCLUIR CONEXAO           |\n");
			printf("|______________________________________|\n");
			excludeConnection(&(*graph));
			printf("|______________________________________|\n");
			getch();
			break;
			case 15:
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|            Vertices [%02.2d]             |\n",(*graph)->vert);
			printf("|             Arestas [%02.2d]             |\n",(*graph)->edge);
			printf("|______________________________________|\n");
			getch();
			break;
			case 16:
			system("cls");
			printf(" ______________________________________ \n");
			printf("|                                      |\n");
			printf("|    TRANSFERIR AQUIVO ENTRE VERTICES  |\n");
			printf("|______________________________________|\n");
			transferFilesToSite(&(*graph));
			printf("|______________________________________|\n");
			getch();
			break;		
			case 0:
			break;
			default:
			break;
		}
	}while(option != 0);
}


