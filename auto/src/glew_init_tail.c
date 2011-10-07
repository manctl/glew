/* ------------------------------------------------------------------------ */

const GLubyte* glewGetErrorString (GLenum error)
{
  static const GLubyte* _glewErrorString[] =
  {
    (const GLubyte*)"No error",
    (const GLubyte*)"Missing GL version",
    (const GLubyte*)"GL 1.1 and up are supported",
    (const GLubyte*)"GLX 1.2 and up are supported",
    (const GLubyte*)"OpenGL ES lib expected, found OpenGL lib",
    (const GLubyte*)"OpenGL lib expected, found OpenGL ES lib",
    (const GLubyte*)"Missing EGL version",
    (const GLubyte*)"EGL 1.1 and up are supported",
    (const GLubyte*)"Unknown error"
  };
  const int max_error = sizeof(_glewErrorString)/sizeof(*_glewErrorString) - 1;
  return _glewErrorString[(int)error > max_error ? max_error : (int)error];
}

const GLubyte* glewGetString (GLenum name)
{
  static const GLubyte* _glewString[] =
  {
    (const GLubyte*)NULL,
    (const GLubyte*)"GLEW_VERSION_STRING",
    (const GLubyte*)"GLEW_VERSION_MAJOR_STRING",
    (const GLubyte*)"GLEW_VERSION_MINOR_STRING",
    (const GLubyte*)"GLEW_VERSION_MICRO_STRING"
  };
  const int max_string = sizeof(_glewString)/sizeof(*_glewString) - 1;
  return _glewString[(int)name > max_string ? 0 : (int)name];
}

/* ------------------------------------------------------------------------ */

GLboolean glewExperimental = GL_FALSE;

#if !defined(GLEW_MX)

#if defined(GLEW_USE_LIB_ES) 
#  if defined (GLEW_INC_EGL)
extern GLenum eglewContextInit (void);
#  endif
#elif defined(_WIN32)
extern GLenum wglewContextInit (void);
#elif !defined(__APPLE__) || defined(GLEW_APPLE_GLX) /* _UNIX */
extern GLenum glxewContextInit (void);
#endif /* _WIN32 */

GLenum glewInit ()
{
  GLenum r;
  if ( (r = glewContextInit()) ) return r;
#if defined(GLEW_USE_LIB_ES)
#  if defined (GLEW_INC_EGL)
 return eglewContextInit();
#  endif
#elif defined(_WIN32)
  return wglewContextInit();
#elif !defined(__APPLE__) || defined(GLEW_APPLE_GLX) /* _UNIX */
  return glxewContextInit();
#endif /* GLEW_USE_LIB_ES */
  return r;
}

#endif /* !GLEW_MX */
