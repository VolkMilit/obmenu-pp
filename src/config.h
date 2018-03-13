#define DISPLAY_LASTES 1 // display lastes files

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
HOME + "/.icons/" + THEME + "/status/24x24/" + icon, \
HOME + "/.local/share/icons/" + icon, \
HOME + "/.local/share/icons/hicolor/32x32/apps/" + icon, \
}
	
#define CAT_ICONS_PATHS \
	HOME + "/.icons/" + THEME + "/categories/scalable/"
//{
//}

#define DESKTOP_PATHS \
{ \
"/usr/share/applications/", \
"/usr/local/share/applications/", \
menu.HOME + "/.local/share/applications/", \
menu.HOME + "/.local/share/applications/Dev/", \
menu.HOME + "/.local/share/applications/Games/", \
menu.HOME + "/.local/share/applications/Tools/" \
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
	"Midnight Commander editor", \
	"TeXdoctk" \
}

#define MISSING \
	HOME + "/.icons/myelementary/status/24/gtk-missing-image.svg"

// quick menu top
#define USER_DEFINE \
	menu.element(menu.getIcon("firefox"), "Веб-браузер", "palemoon-bin"); \
    menu.element(menu.getIcon("thunderbird"), "Почта", "firejail --no3d thunderbird"); \
	menu.pipe(menu.getIcon("steam"), "Steam", "steam-pipe"); \
	menu.element(menu.getIcon("keepassx"), "KeePassX", "keepassx"); \
	menu.element(menu.getIcon("deadbeef"), "DeadBeef", "deadbeef"); \
	menu.element(menu.getIcon("deluge"), "Deluge", "deluge"); \
	menu.element(menu.getIcon("geany"), "Geany", "geany"); \
	menu.element(menu.getIcon("gimp"), "GIMP", "gimp");

// quick menu bottom
# define USER_DEFINE2 \
	menu.xmlmenu("shutdown", menu.catIcon("Shutdown"), "Выключение");
