// 0-9 en 7-Segment emulation
// adapted to use with Wire.h
// - remove all occurences of write(Adr) because included in Wire.beginTransmission
// - rewrite Clear() because cannt send 1024 bytes in once via Wire.write
//===============
#include <avr/pgmspace.h>

const unsigned char Digit48[] PROGMEM = {
// Digit 0  ,23 bytes per Oled Line, 6 Oled Lines
0x00, 0x00, 0x80, 0xFA, 0xFB, 0xF7, 0x77, 0x0F, 0x0F, 0x0F, 
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x83, 0xFD, 
0xFE, 0xFF, 0x7E, 
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
0xFF, 0xFF, 0x00, 
0x00, 0x80, 0xBF, 0x3F, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x3F, 
0x7F, 0x3F, 0x00, 
0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFE, 0xFE, 
0xFF, 0x00, 0x00, 
0x80, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF,
0x7F, 0x00, 0x00, 
0x2F, 0x6F, 0x6F, 0x77, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 
0x78, 0x78, 0x78, 0x78, 0x78, 0x70, 0x4F, 0x3F, 0x3F, 0x3F, 
0x00, 0x00, 0x00, 
// Digit 1
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFC, 
0xFE, 0xFF, 0x7E, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
0xFF, 0xFF, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x3F, 
0x7F, 0x3F, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFE, 0xFE, 
0xFF, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF,
0x7F, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x3F, 0x3F, 0x3F, 
0x00, 0x00, 0x00, 
// Digit 2
0x00, 0x00, 0x00, 0x02, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x83, 0xFD, 
0xFE, 0xFF, 0x7E, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
0xFF, 0xFF, 0x00, 
0x00, 0x80, 0x80, 0x00, 0xC0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xDF, 0x3F, 
0x7F, 0x3F, 0x00, 
0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0x01, 0x01, 0x01, 0x01, 0x01, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 
0x80, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 
0x2F, 0x6F, 0x6F, 0x77, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 
0x78, 0x78, 0x78, 0x78, 0x78, 0x70, 0x40, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 
// Digit 3
0x00, 0x00, 0x00, 0x02, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x83, 0xFD, 
0xFE, 0xFF, 0x7E, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
0xFF, 0xFF, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xDF, 0x3F, 
0x7F, 0x3F, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFD, 0xFE, 0xFE, 
0xFF, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF,
0x7F, 0x00, 0x00, 
0x20, 0x60, 0x60, 0x70, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 
0x78, 0x78, 0x78, 0x78, 0x78, 0x70, 0x4F, 0x3F, 0x3F, 0x3F, 
0x00, 0x00, 0x00, 
// Digit 4
0x00, 0x00, 0x80, 0xF8, 0xF8, 0xF0, 0x70, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFC, 
0xFE, 0xFF, 0x7E, 
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
0xFF, 0xFF, 0x00, 
0x00, 0x00, 0x3F, 0x3F, 0xDF, 0xEF, 0xE0, 0xE0, 0xE0, 0xE0, 
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xDF, 0x3F, 
0x7F, 0x3F, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFD, 0xFE, 0xFE, 
0xFF, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF,
0x7F, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x3F, 0x3F, 0x3F, 
0x00, 0x00, 0x00, 
// Digit 5
0x00, 0x00, 0x80, 0xFA, 0xFB, 0xF7, 0x77, 0x0F, 0x0F, 0x0F, 
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x03, 0x01, 
0x00, 0x00, 0x00, 
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 
0x00, 0x00, 0x3F, 0x3F, 0xDF, 0xEF, 0xE0, 0xE0, 0xE0, 0xE0, 
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0x00, 
0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFD, 0xFE, 0xFE, 
0xFF, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF,
0x7F, 0x00, 0x00, 
0x20, 0x60, 0x60, 0x70, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 
0x78, 0x78, 0x78, 0x78, 0x78, 0x70, 0x4F, 0x3F, 0x3F, 0x3F, 
0x00, 0x00, 0x00, 
// Digit 6
0x00, 0x00, 0x80, 0xFA, 0xFB, 0xF7, 0x77, 0x0F, 0x0F, 0x0F, 
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x03, 0x01, 
0x00, 0x00, 0x00, 
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 
0x00, 0x80, 0xBF, 0x3F, 0xDF, 0xEF, 0xE0, 0xE0, 0xE0, 0xE0, 
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0x00, 
0x00, 0x00, 0x00, 
0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0x01, 0x01, 0x01, 0x01, 0x01, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFD, 0xFE, 0xFE, 
0xFF, 0x00, 0x00, 
0x80, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF,
0x7F, 0x00, 0x00, 
0x2F, 0x6F, 0x6F, 0x77, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 
0x78, 0x78, 0x78, 0x78, 0x78, 0x70, 0x4F, 0x3F, 0x3F, 0x3F, 
0x00, 0x00, 0x00, 
// Digit 7
0x00, 0x00, 0x00, 0x02, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x83, 0xFD, 
0xFE, 0xFF, 0x7E, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
0xFF, 0xFF, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x3F, 
0x7F, 0x3F, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFE, 0xFE, 
0xFF, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF,
0x7F, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x3F, 0x3F, 0x3F, 
0x00, 0x00, 0x00, 
// Digit 8 
0x00, 0x00, 0x80, 0xFA, 0xFB, 0xF7, 0x77, 0x0F, 0x0F, 0x0F, 
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x83, 0xFD, 
0xFE, 0xFF, 0x7E, 
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
0xFF, 0xFF, 0x00, 
0x00, 0x80, 0xBF, 0x3F, 0xDF, 0xEF, 0xE0, 0xE0, 0xE0, 0xE0, 
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xDF, 0x3F, 
0x7F, 0x3F, 0x00, 
0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0x01, 0x01, 0x01, 0x01, 0x01, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFD, 0xFE, 0xFE, 
0xFF, 0x00, 0x00, 
0x80, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF,
0x7F, 0x00, 0x00, 
0x2F, 0x6F, 0x6F, 0x77, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 
0x78, 0x78, 0x78, 0x78, 0x78, 0x70, 0x4F, 0x3F, 0x3F, 0x3F, 
0x00, 0x00, 0x00, 
// Digit 9
0x00, 0x00, 0x80, 0xFA, 0xFB, 0xF7, 0x77, 0x0F, 0x0F, 0x0F, 
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x83, 0xFD, 
0xFE, 0xFF, 0x7E, 
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
0xFF, 0xFF, 0x00, 
0x00, 0x00, 0x3F, 0x3F, 0xDF, 0xEF, 0xE0, 0xE0, 0xE0, 0xE0, 
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xDF, 0x3F, 
0x7F, 0x3F, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFD, 0xFE, 0xFE, 
0xFF, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 
0x7F, 0x00, 0x00, 
0x20, 0x60, 0x60, 0x70, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 
0x78, 0x78, 0x78, 0x78, 0x78, 0x70, 0x4F, 0x3F, 0x3F, 0x3F, 
0x00, 0x00, 0x00, 
// minus - sign
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0x00, 
0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00,
//  Blank Digit  
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// Two vertical Dots
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0,
0xF0, 0xF0, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
};


