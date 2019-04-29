/* THIS PROGRAM IS DESIGNED TO ENCRYPT AND DECRYPT MESSAGES USING BOTH THE ROTATION (CEASER) 
AND SUBSTITUTION CIPHER. USING THIS PROGRAM, YOU CAN CONVERT PLAIN TEXT TO A CIPHER MESSAGE USING A 
ROTATION KEY AND A SUBSTITUTION KEY, AND YOU CAN CONVERT A CIPHER TEXT BACK TO PLAIN TEXT USING THE SAME
KEYS. TO USE THIS PROGRAM, FIRST TYPE ./a.out INTO THE TERMINAL AND PRESS ENTER. THE TASK MENU WILL COME 
UP FOR YOU TO CHOOSE WHAT TASK YOU WISH TO PERFORM. ENTER THE NUMBER OF THE TASK YOU WISH TO PERFORM
AND PRESS ENTER. FOR TASKS 1 AND 2, YOU CAN THEN ENTER THE ROTATION KEY AND PRESS ENTER, AND YOUR 
ADJUSTED TEXT WILL BE PRINTED TO THE TERMINAL. FOR TASKS 3 AND 4, YOU WILL NEED TO HARD CODE YOUR KEY 
INTO THE FUNCTION AT THE BOTTOM OF THE CODE AND THEN COMPILE, AND THEN START THE PROGRAM.  
THIS PROGRAM ONLY TRANSLATES CAPITAL LETTERS, AND LEAVES PUNCTUATION, NUMBERS AND LOWERCASE LETTERS AS IS.*/

/* FLOW CONTROL- THIS CODE USES A SWITCH CASE TO SELECT THE TASK TO BE PERFORMED. THE USER INPUT 
WHICH CASE WILL BE USED. EACH SWITCH CASE USES AN IF/ELSE STATEMENT TO DETERMINE WHAT CHARACTER IS BEING
READ FROM A FILE AND WHAT NEEDS TO BE DONE TO IT IN ORDER TO TRANSLATE IT. IT DOES THIS BY DETERMINING
WHAT THE ASCII NUMBER FOR THE CHARACTER IS AND BASED ON THE VALUE, ONE OF THE IF/ELSE STATEMENTS WILL BE
USED. */

#include <stdio.h> 

char rotationOne(char c, int keyOne); //function for task 1- rotation encryption using key
char rotationTwo(char f, int keyTwo); //function for tast 2- rotation decryption using key
char subcipherEnc(char i, char j); //function for task 3- substitution encryption using key
char subcipherDec(char j, char l); //funcion for task 4- substitution decryption using key

