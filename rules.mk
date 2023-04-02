# Build Options

MCU = atmega32u4
BOOTLOADER = atmel-dfu

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

AUDIO_SUPPORTED = no        # Audio is not supported
RGB_MATRIX_SUPPORTED = no  # RGB matrix is supported and enabled by default
RGBLIGHT_SUPPORTED = no    # RGB underglow is supported, but not enabled by default
RGB_MATRIX_ENABLE = no     # Enable keyboard RGB matrix (do not use together with RGBLIGHT_ENABLE)
SLEEP_LED_ENABLE = no


TAP_DANCE_ENABLE = no
LTO_ENABLED = yes
CAPS_WORD_ENABLED = yes # hidden caps lock-ish for a word

SPLIT_KEYBOARD = yes

# combos 
VPATH  +=  keyboards/gboards
COMBO_ENABLE = yes
