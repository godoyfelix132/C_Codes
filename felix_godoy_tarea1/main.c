#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint32_t     u32Collatz(uint32_t   u32Numero);          // Conjetura de Collatz
void         v_CalculaPrimos(uint16_t    u32_Limite);   //Calcular numeros primos
uint32_t     u32SumaDigitos(uint32_t  u32Numero);       //Sumar digitos
uint8_t    u8GetOption();                             //Mostrar menu y optener opción

int main()
{
     static     uint8_t    u8Opc;          //Opcion que elige el usuario
     static     uint32_t   u32NumToSend;   //Numero a enviar a cada función
     auto       bool       bLoop = true;   //Bandera para cliclo infinito

    while(bLoop){   //Ciclo mientas el usuario no sale
        u8Opc = u8GetOption();
        switch(u8Opc){
            case 1:
                fflush( stdin );
                printf("\nNumero:");
                scanf("%d",&u32NumToSend);
                printf("Pasos: %d\n\n",u32Collatz(u32NumToSend));
                break;
            case 2:
                fflush( stdin );
                printf("\nNumero:");
                scanf("%d",&u32NumToSend);
                v_CalculaPrimos(u32NumToSend);
                printf("\n\n");
                break;
            case 3:
                fflush( stdin );
                printf("\nNumero:");
                scanf("%d",&u32NumToSend);
                printf("%d\n\n",u32SumaDigitos(u32NumToSend));
                break;
            case 4:
                printf("Adios");
                bLoop = false;
                break;
            default:
                printf("Opción invalida");
                bLoop = false;
                break;
        }
    }

    return 0;
}
uint8_t    u8GetOption(){

    static uint8_t u8Opc;

    printf("SELECCIONA UNA OPCION\n\n");
    printf("1\tConjetura de Collatz\n");
    printf("2\tNumeros primos\n");
    printf("3\tSumar digitos\n");
    printf("4\tSalir\n\n");
    scanf("%d",&u8Opc);
    return u8Opc;
}
uint32_t    u32Collatz(uint32_t   u32Numero){

    register    bool        odd;            //Bandera verdadera si el valor es impar
    static      uint32_t    u32ToSend;      //Valor enviado como algumento a la función recursiva.
    static      uint32_t    u32Steps;       //Numero de veces que pasa por la función

    u32Steps++;

    //Evaluación para terminar cuando se llegue a 1
    if (u32Numero>1){

        //Evaluar si es impar
        if (u32Numero%2 == 0){
            odd = false;
        }
        else{
            odd = true;
        }

        //Proceso de operaciones
        if (odd){
            printf("\t%d\n",u32Numero);
            u32ToSend = (u32Numero * 3) + 1;
        }
        else{
            printf("%d \n",u32Numero);
            u32ToSend = (u32Numero/2);
        }

        u32Collatz(u32ToSend);//Función recursiva

    }
    else{
        printf("\t%d\n",u32Numero); //Termina impimiento el 1
        return u32Steps;            //Regresa el numero de veces que se llaó la función
    }
}
void    v_CalculaPrimos(uint16_t    u32_Limite){

    register    bool bValorEsPrimo;          //Bandera verdadera cuando el numero no se ha podido dividir
    register    uint8_t u8ConteoColumnas;     //Cuenta de columnas impresas
    static      uint8_t u8LimiteColumnas=8;   //Limite de columnas a imprimir
    static      uint32_t u32Valor,u32Divisor;     //Valores de control para evaluar primos


    for(u32Valor = 3;u32Valor<=u32_Limite;u32Valor++){
        bValorEsPrimo = true;
        for(u32Divisor=2;u32Divisor<u32Valor-1;u32Divisor++){
            if(u32Valor%u32Divisor == 0){
                bValorEsPrimo = false;
                break;
            }
        }
        if(bValorEsPrimo){
            printf("%d\t", u32Valor);
            u8ConteoColumnas++;
            if (u8ConteoColumnas==u8LimiteColumnas){
                u8ConteoColumnas=0;
                printf("\n");
            }
        }
    }

}
uint32_t      u32SumaDigitos(uint32_t  u32Numero){

    auto uint32_t   u32Suma=0;  //Suma de digitos
    auto uint8_t    u8Resto;    //Resto de la operación modulo

    //Evalua si es mayor o igual a 10 ya que 10 es el primer numero de dos digitos
    if (u32Numero>=10){
        while(u32Numero!=0){
            u8Resto=(u32Numero%10);
            u32Suma=(u32Suma+u8Resto);
            //printf("suma: %d\n", u32Suma);
            u32Numero=(u32Numero/10);
        }
        u32SumaDigitos(u32Suma);    //Función recursiva
    }
    else{
      return u32Numero;
    }

}
