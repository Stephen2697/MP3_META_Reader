//USED WITH: 'readMP3.c'

/*
 Function Name: Genre_Type_Function()
 Functionality: This is quite a basic function, The purpose of this function is to act as a large library for the variety of genre types, whenever this function is called it simply returns the string contained in the desired element location. The previously validated sound file's genre data value will be passed in and that integer value dictates with element is returned. This Code was designed to be implemented in a unique function for readability purposes only as there is little complexity involved - yet it appears tedious when mixed in with the actual c file.
 
 Function Arguements: There is one function arguement.
 1. int* Genre_ID -  Pointer to the integer which contains the value of the genre in question, this simply acts as an index which is then selected out of the Genre_array (string array) below.
 
 Function Returns: character string of the corresponding Genre Type - which will be printed by main().
 */

char*  Genre_Type_Function(int* Genre_ID)
{
	
	//Simply a large String Array declared in Accordance with the ID3v1 Specification.
	char *Genre_array[] = {
		"Blues", "Classic Rock", "Country","Dance","Disco","Funk","Grunge","Hip-Hop",
		"Jazz","Metal","New Age","Oldies","Other","Pop","R&B","Rap","Reggae","Rock",
		"Techno","Industrial","Alternative","Ska","Death Metal","Pranks","Soundtrack",
		"Euro-Techno","Ambient","Trip-Hop","Vocal","Jazz+Funk","Fusion","Trance","Classical",
		"Instrumental","Acid","House","Game","Sound Clip","Gospel","Noise","AlternRock","Bass","Soul",
		"Punk","Space","Meditative","Instrumental Pop", "Instrumental Rock","Ethnic","Gothic",
		"Darkwave","Techno- Industrial","Electronic", "Pop-Folk","Eurodance","Dream","Southern Rock",
		"Comedy","Cult","Gangsta","Top 40","Christian Rap","Pop/Funk","Jungle","Native American",
		"Cabaret","New Wave","Psychadelic","Rave","Showtunes","Trailer","Lo-Fi","Tribal","Acid Punk",
		"Acid Jazz","Polka","Retro","Musical","Rock & Roll","Hard Rock"
	};
	
	//Returns indexed Genre Type.
	return(Genre_array[*Genre_ID]);
	
} //end function
