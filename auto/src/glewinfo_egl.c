}

/* ------------------------------------------------------------------------ */

#if defined (GLEW_USE_LIB_ES)
#if defined (GLEW_INC_EGL)
static void eglewInfo ()
{
#ifdef EGL_VERSION_1_1
  _glewInfo_EGL_VERSION_1_1();
#endif /* EGL_VERSION_1_1 */
