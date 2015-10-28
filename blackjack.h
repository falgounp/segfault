#define SIZE 7
#define NOOFPLAYERS 2
typedef struct {
	int cvalue;
	char cname[11];
	int ctally;
	char csuit[11];
}cards;
void endgame();
void tallying(int x);
void acecheck(); 
void drawacard();
void dealer's_turn();
void player's_turn();
void handshow();
void selecttheacevalue();
void Double();
void split();
void betmoney();

