//TERMINAL DE BANCO//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define t 20
void tentativas();
void menu();
void creditos();
void mybeep(int frequency, int duration);
void musica();
void salvarSaldo(int saldo);
int main()
{
    int conta;
	float saldo;
    printf("Bem-vindo ao caixa bancario.\n\n");
    printf("///////////////////////////////////////////////////\n");
    printf("///\t\t\t\t\t\t///\n");
    printf("///\t\t\t\t\t\t///\n");
    printf("///\t\t\t\t\t\t///\n");
    printf("///\t      Bem-vindo ao seu banco\t\t///\n///\t     Digite o usuario e senha\t\t///\n");
    printf("///\t\t\t\t\t\t///\n");
    printf("///\t\t\t\t\t\t///\n");
    printf("///\t\t\t\t\t\t///\n");
    printf("///////////////////////////////////////////////////\n");

    tentativas();
    menu();
	int voltar = 1;
	while (voltar == 1) 
	{
    	printf("\n\nVoltar ao menu anterior?");
    	printf("\n1 - Sim");
    	printf("\n2 - Nao");
	    printf("\nDigite aqui: ");
	    scanf("%d", &voltar);
    	if (voltar == 1) 
		{
        	menu();
    	}
		else if ((voltar!=1) && (voltar !=2))
		{
			printf("\nOpcao invalida, tente novamente");
			menu();
		}
    	else 
		{
			salvarSaldo(saldo);
        	printf("Realizando as ultimas configuracoes no seu saldo.\n");
    	}
	}
	musica();
    creditos();
	return 0;
}

