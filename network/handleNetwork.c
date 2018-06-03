void showVert(Vertex* list){
	printf("|-- Id[%02.2d] Nome : %-0.20s",list->id , list->inf.name );
}

void showSites(Graph** graph){
	Vertex* aux;
	for (aux = (*graph)->listGraph; aux != NULL ; aux = aux->nextVertex )
	{	
		printf("|-- Id[%02.2d]\n",aux->id);
		printf("|-- Nome : %-0.20s",aux->inf.name);
		printf("|--------------------------------------|\n");
	}
}

void showSitesAndConnections(Graph** graph){
	Vertex* list;
	Edge* adj;
	for (list = (*graph)->listGraph; list != NULL ; list = list->nextVertex )
	{
		printf("|-- Id[%02.2d] Nome : %-0.20s",list->id , list->inf.name );
		for (adj = list->nextEdge; adj != NULL ; adj = adj->nextEdge)
		{
			printf("|   |->Conexao : Id[%02d]\n|     [-> Disponibilidade [%0d]\n|     [-> Tempo de trasferencia [%.2f]\n|     [-> Distancia em metros [%d]\n",adj->id,adj->avlbty,adj->transfer_speed,adj->distance );
		}
	}
}

void changeSite(Graph** graph){
	int option;
	Vertex site,*aux;
	printf("|--------------------------------------|\n");
	printf("|--Insira o id  \n|--");
	scanf("%d",&option);
	for (aux = (*graph)->listGraph; aux != NULL ; aux = aux->nextVertex )
		if (option == aux->id)
			break;
	if (aux ==NULL)
	{
		printf("|--Site nao existe \n");
		return;
	}
	system("cls");
	printf("|--------------------------------------|\n");
	printf("|-- Id[%02.2d]\n|-- Nome : %-0.20s",aux->id , aux->inf.name );
	printf("|-- S.O : %-0.20s|-- HD : %-0.20s",aux->inf.OS , aux->inf.HD );
	printf("|-- Disk Space : %d\n",aux->inf.diskSpace);
	printf("|--------------------------------------|\n");
	printf("|-- Digite o campo que sera mudado\n|-- NOME [1]\n|-- S.O. [2]\n|-- H.D. [3]\n|-- Tamanho do disco em GB [4]\n|--Sair [0]\n|--");
	scanf("%d",&option);
	switch(option){
		case 1:
		printf("|-- Digite o novo nome\n|--");
		fflush(stdin);
		fgets(site.inf.name,20,stdin);
		strcpy(aux->inf.name,site.inf.name);
		break;
		case 2:
		printf("|-- Digite o novo SO\n|--");
		scanf("%s",site.inf.OS);
		strcpy(aux->inf.OS,site.inf.OS);
		break;
		case 3:
		printf("|-- Digite o novo HD\n|--");
		fflush(stdin);
		fgets(site.inf.OS,20,stdin);
		strcpy(aux->inf.HD,site.inf.HD);
		break;
		case 4:
		printf("|-- Digite o novo Tamanho de Disco\n|--");
		scanf("%d",&site.inf.diskSpace );
		aux->inf.diskSpace = site.inf.diskSpace;
		break;
		default:
		return;
	}
}

void insertSite(Graph** graph){
	Vertex site;
	printf("|--Insira o Nome  \n|-- ");
	fflush(stdin);
	fgets(site.inf.name,20,stdin);
	printf("|--Insira o Sitema Operacional  \n|-- ");
	fflush(stdin);
	fgets(site.inf.OS,20,stdin);
	printf("|--Insira a Marca do HD  \n|-- ");
	fflush(stdin);
	fgets(site.inf.HD,20,stdin);
	printf("|--Insira o Espaço em disco  \n|-- ");
	scanf("%d",&site.inf.diskSpace);
	insertNetworkVertex(&(*graph),site);
}

void searchSite(Graph** graph){
	Edge* adj;
	Vertex site,*aux;
	printf("|--Insira o nome  \n|--");
	fflush(stdin);
	fgets(site.inf.name,20,stdin);
	printf("|______________________________________|\n");
	printf("|                                      |\n");

	for (aux = (*graph)->listGraph; aux != NULL ; aux = aux->nextVertex )
		if (strcmp(site.inf.name,aux->inf.name) == 0)
			break;
	if (aux == NULL)
	{
		printf("|--Site nao existe \n");
		return;
	}else{
		printf("|-- Id[%02.2d]\n|-- Nome : %-0.20s",aux->id , aux->inf.name );
		printf("|-- SO : %-0.20s|-- HD : %-0.20s",aux->inf.OS , aux->inf.HD );
		printf("|-- Disk Space : %d\n",aux->inf.diskSpace);
		for (adj = aux->nextEdge; adj != NULL ; adj = adj->nextEdge)
			printf("|   |->Conexao : Id[%02d]\n|     [-> Disponibilidade [%0d]\n|     [-> Tempo de trasferencia [%.2f]\n      [-> Distancia em metros [%d]\n",adj->id,adj->avlbty,adj->transfer_speed,adj->distance );
	}
}

