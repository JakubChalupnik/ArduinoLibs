#ifndef _Rf24PacketDefine_h
#define _Rf24PacketDefine_h

#if defined (__arm__)
#define PACKED __attribute__ ((__packed__)) 
#else
#define PACKED 
#endif

#define RF24_TYPE_TIME 0
#define RF24_TYPE_TEMP 1
#define RF24_TYPE_ID 2
#define RF24_TYPE_SOLAR 3

#define RF24_SENSOR_TYPE_TEMP 16
#define RF24_SENSOR_TYPE_METEO 17

#define F_SENSOR_NONE   0x0000
#define F_SENSOR_DS1820 0x0001
#define F_SENSOR_DS1822 0x0002
#define F_SENSOR_MASK   0x0007

#define F_BATTERY_NONE   0x0000
#define F_BATTERY_CR2032 0x0008
#define F_BATTERY_LIION  0x0010
#define F_BATTERY_SOLAR  0x0018
#define F_BATTERY_MASK 0x0018

#define F_BATTERY_DEAD 0x0020

#define NODE_ID_SIZE 10

#define RF24_SENSOR_PIPE ((uint8_t *) "SnSrS")
#define RF24_BROADCAST_PIPE ((uint8_t *) "BdCsT")
#define RF24_RADIO_CHANNEL 89
#define RF24_NETWORK_CHANNEL 90

typedef struct PACKED {
  uint8_t Raw [8];        // Raw payload, 8 bytes of something
} PayloadRaw_t;

typedef struct PACKED {
  uint8_t BattLevel;      // Battery voltage over 2V in 10s of mV - e.g. 3.3V is reported as 130
} PayloadDefault_t;

typedef struct PACKED {
  uint8_t BattLevel; 
  uint32_t Time;          // Time in standard Unix format
} PayloadTime_t;

typedef struct PACKED {
  uint8_t BattLevel;
  uint16_t Temperature[2];   // Up to two temperatures, reported in tenths of degrees. 0xFFFF means 'no temperature'
} PayloadTemperature_t;

typedef struct PACKED {
  uint8_t BattLevel;
  char Id[NODE_ID_SIZE];    // Node identification
  uint8_t Version;
  uint16_t Flags;
  uint16_t _padding;
} PayloadId_t;

typedef struct PACKED {
  uint8_t BattLevel;
  uint8_t SolarVoltage;    // Reported in tenths of volt
} PayloadSolar_t;

typedef union {
  PayloadDefault_t Default;
  PayloadTime_t Time;
  PayloadTemperature_t Temperature;
  PayloadRaw_t Raw;
} Payload_t;

typedef struct PACKED {
  uint8_t PacketType;
  uint8_t BattLevel;
  uint16_t Flags;
  uint16_t SensorId;
  uint16_t Temperature[2];   // Up to two temperatures, reported in tenths of degrees. 0xFFFF means 'no temperature'
} SensorPayloadTemperature_t;

 typedef struct PACKED {
  uint8_t PacketType;
  uint8_t BattLevel;
  uint8_t Humidity;
  uint8_t Flags;
  uint16_t SensorId;
  uint16_t Temperature;
  uint16_t Pressure;
} SensorPayloadMeteo_t;

#endif