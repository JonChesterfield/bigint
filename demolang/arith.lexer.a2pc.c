// regex 0 = (:(:6164)64)
// regex 1 = (:(:7375)62)
// regex 2 = (:(:6d75)6c)
// regex 3 = (:(:6469)76)
// regex 4 = (:(:7265)6d)
// regex 5 = (:6f72)
// regex 6 = (:(:616e)64)
// regex 7 = (:(:786f)72)
// regex 8 = (:(:6162)73)
// regex 9 = (:(:6e65)67)
// regex 10 = (:(:696e)63)
// regex 11 = (:(:6465)63)
// regex 12 = (:(|2d_)(:(|(|(|(|(|(|(|(|(|3031)32)33)34)35)36)37)38)39)(*(|(|(|(|(|(|(|(|(|3031)32)33)34)35)36)37)38)39))))
// regex 13 = 28
// regex 14 = 29
// regex 15 = (:(|(|(|(|(|200c)0a)0d)09)0b)(*(|(|(|(|(|200c)0a)0d)09)0b)))
// regex 16 = (|(&.(~0a))0a)
// a2pc arith lexer implementation
#include "arith.lexer.h"
#if LEXER_A2PC_ENABLE
// Lexer arity 17
// Using 89 states

#include <stdbool.h>
#include <stdint.h>
#define MUSTTAIL __attribute__((musttail))