const uint8_t taNum[] PROGMEM = {
  0x00,0x00,0x00,0x00, 0x00,0xc0,0xde,0x00, // space ! 
  0x03,0x00,0x03,0x00, 0x74,0x2f,0x74,0x2f, // " #
  0x2c,0x49,0xff,0x39, 0x43,0x33,0x6c,0x63, // $ %
  0x6e,0x59,0x19,0x26, 0x00,0x05,0x03,0x00, // & '
  0x1c,0x22,0x41,0x00, 0x00,0x41,0x22,0x1c, // ( )
  0x2a,0x1c,0x1c,0x2a, 0x08,0x3e,0x08,0x08, // * +
  0x00,0xa0,0x60,0x00, 0x08,0x08,0x08,0x08, // , -
  0x00,0xc0,0xc0,0x00, 0x03,0x0c,0x30,0xc0, // . / 
  0x3e,0x41,0x41,0x3e, 0x04,0x02,0x7f,0x00, // 0 1
  0x62,0x51,0x49,0x46, 0x22,0x41,0x49,0x36, // 2 3
  0x1c,0x12,0x79,0x10, 0x2f,0x49,0x49,0x31, // 4 5
  0x36,0x49,0x49,0x31, 0x41,0x31,0x0d,0x03, // 6 7
  0x36,0x49,0x49,0x36, 0x46,0x49,0x49,0x3e, // 8 9
  0x00,0x36,0x36,0x00, 0x00,0xd6,0x76,0x00, // : ;
  0x08,0x14,0x22,0x41, 0x24,0x24,0x24,0x24, // < = 
  0x41,0x22,0x14,0x08, 0x02,0xc1,0xd9,0x06}; // > ?
