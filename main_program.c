#include <stdio.h> 

char rotationOne(char c, int keyOne); //function for task 1- rotation encryption using key
char rotationTwo(char f, int keyTwo); //function for tast 2- rotation decryption using key

int main () {
    
    int selec = 3; //the first chosen option - hard coded to select 1 for now
   
    printf ("Select an Option:\n"); //user interface to select what task should be performed 
    printf ("1) Encryption using rotation cipher given rotation amount\n");
    printf ("2) Decryption using rotation cipher given rotation amount\n");
    printf ("3) Encryption using substitution cipher given alphabet substitution\n");
    printf ("4) Decryption using substitution cipher given alphabet substitution\n");
    printf ("5) Decryption using rotation cipher without rotation amount\n");
    printf ("6) Decryption using substitution cipher without alphabet substitution\n");
    printf ("Selection: ");

  //  scanf ("%d", &selec); 
  
    
  

    switch (selec) {
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
                
                if(feof(input1)== 1) //when the file is finished, exit the loop 
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
                
                else if ((c+keyOne)<65)
                {
                    d = (c + keyOne) + 26;
                    printf ("%c", d);
                }
                else if ((c+keyOne)>90) //if the letter is encrypted to punctuation
                {
                    d = (c + keyOne) - 26;
                    printf ("%c", d);
                } 
                else 
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
            
            FILE *input4;
            input4 = fopen("task3key", "r");
            
            if (input4 == NULL)
            {
                printf("FAILED TO OPEN KEY FILE\n");
                return -1;
            }
            
            char i, j, k;
            
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
                    printf ("%c", i);
                    //create a function which reads new file
                }
            }
            break; 
            
        case 4: 
            printf ("seleced 4");
            break; 
            
        case 5:
            printf ("selected 5");
            break; 
            
        case 6:
            printf ("selected 6");
            break;
            
        default: 
            printf ("\nunknown option");
    }
    
    }
    
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
 