#include <MaxMatrix.h>
#include <avr/pgmspace.h>

#define maxDisplays 5 // Number of MAX7219's in use.

byte Buf7219[7]; // "width,height,data[5]" single character buffer.
const int data  = 10;  // DIN or MOSI
const int load  = 9;   // CS
const int clock = 8;   // SCK

MaxMatrix m(data, load, clock, maxDisplays);

PROGMEM const unsigned char CH[] = {
3, 8, B0000000, B0000000, B0000000, B0000000, B0000000, // space
1, 8, B1011111, B0000000, B0000000, B0000000, B0000000, // !
3, 8, B0000011, B0000000, B0000011, B0000000, B0000000, // "
5, 8, B0010100, B0111110, B0010100, B0111110, B0010100, // #
4, 8, B0100100, B1101010, B0101011, B0010010, B0000000, // $
5, 8, B1100011, B0010011, B0001000, B1100100, B1100011, // %
5, 8, B0110110, B1001001, B1010110, B0100000, B1010000, // &
1, 8, B0000011, B0000000, B0000000, B0000000, B0000000, // '
3, 8, B0011100, B0100010, B1000001, B0000000, B0000000, // (
3, 8, B1000001, B0100010, B0011100, B0000000, B0000000, // )
5, 8, B0101000, B0011000, B0001110, B0011000, B0101000, // * 
5, 8, B0001000, B0001000, B0111110, B0001000, B0001000, // +
2, 8, B10110000, B1110000, B0000000, B0000000, B0000000, // ,
4, 8, B0001000, B0001000, B0001000, B0001000, B0000000, // -
2, 8, B1100000, B1100000, B0000000, B0000000, B0000000, // .
4, 8, B1100000, B0011000, B0000110, B0000001, B0000000, // /
4, 8, B0111110, B1000001, B1000001, B0111110, B0000000, // 0
3, 8, B1000010, B1111111, B1000000, B0000000, B0000000, // 1
4, 8, B1100010, B1010001, B1001001, B1000110, B0000000, // 2
4, 8, B0100010, B1000001, B1001001, B0110110, B0000000, // 3
4, 8, B0011000, B0010100, B0010010, B1111111, B0000000, // 4
4, 8, B0100111, B1000101, B1000101, B0111001, B0000000, // 5
4, 8, B0111110, B1001001, B1001001, B0110000, B0000000, // 6
4, 8, B1100001, B0010001, B0001001, B0000111, B0000000, // 7
4, 8, B0110110, B1001001, B1001001, B0110110, B0000000, // 8
4, 8, B0000110, B1001001, B1001001, B0111110, B0000000, // 9
2, 8, B0010100, B0000000, B0000000, B0000000, B0000000, // :
2, 8, B10000000, B01010000, B0000000, B0000000, B0000000, // ;
3, 8, B0010000, B0101000, B1000100, B0000000, B0000000, // <
3, 8, B0010100, B0010100, B0010100, B0000000, B0000000, // =
3, 8, B1000100, B0101000, B0010000, B0000000, B0000000, // >
4, 8, B0000010, B1011001, B0001001, B0000110, B0000000, // ?
5, 8, B0111110, B1001001, B1010101, B1011101, B0001110, // @
4, 8, B1111110, B0010001, B0010001, B1111110, B0000000, // A
4, 8, B1111111, B1001001, B1001001, B0110110, B0000000, // B
4, 8, B0111110, B1000001, B1000001, B0100010, B0000000, // C
4, 8, B1111111, B1000001, B1000001, B0111110, B0000000, // D
4, 8, B1111111, B1001001, B1001001, B1000001, B0000000, // E
4, 8, B1111111, B0001001, B0001001, B0000001, B0000000, // F
4, 8, B0111110, B1000001, B1001001, B1111010, B0000000, // G
4, 8, B1111111, B0001000, B0001000, B1111111, B0000000, // H
3, 8, B1000001, B1111111, B1000001, B0000000, B0000000, // I
4, 8, B0110000, B1000000, B1000001, B0111111, B0000000, // J
4, 8, B1111111, B0001000, B0010100, B1100011, B0000000, // K
4, 8, B1111111, B1000000, B1000000, B1000000, B0000000, // L
5, 8, B1111111, B0000010, B0001100, B0000010, B1111111, // M
5, 8, B1111111, B0000100, B0001000, B0010000, B1111111, // N
4, 8, B0111110, B1000001, B1000001, B0111110, B0000000, // O
4, 8, B1111111, B0001001, B0001001, B0000110, B0000000, // P
4, 8, B0111110, B1000001, B1000001, B10111110, B0000000, // Q
4, 8, B1111111, B0001001, B0001001, B1110110, B0000000, // R
4, 8, B1000110, B1001001, B1001001, B0110010, B0000000, // S
5, 8, B0000001, B0000001, B1111111, B0000001, B0000001, // T
4, 8, B0111111, B1000000, B1000000, B0111111, B0000000, // U
5, 8, B0001111, B0110000, B1000000, B0110000, B0001111, // V
5, 8, B0111111, B1000000, B0111000, B1000000, B0111111, // W
5, 8, B1100011, B0010100, B0001000, B0010100, B1100011, // X
5, 8, B0000111, B0001000, B1110000, B0001000, B0000111, // Y
4, 8, B1100001, B1010001, B1001001, B1000111, B0000000, // Z
2, 8, B1111111, B1000001, B0000000, B0000000, B0000000, // [
4, 8, B0000001, B0000110, B0011000, B1100000, B0000000, // backslash
2, 8, B1000001, B1111111, B0000000, B0000000, B0000000, // ]
3, 8, B0000010, B0000001, B0000010, B0000000, B0000000, // hat
4, 8, B1000000, B1000000, B1000000, B1000000, B0000000, // _
2, 8, B0000001, B0000010, B0000000, B0000000, B0000000, // 
4, 8, B0100000, B1010100, B1010100, B1111000, B0000000, // a
4, 8, B1111111, B1000100, B1000100, B0111000, B0000000, // b
4, 8, B0111000, B1000100, B1000100, B0000000, B0000000, // c // JFM MOD.
4, 8, B0111000, B1000100, B1000100, B1111111, B0000000, // d
4, 8, B0111000, B1010100, B1010100, B0011000, B0000000, // e
3, 8, B0000100, B1111110, B0000101, B0000000, B0000000, // f
4, 8, B10011000, B10100100, B10100100, B01111000, B0000000, // g
4, 8, B1111111, B0000100, B0000100, B1111000, B0000000, // h
3, 8, B1000100, B1111101, B1000000, B0000000, B0000000, // i
4, 8, B1000000, B10000000, B10000100, B1111101, B0000000, // j
4, 8, B1111111, B0010000, B0101000, B1000100, B0000000, // k
3, 8, B1000001, B1111111, B1000000, B0000000, B0000000, // l
5, 8, B1111100, B0000100, B1111100, B0000100, B1111000, // m
4, 8, B1111100, B0000100, B0000100, B1111000, B0000000, // n
4, 8, B0111000, B1000100, B1000100, B0111000, B0000000, // o
4, 8, B11111100, B0100100, B0100100, B0011000, B0000000, // p
4, 8, B0011000, B0100100, B0100100, B11111100, B0000000, // q
4, 8, B1111100, B0001000, B0000100, B0000100, B0000000, // r
4, 8, B1001000, B1010100, B1010100, B0100100, B0000000, // s
3, 8, B0000100, B0111111, B1000100, B0000000, B0000000, // t
4, 8, B0111100, B1000000, B1000000, B1111100, B0000000, // u
5, 8, B0011100, B0100000, B1000000, B0100000, B0011100, // v
5, 8, B0111100, B1000000, B0111100, B1000000, B0111100, // w
5, 8, B1000100, B0101000, B0010000, B0101000, B1000100, // x
4, 8, B10011100, B10100000, B10100000, B1111100, B0000000, // y
3, 8, B1100100, B1010100, B1001100, B0000000, B0000000, // z
3, 8, B0001000, B0110110, B1000001, B0000000, B0000000, // {
1, 8, B1111111, B0000000, B0000000, B0000000, B0000000, // |
3, 8, B1000001, B0110110, B0001000, B0000000, B0000000, // }
4, 8, B0001000, B0000100, B0001000, B0000100, B0000000, // ~
};

