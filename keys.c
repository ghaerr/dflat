/* ------------- keys.c ----------- */

#include <stdio.h>
#include "keys.h"

struct keys keys[] = {
	{HOME,		"Home"},
	{UP,		"Up"},
	{PGUP,		"PgUp"},
	{BS,		"BS"},
	{END,		"End"},
	{DN,		"Dn"},
	{PGDN,		"PgDn"},
	{INS,		"Ins"},
	{DEL,		"Del"},

	{F1,		"F1"},
	{F2,		"F2"},
	{F3,		"F3"},
	{F4,		"F4"},
	{F5,		"F5"},
	{F6,		"F6"},
	{F7,		"F7"},
	{F8,		"F8"},
	{F9,		"F9"},
	{F10,		"F10"},

	{ALT_A,		"Alt+A"},
	{ALT_B,		"Alt+B"},
	{ALT_C,		"Alt+C"},
	{ALT_D,		"Alt+D"},
	{ALT_E,		"Alt+E"},
	{ALT_F,		"Alt+F"},
	{ALT_G,		"Alt+G"},
	{ALT_H,		"Alt+H"},
	{ALT_I,		"Alt+I"},
	{ALT_J,		"Alt+J"},
	{ALT_K,		"Alt+K"},
	{ALT_L,		"Alt+L"},
	{ALT_M,		"Alt+M"},
	{ALT_N,		"Alt+N"},
	{ALT_O,		"Alt+O"},
	{ALT_P,		"Alt+P"},
	{ALT_Q,		"Alt+Q"},
	{ALT_R,		"Alt+R"},
	{ALT_S,		"Alt+S"},
	{ALT_T,		"Alt+T"},
	{ALT_U,		"Alt+U"},
	{ALT_V,		"Alt+V"},
	{ALT_W,		"Alt+W"},
	{ALT_X,		"Alt+X"},
	{ALT_Y,		"Alt+Y"},
	{ALT_Z,		"Alt+Z"},
#if MSDOS
	{CTRL_F1,	"Ctrl+F1"},
	{CTRL_F2,	"Ctrl+F2"},
	{CTRL_F3,	"Ctrl+F3"},
	{CTRL_F4,	"Ctrl+F4"},
	{CTRL_F5,	"Ctrl+F5"},
	{CTRL_F6,	"Ctrl+F6"},
	{CTRL_F7,	"Ctrl+F7"},
	{CTRL_F8,	"Ctrl+F8"},
	{CTRL_F9,	"Ctrl+F9"},
	{CTRL_F10,	"Ctrl+F10"},
	{ALT_F1,	"Alt+F1"},
	{ALT_F2,	"Alt+F2"},
	{ALT_F3,	"Alt+F3"},
	{ALT_F4,	"Alt+F4"},
	{ALT_F5,	"Alt+F5"},
	{ALT_F6,	"Alt+F6"},
	{ALT_F7,	"Alt+F7"},
	{ALT_F8,	"Alt+F8"},
	{ALT_F9,	"Alt+F9"},
	{ALT_F10,	"Alt+F10"},
	{CTRL_HOME,	"Ctrl+Home"},
	{CTRL_PGUP,	"Ctrl+PgUp"},
	{CTRL_BS,	"Ctrl+BS"},
	{CTRL_END,	"Ctrl+End"},
	{CTRL_PGDN,	"Ctrl+PgDn"},
	{SHIFT_HT,	"Shift+Tab"},
	{ALT_BS,	"Alt+BS"},
	{ALT_DEL,   "Alt+Del"},
	{SHIFT_DEL,	"Shift+Del"},
	{SHIFT_INS,	"Shift+Ins"},
	{CTRL_INS,	"Ctrl+Ins"},
#endif
	{-1,		NULL}
};
