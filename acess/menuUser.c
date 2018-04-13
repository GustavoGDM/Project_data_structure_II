node seach(node* root,int value);

int menuUser(){

	int option;
	printf("|---------- MENU -----------|\n");
	printf("|-Inserindo Usuario ------[1] \n");
	printf("|-Exibir Usuario ---------[2] \n");
	printf("|-Buscar Usuario ---------[3] \n");
	printf("|-Login ------------------[4] \n");
	printf("|-Sair -------------------[0]\n");
	printf("|-------------------------|");
	scanf("%d",&option);
	return option;

}