#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define REST   0

int tempo = 180; // Tempo hızını artırdım
int buzzer = 11;
int ledPins[] = {3, 4, 5, 6, 7}; // LED pinleri
int numLeds = 5;

int melody[] = {
    // Happy Birthday
    NOTE_C4,4, NOTE_C4,8,
    NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4,
    NOTE_E4,-2, NOTE_C4,4, NOTE_C4,8,
    NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4,
    NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8,

    NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4,
    NOTE_E4,-4, NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8,
    NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
    NOTE_F4,-2,
};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;
int currentLed = 0; // Hangi LED'in yanacağını takip etmek için

char string[] = "Your Word "; //edit text message 
char string2[] = "Your Word";

void setup() {
    pinMode(buzzer, OUTPUT);
    for (int i = 0; i < numLeds; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW); // Başlangıçta LED'leri kapalı tut
    }
    m.init();
    m.setIntensity(4); //change brightness
}

void loop() {
    int thisNote;
    for (thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
        divider = melody[thisNote + 1];
        if (divider > 0) {
            noteDuration = (wholenote) / divider;
        } else if (divider < 0) {
            noteDuration = (wholenote) / abs(divider);
            noteDuration *= 1.5;
        }

        tone(buzzer, melody[thisNote], noteDuration * 0.9);

        // LED'i aç
        digitalWrite(ledPins[currentLed], HIGH);
        delay(noteDuration / 2); // LED'in yanma süresi
        digitalWrite(ledPins[currentLed], LOW);

        // Bir sonraki LED'e geç
        currentLed = (currentLed + 1) % numLeds;

        delay(noteDuration / 2); // Notalar arasında bekleme süresi

        noTone(buzzer);
    }

    // 8x8 matris üzerinde metni göster
    m.shiftLeft(false, true);
    printStringWithShift(string, 50);  // Mesajı göster
    delay(1000);
    m.shiftLeft(false, true);
    printStringWithShift(string2, 50); // İkinci mesajı göster

    // Döngüyü bitir, şarkı bitmeden tekrar etmez
    while (true) {
        delay(1000); // Bu bölümde hiçbir şey yapmadan bekle
    }
}

// Put text on Display
void printCharWithShift(char c, int shift_speed) {
    if (c < 32) return;
    c -= 32;
    memcpy_P(Buf7219, CH + 7*c, 7);
    m.writeSprite(maxDisplays*8, 0, Buf7219);
    m.setColumn(maxDisplays*8 + Buf7219[0], 0);

    for (int i=0; i<=Buf7219[0]; i++) {
        delay(shift_speed);
        m.shiftLeft(false, false);
    }
}

void printStringWithShift(char* s, int shift_speed) {
    while (*s != 0) {
        printCharWithShift(*s, shift_speed);
        s++;
    }
}