const uint8_t taMaj[] PROGMEM = {
  0x39,0x48,0x71,0x41,0x3e, 0x7e,0x11,0x11,0x11,0x7e, // @ A   
  0x7f,0x49,0x49,0x49,0x36, 0x3e,0x41,0x41,0x41,0x22, // B C
  0x7f,0x41,0x41,0x41,0x3e, 0x7f,0x49,0x49,0x41,0x41, // D,E
  0x7f,0x09,0x09,0x01,0x01, // F
  0x3e,0x41,0x49,0x49,0x3a, 0x7f,0x08,0x08,0x08,0x7f, // G,H
  0x00,0x00,0x7f,0x00,0x00, 0x21,0x41,0x41,0x41,0x3f, // I,J
  0x7f,0x08,0x14,0x22,0x41, 0x7f,0x40,0x40,0x40,0x40, // K,L
  0x7f,0x02,0x04,0x02,0x7f, 0x7f,0x04,0x08,0x10,0x7f, // M,N
  0x3e,0x41,0x41,0x41,0x3e, 0x7f,0x11,0x11,0x11,0x0e, // O,P
  0x3e,0x41,0x49,0x51,0x7e, 0x7f,0x09,0x11,0x29,0x46, // Q,R
  0x46,0x49,0x49,0x49,0x32, 0x01,0x01,0x7f,0x01,0x01, // S,T
  0x3f,0x40,0x40,0x40,0x3f, 0x07,0x18,0x60,0x18,0x07, // U,V
  0x1f,0x60,0x1e,0x60,0x1f, 0x63,0x14,0x08,0x14,0x63, // W,X
  0x07,0x04,0x78,0x04,0x07, 0x61,0x51,0x49,0x45,0x43, // Y,Z
  0x00,0x7f,0x41,0x41,0x00, 0x03,0x06,0x1c,0x30,0x60, // [ \
  0x00,0x41,0x41,0x7f,0x00, 0x04,0x02,0x01,0x02,0x04, // ] ^
  0x80,0x80,0x80,0x80,0x80}; // _
  
const uint8_t taMin [] PROGMEM = {
  0x00,0x03,0x06,0x00, 0x20,0x54,0x54,0x78, // ` a 0x38,0x44,0x44,0x7C,
  0x7f,0x44,0x44,0x38, 0x38,0x44,0x44,0x28, // b c
  0x38,0x44,0x44,0x7f, 0x38,0x54,0x54,0x58, // d e
  0x00,0xfe,0x09,0x08, 0x98,0xa4,0xa4,0x78, // f g
  0x7f,0x04,0x04,0x78, 0x00,0x7d,0x00,0x00, // h i
  0x40,0x80,0x80,0x7d, 0x7e,0x10,0x28,0x44, // j k
  0x00,0x3f,0x40,0x00, 0x7c,0x08,0x08,0x7c, // l m
  0x7c,0x04,0x04,0x78, 0x38,0x44,0x44,0x38, // n o
  0xfc,0x24,0x24,0x18, 0x38,0x44,0x44,0xf8, // p q
  0x7c,0x04,0x04,0x08, 0x48,0x54,0x54,0x24, // r s
  0x00,0x3f,0x44,0x04, 0x3c,0x40,0x40,0x7c, // t u
  0x1c,0x60,0x60,0x1c, 0x5c,0x20,0x20,0x5c, // v w
  0x64,0x18,0x18,0x64, 0x04,0x08,0x78,0x04, // x y
  0x64,0x54,0x4C,0x44, 0x08,0x08,0x36,0x41, // z {
  0x00,0x00,0xff,0x00, 0x41,0x36,0x08,0x08, // | }
  0x10,0x20,0x10,0x20, 0xff,0xff,0xff,0xff}; // ~ del
const uint8_t squar[] PROGMEM ={0xff,0x81,0x81,0x81,0x81,0x81,0x81,0xff};
const uint8_t smile[] PROGMEM = {0x3c,0x42,0x95,0xa5,0xa1,0xa1, 0xa5,0x95,0x42,0x3c};
const uint8_t sad  [] PROGMEM = {0x3c,0x42,0xc5,0xa5,0xa1,0xa1, 0xa5,0xc5,0x42,0x3c};
const uint8_t didel[] PROGMEM = {0x82,0xf2,0xfe,0xfe,0x8e,0x82,0xc2,0x3c,0x00, \
                              0xc0,0xf8,0xfd,0x3d,0x0d,0x00, \
                              0x82,0xf2,0xfe,0xfe,0x8e,0x82,0xc2,0x3c,0x00, \
                              0xc0,0xf8,0xfe,0xfe,0x96,0x92,0x82,0x02,0x00, \
                              0xc0,0xf8,0xfe,0xfe,0x86,0x80,0x80,0x80,0x80 };