void tentativas ()//função tentativas//
{
	int tentativas=3;
    do   //TENTATIVAS//
    {
        char correctuser1[t] = "victor";
        char correctuser2[t] = "patricia";
        char usuario[t];
        char correctpasswd1[t] = "03031993";
        char correctpasswd2[t] = "21121969";
        char senha[t];
        printf("\nDigite seu usuario e senha");
        printf("\n>>> Usuario: ");
        scanf("%s", usuario);
        printf("\n>>> Senha: ");
        scanf("%s", senha);
        //SE O USUARIO ESTIVER CORRETO PROSSEGUE//
        if (strcmp(correctuser1, usuario) == 0 && strcmp(correctpasswd1, senha) == 0)
            {
                printf("\nSeja Bem Vindo %s",correctuser1);
                return;
            }
        //SE O USUARIO ESTIVER CORRETO PROSSEGUE//    
        else if (strcmp(correctuser2, usuario) == 0 && strcmp(correctpasswd2, senha) == 0)
            {
                printf("\nSeja Bem Vindo %s",correctuser2);
                return;
            }
        //SE O USUARIO ESTIVER INCORRETO AVISA//
        else
            {
            printf("\nUsuario ou senha incorretos. Restam %d tentativas.\n",tentativas);
            tentativas--;
            }
    } while (tentativas >=0); //POSSUI 3 TENTATIVAS//
    
        if (tentativas==0);//SE O USUARIO ERRAR 3 VEZES ENCERRA//
            {
            printf("\nDesculpe, voce atingiu o limite de tentativas, o programa sera encerrado...\n");
            exit(0);
            }
}
void menu() //função menu//
{
	int saldo;
	float deposito;
	int saque;
	float transf;
	float pagmt;
	FILE *saldoArquivo = fopen("saldo.txt", "r"); //abre arquivo saldo.txt//
	if (saldoArquivo != NULL) 
	{
    fscanf(saldoArquivo, "%d", &saldo);//le o arquivo//
    fclose(saldoArquivo); //fecha  o arquivo//
	} 
	else //erro caso o arquivo nao exista ou esta corrompido//
	{
    printf("\nErro ao abrir o arquivo de saldo.\n");
    printf("Caso esteja com problemas no programa, crie um arquivo (saldo.txt)\n");
    printf("e deixe na pasta raiz do codigo.");
    exit(1);
	}
    int operacoes,voltar;
    printf("\n\n///////////////////////////////////////////////////\n");
    printf("///\t\t\t\t\t\t///\n");
    printf("///\t\t\t\t\t\t///\n");
    printf("///\t\t\t\t\t\t///\n");
    printf("///\t      Escolha as opcoes abaixo\t\t///\n///\t\t\t\t\t\t///\n");
    printf("///\t\t\t\t\t\t///\n");
    printf("///\t\t\t\t\t\t///\n");
    printf("///\t\t\t\t\t\t///\n");
    printf("///////////////////////////////////////////////////\n");
    //SAQUE,SALDO,DEPOSITO,TRANSFERENCIA,PAGAMENTO,HELP//
    printf("\n1 - Saque");
    printf("\n2 - Saldo");
    printf("\n3 - Deposito");
    printf("\n4 - Transferencia");
    printf("\n5 - Pagamentos");
    printf("\n6 - Ajuda");
    printf("\n7 - Sair");
    printf("\n");
    printf("\nDigite sua opcao: ");
    scanf("%d",&operacoes);
    
    //Switch com o menu de opções//
    switch (operacoes)
    {
        case 1:
            {
                printf("\nInforme o valor do Saque\n");
                printf("Valor >>> ");
                scanf("%d",&saque);
                
                //AS MOVIMENTAÇÕES DEVEM SER COERENTES TRANSFERENCIAS NEGATIVA E LIMITE DE SALDO//
                
                if (saque <= 0) 
                {
                printf("Valor de saque invalido.\n");
                } 
                else if (saque > saldo) 
                {
                printf("Saldo insuficiente.\n");
                } 
                else if (saque > 1500)  //SAQUE MAIORES QUE 1500 REAIS NÃO PODE//
                {
                printf("Saque maior que o limite permitido (1500 reais).\n");
                salvarSaldo(saldo);
                } 
                else 
                {
                printf("Saque realizado com sucesso\n");
                saldo -= saque;
				salvarSaldo(saldo);
				}
				printf("Seu novo saldo e R$ %d\n", saldo);
                break;
            }
        case 2:
            {
                printf("\nSeu saldo e R$ %d \n",saldo);
                break;
            }
        case 3:
            {
                printf("\nDigite o valor a ser depositado: ");
                scanf("%f",&deposito);
				saldo = saldo + deposito;
				salvarSaldo(saldo);
				printf("Deposito realizado com sucesso.\n");
				printf("Seu novo saldo e R$ %d\n", saldo);
                break;
            }
        case 4:
            {
                printf("\nDigite o valor da transferencia: ");
                scanf("%f",&transf);
                saldo = saldo - transf;
				salvarSaldo(saldo);
                printf("\nVoce transferiu R$ %.2f e seu novo saldo e de R$ %d", transf, saldo);
                salvarSaldo(saldo);
				break;
            }
        case 5:
            {
                printf("\nDigite o valor da conta a ser paga: ");
                scanf("%f",&pagmt);
                saldo = saldo - pagmt;
				salvarSaldo(saldo);
                printf("\nPagamento realizado com sucesso!\nBoletos podem demorar ate 48h para compensacao.\nPagamentos via PIX podem demorar ate 30 minutos.\nSeu novo saldo e de %d.",saldo);
                salvarSaldo(saldo);
                break;
            }
       case 6:
            {
            	printf("\n\n///////////////////////////////////////////////////\n");
    			printf("///\t\t\t\t\t\t///\n");
    			printf("///\t\t\t\t\t\t///\n");
    			printf("///\t\t\t\t\t\t///\n");
    			printf("///\t    Contate-nos atraves dos numeros\t///\n///(55)3433-5120 ou via whatsapp (55)99155-32963///\n///\t\t\t\t\t\t///\n");
    			printf("///\t\t\t\t\t\t///\n");
    			printf("///\t\t\t\t\t\t///\n");
    			printf("///\t\t\t\t\t\t///\n");
    			printf("///////////////////////////////////////////////////\n");
                break;
            }
        case 7:
        	{
                printf("\nSaindo do sistema...\n");
                salvarSaldo(saldo);
                musica();
    			creditos();
                exit(0);
            }
        default:
        	{
        	printf("Opcao invalida, tente novamente.");
        	menu();
        	}
    }
}
//CRÉDITOS DO AUTOR//
void creditos()
	{
	printf("\n///////////////////////////////////////////////////////////////////////////////////////////////////");
    printf("\n///       \t\t\t\t\t\t\t\t\t\t\t///");
	printf("\n///\t\t\t\tPrograma criado por Victor Hugo.\t\t\t\t///");
	printf("\n///\t\t\t\tDesejo que ele lhe ajude futuramente\t\t\t\t///\n///\t\t\tquando voce estiver sem alguma ideia ou esqueca de algo S2 \t\t///");
	printf("\n///       \t\t\t\t\t\t\t\t\t\t\t///");
	printf("\n///       \t\t\t\t\t\t\t\t\t\t\t///");
	printf("\n///////////////////////////////////////////////////////////////////////////////////////////////////");
	exit(0);
	}
void mybeep(int frequency, int duration)
{
    Beep(frequency, duration);
}
void musica()
{
    FILE *arquivo;
    arquivo = fopen("musica.txt", "r");

    if (arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    int digito;
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        int numero = atoi(linha);

        while (numero > 0)
        {
            int digito = numero % 10;
            Beep(digito * 100, 500);
            numero /= 10;
        }
    }

    fclose(arquivo);
    //EASTER EGG//
}
void salvarSaldo(int saldo)
{
    FILE *saldoArquivo = fopen("saldo.txt", "w");
    if (saldoArquivo != NULL) {
        fprintf(saldoArquivo, "%d", saldo);
        fclose(saldoArquivo);
    } else {
        printf("Erro ao abrir o arquivo de saldo para escrita.\n");
        printf("Caso esteja com problemas no programa, crie um arquivo (saldo.txt)\n");
        printf("e deixe na pasta raiz do codigo.");
        exit(1);
    }
}


//3 FUNÇÕES//
