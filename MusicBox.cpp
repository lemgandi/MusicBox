/*
 * Methods and statics for the MusicBox singleton object
 * Copyright(c) Charles Shapiro November 2017

This file is part of MusicBox.

    MusicBox is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    MusicBox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with MusicBox.  If not, see <http://www.gnu.org/licenses/>.

 */

#include "Arduino.h"

#include <MusicBox.h>
#include <pitches.h>

#define CHS_DEBUG

static note _OopsSong[] =
{
  {NOTE_C4,4},  {NOTE_G3,8},  {NOTE_G3,8},  {NOTE_A3,4},
  {NOTE_G3,4},  {0,4},  {NOTE_B3,4},  {NOTE_C4,4},
  {-1,-1}
};


#define MUSICLIBSIZE ( (sizeof(musicLibrary)/sizeof(note *)) - 1  )


MusicBox::MusicBox()
{
   begin(-1);
}
/*
 * Pass output pin to creator
 */
MusicBox::MusicBox(int thepin)
{
   begin(thepin);   
}
/*
 * Load a tune into the music box for future reference
 */
int MusicBox::loadATune(note *thesong, int thePlace)
{
   boolean retval=true; //retval false means a trouble happened.
   if((thePlace < 0) || (thePlace > MUSICLIBSIZE))
      retval=false;
   if(true == retval) {
      musicLibrary[thePlace+1]=thesong;
   }
}

/*
 * Public interface play
 */
void MusicBox::playATune(int tuneIdx)
{
   if((tuneIdx < MUSICLIBSIZE) && (tuneIdx >= 0) && (musicLibrary[tuneIdx]) )
      playTune(musicLibrary[tuneIdx+1]);
   else
      playTune(musicLibrary[0]);
}

/*
 * Actually play a tune (e.g. a series of notes)
 */
void MusicBox::playTune(note *theTune)
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
   if(thePin > 0) {
      pinMode(thePin,OUTPUT);
      MusicOutPin=thePin;
   }
   memset(musicLibrary,0,sizeof(musicLibrary));
   musicLibrary[0]=_OopsSong;
}
