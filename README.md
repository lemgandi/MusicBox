MusicBox
====

A simple Arduino library to play tunes through the speaker.

# Tunes

Tunes are composed of notes.  A note is:
```
typedef struct note
{
   int pitch;
   int duration;
};
```

Pitch is frequency in hertz (first argument to the tone() routine in the Arduino library)
Duration is a note value (e.g. 1000/Duration). Hence, quarter notes are "4", et cetera.
The "Tone" example code in the Arduino reference has a handy-dandy "pitches.h" table which
neatly translates note frequencies (e.g. "NOTE_A4" = 440).

A tune is an array of notes terminated with a note of pitch -1 and duration -1.

# Routines

MusicBox has the following public routines:

- MusicBox() 
  - create a music box with no output pin
- void MusicBox.begin(int) 
  - set and initialize MusicBox output pin
- MusicBox(int pin) 
  - create a music box with an output pin
- void loadATune(note *tune,int slot) 
  - Load a tune into the music box at slot. There are currently 20 slots.
- void playATune(int slot)  
  - Play the tune at the given slot
- void playTune(note *)  
  - Play a given tune

# Errors
If you attempt to play a tune at a slot outside of the tune library (e.g. slot -1 or slot 22), or
an empty (un-loaded) slot, the music box will play "Shave and a Hair Cut" instead.

