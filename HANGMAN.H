#ifndef HANGMAN
#define HANGMAN
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <graphics.h>
#include <stdio.h>

//Functions and class declarations and definitions

char name[20];

class GameSounds {
public:
    void playSound(int frequency, int duration) {
	sound(frequency);
	delay(duration);
	nosound();
    }
    void sSound() {
	playSound(500, 200);
	playSound(700, 200);
	playSound(900, 200);
    }
    void wSound() {
	playSound(1000, 200);
	playSound(1200, 200);
	playSound(1500, 300);
    }
    void lSound() {
	playSound(300, 200);
	playSound(250, 200);
	playSound(200, 300);
    }
    void e1ASound() {
	playSound(500, 200);
	playSound(300, 200);
	playSound(50, 1000);
    }
    void e1BSound() {
	playSound(300,200);
	playSound(200,200);
	playSound(100,300);
    }
    void e2ASound() {
	playSound(1000, 200);
	playSound(1200, 200);
	playSound(1400, 300);
    }
    void e2BSound() {
	playSound(1200, 200);
	playSound(1300, 200);
	playSound(1500, 300);
    }
};

void Greet() // Function appearing at the start
{
	char Hello[]= "Hello! Welcome to Hangman: The game!";
	char Instr[]= "Save your friend from getting hanged by guessing the word!";
	int i=0,x=0,y=30;
	line(0,60,650,60);
	settextstyle(1,0,2);
	for(i=0;Hello[i]!='\0';i++,x+=18) //For displaying char 1 by 1
	{
		char ch[2];
		ch[0] = Hello[i];
		ch[1] = '\0';
		delay(20);
		outtextxy(x,y,ch);
	}
	setcolor(YELLOW);
	settextstyle(1,0,1);
	x=0,y=70;
	for(i=0;Instr[i]!='\0';i++,x+=11)
	{
		char ch[2];
		ch[0] = Instr[i];
		ch[1] = '\0';
		delay(20);
		outtextxy(x,y,ch);
	}

	setcolor(GREEN);
	outtextxy(0,100,"Do you wish to play?(Y/N)");
	setcolor(WHITE);
}

int dec( char play)
{
	if (play=='n')
	{
		setcolor(LIGHTRED);
		delay(500);
		outtextxy(0,130,"You chose not to save your friend!");
		delay(2000);
		setcolor(WHITE);  // display our angry friend ;]
		circle(500,200,30);//face
		line(480,195,490,200);
		line(520,195,510,200);
		circle(485,200,2);
		circle(515,200,2);
		arc(500,220,0,180,10);
		line(500,230,500,320);//body
		line(500,250,460,280);
		line(500,250,540,280);
		line(500,320,460,350);
		line(500,320,540,350);
		delay(3000);
		setcolor(LIGHTBLUE);
		settextstyle(10,0,7);
		outtextxy(200,250,"Bye!");
		GameSounds g;
		g.e1BSound();
		return 1;
	}
	else if(play=='y'){
		setcolor(LIGHTGREEN);
		outtextxy(0,140,"You chose to save your friend!");
		delay(500);
		settextstyle(0,0,2);
		setcolor(LIGHTCYAN);
		GameSounds g;
		g.e2ASound();
		outtextxy(220,250,"Loading");
		delay(500);
		outtextxy(320,250," .");
		delay(500);
		outtextxy(330,250," .");
		delay(500);
		outtextxy(340,250," .");
		delay(500);
		cleardevice();
		cout << "\n\n\n\n\n\n\n\n\nPlease enter your name : ";
		gets(name);
		return 0;
	}
	return -1;
}

void stand()
{
	bar(100,350,500,400);
	line(400,150,400,400);
	line(250,150,400,150);
	line(250,150,250,170);
}

void display_friend(int misses)
{
	cleardevice();
	setcolor(WHITE);
	switch(misses)
	{
		case 0:
		stand();
		break;
		case 1:
		stand();
		circle(250,190,20);
		break;
		case 2:
		stand();
		circle(250,190,20);
		line(250,210,250,260);
		break;
		case 3:
		stand();
		circle(250,190,20);
		line(250,210,250,260);
		line(250,220,210,260);
		break;
		case 4:
		stand();
		circle(250,190,20);
		line(250,210,250,260);
		line(250,220,210,260);
		line(250,220,290,260);
		break;
		case 5:
		stand();
		circle(250,190,20);
		line(250,210,250,260);
		line(250,220,210,260);
		line(250,220,290,260);
		line(250,260,210,300);
		break;
		case 6:
		stand();
		circle(250,190,20);
		line(250,210,250,260);
		line(250,220,210,260);
		line(250,220,290,260);
		line(250,260,210,300);
		line(250,260,290,300);
		break;
		default:
		cout << "OOPS! Something went wrong! (Your friend is safe!)"<<endl;
		break;
	}
}

