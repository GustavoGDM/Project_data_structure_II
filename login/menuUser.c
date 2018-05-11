int menuUser(Graph** graph ){
	int option;
	do{
		system("cls");
		printf(" ______________________________________\n");
		printf("|                                      | \n");
		printf("|                  MENU                | \n");
		printf("|______________________________________| \n");
		printf("|- Exibir  Sites ---------------- [01] | \n");
		printf("|- Buscar  Sites ---------------- [02] | \n");
		printf("|- Exibir Sites e Conexao ------- [03] | \n");
		printf("|- Numero de vertices e aresta -- [04] | \n");
		printf("|- Busca caminho entre 2 vertices [05] | \n");
		printf("|- Sair ------------------------- [00] |\n");
		printf("|------------------------------->");
		scanf("%d",&option);
		return option;
		switch(option){
			case 1:
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|             EXIBIR SITES             |\n");
			printf("|______________________________________|\n");
			showSites(&(*graph));
			getch();
			break;
			case 2:
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|              BUSCAR SITE             |\n");
			printf("|______________________________________|\n");
			searchSite(&(*graph));
			printf("|______________________________________|\n");
			getch();
			break;
			case 3:
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|        EXIBIR SITES E CONEXOES       |\n");
			printf("|______________________________________|\n");
			showSitesAndConnections(&(*graph));
			printf("|______________________________________|\n");
			getch();
			break;
			case 4:
			system("cls");
			printf(" ______________________________________\n");
			printf("|                                      |\n");
			printf("|            Vertices [%02.2d]             |\n",(*graph)->vert);
			printf("|             Arestas [%02.2d]             |\n",(*graph)->edge);
			printf("|______________________________________|\n");
			getch();
			break;
			case 5:
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
