#ifndef ASCII_H_INCLUDED
#define ASCII_H_INCLUDED

typedef enum {
  alphanumeric = 1,
  punctuation = 2,
  control = 3,
  out_of_range = 4,
} ascii_subtype;

typedef struct {
  const char hex[3];
  const char type;
  const char name[4];
} ascii_element;

#ifdef __cplusplus
#define ASCII_CONSTEXPR constexpr
#else
#define ASCII_CONSTEXPR
#endif

__attribute__((unused)) static const char *ascii_char_to_name(char x);
__attribute__((unused)) static const char *ascii_char_to_hex(char x);
__attribute__((unused)) static ascii_subtype ascii_char_to_type(char x);

static ASCII_CONSTEXPR unsigned ascii_char_to_int(char x) {
  // x + 256 means it'll be >= 0 regardless of whether char is signed
  // unsigned mod is simpler, removes a branch
  int y = (int)x + 256;
  return ((unsigned)y % 256u);
}

#ifndef ASCII_TABLE_ENABLE
#define ASCII_TABLE_ENABLE 0
#endif

// The flat char array is compiler friendly. The array of structs
// further down in the file is easier to read.
static ASCII_CONSTEXPR const char ascii_stringtable[128 * 8 + 1] = {
    //
    "00\0\3"
    "NUL\0"
    "01\0\3"
    "SOH\0"
    "02\0\3"
    "STX\0"
    "03\0\3"
    "ETX\0"
    //
    "04\0\3"
    "EOT\0"
    "05\0\3"
    "ENQ\0"
    "06\0\3"
    "ACK\0"
    "07\0\3"
    "BEL\0"
    //
    "08\0\3"
    "BS\0\0"
    "09\0\3"
    "HT\0\0"
    "0a\0\3"
    "LF\0\0"
    "0b\0\3"
    "VT\0\0"
    //
    "0c\0\3"
    "FF\0\0"
    "0d\0\3"
    "CR\0\0"
    "0e\0\3"
    "SO\0\0"
    "0f\0\3"
    "SI\0\0"
    //
    "10\0\3"
    "DLE\0"
    "11\0\3"
    "DC1\0"
    "12\0\3"
    "DC2\0"
    "13\0\3"
    "DC3\0"
    //
    "14\0\3"
    "NAK\0"
    "15\0\3"
    "SYN\0"
    "16\0\3"
    "ETB\0"
    "17\0\3"
    "CAN\0"
    //
    "18\0\3"
    "EM\0\0"
    "19\0\3"
    "SUB\0"
    "1a\0\3"
    "ESC\0"
    "1b\0\3"
    "FS\0\0"
    //
    "1c\0\3"
    "GS\0\0"
    "1d\0\3"
    "CR\0\0"
    "1e\0\3"
    "RS\0\0"
    "1f\0\3"
    "US\0\0"
    //
    "20\0\2"
    "SP\0\0"
    "21\0\2"
    "!\0\0\0"
    "22\0\2"
    "\"\0\0\0"
    "23\0\2"
    "#\0\0\0"
    //
    "24\0\2"
    "$\0\0\0"
    "25\0\2"
    "%\0\0\0"
    "26\0\2"
    "&\0\0\0"
    "27\0\2"
    "'\0\0\0"
    //
    "28\0\2"
    "(\0\0\0"
    "29\0\2"
    ")\0\0\0"
    "2a\0\2"
    "*\0\0\0"
    "2b\0\2"
    "+\0\0\0"
    //
    "2c\0\2"
    ",\0\0\0"
    "2d\0\2"
    "-\0\0\0"
    "2e\0\2"
    ".\0\0\0"
    "2f\0\2"
    "/\0\0\0"
    //
    "30\0\1"
    "0\0\0\0"
    "31\0\1"
    "1\0\0\0"
    "32\0\1"
    "2\0\0\0"
    "33\0\1"
    "3\0\0\0"
    //
    "34\0\1"
    "4\0\0\0"
    "35\0\1"
    "5\0\0\0"
    "36\0\1"
    "6\0\0\0"
    "37\0\1"
    "7\0\0\0"
    //
    "38\0\1"
    "8\0\0\0"
    "39\0\1"
    "9\0\0\0"
    "3a\0\2"
    ":\0\0\0"
    "3b\0\2"
    ";\0\0\0"
    //
    "3c\0\2"
    "<\0\0\0"
    "3d\0\2"
    "=\0\0\0"
    "3e\0\2"
    ">\0\0\0"
    "3f\0\2"
    "?\0\0\0"
    //
    "40\0\2"
    "@\0\0\0"
    "41\0\1"
    "A\0\0\0"
    "42\0\1"
    "B\0\0\0"
    "43\0\1"
    "C\0\0\0"
    //
    "44\0\1"
    "D\0\0\0"
    "45\0\1"
    "E\0\0\0"
    "46\0\1"
    "F\0\0\0"
    "47\0\1"
    "G\0\0\0"
    //
    "48\0\1"
    "H\0\0\0"
    "49\0\1"
    "I\0\0\0"
    "4a\0\1"
    "J\0\0\0"
    "4b\0\1"
    "K\0\0\0"
    //
    "4c\0\1"
    "L\0\0\0"
    "4d\0\1"
    "M\0\0\0"
    "4e\0\1"
    "N\0\0\0"
    "4f\0\1"
    "O\0\0\0"
    //
    "50\0\1"
    "P\0\0\0"
    "51\0\1"
    "Q\0\0\0"
    "52\0\1"
    "R\0\0\0"
    "53\0\1"
    "S\0\0\0"
    //
    "54\0\1"
    "T\0\0\0"
    "55\0\1"
    "U\0\0\0"
    "56\0\1"
    "V\0\0\0"
    "57\0\1"
    "W\0\0\0"
    //
    "58\0\1"
    "X\0\0\0"
    "59\0\1"
    "Y\0\0\0"
    "5a\0\1"
    "Z\0\0\0"
    "5b\0\2"
    "[\0\0\0"
    //
    "5c\0\2"
    "\\\0\0\0"
    "5d\0\2"
    "]\0\0\0"
    "5e\0\2"
    "^\0\0\0"
    "5f\0\2"
    "_\0\0\0"
    //
    "60\0\2"
    "`\0\0\0"
    "61\0\1"
    "a\0\0\0"
    "62\0\1"
    "b\0\0\0"
    "63\0\1"
    "c\0\0\0"
    //
    "64\0\1"
    "d\0\0\0"
    "65\0\1"
    "e\0\0\0"
    "66\0\1"
    "f\0\0\0"
    "67\0\1"
    "g\0\0\0"
    //
    "68\0\1"
    "h\0\0\0"
    "69\0\1"
    "i\0\0\0"
    "6a\0\1"
    "j\0\0\0"
    "6b\0\1"
    "k\0\0\0"
    //
    "6c\0\1"
    "l\0\0\0"
    "6d\0\1"
    "m\0\0\0"
    "6e\0\1"
    "n\0\0\0"
    "6f\0\1"
    "o\0\0\0"
    //
    "70\0\1"
    "p\0\0\0"
    "71\0\1"
    "q\0\0\0"
    "72\0\1"
    "r\0\0\0"
    "73\0\1"
    "s\0\0\0"
    //
    "74\0\1"
    "t\0\0\0"
    "75\0\1"
    "u\0\0\0"
    "76\0\1"
    "v\0\0\0"
    "77\0\1"
    "w\0\0\0"
    //
    "78\0\1"
    "x\0\0\0"
    "79\0\1"
    "y\0\0\0"
    "7a\0\1"
    "z\0\0\0"
    "7b\0\2"
    "{\0\0\0"
    //
    "7c\0\2"
    "|\0\0\0"
    "7d\0\2"
    "}\0\0\0"
    "7e\0\2"
    "~\0\0\0"
    "7f\0\3"
    "DEL\0"};

