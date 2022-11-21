#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
union REGS i,o;

int status=0;


struct kbc
{
int  qno;
char ques[100];
char ans[50];
char op1[50];
char op2[50];
char op3[50];
char op4[50];
int n;
}obj[50],obj1;

struct profile
{
int pno;
char pname[20];
float hscore;
char pwd[10];
}pobj[50],p1obj;

void showmouse()
{
i.x.ax =1;
int86(0X33,&i,&o);
}
void getmousepos(int *button,int *x,int *y)
{
i.x.ax=3;
int86(0X33,&i,&o);
*button=o.x.bx;
*x=o.x.cx;
*y=o.x.dx;

}



void pro(float score)
{
int count=0,i;
FILE *f;
f=fopen("profile","rb");
while(fread(&pobj[i],sizeof(pobj[i]),1,f)==1)
{
count++;       //for no of records
}
fclose(f);
f=fopen("profile","ab");
for(i=count;i<count+1;i++)
{
printf("Enter your name");
scanf("%s",pobj[i].pname);
pobj[i].pno=count+1;
pobj[i].hscore=score;
fwrite(&pobj[i],sizeof(pobj[i]),1,f);
}
fclose(f);

}

void phscore()
{
int i;
FILE *f;

f=fopen("profile","rb");
gotoxy(1,3);
printf("SL.NO");
gotoxy(10,3);
printf("NAME");
gotoxy(20,3);
printf("SCORE");
while(fread(&pobj[i],sizeof(pobj[i]),1,f)==1)
{
printf("\n\n");
printf("%d.",pobj[i].pno);
printf("\t ");
printf("%s",pobj[i].pname);
printf("\t   ");
printf("%f",pobj[i].hscore);

}
fclose(f);

getch();
}

int password()
{
int i=0,pflag=0,x=0;
char pass[10],ch;
FILE *f;
f=fopen("password","rb");
while(fread(&p1obj,sizeof(p1obj),1,f))
{
x++;
}
fclose(f);

f=fopen("password","ab");
if(x==0)
{

printf("ENTER  THE PASSWORD YOU WISH TO PUT");
gets(p1obj.pwd);
fwrite(&p1obj,sizeof(p1obj),1,f);
fclose(f);
return 2;
}

else
{
//////////////////////////
fclose(f);
f=fopen("password","rb");
gotoxy(25,15);
printf("Enter password");
while(1)
{
ch=getch();

if(ch==13)
break;
else if(ch==8)
{  if(i>0)
    {
      printf("\b");
      printf(" ");
      printf("\b");
      i--;
    }
}
else
{
printf("*");
i++;
pass[i]=ch;
}



}

pass[i+1]='\0';
/////////////problem..../////////////////
for(i=0;pass[i]!='\0';i++)
{
pass[i]=pass[i+1];
}

///////////////////////////////////////
if(strcmpi(pass,p1obj.pwd)==0)
{
pflag=1;
}
fclose(f);


return pflag;
}
}
int enterdata()
{

int i,x=0,flag;
char ch;
FILE *f,*f1;

////////////////////////////////////////


flag=password();

if(flag==2)
{
return 1;
}
else if(flag!=1&&flag!=2)
{
cleardevice();
gotoxy(32,15);
printf("Wrong password");
getch();
return 1;
}
else
{
f=fopen("temp.txt","r");
fscanf(f,"%d",&obj1.n);
fclose(f);
for(i=obj1.n;i<obj1.n+1;i++)
{
cleardevice();
gotoxy(1,1);
printf("Enter the Question");
gets(obj[i].ques);
printf("Enter the option 1");
gets(obj[i].op1);
printf("Enter the option 2");
gets(obj[i].op2);
printf("Enter the option 3");
gets(obj[i].op3);
printf("Enter the option 4");
gets(obj[i].op4);
printf("Eenter the answer");
gets(obj[i].ans);
printf("Enter the Question number");
scanf("%d",&obj[i].qno);
f=fopen("question","ab");
fwrite(&obj[i],sizeof(obj[i]),1,f);
}

fclose(f);
f=fopen("temp.txt","w");
obj1.n=obj1.n+1;
fprintf(f,"%d",obj1.n);
fclose(f);
}
getch();
}

