#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int tailx[100],taily[100];
int counttail=0;
int width=20,height=20,gameover=0;
int x,y,fruitx,fruity,score,flag;
void setup()
{
    gameover=0;
    x=width/2;
    y=height/2;

    label1:
    fruitx=rand()%20;
    if(fruitx==0)
        goto label1;
    label2:
    fruity=rand()%20;
    if(fruity==0)
        goto label2;
    score=0;
}


//making the boundry
void draw()
{

    int i,j;
    system("cls");
    for(int i=0;i<height;i++)
    {
    for(int j=0;j<width;j++)
    {
        if(i==0||i==height-1||j==0||j==width-1)
        {printf("*");}
        else
        {
            if(i==x && j==y)
                printf("0");
            else if(i==fruitx && j==fruity)
            {
                printf("F");
            }
            else{
                int ch=0;
                for(int k=0;k<counttail;k++) //i,j pair
                {
                   if(i==tailx[k] && j==taily[k])
                   {
                       printf("O");
                       ch=1;

                   }
                }
                if(ch==0)
                printf(" ");

            }

        }


    }
    printf("\n");
    }
     printf("score=%d",score);
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a': //asdw
            flag=1;
            break;
        case 's':
            flag=2;
            break;
        case 'w':
            flag=3;
            break;
        case 'd':
            flag=4;
            break;
        case 'x'://for exiting
            gameover=1;
            break;
        }
    }
}
void makelogic()
{
    int i;
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;
    for(i=1;i<counttail;i++)
    {
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;    }


    switch(flag)
    {
        case 1:
             y--;
             break;
        case 2:
            x++;
            break;
        case 3:
            x--;
            break;
        case 4:
            y++;
            break;
        default:
            break;
    }
    if(x<0||x>width||y<0||y>height)
        gameover=1;//to stop the game
    if(x==fruitx && y==fruity)
    {
        label3://food coordiante
    fruitx=rand()%20;
    if(fruitx==0)
        goto label3;
    label4:
    fruity=rand()%20;
    if(fruity==0)
        goto label4;
    score+=10;
    counttail++;
    }
}


int main()
{
    char c;
    int n,m;
    label5:
 setup();
 while(!gameover){
 draw();
 input();
 makelogic();
 //to make the speed slow
 for(m=0;m<10000;m++){
    for(n=0;n<1000;n++){

    }
 }
 for(m=0;m<1000;m++){
    for(n=0;n<1000;n++){

    }
 }
 }

 printf("\npress y to contine again: ");
 scanf("%c",&c);
 if(c=='y'||c=='Y')
    {
        goto label5;}
 return 0;

}
