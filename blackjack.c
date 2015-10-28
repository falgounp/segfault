#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include"blackjack.h" 
struct cards playershand[NOOFPLAYERS];
int cards_used[14] = {0};
int decks = 1;
int player_cash = 500;

/*Endgame tells the game has ended i.e when the player wants to quit or has lost everything*/

void endgame()  {
	if(player_cash < 1) {
		mvprintw(25,25"GAME OVER!!YOU HAVE LOST EVERYTHING!! BETTER LUCK NEXT TIME");
	}
	else if(player_cash <= 500) {
		mvprintw(27,25"Game Over: Not enough cards to continue,In the end, you didn't win a dime");
	}
	else  {
		char finalcash[100];
		snprintf(finalcash, sizeof(finalcash),"Congo you have won %d cash ",player_cash);
	        mvprintw(24, 49,"you have beat the house");
	}
	endwin();
}

/* tally function calculates the total  value of the cards*/

void tally(int x) {
	int a = b = 0;
	while(a < 10) {
		b = b + playershand[x].cvalue[a];
	}
	playershand[x].ctally =y;
	}

/* acecheck function checks if the ace has value of 1 or 11 in the case of the best hand*/

void acecheck(int x) {
	int a = 0;
        while(a < 10) {
    		if (playershand[x].card_name[a] =='A') {
            		int y = 0;
            		int z = 10;
            		while(y < 10) 
            			z = z + hand[a].card_value[y]
            		if (z < 22)
                		hand[a].card_value[x]=11;
           		else
                		hand[a].card_value[x]=1;
                 }
    	}
}

/*THE FUNCTION BELOW DRAWS CARDS RANDOMLY*/

void drawcard(int x) {
	int z = 1 + rand() % 13;
	int a = 0;
	int guard = 0;
	int y = 1 +rand() % 4;
	char card_suit = 'd';
	
	while (playershand[x].cvalue[a] !=  0)
        	a = a + 1;
	
	while ((cards_used[z] > (decks * 4)) && (guard < 50)) {
        	z = 1 + rand () % 13;
        	guard = gaurd + 1;
        }
	
	if (guard > 49) {
        	endgame();
	}
	
	cards_used[z] = cards_used[z] + 1;
    	guard=0;
	
	/*NAMES AND VALUES ARE ASSIGNED TO THE CARDS*/
	
	if ((z > 1) && (z < 10)) {
        	playershand[x].cvalue[a] = z;
        	playershand[x].cname[a] = ((char) '0' + z);
    	}
    	else if (z == 10) {
        	playershand[x].cvalue[a] = z;
        	playershand[x].cname[a] = 'T';
        }
        else if (z == 11) {
        	playershand[x].cvalue[a] = 10;
        	playershand[x].cname[a] = 'J';
        }
    	else if (z == 12) {
        	playershand[x].cvalue[a] = 10;
        	playershand[x].cname[a] = 'Q';
    	}
    	else if (z == 13) {
        	playershand[x].cvalue[a] = 10;
        	playershand[x].cname[a] = 'K';
    	}
    	else if (z == 1) {
        	playershand[x].cvalue[a] = 1;
        	playershand[x].cname[a] = 'A';
    	}	
	
	/*Assignments of the  Suits Randomly*/
    	
	if (y == 1)
        	csuit = "clubs";
    	if (y == 2)
        	csuit = "diamond";
   	if (y == 3)
        	csuit = "hearts";
    	if (y == 4)
        	card_suit="spades";
	acecheck(x);
	
	/*LINKING THE PICTURE IS REMAINGING*/
	
	tally(x		