static lexer_match_t result_value(uint64_t active, uint64_t width)
{
  bool success = (active != 17);
  uint64_t adjusted = (active + 1) % UINT64_C(17);
  if (!success) width = 1;
  if (width == 0) width = 1;
  return (lexer_match_t) {.regex_id = adjusted, .bytes_count = width,};
}
typedef const unsigned char byte;
static lexer_match_t state_0(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_1(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_2(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_3(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_4(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_5(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_6(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_7(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_8(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_9(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_10(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_11(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_12(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_13(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_14(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_15(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_16(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_17(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_18(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_19(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_20(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_21(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_22(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_23(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_24(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_25(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_26(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_27(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_28(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_29(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_30(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_31(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_32(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_33(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_34(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_35(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_36(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_37(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_38(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_39(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_40(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_41(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_42(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_43(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_44(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_45(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_46(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_47(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_48(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_49(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_50(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_51(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_52(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_53(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_54(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_55(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_56(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_57(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_58(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_59(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_60(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_61(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_62(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_63(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_64(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_65(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_66(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_67(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_68(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_69(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_70(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_71(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_72(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_73(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_74(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_75(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_76(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_77(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_78(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_79(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_80(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_81(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_82(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_83(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_84(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_85(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_86(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_87(uint64_t, byte *, byte *, byte *);
static lexer_match_t state_88(uint64_t, byte *, byte *, byte *);

lexer_match_t state_0(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] (:61(:6464))
  // regex[1] (:73(:7562))
  // regex[2] (:6d(:756c))
  // regex[3] (:64(:6976))
  // regex[4] (:72(:656d))
  // regex[5] (:6f72)
  // regex[6] (:61(:6e64))
  // regex[7] (:78(:6f72))
  // regex[8] (:61(:6273))
  // regex[9] (:6e(:6567))
  // regex[10] (:69(:6e63))
  // regex[11] (:64(:6563))
  // regex[12] (:(|_2d)(:(|(|(|(|(|3637)(|3839))(|3435))(|3233))(|3031))(*(|(|(|(|(|3637)(|3839))(|3435))(|3233))(|3031)))))
  // regex[13] 28
  // regex[14] 29
  // regex[15] (:(|(|(|090d)(|0b20))(|0a0c))(*(|(|(|090d)(|0b20))(|0a0c))))
  // regex[16] (|(&.(~0a))0a)
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_18(a, s, c, e);
    case 1: MUSTTAIL return state_18(a, s, c, e);
    case 2: MUSTTAIL return state_18(a, s, c, e);
    case 3: MUSTTAIL return state_18(a, s, c, e);
    case 4: MUSTTAIL return state_18(a, s, c, e);
    case 5: MUSTTAIL return state_18(a, s, c, e);
    case 6: MUSTTAIL return state_18(a, s, c, e);
    case 7: MUSTTAIL return state_18(a, s, c, e);
    case 8: MUSTTAIL return state_18(a, s, c, e);
    case 9: MUSTTAIL return state_19(a, s, c, e);
    case 10: MUSTTAIL return state_20(a, s, c, e);
    case 11: MUSTTAIL return state_19(a, s, c, e);
    case 12: MUSTTAIL return state_19(a, s, c, e);
    case 13: MUSTTAIL return state_19(a, s, c, e);
    case 14: MUSTTAIL return state_18(a, s, c, e);
    case 15: MUSTTAIL return state_18(a, s, c, e);
    case 16: MUSTTAIL return state_18(a, s, c, e);
    case 17: MUSTTAIL return state_18(a, s, c, e);
    case 18: MUSTTAIL return state_18(a, s, c, e);
    case 19: MUSTTAIL return state_18(a, s, c, e);
    case 20: MUSTTAIL return state_18(a, s, c, e);
    case 21: MUSTTAIL return state_18(a, s, c, e);
    case 22: MUSTTAIL return state_18(a, s, c, e);
    case 23: MUSTTAIL return state_18(a, s, c, e);
    case 24: MUSTTAIL return state_18(a, s, c, e);
    case 25: MUSTTAIL return state_18(a, s, c, e);
    case 26: MUSTTAIL return state_18(a, s, c, e);
    case 27: MUSTTAIL return state_18(a, s, c, e);
    case 28: MUSTTAIL return state_18(a, s, c, e);
    case 29: MUSTTAIL return state_18(a, s, c, e);
    case 30: MUSTTAIL return state_18(a, s, c, e);
    case 31: MUSTTAIL return state_18(a, s, c, e);
    case 32: MUSTTAIL return state_19(a, s, c, e);
    case 33: MUSTTAIL return state_18(a, s, c, e);
    case 34: MUSTTAIL return state_18(a, s, c, e);
    case 35: MUSTTAIL return state_18(a, s, c, e);
    case 36: MUSTTAIL return state_18(a, s, c, e);
    case 37: MUSTTAIL return state_18(a, s, c, e);
    case 38: MUSTTAIL return state_18(a, s, c, e);
    case 39: MUSTTAIL return state_18(a, s, c, e);
    case 40: MUSTTAIL return state_21(a, s, c, e);
    case 41: MUSTTAIL return state_22(a, s, c, e);
    case 42: MUSTTAIL return state_18(a, s, c, e);
    case 43: MUSTTAIL return state_18(a, s, c, e);
    case 44: MUSTTAIL return state_18(a, s, c, e);
    case 45: MUSTTAIL return state_23(a, s, c, e);
    case 46: MUSTTAIL return state_18(a, s, c, e);
    case 47: MUSTTAIL return state_18(a, s, c, e);
    case 48: MUSTTAIL return state_24(a, s, c, e);
    case 49: MUSTTAIL return state_24(a, s, c, e);
    case 50: MUSTTAIL return state_24(a, s, c, e);
    case 51: MUSTTAIL return state_24(a, s, c, e);
    case 52: MUSTTAIL return state_24(a, s, c, e);
    case 53: MUSTTAIL return state_24(a, s, c, e);
    case 54: MUSTTAIL return state_24(a, s, c, e);
    case 55: MUSTTAIL return state_24(a, s, c, e);
    case 56: MUSTTAIL return state_24(a, s, c, e);
    case 57: MUSTTAIL return state_24(a, s, c, e);
    case 58: MUSTTAIL return state_18(a, s, c, e);
    case 59: MUSTTAIL return state_18(a, s, c, e);
    case 60: MUSTTAIL return state_18(a, s, c, e);
    case 61: MUSTTAIL return state_18(a, s, c, e);
    case 62: MUSTTAIL return state_18(a, s, c, e);
    case 63: MUSTTAIL return state_18(a, s, c, e);
    case 64: MUSTTAIL return state_18(a, s, c, e);
    case 65: MUSTTAIL return state_18(a, s, c, e);
    case 66: MUSTTAIL return state_18(a, s, c, e);
    case 67: MUSTTAIL return state_18(a, s, c, e);
    case 68: MUSTTAIL return state_18(a, s, c, e);
    case 69: MUSTTAIL return state_18(a, s, c, e);
    case 70: MUSTTAIL return state_18(a, s, c, e);
    case 71: MUSTTAIL return state_18(a, s, c, e);
    case 72: MUSTTAIL return state_18(a, s, c, e);
    case 73: MUSTTAIL return state_18(a, s, c, e);
    case 74: MUSTTAIL return state_18(a, s, c, e);
    case 75: MUSTTAIL return state_18(a, s, c, e);
    case 76: MUSTTAIL return state_18(a, s, c, e);
    case 77: MUSTTAIL return state_18(a, s, c, e);
    case 78: MUSTTAIL return state_18(a, s, c, e);
    case 79: MUSTTAIL return state_18(a, s, c, e);
    case 80: MUSTTAIL return state_18(a, s, c, e);
    case 81: MUSTTAIL return state_18(a, s, c, e);
    case 82: MUSTTAIL return state_18(a, s, c, e);
    case 83: MUSTTAIL return state_18(a, s, c, e);
    case 84: MUSTTAIL return state_18(a, s, c, e);
    case 85: MUSTTAIL return state_18(a, s, c, e);
    case 86: MUSTTAIL return state_18(a, s, c, e);
    case 87: MUSTTAIL return state_18(a, s, c, e);
    case 88: MUSTTAIL return state_18(a, s, c, e);
    case 89: MUSTTAIL return state_18(a, s, c, e);
    case 90: MUSTTAIL return state_18(a, s, c, e);
    case 91: MUSTTAIL return state_18(a, s, c, e);
    case 92: MUSTTAIL return state_18(a, s, c, e);
    case 93: MUSTTAIL return state_18(a, s, c, e);
    case 94: MUSTTAIL return state_18(a, s, c, e);
    case 95: MUSTTAIL return state_18(a, s, c, e);
    case 96: MUSTTAIL return state_18(a, s, c, e);
    case 97: MUSTTAIL return state_25(a, s, c, e);
    case 98: MUSTTAIL return state_18(a, s, c, e);
    case 99: MUSTTAIL return state_18(a, s, c, e);
    case 100: MUSTTAIL return state_26(a, s, c, e);
    case 101: MUSTTAIL return state_18(a, s, c, e);
    case 102: MUSTTAIL return state_18(a, s, c, e);
    case 103: MUSTTAIL return state_18(a, s, c, e);
    case 104: MUSTTAIL return state_18(a, s, c, e);
    case 105: MUSTTAIL return state_27(a, s, c, e);
    case 106: MUSTTAIL return state_18(a, s, c, e);
    case 107: MUSTTAIL return state_18(a, s, c, e);
    case 108: MUSTTAIL return state_18(a, s, c, e);
    case 109: MUSTTAIL return state_28(a, s, c, e);
    case 110: MUSTTAIL return state_29(a, s, c, e);
    case 111: MUSTTAIL return state_30(a, s, c, e);
    case 112: MUSTTAIL return state_18(a, s, c, e);
    case 113: MUSTTAIL return state_18(a, s, c, e);
    case 114: MUSTTAIL return state_31(a, s, c, e);
    case 115: MUSTTAIL return state_32(a, s, c, e);
    case 116: MUSTTAIL return state_18(a, s, c, e);
    case 117: MUSTTAIL return state_18(a, s, c, e);
    case 118: MUSTTAIL return state_18(a, s, c, e);
    case 119: MUSTTAIL return state_18(a, s, c, e);
    case 120: MUSTTAIL return state_33(a, s, c, e);
    case 121: MUSTTAIL return state_18(a, s, c, e);
    case 122: MUSTTAIL return state_18(a, s, c, e);
    case 123: MUSTTAIL return state_18(a, s, c, e);
    case 124: MUSTTAIL return state_18(a, s, c, e);
    case 125: MUSTTAIL return state_18(a, s, c, e);
    case 126: MUSTTAIL return state_18(a, s, c, e);
    case 127: MUSTTAIL return state_18(a, s, c, e);
    case 128: MUSTTAIL return state_18(a, s, c, e);
    case 129: MUSTTAIL return state_18(a, s, c, e);
    case 130: MUSTTAIL return state_18(a, s, c, e);
    case 131: MUSTTAIL return state_18(a, s, c, e);
    case 132: MUSTTAIL return state_18(a, s, c, e);
    case 133: MUSTTAIL return state_18(a, s, c, e);
    case 134: MUSTTAIL return state_18(a, s, c, e);
    case 135: MUSTTAIL return state_18(a, s, c, e);
    case 136: MUSTTAIL return state_18(a, s, c, e);
    case 137: MUSTTAIL return state_18(a, s, c, e);
    case 138: MUSTTAIL return state_18(a, s, c, e);
    case 139: MUSTTAIL return state_18(a, s, c, e);
    case 140: MUSTTAIL return state_18(a, s, c, e);
    case 141: MUSTTAIL return state_18(a, s, c, e);
    case 142: MUSTTAIL return state_18(a, s, c, e);
    case 143: MUSTTAIL return state_18(a, s, c, e);
    case 144: MUSTTAIL return state_18(a, s, c, e);
    case 145: MUSTTAIL return state_18(a, s, c, e);
    case 146: MUSTTAIL return state_18(a, s, c, e);
    case 147: MUSTTAIL return state_18(a, s, c, e);
    case 148: MUSTTAIL return state_18(a, s, c, e);
    case 149: MUSTTAIL return state_18(a, s, c, e);
    case 150: MUSTTAIL return state_18(a, s, c, e);
    case 151: MUSTTAIL return state_18(a, s, c, e);
    case 152: MUSTTAIL return state_18(a, s, c, e);
    case 153: MUSTTAIL return state_18(a, s, c, e);
    case 154: MUSTTAIL return state_18(a, s, c, e);
    case 155: MUSTTAIL return state_18(a, s, c, e);
    case 156: MUSTTAIL return state_18(a, s, c, e);
    case 157: MUSTTAIL return state_18(a, s, c, e);
    case 158: MUSTTAIL return state_18(a, s, c, e);
    case 159: MUSTTAIL return state_18(a, s, c, e);
    case 160: MUSTTAIL return state_18(a, s, c, e);
    case 161: MUSTTAIL return state_18(a, s, c, e);
    case 162: MUSTTAIL return state_18(a, s, c, e);
    case 163: MUSTTAIL return state_18(a, s, c, e);
    case 164: MUSTTAIL return state_18(a, s, c, e);
    case 165: MUSTTAIL return state_18(a, s, c, e);
    case 166: MUSTTAIL return state_18(a, s, c, e);
    case 167: MUSTTAIL return state_18(a, s, c, e);
    case 168: MUSTTAIL return state_18(a, s, c, e);
    case 169: MUSTTAIL return state_18(a, s, c, e);
    case 170: MUSTTAIL return state_18(a, s, c, e);
    case 171: MUSTTAIL return state_18(a, s, c, e);
    case 172: MUSTTAIL return state_18(a, s, c, e);
    case 173: MUSTTAIL return state_18(a, s, c, e);
    case 174: MUSTTAIL return state_18(a, s, c, e);
    case 175: MUSTTAIL return state_18(a, s, c, e);
    case 176: MUSTTAIL return state_18(a, s, c, e);
    case 177: MUSTTAIL return state_18(a, s, c, e);
    case 178: MUSTTAIL return state_18(a, s, c, e);
    case 179: MUSTTAIL return state_18(a, s, c, e);
    case 180: MUSTTAIL return state_18(a, s, c, e);
    case 181: MUSTTAIL return state_18(a, s, c, e);
    case 182: MUSTTAIL return state_18(a, s, c, e);
    case 183: MUSTTAIL return state_18(a, s, c, e);
    case 184: MUSTTAIL return state_18(a, s, c, e);
    case 185: MUSTTAIL return state_18(a, s, c, e);
    case 186: MUSTTAIL return state_18(a, s, c, e);
    case 187: MUSTTAIL return state_18(a, s, c, e);
    case 188: MUSTTAIL return state_18(a, s, c, e);
    case 189: MUSTTAIL return state_18(a, s, c, e);
    case 190: MUSTTAIL return state_18(a, s, c, e);
    case 191: MUSTTAIL return state_18(a, s, c, e);
    case 192: MUSTTAIL return state_18(a, s, c, e);
    case 193: MUSTTAIL return state_18(a, s, c, e);
    case 194: MUSTTAIL return state_18(a, s, c, e);
    case 195: MUSTTAIL return state_18(a, s, c, e);
    case 196: MUSTTAIL return state_18(a, s, c, e);
    case 197: MUSTTAIL return state_18(a, s, c, e);
    case 198: MUSTTAIL return state_18(a, s, c, e);
    case 199: MUSTTAIL return state_18(a, s, c, e);
    case 200: MUSTTAIL return state_18(a, s, c, e);
    case 201: MUSTTAIL return state_18(a, s, c, e);
    case 202: MUSTTAIL return state_18(a, s, c, e);
    case 203: MUSTTAIL return state_18(a, s, c, e);
    case 204: MUSTTAIL return state_18(a, s, c, e);
    case 205: MUSTTAIL return state_18(a, s, c, e);
    case 206: MUSTTAIL return state_18(a, s, c, e);
    case 207: MUSTTAIL return state_18(a, s, c, e);
    case 208: MUSTTAIL return state_18(a, s, c, e);
    case 209: MUSTTAIL return state_18(a, s, c, e);
    case 210: MUSTTAIL return state_18(a, s, c, e);
    case 211: MUSTTAIL return state_18(a, s, c, e);
    case 212: MUSTTAIL return state_18(a, s, c, e);
    case 213: MUSTTAIL return state_18(a, s, c, e);
    case 214: MUSTTAIL return state_18(a, s, c, e);
    case 215: MUSTTAIL return state_18(a, s, c, e);
    case 216: MUSTTAIL return state_18(a, s, c, e);
    case 217: MUSTTAIL return state_18(a, s, c, e);
    case 218: MUSTTAIL return state_18(a, s, c, e);
    case 219: MUSTTAIL return state_18(a, s, c, e);
    case 220: MUSTTAIL return state_18(a, s, c, e);
    case 221: MUSTTAIL return state_18(a, s, c, e);
    case 222: MUSTTAIL return state_18(a, s, c, e);
    case 223: MUSTTAIL return state_18(a, s, c, e);
    case 224: MUSTTAIL return state_18(a, s, c, e);
    case 225: MUSTTAIL return state_18(a, s, c, e);
    case 226: MUSTTAIL return state_18(a, s, c, e);
    case 227: MUSTTAIL return state_18(a, s, c, e);
    case 228: MUSTTAIL return state_18(a, s, c, e);
    case 229: MUSTTAIL return state_18(a, s, c, e);
    case 230: MUSTTAIL return state_18(a, s, c, e);
    case 231: MUSTTAIL return state_18(a, s, c, e);
    case 232: MUSTTAIL return state_18(a, s, c, e);
    case 233: MUSTTAIL return state_18(a, s, c, e);
    case 234: MUSTTAIL return state_18(a, s, c, e);
    case 235: MUSTTAIL return state_18(a, s, c, e);
    case 236: MUSTTAIL return state_18(a, s, c, e);
    case 237: MUSTTAIL return state_18(a, s, c, e);
    case 238: MUSTTAIL return state_18(a, s, c, e);
    case 239: MUSTTAIL return state_18(a, s, c, e);
    case 240: MUSTTAIL return state_18(a, s, c, e);
    case 241: MUSTTAIL return state_18(a, s, c, e);
    case 242: MUSTTAIL return state_18(a, s, c, e);
    case 243: MUSTTAIL return state_18(a, s, c, e);
    case 244: MUSTTAIL return state_18(a, s, c, e);
    case 245: MUSTTAIL return state_18(a, s, c, e);
    case 246: MUSTTAIL return state_18(a, s, c, e);
    case 247: MUSTTAIL return state_18(a, s, c, e);
    case 248: MUSTTAIL return state_18(a, s, c, e);
    case 249: MUSTTAIL return state_18(a, s, c, e);
    case 250: MUSTTAIL return state_18(a, s, c, e);
    case 251: MUSTTAIL return state_18(a, s, c, e);
    case 252: MUSTTAIL return state_18(a, s, c, e);
    case 253: MUSTTAIL return state_18(a, s, c, e);
    case 254: MUSTTAIL return state_18(a, s, c, e);
    case 255: MUSTTAIL return state_18(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_1(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] (|(&.(~0a))0a)
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_34(a, s, c, e);
    case 1: MUSTTAIL return state_34(a, s, c, e);
    case 2: MUSTTAIL return state_34(a, s, c, e);
    case 3: MUSTTAIL return state_34(a, s, c, e);
    case 4: MUSTTAIL return state_34(a, s, c, e);
    case 5: MUSTTAIL return state_34(a, s, c, e);
    case 6: MUSTTAIL return state_34(a, s, c, e);
    case 7: MUSTTAIL return state_34(a, s, c, e);
    case 8: MUSTTAIL return state_34(a, s, c, e);
    case 9: MUSTTAIL return state_34(a, s, c, e);
    case 10: MUSTTAIL return state_35(a, s, c, e);
    case 11: MUSTTAIL return state_34(a, s, c, e);
    case 12: MUSTTAIL return state_34(a, s, c, e);
    case 13: MUSTTAIL return state_34(a, s, c, e);
    case 14: MUSTTAIL return state_34(a, s, c, e);
    case 15: MUSTTAIL return state_34(a, s, c, e);
    case 16: MUSTTAIL return state_34(a, s, c, e);
    case 17: MUSTTAIL return state_34(a, s, c, e);
    case 18: MUSTTAIL return state_34(a, s, c, e);
    case 19: MUSTTAIL return state_34(a, s, c, e);
    case 20: MUSTTAIL return state_34(a, s, c, e);
    case 21: MUSTTAIL return state_34(a, s, c, e);
    case 22: MUSTTAIL return state_34(a, s, c, e);
    case 23: MUSTTAIL return state_34(a, s, c, e);
    case 24: MUSTTAIL return state_34(a, s, c, e);
    case 25: MUSTTAIL return state_34(a, s, c, e);
    case 26: MUSTTAIL return state_34(a, s, c, e);
    case 27: MUSTTAIL return state_34(a, s, c, e);
    case 28: MUSTTAIL return state_34(a, s, c, e);
    case 29: MUSTTAIL return state_34(a, s, c, e);
    case 30: MUSTTAIL return state_34(a, s, c, e);
    case 31: MUSTTAIL return state_34(a, s, c, e);
    case 32: MUSTTAIL return state_34(a, s, c, e);
    case 33: MUSTTAIL return state_34(a, s, c, e);
    case 34: MUSTTAIL return state_34(a, s, c, e);
    case 35: MUSTTAIL return state_34(a, s, c, e);
    case 36: MUSTTAIL return state_34(a, s, c, e);
    case 37: MUSTTAIL return state_34(a, s, c, e);
    case 38: MUSTTAIL return state_34(a, s, c, e);
    case 39: MUSTTAIL return state_34(a, s, c, e);
    case 40: MUSTTAIL return state_34(a, s, c, e);
    case 41: MUSTTAIL return state_34(a, s, c, e);
    case 42: MUSTTAIL return state_34(a, s, c, e);
    case 43: MUSTTAIL return state_34(a, s, c, e);
    case 44: MUSTTAIL return state_34(a, s, c, e);
    case 45: MUSTTAIL return state_34(a, s, c, e);
    case 46: MUSTTAIL return state_34(a, s, c, e);
    case 47: MUSTTAIL return state_34(a, s, c, e);
    case 48: MUSTTAIL return state_34(a, s, c, e);
    case 49: MUSTTAIL return state_34(a, s, c, e);
    case 50: MUSTTAIL return state_34(a, s, c, e);
    case 51: MUSTTAIL return state_34(a, s, c, e);
    case 52: MUSTTAIL return state_34(a, s, c, e);
    case 53: MUSTTAIL return state_34(a, s, c, e);
    case 54: MUSTTAIL return state_34(a, s, c, e);
    case 55: MUSTTAIL return state_34(a, s, c, e);
    case 56: MUSTTAIL return state_34(a, s, c, e);
    case 57: MUSTTAIL return state_34(a, s, c, e);
    case 58: MUSTTAIL return state_34(a, s, c, e);
    case 59: MUSTTAIL return state_34(a, s, c, e);
    case 60: MUSTTAIL return state_34(a, s, c, e);
    case 61: MUSTTAIL return state_34(a, s, c, e);
    case 62: MUSTTAIL return state_34(a, s, c, e);
    case 63: MUSTTAIL return state_34(a, s, c, e);
    case 64: MUSTTAIL return state_34(a, s, c, e);
    case 65: MUSTTAIL return state_34(a, s, c, e);
    case 66: MUSTTAIL return state_34(a, s, c, e);
    case 67: MUSTTAIL return state_34(a, s, c, e);
    case 68: MUSTTAIL return state_34(a, s, c, e);
    case 69: MUSTTAIL return state_34(a, s, c, e);
    case 70: MUSTTAIL return state_34(a, s, c, e);
    case 71: MUSTTAIL return state_34(a, s, c, e);
    case 72: MUSTTAIL return state_34(a, s, c, e);
    case 73: MUSTTAIL return state_34(a, s, c, e);
    case 74: MUSTTAIL return state_34(a, s, c, e);
    case 75: MUSTTAIL return state_34(a, s, c, e);
    case 76: MUSTTAIL return state_34(a, s, c, e);
    case 77: MUSTTAIL return state_34(a, s, c, e);
    case 78: MUSTTAIL return state_34(a, s, c, e);
    case 79: MUSTTAIL return state_34(a, s, c, e);
    case 80: MUSTTAIL return state_34(a, s, c, e);
    case 81: MUSTTAIL return state_34(a, s, c, e);
    case 82: MUSTTAIL return state_34(a, s, c, e);
    case 83: MUSTTAIL return state_34(a, s, c, e);
    case 84: MUSTTAIL return state_34(a, s, c, e);
    case 85: MUSTTAIL return state_34(a, s, c, e);
    case 86: MUSTTAIL return state_34(a, s, c, e);
    case 87: MUSTTAIL return state_34(a, s, c, e);
    case 88: MUSTTAIL return state_34(a, s, c, e);
    case 89: MUSTTAIL return state_34(a, s, c, e);
    case 90: MUSTTAIL return state_34(a, s, c, e);
    case 91: MUSTTAIL return state_34(a, s, c, e);
    case 92: MUSTTAIL return state_34(a, s, c, e);
    case 93: MUSTTAIL return state_34(a, s, c, e);
    case 94: MUSTTAIL return state_34(a, s, c, e);
    case 95: MUSTTAIL return state_34(a, s, c, e);
    case 96: MUSTTAIL return state_34(a, s, c, e);
    case 97: MUSTTAIL return state_34(a, s, c, e);
    case 98: MUSTTAIL return state_34(a, s, c, e);
    case 99: MUSTTAIL return state_34(a, s, c, e);
    case 100: MUSTTAIL return state_34(a, s, c, e);
    case 101: MUSTTAIL return state_34(a, s, c, e);
    case 102: MUSTTAIL return state_34(a, s, c, e);
    case 103: MUSTTAIL return state_34(a, s, c, e);
    case 104: MUSTTAIL return state_34(a, s, c, e);
    case 105: MUSTTAIL return state_34(a, s, c, e);
    case 106: MUSTTAIL return state_34(a, s, c, e);
    case 107: MUSTTAIL return state_34(a, s, c, e);
    case 108: MUSTTAIL return state_34(a, s, c, e);
    case 109: MUSTTAIL return state_34(a, s, c, e);
    case 110: MUSTTAIL return state_34(a, s, c, e);
    case 111: MUSTTAIL return state_34(a, s, c, e);
    case 112: MUSTTAIL return state_34(a, s, c, e);
    case 113: MUSTTAIL return state_34(a, s, c, e);
    case 114: MUSTTAIL return state_34(a, s, c, e);
    case 115: MUSTTAIL return state_34(a, s, c, e);
    case 116: MUSTTAIL return state_34(a, s, c, e);
    case 117: MUSTTAIL return state_34(a, s, c, e);
    case 118: MUSTTAIL return state_34(a, s, c, e);
    case 119: MUSTTAIL return state_34(a, s, c, e);
    case 120: MUSTTAIL return state_34(a, s, c, e);
    case 121: MUSTTAIL return state_34(a, s, c, e);
    case 122: MUSTTAIL return state_34(a, s, c, e);
    case 123: MUSTTAIL return state_34(a, s, c, e);
    case 124: MUSTTAIL return state_34(a, s, c, e);
    case 125: MUSTTAIL return state_34(a, s, c, e);
    case 126: MUSTTAIL return state_34(a, s, c, e);
    case 127: MUSTTAIL return state_34(a, s, c, e);
    case 128: MUSTTAIL return state_34(a, s, c, e);
    case 129: MUSTTAIL return state_34(a, s, c, e);
    case 130: MUSTTAIL return state_34(a, s, c, e);
    case 131: MUSTTAIL return state_34(a, s, c, e);
    case 132: MUSTTAIL return state_34(a, s, c, e);
    case 133: MUSTTAIL return state_34(a, s, c, e);
    case 134: MUSTTAIL return state_34(a, s, c, e);
    case 135: MUSTTAIL return state_34(a, s, c, e);
    case 136: MUSTTAIL return state_34(a, s, c, e);
    case 137: MUSTTAIL return state_34(a, s, c, e);
    case 138: MUSTTAIL return state_34(a, s, c, e);
    case 139: MUSTTAIL return state_34(a, s, c, e);
    case 140: MUSTTAIL return state_34(a, s, c, e);
    case 141: MUSTTAIL return state_34(a, s, c, e);
    case 142: MUSTTAIL return state_34(a, s, c, e);
    case 143: MUSTTAIL return state_34(a, s, c, e);
    case 144: MUSTTAIL return state_34(a, s, c, e);
    case 145: MUSTTAIL return state_34(a, s, c, e);
    case 146: MUSTTAIL return state_34(a, s, c, e);
    case 147: MUSTTAIL return state_34(a, s, c, e);
    case 148: MUSTTAIL return state_34(a, s, c, e);
    case 149: MUSTTAIL return state_34(a, s, c, e);
    case 150: MUSTTAIL return state_34(a, s, c, e);
    case 151: MUSTTAIL return state_34(a, s, c, e);
    case 152: MUSTTAIL return state_34(a, s, c, e);
    case 153: MUSTTAIL return state_34(a, s, c, e);
    case 154: MUSTTAIL return state_34(a, s, c, e);
    case 155: MUSTTAIL return state_34(a, s, c, e);
    case 156: MUSTTAIL return state_34(a, s, c, e);
    case 157: MUSTTAIL return state_34(a, s, c, e);
    case 158: MUSTTAIL return state_34(a, s, c, e);
    case 159: MUSTTAIL return state_34(a, s, c, e);
    case 160: MUSTTAIL return state_34(a, s, c, e);
    case 161: MUSTTAIL return state_34(a, s, c, e);
    case 162: MUSTTAIL return state_34(a, s, c, e);
    case 163: MUSTTAIL return state_34(a, s, c, e);
    case 164: MUSTTAIL return state_34(a, s, c, e);
    case 165: MUSTTAIL return state_34(a, s, c, e);
    case 166: MUSTTAIL return state_34(a, s, c, e);
    case 167: MUSTTAIL return state_34(a, s, c, e);
    case 168: MUSTTAIL return state_34(a, s, c, e);
    case 169: MUSTTAIL return state_34(a, s, c, e);
    case 170: MUSTTAIL return state_34(a, s, c, e);
    case 171: MUSTTAIL return state_34(a, s, c, e);
    case 172: MUSTTAIL return state_34(a, s, c, e);
    case 173: MUSTTAIL return state_34(a, s, c, e);
    case 174: MUSTTAIL return state_34(a, s, c, e);
    case 175: MUSTTAIL return state_34(a, s, c, e);
    case 176: MUSTTAIL return state_34(a, s, c, e);
    case 177: MUSTTAIL return state_34(a, s, c, e);
    case 178: MUSTTAIL return state_34(a, s, c, e);
    case 179: MUSTTAIL return state_34(a, s, c, e);
    case 180: MUSTTAIL return state_34(a, s, c, e);
    case 181: MUSTTAIL return state_34(a, s, c, e);
    case 182: MUSTTAIL return state_34(a, s, c, e);
    case 183: MUSTTAIL return state_34(a, s, c, e);
    case 184: MUSTTAIL return state_34(a, s, c, e);
    case 185: MUSTTAIL return state_34(a, s, c, e);
    case 186: MUSTTAIL return state_34(a, s, c, e);
    case 187: MUSTTAIL return state_34(a, s, c, e);
    case 188: MUSTTAIL return state_34(a, s, c, e);
    case 189: MUSTTAIL return state_34(a, s, c, e);
    case 190: MUSTTAIL return state_34(a, s, c, e);
    case 191: MUSTTAIL return state_34(a, s, c, e);
    case 192: MUSTTAIL return state_34(a, s, c, e);
    case 193: MUSTTAIL return state_34(a, s, c, e);
    case 194: MUSTTAIL return state_34(a, s, c, e);
    case 195: MUSTTAIL return state_34(a, s, c, e);
    case 196: MUSTTAIL return state_34(a, s, c, e);
    case 197: MUSTTAIL return state_34(a, s, c, e);
    case 198: MUSTTAIL return state_34(a, s, c, e);
    case 199: MUSTTAIL return state_34(a, s, c, e);
    case 200: MUSTTAIL return state_34(a, s, c, e);
    case 201: MUSTTAIL return state_34(a, s, c, e);
    case 202: MUSTTAIL return state_34(a, s, c, e);
    case 203: MUSTTAIL return state_34(a, s, c, e);
    case 204: MUSTTAIL return state_34(a, s, c, e);
    case 205: MUSTTAIL return state_34(a, s, c, e);
    case 206: MUSTTAIL return state_34(a, s, c, e);
    case 207: MUSTTAIL return state_34(a, s, c, e);
    case 208: MUSTTAIL return state_34(a, s, c, e);
    case 209: MUSTTAIL return state_34(a, s, c, e);
    case 210: MUSTTAIL return state_34(a, s, c, e);
    case 211: MUSTTAIL return state_34(a, s, c, e);
    case 212: MUSTTAIL return state_34(a, s, c, e);
    case 213: MUSTTAIL return state_34(a, s, c, e);
    case 214: MUSTTAIL return state_34(a, s, c, e);
    case 215: MUSTTAIL return state_34(a, s, c, e);
    case 216: MUSTTAIL return state_34(a, s, c, e);
    case 217: MUSTTAIL return state_34(a, s, c, e);
    case 218: MUSTTAIL return state_34(a, s, c, e);
    case 219: MUSTTAIL return state_34(a, s, c, e);
    case 220: MUSTTAIL return state_34(a, s, c, e);
    case 221: MUSTTAIL return state_34(a, s, c, e);
    case 222: MUSTTAIL return state_34(a, s, c, e);
    case 223: MUSTTAIL return state_34(a, s, c, e);
    case 224: MUSTTAIL return state_34(a, s, c, e);
    case 225: MUSTTAIL return state_34(a, s, c, e);
    case 226: MUSTTAIL return state_34(a, s, c, e);
    case 227: MUSTTAIL return state_34(a, s, c, e);
    case 228: MUSTTAIL return state_34(a, s, c, e);
    case 229: MUSTTAIL return state_34(a, s, c, e);
    case 230: MUSTTAIL return state_34(a, s, c, e);
    case 231: MUSTTAIL return state_34(a, s, c, e);
    case 232: MUSTTAIL return state_34(a, s, c, e);
    case 233: MUSTTAIL return state_34(a, s, c, e);
    case 234: MUSTTAIL return state_34(a, s, c, e);
    case 235: MUSTTAIL return state_34(a, s, c, e);
    case 236: MUSTTAIL return state_34(a, s, c, e);
    case 237: MUSTTAIL return state_34(a, s, c, e);
    case 238: MUSTTAIL return state_34(a, s, c, e);
    case 239: MUSTTAIL return state_34(a, s, c, e);
    case 240: MUSTTAIL return state_34(a, s, c, e);
    case 241: MUSTTAIL return state_34(a, s, c, e);
    case 242: MUSTTAIL return state_34(a, s, c, e);
    case 243: MUSTTAIL return state_34(a, s, c, e);
    case 244: MUSTTAIL return state_34(a, s, c, e);
    case 245: MUSTTAIL return state_34(a, s, c, e);
    case 246: MUSTTAIL return state_34(a, s, c, e);
    case 247: MUSTTAIL return state_34(a, s, c, e);
    case 248: MUSTTAIL return state_34(a, s, c, e);
    case 249: MUSTTAIL return state_34(a, s, c, e);
    case 250: MUSTTAIL return state_34(a, s, c, e);
    case 251: MUSTTAIL return state_34(a, s, c, e);
    case 252: MUSTTAIL return state_34(a, s, c, e);
    case 253: MUSTTAIL return state_34(a, s, c, e);
    case 254: MUSTTAIL return state_34(a, s, c, e);
    case 255: MUSTTAIL return state_34(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_2(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] (:61(:6464))
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_37(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_3(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] (:73(:7562))
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_38(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_4(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] (:6d(:756c))
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_39(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_5(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] (:64(:6976))
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_40(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_6(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] (:72(:656d))
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_41(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_7(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] (:6f72)
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_42(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_8(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] (:61(:6e64))
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_43(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_9(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] (:78(:6f72))
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_44(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_10(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] (:61(:6273))
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_45(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_11(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] (:6e(:6567))
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_46(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_12(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] (:69(:6e63))
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_47(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_13(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] (:64(:6563))
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_48(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_14(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] (:(|_2d)(:(|(|(|(|(|3637)(|3839))(|3435))(|3233))(|3031))(*(|(|(|(|(|3637)(|3839))(|3435))(|3233))(|3031)))))
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_49(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_50(a, s, c, e);
    case 49: MUSTTAIL return state_50(a, s, c, e);
    case 50: MUSTTAIL return state_50(a, s, c, e);
    case 51: MUSTTAIL return state_50(a, s, c, e);
    case 52: MUSTTAIL return state_50(a, s, c, e);
    case 53: MUSTTAIL return state_50(a, s, c, e);
    case 54: MUSTTAIL return state_50(a, s, c, e);
    case 55: MUSTTAIL return state_50(a, s, c, e);
    case 56: MUSTTAIL return state_50(a, s, c, e);
    case 57: MUSTTAIL return state_50(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_15(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] 28
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_51(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_16(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] 29
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_52(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_17(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] (:(|(|(|090d)(|0b20))(|0a0c))(*(|(|(|090d)(|0b20))(|0a0c))))
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_53(a, s, c, e);
    case 10: MUSTTAIL return state_53(a, s, c, e);
    case 11: MUSTTAIL return state_53(a, s, c, e);
    case 12: MUSTTAIL return state_53(a, s, c, e);
    case 13: MUSTTAIL return state_53(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_53(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_18(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 16
  active = 16;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_19(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] (*(|(|(|090d)(|0b20))(|0a0c)))
  // regex[16] _
  // First nullable state 15
  active = 15;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_54(a, s, c, e);
    case 10: MUSTTAIL return state_54(a, s, c, e);
    case 11: MUSTTAIL return state_54(a, s, c, e);
    case 12: MUSTTAIL return state_54(a, s, c, e);
    case 13: MUSTTAIL return state_54(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_54(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_20(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] (*(|(|(|090d)(|0b20))(|0a0c)))
  // regex[16] (|_(&_(~_)))
  // First nullable state 15
  active = 15;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_54(a, s, c, e);
    case 10: MUSTTAIL return state_54(a, s, c, e);
    case 11: MUSTTAIL return state_54(a, s, c, e);
    case 12: MUSTTAIL return state_54(a, s, c, e);
    case 13: MUSTTAIL return state_54(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_54(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_21(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] _
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 13
  active = 13;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_22(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] _
  // regex[15] %
  // regex[16] _
  // First nullable state 14
  active = 14;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_23(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] (:(|(|(|(|(|3637)(|3839))(|3435))(|3233))(|3031))(*(|(|(|(|(|3637)(|3839))(|3435))(|3233))(|3031))))
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 16
  active = 16;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_55(a, s, c, e);
    case 49: MUSTTAIL return state_55(a, s, c, e);
    case 50: MUSTTAIL return state_55(a, s, c, e);
    case 51: MUSTTAIL return state_55(a, s, c, e);
    case 52: MUSTTAIL return state_55(a, s, c, e);
    case 53: MUSTTAIL return state_55(a, s, c, e);
    case 54: MUSTTAIL return state_55(a, s, c, e);
    case 55: MUSTTAIL return state_55(a, s, c, e);
    case 56: MUSTTAIL return state_55(a, s, c, e);
    case 57: MUSTTAIL return state_55(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_24(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] (*(|(|(|(|(|3637)(|3839))(|3435))(|3233))(|3031)))
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 12
  active = 12;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_55(a, s, c, e);
    case 49: MUSTTAIL return state_55(a, s, c, e);
    case 50: MUSTTAIL return state_55(a, s, c, e);
    case 51: MUSTTAIL return state_55(a, s, c, e);
    case 52: MUSTTAIL return state_55(a, s, c, e);
    case 53: MUSTTAIL return state_55(a, s, c, e);
    case 54: MUSTTAIL return state_55(a, s, c, e);
    case 55: MUSTTAIL return state_55(a, s, c, e);
    case 56: MUSTTAIL return state_55(a, s, c, e);
    case 57: MUSTTAIL return state_55(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_25(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] (:6464)
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] (:6e64)
  // regex[7] %
  // regex[8] (:6273)
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 16
  active = 16;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_56(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_57(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_58(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_26(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] (:6976)
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] (:6563)
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 16
  active = 16;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_59(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_60(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_27(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] (:6e63)
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 16
  active = 16;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_61(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_28(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] (:756c)
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 16
  active = 16;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_62(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_29(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] (:6567)
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 16
  active = 16;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_63(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_30(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] 72
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 16
  active = 16;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_64(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_31(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] (:656d)
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 16
  active = 16;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_65(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_32(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] (:7562)
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 16
  active = 16;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_66(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_33(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] (:6f72)
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] _
  // First nullable state 16
  active = 16;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_67(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_34(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] _
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 0
  active = 0;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_35(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] (|_(&_(~_)))
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 0
  active = 0;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_36(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  // All further states are failure
  uint64_t count = (current - start) - 1;
  return result_value(active, count);

}

lexer_match_t state_37(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] (:6464)
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_68(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_38(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] (:7562)
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_69(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_39(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] (:756c)
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_70(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_40(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] (:6976)
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_71(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_41(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] (:656d)
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_72(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_42(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] 72
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_73(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_43(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] (:6e64)
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_74(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_44(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] (:6f72)
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_75(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_45(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] (:6273)
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_76(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_46(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] (:6567)
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_77(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_47(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] (:6e63)
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_59(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_48(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] (:6563)
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_78(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_49(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] (:(|(|(|(|(|3637)(|3839))(|3435))(|3233))(|3031))(*(|(|(|(|(|3637)(|3839))(|3435))(|3233))(|3031))))
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_50(a, s, c, e);
    case 49: MUSTTAIL return state_50(a, s, c, e);
    case 50: MUSTTAIL return state_50(a, s, c, e);
    case 51: MUSTTAIL return state_50(a, s, c, e);
    case 52: MUSTTAIL return state_50(a, s, c, e);
    case 53: MUSTTAIL return state_50(a, s, c, e);
    case 54: MUSTTAIL return state_50(a, s, c, e);
    case 55: MUSTTAIL return state_50(a, s, c, e);
    case 56: MUSTTAIL return state_50(a, s, c, e);
    case 57: MUSTTAIL return state_50(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_50(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] (*(|(|(|(|(|3637)(|3839))(|3435))(|3233))(|3031)))
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 13
  active = 13;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_50(a, s, c, e);
    case 49: MUSTTAIL return state_50(a, s, c, e);
    case 50: MUSTTAIL return state_50(a, s, c, e);
    case 51: MUSTTAIL return state_50(a, s, c, e);
    case 52: MUSTTAIL return state_50(a, s, c, e);
    case 53: MUSTTAIL return state_50(a, s, c, e);
    case 54: MUSTTAIL return state_50(a, s, c, e);
    case 55: MUSTTAIL return state_50(a, s, c, e);
    case 56: MUSTTAIL return state_50(a, s, c, e);
    case 57: MUSTTAIL return state_50(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_51(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] _
  // regex[15] %
  // regex[16] %
  // First nullable state 14
  active = 14;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_52(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] _
  // regex[16] %
  // First nullable state 15
  active = 15;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_53(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] (*(|(|(|090d)(|0b20))(|0a0c)))
  // First nullable state 16
  active = 16;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_53(a, s, c, e);
    case 10: MUSTTAIL return state_53(a, s, c, e);
    case 11: MUSTTAIL return state_53(a, s, c, e);
    case 12: MUSTTAIL return state_53(a, s, c, e);
    case 13: MUSTTAIL return state_53(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_53(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_54(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] (*(|(|(|090d)(|0b20))(|0a0c)))
  // regex[16] %
  // First nullable state 15
  active = 15;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_54(a, s, c, e);
    case 10: MUSTTAIL return state_54(a, s, c, e);
    case 11: MUSTTAIL return state_54(a, s, c, e);
    case 12: MUSTTAIL return state_54(a, s, c, e);
    case 13: MUSTTAIL return state_54(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_54(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_55(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] (*(|(|(|(|(|3637)(|3839))(|3435))(|3233))(|3031)))
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 12
  active = 12;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_55(a, s, c, e);
    case 49: MUSTTAIL return state_55(a, s, c, e);
    case 50: MUSTTAIL return state_55(a, s, c, e);
    case 51: MUSTTAIL return state_55(a, s, c, e);
    case 52: MUSTTAIL return state_55(a, s, c, e);
    case 53: MUSTTAIL return state_55(a, s, c, e);
    case 54: MUSTTAIL return state_55(a, s, c, e);
    case 55: MUSTTAIL return state_55(a, s, c, e);
    case 56: MUSTTAIL return state_55(a, s, c, e);
    case 57: MUSTTAIL return state_55(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_56(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] 73
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_79(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_57(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] 64
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_34(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_58(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] 64
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_73(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_59(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] 63
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_80(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_60(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] 76
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_81(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_61(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] 63
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_82(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_62(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] 6c
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_83(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_63(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] 67
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_84(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_64(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] _
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 5
  active = 5;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_65(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] 6d
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_85(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_66(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] 62
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_86(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_67(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] 72
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_87(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_68(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] 64
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_86(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_69(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] 62
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_83(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_70(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] 6c
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_81(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_71(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] 76
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_85(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_72(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] 6d
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_64(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_73(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] _
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 6
  active = 6;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_74(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] 64
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_87(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_75(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] 72
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_79(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_76(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] 73
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_84(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_77(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] 67
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_36(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_82(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_78(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] 63
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // None of the states are nullable
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  byte next = *current;
  switch(next)
  {
    case 0: MUSTTAIL return state_36(a, s, c, e);
    case 1: MUSTTAIL return state_36(a, s, c, e);
    case 2: MUSTTAIL return state_36(a, s, c, e);
    case 3: MUSTTAIL return state_36(a, s, c, e);
    case 4: MUSTTAIL return state_36(a, s, c, e);
    case 5: MUSTTAIL return state_36(a, s, c, e);
    case 6: MUSTTAIL return state_36(a, s, c, e);
    case 7: MUSTTAIL return state_36(a, s, c, e);
    case 8: MUSTTAIL return state_36(a, s, c, e);
    case 9: MUSTTAIL return state_36(a, s, c, e);
    case 10: MUSTTAIL return state_36(a, s, c, e);
    case 11: MUSTTAIL return state_36(a, s, c, e);
    case 12: MUSTTAIL return state_36(a, s, c, e);
    case 13: MUSTTAIL return state_36(a, s, c, e);
    case 14: MUSTTAIL return state_36(a, s, c, e);
    case 15: MUSTTAIL return state_36(a, s, c, e);
    case 16: MUSTTAIL return state_36(a, s, c, e);
    case 17: MUSTTAIL return state_36(a, s, c, e);
    case 18: MUSTTAIL return state_36(a, s, c, e);
    case 19: MUSTTAIL return state_36(a, s, c, e);
    case 20: MUSTTAIL return state_36(a, s, c, e);
    case 21: MUSTTAIL return state_36(a, s, c, e);
    case 22: MUSTTAIL return state_36(a, s, c, e);
    case 23: MUSTTAIL return state_36(a, s, c, e);
    case 24: MUSTTAIL return state_36(a, s, c, e);
    case 25: MUSTTAIL return state_36(a, s, c, e);
    case 26: MUSTTAIL return state_36(a, s, c, e);
    case 27: MUSTTAIL return state_36(a, s, c, e);
    case 28: MUSTTAIL return state_36(a, s, c, e);
    case 29: MUSTTAIL return state_36(a, s, c, e);
    case 30: MUSTTAIL return state_36(a, s, c, e);
    case 31: MUSTTAIL return state_36(a, s, c, e);
    case 32: MUSTTAIL return state_36(a, s, c, e);
    case 33: MUSTTAIL return state_36(a, s, c, e);
    case 34: MUSTTAIL return state_36(a, s, c, e);
    case 35: MUSTTAIL return state_36(a, s, c, e);
    case 36: MUSTTAIL return state_36(a, s, c, e);
    case 37: MUSTTAIL return state_36(a, s, c, e);
    case 38: MUSTTAIL return state_36(a, s, c, e);
    case 39: MUSTTAIL return state_36(a, s, c, e);
    case 40: MUSTTAIL return state_36(a, s, c, e);
    case 41: MUSTTAIL return state_36(a, s, c, e);
    case 42: MUSTTAIL return state_36(a, s, c, e);
    case 43: MUSTTAIL return state_36(a, s, c, e);
    case 44: MUSTTAIL return state_36(a, s, c, e);
    case 45: MUSTTAIL return state_36(a, s, c, e);
    case 46: MUSTTAIL return state_36(a, s, c, e);
    case 47: MUSTTAIL return state_36(a, s, c, e);
    case 48: MUSTTAIL return state_36(a, s, c, e);
    case 49: MUSTTAIL return state_36(a, s, c, e);
    case 50: MUSTTAIL return state_36(a, s, c, e);
    case 51: MUSTTAIL return state_36(a, s, c, e);
    case 52: MUSTTAIL return state_36(a, s, c, e);
    case 53: MUSTTAIL return state_36(a, s, c, e);
    case 54: MUSTTAIL return state_36(a, s, c, e);
    case 55: MUSTTAIL return state_36(a, s, c, e);
    case 56: MUSTTAIL return state_36(a, s, c, e);
    case 57: MUSTTAIL return state_36(a, s, c, e);
    case 58: MUSTTAIL return state_36(a, s, c, e);
    case 59: MUSTTAIL return state_36(a, s, c, e);
    case 60: MUSTTAIL return state_36(a, s, c, e);
    case 61: MUSTTAIL return state_36(a, s, c, e);
    case 62: MUSTTAIL return state_36(a, s, c, e);
    case 63: MUSTTAIL return state_36(a, s, c, e);
    case 64: MUSTTAIL return state_36(a, s, c, e);
    case 65: MUSTTAIL return state_36(a, s, c, e);
    case 66: MUSTTAIL return state_36(a, s, c, e);
    case 67: MUSTTAIL return state_36(a, s, c, e);
    case 68: MUSTTAIL return state_36(a, s, c, e);
    case 69: MUSTTAIL return state_36(a, s, c, e);
    case 70: MUSTTAIL return state_36(a, s, c, e);
    case 71: MUSTTAIL return state_36(a, s, c, e);
    case 72: MUSTTAIL return state_36(a, s, c, e);
    case 73: MUSTTAIL return state_36(a, s, c, e);
    case 74: MUSTTAIL return state_36(a, s, c, e);
    case 75: MUSTTAIL return state_36(a, s, c, e);
    case 76: MUSTTAIL return state_36(a, s, c, e);
    case 77: MUSTTAIL return state_36(a, s, c, e);
    case 78: MUSTTAIL return state_36(a, s, c, e);
    case 79: MUSTTAIL return state_36(a, s, c, e);
    case 80: MUSTTAIL return state_36(a, s, c, e);
    case 81: MUSTTAIL return state_36(a, s, c, e);
    case 82: MUSTTAIL return state_36(a, s, c, e);
    case 83: MUSTTAIL return state_36(a, s, c, e);
    case 84: MUSTTAIL return state_36(a, s, c, e);
    case 85: MUSTTAIL return state_36(a, s, c, e);
    case 86: MUSTTAIL return state_36(a, s, c, e);
    case 87: MUSTTAIL return state_36(a, s, c, e);
    case 88: MUSTTAIL return state_36(a, s, c, e);
    case 89: MUSTTAIL return state_36(a, s, c, e);
    case 90: MUSTTAIL return state_36(a, s, c, e);
    case 91: MUSTTAIL return state_36(a, s, c, e);
    case 92: MUSTTAIL return state_36(a, s, c, e);
    case 93: MUSTTAIL return state_36(a, s, c, e);
    case 94: MUSTTAIL return state_36(a, s, c, e);
    case 95: MUSTTAIL return state_36(a, s, c, e);
    case 96: MUSTTAIL return state_36(a, s, c, e);
    case 97: MUSTTAIL return state_36(a, s, c, e);
    case 98: MUSTTAIL return state_36(a, s, c, e);
    case 99: MUSTTAIL return state_88(a, s, c, e);
    case 100: MUSTTAIL return state_36(a, s, c, e);
    case 101: MUSTTAIL return state_36(a, s, c, e);
    case 102: MUSTTAIL return state_36(a, s, c, e);
    case 103: MUSTTAIL return state_36(a, s, c, e);
    case 104: MUSTTAIL return state_36(a, s, c, e);
    case 105: MUSTTAIL return state_36(a, s, c, e);
    case 106: MUSTTAIL return state_36(a, s, c, e);
    case 107: MUSTTAIL return state_36(a, s, c, e);
    case 108: MUSTTAIL return state_36(a, s, c, e);
    case 109: MUSTTAIL return state_36(a, s, c, e);
    case 110: MUSTTAIL return state_36(a, s, c, e);
    case 111: MUSTTAIL return state_36(a, s, c, e);
    case 112: MUSTTAIL return state_36(a, s, c, e);
    case 113: MUSTTAIL return state_36(a, s, c, e);
    case 114: MUSTTAIL return state_36(a, s, c, e);
    case 115: MUSTTAIL return state_36(a, s, c, e);
    case 116: MUSTTAIL return state_36(a, s, c, e);
    case 117: MUSTTAIL return state_36(a, s, c, e);
    case 118: MUSTTAIL return state_36(a, s, c, e);
    case 119: MUSTTAIL return state_36(a, s, c, e);
    case 120: MUSTTAIL return state_36(a, s, c, e);
    case 121: MUSTTAIL return state_36(a, s, c, e);
    case 122: MUSTTAIL return state_36(a, s, c, e);
    case 123: MUSTTAIL return state_36(a, s, c, e);
    case 124: MUSTTAIL return state_36(a, s, c, e);
    case 125: MUSTTAIL return state_36(a, s, c, e);
    case 126: MUSTTAIL return state_36(a, s, c, e);
    case 127: MUSTTAIL return state_36(a, s, c, e);
    case 128: MUSTTAIL return state_36(a, s, c, e);
    case 129: MUSTTAIL return state_36(a, s, c, e);
    case 130: MUSTTAIL return state_36(a, s, c, e);
    case 131: MUSTTAIL return state_36(a, s, c, e);
    case 132: MUSTTAIL return state_36(a, s, c, e);
    case 133: MUSTTAIL return state_36(a, s, c, e);
    case 134: MUSTTAIL return state_36(a, s, c, e);
    case 135: MUSTTAIL return state_36(a, s, c, e);
    case 136: MUSTTAIL return state_36(a, s, c, e);
    case 137: MUSTTAIL return state_36(a, s, c, e);
    case 138: MUSTTAIL return state_36(a, s, c, e);
    case 139: MUSTTAIL return state_36(a, s, c, e);
    case 140: MUSTTAIL return state_36(a, s, c, e);
    case 141: MUSTTAIL return state_36(a, s, c, e);
    case 142: MUSTTAIL return state_36(a, s, c, e);
    case 143: MUSTTAIL return state_36(a, s, c, e);
    case 144: MUSTTAIL return state_36(a, s, c, e);
    case 145: MUSTTAIL return state_36(a, s, c, e);
    case 146: MUSTTAIL return state_36(a, s, c, e);
    case 147: MUSTTAIL return state_36(a, s, c, e);
    case 148: MUSTTAIL return state_36(a, s, c, e);
    case 149: MUSTTAIL return state_36(a, s, c, e);
    case 150: MUSTTAIL return state_36(a, s, c, e);
    case 151: MUSTTAIL return state_36(a, s, c, e);
    case 152: MUSTTAIL return state_36(a, s, c, e);
    case 153: MUSTTAIL return state_36(a, s, c, e);
    case 154: MUSTTAIL return state_36(a, s, c, e);
    case 155: MUSTTAIL return state_36(a, s, c, e);
    case 156: MUSTTAIL return state_36(a, s, c, e);
    case 157: MUSTTAIL return state_36(a, s, c, e);
    case 158: MUSTTAIL return state_36(a, s, c, e);
    case 159: MUSTTAIL return state_36(a, s, c, e);
    case 160: MUSTTAIL return state_36(a, s, c, e);
    case 161: MUSTTAIL return state_36(a, s, c, e);
    case 162: MUSTTAIL return state_36(a, s, c, e);
    case 163: MUSTTAIL return state_36(a, s, c, e);
    case 164: MUSTTAIL return state_36(a, s, c, e);
    case 165: MUSTTAIL return state_36(a, s, c, e);
    case 166: MUSTTAIL return state_36(a, s, c, e);
    case 167: MUSTTAIL return state_36(a, s, c, e);
    case 168: MUSTTAIL return state_36(a, s, c, e);
    case 169: MUSTTAIL return state_36(a, s, c, e);
    case 170: MUSTTAIL return state_36(a, s, c, e);
    case 171: MUSTTAIL return state_36(a, s, c, e);
    case 172: MUSTTAIL return state_36(a, s, c, e);
    case 173: MUSTTAIL return state_36(a, s, c, e);
    case 174: MUSTTAIL return state_36(a, s, c, e);
    case 175: MUSTTAIL return state_36(a, s, c, e);
    case 176: MUSTTAIL return state_36(a, s, c, e);
    case 177: MUSTTAIL return state_36(a, s, c, e);
    case 178: MUSTTAIL return state_36(a, s, c, e);
    case 179: MUSTTAIL return state_36(a, s, c, e);
    case 180: MUSTTAIL return state_36(a, s, c, e);
    case 181: MUSTTAIL return state_36(a, s, c, e);
    case 182: MUSTTAIL return state_36(a, s, c, e);
    case 183: MUSTTAIL return state_36(a, s, c, e);
    case 184: MUSTTAIL return state_36(a, s, c, e);
    case 185: MUSTTAIL return state_36(a, s, c, e);
    case 186: MUSTTAIL return state_36(a, s, c, e);
    case 187: MUSTTAIL return state_36(a, s, c, e);
    case 188: MUSTTAIL return state_36(a, s, c, e);
    case 189: MUSTTAIL return state_36(a, s, c, e);
    case 190: MUSTTAIL return state_36(a, s, c, e);
    case 191: MUSTTAIL return state_36(a, s, c, e);
    case 192: MUSTTAIL return state_36(a, s, c, e);
    case 193: MUSTTAIL return state_36(a, s, c, e);
    case 194: MUSTTAIL return state_36(a, s, c, e);
    case 195: MUSTTAIL return state_36(a, s, c, e);
    case 196: MUSTTAIL return state_36(a, s, c, e);
    case 197: MUSTTAIL return state_36(a, s, c, e);
    case 198: MUSTTAIL return state_36(a, s, c, e);
    case 199: MUSTTAIL return state_36(a, s, c, e);
    case 200: MUSTTAIL return state_36(a, s, c, e);
    case 201: MUSTTAIL return state_36(a, s, c, e);
    case 202: MUSTTAIL return state_36(a, s, c, e);
    case 203: MUSTTAIL return state_36(a, s, c, e);
    case 204: MUSTTAIL return state_36(a, s, c, e);
    case 205: MUSTTAIL return state_36(a, s, c, e);
    case 206: MUSTTAIL return state_36(a, s, c, e);
    case 207: MUSTTAIL return state_36(a, s, c, e);
    case 208: MUSTTAIL return state_36(a, s, c, e);
    case 209: MUSTTAIL return state_36(a, s, c, e);
    case 210: MUSTTAIL return state_36(a, s, c, e);
    case 211: MUSTTAIL return state_36(a, s, c, e);
    case 212: MUSTTAIL return state_36(a, s, c, e);
    case 213: MUSTTAIL return state_36(a, s, c, e);
    case 214: MUSTTAIL return state_36(a, s, c, e);
    case 215: MUSTTAIL return state_36(a, s, c, e);
    case 216: MUSTTAIL return state_36(a, s, c, e);
    case 217: MUSTTAIL return state_36(a, s, c, e);
    case 218: MUSTTAIL return state_36(a, s, c, e);
    case 219: MUSTTAIL return state_36(a, s, c, e);
    case 220: MUSTTAIL return state_36(a, s, c, e);
    case 221: MUSTTAIL return state_36(a, s, c, e);
    case 222: MUSTTAIL return state_36(a, s, c, e);
    case 223: MUSTTAIL return state_36(a, s, c, e);
    case 224: MUSTTAIL return state_36(a, s, c, e);
    case 225: MUSTTAIL return state_36(a, s, c, e);
    case 226: MUSTTAIL return state_36(a, s, c, e);
    case 227: MUSTTAIL return state_36(a, s, c, e);
    case 228: MUSTTAIL return state_36(a, s, c, e);
    case 229: MUSTTAIL return state_36(a, s, c, e);
    case 230: MUSTTAIL return state_36(a, s, c, e);
    case 231: MUSTTAIL return state_36(a, s, c, e);
    case 232: MUSTTAIL return state_36(a, s, c, e);
    case 233: MUSTTAIL return state_36(a, s, c, e);
    case 234: MUSTTAIL return state_36(a, s, c, e);
    case 235: MUSTTAIL return state_36(a, s, c, e);
    case 236: MUSTTAIL return state_36(a, s, c, e);
    case 237: MUSTTAIL return state_36(a, s, c, e);
    case 238: MUSTTAIL return state_36(a, s, c, e);
    case 239: MUSTTAIL return state_36(a, s, c, e);
    case 240: MUSTTAIL return state_36(a, s, c, e);
    case 241: MUSTTAIL return state_36(a, s, c, e);
    case 242: MUSTTAIL return state_36(a, s, c, e);
    case 243: MUSTTAIL return state_36(a, s, c, e);
    case 244: MUSTTAIL return state_36(a, s, c, e);
    case 245: MUSTTAIL return state_36(a, s, c, e);
    case 246: MUSTTAIL return state_36(a, s, c, e);
    case 247: MUSTTAIL return state_36(a, s, c, e);
    case 248: MUSTTAIL return state_36(a, s, c, e);
    case 249: MUSTTAIL return state_36(a, s, c, e);
    case 250: MUSTTAIL return state_36(a, s, c, e);
    case 251: MUSTTAIL return state_36(a, s, c, e);
    case 252: MUSTTAIL return state_36(a, s, c, e);
    case 253: MUSTTAIL return state_36(a, s, c, e);
    case 254: MUSTTAIL return state_36(a, s, c, e);
    case 255: MUSTTAIL return state_36(a, s, c, e);
  }
  // Try to avoid warnings about the switch missing cases, which it doesn't
  return result_value(17, 0);

}

lexer_match_t state_79(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] _
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 8
  active = 8;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_80(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] _
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 11
  active = 11;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_81(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] _
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 3
  active = 3;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_82(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] _
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 10
  active = 10;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_83(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] _
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 2
  active = 2;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_84(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] _
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 9
  active = 9;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_85(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] _
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 4
  active = 4;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_86(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] _
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 1
  active = 1;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_87(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] _
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] %
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 7
  active = 7;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t state_88(uint64_t active, byte *start, byte *current, byte *end)
{
  // regex[0] %
  // regex[1] %
  // regex[2] %
  // regex[3] %
  // regex[4] %
  // regex[5] %
  // regex[6] %
  // regex[7] %
  // regex[8] %
  // regex[9] %
  // regex[10] %
  // regex[11] %
  // regex[12] _
  // regex[13] %
  // regex[14] %
  // regex[15] %
  // regex[16] %
  // First nullable state 12
  active = 12;
  if (current == end)
  {
    return result_value(active, (end - start));
  }
  const uint64_t a = active;
  byte *s = start;
  byte *c = current + 1;
  byte *e = end;
  MUSTTAIL return state_36(a, s, c, e);
}

lexer_match_t arith_lexer_a2pc_single_regex_bytes_matching(lexer_t l, size_t regex_idx, lexer_iterator_t iter)
{
  enum {arity = 17,};
  byte* start = (byte*) iter.cursor;
  byte* end = (byte*) iter.end;
  switch(regex_idx)
  {
    case 0: return state_1(arity, start, start, end);
    case 1: return state_2(arity, start, start, end);
    case 2: return state_3(arity, start, start, end);
    case 3: return state_4(arity, start, start, end);
    case 4: return state_5(arity, start, start, end);
    case 5: return state_6(arity, start, start, end);
    case 6: return state_7(arity, start, start, end);
    case 7: return state_8(arity, start, start, end);
    case 8: return state_9(arity, start, start, end);
    case 9: return state_10(arity, start, start, end);
    case 10: return state_11(arity, start, start, end);
    case 11: return state_12(arity, start, start, end);
    case 12: return state_13(arity, start, start, end);
    case 13: return state_14(arity, start, start, end);
    case 14: return state_15(arity, start, start, end);
    case 15: return state_16(arity, start, start, end);
    case 16: return state_17(arity, start, start, end);
    default: return (lexer_match_t) {.regex_id = arity, .bytes_count = 0,};
  }
}

static lexer_match_t state_entry(byte* start, byte* end)
{
  // Initalises active to 'failed'
  return state_0(17, start, start, end);
}

lexer_t arith_lexer_a2pc_create(void)
{
  static enum lexer_engines engine = lexer_engines_a2pc;
  return (lexer_t){.data = (void*)&engine,};
}

void arith_lexer_a2pc_destroy(lexer_t lex)
{
  (void)lex;
}

bool arith_lexer_a2pc_valid(lexer_t lex)
{
  // Check that this lexer is exactly the singleton instance for this language
  lexer_t ref =  arith_lexer_a2pc_create();
  return lex.data == ref.data;
}
size_t arith_lexer_a2pc_regex_count(lexer_t lex)
{
  (void)lex;
  return arith_token_count;
}

lexer_match_t arith_lexer_a2pc_sequence_regex_bytes_matching(lexer_t lex, lexer_iterator_t iter)
{
  byte* start = (byte*)iter.cursor;
  byte* end = (byte*)iter.end;
  return state_entry(start, end);
}

lexer_token_t arith_lexer_a2pc_iterator_step(lexer_t lex, lexer_iterator_t *iter)
{
  lexer_match_t res = arith_lexer_a2pc_sequence_regex_bytes_matching(lex, *iter);
  lexer_token_t result = {
    .id = res.regex_id,
    .value = iter->cursor,
    .width = res.bytes_count,
  };
  iter->cursor += res.bytes_count;
  return result;
}

#endif // LEXER_A2PC_ENABLE
