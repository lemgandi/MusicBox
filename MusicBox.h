#ifndef MUSICBOX_H
#define MUSICBOX_H
/*
 * The MusicBox library object
 * Copyright (c) Charles Shapiro November 2017

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
   note *musicLibrary[21];  // Storage for song pointers
};



#endif
