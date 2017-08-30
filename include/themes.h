/*
*   This file is part of Anemone3DS
*   Copyright (C) 2016-2017 Alex Taber ("astronautlevel"), Dawid Eckert ("daedreth")
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#ifndef THEMES_H
#define THEMES_H

#include <3ds.h>

#define TEX_COUNT       1

typedef struct {
    u16 name[0x40];
    u16 desc[0x80];
    u16 author[0x40];
    char icon_data[0x1200];
    u16 path[262];
    bool is_zip;
    bool selected;
    ssize_t preview_id;
    bool has_preview;
    char preview_path[0x106];
} theme;

void parse_smdh(theme *entry, u16 *path);
int scan_themes(theme **themes, int num_themes);
Result single_install(theme);
Result shuffle_install(theme **themes_list, int num_themes);

#endif