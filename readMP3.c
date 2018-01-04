//PROGRAM TITLE: 'readMP3.c'
//CREATION DATE: 16/03/2017
//LAST MODIFIED: 21/04/2017

//VERSION IDENTIFIER: 0.9.9

//MODULE: PROGRAMMING WITH WITH PERSISTENT DATA
//PROGRAM DESIGN CORRESPONDS TO THE SPECIFICATION OF REQUIREMENTS DOCUMENTED: GrpTasksOddTeams.pdf

//For Instructions Of Usage See Included: 'README.txt'
//PROGRAMMING LANGUAGE: C
//LICENSE: ALL RIGHTS RESERVED © 2017

//REFERENCES FOR CODE DESIGN
//1. 'A Guide To C Programming' - © Paul Kelly 2007
//2. Bug Fixing & Diagnostic - Stackoverflow Forums - stackoverflow.com
//3. Bug Fixing & Diagnostics - Tutorialspoint - tutorialspoint.com
//4. Reference Point About IDV3 - https://en.wikipedia.org/wiki/ID3

/*Program Information:
This Program has the sole purpose of extracting META Data from sound filenames inputted to it. Error Checking & Validation Steps are implemented extensively. Once this desired data is Extracted This Data is Stored byte by byte into a dedicated Struct Variable. Assuming execution of this program gets passed the Error Checking Code the extracted Data is Outputted to Standard Output - Displayed to User. 
*/

//INCORPORATED LIBRARIES & HEADER FILES
#include <stdio.h>
#include <stdlib.h>

#include "Symbolic_Naming_Scheme.h"
#include "Structure_Templates.h"

//FUNCTION PROTOTYPING
//Function Descriptions available at start of implementations.
char* Data_Handling_Function(int, ID3_TAG*);
char*  Genre_Type_Function(int*);

//ADDITIONAL INCORPORATED LIBRARIES & HEADER FILES
#include "Data_Handling_Function.h"
#include "Genre_Type_Function.h"

//DEBUGGING #DEFINE SWITCH - USED TO TEST PROGRAM & ALLOW EASIER DEBUGGING.
//If '#define DEBUG_MODE' is commented out and the following #define is not commented out then program works as intended.
//#define DEBUG_MODE

//If '#define NON_DEBUG_MODE' is commented out and the previous #define is not commented out then program is operating in Debug mode. This mode removes the command line input of the file name... Meaning the program will operate on a specific filename.
#define NON_DEBUG_MODE

/*
 Function Name: Data_Handling_Function()
 Functionality: This function has several primary purposes, firstly It takes in the user's command line input, performing error checks to ensure the correct number of function arguments have been passed to the program. Once complete the function declares it's neccessary variables of varying data types including a struct variable and struct variable pointer. Then the program provides some basic user feedback, it then attempts to open the filename passed into main() which is stored in the argument vector (argv[]). Appropriate Error checking is in place - meaning if the specified file cannot be opened then a corresponding error feedback is given to the user and the program is terminated. Once the file is successfully opened main() will find the TAG string identifier and extract the data it needs from the sound file - assuming it is formatted correctly & if not then more error feedback is given. If an TAG field is empty the program will return 'Unknown' as specified in the program descriptor. Lastly - main() fulfills it's main task by calling the Data_Handling_Function() in an integrated printf statement. Note: At no stage does Main() directly interact with the 'Genre_Type_Function()' function.
 
 Function Arguements: There are two function arguements. 
 1. argc - 'Argument Counter' -  data type: integer.
 2. argv - 'Argument Vector' - data type: array of character strings.
 
 Function Returns: integer value - used to terminate main() i.e. 'return 0;' 
 */

#ifdef NON_DEBUG_MODE
int main(int argc, char *argv[])
#endif
    
