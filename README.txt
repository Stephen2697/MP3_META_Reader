To make this file work it must be called by the command line. 
The following steps work on MacOs and Linux, these steps will require reworking on Windows.

1. Open Terminal.
2. Change directory to the current location of the ‘readMP3.c’ file - e.g. type this: cd /Users/Stephen/Desktop.
3. Compile ‘readMP3.c’ - e.g. type this: gcc readMP3.c -o readMP3.
4. Open file & input Sound file - e.g. type this: ./readMP3 Sleep.mp3

***The Above is Tested & Works on MacOS

***Below is an Exact Transcript of the file in operation with the provided file:

Stephens-Mac-Mini:Desktop Stephen$ cd /Users/Stephen/Desktop 
Stephens-Mac-Mini:PWPD_Assignment Stephen$ gcc readMP3.c -o readMP3
Stephens-Mac-Mini:PWPD_Assignment Stephen$ ./readMP3 Sleep.mp3
--------------------------------------------
--------------------------------------------
Processing Input...
Hello, Welcome To This MP3 TAG Analyser
Opening File: [Sleep.mp3]
Checking File Now...
--------------------------------------------
--------------------------------------------
Title of the song: [Sleep Away]
Author of the song (artist): [Bob Acri]
Album: [Bob Acri]
Year: [2004]
Genre: [Other]
--------------------------------------------
--------------------------------------------

***Below is another snapshot with the second file:

Stephens-Mac-Mini:Desktop Stephen$ cd /Users/Stephen/Desktop 
Stephens-Mac-Mini:Assignment_Part1 Stephen$ gcc readMP3.c -o readMP3
Stephens-Mac-Mini:Assignment_Part1 Stephen$ ./readMP3 Queen.mp3
--------------------------------------------
--------------------------------------------
Processing Input...
Hello, Welcome To This MP3 TAG Analyser
Opening File: [Queen.mp3]
Checking File Now...
--------------------------------------------
--------------------------------------------
Title of the song: [Another One Bites The Dust]
Author of the song (artist): [Queen]
Album: [Greatest Hits]
Year: [1984]
Genre: [Classic Rock]
--------------------------------------------
--------------------------------------------
