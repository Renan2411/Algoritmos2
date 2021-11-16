#include <stdio.h>
#include <stdlib.h>

//Criando um Registro/Estrutura
struct ficha_aluno
{
    char nome[50];
    char disciplina[40];
    float nota_p1;
    float nota_p2;
}alunoZ; //Da para criar junto com a criação do Registro

int func(){
    struct ficha_aluno alunoY;

    return 0;
}

int main(){
    //Forma de declaração de uma variável de STRUCT
    struct ficha_aluno aluno[10]; 

    return 0;
}