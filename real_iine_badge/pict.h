
#define MATRIX_LINES  8

#define VERTICAL_MODE 0
#define HORIZONTAL_MODE 1

#define FORWARD_MODE 0
#define BACKWARD_MODE 1

static const uint8_t PROGMEM
  icons[][MATRIX_LINES] = {
  { B11111111,
    B11111111,
    B11011011,
    B11011011,
    B11111111,
    B10111101,
    B11000011,
    B11111111 },
  { B11111111,
    B11111111,
    B11011011,
    B11011011,
    B11111111,
    B10000001,
    B11000011,
    B11111111 },
  { B11111111,
    B11011011,
    B11011011,
    B11111111,
    B10000001,
    B10000001,
    B11000011,
    B11111111 },
  { B01100110,
    B01111110,
    B11111111,
    B11111111,
    B11111111,
    B01111110,
    B00111100,
    B00011000 },

  };

static const uint8_t PROGMEM
 numbertable[][MATRIX_LINES] = {
{0x00, 0x02, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02} ,   //00
{0x00, 0x02, 0x06, 0x02, 0x02, 0x02, 0x02, 0x02} ,   //01
{0x00, 0x07, 0x01, 0x01, 0x07, 0x04, 0x04, 0x07} ,   //02
{0x00, 0x07, 0x01, 0x01, 0x07, 0x01, 0x01, 0x07} ,   //03
{0x00, 0x05, 0x05, 0x05, 0x07, 0x01, 0x01, 0x01} ,   //04
{0x00, 0x07, 0x04, 0x04, 0x07, 0x01, 0x01, 0x07} ,   //05
{0x00, 0x07, 0x04, 0x04, 0x07, 0x05, 0x05, 0x07} ,   //06
{0x00, 0x07, 0x05, 0x01, 0x02, 0x02, 0x02, 0x02} ,   //07
{0x00, 0x07, 0x05, 0x05, 0x07, 0x05, 0x05, 0x07} ,   //08
{0x00, 0x07, 0x05, 0x05, 0x07, 0x01, 0x01, 0x07} ,   //09

{0x00, 0x22, 0x65, 0x25, 0x25, 0x25, 0x25, 0x22} ,   //10
{0x00, 0x22, 0x66, 0x22, 0x22, 0x22, 0x22, 0x22} ,   //11
{0x00, 0x27, 0x61, 0x21, 0x27, 0x24, 0x24, 0x27} ,   //12
{0x00, 0x27, 0x61, 0x21, 0x27, 0x21, 0x21, 0x27} ,   //13
{0x00, 0x25, 0x65, 0x25, 0x27, 0x21, 0x21, 0x21} ,   //14
{0x00, 0x27, 0x64, 0x24, 0x27, 0x21, 0x21, 0x27} ,   //15
{0x00, 0x27, 0x64, 0x24, 0x27, 0x25, 0x25, 0x27} ,   //16
{0x00, 0x27, 0x65, 0x21, 0x22, 0x22, 0x22, 0x22} ,   //17
{0x00, 0x27, 0x65, 0x25, 0x27, 0x25, 0x25, 0x27} ,   //18
{0x00, 0x27, 0x65, 0x25, 0x27, 0x21, 0x21, 0x27} ,   //19

{0x00, 0x72, 0x15, 0x15, 0x75, 0x45, 0x45, 0x72} ,   //20
{0x00, 0x72, 0x16, 0x12, 0x72, 0x42, 0x42, 0x72} ,   //21
{0x00, 0x77, 0x11, 0x11, 0x77, 0x44, 0x44, 0x77} ,   //22
{0x00, 0x77, 0x11, 0x11, 0x77, 0x41, 0x41, 0x77} ,   //23
{0x00, 0x75, 0x15, 0x15, 0x77, 0x41, 0x41, 0x71} ,   //24
{0x00, 0x77, 0x14, 0x14, 0x77, 0x41, 0x41, 0x77} ,   //25
{0x00, 0x77, 0x14, 0x14, 0x77, 0x45, 0x45, 0x77} ,   //26
{0x00, 0x77, 0x15, 0x11, 0x72, 0x42, 0x42, 0x72} ,   //27
{0x00, 0x77, 0x15, 0x15, 0x77, 0x45, 0x45, 0x77} ,   //28
{0x00, 0x77, 0x15, 0x15, 0x77, 0x41, 0x41, 0x77} ,   //29

{0x00, 0x72, 0x15, 0x15, 0x75, 0x15, 0x15, 0x72} ,   //30
{0x00, 0x72, 0x16, 0x12, 0x72, 0x12, 0x12, 0x72} ,   //31
{0x00, 0x77, 0x11, 0x11, 0x77, 0x14, 0x14, 0x77} ,   //32
{0x00, 0x77, 0x11, 0x11, 0x77, 0x11, 0x11, 0x77} ,   //33
{0x00, 0x75, 0x15, 0x15, 0x77, 0x11, 0x11, 0x71} ,   //34
{0x00, 0x77, 0x14, 0x14, 0x77, 0x11, 0x11, 0x77} ,   //35
{0x00, 0x77, 0x14, 0x14, 0x77, 0x15, 0x15, 0x77} ,   //36
{0x00, 0x77, 0x15, 0x11, 0x72, 0x12, 0x12, 0x72} ,   //37
{0x00, 0x77, 0x15, 0x15, 0x77, 0x15, 0x15, 0x77} ,   //38
{0x00, 0x77, 0x15, 0x15, 0x77, 0x11, 0x11, 0x77} ,   //39

{0x00, 0x52, 0x55, 0x55, 0x75, 0x15, 0x15, 0x12} ,   //40
{0x00, 0x52, 0x56, 0x52, 0x72, 0x12, 0x12, 0x12} ,   //41
{0x00, 0x57, 0x51, 0x51, 0x77, 0x14, 0x14, 0x17} ,   //42
{0x00, 0x57, 0x51, 0x51, 0x77, 0x11, 0x11, 0x17} ,   //43
{0x00, 0x55, 0x55, 0x55, 0x77, 0x11, 0x11, 0x11} ,   //44
{0x00, 0x57, 0x54, 0x54, 0x77, 0x11, 0x11, 0x17} ,   //45
{0x00, 0x57, 0x54, 0x54, 0x77, 0x15, 0x15, 0x17} ,   //46
{0x00, 0x57, 0x55, 0x51, 0x72, 0x12, 0x12, 0x12} ,   //47
{0x00, 0x57, 0x55, 0x55, 0x77, 0x15, 0x15, 0x17} ,   //48
{0x00, 0x57, 0x55, 0x55, 0x77, 0x11, 0x11, 0x17} ,   //49

{0x00, 0x72, 0x45, 0x45, 0x75, 0x15, 0x15, 0x72} ,   //50
{0x00, 0x72, 0x46, 0x42, 0x72, 0x12, 0x12, 0x72} ,   //51
{0x00, 0x77, 0x41, 0x41, 0x77, 0x14, 0x14, 0x77} ,   //52
{0x00, 0x77, 0x41, 0x41, 0x77, 0x11, 0x11, 0x77} ,   //53
{0x00, 0x75, 0x45, 0x45, 0x77, 0x11, 0x11, 0x71} ,   //54
{0x00, 0x77, 0x44, 0x44, 0x77, 0x11, 0x11, 0x77} ,   //55
{0x00, 0x77, 0x44, 0x44, 0x77, 0x15, 0x15, 0x77} ,   //56
{0x00, 0x77, 0x45, 0x41, 0x72, 0x12, 0x12, 0x72} ,   //57
{0x00, 0x77, 0x45, 0x45, 0x77, 0x15, 0x15, 0x77} ,   //58
{0x00, 0x77, 0x45, 0x45, 0x77, 0x11, 0x11, 0x77} ,   //59

{0x00, 0x72, 0x45, 0x45, 0x75, 0x55, 0x55, 0x72} ,   //60
{0x00, 0x72, 0x46, 0x42, 0x72, 0x52, 0x52, 0x72} ,   //61
{0x00, 0x77, 0x41, 0x41, 0x77, 0x54, 0x54, 0x77} ,   //62
{0x00, 0x77, 0x41, 0x41, 0x77, 0x51, 0x51, 0x77} ,   //63
{0x00, 0x75, 0x45, 0x45, 0x77, 0x51, 0x51, 0x71} ,   //64
{0x00, 0x77, 0x44, 0x44, 0x77, 0x51, 0x51, 0x77} ,   //65
{0x00, 0x77, 0x44, 0x44, 0x77, 0x55, 0x55, 0x77} ,   //66
{0x00, 0x77, 0x45, 0x41, 0x72, 0x52, 0x52, 0x72} ,   //67
{0x00, 0x77, 0x45, 0x45, 0x77, 0x55, 0x55, 0x77} ,   //68
{0x00, 0x77, 0x45, 0x45, 0x77, 0x51, 0x51, 0x77} ,   //69

{0x00, 0x72, 0x55, 0x15, 0x25, 0x25, 0x25, 0x22} ,   //70
{0x00, 0x72, 0x56, 0x12, 0x22, 0x22, 0x22, 0x22} ,   //71
{0x00, 0x77, 0x51, 0x11, 0x27, 0x24, 0x24, 0x27} ,   //72
{0x00, 0x77, 0x51, 0x11, 0x27, 0x21, 0x21, 0x27} ,   //73
{0x00, 0x75, 0x55, 0x15, 0x27, 0x21, 0x21, 0x21} ,   //74
{0x00, 0x77, 0x54, 0x14, 0x27, 0x21, 0x21, 0x27} ,   //75
{0x00, 0x77, 0x54, 0x14, 0x27, 0x25, 0x25, 0x27} ,   //76
{0x00, 0x77, 0x55, 0x11, 0x22, 0x22, 0x22, 0x22} ,   //77
{0x00, 0x77, 0x55, 0x15, 0x27, 0x25, 0x25, 0x27} ,   //78
{0x00, 0x77, 0x55, 0x15, 0x27, 0x21, 0x21, 0x27} ,   //79

{0x00, 0x72, 0x55, 0x55, 0x75, 0x55, 0x55, 0x72} ,   //80
{0x00, 0x72, 0x56, 0x52, 0x72, 0x52, 0x52, 0x72} ,   //81
{0x00, 0x77, 0x51, 0x51, 0x77, 0x54, 0x54, 0x77} ,   //82
{0x00, 0x77, 0x51, 0x51, 0x77, 0x51, 0x51, 0x77} ,   //83
{0x00, 0x75, 0x55, 0x55, 0x77, 0x51, 0x51, 0x71} ,   //84
{0x00, 0x77, 0x54, 0x54, 0x77, 0x51, 0x51, 0x77} ,   //85
{0x00, 0x77, 0x54, 0x54, 0x77, 0x55, 0x55, 0x77} ,   //86
{0x00, 0x77, 0x55, 0x51, 0x72, 0x52, 0x52, 0x72} ,   //87
{0x00, 0x77, 0x55, 0x55, 0x77, 0x55, 0x55, 0x77} ,   //88
{0x00, 0x77, 0x55, 0x55, 0x77, 0x51, 0x51, 0x77} ,   //89

{0x00, 0x72, 0x55, 0x55, 0x75, 0x15, 0x15, 0x72} ,   //90
{0x00, 0x72, 0x56, 0x52, 0x72, 0x12, 0x12, 0x72} ,   //91
{0x00, 0x77, 0x51, 0x51, 0x77, 0x14, 0x14, 0x77} ,   //92
{0x00, 0x77, 0x51, 0x51, 0x77, 0x11, 0x11, 0x77} ,   //93
{0x00, 0x75, 0x55, 0x55, 0x77, 0x11, 0x11, 0x71} ,   //94
{0x00, 0x77, 0x54, 0x54, 0x77, 0x11, 0x11, 0x77} ,   //95
{0x00, 0x77, 0x54, 0x54, 0x77, 0x15, 0x15, 0x77} ,   //96
{0x00, 0x77, 0x55, 0x51, 0x72, 0x12, 0x12, 0x72} ,   //97
{0x00, 0x77, 0x55, 0x55, 0x77, 0x15, 0x15, 0x77} ,   //98
{0x00, 0x77, 0x55, 0x55, 0x77, 0x11, 0x11, 0x77} ,   //99
{0x00, 0x66, 0xFD, 0xFD, 0xFB, 0x7E, 0x3C, 0x18} ,   //ハート(100)
{0x6A, 0xEA, 0xEE, 0x60, 0x67, 0x65, 0x67, 0xF4} ,   //1UP(101)


 };
