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

Both Space and Enter work as Rectangle keys when held down (presses Left Ctrl + Left ALT when held)
*/

enum {
    A = KC_A,
    B = KC_B,
    C = KC_C,
    D = KC_D,
    E = KC_E,
    F = KC_F,
    G = KC_G,
    H = KC_H,
    I = KC_I,
    J = KC_J,
    K = KC_K,
    L = KC_L,
    M = KC_M,
    N = KC_N,
    O = KC_O,
    P = KC_P,
    Q = KC_Q,
    R = KC_R,
    S = KC_S,
    T = KC_T,
    U = KC_U,
    V = KC_V,
    W = KC_W,
    X = KC_X,
    Y = KC_Y,
    Z = KC_Z,
    OE = KC_SCLN,
    AE = KC_QUOT,
    AO = KC_LBRC,
    LShift = KC_LSFT,
    LCtrl = KC_LCTL,
    LAlt = KC_LALT,
    LCmd = KC_LGUI,
    RShift = KC_RSFT,
    RCtrl = KC_RCTL,
    RAlt = KC_RALT,
    RCmd = KC_RGUI,
    Esc = KC_ESC,
    Bkspc = KC_BSPC,
    Comma = KC_COMM,
    Dot = KC_DOT,
    Dash = KC_SLSH,
    Tab = KC_TAB,

    Layer1 = LT(1, KC_BSPC),
    Layer2 = LT(2, KC_BSPC),
    Layer3 = LT(3, KC_DELETE),
    Layer4 = TG(4),
    Layer5 = TG(5),
    Layer6 = LT(6, S(LOPT(KC_Q))),

    Space = KC_SPC,
    Enter = KC_ENT,
    RectSpace = MT(MOD_LCTL | MOD_LALT, KC_SPC),
    RectEnter = MT(MOD_LCTL | MOD_LALT, KC_ENT),
    RectTab = MT(MOD_LCTL | MOD_LALT, KC_TAB),

    FN1 = KC_F1,
    FN2 = KC_F2,
    FN3 = KC_F3,
    FN4 = KC_F4,
    FN5 = KC_F5,
    FN6 = KC_F6,
    FN7 = KC_F7,
    FN8 = KC_F8,
    FN9 = KC_F9,
    FN10 = KC_F10,
    FN11 = KC_F11,
    FN12 = KC_F12,

    Tilde = KC_RBRC,
    Plus = KC_MINS,
    Percent = S(KC_5),
    Equal = S(KC_0),
    Less = KC_GRV,
    More = S(KC_GRV),
    SQuot = KC_NUHS,
    CQuot = S(KC_EQL),
    DQuot = S(KC_2),
    Slash = S(KC_7),
    BSlash = S(ALGR(KC_7)),
    LBrace = S(ALGR(KC_8)),
    RBrace = S(ALGR(KC_9)),
    Star = S(KC_NUHS),
    Wall = ALGR(KC_7),
    LBrackt = S(KC_8),
    RBrackt = S(KC_9),
    LArray = ALGR(KC_8),
    RArray = ALGR(KC_9),
    Hash = S(KC_3),
    At = ALGR(KC_2),
    QMark = S(KC_MINS),
    Excl = S(KC_1),
    And = S(KC_6),
    Dollar = ALGR(KC_4),
    Euro = S(KC_4),

    N1 = KC_1,
    N2 = KC_2,
    N3 = KC_3,
    N4 = KC_4,
    N5 = KC_5,
    N6 = KC_6,
    N7 = KC_7,
    N8 = KC_8,
    N9 = KC_9,
    N0 = KC_0,

    NLock = KC_NUM,
    CLock = KC_CAPS,

    Up = KC_UP,
    Down = KC_DOWN,
    Left = KC_LEFT,
    Right = KC_RGHT,

    LDesktp = LCTL(KC_LEFT),
    RDesktp = LCTL(KC_RIGHT),

