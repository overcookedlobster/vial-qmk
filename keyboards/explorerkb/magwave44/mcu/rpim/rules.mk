# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# RP2040-specific options
ALLOW_WARNINGS = yes
PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.

SERIAL_DRIVER = vendor

# RGB settiing
WS2812_DRIVER = vendor

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
RGBLIGHT_ENABLE = no
