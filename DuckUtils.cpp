#include "DuckUtils.h"

namespace duckutils {
String createUuid() {
  String msg = "";
  int i;

  for (i = 0; i < CDPCFG_UUID_LEN; i++) {
    byte randomValue = random(0, 36);
    if (randomValue < 26) {
      msg = msg + char(randomValue + 'a');
    } else {
      msg = msg + char((randomValue - 26) + '0');
    }
  }
  Serial.print("createUuid: ");
  Serial.println(msg);
  return msg;
}

String convertToHex(byte* data, int size) {
  String buf = "";
  buf.reserve(size * 2);
  const char* cs = "0123456789abcdef";
  for (int i = 0; i < size; i++) {
    byte val = data[i];
    buf += cs[(val >> 4) & 0x0f];
    buf += cs[val & 0x0f];
  }
  return buf;
}
}