#include <stdio.h> 

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
    
    scanf ("%d", &selec); 
    
    switch (selec) {
        case 1: 
            printf ("selected 1");
            
           // printf ("enter text");
       //     printf ("plain text: hello")
            
       //     char plainTextOne[]= "hello" 
          //  int keyOne
            
//            printf ("cipher text: %s" s)
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
