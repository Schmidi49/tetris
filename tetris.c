#include <stdio.h>
#include <time.h>
#include <conio.h>

void drawboard(char field[19][10], int level, int linesleft, int linestotal, int nextblock);
void block_init(int block);

int main()
{
start:
    srand(time(NULL));
	char field[19][10];
	int loop, loop1, delayloop, lineclearloop, lineclearloop1, delay = 30000, linestemp, turnsuccessful = 0;
	int level=1, linesleft = 30, linestotal = 0;
	char a, b=178;
	int column1=3, row1=0, column2=3, row2=1, column3=3, row3=2, column4=3, row4=3;
    int key, block, nextblock, turnposition = 1;
	for (loop = 0; loop <= 18; loop++)
	{
		for (loop1 = 0; loop1 <= 9; loop1++)
		{
			field[loop][loop1] = 0;
		}
	}
	block = (rand() % 7) + 1;
	nextblock = (rand() % 7) + 1;
	if (block == 1)
    {
		row1 = 0;
		column1 = 3;
		row2 = 1;
		column2 = 3;
		row3 = 2;
		column3 = 3;
		row4 = 3;
		column4 = 3;
	}
	if (block == 2)
	{
		row1 = 0;
		column1 = 3;
		row2 = 0;
		column2 = 4;
		row3 = 1;
		column3 = 3;
		row4 = 1;
		column4 = 4;
	}
	if (block == 3)
    {
	    row1 = 0;
	    column1 = 4;
		row2 = 1;
		column2 = 4;
		row3 = 1;
		column3 = 3;
		row4 = 2;
		column4 = 3;
	}
	if (block == 4)
	{
	    row1 = 0;
	    column1 = 3;
		row2 = 1;
		column2 = 3;
		row3 = 1;
		column3 = 4;
		row4 = 2;
		column4 = 4;
	}
	if (block == 5)
	{
		row1 = 0;
		column1 = 3;
		row2 = 1;
		column2 = 3;
		row3 = 2;
		column3 = 3;
		row4 = 2;
		column4 = 4;
	}
	if (block == 6)
	{
	    row1 = 0;
		column1 = 4;
		row2 = 1;
		column2 = 4;						  
		row3 = 2;
		column3 = 4;
		row4 = 2;
		column4 = 3;
	}
	if (block == 7)
	{
	    row1 = 0;
		column1 = 4;
		row2 = 1;
		column2 = 3;
		row3 = 1;
		column3 = 4;
		row4 = 1;
		column4 = 5;
	}
	
	printf("+-----------------------------------------------------------------------+\n");
	printf("|                                                                       |\n");
	printf("|                                                                       |\n"); 
	printf("|                                                                       |\n"); 
	printf("|              %c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c  %c%c%c%c   %c%c%c  %c%c%c%c                    |\n", b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b); 
	printf("|                %c    %c        %c    %c   %c   %c   %c                       |\n", b, b, b, b, b, b, b);                       
	printf("|                %c    %c%c%c%c%c    %c    %c%c%c%c%c   %c   %c%c%c%c                    |\n", b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b); 
	printf("|                %c    %c        %c    %c  %c    %c      %c                    |\n", b, b, b, b, b, b, b); 
	printf("|                %c    %c%c%c%c%c    %c    %c   %c  %c%c%c  %c%c%c%c                    |\n", b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b); 
	printf("|                                                                       |\n"); 
	printf("|                                                                       |\n"); 
	printf("|       Please adjust the window to match the boundary on screen.       |\n"); 
	printf("|                                                                       |\n"); 
	printf("|                         -PRESS ENTER-                                 |\n"); 
	printf("|Controls:                                                              |\n"); 
	printf("|  Left Arrow - move left                                               |\n"); 
	printf("|  Right Arrow - move right                                             |\n"); 
	printf("|  F - rotate clockwise                                                 |\n");
    printf("|  D - rotate counterclockwise                                          |\n"); 
	printf("|                                             programmed by Michael Wong|\n"); 
    printf("+-----------------------------------------------------------------------+\n");
	getchar();
	printf("Enter your desired speed at level 1.  Enter around 30000 for very slow, enter around 5000 for fast:");
	scanf("%d", &delay);
	
	
	while (1)
	{
//-----------------------------------------------------------STARTBLOCK1
		if (block == 1)
		{                   
          field[row1][column1] = 178;
          field[row2][column2] = 178;
          field[row3][column3] = 178;
          field[row4][column4] = 178;
		  printf("%d", turnposition);
          drawboard(field, level, linesleft, linestotal, nextblock);
          field[row1][column1] = 0;
          field[row2][column2] = 0;
          field[row3][column3] = 0;
          field[row4][column4] = 0;
          
          if ((row2 <= 17) && (field[row4+1][column4]==0))
          {
                   row1++;
                   row2++;
                   row3++;
                   row4++;
          }         
          
          for (delayloop = 0; delayloop <= delay; delayloop++)
          {
                   if (kbhit())
                   {
                         key = getch();
                         if (key == 75)
                         {
                                 if (((turnposition == 1) && (column1 > 0) && (field[row1][column1-1]==0) && (field[row2][column2-1]==0) && (field[row3][column3-1]==0) && (field[row4][column4-1]==0)) || ((turnposition == 2) && (column1 > 0) && (field[row1][column1-1]==0)))
                                 {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1--;
                                         column2--;
                                         column3--;
                                         column4--;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                 }
                         }                     
                         if (key == 77)
                         {
                                if (((turnposition == 1) && (column4 < 9) && (field[row4][column4+1]==0) && (field[row3][column3+1]==0) && (field[row2][column2+1]==0) && (field[row1][column1+1]==0)) || ((turnposition == 2) && (column4 < 9) && (field[row4][column4+1]==0)))
                                {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1++;
                                         column2++;
                                         column3++;
                                         column4++;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                }
                          }
					      if (key == 102)
					      {
						        if ((turnposition == 1) &&(column1!=0)&& (column2 < 8) && (((field[row2][column2-1]==0) && (field[row2][column2+1]==0) && (field[row2][column2+2]==0))))
						        {							   
								         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         column1 = column2-1;
								         column3 = column2+1;
								         column4 = column2+2;
								         row1 = row2;
								         row3 = row2;
								         row4 = row2;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;
								         drawboard(field, level, linesleft, linestotal, nextblock);
						        }
						    	if ((turnposition == 2) && (field[row2-1][column2]==0) && (field[row2+1][column2]==0) && (field[row2+2][column2]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         column1 = column2;
								         column3 = column2;
								         column4 = column2;
								         row1 = row2-1;
								         row3 = row2+1;
								         row4 = row2+2;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
				  		        if ((turnposition == 1) && (turnsuccessful == 1))
						        {
                                         turnposition = 2;
                                }
                                else
                                {
										 turnposition = 1;
                                }
                                turnsuccessful = 0;
                          }
						  if (key == 100)
					      {
						        if ((turnposition == 1) && (column2 > 1)&& (column2 < 9) && (((field[row2][column1-2]==0) && (field[row2][column2-1]==0) && (field[row2][column4+1]==0))))
						        {							   
								         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         column1 = column1-2;
										 column2 = column2-1;
										 column4 = column4+1;
										 row1 = row2;
										 row3 = row2;
										 row4 = row2;
										 field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;
								         drawboard(field, level, linesleft, linestotal, nextblock);
						        }
						    	if ((turnposition == 2) && (field[row3-1][column3]==0) && (field[row3+1][column3]==0) && (field[row3+2][column3]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         column1 = column3;
										 column2 = column3;
										 column4 = column3;
										 row1 = row3-1;
										 row2 = row3+1;
										 row4 = row3+2;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
				  		        if ((turnposition == 1) && (turnsuccessful == 1))
						        {
                                         turnposition = 2;
                                }
                                else
                                {
										 turnposition = 1;
                                }
                                turnsuccessful = 0;
                          }
	               }
          }
          if (((turnposition == 1) && ((row4==18) || (field[row4+1][column1]!=0)) || ((turnposition == 2) && ( (row4==18) || (field[row1+1][column1]!=0) || (field[row2+1][column2]!=0) || (field[row3+1][column3]!=0) || (field[row4+1][column4]!=0)))))
          {
                   field[row1][column1] = 178;
                   field[row2][column2] = 178;
                   field[row3][column3] = 178;
                   field[row4][column4] = 178;
				   block = nextblock;
				   nextblock = (rand() % 7) + 1;
				   if (block == 1)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 3;
						  column4 = 3;
				   }
				   if (block == 2)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 0;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 1;
						  column4 = 4;
				   }
				   if (block == 3)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 4)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 5)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 6)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;						  
						  row3 = 2;
						  column3 = 4;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 7)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 1;
						  column4 = 5;
				   }
		           turnposition = 1;
                   drawboard(field, level, linesleft, linestotal, nextblock);
                   for (loop = 0; loop <= 18; loop++)
                   {
                          if ((field[loop][0] != 0) && (field[loop][1] != 0) && (field[loop][2] != 0) && (field[loop][3] != 0) && (field[loop][4] != 0) && (field[loop][5] != 0) && (field[loop][6] != 0) && (field[loop][7] != 0) && (field[loop][8] != 0) && (field[loop][9] != 0))
                          {
                                linesleft--;
                                linestotal++;
                                for (lineclearloop = (19-loop); lineclearloop <= 18; lineclearloop++)
                                {
                                         for (lineclearloop1 = 0; lineclearloop1 <= 9; lineclearloop1++)
                                         {
                                                 field[19-lineclearloop][lineclearloop1] = field[19-lineclearloop-1][lineclearloop1];
                                         }
                                }                                       
                          }
						  if (linesleft < 0)
						  {
                                linestemp = linesleft;
							    linesleft = 30 + linestemp;
							    level++;
							    delay = 3 * delay/4;
			              }                                           
                   }
                   if ((field[0][3] != 0) || (field[0][4] != 0))
                   {
                          field[6][3]='G';
                          field[6][4]='A';
                          field[6][5]='M';
                          field[6][6]='E';
                          field[7][3]='O';
                          field[7][4]='V';
                          field[7][5]='E';
                          field[7][6]='R';
                          drawboard(field, level, linesleft, linestotal, nextblock);
                       // ??? not sure what to do   cin.get();
						  printf("Play again?(Y/N)\n");
						  a = getchar();
						  getchar();
						  if (a == 'Y')
						  {
							  goto start;
						  }
						  if (a == 'N')
						  {
							  return 0;
						  }
                   }
          }
        }
		
          