    Mouse1 = KC_MS_BTN1,
    Mouse2 = KC_MS_BTN2,
    MUp = KC_MS_UP,
    MDown = KC_MS_DOWN,
    MLeft = KC_MS_LEFT,
    MRight = KC_MS_RIGHT,

    ScrUp = KC_MS_WH_UP,
    ScrDown = KC_MS_WH_DOWN,

    VolUp = KC_AUDIO_VOL_UP,
    VolDown = KC_AUDIO_VOL_DOWN,
    VolMute = KC_AUDIO_MUTE,
    MedBack = KC_MEDIA_PREV_TRACK,
    MedPaus = KC_MEDIA_PLAY_PAUSE,
    MedForw = KC_MEDIA_NEXT_TRACK,

    SShot = S(LGUI(KC_4)),
    SCap = S(LGUI(KC_5)),

    GitComm = S(LOPT(KC_C)),
    GitPush = S(LOPT(KC_P)),
    GitChec = S(LOPT(KC_V)),
    GitPull = S(LOPT(KC_L)),

    OUp = LALT(KC_UP),
    OLeft = LALT(KC_LEFT),
    ODown = LALT(KC_DOWN),
    ORight = LALT(KC_RGHT),

    LockSc = LCTL(LGUI(KC_Q)),

    GCAuthA = SAFE_RANGE,
    GCAuthL,
    HomeLessTap, // MT(MOD_LALT, KC_GRV)
    HomeMoreTap, // MT(MOD_LALT, S(KC_GRV))

    VSSugg = LOPT(KC_ESC),
    VSDef,
    VSPeek = LOPT(KC_F12),

    HomeA = MT(MOD_LCTL, KC_A),
    HomeFN6 = MT(MOD_LCTL, KC_F6),
    HomeTilde = MT(MOD_LCTL, KC_RBRC),
    HomeUndo = MT(MOD_LCTL, LGUI(KC_Z)),
    HomeVolUp = MT(MOD_LCTL, KC_AUDIO_VOL_UP),

    HomeS = MT(MOD_LALT, KC_S),
    HomeFN7 = MT(MOD_LALT, KC_F7),
    HomeCut = MT(MOD_LALT, LGUI(KC_X)),
    HomeLess = MT(MOD_LALT, HomeLessTap),
    HomeMore = MT(MOD_LALT, HomeMoreTap),

    HomeD = MT(MOD_LSFT, KC_D),
    HomeFN8 = MT(MOD_LSFT, KC_F8),
    HomeLArray = MT(MOD_LSFT, ALGR(KC_8)),
    HomeCopy = MT(MOD_LSFT, LGUI(KC_C)),
    HomeRArray = MT(MOD_LSFT, ALGR(KC_9)),

    HomeF = MT(MOD_LGUI, KC_F),
    HomeFN9 = MT(MOD_LGUI, KC_F9),
    HomeLBrackt = MT(MOD_LGUI, S(KC_8)),
    HomePaste = MT(MOD_LGUI, LGUI(KC_V)),
    HomeRBrackt = MT(MOD_LGUI, S(KC_9)),

    HomeJ = MT(MOD_RGUI, KC_J),
    HomeN2 = MT(MOD_RGUI, KC_2),

    HomeK = MT(MOD_RSFT, KC_K),
    HomeN3 = MT(MOD_RSFT, KC_3),

    HomeL = MT(MOD_LALT, KC_L),
    HomeN4 = MT(MOD_LALT, KC_4),

    HomeOE = MT(MOD_RCTL, KC_SCLN),
    HomeN5 = MT(MOD_RCTL, KC_5),
};

void keyboard_post_init_user(void) {  
    // Initialize RGB to static black  
    rgblight_enable_noeeprom();  
    rgblight_sethsv_noeeprom(HSV_BLACK);  
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);  
}

