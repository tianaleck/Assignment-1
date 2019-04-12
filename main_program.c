#include <stdio.h> 

char rotationOne(char c, int keyOne); //function for task 1- rotation encryption using key

int main () {
    
    int selec = 1; //the first chosen option - hard coded to select 1 for now
   
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

            FILE *input; //linking (?) to the file 
            input = fopen("practice", "r");
            if(input == NULL) //if the file cannot be opened
            {
                printf("FAILED TO OPEN FILE\n");
                return -1;
            }
            char c, d, e;
        
            while (1) { //while the file isnt at the end 
                
                fscanf(input, "%c", &c); //reading the character from the file
                
                if(feof(input)== 1) //when the file is finished, exit the loop 
                {
                    break;
                }
                else if (c==' ')  //if the letter is a space, print as is
                {
                    printf ("%c", c);
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
            printf ("selected 2");
            break; 
        case 3: 
            printf ("selected 3");
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
    
   char rotationOne(char c, int keyOne)  //function not working- isnt translating 
    {
        c = c + keyOne;
        return c;
    } 