int main () { 
    
    int selec; //declaring the variable which determines task selected 
   
    printf ("Select an Option:\n"); //user interface to select what task should be performed 
    printf ("1) Encryption using rotation cipher given rotation amount\n");
    printf ("2) Decryption using rotation cipher given rotation amount\n");
    printf ("3) Encryption using substitution cipher given alphabet substitution\n");
    printf ("4) Decryption using substitution cipher given alphabet substitution\n");
    printf ("Selection: ");

    scanf ("%d", &selec); //reads value from user and assigns it to int selec
    
  

    switch (selec) //switch case determines what task to perform- based on input number
    {
        case 1: //rotation encryption using a key
            printf ("\nSelected 1- Rotation encryption with key.\n");
            printf ("Enter rotation key: ");
            
            int keyOne; //rotation key initialisation
            scanf ("%d", &keyOne); //reads value from user and assigns to keyOne

            FILE *input1; //declaring a pointer of type file, so file can be accessed by program
            input1 = fopen("task1", "r"); //opening the file and assigning it to input1 to be read
            if(input1 == NULL) //if the file cannot be opened, print an error message to avoid killing
            {                  ///the program
                printf("FAILED TO OPEN FILE\n");
                return -1; //returning -1 to avoid killing program
            }
            char c, d, e;
        
            while (1) { //while the file isnt at the end, follow the loop
                
                fscanf(input1, "%c", &c); //reading the character from the file
                
                if(feof(input1)==1) //when the file is finished, exit the loop 
                {
                    break;
                }
                else if (c<65)  //if the char is not a letter (below ASCII 65)
                {
                    printf ("%c", c); //print the char unchanged
                }
                else if (c>90) //if the char is not a letter (above ASCII 90)
                {
                    printf ("%c", c); //print the char unchanged
                }
                
                else if ((c+keyOne)<65) //if the char is not a letter (below ASCII 65)
                {
                    d = (c + keyOne) + 26; //once translated, 'loop' back around to the end of the alphabet
                    printf ("%c", d);
                }
                else if ((c+keyOne)>90) //if the letter is encrypted to punctuation (outside letter range)
                {
                    d = (c + keyOne) - 26; //once translated, 'loop' back around to the start of the alphabet
                    printf ("%c", d);
                } 
                else //only translating capital letters
                {
                   e = rotationOne(c, keyOne); //calling the function to translate
                   printf ("%c", e); //printing ciphertext

                }
            }
            printf ("\n");
            break; 
            
        case 2: 
            printf ("\nSelected 2- Rotation decryption with key. \n");
            printf ("Enter rotation key: ");
            
            int keyTwo=0;
            scanf ("%d", &keyTwo); //reading key value from terminal and assigning it to int keyTwo 
        
            FILE *input2; //declaring a pointer of type file, so the file can be accessed by the program
            input2 = fopen("task2", "r"); //opening the file and assigning it to input2 to be read
            if (input2 == NULL) //if the file cannot be opened due to error
            {
                printf ("FAILED TO OPEN FILE\n"); //print an error message
                return -1; //returning -1 to avoid killing program 
            }
            
            char f, g, h;
            
            while (1) 
            {
                fscanf(input2, "%c", &f); //reading the characters from file
                
                if (feof(input2)==1) //if the file is finished
                {
                    break;
                }
                else if (f<65) //if the char is not a letter (below ASCII 65)
                {
                    printf ("%c", f); //print the char unchanged
                }
                else if (f>90) //if the char is not a letter (above ASCII 90)
                {
                    printf ("%c", f); //print the char unchanged
                }
                else if ((f-keyTwo)<65) //if decrypted char is not a letter within range
                {
                    g = (f - keyTwo) + 26; //once translated, 'loop' back around to end of alphabet
                    printf ("%c", g);
                }
                else if ((f-keyTwo)>90) //if decrypted char is not a letter within range
                {
                    g = (f - keyTwo) - 26; //once translated, 'loop' back around to end of alphabet
                    printf ("%c", g);
                }
                else 
                {
                    h = rotationTwo(f, keyTwo); //calling function to decrypt
                    printf ("%c", h); //printing plaintext 
                } 
            }
            printf ("\n");
            break; 
            
        case 3: 
            printf ("\nSelected 3- Substitution encryption given a key\n");
            
            FILE *input3; //declaring a pointer of type file, so file can be accessed by program
            input3 = fopen("task3", "r"); //opening the file and assigning it to input3 to be read
            if (input3 == NULL) //if the file cannot be opened due to error
            {
                printf("FAILED TO OPEN FILE\n"); //print an error message
                return -1; //return -1 to avoid killing the program 
            }
            
            char i, j;
            
            while (1) 
            {
                fscanf (input3, "%c", &i);
                
                if (feof(input3)==1) //when the file is finished
                {
                    break; //break the loop
                }
                else if (i<65) //if the char is not a letter (below ASCII 65)
                {
                    printf ( "%c", i); //print the char unchanged
                }
                else if (i>90) //if the char is not a letter (above ASCII 90)
                {
                    printf ("%c", i); //print char unchanged 
                }
                else // only translating capital letters
                {
                    j = subcipherEnc(i,j); //calling function to translate char
                    printf ("%c", j); //printing ciphertext
                }
            }
            printf ("\n");
            break; 
            
        case 4: 
            printf ("\nSelected 4- Substitution decryption with key\n");
            
            FILE *input4; //declaring a pointer of type file, so the file can be accessed 
            input4 = fopen("task4", "r"); //opening the file and assigning it to input4 to be read
            if (input4 == NULL) //if the file cannot be opened due to error
            {
                printf ("FAILED TO OPEN FILE\n"); //print an error message 
                return -1; //return -1 to avoid killing program
            }
            
            char k, l;
            
            while (1) 
            {
                fscanf (input4, "%c", &k);
                
                if (feof(input4)==1) //when the file is finished 
                {
                    break; //break the loop
                }
                else if (k<65) //if the char is not a letter (below ASCII 65)
                {
                    printf ( "%c", k); //print the char unchanged
                }
                else if (k>90) //if the char is not a letter (above ASCII 90)
                {
                    printf ("%c", k); //print the char unchanged
                }
                else //only translating capital letters
                {
                    l = subcipherDec(k,l); //calling the function to translate
                    printf ("%c", l); //printing plaintext
                } 
            }

            printf ("\n");
            break; 
            
        default: 
            printf ("\nunknown option\n"); //if entered value isnt an option, default is selected
            } //closing switch case
            } //closing int main
            