void housekeeping_task_user(void) {  
    rgblight_setrgb_at(10, 0, 0, 0);
    rgblight_setrgb_at(10, 0, 0, 28);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case GCAuthA:
        if (record->event.pressed) {
            // The Slash key produces a dash in the US layout
            SEND_STRING("gcloud auth application/default login");
        }
        break;
    case GCAuthL:
        if (record->event.pressed) {
            SEND_STRING("gcloud auth login");
        }
        break;
    case HomeLess:
        // if tapped send KC_GRV, otherwise hold LALT
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_GRV);
            return false;
        }
        break;
    case HomeMore:
        // if tapped send S(KC_GRV), otherwise hold LALT
        if (record->tap.count && record->event.pressed) {
            tap_code16(S(KC_GRV));
            return false;
        }
        break;
    case VSDef:
        if (record->event.pressed) {
            tap_code16(KC_ESC);
            tap_code16(KC_F12);
            return false;
        }
        break;
    case MT(MOD_LSFT, ALGR(KC_8)):
        if (record->tap.count && record->event.pressed) {
            tap_code16(ALGR(KC_8));
            return false;
        }
        break;
    case MT(MOD_LGUI, S(KC_8)):
        if (record->tap.count && record->event.pressed) {
            tap_code16(S(KC_8));
            return false;
        }
        break;
    case MT(MOD_LCTL, LGUI(KC_Z)):
        if (record->tap.count && record->event.pressed) {
            tap_code16(LGUI(KC_Z));
            return false;
        }
        break;
    case MT(MOD_LALT, LGUI(KC_X)):
        if (record->tap.count && record->event.pressed) {
            tap_code16(LGUI(KC_X));
            return false;
        }
        break;
    case MT(MOD_LSFT, LGUI(KC_C)):
        if (record->tap.count && record->event.pressed) {
            tap_code16(LGUI(KC_C));
            return false;
        }
        break;
    case MT(MOD_LGUI, LGUI(KC_V)):
        if (record->tap.count && record->event.pressed) {
            tap_code16(LGUI(KC_V));
            return false;
        }
        break;
    case MT(MOD_LSFT, ALGR(KC_9)):
        if (record->tap.count && record->event.pressed) {
            tap_code16(ALGR(KC_9));
            return false;
        }
        break;
    case MT(MOD_LGUI, S(KC_9)):
        if (record->tap.count && record->event.pressed) {
            tap_code16(S(KC_9));
            return false;
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // LAYER 0
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                        ,-----------------------------------------------------.
      VSSugg,       Q,       W,       E,       R,       T,                                Y,       U,       I,       O,       P,     Esc,
  //|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
          Tab,   HomeA,   HomeS,   HomeD,   HomeF,       G,                                H,   HomeJ,   HomeK,   HomeL,  HomeOE,      AE,
  //|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
       Layer2,       Z,       X,       C,       V,       B,                                N,       M,   Comma,     Dot,    Dash,  Layer1,
  //|--------+--------+--------+--------+--------+--------+----------|  |----------+--------+--------+--------+--------+--------+--------|
                                              Esc,  Layer1, RectSpace,    RectEnter,  Layer2,     Esc
                                      //`----------------------------'  `----------------------------'

  ),

  // LAYER 1
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------.                        ,-------------------------------------------------------------.
          FN1,      FN2,     FN3,        FN4,       FN5,     FN6,                          XXXXXXX,        At,      And,     Excl,    QMark,        Esc,
  //|--------+---------+--------+-----------+----------+--------|                        |--------+----------+---------+---------+---------+-----------|
          Tab, HomeUndo, HomeCut,   HomeCopy, HomePaste,    FN12,                               N1,    HomeN2,   HomeN3,   HomeN4,   HomeN5,       Euro,
  //|--------+---------+--------+-----------+----------+--------|                        |--------+----------+---------+---------+---------+-----------|
       Layer3,  XXXXXXX, XXXXXXX,    XXXXXXX,    VSPeek,   VSDef,                               N6,        N7,       N8,       N9,       N0,    _______,
  //|--------+---------+--------+-----------+----------+--------+----------|  |----------+--------+----------+---------+---------+---------+-----------|
                                                 VSSugg, _______, RectSpace,    RectEnter,  Layer3,      RAlt
                                          //`------------------------------'  `------------------------------'
  ),

  // LAYER 2
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------.                         ,-------------------------------------------------------------.
      XXXXXXX,      Hash,     Dollar,      CQuot,       DQuot,   Slash,                             NLock,  LDesktp,      Up,        RDesktp, XXXXXXX,     Esc,
  //|--------+----------+-----------+-----------+------------+--------|                         |--------+---------+--------+---------------+--------+--------|
          Tab, HomeTilde,   HomeLess, HomeLArray, HomeLBrackt,  LBrace,                             CLock,     Left,    Down,          Right, XXXXXXX,      AO,
  //|--------+----------+-----------+-----------+------------+--------|                         |--------+---------+--------+---------------+--------+--------|
      _______,   Percent,       Wall,       Star,        Plus,   Equal,                               FN7,      FN8,     FN9,           FN10,    FN11,  Layer3,
  //|--------+----------+-----------+-----------+------------+--------+----------|  |-----------+--------+---------+--------+---------------+--------+--------|
                                                       VSSugg,  Layer3,   RectTab,     RectEnter, _______,     RAlt
                                                  //`----------------------------'  `------------------------------'
    ),

  // LAYER 3
    [3] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------------.                         ,--------------------------------------------------------.
       Layer4,         SShot,     SCap,    XXXXXXX,       SQuot,   BSlash,                           XXXXXXX,    Mouse1,      MUp,  Mouse2, GCAuthA,     Esc,
  //|--------+--------------+---------+-----------+------------+---------|                         |--------+----------+---------+--------+--------+--------|
          Tab,     HomeVolUp, HomeMore, HomeRArray, HomeRBrackt,   RBrace,                             ScrUp,     MLeft,    MDown,  MRight, GCAuthL,  LockSc,
  //|--------+--------------+---------+-----------+------------+---------|                         |--------+----------+---------+--------+--------+--------|
      _______,       VolDown,  VolMute,    MedBack,     MedPaus,  MedForw,                           ScrDown,   GitComm,  GitPush, GitChec, GitPull, _______,
  //|--------+--------------+---------+-----------+------------+---------+-----------|  |----------+--------+----------+---------+--------+--------+--------|
                                                         VSSugg,  _______,    RectTab,    RectEnter, _______,      RAlt
                                                //`----------------------------------'  `------------------------------'
  ),

  // LAYER 4
    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                        ,-----------------------------------------------------.
          Tab,       Q,       W,       E,       R,       T,                                Y,       U,       I,       O,       P,   Bkspc,
  //|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
       LShift,       A,       S,       D,       F,       G,                                H,       J,       K,       L,      OE,      AE,
  //|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
        LCtrl,       Z,       X,       C,       V,       B,                                N,       M,   Comma,     Dot,    Dash,     Esc,
  //|--------+--------+--------+--------+--------+--------+----------|  |----------+--------+--------+--------+--------+--------+--------|
                                               N2,      N1,     Space,        Enter,  Layer5,  Layer4
                                      //`----------------------------'  `----------------------------'

  ),

  // LAYER 5
    [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                        ,-----------------------------------------------------.
          Tab,       Q,       W,       E,       R,       T,                                Y,       U,       I,       O,       P,   Bkspc,
  //|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
       LShift,       A,       S,       D,       F,       G,                                H,       J,       K,       L,      OE,      AE,
  //|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
        LCtrl,       Z,       X,       C,       V,       B,                                N,       M,   Comma,     Dot,    Dash,     Esc,
  //|--------+--------+--------+--------+--------+--------+----------|  |----------+--------+--------+--------+--------+--------+--------|
                                               N2,      N1,     Space,        Enter,  Layer4,  Layer5
                                      //`----------------------------'  `----------------------------'
  )
};
