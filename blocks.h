#include "../theme.h"
// Modify this file to change what commands output to your statusbar, and recompile using the make command.
// https://glyphsearch.com
// https://www.nerdfonts.com/cheat-sheet

static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"^lm()^lm($TERM watch sensors) ", "cat /sys/class/hwmon/hwmon4/temp1_input | head -c2; echo '°C'",	3,		0},
	{"^lm()^lm($TERM htop)󰘚 ", "free -h | awk '/^Mem/ { print $3 }' | sed s/i//g",	3,		0},
	{"^lm()^lm($TERM htop)󰍛 ", "echo \"$[100-$(vmstat 1 1 | tail -1 | awk '{print $15}')]\"%",	3,		0},
	{"^lm()^lm(pkill -RTMIN+5 someblocks;light -A 5)^rm(pkill -RTMIN+5 someblocks;light -U 5)󰃟 ", "light | cut -f1 -d '.' | tr -d '\n' ; echo '%'",		15,		5},
	{"^lm()^rm()󰂀 ", "cat /sys/class/power_supply/BAT0/capacity | tr -d '\n'; echo '%'",					30,		0},
	{"^lm()^lm($TERM pulsemixer)^rm(pamixer -t)󰕾 ", "pamixer --get-volume-human",					10,		0},
	//{"^lm()^rm() ", "cat /tmp/dwl-keymap",					0,		10},
	{"^lm()^rm()", "$HOME/.local/bin/tray.sh",					15,		8},
	{"^lm()^lm($TERM khal interactive)", "date '+%d/%m %H:%M'",					30,		0},
};

// sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 3;
