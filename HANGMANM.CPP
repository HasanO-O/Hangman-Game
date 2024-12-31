#include <iostream.h>
#include <fstream.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include "HANGMAN.h"
#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <ctype.h>
//IMPORTANT : This file must be stored in the BGI folder of TurboC++
class Game {   // class containing virtual function & destructor
	public:
	virtual void play_game() = 0;
	virtual ~Game(){
		cout << "Game destroyed!" << endl;
	}
};

class Words : public Game,public GameSounds
{
	public:
	char word[10];//words
	char ans[10];//displays answer on the screen
	char str[10]; //stores user's input string
	char letter;
	int misses;
	int guess;

	void play_game();
	Words()
	{
		sSound();
		srand(time(NULL));
		//define words for each category
		char values[][10]={
		"DOG","CAT","PANDA","BEAR","TIGER","HORSE","HYENA",
		"BURGER","PIZZA","BURRITO","FRANKIE","FRIEDRICE","NOODLES","BIRYANI",
		"APPLE","MANGO","GUAVA","WATERMELON","KIWI","ORANGE","BANANA",
		"PINK","BLACK","GREEN","YELLOW","BLUE","WHITE","MAGENTA",
		"SHINCHAN","DORAEMON","POKEMON","BAYBLADE","BENTEN","SCOOBYDOO","MINIONS",
		"IRONMAN","SUPERMAN","BATMAN","SPIDERMAN","BLACKWIDOW","THOR","VISION",
		"MUMBAI","CHENNAI","KOLKATA","LUCKNOW","DARJEELING","BANGLORE","HYDERABAD"
		};
		int N = sizeof(values) / sizeof(values[0]);
		int index = rand() % N;
		strcpy(word,values[index]);
		int i=0;
		while(i<strlen(word))
		{
			ans[i]='_';
			i++;
		}
		ans[i]='\0';
		str[i]='\0';
		misses=0;
		guess=0;
	}
};

void Words :: play_game()
{
	int i;
	while(strcmp(word,ans)!=0 && misses<7)
	{
		display_friend(misses);
		display_player(str,ans,misses);
		if(strcmp(word,"BATMAN")== 0 || strcmp(word,"IRONMAN")== 0 ||
		 strcmp(word,"THOR")== 0 || strcmp(word,"BLACKWIDOW")== 0 ||
		 strcmp(word,"SPIDERMAN")== 0 || strcmp(word,"SUPERMAN")== 0 ||
		 strcmp(word,"VISION")== 0)
		 {
		   outtextxy(20,90,"The word is related to Superheroes");
		 }
	      else if(strcmp(word,"DORAEMON")== 0 || strcmp(word,"SHINCHAN")== 0 ||
		      strcmp(word,"BAYBLADE")== 0 || strcmp(word,"SCOOBYDOO")== 0 ||
		      strcmp(word,"MINIONS")== 0 || strcmp(word,"POKEMON")== 0 ||
		      strcmp(word,"BENTEN")== 0)
		 {
		   outtextxy(20,90,"The word is related to Cartoons/Anime");
		 }
	      else if(strcmp(word,"MANGO")== 0 || strcmp(word,"APPLE")== 0 ||
		      strcmp(word,"KIWI")== 0 || strcmp(word,"GUAVA")== 0 ||
		      strcmp(word,"WATERMELON")== 0 || strcmp(word,"BANANA")== 0 ||
		      strcmp(word,"CHERRY")== 0)
		 {
		   outtextxy(20,90,"The word is related to Fruits");
		 }
	      else if(strcmp(word,"MUMBAI")== 0 || strcmp(word,"KOLKATA")== 0 ||
		      strcmp(word,"BANGALORE")== 0 || strcmp(word,"LUCKNOW")== 0 ||
		      strcmp(word,"DARJEELING")== 0 || strcmp(word,"CHENNAI")== 0 ||
		      strcmp(word,"HYDREBAD")== 0)
		 {
		   outtextxy(20,90,"The word is related to a City");
		 }
	      else if(strcmp(word,"DOG")== 0 || strcmp(word,"CAT")== 0 ||
		      strcmp(word,"BEAR")== 0 || strcmp(word,"PANDA")== 0 ||
		      strcmp(word,"HORSE")== 0 || strcmp(word,"TIGER")== 0 ||
		      strcmp(word,"HYENA")== 0)
		 {
		   outtextxy(20,90,"The word is related to Animals");
		 }
	      else if(strcmp(word,"PIZZA")== 0 || strcmp(word,"FRIEDRICE")== 0 ||
		      strcmp(word,"BURGER")== 0 || strcmp(word,"BURRITO")== 0 ||
		      strcmp(word,"FRANKIE")== 0 || strcmp(word,"BIRYANI")== 0 ||
		      strcmp(word,"NOODLES")== 0)
		 {
		   outtextxy(20,90,"The word is related to Food");
		 }
	      else if(strcmp(word,"BLACK")== 0 || strcmp(word,"WHITE")== 0 ||
		      strcmp(word,"PINK")== 0 || strcmp(word,"CYAN")== 0 ||
		      strcmp(word,"GREEN")== 0 || strcmp(word,"BLUE")== 0 ||
		      strcmp(word,"MAGENTA")== 0)
		 {
		   outtextxy(20,90,"The word is related to Colors");
		 }

		outtextxy(20,110,"Guess the word (Enter 1 character at a time)");
		letter = getch();
		letter = toupper(letter);
		for(i=0;i<strlen(word);i++)
		{
			if(letter==word[i])
			{
				ans[i]=letter;
				guess=1;
			}
		}
		if(guess==1)
		{
			outtextxy(20,130,"CORRECT! You're getting closer!");
			wSound();
			delay(2000);
		}
		else
		{
			outtextxy(20,130,"INCORRECT! Your friend is in more trouble now!");
			lSound();
			str[misses]=letter;
			misses++;
			delay(2000);
		}
		guess=0;
	}
	result(ans,word,misses);
}

class Man : public Words
{
	public:
	Man()
	{
		Greet();
	}
	~Man()
	{
		cout << "Object destroyed!" << endl;
	}
};

int main()
{
	int gd=DETECT , gm;
	char play,Start;
	initgraph(&gd,&gm,"C://turboc3/bgi");
	Game* game = new Man();
	Man m1;
	play = getch();
	delay(100);
	Start = dec(tolower(play));
	if(Start==0){
		game->play_game(); //Call method of other class using
	}                          //base class pointer hence showing
				   //polymorphism of virtual function
	else if(Start==-1)
	{
		cleardevice();
		closegraph();
		cout << "\n\n\n\n\n\n\n\n\n\tERROR READING INPUT(Incorrect input given)! Please try again!" << endl;
		getch();
		return 1;
	}
	getch();
	cleardevice();             //Virtual destructor will also be invoked
	closegraph();
	return 0;
}
