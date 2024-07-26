#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de  alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()//função responsavel por cadastrar usuarios do sistem
{
	//inicio de criação de variaveis/string
      char arquivo[40];
	  char cpf [40];
      char nome[40];
      char sobrenome[40];
      char cargo[40];
      //final de criação de vairação/string
      
      printf("Digite o CPF a ser cadastrado:");
      scanf("%s", cpf);//%s refere-se a string
      
      strcpy(arquivo,cpf);//Responsavel por copiar o valor das string
      
      FILE *file;//cria o arquivo
      file = fopen(arquivo,"w");//cria o arquivo no sistema
      fprintf(file,cpf);//salvo o valor da variavel
      fclose(file);//fecha o arquivo
      
      file = fopen(arquivo,"a");//abriu aquivo com atualição
      fprintf(file,",");//coloca , em casa ação do código
      fclose(file);
      
      printf("Digite o nome a ser cadastrado: ");//código para o cliente cadastrar o nome
      scanf("%s", nome);
      
      file = fopen(arquivo,"a");//abreo arquivo para atualização
      fprintf(file,nome);//abre o arquivo nome
      fclose(file);//fecha o arquivo
      
      file = fopen(arquivo,"a");//abre o arquivo para atualização
      fprintf(file,",");//coloca virguar depois da ação do nome
      fclose(file);//fecha arquivo
      
      printf("Digite o sobrenome a ser cadastrado: ");//ação para cadastrar sobrenome
      scanf("%s", sobrenome);
      
      file = fopen(arquivo, "a");//abre o aquivo do sobrenome para atualização
      fprintf(file,sobrenome);
      fclose(file);//fecha arquivo
      
      file = fopen(arquivo,"a");
      fprintf(file,"Sobrenome\n");//coloca a virgula depois do sobrenome
      fclose(file);
      
      printf("Difite o cargo a ser cadastrado: ");
      scanf("%s", cargo);
      
      file = fopen(arquivo, "a");
      fprintf(file,cargo);
      fclose(file);
      
      system("pause");//pause o sistema para o cliente entender o que aconteceu
     
}

int consulta()
{
	 setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	 
	 //inicio de variaveis string
	 char cpf [40];
	 char conteudo [200];
	 //fim da variavel string
	 
	 printf("Digite o CPF a ser consultado: ");
	 scanf("%s", cpf);
	 
	 FILE *file;
	 file = fopen (cpf,"r");
	 
	 if(file == NULL)//se o documento for igual de nulo ou seja não existir
	 {
	 	printf("Não foi possivel abrir o arquivo, não localizado. \n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)//quando a ação for diferente
	 {
	 	printf ("\nEssas são informações do usuário:");
	    printf("%s", conteudo);
	    printf("\n\n");//pular linha no sistema
	    
	 }
	 
	 system("pause");
}

int deletar()
{
 	char cpf[40];
 	
 	printf("Digite o CPF do usuário a ser deletado: ");
 	scanf("%s", cpf);
 	
 	remove(cpf);
 	
 	FILE *file;
 	file = fopen(cpf,"r");
 	
 	if(file == NULL)
 	{
 		printf("O usuário não se encontra no sistema! \n");
 		system("pause"); 		
	 }
	    
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
		 
	
         system("cls");  
	
	     setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	     printf("### Cartório da EBAC ###\n\n");//Início do menu
	     printf("Escolha a opção do menu desejada: \n\n");
	     printf("\t1 - Registar nomes\n");
	     printf("\t2 - Consultar nome\n");
	     printf("\t3 - Deletar nomes \n\n");
	     printf("\t4 - Sair do sistema");
         printf("Opção: ");//final do menu


         scanf("%d", &opcao);//armezenando a escolha do usuário
          
         system("cls"); //responsavel por limpar a tela
         
             switch(opcao)//inicio da sessão do menu
             {
             case 1:
             registro();
    	     break;
		 
		     case 2:
		     consulta();
		     break;
		  
		     case 3:
		     deletar();
		     break;
		     
		     case 4:
		     printf("Obrigado por utilizar o sistema");
		     return 0;
		     break;
		  
		     default:
		     printf("Essa opção não esta disponível!\n");
		     system("pause");//fim da seleção
		     break;
		     }
         
         
         
     }
}
