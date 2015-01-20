#ifndef _PacketDefine_h
#define _PacketDefine_h

#define RF12_NET_GROUP 5
#define RF12_NET_NODE 30
#define RF12_NET_NODE_METEO 3
#define RF12_NET_NODE_TIME 4
#define RF12_NET_NODE_CPU 5

#define RF12_PACKET_TIME 1
#define RF12_PACKET_METEO 2
#define RF12_PACKET_TEMPERATURE 3

typedef struct {
  uint8_t type;
  int16_t temp;
  int32_t pres;
  int dht_temp;
  int humidity;
} MeteoPayload_t;

typedef struct {
  uint8_t type;
  uint8_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t minute;
} TimePayload_t;

typedef struct {
  uint8_t type;
  uint16_t temp1;
  uint16_t temp2;
} TemperaturePayload_t;

#endif