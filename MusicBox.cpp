/*
 * Methods and statics for the MusicBox singleton object
 */

#include "Arduino.h"

#include <MusicBox.h>
#include <pitches.h>

static const note StartSong[] = {
  {NOTE_C4,8},  {NOTE_D4,8},  {NOTE_E4,8},  {NOTE_G4,8},
  {0,8},  {NOTE_E4,8},  {NOTE_G4,4},  {-1,-1}
};

static const note FailSong[] = {
   {NOTE_C6,4},   {NOTE_B5,4},   {NOTE_A5,4},   {NOTE_G5,4},
   {NOTE_C4,2},
   {-1,-1}
};

/*
 * Mostly for testing
 */
static const note ShaveandHaircutSong[] =
{
  {NOTE_C4,4},  {NOTE_G3,8},  {NOTE_G3,8},  {NOTE_A3,4},
  {NOTE_G3,4},  {0,4},  {NOTE_B3,4},  {NOTE_C4,4},
  {-1,-1}
};

/*
 * Play if we win
 */
static const note SuccessSong[] =  {
{NOTE_F4,   8},{NOTE_E4,  16},{NOTE_D4,   8},{NOTE_CS4,  16},
{NOTE_C4,   8},{NOTE_B3,  16},{NOTE_AS3,   8},{NOTE_A3,  16},
{NOTE_G3,  16},{NOTE_A3,  16},{NOTE_AS3,  16},{NOTE_A3,   8},
{NOTE_G3,  16},{NOTE_C4,   8},{0,   3,},{NOTE_C4,  12},
{NOTE_A3,  16},{NOTE_A3,  16},{NOTE_A3,  16},{NOTE_GS3,   8},
{NOTE_A3,  16},{NOTE_F4,   8},{NOTE_C4,  16},{NOTE_C4,   8},
{NOTE_A3,  16},{NOTE_AS3,   8},{NOTE_AS3,  16},{NOTE_AS3,   8},
{NOTE_C4,  16},{NOTE_D4,  4},{0,    12},{NOTE_AS3,  12},
{NOTE_G3,  16},{NOTE_G3,  16},{NOTE_G3,  16},{NOTE_FS3,   8},
{NOTE_G3,  16},{NOTE_E4,   8},{NOTE_D4,  16},{NOTE_D4,   8},
{NOTE_AS3,  16},{NOTE_A3,   8},{NOTE_A3,  16},{NOTE_A3,   8},
{NOTE_AS3,  16},{NOTE_C4,  4},{0,  12},{NOTE_C4,  12},
{NOTE_A3,  16},{NOTE_A3,  16},{NOTE_A3,  16},{NOTE_GS3,   8},
{NOTE_A3,  16},{NOTE_A4,   8},{NOTE_F4,  16},{NOTE_F4,   8},
{NOTE_C4,  16},{NOTE_B3,   8},{NOTE_G4,  16},{NOTE_G4,   8},
{NOTE_G4,  16},{NOTE_G4,  4},{0,  16},{NOTE_G4,  12},
{NOTE_E4,  17},{NOTE_G4,  17},{NOTE_G4,  17},{NOTE_FS4,   8},
{NOTE_G4,  12},{NOTE_D4,  17},{NOTE_G4,  17}, {NOTE_G4,  17},
{NOTE_FS4,   8},{NOTE_G4,  16},{NOTE_C4,   8},{ NOTE_B3,  16},
{NOTE_C4,   8},{NOTE_B3,  16},{NOTE_C4,   8},{0,1},
{-1,-1}
};
static int MusicOutPin;

/*
 * Public interface play
 */
void MusicBox::playTune(tuneType theTune)
{
   switch(theTune) {
      case Start:
         playATune(StartSong);
	 break;
      case Happy:
         playATune(SuccessSong);
	 break;
      case Sad:
         playATune(FailSong);
	 break;
      default: // ShaveandHaircut
         playATune(ShaveandHaircutSong);
	 break;
   }
}
/*
 * Actually play the tune
 */
void MusicBox::playATune(note *theTune)
{
  int thePause;
  
   while(theTune->duration != -1) {
     tone(MusicOutPin,theTune->pitch,(unsigned long)(1000/(theTune->duration)));
     delay(( (1000/(theTune->duration)) * 1.30));
     ++theTune;
   }
}

/*
 * Public interface init
 */
void MusicBox::begin(int thePin)
{
   pinMode(thePin,OUTPUT);
   MusicOutPin=thePin;
}