int play()
{
int i,flag=0,flag2,flag3=0,button,x,y,flag4=1,flag5=0;
float score=0;
char ch;
FILE *f;
int gd=DETECT,gm,style;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");

f=fopen("question","rb");
while(fread(&obj[i],sizeof(obj[i]),1,f)==1)
{
k:

//clrscr();
//system("cls");
//cleardevice();

// for back to menu///////////////////////////////////////////
 gotoxy(79,25);
 printf("\n\n\n\n\n");
 printf("                                       " );
 printf("                                       ");
 printf("X");
 setcolor(RED);
 rectangle(616,458,638,479);
 setcolor(WHITE);
////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////



showmouse();


setbkcolor(BLUE);
gotoxy(65,6);
printf("12.120000");
gotoxy(65,7);
printf("11.110000");
gotoxy(65,8);
printf("10.100000");
gotoxy(65,9);
printf(" 9.90000");
gotoxy(65,10);
printf(" 8.80000");
gotoxy(65,11);
printf(" 7.70000");
gotoxy(65,12);
printf(" 6.60000");
gotoxy(65,13);
printf(" 5.50000");
gotoxy(65,14);
printf(" 4.40000");
gotoxy(65,15);
printf(" 3.30000");
gotoxy(65,16);
printf(" 2.20000");
gotoxy(65 ,17);
printf(" 1.10000");



for(style=0;style<1;style++)
settextstyle(1,HORIZ_DIR,5);
setcolor(RED);
outtextxy(167,130,"KBC");



for(style=0;style<1;style++)
settextstyle(12,HORIZ_DIR,8);
setcolor(RED);
outtextxy(500,280,"MONEY TREE");
setcolor(WHITE);

circle(200,150,75);

line(0,291,800,291);//base line
line(450,0,450,292);//vertical line
//////////////////////////// /Money tree/////////////////////////////////////////////////


rectangle(450,78,800,95); //money tree 1
rectangle(450,78,800,111);//money tree 2
rectangle(450,78,800,127);//moneytree 3
rectangle(450,78,800,143);//moneytree 4
rectangle(450,78,800,159);//monrytree 5
rectangle(450,78,800,175);//monrytree 6
rectangle(450,78,800,190);//monrytree 7
rectangle(450,78,800,207);//monrytree 8
rectangle(450,78,800,222);//monrytree 9
rectangle(450,78,800,238);//monrytree 10
rectangle(450,78,800,255);//monrytree 11
rectangle(450,78,800,270);//monrytree 12
////////////////////////////////////////////////////////////////////////

//////////////////////////50:50///////////////////////////////////////////////////

if(status<3)
{
rectangle(450,0,530,30);

for(style=0;style<1;style++)
settextstyle(12,HORIZ_DIR,8);
setcolor(RED);
outtextxy(470,10,"50:50");
setcolor(WHITE);
}
else
{

rectangle(450,0,530,30);

for(style=0;style<1;style++)
settextstyle(12,HORIZ_DIR,8);
setcolor(RED);
outtextxy(470,10,"50:50");
setcolor(WHITE);
line(450,0,530,30);
line(450,30,530,0);
}



///////////////////////////options//////////////////////////////
rectangle(5,365,200,390);  //#b
rectangle(5,332,200,360);//#a
rectangle(230,365,400,390); //#d
rectangle(230,332,400,360); //#c
////////////////////////////////////////////////


gotoxy(1,20);
printf("%d.",obj[i].qno);
printf("%s\n",obj[i].ques);
gotoxy(2,22);
printf("A.%s\n",obj[i].op1);
gotoxy(2,24);
printf("B.%s\n",obj[i].op2);
gotoxy(30,22);
printf("C.%s\n",obj[i].op3);
gotoxy(30,24);
printf("D.%s\n",obj[i].op4);
////////////////////////moving of money tree//////////////////////
if(i==1)
{
setcolor(RED);
rectangle(450,255,800,270);
}
if(i==2)
{
setcolor(RED);
rectangle(450,238,800,255);
}
if(i==3)
{
setcolor(RED);
rectangle(450,222,800,238);
}
if(i==4)
{
setcolor(RED);
rectangle(450,207,800,222);
}
if(i==5)
{
setcolor(RED);
rectangle(450,190,800,207);
}
if(i==6)
{
setcolor(RED);
rectangle(450,175,800,190);
}
if(i==7)
{
setcolor(RED);
rectangle(450,159,800,175);
}
if(i==8)
{
setcolor(RED);
rectangle(450,143,800,159);
}
if(i==9)
{
setcolor(RED);
rectangle(450,127,800,143);
}
if(i==10)
{
setcolor(RED);
rectangle(450,111,800,127);
}

/////////////////////////////////////////////////////////////////////
while(!kbhit())                        //rectangle(5,365,200,390);  //#b
				       // rectangle(5,332,200,360);//#a
				       // rectangle(230,365,400,390); //#d
				       // rectangle(230,332,400,360); //#c
{

	 getmousepos(&button,&x,&y);

	 ////////////mouse detection//////////////////
	 if((x>5)&&(x<200)&&(y>365)&&(y<390))
	 {
	   setcolor(BROWN);
	   rectangle(5,365,200,390);
	 }
	 else
	 {
	 setcolor(WHITE);
	 rectangle(5,365,200,390);
	 }
	 if((x>5)&&(x<200)&&(y>332)&&(y<360) )
	 {
	    setcolor(BROWN);
	   rectangle(5,332,200,360);
	 }
	 else
	 {
	   setcolor(WHITE);
	   rectangle(5,332,200,360);
	 }

	 if((x>230)&&(x<400)&&(y>365)&&(y<390) )
	 {
	  setcolor(BROWN);
	   rectangle(230,365,400,390);
	 }
	 else
	 {
	   setcolor(WHITE);
	   rectangle(230,365,400,390);
	 }
	 if((x>230)&&(x<400)&&(y>332)&&(y<360) )
	 {
	   setcolor(BROWN);
	   rectangle(230,332,400,360);
	 }
	 else
	 {
	   setcolor(WHITE);
	   rectangle(230,332,400,360);
	 }
	 if((x>616)&&(x<638)&&(y>458)&&(y<478) )
	 {
	   setcolor(RED);                //of back to menu
	   rectangle(616,458,638,478);
	 }
	 else
	 {
	   setcolor(WHITE);
	   rectangle(616,458,638,478);
	 }
	 if((x>450)&&(x<530)&&(y>0)&&(y<30) )
	 {
	   setcolor(GREEN);
	   rectangle(450,0,530,30);
	 }                                 //of 50:50
	 else
	 {
	   setcolor(WHITE);
	   rectangle(450,0,530,30);
	 }


       /////// ////////////////////////////////////////////

	 if( (button == 1)&&(x>5)&&(x<200)&&(y>365)&&(y<390) )
	 {
	    flag3=1;
	    break;
	 }
	 if( (button == 1)&&(x>5)&&(x<200)&&(y>332)&&(y<360) )
	 {
	    flag3=2;
	    break;
	 }
	 if( (button == 1)&&(x>230)&&(x<400)&&(y>365)&&(y<390) )
	 {
	    flag3=3;
	    break;
	 }
	 if( (button == 1)&&(x>230)&&(x<400)&&(y>332)&&(y<360) )
	 {
	    flag3=4;
	    break;
	 }

	 if( (button == 1)&&(x>616)&&(x<638)&&(y>458)&&(y<478) )
	 {
	    flag3=5;
	    break;
	 }                                 // rectangle(616,458,638,478);
	 if( (button == 1)&&(x>450)&&(x<530)&&(y>0)&&(y<30) )
	 {
	    flag3=6;             //rectangle(450,0,530,30);

	    break;
	 }



    }


if(flag3==1)
{
ch='b';
}

else if(flag3==2)
{
ch='a';
}
else if(flag3==3)
{
ch='d';
}
else if(flag3==4)
{
ch='c';
}
else if(flag3==5)
{
ch='m';
}
else if(flag3==6)
{
ch='f';
}
else if(flag3==7)
{
ch='n';
}

else if(flag3==0)
{
printf("\n\n\nEnter choice");
z:
scanf("%c",&ch);
}

switch(ch)
{
case 'a':if(strcmpi(obj[i].op1,obj[i].ans)==0)
	 {

	 gotoxy(30,26);
	 printf("\n\nCORRECT");
	 score=score+10000;
	 gotoxy(30,25);
	 printf("\n\n\n\n\n");
	 printf("                                   ");
	 printf("NEXT OUESTION  ->");
	 rectangle(276,458,418,479);
	while(1)
	{
	 getmousepos(&button,&x,&y);

	 if((x>276)&&(x<418)&&(y>458)&&(y<479) )
	 {
	   setcolor(GREEN);
	   rectangle(276,458,418,479);
	 }
	 else
	{
	   setcolor(WHITE);
	   rectangle(276,458,418,479);
	}

	if( (button == 1)&&(x>276)&&(x<418)&&(y>458)&&(y<479) )
	 {
		 //i=i+1;
	 setcolor(WHITE);
	 //sleep(1);
	 cleardevice();
	 goto h;

	 }


       }






	 }
	 else
	 {
	 printf("\n\nNOT CORRECT");
	 flag=1;
	 }
	 break;
case 'b':if(strcmpi(obj[i].op2,obj[i].ans)==0)
	 {

	  gotoxy(30,26);
	  printf("\n\nCORRECT");
	 score=score*3;
	 gotoxy(30,25);
	 printf("\n\n\n\n\n");
	 printf("                                   ");
	 printf("NEXT OUESTION  ->");
	 rectangle(276,458,418,479);
	while(1)
	{
	 getmousepos(&button,&x,&y);

	 if((x>276)&&(x<418)&&(y>458)&&(y<479) )
	 {
	   setcolor(GREEN);
	   rectangle(276,458,418,479);
	 }
	 else
	{
	   setcolor(WHITE);
	   rectangle(276,458,418,479);
	}

	if( (button == 1)&&(x>276)&&(x<418)&&(y>458)&&(y<479) )
	 {
		 //i=i+1;
	 setcolor(WHITE);
	 //sleep(1);
	 cleardevice();
	 goto h;

	 }


       }




	 }
	 else
	 {
	 printf("\n\nNOT CORRECT");
	 flag=1;

	 }

	 break;
case 'c':if(strcmpi(obj[i].op3,obj[i].ans)==0)
	 {


	 gotoxy(30,26);
	  printf("\n\nCORRECT");
	 score=score+10000;
	 gotoxy(30,25);
	 printf("\n\n\n\n\n");
	 printf("                                   ");
	 printf("NEXT OUESTION  ->");
	 rectangle(276,458,418,479);
	while(1)
	{
	 getmousepos(&button,&x,&y);

	 if((x>276)&&(x<418)&&(y>458)&&(y<479) )
	 {
	   setcolor(GREEN);
	   rectangle(276,458,418,479);
	 }
	 else
	{
	   setcolor(WHITE);
	   rectangle(276,458,418,479);
	}

	if( (button == 1)&&(x>276)&&(x<418)&&(y>458)&&(y<479) )
	 {
		 //i=i+1;
	 setcolor(WHITE);
	 //sleep(1);
	 cleardevice();
	 goto h;

	 }


       }




	 }
	 else
	 {
	 printf("\n\nNOT CORRECT");
	 flag=1;
	 }
	 break;

case 'd':if(strcmpi(obj[i].op4,obj[i].ans)==0)
	 {



	 gotoxy(30,26);
	  printf("\n\nCORRECT");
	 score=score+10000;
	 gotoxy(30,25);
	 printf("\n\n\n\n\n");
	 printf("                                   ");
	 printf("NEXT OUESTION  ->");
	 rectangle(276,458,418,479);
	while(1)
	{
	 getmousepos(&button,&x,&y);

	 if((x>276)&&(x<418)&&(y>458)&&(y<479) )
	 {
	   setcolor(GREEN);
	   rectangle(276,458,418,479);
	 }
	 else
	{
	   setcolor(WHITE);
	   rectangle(276,458,418,479);
	}

	if( (button == 1)&&(x>276)&&(x<418)&&(y>458)&&(y<479) )
	 {
		 //i=i+1;
	 setcolor(WHITE);
	 //sleep(1);
	 cleardevice();

	 goto h;

	 }


       }




	 }
	 else
	 {
	 printf("\n\nNOT CORRECT");
	 flag=1;
	 }

	 break;

case  'f' : flag2=0;
	   if(flag5==0)     //for 50:50 status
	   {
	     if(strcmpi(obj[i].ans,obj[i].op1)!=0)
	      {
	       setcolor(RED);               // rectangle(5,365,200,390);  //#b
	       rectangle(5,332,200,360);	   //rectangle(5,332,200,360);//#a
	      flag2++;			   // rectangle(230,365,400,390); //#d
					   // rectangle(230,332,400,360); //#
	      }
	     if(strcmpi(obj[i].ans,obj[i].op2)!=0)
	      {
	       setcolor(RED);

	       rectangle(5,365,200,390);
	       flag2++;
	       if(flag2==2)
		{
		  goto j;
		}
	      }

	     if(strcmpi(obj[i].ans,obj[i].op3)!=0)
	      {
	       setcolor(RED);
	       rectangle(230,332,400,360);
	       flag2++;
	       if(flag2==2)
		{
		  goto j;
		}

	      }
	     if(strcmpi(obj[i].ans,obj[i].op4)!=0)
	      {
	       setcolor(RED);
	       rectangle(230,365,400,390);
	       flag2++;

	       if(flag2==2)
		{
		 goto j;
		}
	      }

	     j:

	     /////status of 5050///////
	     status++;
	     if(status==3)
	     {
	     flag5=1;
	     }
	     //////////////////////////
	     sleep(3);
	     setcolor(WHITE);
	     goto k;
	  }
     else
	  {  goto k;

	  }
	     break;
case 'm':return 1;

	 break;
case 'p':getch();
	 exit(0);
	 break;

case 'n':
	 //i=i+1;
	 setcolor(WHITE);
	 sleep(1);
	 cleardevice();
	 goto h;
	 break;

case '\n':goto k;
	  break;
default:goto z;
}

getch();
if(flag==1)
{
break;
}
h:
i++;
cleardevice();
setcolor(WHITE);
}
fclose(f);

printf("\nYOUR SCORE IS: %f RS\n",score);
pro(score);
return 1;

getch();
cleardevice();
closegraph();


}