//xxxxxxxxxxxxxxxxxxxxxx
//\prog: "OledPixBase.h"   170504
// Initialisation et fonctions de base
void  Clear();
byte taInitOled[]={ 0xae, 0xd5, 0x80, 0xa8, 63, \
        0xD3, 0x0, 0x40, 0x8d, 0x14, 0x20, 0x00, 0xa1, \
        0xc8, 0xDA, 0x12, 0x81, 0xcf, 0xd9, 0xf1, 0xdb, \
        0x40, 0xa4, 0xa6, 0x2e, 0xaf };
void  SetupOledPix () { 
  for (byte i=0; i<sizeof (taInitOled); i++) { 
    Start(); Write(0);
    Write (taInitOled[i]); Stop();
  }
  Clear();
}

void  WrStaData () {  
  Start(); Write(0x40);
}

void  WrStaCom () {  
  Start(); Write(0);
}

void  Cmd (byte cc) {  
  WrStaCom (); Write (cc); Stop();
}

byte taIniTr[]={Adr,0,0x21,0x0,0x7f,0x22,0x0,0x7F};

void  IniTransfert () {  
  for (byte i=0; i<sizeof (taIniTr); i++) { 
    WrStaCom ();
    Write (taIniTr[i]); Stop();
  } 
}

byte saveLi,saveCol;
void  SetLine (byte cc) { 
  saveLi=cc;
  cc--; if(cc<0) {cc=7;} 
  WrStaCom (); Write (0x22);
  Write (cc); Write (7); Stop();
}
void  SetCol (byte cc) {  
  WrStaCom (); Write (0x21);
  Write (cc); Write (127); Stop();
  saveCol=cc;
}
void  LiCol (byte li,byte co) { 
  SetLine (li); SetCol (co);
//  ptMap = (128*saveLi)+saveCol;
}



#define  Sprite(tt) \  
  WrStaData(); \
  for (byte i=0; i<sizeof tt; i++) { \
  Write (pgm_read_byte(&tt[i])); } Stop()
#define CopybMapRam(tt) \
  WrStaData(); \
  for (byte i=0; i<sizeof tt; i++) { \
  Write (tt[i]); } Write(0); Stop();
#define Copy(tt) \
  WrStaData(); \
  for (byte i=0; i<sizeof tt/4; i++) { \
   for (byte j=0; j<4; j++) {Write (pgm_read_byte(&tt[4*i+j]));} \
   Write (0); } Stop();
// Maj en 5 de large 
#define CopyMaj(tt) \
  WrStaData(); \
  for (byte i=0; i<sizeof tt/5; i++) { \
   for (byte j=0; j<5; j++) {Write (pgm_read_byte(&tt[5*i+j]));} \
   Write (0); } Stop();
   
//xxxxxxxxxxxxxxxxxxxxxxxxxx
//\prog: "OledCarPix.h" 170426
void Error();
void DoubleH () {Cmd (0xda);Cmd (0x02);}
void Car(char cc) {
  cc&=0x7F; 
  switch (cc/32) {
    case 0:
       if(cc=13) {SetLine(saveLi+1);SetCol(0);} // saut de ligne
     else Error();
       break;
    case 1:  // codes 32-
      Start(); Write (0x40);
      for (byte i=0; i<4; i++)
      { Write (pgm_read_byte(&taNum[((cc-32)*4)+i])); }
      Write (0); Stop(); 
          break;
     case 2:  // codes 64-
      Start(); Write (0x40);
      for (byte i=0; i<5; i++)
      { Write (pgm_read_byte(&taMaj[((cc-64)*5)+i])); }
      Write (0); Stop();
          break;
    case 3:  //codes 96-
      Start(); Write (0x40);
      for (byte i=0; i<4; i++)
      { Write (pgm_read_byte(&taMin[((cc-96)*4)+i])); }
      Write (0); Stop();
          break;
  }  // end switch
}
void Error() {
//  LiCol(0,100); Car('e');Car('r');Car('r');Car('o');Car('r');
}

