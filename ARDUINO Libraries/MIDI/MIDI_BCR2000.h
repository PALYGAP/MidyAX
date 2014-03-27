/*!
 *  @file		MIDI.h
 *  Project		MIDI Library
 *	@brief		MIDI Library for the Arduino
 *	Version		3.2
 *  @author		Francois Best 
 *	@date		24/02/11
 *  License		GPL Forty Seven Effects - 2011
 */

#ifndef LIB_MIDI_BCR2000_H_
#define LIB_MIDI_BCR2000_H_

#include <inttypes.h> 
#include "COMMON.h" 

/*  
    ###############################################################
    #                                                             #
    #    CONFIGURATION AREA                                       #
    #                                                             #
    #    Here are a few settings you can change to customize      #
    #    the library for your own project. You can for example    #
    #    choose to compile only parts of it so you gain flash     #
    #    space and optimise the speed of your sketch.             #
    #                                                             #
    ###############################################################
 */


#define COMPILE_MIDI_IN         1           // Set this setting to 1 to use the MIDI input.
#define COMPILE_MIDI_OUT        1           // Set this setting to 1 to use the MIDI output. 
#define COMPILE_MIDI_THRU       0           // Set this setting to 1 to use the MIDI Soft Thru feature
                                            // Please note that the Thru will work only when both COMPILE_MIDI_IN and COMPILE_MIDI_OUT set to 1.


#define BCR2000_USE_SERIAL_PORT Serial2     // Change the number (to Serial1 for example) if you want
                                            // to use a different serial port for MIDI I/O.
                                            // EF_MODIF : AXE-FX is on Serial2


#define USE_RUNNING_STATUS		1			// Running status enables short messages when sending multiple values
                                            // of the same type and channel.
                                            // Set to 0 if you have troubles with controlling you hardware.


#define USE_CALLBACKS           1           // Set this to 1 if you want to use callback handlers (to bind your functions to the library).
                                            // To use the callbacks, you need to have COMPILE_MIDI_IN set to 1

#define USE_1BYTE_PARSING       0           // Each call to MIDI.read will only parse one byte (might be faster).


// END OF CONFIGURATION AREA 
// (do not modify anything under this line unless you know what you are doing)


#define MIDI_BAUDRATE			31250

#define MIDI_CHANNEL_OMNI		0
#define MIDI_CHANNEL_OFF		17			// and over

//#define MIDI_SYSEX_ARRAY_SIZE	255			// Maximum size is 65535 bytes.  EF_MODIF: put in COMMON.H


//extern enum kMIDIType;
//extern enum kThruFilterMode;
//extern struct midimsg;


/*! \brief The main class for MIDI handling.\n
	See member descriptions to know how to use it,
	or check out the examples supplied with the library.
 */
class MIDI_BCR2000_Class {
	
	
public:
	// Constructor and Destructor
	MIDI_BCR2000_Class();
	~MIDI_BCR2000_Class();
	
	
	void begin(const byte inChannel = 1);
	
	
	
	
/* ####### OUTPUT COMPILATION BLOCK ####### */	
#if COMPILE_MIDI_OUT

public:	
	
	void sendNoteOn(byte NoteNumber,byte Velocity,byte Channel);
	void sendNoteOff(byte NoteNumber,byte Velocity,byte Channel);
	void sendProgramChange(byte ProgramNumber,byte Channel);
	void sendControlChange(byte ControlNumber, byte ControlValue,byte Channel);
	void sendPitchBend(int PitchValue,byte Channel);
	void sendPitchBend(unsigned int PitchValue,byte Channel);
	void sendPitchBend(double PitchValue,byte Channel);
	void sendPolyPressure(byte NoteNumber,byte Pressure,byte Channel);
	void sendAfterTouch(byte Pressure,byte Channel);
	void sendSysEx(int length, const byte *const array,bool ArrayContainsBoundaries = false);	
	void sendTimeCodeQuarterFrame(byte TypeNibble, byte ValuesNibble);
	void sendTimeCodeQuarterFrame(byte data);
	void sendSongPosition(unsigned int Beats);
	void sendSongSelect(byte SongNumber);
	void sendTuneRequest();
	void sendRealTime(kMIDIType Type);
	
	void send(kMIDIType type, byte param1, byte param2, byte channel);
	
private:
	
	const byte genstatus(const kMIDIType inType,const byte inChannel) const;
	
	
	// Attributes
#if USE_RUNNING_STATUS
	byte			mRunningStatus_TX;
#endif // USE_RUNNING_STATUS

#endif	// COMPILE_MIDI_OUT
	

	
/* ####### INPUT COMPILATION BLOCK ####### */
#if COMPILE_MIDI_IN	
	
public:
	
	bool read();
	bool read(const byte Channel);
	
	// Getters
	kMIDIType getType() const;
	byte getChannel() const;
	byte getData1() const;
	byte getData2() const;
	const byte * getSysExArray() const;
	unsigned int getSysExArrayLength() const;
	bool check() const;
	