void main()
{
char ch;
int c,e,x,y,button;
int gd=DETECT,gm,flag=0,a,flag1=0;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
while(1)
{

int style;

cleardevice();
setbkcolor(GREEN);
setcolor(RED);
for(style=0;style<1;style++)
settextstyle(7,0,4);
outtextxy(150,70,"WELCOME TO KBC ");
showmouse();



gotoxy(35,10);
printf("1.PLAY\n");
gotoxy(35,11);
printf("2.HIGH SCORE\n");
gotoxy(35,12);
printf("3.EXIT");
gotoxy(69,23);
printf("\n\n\n\n\n\n\n");
printf("                              ");
printf("                               ");
printf("9.ENTER DATA");
gotoxy(1,3);
setcolor(WHITE);
rectangle(250,143,374,157);
rectangle(250,160,374,174);
rectangle(250,177,374,192);
rectangle(470,460,590,478);
while(1)
{

getmousepos(&button,&x,&y);
if((x>250)&&(x<374)&&(y>143)&&(y<157))
{
setcolor(RED);
rectangle(250,143,374,157);
}
else
{
setcolor(WHITE);
rectangle(250,143,374,157);
}

if((x>250)&&(x<374)&&(y>160)&&(y<174))
{
setcolor(RED);
rectangle(250,160,374,174);
}
else
{
setcolor(WHITE);
rectangle(250,160,374,174);
}

if((x>250)&&(x<374)&&(y>177)&&(y<192))
{
setcolor(RED);
 rectangle(250,177,374,192);
}
else
{
setcolor(WHITE);
rectangle(250,177,374,192);
}
if((x>470)&&(x<590)&&(y>460)&&(y<478))
{
setcolor(RED);
rectangle(470,460,590,478);
}
else
{
setcolor(WHITE);                               // rectangle(525,460,637,478);
rectangle(470,460,590,478);
}
if((button==1)&&(x>250)&&(x<374)&&(y>143)&&(y<157))
{
 flag1=1;
 c=1;
 break;
}
if((button==1)&&(x>250)&&(x<374)&&(y>160)&&(y<174))
{
flag1=1;
c=2;
break;
}
if((button==1)&&(x>250)&&(x<374)&&(y>177)&&(y<192))
{
flag1=1;
c=3;
break;
}
if((button==1)&&(x>470)&&(x<590)&&(y>460)&&(y<478))
{
flag1=1;
c=9;
break;
}
}
if(flag1==0)
{
scanf("%d",&c);
}


switch(c)
{
case 9: cleardevice();
	a=enterdata();
	a=1;
	break;
case 1: cleardevice();
	a=play();

	break;


case 2: cleardevice();
	phscore();
	cleardevice();
	a=1;
	break;
case 3: sleep(1);
	exit(0);
	break;
}
if(a==1)
{

cleardevice();
continue;
}
if(flag==1)
{
printf("HHHHHHHHHHHHHHHH");
cleardevice();
continue;
}

if(e==1)
{
continue;
}
else
{
break;
}

}
closegraph();
getch();
}