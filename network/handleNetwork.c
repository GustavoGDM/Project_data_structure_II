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

			printf("|   |->Conexao : Id[%02d]\n|     [-> Disponibilidade [%0d]\n|     [-> Tempo de trasferencia [%.2f]\n      [-> Distancia em metros [%d]\n",adj->id,adj->avlbty,adj->transfer_speed,adj->distance );
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
		printf("|--Site nao existe ");
		return;
	}
	printf("|-- Digite o campo que sera mudado\n|-- NOME [1]\n|-- SO [2]\n|-- HD [3]\n|-- Tamanho do disco [4]\n|--");
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
		printf("|--Site nao existe ");
		return;
	}else{
		printf("|-- Id[%02.2d]\n|-- Nome : %-0.20s",aux->id , aux->inf.name );
		printf("|-- SO : %-0.20s|-- HD : %-0.20s",aux->inf.OS , aux->inf.HD );
		printf("|-- Disk Space : %d\n",aux->inf.diskSpace);
		for (adj = aux->nextEdge; adj != NULL ; adj = adj->nextEdge)
			printf("     |->  Id[%02d] -> Disponibilidade [%02d] -> Tempo de trasferência [%.2f] -> Distancia [%d] ",adj->id,adj->avlbty,adj->transfer_speed,adj->distance );
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
		printf("|--Site nao existe ");
		return;
	}
	//searchVertx(Vertex** list, int id );
	printf("|--Insira o id destino  \n|-- ");
	scanf("%i",&vert2);
	list = (*graph)->listGraph;
	if (searchVertx(&list, vert2) == NULL){
		printf("|--Site nao existe ");
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
	printf("|--Insira a Taxa de trasferência \n|-- ");
	scanf("%f",&adj.transfer_speed);
	printf("|--Insira a Distancia em metros  \n|-- ");
	scanf("%d",&adj.distance);
	insertNetworkEdge(&(*graph),vert1,adj);


}
