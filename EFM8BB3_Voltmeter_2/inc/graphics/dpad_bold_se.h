#define dpad_bold_se_width 16
#define dpad_bold_se_height 16
static SI_SEGMENT_VARIABLE(dpad_bold_se_bits[], const uint8_t, SI_SEG_CODE) = {
  0x60, 0x00, 0xF0, 0x00, 0xF8, 0x80, 0x7D, 0x80, 0x3F, 0x80, 0x1F, 0x80, 
  0x0F, 0x80, 0x1F, 0x80, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
