#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//uso de variáveis globais para garantir o acesso por todas as funções as quais esses são requisitados
char complexo1[30],complexo2[30]; char ultimo[30];
int inserido;

//ERRO APRESENTADO, COMENTADO E SOLUCIONADO NA LINHA 107.

int leituramain(){
    int operadormain;
    //Criada função operador main para evitar repetição
     do{//imprime o manual novamente para que o usuário consiga escolher sem necessidade de repetição de escrita
        puts("Manual:");
        printf("1: Inserir números complexos em um vetor\n2: Soma entre números complexos\n3: Subtração entre complexos\n4: Multiplicação entre complexos\n5: Divisão entre complexos\n6-Exibir\n7-Sair\n");
        scanf("%d",&operadormain);
        system("clear");
     }while(operadormain<0 || operadormain > 7);

     return(operadormain);
}
int leitura(){
    int operador;
    void scan();
    do{
        puts("1- Deseja inserir manualmente os números\n2-Deseja usar números já inseridos\n");
        scanf("%d",&operador);
        if(operador!=1 && operador!=2){
            printf("Número inválido, insira novamente o valor desejado\n");
            scanf("%d",&operador);
        }
        if(operador == 2 && inserido != 1){
            puts("Não há números inseridos\n");
            scan();
           inserido = 1;
        }
    }while(operador!=1 && operador!=2);
    system("clear");
    return operador;
}
int operadorresultados(){
    int a;
    //variável genérica a paenas para verificação e envio de dados para as outras funções
    while(a!=0 && a!=2){
        puts("0-Deseja imprimir os complexos armazenados por você? OU 2-deseja imprimir o último resultado salvo?\n");
        scanf("%d",&a);
        if(a!=0 && a!=2){
            puts("INválido\n");
            scanf("%d",&a);
        }
    }
    return a;
}
void scan(){
    //aqui salvamos os dados inseridos pelo usuário nas variáveis globais
    puts("Olá, vamos inserir os números no vetor\n");
    puts("Digite o 1 complexo: ");
    scanf("%s",complexo1);
    setbuf(stdin,NULL);
    puts("Digite o 2 complexo: ");
    scanf("%s",complexo2);
    inserido = 1;
    setbuf(stdin,NULL);
    return;
}
void adicionar (char C1[],char C2[]){
        puts("Complexo 1:");
        scanf("%s",C1);
        setbuf(stdin,NULL);
        puts("Complexo 2:");
        scanf("%s",C2);
        setbuf(stdin,NULL);
        system("clear");
        return;
}
void resultados(int check, char RF[]){
    if(check == 1){
        printf("Resultado: %s\n\n",RF);
        return;
    }
    else if(check == 0){
        printf("Complexos dentro do vetor armazenado pelo usuário: %s\n%s\n",complexo1,complexo2);
        return;
    }
    else if(check == 2){
        printf("O último resultado realizado pela calculadora é: %s\n",ultimo);
        return;
    }
}
void soma(){
    int op;
    int indice=0;
    char C1[15],C2[15],RF[30];
    double real[2],im[2];
    double RR,RI;
    op = leitura();
    if(op==1){
        //se ele deseja inserir valores, chamamos uma função para adicionar e utilizar os outros valores
        adicionar(C1,C2);
        printf("Número complexo: (%s)+(%s)\n",C1,C2);
        sscanf(C1,"%lf %lf",&real[0],&im[0]);
        sscanf(C2,"%lf %lf",&real[1],&im[1]);
        RR = real[0] + real[1];
        RI = im[0] + im[1];
        if(RI >= 0) //Erro citado no e-mail era referente à estes casos cujo RI estava (RI > 0), portanto resultados iguais a 0 não acompanhariam o sinal de +
                    //e com esse pequeno ajuste, foi possivel arrumar o problema do 0
            indice++;
        if(indice == 1){
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(RF,"%s+%si",C1,C2);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
        else{
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(RF,"%s%si",C1,C2);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
    }
    if(op == 2){
        sscanf(complexo1,"%lf %lf",&real[0],&im[0]);
        sscanf(complexo2,"%lf %lf",&real[1],&im[1]);
        RR = real[0] + real[1];
        RI = im[0] + im[1];
        if(RI >= 0)
            indice++;
        if(indice == 1){
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(RF,"%s+%si",C1,C2);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
        else{
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(RF,"%s%si",C1,C2);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
         inserido = 1;
    }
    return;
}
void subtracao(){
    int op;
    int indice=0;
    char C1[15],C2[15],RF[30];
    double real[2],im[2];
    double RR,RI;
    op = leitura();
    if(op==1){
        adicionar(C1,C2);
        printf("Número complexo: (%s)-(%s)\n",C1,C2);
        sscanf(C1,"%lf %lf",&real[0],&im[0]);
        sscanf(C2,"%lf %lf",&real[1],&im[1]);
        RR = real[0] - real[1];
        RI = im[0] - im[1];
        if(RI >= 0)
            indice++;
        if(indice == 1){
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(RF,"%s+%si",C1,C2);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
        else{
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(RF,"%s%si",C1,C2);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
    }
    else if(op==2){
        sscanf(complexo1,"%lf%lf",&real[0],&im[0]);
        sscanf(complexo2,"%lf%lf",&real[1],&im[1]);
        RR = real[0] - real[1];
        RI = im[0] - im[1];
        if(RI >= 0)
            indice++;
        if(indice == 1){
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(RF,"%s+%si",C1,C2);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
        else{
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(RF,"%s%si",C1,C2);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
    }
    indice = 0;
    return;
}
void multiplicar(){
     int op;
    int indice=0;
    char C1[15],C2[15],RF[30];
    double real[2],im[2];
    double RR,RI;
    op = leitura();
    if(op==1){
        adicionar(C1,C2);
        printf("Número complexo: (%s)*(%s)\n",C1,C2);
        sscanf(C1,"%lf %lf",&real[0],&im[0]);
        sscanf(C2,"%lf %lf",&real[1],&im[1]);
        RR = ((real[0]*real[1])-(im[0]*im[1]));
        RI = ((real[0]*im[1])+(real[1]*im[0]));
        if(RI >= 0)
            indice++;
        if(indice == 1){
            sprintf(C1,"%0.1lf",RR);
            sprintf(C2,"%0.1lf",RI);
            sprintf(RF,"%s+%si",C1,C2);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
        else{
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(RF,"%s%si",C1,C2);
            strcpy(ultimo,RF);
            resultados(1,RF);;
        }
    }
    else if(op==2){
        sscanf(complexo1,"%lf%lf",&real[0],&im[0]);
        sscanf(complexo2,"%lf%lf",&real[1],&im[1]);
        RR = ((real[0]*real[1])-(im[0]*im[1]));
        RI = ((real[0]*im[1])+(real[1]*im[0]));
        if(RI >= 0)
            indice++;
        if(indice == 1){
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(RF,"%s+%si",C1,C2);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
        else{
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(RF,"%s%si",C1,C2);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
    }
    indice = 0;
    return;
}
void divisao(){
    int op;
    int indice=0;
    char C1[15],C2[15],C3[15],RF[30];
    double real[2],im[2];
    double RR,RI,RD;
    op = leitura();
    if(op==1){
        adicionar(C1,C2);
        printf("Número complexo: (%s)/(%s)\n",C1,C2);
        sscanf(C1,"%lf %lf",&real[0],&im[0]);
        sscanf(C2,"%lf %lf",&real[1],&im[1]);
        RR = ((real[0]*real[1])-(im[0]*im[1]));
        RI = ((real[0]*im[1])+(real[1]*im[0]));
        RD = ((real[1]*real[1])+(im[1]*im[1]));
        if(RD == 0){
            puts("Divisão por 0 não é possível\n");
            return;
        }
         if((RI >= 0 && RD >= 0)||(RI<0 && RR<0 && RD<0))
            indice++;
        if(indice == 1){
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(C3,"%.1lf",RD);
            sprintf(RF,"(%s+%si)/%s",C1,C2,C3);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
        else{
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(C3,"%.1lf",RD);
            sprintf(RF,"(%s%si)/%s",C1,C2,C3);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
    }
    else if(op==2){
        sscanf(complexo1,"%lf%lf",&real[0],&im[0]);
        sscanf(complexo2,"%lf%lf",&real[1],&im[1]);
        RR = ((real[0]*real[1])+(im[0]*im[1]));
        RI = ((real[1]*im[0])-(real[0]*im[1]));
        RD = ((real[1]*real[1])+(im[1]*im[1]));
        if(RD == 0){
            puts("Divisão por 0 não é possível\n");
            return;
        }
        if((RI >= 0 && RD >= 0)||(RI<0 && RR<0 && RD<0))
            indice++;
        if(indice == 1){
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(C3,"%.1lf",RD);
            sprintf(RF,"(%s+%si)/%s",C1,C2,C3);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
        else{
            sprintf(C1,"%.1lf",RR);
            sprintf(C2,"%.1lf",RI);
            sprintf(C3,"%.1lf",RD);
            sprintf(RF,"(%s%si)/%s",C1,C2,C3);
            strcpy(ultimo,RF);
            resultados(1,RF);
        }
    }
    indice = 0;
    return;
}
int main(){
    int continuar = 0;
    int operador;
    operador = leituramain();
    char real[2][11],imag[2][15];
    int check;
    do{
        switch(operador){
            case 1: scan(); operador = leituramain(); break;

            case 2: soma(); operador = leituramain(); break;

            case 3: subtracao(); operador = leituramain(); break;

            case 4: multiplicar(); operador = leituramain(); break;

            case 5: divisao();  operador = leituramain(); break;

            case 6: check = operadorresultados();
            if(check == 0){ resultados(check,complexo1);} else{resultados(2,ultimo);}operador = leituramain(); break;

            case 7: continuar = 1; break;

            default: puts("Número inválido, digite outro valor válido");  operador = leituramain(); break;
        }
    }while(continuar!=1);
    return 0;
}
