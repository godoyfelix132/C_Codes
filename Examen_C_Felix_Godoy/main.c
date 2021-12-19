#include <stdio.h>
#include <stdlib.h>

//char* found(char*str1,char*str2);

char* funcion_1(char*,char*, int, int);

void* funcion_2(char*,int);

int main()
{
    //ejecicio 1
    //char str1[] = "tttazulttt";
    //char str2[] = "azul";
    //int tStr1 = sizeof(str1)/sizeof(char);
    //int tStr2 = sizeof(str2)/sizeof(char);
    //char *p;
    //p = funcion_1(str1,str2,tStr1,tStr2);
    //puts("Direccion");
    //printf("%p\n",str1[3]);
    //puts("puntero");
    //printf("%p\n",p);

    //ejecicio 2
    char str[] = "reversa";
    int tStr = sizeof(str)/sizeof(char);
    funcion_2(str,tStr);

    return 0;
}

void* funcion_2(char* str, int tStr){
    char *temp;
    printf("%s\n",str+6);
    str=str+tStr;
    printf("%s\n",str-8);
    for(int i=0;i<=tStr;i++){
        printf("%c\n",*str+i);
        str+i = temp-tStr-1;
    }
    printf("%c\n",str[0]);
    printf("%c\n",str[1]);
    printf("%c\n",str[2]);
    printf("%c\n",str[3]);

}

char* funcion_1(char *str1,char *str2, int tStr1, int tStr2){
    int flag=0;
    int j=0;
    for(int i=0; i<=tStr1;i++){
        if(str1[i]==str2[0]){//encontro el primer caracter
            for(int x=0;x<=tStr2;x++){//recorre la cadena comparandola
                if(str1[i+x]==str2[x]){
                        j++;
                }
            }
            if(j==tStr2){
                puts("palabra encontrada");
                return str1[i];
                break;
            }
        }
    }
}