//-----------------------------------------------------------STARTBLOCK2

		if (block == 2)
		{                   
          field[row1][column1] = 178;
          field[row2][column2] = 178;
          field[row3][column3] = 178;
          field[row4][column4] = 178;
          drawboard(field, level, linesleft, linestotal, nextblock);
          field[row1][column1] = 0;
          field[row2][column2] = 0;
          field[row3][column3] = 0;
          field[row4][column4] = 0;
          
          row1++;
          row2++;
          row3++;
          row4++;
          
          for (delayloop = 0; delayloop <= delay; delayloop++)
          {
			       if (kbhit())
                   {

                         key = getch();
                         if (key == 75)
                         {
                                 if (((turnposition == 1) && (column1 > 0) && (field[row1][column1-1]==0) && (field[row3][column3-1]==0)))
                                 {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1--;
                                         column2--;
                                         column3--;
                                         column4--;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                 }
                         }                     
                         if (key == 77)
                         {
                                if (((turnposition == 1) && (column4 < 9) && (field[row4][column4+1]==0) && (field[row2][column2+1]==0)))
                                {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1++;
                                         column2++;
                                         column3++;
                                         column4++;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                }
                          }
				   }
          }



          if ((row4 == 18) || (field[row3+1][column3]!=0) || (field[row4+1][column4]!=0))
          {
			       field[row1][column1] = 178;
                   field[row2][column2] = 178;
                   field[row3][column3] = 178;
                   field[row4][column4] = 178;
				   block = nextblock;
				   nextblock = (rand() % 7) + 1;
				   if (block == 1)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 3;
						  column4 = 3;
				   }
				   if (block == 2)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 0;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 1;
						  column4 = 4;
				   }
				   if (block == 3)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 4)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 5)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 6)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;						  
						  row3 = 2;
						  column3 = 4;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 7)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 1;
						  column4 = 5;
				   }
                   turnposition = 1;
                   drawboard(field, level, linesleft, linestotal, nextblock);
                   for (loop = 0; loop <= 18; loop++)
                   {
                          if ((field[loop][0] != 0) && (field[loop][1] != 0) && (field[loop][2] != 0) && (field[loop][3] != 0) && (field[loop][4] != 0) && (field[loop][5] != 0) && (field[loop][6] != 0) && (field[loop][7] != 0) && (field[loop][8] != 0) && (field[loop][9] != 0))
                          {
                                linesleft--;
                                linestotal++;
                                for (lineclearloop = (19-loop); lineclearloop <= 18; lineclearloop++)
                                {
                                         for (lineclearloop1 = 0; lineclearloop1 <= 9; lineclearloop1++)
                                         {
                                                 field[19-lineclearloop][lineclearloop1] = field[19-lineclearloop-1][lineclearloop1];
                                         }
                                }                                       
                          }
						  if (linesleft < 0)
						  {
                                linestemp = linesleft;
							    linesleft = 30 + linestemp;
							    level++;
							    delay = 3 * delay/4;
			              }                                           
                   }
                   if ((field[0][3] != 0) || (field[0][4] != 0))
                   {
                          field[6][3]='G';
                          field[6][4]='A';
                          field[6][5]='M';
                          field[6][6]='E';
                          field[7][3]='O';
                          field[7][4]='V';
                          field[7][5]='E';
                          field[7][6]='R';
                          drawboard(field, level, linesleft, linestotal, nextblock);
                       // ??? not sure what to do   cin.get();
						  printf("Play again?(Y/N)\n");
						  a = getchar();
						  getchar();
						  if (a == 'Y')
						  {
							  goto start;
						  }
						  if (a == 'N')
						  {
							  return 0;
						  }
                   }
          }
		}
		
