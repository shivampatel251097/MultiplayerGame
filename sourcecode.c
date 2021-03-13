#include<stdio.h>
#include<semaphore.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
sem_t s;
void detail();
void game();
void detail()
{
        printf("\t\t\t\t***********************WELCOME TO ONLINE MULTIPLAYER GAME **************************\n");
        printf("This Online Multiplayer game is designed by:");
        printf("\n\n\t\t\t\t\t\tName-Shivam Patel\n\t\t\t\t\t\tSection-K1607\n\t\t\t\t\t\tRoll No.-A07\n\t\t\t\t\t\tReg No-11611415\n");
}
void game()
{
        sem_wait(&s);
        printf("Game is running..\n");//complexity O(1) as it is statement
        sleep(2);
        printf("Game is finished\n");//complexity O(1) as it is statement
        sem_post(&s);
}

int main()
{
    detail();
    sem_init(&s,0,1);
    int p,i,k;
    printf("Enter the Number of Players pesent currently:-\n"); //complexity O(1) as it is statement
    scanf("%d",&p);
        if(p<3)
        {
            printf("There must be minimum 3 players for starting the game\n");//complexity O(1) as it is statement

        }
if(p%3!=0)
	{ 
       		int c=p/3;
       		printf("The game can be played %d times with these number of players\n",c);//complexity O(1) as it is statement
        	if(c>=1)
		{
			int i;
        	for(i=0;i<c;i++)		//complexity n for for loop
			{						
        		game();
			}
		}
		int x=p%3;
		int z;
		abc:
        printf("To run the game for 1 more time %d more players are required ",3-x);//complexity O(1) as it is statement
        scanf("%d",&z);
        if(3-x==z)//complexity O(1) as it is statement
		{
        	game();
		}
		else//complexity O(1) as it is statement
			{
				if(3-x>z)
					{
						x=x+z; //complexity O(1) as it is statement
						goto abc;
					}
				else
					{
						printf("\nExcess Players\n");
						exit(0);
					}
			}
    }
else
	{
        p=p/3;//complexity O(1) as it is statement
       	printf("The game can be played %d times with these number of players\n",p);
       	for(i=0;i<p;i++)// complexity=n
      		{
				game();
			}
	}
}
//End of code