static const char *ascii_stringtable_char_to_name(char x) {
  unsigned z = ascii_char_to_int(x);
  if (z < 128u) {
    return &ascii_stringtable[8 * z + 4];
  } else {
    return ascii_char_to_hex(x);
  }
}

static const char *ascii_stringtable_char_to_hex(char x) {
  unsigned z = ascii_char_to_int(x);
  if (z < 128u) {
    return &ascii_stringtable[8 * z];
  } else {
    static ASCII_CONSTEXPR const char higher[128 * 3 + 1] =
        "80\081\082\083\084\085\086\087\0"
        "88\089\08a\08b\08c\08d\08e\08f\0"
        "90\091\092\093\094\095\096\097\0"
        "98\099\09a\09b\09c\09d\09e\09f\0"
        "a0\0a1\0a2\0a3\0a4\0a5\0a6\0a7\0"
        "a8\0a9\0aa\0ab\0ac\0ad\0ae\0af\0"
        "b0\0b1\0b2\0b3\0b4\0b5\0b6\0b7\0"
        "b8\0b9\0ba\0bb\0bc\0bd\0be\0bf\0"
        "c0\0c1\0c2\0c3\0c4\0c5\0c6\0c7\0"
        "c8\0c9\0ca\0cb\0cc\0cd\0ce\0cf\0"
        "d0\0d1\0d2\0d3\0d4\0d5\0d6\0d7\0"
        "d8\0d9\0da\0db\0dc\0dd\0de\0df\0"
        "e0\0e1\0e2\0e3\0e4\0e5\0e6\0e7\0"
        "e8\0e9\0ea\0eb\0ec\0ed\0ee\0ef\0"
        "f0\0f1\0f2\0f3\0f4\0f5\0f6\0f7\0"
        "f8\0f9\0fa\0fb\0fc\0fd\0fe\0ff\0";

    return &higher[3 * (z - 128)];
  }
}

