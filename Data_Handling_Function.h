//USED WITH: 'readMP3.c'

/*
 Function Name: Data_Handling_Function()
 Functionality: This function Validates Data read in from the sound file. It is implemeneted to operate as a switch statement which handles any function calls appropriately. The function takes in two arguements, the first specifies the mode which the function should operate in and the second arguement passes the pointer to the struct variable from main(). The switch statement interprets the Mode specifier and executes the correspond code in 5 major cases. Ultimately this function processes the data in the struct variable and returns the contents of the struct variable member if there is any and if not it returns the string "Unknown" to main() as specified in the program descriptor provided in assignment.
 
 Function Arguements: There are two function arguements.
 1.  int Mode - integer value which is dictated by main() to process and return the desired data, interpretted by the switch statement.
 2.  ID3_TAG* Song_Var_pointer - struct variable pointer used to access the sound file data in order for this data to be processed.
 
 Function Returns: character string - which will be printed by main().
 */


char* Data_Handling_Function(int Mode, ID3_TAG* Song_Var_pointer)
{
	//Variable declarations
	
	//specified as static to simply allocate memory once, for efficiency purposes. This string is maintained after function is exited.
	static char Error[] = "Unknown";
	
	//Switch Statement - interprets the value of 'Mode' variable - i.e. establishes what is to be done.
	switch (Mode)
	{
		
		//Dealing With Song Title
		case SONG_NAME_MODE :
		{
			
			//return statement merged with turnary conditon - (conditional operator)
			//'Is song title empty?'
			//YES: Return Error string - e.g. return "Unknown" to main()
			//NO: Return Song Title String to Main
			return ((*(Song_Var_pointer ->Song_Title) == '\0') ?  Error : Song_Var_pointer ->Song_Title);
			break;
			
		} //end case 1
			
			
		//Dealing With Artist Name
		case ARTIST_NAME_MODE :
		{
			//return statement merged with turnary conditon - (conditional operator)
			//'Is Artist Name empty?'
			//YES: Return Error string - e.g. return "Unknown" to main()
			//NO: Return Artist Name String to Main
			return ((*(Song_Var_pointer ->Artist_Name) == '\0') ?  Error : Song_Var_pointer ->Artist_Name);
			break;
			
		} //end case 2
			
			
		//Dealing With Album Title
		case ALBUM_NAME_MODE :
		{
			//return statement merged with turnary conditon - (conditional operator)
			//'Is  Album Title empty?'
			//YES: Return Error string - e.g. return "Unknown" to main()
			//NO: Return Album Title String to Main
			return ((*(Song_Var_pointer ->Album_Title) == '\0') ?  Error : Song_Var_pointer ->Album_Title);
			break;
			
		} //end case 3
			
			
		//Dealing With Release Year
		case RELEASE_YEAR_MODE :
		{
			//return statement merged with turnary conditon - (conditional operator)
			//'Is Release Year information empty?'
			//YES: Return Error string - e.g. return "Unknown" to main()
			//NO: Return Release Year String to Main
			return ((*(Song_Var_pointer ->Release_Year) == '\0') ?  Error : Song_Var_pointer ->Release_Year);
			break;
			
		} //end case 4
			
			
		//Dealing With Genre Type
		case SONG_GENRE_MODE :
		{
			//Obtain the ASCII Value of the Genre_Type of the Sound file
			int Genre_INT = (Song_Var_pointer->Genre_Type[0]);
			
			//return statement merged with turnary conditon - (conditional operator)
			//'Is  Genre Type Number outside the 0-79 range?'
			//YES: Return Error string - e.g. return "Unknown" to main()
			//NO: Return to main() the results of the Genre_Type_Function() function call after passing the valid Genre Type value into Genre_Type_Function().
			return (Genre_INT > 79 || Genre_INT <0) ?  Error : Genre_Type_Function(&Genre_INT);
			break;
			
		} //end case 5
		
		//Default case is redundant in this usage as the variable used in this switch statement is dictated entirely by the programmer and not the user. Code left here for convention.
		default:
		{
			printf("\nOops Something Went Wrong :(\n");
			return 0;
			
		} //end default case
			
			
	} //end switch
	
	
} //end function