void display_player(char str[10],char ans[10],int misses)
{
	int i , x=20 , y=10;
	setcolor(WHITE);
	settextstyle(0,0,1);
	outtextxy(20,10,"Incorrect Guesses :- ");
	x=20;
	y=25;
	for(i=0;str[i]!='\0' && i<misses;i++,x+=10)
	{
		char ch[2];
		ch[0] = str[i];
		ch[1] = '\0';
		outtextxy(x,y,ch);
	}
	str[i]=NULL;
	outtextxy(20,40,"Tries left:");
	misses = 7 - misses;
	int arr[2];
	arr[0] = misses;
	char ch[2];
	ch[0] = (arr[0]+48);
	ch[1] = '\0';
	outtextxy(130,40,ch);
	outtextxy(20,55,"The Word : ");
	x = 20;
	y = 70;
	for(i=0;ans[i]!='\0';i++,x+=10)
	{
		char ch[2];
		ch[0] = ans[i];
		ch[1] = '\0';
		outtextxy(x,y,ch);
	}
}

void result(char ans[10],char word[10],int misses)
{
	cleardevice();
	GameSounds g;
	if(strcmp(ans,word)==0)
	{
		settextstyle(7,0,1);
		setcolor(LIGHTGREEN);
		outtextxy(50,80,"Congratulations! You saved your friend's life just now!");
		g.e2ASound();
		setcolor(WHITE);
		circle(250,190,20);
		line(240,180,240,185);
		line(260,180,260,185);
		arc(250,190,180,360,10);
		line(250,210,250,260);
		line(250,220,210,260);
		line(250,220,290,260);
		line(250,260,210,300);
		line(250,260,290,300);
		delay(2000);
		line(240,190,260,190);
		rectangle(290,140,600,190);
		setcolor(LIGHTMAGENTA);
		settextstyle(5,0,2);
		outtextxy(305,150,"Thank You , My Friend! ");
		char ch[2];
		settextstyle(0,0,2);
		ch[0] = 03;
		ch[1] = '\0';
		outtextxy(565,160,ch);
		g.e2BSound();
		delay(3000);
		settextstyle(1,0,5);
		setcolor(LIGHTCYAN);
		outtextxy(120,400,"[You may leave now]");
		ofstream my_file("GAMEDATA.txt",ios::app);
		my_file << "\n" << setw(20) << name;
		my_file << "\t" << setw(10) << word ;
		my_file << "\t\t" << misses;
		my_file << "\t" << "WIN";
		my_file.close();
		return;
	}
	else
	{
		settextstyle(1,0,2);
		setcolor(LIGHTRED);
		outtextxy(100,50,"Oh no! You could not save your friend!");
		setcolor(WHITE);
		bar(100,350,500,400);
		line(400,150,400,400);
		line(250,150,400,150);
		line(250,150,250,170);
		setcolor(LIGHTRED);
		circle(250,190,20);
		line(235,185,245,195);//dead eyes
		line(235,195,245,185);//
		line(255,185,265,195);//
		line(255,195,265,185);//
		line(250,210,250,260);
		line(250,220,210,260);
		line(250,220,290,260);
		line(250,260,210,300);
		line(250,260,290,300);
		g.e1BSound();
		delay(3000);
		cleardevice();
		settextstyle(1,0,2);
		setcolor(RED);
		circle(300,100,50);
		setfillstyle(SOLID_FILL,RED);
		fillellipse(320,90,10,15);
		fillellipse(280,90,10,15);
		arc(300,100,170,10,42);
		arc(300,85,190,350,42);
		floodfill(300,140,RED);
		circle(300,100,55);
		floodfill(352,100,RED);
		outtextxy(110,200,"Mwuahahahahahahahahahahahahahah");
		g.e1ASound();
		delay(2000);
		cleardevice();
		setcolor(RED);
		circle(300,100,50);
		setfillstyle(SOLID_FILL,RED);
		fillellipse(320,90,10,15);
		fillellipse(280,90,10,15);
		arc(300,100,170,10,42);
		arc(300,85,190,350,42);
		floodfill(300,140,RED);
		circle(300,100,55);
		floodfill(352,100,RED);
		outtextxy(150,200,"I suggest you should leave now!");
		g.e1BSound();
		ofstream my_file("GAMEDATA.txt",ios::app);
		my_file << "\n" << setw(20) << name;
		my_file << "\t" << setw(10) << word ;
		my_file << "\t\t" << misses;
		my_file << "\t" << "LOSS";
		my_file.close();
		return;
	}
}

#endif