# The Default Helix Layout
## Layout

### Qwerty

```
,-------------------------------------.               ,------------------------------------------.
|  `  |  1  |  2  |  3  |  4  |   5   |               |   6  |   7  |   8   |   9   |   0  |  =  |
|-----+-----+-----+-----+-----+-------|               |------+------+-------+-------+------+-----|
| Tab |  Q  |  W  |  E  |  R  |   T   |               |   Y  |   U  |   I   |   O   |   P  |  -  |
|-----+-----+-----+-----+-----+-------|               |------+------+-------+-------+------+-----|
|Ctrl |  A  |  S  |  D  |  F  |   G   |               |   H  |   J  |   K   |   L   |   ;  |  '  |
|-----+-----+-----+-----+-----+-------+-------+-------+------+------+-------+-------+------+-----|
|Shift|  Z  |  X  |  C  |  V  |   B   |  ESC  |Backsp |   N  |   M  |   ,   |   .   |   /  |  \  |
|-----+-----+-----+-----+-----+-------+-------+-------+------+------+-------+-------+------+-----|
|Op/Wi|Adjst| Spc |  [  |  ]  |Cmd/Alt|Eis/Low|Kan/Rai|Sht/Sp|Enter |Opt/Win|Cmd/Alt|   ¥  | Esc |
`------------------------------------------------------------------------------------------------'
```

## Layers

|Priority|number|name|description|
| ---- | ---- | --- | --- |
|high|16|Adjust|Functions|
||4|Raise|Numeric charactors|
||3|Lower|Other charactors|
||2|Dvorak|Dvorak leyout|
||1|Colemak|Colemak leyout|
|low|0|Qwerty|QWERTY leyout(base)|

### Lower
```
,-----------------------------------------.             ,-----------------------------------------.
|      |      |      |      |ScLeft|ScRght|             |      |      |      |      |      |      |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|      |      | MsUp |      |ScDown| ScUp |             |   ^  |   +  |   *  |      |   (  |   )  |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|      |MsLeft|MsDown|MsRght|LClick|RClick|             |      |   _  |   =  |      |   [  |   ]  |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|      | Next | Vol- | Vol+ | Play |      |      |      |      |      |      |      |   {  |   }  |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |      |      |
`-------------------------------------------------------------------------------------------------'
```

### Raise
```
,-----------------------------------------.             ,-----------------------------------------.
|      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|      |      |NUMLOC|      |      |      |             | Home |PgDown| PgUp | End  |  ~   | F12  |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|      | CAPS | Sclc |Insert| PrtSc| Pause|             | Left | Down |  Up  | Right|  |   |      |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      | DEL  | Bksp | Menu |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |      |      |
`-------------------------------------------------------------------------------------------------'
```

### Adjust (Lower + Raise)
```
,-----------------------------------------.             ,-----------------------------------------.
| Reset|      |      |      |      |      |             |      |      |      |      |      |      |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|      |      |RGBRST|      |      | Win  |             |      |      |      |      |      |      |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|      |      |      |Aud on|Audoff| Mac  |             |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|      | MODE | HUE+ | SAT+ | VAL+ |      |QWERTY|      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|RGB ON|      | HUE- | SAT- | VAL- |      |FLOGGY|      |      |      |      |      |      |      |
`-------------------------------------------------------------------------------------------------'
```

## Customize

see `qmk_firmware/keyboards/helix/rev2/keymaps/default/rules.mk`

```
# Helix Spacific Build Options
# you can uncomment and edit follows 7 Variables
#  jp: 以下の7つの変数を必要に応じて編集し、コメントアウトをはずします。
# HELIX_ROWS = 5              # Helix Rows is 4 or 5
# OLED_ENABLE = no            # OLED_ENABLE
# LOCAL_GLCDFONT = no         # use each keymaps "helixfont.h" insted of "common/glcdfont.c"
# LED_BACK_ENABLE = no        # LED backlight (Enable WS2812 RGB underlight.)
# LED_UNDERGLOW_ENABLE = no   # LED underglow (Enable WS2812 RGB underlight.)
# LED_ANIMATIONS = yes        # LED animations
# IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)
```
## Compile

go to qmk top directory.
```
$ cd qmk_firmware
```

build
```
$ make helix:default
$ make helix/rev2/back:default               # with backlight
$ make HELIX=no_ani helix/rev2/back:default  # with backlight without animation
$ make helix/rev2/under:default              # with underglow
$ make helix/rev2/oled:default               # with oled
$ make helix/rev2/oled/back:default          # with oled and backlight
$ make helix/rev2/oled/under:default         # with oled and underglow
```

flash to keyboard
```
$ make helix:default:flash
$ make helix/rev2/back:default:flash               # with backlight
$ make HELIX=no_ani helix/rev2/back:default:flash  # with backlight without animation
$ make helix/rev2/under:default:flash              # with underglow
$ make helix/rev2/oled:default:flash               # with oled
$ make helix/rev2/oled/back:default:flash          # with oled and backlight
$ make helix/rev2/oled/under:default:flash         # with oled and underglow

```

## Link
* more detail wrote in Japanese [helix/Doc/firmware_jp.md](https://github.com/MakotoKurauchi/helix/blob/master/Doc/firmware_jp.md)
* [Helix top](https://github.com/MakotoKurauchi/helix)

