/******************************************************************************

                           Assignment ConnectFour game

 Author : Bhagyashree Birajdar
 Date   : 17/11/2021

A 2-D array/matrix is used to create a board as (scores[][]) on which the game is played.
Further, number of rows as (ROWS) and columns as (COLS) for board is taken 
from user and also accept the column number in which they have to put their piece.

The program is divided into 2 major modules -1)Main 2) 5 function implementations
5 Functions:
1)init_scores() - fills the scores with the empty character
2) display_board() - prints the board and the scores according to current game
3)choose_column() - choose column number
4) pushinto_column() - fills the column according to what's already in there
5) checkfor_connect(char disc) - This function checks for a 4-disc row in part1, column in part2 and diagonal in part3
    

*******************************************************************************/





#include <stdio.h>


#define CONNECT   4
char scores[20][20];
int column = 0;
int ROWS,COLS;
char disc = 'r';

void init_scores();
void display_board();
void choose_column();
void pushinto_column();
int checkfor_connect(char disc);

/*------------------------------ Main Function --------------------------------*/

main()
{
    printf("Enter number of rows\t");
    scanf("%d",&ROWS);
    printf("Enter number of columns\t");
    scanf("%d",&COLS);
    
    init_scores();
   // test_scores();
    display_board();
    
    while (1)
    {
        printf("Player %c", disc);
        choose_column();
        printf("\n\n");
        display_board();
        if (checkfor_connect('r'))
        {
            printf("\n\nPlayer r wins!\n\n");
            break;  
        }
        if (checkfor_connect('y'))
        {
            printf("\n\nPlayer y wins!\n\n");
            break;  
        }   
    }
    
    return 0; 
}

/*------------- Function Definations/Function Implementations -----------------*/

void init_scores()
{
    // fill the scores with the empty character:
    int i, j;
    
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            scores[i][j] = ' ';
        }
    }
}

void display_board()
{
    // print the board and the scores according to current game:
   
    int i, j;
    
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("| %c ", scores[i][j]);
            
        }
        printf("|\n----------------------");
        printf("\n");
       
    }
}

void choose_column()
{
    // choose column number:
    int c;
    
    while (1)
    {
        
        printf("\tWhat column do you want to put your piece?: ");
        scanf(" %d", &c);
        switch(c)
        {
            case  1 :
                    column = 0;
                     if(c>COLS)
                    {
                        printf("Please give column less than or equal to %d",COLS);
                    }
                    break;
            case  2 :
                    column = 1;
                     if(c>COLS)
                    {
                        printf("Please give column less than or equal to %d",COLS);
                    }
                    break;
            case  3 :
                    column = 2;
                    if(c>COLS)
                    {
                        printf("Please give column less than or equal to %d",COLS);
                    }
                    break;
            case  4 :
                    column = 3;
                    if(c>COLS)
                    {
                        printf("Please give column less than or equal to %d",COLS);
                    }
                    break;
            case  5 :
                    column = 4;
                    if(c>COLS)
                    {
                        printf("Please give column less than or equal to %d",COLS);
                    }
                    break;
            case  6 :
                    column = 5;
                     if(c>COLS)
                    {
                        printf("Please give column less than or equal to %d",COLS);
                    }
                    break;
            case  7 :
                    column = 6;
                     if(c>COLS)
                    {
                        printf("Please give column less than or equal to %d",COLS);
                    }
                    break;
            default:
                   column = 666;
                   printf("\nWrong letter! Try again.\n\n");
                   display_board();
        }
        
        /* If  only the column number given by user is valid and the top most row of board is 
           empty push disc in column */
        if ((column >= 0 && column <= 6) && (scores[0][column] == ' '))
        {
            pushinto_column();
            disc = (disc == 'r') ? 'y' : 'r';
            break;
        }
        if((scores[0][column])!=0)
        {
            printf("The %d column is full !!! Please try another column\n",(column+1));
        }
    }
}

void pushinto_column()
{
    // fills the column according to what's already in there:
   
    int level ;     /* lowest level or bottom of the board */

    for (level = ROWS-1; level >= 0; level--)
    {
        if (scores[level][column] == ' ')
        {
            scores[level][column] = disc;
            break;
        } 
    }               
}

int checkfor_connect(char disc)
{
    /* This function checks for a 4-disc row in part1, column in part2 and diagonal in part3
    
    /* Part 1 - check for 4 connected rows
       check for 4-disc rows
       each row has 4 different ways to connect 4
    
    | X | X | X | X |   |   |   |
    |   | X | X | X | X |   |   |
    |   |   | X | X | X | X |   |
    |   |   |   | X | X | X | X |
    
     */
     
    int i, j, k;
    int count;
    int ways = 4;
    
    for (i = 0; i < ROWS; ++i)
    {
        for (j = 0; j < ways; ++j)
        {
            count = 0;
            for (k = 0; k < CONNECT; ++k)
            {
                if (scores[i][j + k] == disc) count++;
            }
            if (count == CONNECT) return 1;
        }
    }
    
    
    /* Part 2 - check for 4 connected columns
       check for 4-disc columns
       each column has 3 different ways to connect 4
    
    
    | X |   |   |
    | X | X |   |
    | X | X | X |
    | X | X | X |
    |   | X | X |
    |   |   | X |
    
    */
    
    ways = 3;
    
    for (j = 0; j < COLS; ++j)
    {
        for (i = 0; i < ways; ++i)
        {
            count = 0;
            for (k = 0; k < CONNECT; ++k)
            {
                if (scores[i + k][j] == disc) count++;
            }
            if (count == CONNECT) return 1;
        }
    }
    
    /* Part 3 - check for 4 connected diagonal
       check for 4-disc diagonal
       
    
      A B C D E F G
    0| | | | | | | |
    1| |\|\|\|\|\| |
    2| |\|\|\|\|\| |
    3| |\|\|\|\|\| |
    4| |\|\|\|\|\| |
    5| | | | | | | |
    
    */
    
    int ii, jj;
    for (i = 1; i < ROWS-1; i++)
    {
        for (j = 1; j < COLS-1; j++)
        {
            
            /* left-tilted diagonals */
            count = 0;
            // left-upwards:
            for (ii = i, jj = j; (ii >= 0) || (jj >= 0); ii--, jj--)
            {
                if (scores[ii][jj] == disc)
                {
                    count++;
                    if (count == CONNECT) return 1;    
                }
                else
                    break;
            }
            // right-downwards:
            for (ii = i+1, jj = j+1; (ii <= ROWS-1) || (jj <= COLS-1); ii++, jj++)
            {
                if (scores[ii][jj] == disc)
                {
                    count++;
                    if (count == CONNECT) return 1;
                }
                else
                    break;
            }
            
            /* right-tilted diagonals */
            count = 0;
            // left-downwards:
            for (ii = i, jj = j; (ii <= ROWS-1) || (jj >= 0); ii++, jj--)
            {
                if (scores[ii][jj] == disc)
                {
                    count++;
                    if (count == CONNECT) return 1;    
                }
                else
                    break;
            }
            // right-upwards:
            for (ii = i-1, jj = j+1; (ii >= 0) || (jj <= COLS-1); ii--, j++)
            {
                if (scores[ii][jj] == disc)
                {
                    count++;
                    if (count == CONNECT) return 1;
                }
                else
                    break;
            }
            
        }
    }

    return 0;       
}
    
    

