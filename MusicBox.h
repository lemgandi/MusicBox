#ifndef MUSICBOX_H
#define MUSICBOX_H


typedef enum tuneType {Start,Happy,Sad,ShaveandHaircut};

typedef struct note
{
   int pitch;
   int duration;
};




class MusicBox {
public:
   void begin(int);
   void playTune(tuneType);
private:
   void playATune(note *);
};



#endif
