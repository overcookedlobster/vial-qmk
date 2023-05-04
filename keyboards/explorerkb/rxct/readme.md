# Explorer Keyboard RxCT

![Explorer Keyboard RxCT](https://github.com/DreaM117er/Explorer-Keyboard-RxCT/blob/main/image0.jpg)

A spilt keyboard fully supported camara tripod, based on 4x5/3x5 main martrix, optional expanded 1 column to be 4x6/3x6 or more; 7 levels adjustable thumb cluster angle basepart, supported 1-4 thumb keys installed.

* Keyboard Maintainer: [DreaM117er](https://github.com/DreaM117er)
* Hardware Supported: ATmega32U4 MCU
* Hardware Availability: https://github.com/DreaM117er/vial-qmk/tree/vial/keyboards/explorerkb/

Make example for this keyboard (after setting up your build environment):

    make explorerkb:default

Flashing example for this keyboard:

    make explorerkb:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