	byte getInputChannel() const 
    {
        return mInputChannel;
    }
	
	// Setters
	void setInputChannel(const byte Channel);
	
	/*! \brief Extract an enumerated MIDI type from a status byte.
	 
	 This is a utility static method, used internally, made public so you can handle kMIDITypes more easily.
	 */
	static inline const kMIDIType getTypeFromStatusByte(const byte inStatus) 
    {
		if ((inStatus < 0x80) 
			|| (inStatus == 0xF4) 
			|| (inStatus == 0xF5) 
			|| (inStatus == 0xF9) 
			|| (inStatus == 0xFD)) return InvalidType; // data bytes and undefined.
		if (inStatus < 0xF0) return (kMIDIType)(inStatus & 0xF0);	// Channel message, remove channel nibble.
		else return (kMIDIType)inStatus;
	}
	
	
#if USE_CALLBACKS
	
	void setHandleNoteOff(void (*fptr)(byte channel, byte note, byte velocity));
	void setHandleNoteOn(void (*fptr)(byte channel, byte note, byte velocity));
	void setHandleAfterTouchPoly(void (*fptr)(byte channel, byte note, byte pressure));
	void setHandleControlChange(void (*fptr)(byte channel, byte number, byte value));
	void setHandleProgramChange(void (*fptr)(byte channel, byte number));
	void setHandleAfterTouchChannel(void (*fptr)(byte channel, byte pressure));
	void setHandlePitchBend(void (*fptr)(byte channel, int bend));
	void setHandleSystemExclusive(void (*fptr)(byte * array, byte size));
	void setHandleTimeCodeQuarterFrame(void (*fptr)(byte data));
	void setHandleSongPosition(void (*fptr)(unsigned int beats));
	void setHandleSongSelect(void (*fptr)(byte songnumber));
	void setHandleTuneRequest(void (*fptr)(void));
	void setHandleClock(void (*fptr)(void));
	void setHandleStart(void (*fptr)(void));
	void setHandleContinue(void (*fptr)(void));
	void setHandleStop(void (*fptr)(void));
	void setHandleActiveSensing(void (*fptr)(void));
	void setHandleSystemReset(void (*fptr)(void));
	
	void disconnectCallbackFromType(kMIDIType Type);
	
#endif // USE_CALLBACKS
	
	
private:
	
	bool input_filter(byte inChannel);
	bool parse(byte inChannel);
	void reset_input_attributes();
	
	// Attributes
	byte			mRunningStatus_RX;
	byte			mInputChannel;
	
	byte			mPendingMessage[MIDI_SYSEX_ARRAY_SIZE];
	unsigned int	mPendingMessageExpectedLenght;
	unsigned int	mPendingMessageIndex;					// Extended to unsigned int for larger sysex payloads.
	
	midimsg			mMessage;
	
#if USE_CALLBACKS
	
	void launchCallback();
	
	void (*mNoteOffCallback)(byte channel, byte note, byte velocity);
	void (*mNoteOnCallback)(byte channel, byte note, byte velocity);
	void (*mAfterTouchPolyCallback)(byte channel, byte note, byte velocity);
	void (*mControlChangeCallback)(byte channel, byte, byte);
	void (*mProgramChangeCallback)(byte channel, byte);
	void (*mAfterTouchChannelCallback)(byte channel, byte);
	void (*mPitchBendCallback)(byte channel, int);
	void (*mSystemExclusiveCallback)(byte * array, byte size);
	void (*mTimeCodeQuarterFrameCallback)(byte data);
	void (*mSongPositionCallback)(unsigned int beats);
	void (*mSongSelectCallback)(byte songnumber);
	void (*mTuneRequestCallback)(void);
	void (*mClockCallback)(void);
	void (*mStartCallback)(void);
	void (*mContinueCallback)(void);
	void (*mStopCallback)(void);
	void (*mActiveSensingCallback)(void);
	void (*mSystemResetCallback)(void);
	
#endif // USE_CALLBACKS
	
	
#endif // COMPILE_MIDI_IN
	

/* ####### THRU COMPILATION BLOCK ####### */
#if (COMPILE_MIDI_IN && COMPILE_MIDI_OUT && COMPILE_MIDI_THRU) // Thru
	
public:
	
	// Getters
	kThruFilterMode getFilterMode() const { return mThruFilterMode; }
	bool getThruState() const { return mThruActivated; }
	
	
	// Setters
	void turnThruOn(kThruFilterMode inThruFilterMode = Full);
	void turnThruOff();
	
	void setThruFilterMode(const kThruFilterMode inThruFilterMode);
	
	
private:
	
	void thru_filter(byte inChannel);
	
	bool				mThruActivated;
	kThruFilterMode		mThruFilterMode;
	
#endif // Thru
	
};

extern MIDI_BCR2000_Class MIDI_BCR2000;

#endif // LIB_MIDI_BCR2000_H_