// problem with sizeof tt ?
/* #define Text(tt) \
  for (byte i=0; i<sizeof tt; i++) \ 
  { Car (tt[i]);} */ 

//void Text(tt); 


     
#define BigText(tt) \
  for (byte i=0; i<sizeof tt; i++) \
  { Big (tt[i]); } 
  
//xxxxxxxxxxxxxxxxxxxxxxxxxxx
//\prog: OledNum.h  Avec zeros non significatifs
void Bin8 (byte bb) {
  for (byte i=0;i<8;i++) {
     if (bb&0x80) Car('1');
     else Car('0');
     bb <<= 1;
  }
  Car(' ');
}
char ConvNibble (byte nn) { // converti 4 bit hexa en Ascii
  byte cc;
  if (nn<10) {cc = nn + '0';}
  else {cc = nn-10 + 'a';}
  return cc;
}
void Hex8 (byte hh) {
  byte cc;
  cc = ConvNibble (hh >> 4) ; // ne modifie pas hh
  Car(cc);
  cc = ConvNibble (hh & 0x0F) ; 
  Car(cc);
  Car(' '); // space
}
void Hex16 (uint16_t hh) {
  byte cc;
  cc = ConvNibble (hh >> 12) ;   Car(cc);
  cc = ConvNibble ((hh >> 8)&0x0F) ; Car(cc);
  cc = ConvNibble ((hh >> 4)&0x0F) ; Car(cc);
  cc = ConvNibble (hh & 0x0F) ;   Car(cc);
  Car(' ');
}
void Hex12 (uint16_t hh) {
  byte cc=0;
  cc = ConvNibble ((hh >> 8)&0x0F) ; Car(cc);
  cc = ConvNibble ((hh >> 4)&0x0F) ; Car(cc);
  cc = ConvNibble (hh & 0x0F) ;   Car(cc);
  Car(' ');
}
uint16_t BinDec8 (uint8_t bb) {
  uint16_t dd=0;
   for (byte i=0; i<8; i++) {
    if ((dd & 0x0F)>0x04) {dd += 0x03;}
    if ((dd & 0xF0)>0x40) {dd += 0x30;}
    dd=dd<<1;
    if ((bb & 0x80)) {dd += 1;}  //inject bit
    bb=bb<<1; // prepare next bit
  }
  return dd;
}
void Dec8 (byte hh) {
  Hex12(BinDec8(hh));
}
uint16_t BinDec9999 (uint16_t bb) { //0x270F max
  uint16_t dd=0;
 for (byte i=0; i<16; i++) {
    if ((dd & 0x000F)>0x0004) {dd += 0x0003;}
    if ((dd & 0x00F0)>0x0040) {dd += 0x0030;}
    if ((dd & 0x0F00)>0x0400) {dd += 0x0300;}
    if ((dd & 0xF000)>0x4000) {dd += 0x3000;}
      dd=dd<<1;
      if ((bb & 0x8000)) {dd += 1; }  //inject bit
      bb<<=1; // prepare next bit
  }
  return dd;
}
void Dec9999 (uint16_t hh) {  // limit� � 0x2703
  if (hh>9999) { Car('?'); Car('?'); Car('?'); Car('?'); } 
  else Hex16(BinDec9999(hh));
}

void Hex16_2 (uint16_t hh) {
  byte cc;
  cc = ConvNibble (hh >> 12) ;   //Big(cc);
  cc = ConvNibble ((hh >> 8)&0x0F) ; //Big(cc);
  cc = ConvNibble ((hh >> 4)&0x0F) ; Car(cc);
  cc = ConvNibble (hh & 0x0F) ;   Car(cc);
  //Big(' ');
}

void Dec99 (uint16_t hh) {  // limité à 99
  if (hh>99) hh=99; 
  else Hex16_2(BinDec9999(hh));
}


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//\prog: "OledGraPix.h" 170426
void Dot(byte xx,byte yy) {  // yy 0-64 --> 0-7
      LiCol(yy/8,xx);
      WrStaData (); Write (1<<yy%8); Stop();
}
//ddot  2points superposés si (yy/8!=7)
// si =7 il faut agit sur le bit0 de la ligne suiv si !=7
void DDot(byte xx,byte yy) {  // yy0-64 --> 0-7
 byte tmp=(1<<yy%8);
 if (yy%8!=7) tmp+=(1<<(yy%8+1));
       LiCol(yy/8,xx);
      WrStaData (); Write (tmp); Stop();
}

