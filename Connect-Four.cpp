#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int examination(char alltable [] [7],int a,char collor,int tour);
void table(char alltable [] [7]);
char choices(int choice,char collor,char alltable[][7]);
			
int main(){
	char alltable [6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ', ' ', ' '},{' ', ' ', ' ', ' ', ' ', ' ', ' '}};
	table(alltable);
	char collor= 'k';
	printf("\n e = Empty Slot    b = Blue Disk     r = Red Disk \n");
	printf("If the player's 4 disk match column, horizontal or cross, the player wins the game...\n");
	printf("First player starts with red disk, then second player will play with blue disks...\n");
	int choice;
	int a;
	int tour=1;
	
	while(tour<=49 && a!=1){
		
		while(tour%2!=0 && a!=1){
			printf("First player (red), please choose a column that you will drop your disk...\n");
			scanf("%d",&choice);
			collor = 'r';
			if(choice<1 || 7<choice){
					printf("You have to choose a number between 1 and 7...\n");
					continue;
				}
			else if(1 <= choice <= 7){
			
				if(alltable[0][choice-1]=='r' ||alltable[0][choice-1]=='b'){
					printf("This column is full...\n");
					continue;
				}
				alltable[6][7]=choices(choice,collor,alltable);
					table(alltable);
					tour++;
					a=examination(alltable, a , collor , tour);
				}
			}
		
		while(tour%2==0 && a!=1){
			printf("Second player (blue), please choose a column that you will drop your disk...\n");
			scanf("%d",&choice);
			collor = 'b';
			
			if(choice<1 || 7<choice){
				printf("You have to choose a number between 1 and 7...\n");
				continue;
			}
				
			else if(1 <= choice <= 7){
				if(alltable[0][choice-1]=='r' ||alltable[0][choice-1]=='b'){
					printf("This column is full...\n");
					continue;
			}
				alltable[6][7]=choices(choice,collor,alltable);
			
				}
					table(alltable);
					tour++;
					a=examination(alltable, a , collor , tour);
				}	
			}
		}
		
		char choices(int choice,char collor,char alltable[][7]){
				if(alltable [5] [choice-1]==' '){
					alltable[5] [choice-1]=collor;
				}
				else if (alltable[4][choice-1]==' ' && alltable [5] [choice-1]!=' '){
					alltable[4] [choice-1]=collor;
				}
				else if (alltable[3][choice-1]==' ' && alltable[4][choice-1]!=' '){
					alltable[3] [choice-1]=collor;
				}
				else if (alltable[2][choice-1]==' ' && alltable[3][choice-1]!=' '){
					alltable[2] [choice-1]=collor;
				}
				else if (alltable[1][choice-1]==' ' && alltable[2][choice-1]!=' '){
					alltable[1] [choice-1]=collor;
				}
				else if (alltable[0][choice-1]==' ' && alltable[1][choice-1]!=' '){
					alltable[0] [choice-1]=collor;
				}
				return alltable[6][7];
		}
		void table(char alltable [] [7]){
		printf("\t\t   1     2     3     4     5     6     7\n\n");
		for(int i=0;i<6;i++){
			printf("\t\t|");
			for(int j=0;j<7;j++){
				printf("  %c  |",alltable [i][j]);
			}
			printf("\n\n");
		}
		}
		int examination(char alltable[][7],int a,char collor,int tour){
		for(int i=0;i<6;i++){
			for(int j=0;j<7;j++){
				//horizontal match
				if(alltable[i][j]== collor && alltable[i][j] == alltable[i][j+1] && alltable[i][j+1] == alltable[i][j+2] && alltable[i][j+2] == alltable[i][j+3] && j<4){
					a=1;
				}
				//vertical match
				else if(alltable[i][j]== collor && alltable[i][j] == alltable[i+1][j] && alltable[i+1][j] == alltable[i+2][j] && alltable[i+2][j] == alltable[i+3][j] && i<3){
					a=1;
				}
				//cross match high to low (left to right)
				else if(alltable[i][j]== collor && alltable[i][j] == alltable[i+1][j+1] && alltable[i+1][j+1] == alltable[i+2][j+2] && alltable[i+2][j+2] == alltable[i+3][j+3] && i<3 && j<4){
					a=1;
				}
				//cross match low to high (left to right)
				else if(alltable[i][j]== collor && alltable[i][j] == alltable[i-1][j+1] && alltable[i-1][j+1] == alltable[i-2][j+2] && alltable[i-2][j+2] == alltable[i-3][j+3] && i>2 && j<4){
					a=1;
				}	
			}
		}
			
		if(a==1 && collor == 'b'){
		printf("Second player (blue) won the game...\n");
			}
					
			else if(a==1 && collor == 'r'){
				printf("First player (red) won the game...\n");
			}
				
			else if(tour==42){
				printf("Draw...");
			}
			return a;
		}	
