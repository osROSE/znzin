// This file is included by zz_error.cpp
//
// CAUSION: Do not modify or save in Visual Studio IDE. It can cause abnormal code conversion.
//
// 1. Open in Ultraedit.
// 2. Copy by custom user clipboard (Ctrl+1)

//-----------------------------------------------------------------------------
// error/message code and text definition here.
//-----------------------------------------------------------------------------
// CAUTION: before creating new message text, define new enum code in zz_error::zz_error_code.

// sample for cut and paste
//ZZ_REG_ERROR (XXXXXX, KOREAN, "");
//ZZ_REG_ERROR (XXXXXX, ENGLISH, "");

ZZ_REG_ERROR (MSG_ERROR, KOREAN, "¿À·ù");
ZZ_REG_ERROR (MSG_ERROR, ENGLISH, "error");
ZZ_REG_ERROR (MSG_ERROR, JAPANESE, "ƒGƒ‰[");

ZZ_REG_ERROR (INIT_FAIL, KOREAN, "ÃÊ±âÈ­ ½ÇÆĞ");
ZZ_REG_ERROR (INIT_FAIL, ENGLISH, "Iniitalization failed");
ZZ_REG_ERROR (INIT_FAIL, JAPANESE, "‰Šú‰»‚É¸”s‚µ‚Ü‚µ‚½B");

ZZ_REG_ERROR (CREATE_D3D_FAIL, KOREAN, "Direct3D °´Ã¼¸¦ »ı¼ºÇÒ ¼ö ¾ø½À´Ï´Ù.");
ZZ_REG_ERROR (CREATE_D3D_FAIL, ENGLISH, "cannot create direct3d.");
ZZ_REG_ERROR (CREATE_D3D_FAIL, JAPANESE, "DirectX‚Ìƒo[ƒWƒ‡ƒ“‚ğŠm”F‚µ‚Ä‚­‚¾‚³‚¢B");

ZZ_REG_ERROR (CREATE_FONT_FAIL, KOREAN, "ÆùÆ®¸¦ »ı¼ºÇÒ ¼ö ¾ø½À´Ï´Ù.");
ZZ_REG_ERROR (CREATE_FONT_FAIL, ENGLISH, "cannot create font.");
ZZ_REG_ERROR (CREATE_FONT_FAIL, JAPANESE, "ƒtƒHƒ“ƒg‚ğì¬‚Å‚«‚Ü‚¹‚ñB");

ZZ_REG_ERROR (CREATE_TEXTURE_FAIL, KOREAN, "ÅØ½ºÃÄ¸¦ »ı¼ºÇÒ ¼ö ¾ø½À´Ï´Ù.");
ZZ_REG_ERROR (CREATE_TEXTURE_FAIL, ENGLISH, "cannot create texture.");
ZZ_REG_ERROR (CREATE_TEXTURE_FAIL, JAPANESE, "ƒeƒNƒXƒ`ƒƒ[‚ğì¬‚Å‚«‚Ü‚¹‚ñB");

ZZ_REG_ERROR (MSG_EXIT_D3DERROR, KOREAN,
"ÇöÀç »ç¿ëÇÏ°í °è½Å ±×·¡ÇÈ Ä«µå´Â %s  ÀÔ´Ï´Ù.\n"
"±×·¡ÇÈÄ«µå¿¡¼­ °ÔÀÓ¿¡ ²À ÇÊ¿äÇÑ ÀÏºÎ ±â´ÉÀ» Á¦°øÇÏÁö ¾Ê¾Æ ´õÀÌ»ó ½ÇÇàÀÌ ºÒ°¡´ÉÇÕ´Ï´Ù.\n"
"È¨ÆäÀÌÁö¿¡¼­ ÃÖÀú»ç¾ç ÀÌ»óÀÇ ½Ã½ºÅÛÀÎÁö È®ÀÎÇÏ½Ã±â ¹Ù¶ø´Ï´Ù.\n"
"±×·¡ÇÈ Ä«µå µå¶óÀÌ¹ö¸¦ ÃÖ½Å¹öÀüÀ¸·Î ¾÷µ¥ÀÌÆ®ÇÏ½Ã¸é ÀÌ ¹®Á¦°¡ ÇØ°áµÉ ¼öµµ ÀÖ½À´Ï´Ù.\n");
ZZ_REG_ERROR (MSG_EXIT_D3DERROR, ENGLISH,
"Your graphics card is %s.\n"
"Some mandatory features are missing, so the application will be terminated.\n"
"Please, check the minimum system requirements in our website.\n"
"In some cases, this problem may be solved just after updating your graphics card driver.\n");
ZZ_REG_ERROR (MSG_EXIT_D3DERROR, JAPANESE,
"‹M•û‚ÌƒOƒ‰ƒtƒBƒbƒNƒJ[ƒh‚Í%s‚Å‚·B\n"
"ƒQ[ƒ€‚ğƒvƒŒ[‚·‚é‚½‚ß‚É•K—v‚È‹@”\‚ğAƒOƒ‰ƒtƒBƒbƒNƒJ[ƒh‚ªƒTƒ|[ƒg‚µ‚Ä‚¨‚è‚Ü‚¹‚ñB\n"
"Œö®ƒz[ƒ€ƒy[ƒW‚©‚çA•K—vƒXƒyƒbƒN‚ğÄ“x‚²Šm”F‚­‚¾‚³‚¢B\n"
"ƒOƒ‰ƒtƒBƒbƒNƒJ[ƒh‚Ìƒhƒ‰ƒCƒo‚ğAÅV‚Ìƒo[ƒWƒ‡ƒ“‚É‚·‚ê‚Î–â‘è‚ª‰ğŒˆ‚³‚ê‚é‰Â”\«‚ª‚ ‚è‚Ü‚·B\n");

