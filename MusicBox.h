#ifndef MUSICBOX_H
#define MUSICBOX_H


typedef struct note
{
   int pitch;
   int duration;
};




class MusicBox {
public:
   MusicBox();
   MusicBox(int);
   void begin(int);
   void playTune(note *);
   void playATune(int);
   int loadATune(note *,int);
private:
   int MusicOutPin;  // Pin where music appears.
   note *musicLibrary[21];
};



#endif