//-----------------------------------------------------------STARTBLOCK3
		if (block == 3)
		{                   
          field[row1][column1] = 178;
          field[row2][column2] = 178;
          field[row3][column3] = 178;
          field[row4][column4] = 178;
          drawboard(field, level, linesleft, linestotal, nextblock);
          field[row1][column1] = 0;
          field[row2][column2] = 0;
          field[row3][column3] = 0;
          field[row4][column4] = 0;
          
          if ((row2 <= 17) && (field[row4+1][column4]==0))
          {
                   row1++;
                   row2++;
                   row3++;
                   row4++;
          }
          for (delayloop = 0; delayloop <= delay; delayloop++)
          {
                   if (kbhit())
                   {
                         key = getch();
                         if (key == 75)
                         {
                                 if (((turnposition == 1) && (column3 > 0) && (field[row1][column1-1]==0) && (field[row3][column3-1]==0) && (field[row4][column4-1]==0)) || ((turnposition == 2) && (column1 > 0) && (field[row1][column1-1]==0) && (field[row3][column3-1]==0)))
                                 {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1--;
                                         column2--;
                                         column3--;
                                         column4--;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                 }
                         }                     
                         if (key == 77)
                         {
                                if (((turnposition == 1) && (column1 < 9) && (field[row1][column1+1]==0) && (field[row2][column2+1]==0) && (field[row4][column4+1]==0)) || ((turnposition == 2) && (column4 < 9) && (field[row2][column2+1]==0) && (field[row4][column4+1]==0)))
                                {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1++;
                                         column2++;
                                         column3++;
                                         column4++;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                }
                          }
					      if ((key == 102) || (key == 100))
					      {
						        if ((turnposition==1) && (field[row1+1][column1-2]==0) && (column3 > 0) && (field[row4][column4+1]==0))
						        {							   
								         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1++;
								         row3++;
								         column1 = column1 - 2;
								         column2--;
								         column4++;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;
								         drawboard(field, level, linesleft, linestotal, nextblock);
						        }
						    	if ((turnposition == 2) && (field[row1-1][column1+2]==0) && (field[row4-1][column4]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1--;
								         row3--;
								         column1 = column1 + 2;
								         column2++;
								         column4--;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
				  		        if ((turnposition == 1) && (turnsuccessful == 1))
						        {
                                         turnposition = 2;
                                }
                                else
                                {
										 turnposition = 1;
                                }
                                turnsuccessful = 0;
                          }		  
	               }
          }
          if ((row4 == 18) || (((turnposition == 1) && ((field[row2+1][column2]!=0) || (field[row4+1][column4]!=0))) || ((turnposition==2) && ((field[row1+1][column1]!=0) || (field[row3+1][column3]!=0) || (field[row4+1][column4]!=0)))))
          {
  
			       field[row1][column1] = 178;
                   field[row2][column2] = 178;
                   field[row3][column3] = 178;
                   field[row4][column4] = 178;
				   block = nextblock;
				   nextblock = (rand() % 7) + 1;
				   if (block == 1)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 3;
						  column4 = 3;
				   }
				   if (block == 2)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 0;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 1;
						  column4 = 4;
				   }
				   if (block == 3)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 4)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 5)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 6)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;						  
						  row3 = 2;
						  column3 = 4;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 7)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 1;
						  column4 = 5;
				   }
		           turnposition = 1;
                   drawboard(field, level, linesleft, linestotal, nextblock);
                   for (loop = 0; loop <= 18; loop++)
                   {
                          if ((field[loop][0] != 0) && (field[loop][1] != 0) && (field[loop][2] != 0) && (field[loop][3] != 0) && (field[loop][4] != 0) && (field[loop][5] != 0) && (field[loop][6] != 0) && (field[loop][7] != 0) && (field[loop][8] != 0) && (field[loop][9] != 0))
                          {
                                linesleft--;
                                linestotal++;
                                for (lineclearloop = (19-loop); lineclearloop <= 18; lineclearloop++)
                                {
                                         for (lineclearloop1 = 0; lineclearloop1 <= 9; lineclearloop1++)
                                         {
                                                 field[19-lineclearloop][lineclearloop1] = field[19-lineclearloop-1][lineclearloop1];
                                         }
                                }                                       
                          }
						  if (linesleft < 0)
						  {
                                linestemp = linesleft;
							    linesleft = 30 + linestemp;
							    level++;
							    delay = 3 * delay/4;
			              }                                           
                   }
                   if ((field[0][3] != 0) || (field[0][4] != 0))
                   {
                          field[6][3]='G';
                          field[6][4]='A';
                          field[6][5]='M';
                          field[6][6]='E';
                          field[7][3]='O';
                          field[7][4]='V';
                          field[7][5]='E';
                          field[7][6]='R';
                          drawboard(field, level, linesleft, linestotal, nextblock);
                       // ??? not sure what to do   cin.get();
						  printf("Play again?(Y/N)\n");
						  a = getchar();
						  getchar();
						  if (a == 'Y')
						  {
							  goto start;
						  }
						  if (a == 'N')
						  {
							  return 0;
						  }
                   }
          }
		}
		
