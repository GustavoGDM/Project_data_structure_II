void  inicilizerFiles(tree** root){
	FILE *arquivo;
	infUser user;
	// insert(node* root,infUser user) 
	arquivo = fopen("acesso.dat","rb");
	if(arquivo == NULL){
		printf("Erro, Arquivo não existe!\n");
		return;
	}
	while (1){
		fread(&user,sizeof(infUser),1,arquivo);
		if(feof(arquivo)){
			fclose(arquivo);
			return;
		}
		insert(&(*root),user);
	}
	fclose(arquivo);
	// Ler Dados do Grafos
	// infRede
	// arquivo = fopen("rede.dat","rb+");
	// if(arquivo == NULL){
	// 	printf("Erro, Arquivo não existe!\n");
	// 	return;
	// }
	// while (1){
	// 	fread(&,sizeof(),1,arquivo);
	// 	if(feof(arquivo)){
	// 		fclose(arquivo);
	// 		return;
	// 	}
	// }
}

void writeTree(tree** root,FILE** arquivo){
	if(*root != NULL){
		fwrite(&(*root)->user,sizeof(infUser),1,(*arquivo));
		write(&(*root)->left,&(*arquivo));
		write(&(*root)->right,&(*arquivo));
	}
}

void closingFiles(tree** root){
	FILE *arquivo;
	arquivo = fopen("acesso.dat","wb");
	if(arquivo == NULL){
		printf("Erro, Arquivo não existe!\n");
		return;
	}
	writeTree(&(*root),&arquivo);	
	fclose(arquivo);
	// Gravar Dadps do Grafos
	// arquivo = fopen("rede.dat","+wb");
	// writeGraph(&(*root),&arquivo);	
	// fclose(arquivo);
}
