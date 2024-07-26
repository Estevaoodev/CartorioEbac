#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de  aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()//fun��o responsavel por cadastrar usuarios do sistem
{
	//inicio de cria��o de variaveis/string
      char arquivo[40];
	  char cpf [40];
      char nome[40];
      char sobrenome[40];
      char cargo[40];
      //final de cria��o de vaira��o/string
      
      printf("Digite o CPF a ser cadastrado:");
      scanf("%s", cpf);//%s refere-se a string
      
      strcpy(arquivo,cpf);//Responsavel por copiar o valor das string
      
      FILE *file;//cria o arquivo
      file = fopen(arquivo,"w");//cria o arquivo no sistema
      fprintf(file,cpf);//salvo o valor da variavel
      fclose(file);//fecha o arquivo
      
      file = fopen(arquivo,"a");//abriu aquivo com atuali��o
      fprintf(file,",");//coloca , em casa a��o do c�digo
      fclose(file);
      
      printf("Digite o nome a ser cadastrado: ");//c�digo para o cliente cadastrar o nome
      scanf("%s", nome);
      
      file = fopen(arquivo,"a");//abreo arquivo para atualiza��o
      fprintf(file,nome);//abre o arquivo nome
      fclose(file);//fecha o arquivo
      
      file = fopen(arquivo,"a");//abre o arquivo para atualiza��o
      fprintf(file,",");//coloca virguar depois da a��o do nome
      fclose(file);//fecha arquivo
      
      printf("Digite o sobrenome a ser cadastrado: ");//a��o para cadastrar sobrenome
      scanf("%s", sobrenome);
      
      file = fopen(arquivo, "a");//abre o aquivo do sobrenome para atualiza��o
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
	 
	 if(file == NULL)//se o documento for igual de nulo ou seja n�o existir
	 {
	 	printf("N�o foi possivel abrir o arquivo, n�o localizado. \n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)//quando a a��o for diferente
	 {
	 	printf ("\nEssas s�o informa��es do usu�rio:");
	    printf("%s", conteudo);
	    printf("\n\n");//pular linha no sistema
	    
	 }
	 
	 system("pause");
}

int deletar()
{
 	char cpf[40];
 	
 	printf("Digite o CPF do usu�rio a ser deletado: ");
 	scanf("%s", cpf);
 	
 	remove(cpf);
 	
 	FILE *file;
 	file = fopen(cpf,"r");
 	
 	if(file == NULL)
 	{
 		printf("O usu�rio n�o se encontra no sistema! \n");
 		system("pause"); 		
	 }
	    
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
		 
	
         system("cls");  
	
	     setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	     printf("### Cart�rio da EBAC ###\n\n");//In�cio do menu
	     printf("Escolha a op��o do menu desejada: \n\n");
	     printf("\t1 - Registar nomes\n");
	     printf("\t2 - Consultar nome\n");
	     printf("\t3 - Deletar nomes \n\n");
	     printf("\t4 - Sair do sistema");
         printf("Op��o: ");//final do menu


         scanf("%d", &opcao);//armezenando a escolha do usu�rio
          
         system("cls"); //responsavel por limpar a tela
         
             switch(opcao)//inicio da sess�o do menu
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
		     printf("Essa op��o n�o esta dispon�vel!\n");
		     system("pause");//fim da sele��o
		     break;
		     }
         
         
         
     }
}