void insertConnection(Graph** graph){
	int vert1,vert2;
	Edge adj;
	Vertex* list;
	printf("|--Insira o id oringem   \n|-- ");
	scanf("%i",&vert1);
	list = (*graph)->listGraph;
	if (searchVertx(&list, vert1 ) == NULL){
		printf("|--Site nao existe \n");
		return;
	}
	//searchVertx(Vertex** list, int id );
	printf("|--Insira o id destino  \n|-- ");
	scanf("%i",&vert2);
	list = (*graph)->listGraph;
	if (searchVertx(&list, vert2) == NULL){
		printf("|--Site nao existe \n");
		return;
	}
	adj.listId = vert1;
	adj.id = vert2;
	availability:
	printf("|--Insira a Disponibilidade  [1 - menos dispoivel] ateh [5 - mais disponivel] \n|-- ");
	scanf("%d",&adj.avlbty);
	if (adj.avlbty <= 0 ||  adj.avlbty >5)
	{
		printf("|-- Valor não é valido\n");
		goto availability;
	}
	printf("|--Insira a Taxa de trasferência MB \n|-- ");
	scanf("%f",&adj.transfer_speed);
	printf("|--Insira a Distancia em metros  \n|-- ");
	scanf("%d",&adj.distance);
	insertNetworkEdge(&(*graph),vert1,adj);
	printf("|--Inserido com sucesso\n");	

}

void changeConnection(Graph** graph){
	Edge* adj,adjAux;
	int vert1,option;
	Vertex site,*aux;
	printf("|--Insira o nome  \n|--");
	fflush(stdin);
	fgets(site.inf.name,20,stdin);
	for (aux = (*graph)->listGraph; aux != NULL ; aux = aux->nextVertex )
		if (strcmp(site.inf.name,aux->inf.name) == 0)
			break;
	if (aux == NULL)
	{
		printf("|--Site nao existe \n");
		return;
	}else{
		printf("|______________________________________|\n");
		printf("|                                      |\n");
		printf("|-- Id[%02.2d]\n|-- Nome : %-0.20s",aux->id , aux->inf.name );
		for (adj = aux->nextEdge; adj != NULL ; adj = adj->nextEdge)
			printf("|   |->Conexao : Id[%02d]\n|     [-> Disponibilidade [%0d]\n|     [-> Tempo de trasferencia [%.2f]\n|     [-> Distancia em metros [%d]\n",adj->id,adj->avlbty,adj->transfer_speed,adj->distance );
	}
	printf("|--Insira o id Da Conexao\n|-- ");
	scanf("%i",&vert1);

	for (adj = aux->nextEdge; adj != NULL ; adj = adj->nextEdge){
		if (vert1 == adj->id)
		{
			printf("|-- Digite o campo que sera mudado\n|-- Id [1]\n|-- Disponibilidade [2]\n|-- Tempo de trasferencia [3]\n|-- Distancia [4]\n|--");
			scanf("%d",&option);
			switch(option){
				case 1:
				printf("|--Insira o novo id \n|-- ");
				scanf("%d",&adjAux.id);
				adj->id = adjAux.id ;
				break;
				case 2:
				printf("|--Insira a nova Disponibilidade\n|-- ");
				scanf("%d",&adjAux.avlbty);
				adj->avlbty = adjAux.avlbty;
				break;
				case 3:
				printf("|--Insira o novo Tempo de trasferencia \n|-- ");
				scanf("%d",&adjAux.transfer_speed);
				adj->transfer_speed = adjAux.transfer_speed;
				break;
				case 4:
				printf("|--Insira a nova Distancia \n|-- ");
				scanf("%d",&adjAux.distance);
				adj->distance = adjAux.distance;
				break;
				default:
				printf("|--Opcao invalida\n|-- ");
			}
			printf("|--Campo alterado com sucesso\n|-- ");
			return;
		}
	}
		printf("|--Conexao nao existe \n");
		return;
}

void transferFilesToSite( Graph** graph ){
	int vert1,option;
	float result;
	Vertex* list,*lsitv1,*lsitv2;
	Files file;
	list = (*graph)->listGraph;
	showSites(&(*graph));
	printf("|--Insira o id oringem   \n|-- ");
	scanf("%d",&vert1);
	lsitv1 = searchVertx(&list, vert1);
	if ( lsitv1  == NULL){
		printf("|--Site nao existe ");
		return;
	}else if (lsitv1->nextFile == NULL)
	{
		printf("|--Site nao tem arquivo ");
		return;
	}
	showFileVertex(&lsitv1);
	printf("|--Insira o nome do arquivo  \n|-- ");
	fflush(stdin);
	scanf("%s",file.name);
	fflush(stdin);
	printf("|--Insira o id destino  \n|-- ");
	scanf("%d",&file.id);
	lsitv2 = searchVertx(&list, file.id);
	if ( lsitv2  == NULL){
		printf("|--Site nao existe \n");
		return;
	}
	
	if (!seachPath(&(*graph),vert1,file.id)){
		printf("|--Os sites Ñão estão conecatados\n");
		return;
	}

	removeFile(&lsitv1,file.name );
	insertnewFile(&lsitv2->nextFile,file );
	printf("|-- O arquivo a ser transferido pode ser pelo caminho  \n|-- Maior Disponibilidade [0]\n|-- Maior Taixa de  transferido  [1]\n|-- Menor Distancia [2]\n|-- ");
	scanf("%d",&option);
	switch(option){
		case avlbty:
			result = searchMaxPath( &(*graph), avlbty , vert1, file.id);
			printf("|-- Total acumulado de Disponibilidade no caminho  %.2f \n",result);
		break;
		case transfer_speed:
			result = searchMaxPath( &(*graph), transfer_speed , vert1, file.id);
			printf("|-- A soma do caminho com maior velocidades eh %.2f MB \n",result);
		break;
		case distance:
			result = minPath( &(*graph), vert1, file.id);
			printf("|-- O Menor caminho Entre os dois sites eh %.0f metros \n",result);
		break;
	}
	return;
}