/*THIS IS THE FUNCTION FOR TASK 1. THE INPUTS OF THIS FUNCTION ARE THE CHARACTER READ FROM THE FILE, AND 
THE KEY READ FROM STDIN. THE CHARACTER MUST BE OF DATA TYPE CHAR AND THE KEY MUST BE OF DATA TYPE INT. 
THE FUNCTION TAKES PLAIN TEXT CHAR C AS AN ASCII NUMERAL, AND ADDS THE NUMBER OF THE KEY. THIS RETURNS 
A NEW ASCII NUMERAL FOR CHAR C AND THIS IS THE CIPHER TEXT CHARACTER. THE RETURN VALUE IS THE TRANSLATED 
CHARACTER.  */
    char rotationOne(char c, int keyOne)   
    {
        c = c + keyOne;
        return c;
    } 
    
/*THIS IS THE FUNCTION FOR TASK 2. THE INPUTS OF THIS FUNCTION ARE THE CHARACTER READ FROM THE FILE, AND
THE KEY READ FROM STDIN. THE CHARACACTER MUST BE OF DATA TYPE CHAR AND THE KEY MUST BE OF DATA TYPE INT. 
THE FUNCTION TAKES CIPHER TEXT CHAR C AS AN ASCII NUMERAL, AND TAKES AWAY THE NUMBER OF THE KEY. THIS
RETURNS THE NEW ASCII NUMERAL FOR CHAR C AND THIS IS THE PLAIN TEXT CHARACTER. THE RETURN VALUE IS THE 
PLAINTEXT CHARACTER. */    
    char rotationTwo(char f, int keyTwo)
    {
        f = f - keyTwo;
        return f;
    }
    
/*THIS IS THE FUNCTION FOR TASK 3. THE INPUT OF THIS FUNCTION IS THE PLAIN TEXT CHAR READ FROM THE FILE.
THE CHARACTER MUST BE OF DATA TYPE CHAR. THE KEY IS HARD CODED IN THE FUNCTION. THE FUNCTION TAKES THE CHAR
AND USES A SWITCH CASE TO DETERMINE WHAT LETTER THE CHAR IS AND REASSIGNS IT TO A NEW LETTER BASED ON THE
KEY. THE RETURN VALUE IS THE REASSIGNED LETTER, WHICH IS THE CIPHERTEXT.  */    
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
        
/*THIS IS THE FUNCTION FOR TASK 4. THE INPUT OF THIS FUNCTION IS THE CIPHERTEXT CHAR READ FROM THE FILE.
THE CHARACTER MUST BE OF DATA TYPE CHAR. THE KEY IS HARD CODED IN THE FUNCTION. THE FUNCTION TAKES THE CHAR
AND USES A SWITCH CASE TO DETERMINE WHAT LETTER THE CHAR IS AND REASSIGNS IT TO A NEW LETTER BASED ON THE
KEY. THE RETURN VALUE IS THE REASSIGNED LETTER, WHICH IS THE PLAINTEXT.  */        
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