//-----------------------------------------------------------STARTBLOCK4
		if (block == 4)
		{                   
          field[row1][column1] = 178;
          field[row2][column2] = 178;
          field[row3][column3] = 178;
          field[row4][column4] = 178;
          drawboard(field, level, linesleft, linestotal, nextblock);
          field[row1][column1] = 0;
          field[row2][column2] = 0;
          field[row3][column3] = 0;
          field[row4][column4] = 0;
          
          if ((row2 <= 17) && (field[row4+1][column4]==0))
          {
                   row1++;
                   row2++;
                   row3++;
                   row4++;
          }
          for (delayloop = 0; delayloop <= delay; delayloop++)
          {
                   if (kbhit())
                   {
                         key = getch();
                         if (key == 75)
                         {
                                 if (((turnposition == 1) && (column1 > 0) && (field[row1][column1-1]==0) && (field[row2][column2-1]==0) && (field[row4][column4-1]==0)) || ((turnposition == 2) && (column4 > 0) && (field[row2][column2-1]==0) && (field[row4][column4-1]==0)))
                                 {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1--;
                                         column2--;
                                         column3--;
                                         column4--;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                 }
                         }                     
                         if (key == 77)
                         {
                                if (((turnposition == 1) && (column3 < 9) && (field[row1][column1+1]==0) && (field[row3][column3+1]==0) && (field[row4][column4+1]==0)) || ((turnposition == 2) && (column1 < 9) && (field[row1][column1+1]==0) && (field[row3][column3+1]==0)))
                                {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1++;
                                         column2++;
                                         column3++;
                                         column4++;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                }
                          }
					      if ((key == 100) || (key == 102))
					      {
						        if ((turnposition == 1) && (column2 > 0) && (field[row2+1][column2-1]==0) && (field[row3+1][column3-1]==0))
						        {							   
								         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1++;
								         row3++;
								         column1++;
								         column3--;
								         column4 = column4-2;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;
								         drawboard(field, level, linesleft, linestotal, nextblock);
						        }
						    	if ((turnposition == 2) && (field[row2-1][column2]==0) && (field[row1+1][column1]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1--;
								         row3--;
								         column1--;
								         column3++;
								         column4 = column4 + 2;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
				  		        if ((turnposition == 1) && (turnsuccessful == 1))
						        {
                                         turnposition = 2;
                                }
                                else
                                {
										 turnposition = 1;
                                }
                                turnsuccessful = 0;
                          }		  
	               }
          }
          if ((row4 == 18) || (((turnposition == 1) && ((field[row2+1][column2]!=0) || (field[row4+1][column4]!=0))) || ((turnposition==2) && ((field[row1+1][column1]!=0) || (field[row3+1][column3]!=0) || (field[row4+1][column4]!=0)))))
          {
  
			       field[row1][column1] = 178;
                   field[row2][column2] = 178;
                   field[row3][column3] = 178;
                   field[row4][column4] = 178;
				   block = nextblock;
				   nextblock = (rand() % 7) + 1;
				   if (block == 1)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 3;
						  column4 = 3;
				   }
				   if (block == 2)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 0;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 1;
						  column4 = 4;
				   }
				   if (block == 3)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 4)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 5)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 6)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;						  
						  row3 = 2;
						  column3 = 4;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 7)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 1;
						  column4 = 5;
				   }
		           turnposition = 1;
                   drawboard(field, level, linesleft, linestotal, nextblock);
                   for (loop = 0; loop <= 18; loop++)
                   {
                          if ((field[loop][0] != 0) && (field[loop][1] != 0) && (field[loop][2] != 0) && (field[loop][3] != 0) && (field[loop][4] != 0) && (field[loop][5] != 0) && (field[loop][6] != 0) && (field[loop][7] != 0) && (field[loop][8] != 0) && (field[loop][9] != 0))
                          {
                                linesleft--;
                                linestotal++;
                                for (lineclearloop = (19-loop); lineclearloop <= 18; lineclearloop++)
                                {
                                         for (lineclearloop1 = 0; lineclearloop1 <= 9; lineclearloop1++)
                                         {
                                                 field[19-lineclearloop][lineclearloop1] = field[19-lineclearloop-1][lineclearloop1];
                                         }
                                }                                       
                          }
						  if (linesleft < 0)
						  {
                                linestemp = linesleft;
							    linesleft = 30 + linestemp;
							    level++;
							    delay = 3 * delay/4;
			              }                                           
                   }
                   if ((field[0][3] != 0) || (field[0][4] != 0))
                   {
                          field[6][3]='G';
                          field[6][4]='A';
                          field[6][5]='M';
                          field[6][6]='E';
                          field[7][3]='O';
                          field[7][4]='V';
                          field[7][5]='E';
                          field[7][6]='R';
                          drawboard(field, level, linesleft, linestotal, nextblock);
                       // ??? not sure what to do   cin.get();
						  printf("Play again?(Y/N)\n");
						  a = getchar();
						  getchar();
						  if (a == 'Y')
						  {
							  goto start;
						  }
						  if (a == 'N')
						  {
							  return 0;
						  }
                   }
          }
		}
		
