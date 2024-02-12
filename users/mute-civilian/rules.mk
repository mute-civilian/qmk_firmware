SRC += mutecivilian.c
SRC += features/secrets.c
SRC += process_records.c

ifeq ($(strip $(CUSTOM_POINTING_DEVICE)), yes)
	SRC += features/pointing.c
endif

SERIAL_DRIVER = vendor

ifeq ($(strip $(POINTING_DEVICE)), trackpoint_cirque35)
	OPT_DEFS += -DPOINTING_DEVICE_TRACKPOINT_CIRQUE35

	POINTING_DEVICE_ENABLE = yes
	OPT_DEFS += -DSPLIT_POINTING_ENABLE
	OPT_DEFS += -DPOINTING_DEVICE_COMBINED

	ifeq ($(strip $(SIDE)), left)
		PS2_ENABLE = yes
		PS2_DRIVER = vendor
		POINTING_DEVICE_DRIVER = ps2
	endif
	ifeq ($(strip $(SIDE)), right)
		POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
	endif
endif

MOUSEKEY_ENABLE       = yes
COMBO_ENABLE          = yes
CAPS_WORD_ENABLE      = yes

ifeq ($(strip $(ENCODER_ENABLE)), yes)
	ENCODER_MAP_ENABLE = yes
endif

# save space on MCU by disabling unused features
BOOTMAGIC_ENABLE      = no
COMMAND_ENABLE        = no
CONSOLE_ENABLE        = no
GRAVE_ESC_ENABLE      = no
MAGIC_ENABLE          = no
MUSIC_ENABLE          = no
RGB_MATRIX_ENABLE     = no
RGB_MATRIX_SUPPORTED  = no
RGB_LIGHT_SUPPORTED   = no
SPACE_CADET_ENABLE    = no
# end save space
