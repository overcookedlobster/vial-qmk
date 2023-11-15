# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# RP2040-specific options
ALLOW_WARNINGS = yes
PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.

SERIAL_DRIVER = vendor

# This file intentionally left blank
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes            # Enable N-Key Rollover
AUDIO_ENABLE = no           # Audio output
LTO_ENABLE = yes

AUDIO_SUPPORTED = no        # Audio is not supported
SPLIT_KEYBOARD = no

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow

ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

