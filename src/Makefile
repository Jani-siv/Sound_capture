CC = g++
CFLAGS = -Wall -Wl,--start-group -lgcc -lc -lc -lm  -Wl,--end-group -O0 -g -gdwarf-2 -lcurl -lpthread -lstdc++fs
SOUND = -lasound

objects = main.o CreateFile.o ParseSound.o SoundRecorder.o UploadFile.o Commands.o ReadOneFile.o ErrorLog.o

edit: $(objects)
	$(CC) $(CFLAGS) -o recorder $(objects) $(SOUND)

main.o: SoundRecorder.h menu.h
	$(CC) $(CFLAGS) -c main.cpp
CreateFile.o: CreateFile.h Riff.h
	$(CC) $(CFLAGS) -c CreateFile.cpp
ParseSound.o: ParseSound.h
	$(CC) $(CFLAGS) -c ParseSound.cpp
SoundRecorder.o: SoundRecorder.h CreateFile.h ErrorLog.h
	$(CC) $(CFLAGS) -c SoundRecorder.cpp
UploadFile.o: UploadFile.h ReadOneFile.h
	$(CC) $(CFLAGS) -c UploadFile.cpp
Commands.o: Commands.h ErrorLog.h
	$(CC) $(CFLAGS) -c Commands.cpp
ReadOneFile.o: ReadOneFile.h
	$(CC) $(CFLAGS) -c ReadOneFile.cpp
ErrorLog.o: ErrorLog.h
	$(CC) $(CFLAGS) -c ErrorLog.cpp
	
.PHONY : clean
clean :
	rm $(objects)
	