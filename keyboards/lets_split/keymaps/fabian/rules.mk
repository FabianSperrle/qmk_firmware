# Build Options
#   change to "no" to disable the options, or define them in the Makefile in 
#   the appropriate keymap folder that will get included automatically
#
# UNICODE_ENABLE = yes

TAP_DANCE_ENABLE = yes
BOOTMAGIC_ENABLE = false
RGBLIGHT_ENABLE = yes
ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
