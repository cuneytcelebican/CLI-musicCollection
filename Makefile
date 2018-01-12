OBJ = main.o CliLogging.o FileOperator.o MediaPlayer.o Model.o View.o Song.o Songs.o Recording.o Recordings.o Track.o Tracks.o User.o Users.o Playlist.o

myTunes: $(OBJ)
	g++ -o myTunes $(OBJ)

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

CliLogging.o: CliLogging.cpp CliLogging.h
	g++ -c -std=c++11 CliLogging.cpp

FileOperator.o: FileOperator.cpp FileOperator.h
	g++ -c -std=c++11 FileOperator.cpp

MediaPlayer.o: MediaPlayer.cpp MediaPlayer.h
	g++ -c -std=c++11 MediaPlayer.cpp

View.o: View.cpp View.h
	g++ -c -std=c++11 View.cpp

Model.o: Model.cpp Model.h
	g++ -c -std=c++11 Model.cpp

Song.o: Song.cpp Song.h
	g++ -c -std=c++11 Song.cpp

Songs.o: Songs.cpp Songs.h
	g++ -c -std=c++11 Songs.cpp

Recording.o: Recording.cpp Recording.h
	g++ -c -std=c++11 Recording.cpp

Recordings.o: Recordings.cpp Recordings.h
	g++ -c -std=c++11 Recordings.cpp

Track.o: Track.cpp Track.h
	g++ -c -std=c++11 Track.cpp

Tracks.o: Tracks.cpp Tracks.h
	g++ -c -std=c++11 Tracks.cpp

User.o: User.cpp User.h
	g++ -c -std=c++11 User.cpp

Users.o: Users.cpp Users.h
	g++ -c -std=c++11 Users.cpp

Playlist.o: Playlist.cpp Playlist.h
	g++ -c -std=c++11 Playlist.cpp

clean:
	rm -f $(OBJ) myTunes