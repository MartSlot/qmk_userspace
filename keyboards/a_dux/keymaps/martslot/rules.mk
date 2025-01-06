CONVERT_TO = liatris

# Supported keycodes
MOUSEKEY_ENABLE = yes      # Mouse movement using keys
EXTRAKEY_ENABLE = yes      # Audio and system control

# N-key rollover instead of 6-key rollover
NKRO_ENABLE = yes          # Enable N-Key Rollover

AUTO_SHIFT_ENABLE = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
LEADER_ENABLE = yes
OS_DETECTION_ENABLE = yes

INTROSPECTION_KEYMAP_C = shared/introspection.c
SRC += shared/casemode.c
SRC += shared/keymap.c
SRC += shared/layers.c
SRC += shared/leader.c
SRC += shared/switcher.c
SRC += shared/tap_hold.c
SRC += empty.c
