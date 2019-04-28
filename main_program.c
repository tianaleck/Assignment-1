#include <stdio.h> 

char rotationOne(char c, int keyOne); //function for task 1- rotation encryption using key
char rotationTwo(char f, int keyTwo); //function for tast 2- rotation decryption using key
char subcipherEnc(char i, char j); //function for task 3- substitution encryption using key
char subcipherDec(char j, char l); //funcion for task 4- substitution decryption using key

int main () { 
    
    int selec = 4; //the first chosen option - hard coded to select 1 for now
   
    printf ("Select an Option:\n"); //user interface to select what task should be performed 
    printf ("1) Encryption using rotation cipher given rotation amount\n");
    printf ("2) Decryption using rotation cipher given rotation amount\n");
    printf ("3) Encryption using substitution cipher given alphabet substitution\n");
    printf ("4) Decryption using substitution cipher given alphabet substitution\n");
    //printf ("5) Decryption using rotation cipher without rotation amount\n");
    //printf ("6) Decryption using substitution cipher without alphabet substitution\n");
    printf ("Selection: ");

  //  scanf ("%d", &selec); 
  
    
  

    switch (selec) 
    {
        case 1: //rotation encryption using a key
            
            printf ("\nSelected 1- Rotation encryption with key.\n");
            printf ("Enter rotation key: ");
            int keyOne=0; //rotation key initialisation
            scanf ("%d", &keyOne); 

            FILE *input1; //linking (?) to the file 
            input1 = fopen("task1", "r");
            if(input1 == NULL) //if the file cannot be opened
            {
                printf("FAILED TO OPEN FILE\n");
                return -1;
            }
            char c, d, e;
        
            while (1) { //while the file isnt at the end 
                
                fscanf(input1, "%c", &c); //reading the character from the file
                
                if(feof(input1)==1) //when the file is finished, exit the loop 
                {
                    break;
                }
                else if (c<65)  //if the char is not a letter (below ASCII 65)
                {
                    printf ("%c", c);
                }
                else if (c>90) //if the char is not a letter (above ASCII 90)
                {
                    printf ("%c", c);
                }
                
                else if ((c+keyOne)<65) //if the char is not a letter (below ASCII 65)
                {
                    d = (c + keyOne) + 26;
                    printf ("%c", d);
                }
                else if ((c+keyOne)>90) //if the letter is encrypted to punctuation (outside letter range)
                {
                    d = (c + keyOne) - 26;
                    printf ("%c", d);
                } 
                else //only translating capital letters
                {
                   e = rotationOne(c, keyOne);
                   printf ("%c", e);

                }
            }
            printf ("\n");
            break; 
            
        case 2: 
            printf ("\nSelected 2- Rotation decryption with key. \n");
            printf ("Enter rotation key: ");
            int keyTwo=0;
            scanf ("%d", &keyTwo); //reading key value from terminal
        
            FILE *input2; //opening file
            input2 = fopen("task2", "r"); //reading file
            
            if (input2 == NULL) //if the file cannot be opened due to error
            {
                printf ("FAILED TO OPEN FILE\n");
                return -1;
            }
            
            char f, g, h;
            
            while (1) 
            {
                fscanf(input2, "%c", &f); //reading the characters from file
                
                if (feof(input2)==1) //if the file is finished
                {
                    break;
                }
                else if (f<65) //if the char is not a letter 
                {
                    printf ("%c", f); //something wrong with this one
                }
                else if (f>90) //if the char is not a letter
                {
                    printf ("%c", f);
                }
                else if ((f-keyTwo)<65) //if decrypted char is not a letter within range
                {
                    g = (f - keyTwo) + 26;
                    printf ("%c", g);
                }
                else if ((f-keyTwo)>90) //if decrypted char is not a letter within range
                {
                    g = (f - keyTwo) - 26;
                    printf ("%c", g);
                }
                else 
                {
                    h = rotationTwo(f, keyTwo); //using function to decrypt
                    printf ("%c", h);
                } 
            }
            printf ("\n");
            break; 
            
        case 3: 
            printf ("\nSelected 3- Substitution encryption given a key\n");
            
            FILE *input3;
            input3 = fopen("task3", "r");
            if (input3 == NULL)
            {
                printf("FAILED TO OPEN FILE\n");
                return -1;
            }
            
            char i, j;
            
            while (1) 
            {
                fscanf (input3, "%c", &i);
                
                if (feof(input3)==1) 
                {
                    break;
                }
                else if (i<65)
                {
                    printf ( "%c", i);
                }
                else if (i>90)
                {
                    printf ("%c", i);
                }
                else
                {
                    j = subcipherEnc(i,j);
                    printf ("%c", j);
                }
            }
            printf ("\n");
            break; 
            
        case 4: 
            printf ("\nSelected 4- Substitution decryption with key\n");
            
            FILE *input4;
            input4 = fopen("task4", "r");
            if (input4 == NULL)
            {
                printf ("FAILED TO OPEN FILE\n");
                return -1;
            }
            
            char k, l;
            
            while (1) 
            {
                fscanf (input4, "%c", &k);
                
                if (feof(input4)==1) 
                {
                    break;
                }
                else if (k<65)
                {
                    printf ( "%c", k);
                }
                else if (k>90)
                {
                    printf ("%c", k);
                }
                else
                {
                    l = subcipherDec(k,l);
                    printf ("%c", l);
                } 
            printf ("\n");
            break; 
            
        default: 
            printf ("\nunknown option");
            }
    } //closing switch case
            } //closing int main

    char rotationOne(char c, int keyOne)   
    {
        c = c + keyOne;
        return c;
    } 
    
    char rotationTwo(char f, int keyTwo)
    {
        f = f - keyTwo;
        return f;
    }
    
    char subcipherEnc(char i, char j)
    {
         switch (i)
        {
            case 'A':
                i = 'Q';
                break;
            case 'B':
                i = 'W';
                break;
            case 'C':
                i = 'E';
                break;
            case 'D':
                i = 'R';
                break;
            case 'E':
                i = 'T';
                break;
            case 'F':
                i = 'Y';
                break;
            case 'G':
                i = 'U';
                break;
            case 'H':
                i = 'I';
                break;
            case 'I':
                i = 'O';
                break;
            case 'J':
                i = 'P';
                break;
            case 'K':
                i = 'A';
                break;
            case 'L':
                i = 'S';
                break;
            case 'M':
                i = 'D';
                break;
            case 'N':
                i = 'F';
                break;
            case 'O':
                i = 'G';
                break;
            case 'P':
                i = 'H';
                break;
            case 'Q':
                i = 'J';
                break;
            case 'R':
                i = 'K';
                break;
            case 'S':
                i = 'L';
                break;
            case 'T':
                i = 'Z';
                break;
            case 'U':
                i = 'X';
                break;
            case 'V':
                i = 'C';
                break;
            case 'W':
                i = 'V';
                break;
            case 'X':
                i = 'B';
                break;
            case 'Y':
                i = 'N';
                break;
            case 'Z':
                i = 'M';
                break;
            return i;
        }

                return i;
        }
        
        
        char subcipherDec(char k, char l)
    {
         switch (k)
        {
            case 'A':
                k = 'Q';
                break;
            case 'B':
                k = 'W';
                break;
            case 'C':
                k = 'E';
                break;
            case 'D':
                k = 'R';
                break;
            case 'E':
                k = 'T';
                break;
            case 'F':
                k = 'Y';
                break;
            case 'G':
                k = 'U';
                break;
            case 'H':
                k = 'I';
                break;
            case 'I':
                k = 'O';
                break;
            case 'J':
                k = 'P';
                break;
            case 'K':
                k = 'A';
                break;
            case 'L':
                k = 'S';
                break;
            case 'M':
                k = 'D';
                break;
            case 'N':
                k = 'F';
                break;
            case 'O':
                k = 'G';
                break;
            case 'P':
                k = 'H';
                break;
            case 'Q':
                k = 'J';
                break;
            case 'R':
                k = 'K';
                break;
            case 'S':
                k = 'L';
                break;
            case 'T':
                k = 'Z';
                break;
            case 'U':
                k = 'X';
                break;
            case 'V':
                k = 'C';
                break;
            case 'W':
                k = 'V';
                break;
            case 'X':
                k = 'B';
                break;
            case 'Y':
                k = 'N';
                break;
            case 'Z':
                k = 'M';
                break;
            return k;
        }

                return k;
        } 