/*
// source: doc/msg_jp.txt
1. "??"
1. "error"
1. "ƒGƒ‰["

2. "??? ??"
2. "Iniitalization failed"
2. "‰Šú‰»‚É¸”s‚µ‚Ü‚µ‚½B"

3. "Direct3D ??? ??? ? ????."
3. "cannot create direct3d."
3. "DirectX‚Ìƒo[ƒWƒ‡ƒ“‚ğŠm”F‚µ‚Ä‚­‚¾‚³‚¢B"

4. "??? ??? ? ????."
4. "cannot create font."
4. "ƒtƒHƒ“ƒg‚ğì¬‚Å‚«‚Ü‚¹‚ñB"

5. "???? ??? ? ????."
5. "cannot create texture."
5. "ƒeƒNƒXƒ`ƒƒ[‚ğì¬‚Å‚«‚Ü‚¹‚ñB"

6. "?? ???? ?? ??? ??? %s  ???."
6. "Your graphics card is %s."
6. "‹M•û‚ÌƒOƒ‰ƒtƒBƒbƒNƒJ[ƒh‚Í%s‚Å‚·B"

7. "??????? ??? ? ??? ?? ??? ???? ?? ??? ??? ??????."
7. "Some mandatory features are missing, so the application will be terminated."
7. "ƒQ[ƒ€‚ğƒvƒŒ[‚·‚é‚½‚ß‚É•K—v‚È‹@”\‚ğAƒOƒ‰ƒtƒBƒbƒNƒJ[ƒh‚ªƒTƒ|[ƒg‚µ‚Ä‚¨‚è‚Ü‚¹‚ñB"

8. "?????? ???? ??? ????? ????? ????."
8. "Please, check the minimum system requirements in our website."
8. "Œö®ƒz[ƒ€ƒy[ƒW‚©‚çA•K—vƒXƒyƒbƒN‚ğÄ“x‚²Šm”F‚­‚¾‚³‚¢B"

9. "??? ?? ????? ?????? ??????? ? ??? ??? ?? ????."
9. "In some cases, this problem may be solved just after updating your graphics card driver."
9. "ƒOƒ‰ƒtƒBƒbƒNƒJ[ƒh‚Ìƒhƒ‰ƒCƒo‚ğAÅV‚Ìƒo[ƒWƒ‡ƒ“‚É‚·‚ê‚Î–â‘è‚ª‰ğŒˆ‚³‚ê‚é‰Â”\«‚ª‚ ‚è‚Ü‚·B"

10. "?? ??? ??"
10. "Launch Rose Online"
10. "ƒ[ƒYƒIƒ“ƒ‰ƒCƒ“‚ÌÀs"

11. "?? ??? ??"
11. "Uninstall Rose Online"
11. "ƒ[ƒYƒIƒ“ƒ‰ƒCƒ“‚Ìíœ"

12. "????"
12. "Configuration"
12. "ƒ[ƒYƒIƒ“ƒ‰ƒCƒ“‚Ìİ’è"

*/

//------------------------------------------------------------------------------