#ifdef DEBUG_MODE
int main()
#endif
{
	//argChecker - acts as an error handling flag which is used to detect when the incorrect number of arguments have been passed to main() i.e. the initial error checking feature.
    #ifdef NON_DEBUG_MODE
	int argChecker = 0;
    #endif
	
	//Basic effort at a textual user-interface to illustrate the start of the program
	printf("\n--------------------------------------------\n--------------------------------------------\n");
	
	//Turnary Condition - (Conditional Operator)
	//'Is argument counter not equal to 2?'
	//Yes: change argChecker to 1 - acts as an error handling flag.
	//No: output user feedback to illustrate a successful operating status
    #ifdef NON_DEBUG_MODE
	(argc != CORRECT_NUM_ARGUMENTS) ? argChecker = 1 : printf("Processing Input...\n");
    #endif
	
	//Dealing with cases where incorrect number of arguments have been passed into main()
    #ifdef NON_DEBUG_MODE
	if (argChecker == 1)
	{
		//output basic user feedback & terminate program.
		printf("\nPlease Only Enter Two Arguments - Maximum , Try Running Program Again\n");
		return 0;
	} //end if
    #endif
	
	//Variable Declarations
	//------------
	
	//Declaration of DATA TYPE: struct ID3_TAG
	//(typedefined to just: 'ID3_TAG' above)
	ID3_TAG Song_Variable;
	ID3_TAG* Song_Var_pointer;
	
	//Assign address of Song_variable to Song_Var_pointer
	Song_Var_pointer = &Song_Variable;
	
	//Declare File pointer
	FILE* File_pointer ;
	
	//Declare & Initialise valid_counter - acts as a counter which is incremented when each letter: 'T', 'A', 'G' is found. So after a successful run this counter should equal 3.
	int valid_counter = 0;
	
	//Basic user feedback to illustrate a successful operating status & to inform the user what is going on behind the scenes.
	printf("Hello, Welcome To This MP3 TAG Analyser\n");
    
    #ifdef NON_DEBUG_MODE
	printf("Trying To Open File: [%s]...\n", *(argv+1));
    #endif
	
	//Open the file in 'read binary mode'
    //Accessing Second Element of (argv) Argument Vector (String Array) as the first element contains the initial command file call to open file e.g. "./readMP3" and the second element of argv contains the intended sound file name.
    #ifdef NON_DEBUG_MODE
	File_pointer = fopen(*(argv + 1), "rb");
    #endif
	
    #ifdef DEBUG_MODE
    File_pointer = fopen("/Users/Stephen/odrive/DIT Google Drive/PWPD/PWPD_Assignment/PWPD_Assignment/Sleep.mp3", "rb");
    #endif
	
	
	//If file is opened successfully....
	if (File_pointer != NULL)
	{
		//fseek to end of file with a negative offset of  128 - #defined above.
		fseek(File_pointer, -BYTE_LEN, SEEK_END);
		
		//fread 3 characters into the appropraite struct variable member
		fread(Song_Variable.VALID_ID, sizeof(char), TAG_LEN , File_pointer);
		
		//Turnary Conditon - (Conditonal Operator)
		//Perform check - 'Were T, A, G read in?'
		//YES: Increment the valid_counter variable
		//No: Do not change the value of the valid_counter
		valid_counter = (Song_Variable.VALID_ID[0] == 'T') ? valid_counter +1 : 0;
		valid_counter = (Song_Variable.VALID_ID[1] == 'A') ? valid_counter +1 : 0;
		valid_counter = (Song_Variable.VALID_ID[2] == 'G') ? valid_counter +1 : 0;
		
		//'if TAG was found successfully' - i.e. this file correspomds to ID3 Formatting
		if (valid_counter == 3)
		{
			
			//Basic user feedback to illustrate a successful operating status & to inform the user what is going on behind the scenes.
			printf("Checking File Now...\n");
			printf("--------------------------------------------\n--------------------------------------------\n");
			
			//Using fread, extract the desired information one piece at a time...
			//Data is stored in the struct variable in each corresponding struct variable member location.
			//Each fread statement reads a #defined number of 1 byte (sizeof - char) segments from the file.
			fread(Song_Variable.Song_Title, sizeof(char), STD_FIELD_LEN, File_pointer);
			fread(Song_Variable.Artist_Name, sizeof(char), STD_FIELD_LEN, File_pointer);
			fread(Song_Variable.Album_Title, sizeof(char), STD_FIELD_LEN, File_pointer);
			fread(Song_Variable.Release_Year, sizeof(char), YEAR_LEN, File_pointer);
			fread(Song_Variable.Comment, sizeof(char), STD_FIELD_LEN, File_pointer);
			fread(Song_Variable.Genre_Type, sizeof(char), GENRE_LEN, File_pointer);
			
			//File no longer needed...
			fclose(File_pointer);
		
		} //end if
		
		//Otherwise the file selected does not correspsond to the ID3 specification formatting & terminate.
		else
		{
			printf("\nInvalid File Selected, The file does not contain a valid audio tag,\nSelect a Sound File which conforms to the ID3 V1 or ID3 V1.1 Specification\n");
			
			return 0;
		} //end else
		
		//Now output the desired data to standard output using integrated function calls within printf statements
		//The first argument passed to the Data_Handling_Function() is a mode selector which works with the switch function within Data_Handling_Function(). The second argument passes a pointer to the struct variable which contains the desired data.
		printf("Title of the song: [%s]\n", Data_Handling_Function(SONG_NAME_MODE, Song_Var_pointer));
		printf("Author of the song (artist): [%s]\n", Data_Handling_Function(ARTIST_NAME_MODE, Song_Var_pointer));
		printf("Album: [%s]\n", Data_Handling_Function(ALBUM_NAME_MODE, Song_Var_pointer));
		printf("Year: [%s]\n", Data_Handling_Function(RELEASE_YEAR_MODE, Song_Var_pointer));
		printf("Genre: [%s]\n", Data_Handling_Function(SONG_GENRE_MODE, Song_Var_pointer));
		
		printf("--------------------------------------------\n--------------------------------------------\n\n");
	
		
	} //end outer if
	
	//Otherwise file could not be opened... & terminate.
	else
	{
		printf("\nThe Selected Filename could not be opened.\nRe-run This Program & Try Again...\n");
        
        printf("--------------------------------------------\n--------------------------------------------\n\n");
        
		return 0;
	} //end else
	
} //end main


