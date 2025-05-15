#include<stdio.h>
int main()
{
    int notes,rem;
    printf("enter the amout");
    scanf("%d", &notes);
    if (notes>=500)
    {
        rem=notes%500;
        printf("%d notes is %d\n",500,notes/500);
        notes=rem;
    }
    if (notes>=200)
    {
        rem = notes%200;
        printf("%d notes is %d\n",200,notes/200);
        notes=rem;
    }
    if (notes>=100)
    {
        rem = notes%100;
        printf("%d notes is %d\n",100,notes/100);
        notes=rem;
    }
    if (notes>=50)
    {
        rem = notes%50;
        printf("%d notes is %d\n",50,notes/50);
        notes=rem;
    }
     if (notes>=20)
    {
        rem = notes%20;
        printf("%d notes is %d\n",20,notes/20);
        notes=rem;
    }
     if (notes>=10)
    {
        rem = notes%10;
        printf("%d notes is %d\n",10,notes/10);
        notes=rem;
    }
     if (notes>=5)
    {
        rem = notes%5;
        printf("%d notes is %d\n",5,notes/5);
        notes=rem;
    }
     if (notes>=2)
    {
        rem = notes%2;
        printf("%d notes is %d\n",2,notes/2);
        notes=rem;
    }
     if (notes>=1)
    {
        rem = notes%1;
        printf("%d notes is %d\n",1,notes/1);
        notes=rem;
    }
return 0;
}