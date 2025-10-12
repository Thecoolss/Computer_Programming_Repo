#include "../include/welcome.h"
#include "utest.h"

UTEST(welcome, english) {
    set_welcome_language(LANG_EN);
    ASSERT_STREQ("Hello, World!", get_welcome_message());
}

UTEST(welcome, spanish) {
    set_welcome_language(LANG_ES);
    ASSERT_STREQ("Hola, Mundo!", get_welcome_message());
}

UTEST_MAIN();