static ascii_subtype ascii_stringtable_char_to_type(char x) {
  unsigned z = ascii_char_to_int(x);
  if (z < 128u) {
    return (ascii_subtype)ascii_stringtable[z * 8 + 3];
  } else {
    return out_of_range;
  }
}

#if ASCII_TABLE_ENABLE
static ASCII_CONSTEXPR const ascii_element ascii_table[128] = {
    // [ 0 7 ]
    [0x00] = {{"00"}, control, {"NUL"}},
    [0x01] = {{"01"}, control, {"SOH"}},
    [0x02] = {{"02"}, control, {"STX"}},
    [0x03] = {{"03"}, control, {"ETX"}},
    [0x04] = {{"04"}, control, {"EOT"}},
    [0x05] = {{"05"}, control, {"ENQ"}},
    [0x06] = {{"06"}, control, {"ACK"}},
    [0x07] = {{"07"}, control, {"BEL"}},

    // [ 8 15 ]
    [0x08] = {{"08"}, control, {"BS"}},
    [0x09] = {{"09"}, control, {"HT"}},
    [0x0a] = {{"0a"}, control, {"LF"}},
    [0x0b] = {{"0b"}, control, {"VT"}},
    [0x0c] = {{"0c"}, control, {"FF"}},
    [0x0d] = {{"0d"}, control, {"CR"}},
    [0x0e] = {{"0e"}, control, {"SO"}},
    [0x0f] = {{"0f"}, control, {"SI"}},

    // [ 16 23 ]
    [0x10] = {{"10"}, control, {"DLE"}},
    [0x11] = {{"11"}, control, {"DC1"}},
    [0x12] = {{"12"}, control, {"DC2"}},
    [0x13] = {{"13"}, control, {"DC3"}},
    [0x14] = {{"14"}, control, {"NAK"}},
    [0x15] = {{"15"}, control, {"SYN"}},
    [0x16] = {{"16"}, control, {"ETB"}},
    [0x17] = {{"17"}, control, {"CAN"}},

    // [ 24 31 ]
    [0x18] = {{"18"}, control, {"EM"}},
    [0x19] = {{"19"}, control, {"SUB"}},
    [0x1a] = {{"1a"}, control, {"ESC"}},
    [0x1b] = {{"1b"}, control, {"FS"}},
    [0x1c] = {{"1c"}, control, {"GS"}},
    [0x1d] = {{"1d"}, control, {"CR"}},
    [0x1e] = {{"1e"}, control, {"RS"}},
    [0x1f] = {{"1f"}, control, {"US"}},

    // [ 32 47 ]
    [0x20] = {{"20"}, punctuation, {"SP"}},
    [0x21] = {{"21"}, punctuation, {"!"}},
    [0x22] = {{"22"}, punctuation, {"\""}},
    [0x23] = {{"23"}, punctuation, {"#"}},
    [0x24] = {{"24"}, punctuation, {"$"}},
    [0x25] = {{"25"}, punctuation, {"%"}},
    [0x26] = {{"26"}, punctuation, {"&"}},
    [0x27] = {{"27"}, punctuation, {"'"}},

    // [ 40 47 ]
    [0x28] = {{"28"}, punctuation, {"("}},
    [0x29] = {{"29"}, punctuation, {")"}},
    [0x2a] = {{"2a"}, punctuation, {"*"}},
    [0x2b] = {{"2b"}, punctuation, {"+"}},
    [0x2c] = {{"2c"}, punctuation, {","}},
    [0x2d] = {{"2d"}, punctuation, {"-"}},
    [0x2e] = {{"2e"}, punctuation, {"."}},
    [0x2f] = {{"2f"}, punctuation, {"/"}},

    // [ 48 55 ]
    [0x30] = {{"30"}, alphanumeric, {"0"}},
    [0x31] = {{"31"}, alphanumeric, {"1"}},
    [0x32] = {{"32"}, alphanumeric, {"2"}},
    [0x33] = {{"33"}, alphanumeric, {"3"}},
    [0x34] = {{"34"}, alphanumeric, {"4"}},
    [0x35] = {{"35"}, alphanumeric, {"5"}},
    [0x36] = {{"36"}, alphanumeric, {"6"}},
    [0x37] = {{"37"}, alphanumeric, {"7"}},

    // [ 56 63 ]
    [0x38] = {{"38"}, alphanumeric, {"8"}},
    [0x39] = {{"39"}, alphanumeric, {"9"}},
    [0x3a] = {{"3a"}, punctuation, {":"}},
    [0x3b] = {{"3b"}, punctuation, {";"}},
    [0x3c] = {{"3c"}, punctuation, {"<"}},
    [0x3d] = {{"3d"}, punctuation, {"="}},
    [0x3e] = {{"3e"}, punctuation, {">"}},
    [0x3f] = {{"3f"}, punctuation, {"?"}},

    // [ 64 71 ]
    [0x40] = {{"40"}, punctuation, {"@"}},
    [0x41] = {{"41"}, alphanumeric, {"A"}},
    [0x42] = {{"42"}, alphanumeric, {"B"}},
    [0x43] = {{"43"}, alphanumeric, {"C"}},
    [0x44] = {{"44"}, alphanumeric, {"D"}},
    [0x45] = {{"45"}, alphanumeric, {"E"}},
    [0x46] = {{"46"}, alphanumeric, {"F"}},
    [0x47] = {{"47"}, alphanumeric, {"G"}},

    // [ 72 79 ]
    [0x48] = {{"48"}, alphanumeric, {"H"}},
    [0x49] = {{"49"}, alphanumeric, {"I"}},
    [0x4a] = {{"4a"}, alphanumeric, {"J"}},
    [0x4b] = {{"4b"}, alphanumeric, {"K"}},
    [0x4c] = {{"4c"}, alphanumeric, {"L"}},
    [0x4d] = {{"4d"}, alphanumeric, {"M"}},
    [0x4e] = {{"4e"}, alphanumeric, {"N"}},
    [0x4f] = {{"4f"}, alphanumeric, {"O"}},

    // [ 80 87 ]
    [0x50] = {{"50"}, alphanumeric, {"P"}},
    [0x51] = {{"51"}, alphanumeric, {"Q"}},
    [0x52] = {{"52"}, alphanumeric, {"R"}},
    [0x53] = {{"53"}, alphanumeric, {"S"}},
    [0x54] = {{"54"}, alphanumeric, {"T"}},
    [0x55] = {{"55"}, alphanumeric, {"U"}},
    [0x56] = {{"56"}, alphanumeric, {"V"}},
    [0x57] = {{"57"}, alphanumeric, {"W"}},

    // [ 88 95 ]
    [0x58] = {{"58"}, alphanumeric, {"X"}},
    [0x59] = {{"59"}, alphanumeric, {"Y"}},
    [0x5a] = {{"5a"}, alphanumeric, {"Z"}},
    [0x5b] = {{"5b"}, punctuation, {"["}},
    [0x5c] = {{"5c"}, punctuation, {"\\"}},
    [0x5d] = {{"5d"}, punctuation, {"]"}},
    [0x5e] = {{"5e"}, punctuation, {"^"}},
    [0x5f] = {{"5f"}, punctuation, {"_"}},

    // [ 96 103 ]
    [0x60] = {{"60"}, punctuation, {"`"}},
    [0x61] = {{"61"}, alphanumeric, {"a"}},
    [0x62] = {{"62"}, alphanumeric, {"b"}},
    [0x63] = {{"63"}, alphanumeric, {"c"}},
    [0x64] = {{"64"}, alphanumeric, {"d"}},
    [0x65] = {{"65"}, alphanumeric, {"e"}},
    [0x66] = {{"66"}, alphanumeric, {"f"}},
    [0x67] = {{"67"}, alphanumeric, {"g"}},

    // [ 104 111 ]
    [0x68] = {{"68"}, alphanumeric, {"h"}},
    [0x69] = {{"69"}, alphanumeric, {"i"}},
    [0x6a] = {{"6a"}, alphanumeric, {"j"}},
    [0x6b] = {{"6b"}, alphanumeric, {"k"}},
    [0x6c] = {{"6c"}, alphanumeric, {"l"}},
    [0x6d] = {{"6d"}, alphanumeric, {"m"}},
    [0x6e] = {{"6e"}, alphanumeric, {"n"}},
    [0x6f] = {{"6f"}, alphanumeric, {"o"}},

    // [ 112 119 ]
    [0x70] = {{"70"}, alphanumeric, {"p"}},
    [0x71] = {{"71"}, alphanumeric, {"q"}},
    [0x72] = {{"72"}, alphanumeric, {"r"}},
    [0x73] = {{"73"}, alphanumeric, {"s"}},
    [0x74] = {{"74"}, alphanumeric, {"t"}},
    [0x75] = {{"75"}, alphanumeric, {"u"}},
    [0x76] = {{"76"}, alphanumeric, {"v"}},
    [0x77] = {{"77"}, alphanumeric, {"w"}},

    // [ 120 127 ]
    [0x78] = {{"78"}, alphanumeric, {"x"}},
    [0x79] = {{"79"}, alphanumeric, {"y"}},
    [0x7a] = {{"7a"}, alphanumeric, {"z"}},
    [0x7b] = {{"7b"}, punctuation, {"{"}},
    [0x7c] = {{"7c"}, punctuation, {"|"}},
    [0x7d] = {{"7d"}, punctuation, {"}"}},
    [0x7e] = {{"7e"}, punctuation, {"~"}},
    [0x7f] = {{"7f"}, control, {"DEL"}},
};

