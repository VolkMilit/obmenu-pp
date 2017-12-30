#define ICONS_PATHS \
{ \
HOME + "/.icons/" + THEME + "/apps/32x32/" + icon, \
HOME + "/.icons/" + THEME + "/apps/192x192/" + icon, \
HOME + "/.icons/" + THEME + "/apps/scalable/" + icon, \
"/usr/share/icons/hicolor/32x32/apps/" + icon, \
"/usr/share/icons/hicolor/48x48/apps/" + icon, \
"/usr/share/icons/hicolor/scalable/apps/" + icon, \
"/usr/lib/python2.7/dist-packages/" + icon + "/data/pixmaps/" + icon, \
"/usr/share/local/icons/hicolor/32x32/apps/" + icon, \
"/usr/share/pixmaps/" + icon, \
HOME + "/.icons/" + THEME + "/status/24x24/" + icon \
}
	
#define CAT_ICONS_PATHS \
	HOME + "/.icons/" + THEME + "/categories/scalable/"
//{
//}

#define DESKTOP_PATHS \
{ \
"/usr/share/applications/", \
"/usr/local/share/applications/", \
HOME + "/.local/share/applications/", \
HOME + "/.local/share/applications/Dev/", \
HOME + "/.local/share/applications/Games/", \
HOME + "/.local/share/applications/Tools/" \
}

#define CATEGORIES \
{ \
"AudioVideo", \
"Development", \
"Game", \
"Graphics", \
"Network", \
"Office", \
"Settings", \
"System", \
"Utility", \
}

#define HIDE \
{ \
	"Tint2", \
	"Process Viewer", \
	"Metadata Anonymisation Toolkit", \
	"Vim", \
	"ClipIt", \
	"compton", \
	"SpaceFM File Search", \
	"OpenJDK Java 8 Policy Tool", \
	"ImageMagick (color depth=q16)", \
	"Icon Browser", \
	"mpv Media Player", \
	"Midnight Commander editor" \
}

#define MISSING \
	HOME + "/.icons/myelementary/status/24/gtk-missing-image.svg"

#define USER_DEFINE \
	element(getIcon("firefox"), "Веб-браузер", "firejail --no3d firefox"); \
    element(getIcon("thunderbird"), "Почта", "thunderbird"); \
	pipe(getIcon("steam"), "Steam", "/home/volk/Projects/obmenu-generator-pp/obmenu-generator-pp/steam-pipe"); \
	element(getIcon("keepassx"), "KeePassX", "keepassx"); \
	element(getIcon("deadbeef"), "DeadBeef", "deadbeef"); \
	element(getIcon("deluge"), "Deluge", "deluge"); \
	element(getIcon("geany"), "Geany", "geany"); \
	element(getIcon("gimp"), "GIMP", "gimp");
