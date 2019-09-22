#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cash=100;

void Play(int bet) {
    int i,x,y,temp,guess;
    char C[3] = {'K','Q','J'};
    srand(time(NULL));
    printf("\nStarting position\t");
    for(i=0; i<3; i++) printf("%c\t",C[i]);
        printf("\nShuffling cards....");
        for(i=0;i<5;i++) {
            x = rand() % 3;
            y = rand() % 3;
            temp=C[x];
            C[x] = C[y]; 
            C[y] = temp;
        }
        printf("\nGuess position of Queen 1,2 or 3\t");
        scanf("%d",&guess);
        if(C[guess-1]=='Q') {
            cash+= 3*bet;
            printf("\nCongratulations you have won %d \n your total cash is %d\t",3*bet,cash);
        }
        else {
            cash-= bet;
            printf("\nSorry you have lost %d \n your total cash is %d\t",bet,cash);
        }
}


int main() {

    int bet;
    while(cash>0) {
        printf("\nEnter bet amount\t");
        scanf("%d",&bet);
        if(bet>cash || bet==0) break;
        Play(bet);
    }
    printf("Game Over");
    
    return 0;
}