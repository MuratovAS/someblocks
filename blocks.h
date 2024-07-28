#include "../theme.h"
// Modify this file to change what commands output to your statusbar, and recompile using the make command.
// https://glyphsearch.com
// https://www.nerdfonts.com/cheat-sheet

static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"^lm()^lm($TERM watch sensors) ", "sensors k10temp-pci-00c3 | grep -o '+.*C'",	3,		0},
	{"^lm()^lm($TERM htop)󰘚 ", "free -h | awk '/^Mem/ { print $3 }' | sed s/i//g",	3,		0},
	{"^lm()^lm($TERM htop)󰍛 ", "echo \"$[100-$(vmstat 1 1 | tail -1 | awk '{print $15}')]\"%",	3,		0},
	{"^lm()^us(pkill -RTMIN+5 someblocks;light -A 5)^ds(pkill -RTMIN+5 someblocks;light -U 5)󰃟 ", "light | cut -f1 -d '.' | tr -d '\n' ; echo '%'",		15,		5},
	{"^us()^ds()󰂀 ", "cat /sys/class/power_supply/BAT0/capacity | tr -d '\n'; echo '%'",					30,		0},
	{"^lm($TERM pulsemixer)^rm(pamixer -t)^ds(pamixer -d 2;pkill -RTMIN+6 someblocks)^us(pamixer -i 2;pkill -RTMIN+6 someblocks)󰕾 ", "pamixer --get-volume-human",					10,		6},
	{"^lm()^rm()^us()^ds()", "$HOME/.local/bin/tray.sh",					15,		8},
	{"^lm($TERM khal interactive)", "date '+%d/%m %H:%M'",					30,		0},
};

// sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 3;