static const char *ascii_table_char_to_name(char x) {
  unsigned z = ascii_char_to_int(x);
  if (z < 128u) {
    return ascii_table[z].name;
  } else {
    return ascii_char_to_hex(x);
  }
}

static const char *ascii_table_char_to_hex(char x) {
  unsigned z = ascii_char_to_int(x);
  if (z < 128u) {
    return ascii_table[z].hex;
  } else {
    static ASCII_CONSTEXPR const char higher[128 * 3 + 1] =
        "80\081\082\083\084\085\086\087\0"
        "88\089\08a\08b\08c\08d\08e\08f\0"
        "90\091\092\093\094\095\096\097\0"
        "98\099\09a\09b\09c\09d\09e\09f\0"
        "a0\0a1\0a2\0a3\0a4\0a5\0a6\0a7\0"
        "a8\0a9\0aa\0ab\0ac\0ad\0ae\0af\0"
        "b0\0b1\0b2\0b3\0b4\0b5\0b6\0b7\0"
        "b8\0b9\0ba\0bb\0bc\0bd\0be\0bf\0"
        "c0\0c1\0c2\0c3\0c4\0c5\0c6\0c7\0"
        "c8\0c9\0ca\0cb\0cc\0cd\0ce\0cf\0"
        "d0\0d1\0d2\0d3\0d4\0d5\0d6\0d7\0"
        "d8\0d9\0da\0db\0dc\0dd\0de\0df\0"
        "e0\0e1\0e2\0e3\0e4\0e5\0e6\0e7\0"
        "e8\0e9\0ea\0eb\0ec\0ed\0ee\0ef\0"
        "f0\0f1\0f2\0f3\0f4\0f5\0f6\0f7\0"
        "f8\0f9\0fa\0fb\0fc\0fd\0fe\0ff\0";

    return &higher[3 * (z - 128)];
  }
}

static ascii_subtype ascii_table_char_to_type(char x) {
  unsigned z = ascii_char_to_int(x);
  char lookup = ascii_table[z % 128u].type;
  if (z < 128u) {
    return (ascii_subtype)lookup;
  } else {
    return out_of_range;
  }
}

#endif

__attribute__((unused)) static const char *ascii_char_to_name(char x) {
  return ascii_stringtable_char_to_name(x);
}
__attribute__((unused)) static const char *ascii_char_to_hex(char x) {
  return ascii_stringtable_char_to_hex(x);
}
__attribute__((unused)) static ascii_subtype ascii_char_to_type(char x) {
  return ascii_stringtable_char_to_type(x);
}

#endif
