#ifndef _Rf24PacketDefine_h
#define _Rf24PacketDefine_h

#define RF24_CHANNEL 90

#define RF24_TYPE_TIME 0
#define RF24_TYPE_TEMP 1
#define RF24_TYPE_ID 2

#define F_SENSOR_NONE   0x0000
#define F_SENSOR_DS1820 0x0001
#define F_SENSOR_DS1822 0x0002
#define F_SENSOR_MASK   0x0007

#define F_BATTERY_NONE   0x0000
#define F_BATTERY_CR2032 0x0008
#define F_BATTERY_LIION  0x0010
#define F_BATTERY_MASK 0x0018

#define NODE_ID_SIZE 10

typedef struct {
  uint8_t Raw [8];    		// Raw payload, 8 bytes of something
} PayloadRaw_t;

typedef struct {
  uint8_t BattLevel;    	// Battery voltage over 2V in 10s of mV - e.g. 3.3V is reported as 130
} PayloadDefault_t;

typedef struct {
  uint8_t BattLevel; 
  uint32_t Time;        	// Time in standard Unix format
} PayloadTime_t;

typedef struct {
  uint8_t BattLevel;
  uint16_t Temperature[2];   // Up to two temperatures, reported in tenths of degrees. 0xFFFF means 'no temperature'
} PayloadTemperature_t;

typedef struct {
  uint8_t BattLevel;
  char Id[NODE_ID_SIZE];    // Node identification
  uint8_t Version;
  uint16_t Flags;
  uint16_t _padding;
} PayloadId_t;

typedef union {
  PayloadDefault_t Default;
  PayloadTime_t Time;
  PayloadTemperature_t Temperature;
  PayloadRaw_t Raw;
} Payload_t;

#endif