void Hline (byte yy) {
  for (byte i=0; i<128; i++) { Dot(i,yy); }
}
void Vline (byte xx) {
  for (byte i=0; i<8; i++) { 
    LiCol (i,xx); 
    WrStaData (); Write (0xFF); Stop();
  } 
}  
#define vLine Vline
#define hLine Hline




#define BigCar(a) Big(a)  //ko
// digits 0-9 in 7-Segment  23 pixel wide X 6 Columns

void Big(byte cc) {
  
  cc&=0x7F; byte tmp,i,k;
  saveLi=saveLi-5; // sur 6 lignes
  SetLine (saveLi);
  for (byte l=0; l<6; l++){  // Digits 6 column high
   k=23; // taille pixels par digit
   
   for (byte i=0; i<k; i++) {
   
      tmp = pgm_read_byte(&Digit48[((cc-48)*138)+(l*23)+i]);
      
      // on écrit ce byte sur 1 colonne
      Start(); Write (0x40);
      Write (tmp); Stop();    
     
  } // end for i, write 1 line
  
  saveLi=saveLi+1; // next line
  SetLine (saveLi); SetCol(saveCol);
 } // end for l (6 lines)
 
  saveLi=saveLi-1; // restore after for l loop
  // inter-Digit spacing
  saveCol+=25;   // prepare for next char
  SetCol(saveCol);
}


void BigBin8 (byte bb) {
  for (byte i=0;i<8;i++) {
     if (bb&0x80) Big('1');
     else Big('0');
     bb <<= 1;
  }
  Big(' ');
}

void BigHex81 (byte hh) {
  byte cc;
  cc = ConvNibble (hh >> 4) ; // ne modifie pas hh
  //Big(cc);
  cc = ConvNibble (hh & 0x0F) ; 
  Big(cc); // display 1 digit only no space
  //Big(' '); // space
}

void BigHex8 (byte hh) {
  byte cc;
  cc = ConvNibble (hh >> 4) ; // ne modifie pas hh
  Big(cc);
  cc = ConvNibble (hh & 0x0F) ; 
  Big(cc);
  Big(' '); // space
}
void BigHex16 (uint16_t hh) {
  byte cc;
  cc = ConvNibble (hh >> 12) ;   Big(cc);
  cc = ConvNibble ((hh >> 8)&0x0F) ; Big(cc);
  cc = ConvNibble ((hh >> 4)&0x0F) ; Big(cc);
  cc = ConvNibble (hh & 0x0F) ;   Big(cc);
  //Big(' ');
}
void BigHex12 (uint16_t hh) {
  byte cc=0;
  cc = ConvNibble ((hh >> 8)&0x0F) ; Big(cc);
  cc = ConvNibble ((hh >> 4)&0x0F) ; Big(cc);
  cc = ConvNibble (hh & 0x0F) ;   Big(cc);
  Big(' ');
}

void BigDec8 (byte hh) { BigHex12(BinDec8(hh)); }

void BigDec9999 (uint16_t hh) {  // limité à 0x270F 
  if (hh>9999) { Big('?'); Big('?'); Big('?'); Big('?'); } 
  else BigHex16(BinDec9999(hh));
}

void BigHex16_2 (uint16_t hh) {
  byte cc;
  cc = ConvNibble (hh >> 12) ;   //Big(cc);
  cc = ConvNibble ((hh >> 8)&0x0F) ; //Big(cc);
  cc = ConvNibble ((hh >> 4)&0x0F) ; Big(cc);
  cc = ConvNibble (hh & 0x0F) ;   Big(cc);
  //Big(' ');
}

void BigDec99 (uint16_t hh) {  // limité à 99
  if (hh>99) hh=99; 
  else BigHex16_2(BinDec9999(hh));
}



void Text( String zz ) {
  char tt[zz.length()+1];
  zz.toCharArray(tt, zz.length() );
  for (byte i=0; i<zz.length(); i++)  Car (tt[i]);
}


void  Clear() {  //nn<128x8=1024
// can't send more then 32 byte via Wire.write()
// so use 8 empty Text lines to clear Display
    IniTransfert();
    WrStaData(); 
    //for (int i=0; i<2; i++) {  Write (0); }
    Stop();

for (int i=0; i<8; i++){
 LiCol(i,0);
 Text("                           ");}
}