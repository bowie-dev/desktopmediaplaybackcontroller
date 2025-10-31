
#include <Arduino.h>
#include <HID-Project.h>

#define BTN_PREV 0
#define BTN_PLAY 1
#define BTN_NEXT 2
#define BTN_VOLDN 3
#define BTN_VOLUP 4
#define BTN_EXTRA 5
#define ENC_A 6
#define ENC_B 7
#define ENC_BTN 8

unsigned long debounceDelay = 20;
unsigned long lastEncTime = 0;
int lastEncA = 0;
int lastEncB = 0;
int lastEncState = 0;

bool btnStatePrev = 0, lastBtnPrev = 0;
bool btnStatePlay = 0, lastBtnPlay = 0;
bool btnStateNext = 0, lastBtnNext = 0;
bool btnStateVoldn = 0, lastBtnVoldn = 0;
bool btnStateVolup = 0, lastBtnVolup = 0;
bool btnStateExtra = 0, lastBtnExtra = 0;
bool btnStateEnc = 0, lastBtnEnc = 0;

// desktop media playbck controller
// kinda messy version but works fine

unsigned long lastPressPrev = 0, lastPressPlay = 0, lastPressNext = 0, lastPressVoldn = 0, lastPressVolup = 0, lastPressExtra = 0, lastPressEnc = 0;

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("starting");

  pinMode(BTN_PREV, INPUT);
  pinMode(BTN_PLAY, INPUT);
  pinMode(BTN_NEXT, INPUT);
  pinMode(BTN_VOLDN, INPUT);
  pinMode(BTN_VOLUP, INPUT);
  pinMode(BTN_EXTRA, INPUT);
  pinMode(ENC_A, INPUT);
  pinMode(ENC_B, INPUT);
  pinMode(ENC_BTN, INPUT);

  Consumer.begin();
  Serial.println("ready");
}

void loop() {
  checkButton(BTN_PREV, &btnStatePrev, &lastBtnPrev, &lastPressPrev, MEDIA_PREVIOUS);
  checkButton(BTN_PLAY, &btnStatePlay, &lastBtnPlay, &lastPressPlay, MEDIA_PLAY_PAUSE);
  checkButton(BTN_NEXT, &btnStateNext, &lastBtnNext, &lastPressNext, MEDIA_NEXT);
  checkButton(BTN_VOLDN, &btnStateVoldn, &lastBtnVoldn, &lastPressVoldn, MEDIA_VOL_DOWN);
  checkButton(BTN_VOLUP, &btnStateVolup, &lastBtnVolup, &lastPressVolup, MEDIA_VOL_UP);
  checkButton(BTN_EXTRA, &btnStateExtra, &lastBtnExtra, &lastPressExtra, MEDIA_MUTE);

  checkEncoder();
  checkButton(ENC_BTN, &btnStateEnc, &lastBtnEnc, &lastPressEnc, MEDIA_PLAY_PAUSE);

  delay(2);
}

void checkButton(int pin, bool *state, bool *lastState, unsigned long *lastPress, int mediaKey) {
  bool reading = digitalRead(pin);
  unsigned long now = millis();

  if (reading != *lastState) {
    *lastPress = now;
  }

  if ((now - *lastPress) > debounceDelay) {
    if (reading != *state) {
      *state = reading;
      if (*state == HIGH) {
        Consumer.write(mediaKey);
        Serial.print("btn ");
        Serial.print(pin);
        Serial.println(" pressed");
      }
    }
  }

  *lastState = reading;
}

void checkEncoder() {
  int a = digitalRead(ENC_A);
  int b = digitalRead(ENC_B);
  int state = (a << 1) | b;
  unsigned long now = millis();

  if (state != lastEncState && (now - lastEncTime) > 2) {
    if ((lastEncState == 0 && state == 1) || (lastEncState == 1 && state == 3) ||
        (lastEncState == 3 && state == 2) || (lastEncState == 2 && state == 0)) {
      Consumer.write(MEDIA_VOL_UP);
      Serial.println("enc cw");
    } else if ((lastEncState == 0 && state == 2) || (lastEncState == 2 && state == 3) ||
               (lastEncState == 3 && state == 1) || (lastEncState == 1 && state == 0)) {
      Consumer.write(MEDIA_VOL_DOWN);
      Serial.println("enc ccw");
    }
    lastEncTime = now;
  }

  lastEncState = state;
}
