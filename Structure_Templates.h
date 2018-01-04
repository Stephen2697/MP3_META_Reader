//STRUCTURE TEMPLATE DECLARATIONS
//USED WITH: 'readMP3.c'

//ID3_TAG - Used to store Meta data of the Sound file which we wish to access
struct ID3_TAG
{
	char VALID_ID[TAG_LEN+1];
	char Song_Title[STD_FIELD_LEN+1];
	char Artist_Name[STD_FIELD_LEN+1];
	char Album_Title[STD_FIELD_LEN+1];
	char Release_Year[YEAR_LEN+1];
	char Comment[STD_FIELD_LEN+1];
	char Genre_Type[GENRE_LEN+1];
};

//TYPE DEFINES
typedef struct ID3_TAG ID3_TAG;