//-----------------------------------------------------------STARTBLOCK5
		if (block == 5)
		{                   
          field[row1][column1] = 178;
          field[row2][column2] = 178;
          field[row3][column3] = 178;
          field[row4][column4] = 178;
          drawboard(field, level, linesleft, linestotal, nextblock);
          field[row1][column1] = 0;
          field[row2][column2] = 0;
          field[row3][column3] = 0;
          field[row4][column4] = 0;
          
          if ((row2 <= 17) && (field[row4+1][column4]==0))
          {
                   row1++;
                   row2++;
                   row3++;
                   row4++;
          }
          for (delayloop = 0; delayloop <= delay; delayloop++)
          {
                   if (kbhit())
                   {
                         key = getch();
                         if (key == 75)
                         {
                                 if (((turnposition == 1) && (column1 > 0) && (field[row1][column1-1]==0) && (field[row2][column2-1]==0) && (field[row3][column3-1]==0)) || ((turnposition == 2) && (column1 > 0) && (field[row1][column1-1]==0) && (field[row4][column4-1]==0)) || ((turnposition == 3) && (column1 > 0) && (field[row1][column1-1]==0) && (field[row3][column3-1]==0) && (field[row4][column4-1]==0)) || ((turnposition == 4) && (column2 > 0) && (field[row1][column1-1]==0) && (field[row2][column2-1]==0)))
                                 {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1--;
                                         column2--;
                                         column3--;
                                         column4--;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                 }
                         }                     
                         if (key == 77)
                         {
                                if (((turnposition == 1) && (column4 < 9) && (field[row1][column1+1]==0) && (field[row2][column2+1]==0) && (field[row4][column4+1]==0)) || ((turnposition == 2) && (column3 < 9) && (field[row3][column3+1]==0) && (field[row4][column4+1]==0)) || ((turnposition == 3) && (column2 < 9) && (field[row2][column2+1]==0) && (field[row3][column3+1]==0) && (field[row4][column4+1]==0)) || ((turnposition == 4) && (column1 < 9) && (field[row1][column1+1]==0) && (field[row4][column4+1]==0)))
                                {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1++;
                                         column2++;
                                         column3++;
                                         column4++;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                }
                          }
					      if (key == 102)
					      {
						        if ((turnposition == 1) && (column1!=0) && (((field[row2][column2-1]==0) && (field[row2][column2+1]==0) && (field[row3][column3-1]==0))))
						        {							   
								         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1++;
								         row3--;
								         column1--;
								         column3++;
								         column4 = column4 - 2;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;
								         drawboard(field, level, linesleft, linestotal, nextblock);
						        }
						    	if ((turnposition == 2) && (field[row1-1][column1]==0) && (field[row2-1][column2]==0) && (field[row4][column4+1]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1--;
								         row2--;
								         column3--;
								         column4++;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
							    if ((turnposition == 3) && (column3 != 9) && (field[row1+1][column1]==0) && (field[row2][column2+1]==0) && (field[row3][column3+1]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row2++;
								         row4--;
								         column1 = column1 + 2;
								         column2--;
								         column4++;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
							    if ((turnposition == 4) && (field[row1][column1-1]==0) && (field[row3+1][column3]==0) && (field[row4+1][column4]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row3++;
								         row4++;
								         column1--;
								         column2++;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
				  		        if ((turnposition == 1) && (turnsuccessful == 1))
						        {
                                         turnposition = 2;
                                }
                                else
                                {
										 if ((turnposition == 2) && (turnsuccessful == 1))
										 {
                                                 turnposition = 3;
                                         }
                                         else
                                         {
                                                 if ((turnposition == 3)&& (turnsuccessful == 1))
                                                 {
                                                            turnposition = 4;
                                                 }
                                                 else
                                                 {
                                                            if ((turnposition == 4) && (turnsuccessful == 1))
                                                            {
                                                                         turnposition = 1;
                                                            }
                                                 }
                                         }                     
                                }
                                turnsuccessful = 0;
                          }
						  if (key == 100)
					      {
						        if ((turnposition == 1) && (column1 != 0) && (field[row1][column1+1]==0) && (field[row2][column2+1]==0) && (field[row2][column2-1]==0))
						        {							   
								         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row3--;
								         row4--;
								         column1++;
								         column2--;
										 field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;
								         drawboard(field, level, linesleft, linestotal, nextblock);
						        }
						    	if ((turnposition == 2) && (field[row2-1][column2]==0) && (field[row2+1][column2]==0) && (field[row3+1][column3]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1--;
								         row3++;
								         column1++;
								         column3--;
								         column4 = column4 + 2;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
							    if ((turnposition == 3) && (column3 != 9) && (field[row3][column3-1]==0) && (field[row4][column4-1]==0) && (field[row3][column3+1]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1++;
								         row2++;
								         column3++;
								         column4--;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
							    if ((turnposition == 4) && (field[row2-1][column2]==0) && (field[row3-1][column3]==0) && (field[row3+1][column3]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row2--;
								         row4++;
								         column1 = column1 - 2;
								         column2++;
								         column4--;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
				  		        if ((turnposition == 1) && (turnsuccessful == 1))
						        {
                                         turnposition = 4;
                                }
                                else
                                {
										 if ((turnposition == 4) && (turnsuccessful == 1))
										 {
                                                 turnposition = 3;
                                         }
                                         else
                                         {
                                                 if ((turnposition == 3)&& (turnsuccessful == 1))
                                                 {
                                                            turnposition = 2;
                                                 }
                                                 else
                                                 {
                                                            if ((turnposition == 2) && (turnsuccessful == 1))
                                                            {
                                                                         turnposition = 1;
                                                            }
                                                 }
                                         }                     
                                }
                                turnsuccessful = 0;
                          }
	               }
          }
          if ((row4 == 18) || (((turnposition == 1) && ((field[row3+1][column3]!=0) || (field[row4+1][column4]!=0))) || ((turnposition==2) && ((field[row2+1][column2]!=0) || (field[row3+1][column3]!=0) || (field[row4+1][column4]!=0))) || (((turnposition == 3) && ((field[row1+1][column1]!=0) || (field[row4+1][column4]!=0))) || (((turnposition == 4) && ((field[row2+1][column2]!=0) || (field[row3+1][column3]!=0) || (field[row4+1][column4]!=0)))))))
          {
  
			       field[row1][column1] = 178;
                   field[row2][column2] = 178;
                   field[row3][column3] = 178;
                   field[row4][column4] = 178;
				   block = nextblock;
				   nextblock = (rand() % 7)+1;
				   if (block == 1)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 3;
						  column4 = 3;
				   }
				   if (block == 2)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 0;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 1;
						  column4 = 4;
				   }
				   if (block == 3)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 4)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 5)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 6)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;						  
						  row3 = 2;
						  column3 = 4;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 7)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 1;
						  column4 = 5;
				   }
		           turnposition = 1;
                   drawboard(field, level, linesleft, linestotal, nextblock);
                   for (loop = 0; loop <= 18; loop++)
                   {
                          if ((field[loop][0] != 0) && (field[loop][1] != 0) && (field[loop][2] != 0) && (field[loop][3] != 0) && (field[loop][4] != 0) && (field[loop][5] != 0) && (field[loop][6] != 0) && (field[loop][7] != 0) && (field[loop][8] != 0) && (field[loop][9] != 0))
                          {
                                linesleft--;
                                linestotal++;
                                for (lineclearloop = (19-loop); lineclearloop <= 18; lineclearloop++)
                                {
                                         for (lineclearloop1 = 0; lineclearloop1 <= 9; lineclearloop1++)
                                         {
                                                 field[19-lineclearloop][lineclearloop1] = field[19-lineclearloop-1][lineclearloop1];
                                         }
                                }                                       
                          }
						  if (linesleft < 0)
						  {
                                linestemp = linesleft;
							    linesleft = 30 + linestemp;
							    level++;
							    delay = 3 * delay/4;
			              }                                           
                   }
                   if ((field[0][3] != 0) || (field[0][4] != 0))
                   {
                          field[6][3]='G';
                          field[6][4]='A';
                          field[6][5]='M';
                          field[6][6]='E';
                          field[7][3]='O';
                          field[7][4]='V';
                          field[7][5]='E';
                          field[7][6]='R';
                          drawboard(field, level, linesleft, linestotal, nextblock);
                       // ??? not sure what to do   cin.get();
						  printf("Play again?(Y/N)\n");
						  a = getchar();
						  getchar();
						  if (a == 'Y')
						  {
							  goto start;
						  }
						  if (a == 'N')
						  {
							  return 0;
						  }
                   }
          }
		}
		
//-----------------------------------------------------------STARTBLOCK6
		if (block == 6)
		{                   
          field[row1][column1] = 178;
          field[row2][column2] = 178;
          field[row3][column3] = 178;
          field[row4][column4] = 178;
	      drawboard(field, level, linesleft, linestotal, nextblock);
          field[row1][column1] = 0;
          field[row2][column2] = 0;
          field[row3][column3] = 0;
          field[row4][column4] = 0;
          
          if ((row2 <= 17) && (field[row4+1][column4]==0))
          {
                   row1++;
                   row2++;
                   row3++;
                   row4++;
          }
          for (delayloop = 0; delayloop <= delay; delayloop++)
          {
                   if (kbhit())
                   {
                         key = getch();
                         if (key == 75)
                         {
                                 if (((turnposition == 1) && (column4 > 0) && (field[row1][column1-1]==0) && (field[row2][column2-1]==0) && (field[row4][column4-1]==0)) || ((turnposition == 2) && (column1 > 0) && (field[row1][column1-1]==0) && (field[row2][column2-1]==0)) || ((turnposition == 3) && (column2 > 0) && (field[row2][column2-1]==0) && (field[row3][column3-1]==0) && (field[row4][column4-1]==0)) || ((turnposition == 4) && (column1 > 0) && (field[row1][column1-1]==0) && (field[row4][column4-1]==0)))
                                 {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1--;
                                         column2--;
                                         column3--;
                                         column4--;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                 }
                         }                     
                         if (key == 77)
                         {
                                if (((turnposition == 1) && (column1 < 9) && (field[row1][column1+1]==0) && (field[row2][column2+1]==0) && (field[row3][column3+1]==0)) || ((turnposition == 2) && (column4 < 9) && (field[row1][column1+1]==0) && (field[row4][column4+1]==0)) || ((turnposition == 3) && (column1 < 9) && (field[row1][column1+1]==0) && (field[row3][column3+1]==0) && (field[row4][column4+1]==0)) || ((turnposition == 4) && (column3 < 9) && (field[row3][column3+1]==0) && (field[row4][column4+1]==0)))
                                {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1++;
                                         column2++;
                                         column3++;
                                         column4++;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                }
                          }
					      if (key == 102)
					      {
						        if ((turnposition == 1) && (column1!=9) && (((field[row1][column1-1]==0) && (field[row2][column2-1]==0) && (field[row2][column2+1]==0))))
						        {							   
								         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row3--;
								         row4--;
								         column1--;
								         column2--;
								         column4 = column4 + 2;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;
								         drawboard(field, level, linesleft, linestotal, nextblock);
						        }
						    	if ((turnposition == 2) && (field[row3-1][column3]==0) && (field[row4-1][column4]==0) && (field[row3+1][column3]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row2--;
								         row4++;
								         column1 = column1 + 2;
								         column2++;
								         column4--;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
							    if ((turnposition == 3) && (column2 != 0) && (field[row3][column3-1]==0) && (field[row3][column3+1]==0) && (field[row4][column4+1]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1++;
								         row2++;
								         column1 = column1 - 2;
								         column3++;
								         column4++;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
							    if ((turnposition == 4) && (field[row1+1][column1]==0) && (field[row2+1][column3]==0) && (field[row2-1][column2]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1--;
								         row3++;
								         column1++;
								         column3--;
								         column4 = column4 - 2;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
				  		        if ((turnposition == 1) && (turnsuccessful == 1))
						        {
                                         turnposition = 2;
                                }
                                else
                                {
										 if ((turnposition == 2) && (turnsuccessful == 1))
										 {
                                                 turnposition = 3;
                                         }
                                         else
                                         {
                                                 if ((turnposition == 3) && (turnsuccessful == 1))
                                                 {
                                                            turnposition = 4;
                                                 }
                                                 else
                                                 {
                                                            if ((turnposition == 4) && (turnsuccessful == 1))
                                                            {
                                                                         turnposition = 1;
                                                            }
                                                 }
                                         }                     
                                }
                                turnsuccessful = 0;
                          }
						  if (key == 100)
					      {
						        if ((turnposition == 1) && (column1 != 9) && (field[row2][column2-1]==0) && (field[row2][column2+1]==0) && (field[row3][column3+1]==0))
						        {							   
								         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1++;
								         row3--;
								         column1--;
								         column3++;
								         column4 = column4 + 2;
										 field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;
								         drawboard(field, level, linesleft, linestotal, nextblock);
						        }
						    	if ((turnposition == 2) && (field[row3-1][column3]==0) && (field[row3+1][column3]==0) && (field[row2+1][column2]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row3++;
								         row4++;
								         column1++;
								         column2++;
								         column4 = column4 - 2;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
							    if ((turnposition == 3) && (column2 != 0) && (field[row2][column2-1]==0) && (field[row3][column3-1]==0) && (field[row3][column3+1]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row2++;
								         row4--;
								         column1 = column1 - 2;
								         column2--;
								         column4++;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
							    if ((turnposition == 4) && (field[row2-1][column2]==0) && (field[row2+1][column2]==0) && (field[row3-1][column3]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1--;
								         row2--;
								         column1 = column1 + 2;
								         column3--;
								         column4--;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
				  		        if ((turnposition == 1) && (turnsuccessful == 1))
						        {
                                         turnposition = 4;
                                }
                                else
                                {
										 if ((turnposition == 4) && (turnsuccessful == 1))
										 {
                                                 turnposition = 3;
                                         }
                                         else
                                         {
                                                 if ((turnposition == 3)&& (turnsuccessful == 1))
                                                 {
                                                            turnposition = 2;
                                                 }
                                                 else
                                                 {
                                                            if ((turnposition == 2) && (turnsuccessful == 1))
                                                            {
                                                                         turnposition = 1;
                                                            }
                                                 }
                                         }                     
                                }
                                turnsuccessful = 0;
                          }
	               }
          }
          if ((row4 == 18) || (((turnposition == 1) && ((field[row3+1][column3]!=0) || (field[row4+1][column4]!=0))) || ((turnposition==2) && ((field[row2+1][column2]!=0) || (field[row3+1][column3]!=0) || (field[row4+1][column4]!=0))) || (((turnposition == 3) && ((field[row1+1][column1]!=0) || (field[row4+1][column4]!=0))) || (((turnposition == 4) && ((field[row2+1][column2]!=0) || (field[row1+1][column1]!=0) || (field[row4+1][column4]!=0)))))))
          {
  
			       field[row1][column1] = 178;
                   field[row2][column2] = 178;
                   field[row3][column3] = 178;
                   field[row4][column4] = 178;
				   block = nextblock;
				   nextblock = (rand() % 7) + 1;
				   if (block == 1)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 3;
						  column4 = 3;
				   }
				   if (block == 2)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 0;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 1;
						  column4 = 4;
				   }
				   if (block == 3)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 4)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 5)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 6)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;						  
						  row3 = 2;
						  column3 = 4;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 7)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 1;
						  column4 = 5;
				   }
		           turnposition = 1;
                   drawboard(field, level, linesleft, linestotal, nextblock);
                   for (loop = 0; loop <= 18; loop++)
                   {
                          if ((field[loop][0] != 0) && (field[loop][1] != 0) && (field[loop][2] != 0) && (field[loop][3] != 0) && (field[loop][4] != 0) && (field[loop][5] != 0) && (field[loop][6] != 0) && (field[loop][7] != 0) && (field[loop][8] != 0) && (field[loop][9] != 0))
                          {
                                linesleft--;
                                linestotal++;
                                for (lineclearloop = (19-loop); lineclearloop <= 18; lineclearloop++)
                                {
                                         for (lineclearloop1 = 0; lineclearloop1 <= 9; lineclearloop1++)
                                         {
                                                 field[19-lineclearloop][lineclearloop1] = field[19-lineclearloop-1][lineclearloop1];
                                         }
                                }                                       
                          }
						  if (linesleft < 0)
						  {
                                linestemp = linesleft;
							    linesleft = 30 + linestemp;
							    level++;
							    delay = 3 * delay/4;
			              }                                           
                   }
                   if ((field[0][3] != 0) || (field[0][4] != 0))
                   {
                          field[6][3]='G';
                          field[6][4]='A';
                          field[6][5]='M';
                          field[6][6]='E';
                          field[7][3]='O';
                          field[7][4]='V';
                          field[7][5]='E';
                          field[7][6]='R';
                          drawboard(field, level, linesleft, linestotal, nextblock);
                       // ??? not sure what to do   cin.get();
						  printf("Play again?(Y/N)\n");
						  a = getchar();
						  getchar();
						  if (a == 'Y')
						  {
							  goto start;
						  }
						  if (a == 'N')
						  {
							  return 0;
						  }
                   }
          }
		}
		
//-----------------------------------------------------------STARTBLOCK7
		if (block == 7)
		{                   
          field[row1][column1] = 178;
          field[row2][column2] = 178;
          field[row3][column3] = 178;
          field[row4][column4] = 178;
	      drawboard(field, level, linesleft, linestotal, nextblock);
          field[row1][column1] = 0;
          field[row2][column2] = 0;
          field[row3][column3] = 0;
          field[row4][column4] = 0;
          
          if ((row2 <= 17) && (field[row4+1][column4]==0))
          {
                   row1++;
                   row2++;
                   row3++;
                   row4++;
          }
          for (delayloop = 0; delayloop <= delay; delayloop++)
          {
                   if (kbhit())
                   {
                         key = getch();
                         if (key == 75)
                         {
                                 if (((turnposition == 1) && (column2 > 0) && (field[row1][column1-1]==0) && (field[row2][column2-1]==0)) || ((turnposition == 2) && (column1 > 0) && (field[row1][column1-1]==0) && (field[row2][column2-1]==0) && (field[row4][column4-1]==0)) || ((turnposition == 3) && (column1 > 0) && (field[row1][column1-1]==0) && (field[row4][column4-1]==0)) || ((turnposition == 4) && (column2 > 0) && (field[row1][column1-1]==0) && (field[row2][column2-1]==0) && (field[row4][column4-1]==0)))
                                 {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1--;
                                         column2--;
                                         column3--;
                                         column4--;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                 }
                         }                     
                         if (key == 77)
                         {
                                if (((turnposition == 1) && (column4 < 9) && (field[row1][column1+1]==0) && (field[row4][column4+1]==0)) || ((turnposition == 2) && (column3 < 9) && (field[row1][column1+1]==0) && (field[row3][column3+1]==0) && (field[row4][column4+1]==0)) || ((turnposition == 3) && (column3 < 9) && (field[row3][column3+1]==0) && (field[row4][column4+1]==0)) || ((turnposition == 4) && (column3 < 9) && (field[row1][column1+1]==0) && (field[row3][column3+1]==0) && (field[row4][column4+1]==0)))
                                {
                                         field[row1][column1] = 0;
                                         field[row2][column2] = 0;
                                         field[row3][column3] = 0;
                                         field[row4][column4] = 0;
                                         column1++;
                                         column2++;
                                         column3++;
                                         column4++;
                                         field[row1][column1] = 178;
                                         field[row2][column2] = 178;
                                         field[row3][column3] = 178;
                                         field[row4][column4] = 178;
							             drawboard(field, level, linesleft, linestotal, nextblock);
                                }
                          }
					      if (key == 102)
					      {
						        if ((turnposition == 1) && (field[row3+1][column3]==0))
						        {							   
								         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row4++;
								         column2++;
								         column3++;
								         column4--;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;
								         drawboard(field, level, linesleft, linestotal, nextblock);
						        }
						    	if ((turnposition == 2) && (column2 != 0) && (field[row2][column2-1]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1++;
								         column1--;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
							    if ((turnposition == 3) && (field[row2-1][column2]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1--;
								         column1++;
								         column2--;
								         column3--;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
							    if ((turnposition == 4) && (column3 < 9) && (field[row3][column3+1]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row4--;
								         column4++;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
				  		        if ((turnposition == 1) && (turnsuccessful == 1))
						        {
                                         turnposition = 2;
                                }
                                else
                                {
										 if ((turnposition == 2) && (turnsuccessful == 1))
										 {
                                                 turnposition = 3;
                                         }
                                         else
                                         {
                                                 if ((turnposition == 3)&& (turnsuccessful == 1))
                                                 {
                                                            turnposition = 4;
                                                 }
                                                 else
                                                 {
                                                            if ((turnposition == 4) && (turnsuccessful == 1))
                                                            {
                                                                         turnposition = 1;
                                                            }
                                                 }
                                         }                     
                                }
                                turnsuccessful = 0;
                          }
						  if (key == 100)
					      {
						        if ((turnposition == 1) && (field[row3+1][column3]==0))
						        {							   
								         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row4++;
								         column4--;
										 field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;
								         drawboard(field, level, linesleft, linestotal, nextblock);
						        }
						    	if ((turnposition == 2) && (column2 > 0) && (field[row3][column3+1]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row4--;
								         column2--;
								         column3--;
								         column4++;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
							    if ((turnposition == 3) && (field[row2-1][column2]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1--;
								         column1++;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
							    if ((turnposition == 4) && (column3 < 9) && (field[row2][column2-1]==0))
						        {
                                         field[row1][column1] = 0;
								         field[row2][column2] = 0;
								         field[row3][column3] = 0;
								         field[row4][column4] = 0;
								         row1++;
								         column1--;
								         column2++;
								         column3++;
								         field[row1][column1] = 178;
								         field[row2][column2] = 178;
								         field[row3][column3] = 178;
								         field[row4][column4] = 178;
								         turnsuccessful = 1;	
								         drawboard(field, level, linesleft, linestotal, nextblock);
							    }
				  		        if ((turnposition == 1) && (turnsuccessful == 1))
						        {
                                         turnposition = 4;
                                }
                                else
                                {
										 if ((turnposition == 4) && (turnsuccessful == 1))
										 {
                                                 turnposition = 3;
                                         }
                                         else
                                         {
                                                 if ((turnposition == 3)&& (turnsuccessful == 1))
                                                 {
                                                            turnposition = 2;
                                                 }
                                                 else
                                                 {
                                                            if ((turnposition == 2) && (turnsuccessful == 1))
                                                            {
                                                                         turnposition = 1;
                                                            }
                                                 }
                                         }                     
                                }
                                turnsuccessful = 0;
                          }
	               }
          }
          if ((row4 == 18) || (((turnposition == 1) && ((field[row2+1][column2]!=0) || (field[row3+1][column3]!=0) || (field[row4+1][column4]!=0))) || ((turnposition==2) && ((field[row3+1][column3]!=0) || (field[row4+1][column4]!=0))) || (((turnposition == 3) && ((field[row1+1][column1]!=0) || (field[row3+1][column3]!=0) || (field[row4+1][column4]!=0))) || (((turnposition == 4) && ((field[row2+1][column2]!=0) || (field[row4+1][column4]!=0)))))))
          {
  
			       field[row1][column1] = 178;
                   field[row2][column2] = 178;
                   field[row3][column3] = 178;
                   field[row4][column4] = 178;
				   block = nextblock;
				   nextblock = (rand() % 7) + 1;
				   if (block == 1)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 3;
						  column4 = 3;
				   }
				   if (block == 2)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 0;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 1;
						  column4 = 4;
				   }
				   if (block == 3)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;
						  row3 = 1;
						  column3 = 3;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 4)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 5)
				   {
					      row1 = 0;
						  column1 = 3;
						  row2 = 1;
						  column2 = 3;
						  row3 = 2;
						  column3 = 3;
						  row4 = 2;
						  column4 = 4;
				   }
				   if (block == 6)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 4;						  
						  row3 = 2;
						  column3 = 4;
						  row4 = 2;
						  column4 = 3;
				   }
				   if (block == 7)
				   {
					      row1 = 0;
						  column1 = 4;
						  row2 = 1;
						  column2 = 3;
						  row3 = 1;
						  column3 = 4;
						  row4 = 1;
						  column4 = 5;
				   }
		           turnposition = 1;
                   drawboard(field, level, linesleft, linestotal, nextblock);
                   for (loop = 0; loop <= 18; loop++)
                   {
                          if ((field[loop][0] != 0) && (field[loop][1] != 0) && (field[loop][2] != 0) && (field[loop][3] != 0) && (field[loop][4] != 0) && (field[loop][5] != 0) && (field[loop][6] != 0) && (field[loop][7] != 0) && (field[loop][8] != 0) && (field[loop][9] != 0))
                          {
                                linesleft--;
                                linestotal++;
                                for (lineclearloop = (19-loop); lineclearloop <= 18; lineclearloop++)
                                {
                                         for (lineclearloop1 = 0; lineclearloop1 <= 9; lineclearloop1++)
                                         {
                                                 field[19-lineclearloop][lineclearloop1] = field[19-lineclearloop-1][lineclearloop1];
                                         }
                                }                                       
                          }
						  if (linesleft < 0)
						  {
                                linestemp = linesleft;
							    linesleft = 30 + linestemp;
							    level++;
							    delay = 3 * delay/4;
			              }                                           
                   }
                   if ((field[0][3] != 0) || (field[0][4] != 0))
                   {
                          field[6][3]='G';
                          field[6][4]='A';
                          field[6][5]='M';
                          field[6][6]='E';
                          field[7][3]='O';
                          field[7][4]='V';
                          field[7][5]='E';
                          field[7][6]='R';
                          drawboard(field, level, linesleft, linestotal, nextblock);
                       // ??? not sure what to do   cin.get();
						  printf("Play again?(Y/N)\n");
						  a = getchar();
						  getchar();
						  if (a == 'Y')
						  {
							  goto start;
						  }
						  if (a == 'N')
						  {
							  return 0;
						  }
                   }
          }
		}
    }      
    
	getchar(); // ??? not sure what to do   cin.get();
	return 0;
}


void drawboard(char field[19][10], int level, int linesleft, int linestotal, int nextblock)
{
	char b = 178;
    int loop, loop1;
    printf("\n");	
	printf("+----------+\n");
	for (loop = 0; loop <= 18; loop++)
	{
        printf("|");
        for (loop1 = 0; loop1 <= 9; loop1++)
        {
            printf("%c", field[loop][loop1]);
        }
        printf("|");
        if (loop == 1)
        {
            printf("      LEVEL:");
        }
        if (loop == 2)
        {
            printf("          %d", level);
        }
        if (loop == 4)
        {
            printf("      LINES LEFT UNTIL NEXT LEVEL:");
        }
        if (loop == 5)
        {
            printf("          %d", linesleft);
        }
        if (loop == 7)
        {
            printf("      TOTAL LINES:");
        }
        if (loop == 8)
        {
            printf("          %d", linestotal);
        }              
		if (loop == 10)
		{
			printf("      NEXT: Nr %d", nextblock);
		}
		if (loop == 12)
		{
			printf("         ");
			if (nextblock == 1)
			{
				printf("%c", b);
			}
			if (nextblock == 2)
			{
				printf("%c%c", b, b);
			}
			if (nextblock == 3)
			{
				printf(" %c", b);
			}
			if (nextblock == 4)
			{
				printf("%c", b);
			}
			if (nextblock == 5)
			{
				printf("%c", b);
			}
			if (nextblock == 6)
			{
				printf(" %c", b);
			}
			if (nextblock == 7)
			{
				printf(" %c", b);
			}
		}
		if (loop == 13)
		{
			printf("         ");
			if (nextblock == 1)
			{
				printf("%c", b);
			}
			if (nextblock == 2)
			{
				printf("%c%c", b, b);
			}
			if (nextblock == 3)
			{
				printf("%c%c", b, b);
			}
			if (nextblock == 4)
			{
				printf("%c%c", b, b);
			}
			if (nextblock == 5)
			{
				printf("%c", b);
			}
			if (nextblock == 6)
			{
				printf(" %c", b);
			}
			if (nextblock == 7)
			{
				printf("%c%c%c", b, b, b);
			}
		}
		if (loop == 14)
		{
			printf("         ");
			if (nextblock == 1)
			{
				printf("%c", b);
			}
			if (nextblock == 3)
			{
				printf("%c", b);
			}
			if (nextblock == 4)
			{
				printf(" %c", b);
			}
			if (nextblock == 5)
			{
				printf("%c%c", b, b);
			}
			if (nextblock == 6)
			{
				printf("%c%c", b, b);
			}
		}
		if (loop == 15)
		{
			printf("         ");
			if (nextblock == 1)
			{
				printf("%c", b);
			}
		}
        printf("\n");
     }
     printf("+----------+");

}