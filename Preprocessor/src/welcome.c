
#include "welcome.h"

static WelcomeLanguage current_lang = LANG_EN;

void set_welcome_language(WelcomeLanguage lang) {
  current_lang = lang;
}

const char* get_welcome_message(void) {
  switch (current_lang) {
    case LANG_EN:
      return "Hello, World!";
    case LANG_ES:
      return "Hola, Mundo!";
    default:
      return "Unknown Language";
  }
}
