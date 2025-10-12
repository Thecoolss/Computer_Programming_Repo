#pragma once

typedef enum {
  LANG_EN,
  LANG_ES
} WelcomeLanguage;

void set_welcome_language(WelcomeLanguage lang);
const char* get_welcome_message(void);
