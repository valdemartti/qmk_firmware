/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

/*
Explanation for custom keys:

SShot = Screenshot
SCap = Screen Capture
DesktpL = Desktop Left (ctrl+left)
DesktpR = Desktop Right (ctrl+right)
OptUp = Option Up (opt+up)
OptLeft = Option Left (opt+left)
OptDown = Option Down (opt+down)
OptRig = Option Right (opt+right)
GitComm = Git Commit (VSCODE shortcut)
GitPush = Git Push (VSCODE shortcut)
MedBack = Media Back
MedPaus = Media Pause
MedForw = Media Forward
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // LAYER 0 (MO(0))
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      Tab,     q Q,     w W,     e E,     r R,     t T,                          y Y,     u U,     i I,     o O,     p P,   Bkspc,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //    Lctrl,     a A,     s S,     d D,     f F,     g G,                          h H,     j J,     k K,     l L,     ö Ö,     ä Ä,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //   Lshift,     z Z,     x X,     c C,     v V,     b B,                          n N,     m M,     , ;,     . :,     - _,     Esc,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //      Cmd,   MO(1),   Space,      Enter,   MO(2),    RAlt
                                      //`--------------------------'  `--------------------------'

    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  // LAYER 1 (MO(1))
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      Tab,      F1,      F2,      F3,      F4,      F5,                            =,       <,       >,       ',       `,   Bkspc,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //    Lctrl,      F6,      F7,      F8,      F9,     F10,                            /,       {,       },       ",       *,       |,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //   Lshift,     F11,     F12,       ^,       ~,       %,                            \,       (,       ),       [,       ],     Esc,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //      Cmd,        ,   Space,      Enter,   MO(3),    RAlt
                                      //`--------------------------'  `--------------------------'

    [1] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.                    ,-----------------------------------------------------------------------------.
       KC_TAB,   KC_F1,   KC_F2,      KC_F3,         KC_F4,   KC_F5,                            S(KC_0),    KC_NUBS, S(KC_NUBS),    KC_NUHS,  S(KC_EQL),       KC_BSPC,
  //|--------+--------+--------+-----------+--------------+--------|                    |--------------+-----------+-----------+-----------+-----------+--------------|
      KC_LCTL,   KC_F6,   KC_F7,      KC_F8,         KC_F9,  KC_F10,                            S(KC_7), ALGR(KC_7), ALGR(KC_0),    S(KC_2), S(KC_NUHS), ALGR(KC_NUBS),
  //|--------+--------+--------+-----------+--------------+--------|                    |--------------+-----------+-----------+-----------+-----------+--------------|
      KC_LSFT,  KC_F11,  KC_F12, S(KC_RBRC), ALGR(KC_RBRC), S(KC_5),                      ALGR(KC_MINS),    S(KC_8),    S(KC_9), ALGR(KC_8), ALGR(KC_9),        KC_ESC,
  //|--------+--------+--------+-----------+--------------+--------+--------|  |--------+--------------+-----------+-----------+-----------+-----------+--------------|
                                                   KC_LGUI, _______,  KC_SPC,     KC_ENT,         MO(3),    KC_RALT
                                         //`--------------------------------'  `-----------------------------------'
  ),

  // LAYER 2 (MO(2))
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      Tab,       #,       @,       ?,       !,       &,                      NumLock, DesktpL,      up, DesktpR,        ,   Bkspc,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //    Lctrl,       1,       2,       3,       4,       5,                     CapsLock,    left,    down,   right,        ,     å Å,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //   Lshift,       6,       7,       8,       9,       0,                             ,        ,        ,        ,        ,     Esc,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //      Cmd,   MO(3),   Space,      Enter,        ,    RAlt
                                      //`--------------------------'  `--------------------------'

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------.                    ,------------------------------------------------------------------.
       KC_TAB, S(KC_3), ALGR(KC_2), S(KC_MINS), S(KC_1), S(KC_6),                       KC_NUM, LCTL(KC_LEFT),   KC_UP, LCTL(KC_RIGHT), XXXXXXX, KC_BSPC,
  //|--------+--------+-----------+-----------+--------+--------|                    |--------+--------------+--------+---------------+--------+--------|
      KC_LCTL,    KC_1,       KC_2,       KC_3,    KC_4,    KC_5,                      KC_CAPS,       KC_LEFT, KC_DOWN,        KC_RGHT, XXXXXXX, KC_LBRC,
  //|--------+--------+-----------+-----------+--------+--------|                    |--------+--------------+--------+---------------+--------+--------|
      KC_LSFT,    KC_6,       KC_7,       KC_8,    KC_9,    KC_0,                      XXXXXXX,       XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+-----------+-----------+--------+--------+--------|  |--------+--------+--------------+--------+---------------+--------+--------|
                                                KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______,       KC_RALT
                                            //`--------------------------'  `--------------------------------'
  ),

  // LAYER 3 (MO(3))
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      Tab,        ,        ,        ,   SShot,    SCap,                             ,        ,   OptUp,        ,        ,   Bkspc,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //    Lctrl, GitComm, GitPush, VolMute, VolDown,   VolUp,                             , OptLeft, OptDown,  OptRig,        , LockSc ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //   Lshift,        ,        , MedBack, MedPaus, MedForw,                             ,        ,        ,        ,        ,     Esc,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //      Cmd,        ,   Space,      Enter,        ,    RAlt
                                      //`--------------------------'  `--------------------------'

    [3] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------------------------------.                    ,--------------------------------------------------------------------------------.
       KC_TAB,       XXXXXXX,       XXXXXXX,    XXXXXXX,     S(LGUI(KC_4)),   S(LGUI(KC_5)),                      XXXXXXX,       XXXXXXX,   LOPT(KC_UP),       XXXXXXX, XXXXXXX,          KC_BSPC,
  //|--------+--------------+--------------+-----------+------------------+----------------|                    |--------+--------------+--------------+--------------+--------+-----------------|
      KC_LCTL, S(LOPT(KC_C)), S(LOPT(KC_P)), KC_KB_MUTE, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP,                      XXXXXXX, LOPT(KC_LEFT), LOPT(LC_DOWN), LOPT(KC_RGHT), XXXXXXX, LCTL(LGUI(KC_Q)),
  //|--------+--------------+--------------+-----------+------------------+----------------|                    |--------+--------------+--------------+--------------+--------+-----------------|
      KC_LSFT,       XXXXXXX,       XXXXXXX,    KC_MPRV,           KC_MPLY,         KC_MNXT,                      XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX,           KC_ESC,
  //|--------+--------------+--------------+-----------+------------------+----------------+--------|  |--------+--------+--------------+--------------+--------------+--------+-----------------|
                                                                   KC_LGUI,         _______,  KC_SPC,     KC_ENT, _______,       KC_RALT
                                                     //`--------------------------------------------'  `--------------------------------'
  )
};