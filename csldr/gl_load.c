/* opengl 1.1 loader to avoid linking to opengl32.lib */
#include "pch.h"

void (APIENTRY *GL_Accum)(GLenum op, GLfloat value);
void (APIENTRY *GL_AlphaFunc)(GLenum func, GLclampf ref);
GLboolean(APIENTRY *GL_AreTexturesResident)(GLsizei n, const GLuint *textures, GLboolean *residences);
void (APIENTRY *GL_ArrayElement)(GLint i);
void (APIENTRY *GL_Begin)(GLenum mode);
void (APIENTRY *GL_BindTexture)(GLenum target, GLuint texture);
void (APIENTRY *GL_Bitmap)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
void (APIENTRY *GL_BlendFunc)(GLenum sfactor, GLenum dfactor);
void (APIENTRY *GL_CallList)(GLuint list);
void (APIENTRY *GL_CallLists)(GLsizei n, GLenum type, const GLvoid *lists);
void (APIENTRY *GL_Clear)(GLbitfield mask);
void (APIENTRY *GL_ClearAccum)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void (APIENTRY *GL_ClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
void (APIENTRY *GL_ClearDepth)(GLclampd depth);
void (APIENTRY *GL_ClearIndex)(GLfloat c);
void (APIENTRY *GL_ClearStencil)(GLint s);
void (APIENTRY *GL_ClipPlane)(GLenum plane, const GLdouble *equation);
void (APIENTRY *GL_Color3b)(GLbyte red, GLbyte green, GLbyte blue);
void (APIENTRY *GL_Color3bv)(const GLbyte *v);
void (APIENTRY *GL_Color3d)(GLdouble red, GLdouble green, GLdouble blue);
void (APIENTRY *GL_Color3dv)(const GLdouble *v);
void (APIENTRY *GL_Color3f)(GLfloat red, GLfloat green, GLfloat blue);
void (APIENTRY *GL_Color3fv)(const GLfloat *v);
void (APIENTRY *GL_Color3i)(GLint red, GLint green, GLint blue);
void (APIENTRY *GL_Color3iv)(const GLint *v);
void (APIENTRY *GL_Color3s)(GLshort red, GLshort green, GLshort blue);
void (APIENTRY *GL_Color3sv)(const GLshort *v);
void (APIENTRY *GL_Color3ub)(GLubyte red, GLubyte green, GLubyte blue);
void (APIENTRY *GL_Color3ubv)(const GLubyte *v);
void (APIENTRY *GL_Color3ui)(GLuint red, GLuint green, GLuint blue);
void (APIENTRY *GL_Color3uiv)(const GLuint *v);
void (APIENTRY *GL_Color3us)(GLushort red, GLushort green, GLushort blue);
void (APIENTRY *GL_Color3usv)(const GLushort *v);
void (APIENTRY *GL_Color4b)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
void (APIENTRY *GL_Color4bv)(const GLbyte *v);
void (APIENTRY *GL_Color4d)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
void (APIENTRY *GL_Color4dv)(const GLdouble *v);
void (APIENTRY *GL_Color4f)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void (APIENTRY *GL_Color4fv)(const GLfloat *v);
void (APIENTRY *GL_Color4i)(GLint red, GLint green, GLint blue, GLint alpha);
void (APIENTRY *GL_Color4iv)(const GLint *v);
void (APIENTRY *GL_Color4s)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
void (APIENTRY *GL_Color4sv)(const GLshort *v);
void (APIENTRY *GL_Color4ub)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void (APIENTRY *GL_Color4ubv)(const GLubyte *v);
void (APIENTRY *GL_Color4ui)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
void (APIENTRY *GL_Color4uiv)(const GLuint *v);
void (APIENTRY *GL_Color4us)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
void (APIENTRY *GL_Color4usv)(const GLushort *v);
void (APIENTRY *GL_ColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void (APIENTRY *GL_ColorMaterial)(GLenum face, GLenum mode);
void (APIENTRY *GL_ColorPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void (APIENTRY *GL_CopyPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
void (APIENTRY *GL_CopyTexImage1D)(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
void (APIENTRY *GL_CopyTexImage2D)(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void (APIENTRY *GL_CopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void (APIENTRY *GL_CopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void (APIENTRY *GL_CullFace)(GLenum mode);
void (APIENTRY *GL_DeleteLists)(GLuint list, GLsizei range);
void (APIENTRY *GL_DeleteTextures)(GLsizei n, const GLuint *textures);
void (APIENTRY *GL_DepthFunc)(GLenum func);
void (APIENTRY *GL_DepthMask)(GLboolean flag);
void (APIENTRY *GL_DepthRange)(GLclampd zNear, GLclampd zFar);
void (APIENTRY *GL_Disable)(GLenum cap);
void (APIENTRY *GL_DisableClientState)(GLenum array);
void (APIENTRY *GL_DrawArrays)(GLenum mode, GLint first, GLsizei count);
void (APIENTRY *GL_DrawBuffer)(GLenum mode);
void (APIENTRY *GL_DrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
void (APIENTRY *GL_DrawPixels)(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void (APIENTRY *GL_EdgeFlag)(GLboolean flag);
void (APIENTRY *GL_EdgeFlagPointer)(GLsizei stride, const GLvoid *pointer);
void (APIENTRY *GL_EdgeFlagv)(const GLboolean *flag);
void (APIENTRY *GL_Enable)(GLenum cap);
void (APIENTRY *GL_EnableClientState)(GLenum array);
void (APIENTRY *GL_End)(void);
void (APIENTRY *GL_EndList)(void);
void (APIENTRY *GL_EvalCoord1d)(GLdouble u);
void (APIENTRY *GL_EvalCoord1dv)(const GLdouble *u);
void (APIENTRY *GL_EvalCoord1f)(GLfloat u);
void (APIENTRY *GL_EvalCoord1fv)(const GLfloat *u);
void (APIENTRY *GL_EvalCoord2d)(GLdouble u, GLdouble v);
void (APIENTRY *GL_EvalCoord2dv)(const GLdouble *u);
void (APIENTRY *GL_EvalCoord2f)(GLfloat u, GLfloat v);
void (APIENTRY *GL_EvalCoord2fv)(const GLfloat *u);
void (APIENTRY *GL_EvalMesh1)(GLenum mode, GLint i1, GLint i2);
void (APIENTRY *GL_EvalMesh2)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
void (APIENTRY *GL_EvalPoint1)(GLint i);
void (APIENTRY *GL_EvalPoint2)(GLint i, GLint j);
void (APIENTRY *GL_FeedbackBuffer)(GLsizei size, GLenum type, GLfloat *buffer);
void (APIENTRY *GL_Finish)(void);
void (APIENTRY *GL_Flush)(void);
void (APIENTRY *GL_Fogf)(GLenum pname, GLfloat param);
void (APIENTRY *GL_Fogfv)(GLenum pname, const GLfloat *params);
void (APIENTRY *GL_Fogi)(GLenum pname, GLint param);
void (APIENTRY *GL_Fogiv)(GLenum pname, const GLint *params);
void (APIENTRY *GL_FrontFace)(GLenum mode);
void (APIENTRY *GL_Frustum)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLuint(APIENTRY *GL_GenLists)(GLsizei range);
void (APIENTRY *GL_GenTextures)(GLsizei n, GLuint *textures);
void (APIENTRY *GL_GetBooleanv)(GLenum pname, GLboolean *params);
void (APIENTRY *GL_GetClipPlane)(GLenum plane, GLdouble *equation);
void (APIENTRY *GL_GetDoublev)(GLenum pname, GLdouble *params);
GLenum(APIENTRY *GL_GetError)(void);
void (APIENTRY *GL_GetFloatv)(GLenum pname, GLfloat *params);
void (APIENTRY *GL_GetIntegerv)(GLenum pname, GLint *params);
void (APIENTRY *GL_GetLightfv)(GLenum light, GLenum pname, GLfloat *params);
void (APIENTRY *GL_GetLightiv)(GLenum light, GLenum pname, GLint *params);
void (APIENTRY *GL_GetMapdv)(GLenum target, GLenum query, GLdouble *v);
void (APIENTRY *GL_GetMapfv)(GLenum target, GLenum query, GLfloat *v);
void (APIENTRY *GL_GetMapiv)(GLenum target, GLenum query, GLint *v);
void (APIENTRY *GL_GetMaterialfv)(GLenum face, GLenum pname, GLfloat *params);
void (APIENTRY *GL_GetMaterialiv)(GLenum face, GLenum pname, GLint *params);
void (APIENTRY *GL_GetPixelMapfv)(GLenum map, GLfloat *values);
void (APIENTRY *GL_GetPixelMapuiv)(GLenum map, GLuint *values);
void (APIENTRY *GL_GetPixelMapusv)(GLenum map, GLushort *values);
void (APIENTRY *GL_GetPointerv)(GLenum pname, GLvoid **params);
void (APIENTRY *GL_GetPolygonStipple)(GLubyte *mask);
const GLubyte *(APIENTRY *GL_GetString)(GLenum name);
void (APIENTRY *GL_GetTexEnvfv)(GLenum target, GLenum pname, GLfloat *params);
void (APIENTRY *GL_GetTexEnviv)(GLenum target, GLenum pname, GLint *params);
void (APIENTRY *GL_GetTexGendv)(GLenum coord, GLenum pname, GLdouble *params);
void (APIENTRY *GL_GetTexGenfv)(GLenum coord, GLenum pname, GLfloat *params);
void (APIENTRY *GL_GetTexGeniv)(GLenum coord, GLenum pname, GLint *params);
void (APIENTRY *GL_GetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
void (APIENTRY *GL_GetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params);
void (APIENTRY *GL_GetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params);
void (APIENTRY *GL_GetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
void (APIENTRY *GL_GetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
void (APIENTRY *GL_Hint)(GLenum target, GLenum mode);
void (APIENTRY *GL_IndexMask)(GLuint mask);
void (APIENTRY *GL_IndexPointer)(GLenum type, GLsizei stride, const GLvoid *pointer);
void (APIENTRY *GL_Indexd)(GLdouble c);
void (APIENTRY *GL_Indexdv)(const GLdouble *c);
void (APIENTRY *GL_Indexf)(GLfloat c);
void (APIENTRY *GL_Indexfv)(const GLfloat *c);
void (APIENTRY *GL_Indexi)(GLint c);
void (APIENTRY *GL_Indexiv)(const GLint *c);
void (APIENTRY *GL_Indexs)(GLshort c);
void (APIENTRY *GL_Indexsv)(const GLshort *c);
void (APIENTRY *GL_Indexub)(GLubyte c);
void (APIENTRY *GL_Indexubv)(const GLubyte *c);
void (APIENTRY *GL_InitNames)(void);
void (APIENTRY *GL_InterleavedArrays)(GLenum format, GLsizei stride, const GLvoid *pointer);
GLboolean(APIENTRY *GL_IsEnabled)(GLenum cap);
GLboolean(APIENTRY *GL_IsList)(GLuint list);
GLboolean(APIENTRY *GL_IsTexture)(GLuint texture);
void (APIENTRY *GL_LightModelf)(GLenum pname, GLfloat param);
void (APIENTRY *GL_LightModelfv)(GLenum pname, const GLfloat *params);
void (APIENTRY *GL_LightModeli)(GLenum pname, GLint param);
void (APIENTRY *GL_LightModeliv)(GLenum pname, const GLint *params);
void (APIENTRY *GL_Lightf)(GLenum light, GLenum pname, GLfloat param);
void (APIENTRY *GL_Lightfv)(GLenum light, GLenum pname, const GLfloat *params);
void (APIENTRY *GL_Lighti)(GLenum light, GLenum pname, GLint param);
void (APIENTRY *GL_Lightiv)(GLenum light, GLenum pname, const GLint *params);
void (APIENTRY *GL_LineStipple)(GLint factor, GLushort pattern);
void (APIENTRY *GL_LineWidth)(GLfloat width);
void (APIENTRY *GL_ListBase)(GLuint base);
void (APIENTRY *GL_LoadIdentity)(void);
void (APIENTRY *GL_LoadMatrixd)(const GLdouble *m);
void (APIENTRY *GL_LoadMatrixf)(const GLfloat *m);
void (APIENTRY *GL_LoadName)(GLuint name);
void (APIENTRY *GL_LogicOp)(GLenum opcode);
void (APIENTRY *GL_Map1d)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
void (APIENTRY *GL_Map1f)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
void (APIENTRY *GL_Map2d)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
void (APIENTRY *GL_Map2f)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
void (APIENTRY *GL_MapGrid1d)(GLint un, GLdouble u1, GLdouble u2);
void (APIENTRY *GL_MapGrid1f)(GLint un, GLfloat u1, GLfloat u2);
void (APIENTRY *GL_MapGrid2d)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
void (APIENTRY *GL_MapGrid2f)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
void (APIENTRY *GL_Materialf)(GLenum face, GLenum pname, GLfloat param);
void (APIENTRY *GL_Materialfv)(GLenum face, GLenum pname, const GLfloat *params);
void (APIENTRY *GL_Materiali)(GLenum face, GLenum pname, GLint param);
void (APIENTRY *GL_Materialiv)(GLenum face, GLenum pname, const GLint *params);
void (APIENTRY *GL_MatrixMode)(GLenum mode);
void (APIENTRY *GL_MultMatrixd)(const GLdouble *m);
void (APIENTRY *GL_MultMatrixf)(const GLfloat *m);
void (APIENTRY *GL_NewList)(GLuint list, GLenum mode);
void (APIENTRY *GL_Normal3b)(GLbyte nx, GLbyte ny, GLbyte nz);
void (APIENTRY *GL_Normal3bv)(const GLbyte *v);
void (APIENTRY *GL_Normal3d)(GLdouble nx, GLdouble ny, GLdouble nz);
void (APIENTRY *GL_Normal3dv)(const GLdouble *v);
void (APIENTRY *GL_Normal3f)(GLfloat nx, GLfloat ny, GLfloat nz);
void (APIENTRY *GL_Normal3fv)(const GLfloat *v);
void (APIENTRY *GL_Normal3i)(GLint nx, GLint ny, GLint nz);
void (APIENTRY *GL_Normal3iv)(const GLint *v);
void (APIENTRY *GL_Normal3s)(GLshort nx, GLshort ny, GLshort nz);
void (APIENTRY *GL_Normal3sv)(const GLshort *v);
void (APIENTRY *GL_NormalPointer)(GLenum type, GLsizei stride, const GLvoid *pointer);
void (APIENTRY *GL_Ortho)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void (APIENTRY *GL_PassThrough)(GLfloat token);
void (APIENTRY *GL_PixelMapfv)(GLenum map, GLsizei mapsize, const GLfloat *values);
void (APIENTRY *GL_PixelMapuiv)(GLenum map, GLsizei mapsize, const GLuint *values);
void (APIENTRY *GL_PixelMapusv)(GLenum map, GLsizei mapsize, const GLushort *values);
void (APIENTRY *GL_PixelStoref)(GLenum pname, GLfloat param);
void (APIENTRY *GL_PixelStorei)(GLenum pname, GLint param);
void (APIENTRY *GL_PixelTransferf)(GLenum pname, GLfloat param);
void (APIENTRY *GL_PixelTransferi)(GLenum pname, GLint param);
void (APIENTRY *GL_PixelZoom)(GLfloat xfactor, GLfloat yfactor);
void (APIENTRY *GL_PointSize)(GLfloat size);
void (APIENTRY *GL_PolygonMode)(GLenum face, GLenum mode);
void (APIENTRY *GL_PolygonOffset)(GLfloat factor, GLfloat units);
void (APIENTRY *GL_PolygonStipple)(const GLubyte *mask);
void (APIENTRY *GL_PopAttrib)(void);
void (APIENTRY *GL_PopClientAttrib)(void);
void (APIENTRY *GL_PopMatrix)(void);
void (APIENTRY *GL_PopName)(void);
void (APIENTRY *GL_PrioritizeTextures)(GLsizei n, const GLuint *textures, const GLclampf *priorities);
void (APIENTRY *GL_PushAttrib)(GLbitfield mask);
void (APIENTRY *GL_PushClientAttrib)(GLbitfield mask);
void (APIENTRY *GL_PushMatrix)(void);
void (APIENTRY *GL_PushName)(GLuint name);
void (APIENTRY *GL_RasterPos2d)(GLdouble x, GLdouble y);
void (APIENTRY *GL_RasterPos2dv)(const GLdouble *v);
void (APIENTRY *GL_RasterPos2f)(GLfloat x, GLfloat y);
void (APIENTRY *GL_RasterPos2fv)(const GLfloat *v);
void (APIENTRY *GL_RasterPos2i)(GLint x, GLint y);
void (APIENTRY *GL_RasterPos2iv)(const GLint *v);
void (APIENTRY *GL_RasterPos2s)(GLshort x, GLshort y);
void (APIENTRY *GL_RasterPos2sv)(const GLshort *v);
void (APIENTRY *GL_RasterPos3d)(GLdouble x, GLdouble y, GLdouble z);
void (APIENTRY *GL_RasterPos3dv)(const GLdouble *v);
void (APIENTRY *GL_RasterPos3f)(GLfloat x, GLfloat y, GLfloat z);
void (APIENTRY *GL_RasterPos3fv)(const GLfloat *v);
void (APIENTRY *GL_RasterPos3i)(GLint x, GLint y, GLint z);
void (APIENTRY *GL_RasterPos3iv)(const GLint *v);
void (APIENTRY *GL_RasterPos3s)(GLshort x, GLshort y, GLshort z);
void (APIENTRY *GL_RasterPos3sv)(const GLshort *v);
void (APIENTRY *GL_RasterPos4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void (APIENTRY *GL_RasterPos4dv)(const GLdouble *v);
void (APIENTRY *GL_RasterPos4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void (APIENTRY *GL_RasterPos4fv)(const GLfloat *v);
void (APIENTRY *GL_RasterPos4i)(GLint x, GLint y, GLint z, GLint w);
void (APIENTRY *GL_RasterPos4iv)(const GLint *v);
void (APIENTRY *GL_RasterPos4s)(GLshort x, GLshort y, GLshort z, GLshort w);
void (APIENTRY *GL_RasterPos4sv)(const GLshort *v);
void (APIENTRY *GL_ReadBuffer)(GLenum mode);
void (APIENTRY *GL_ReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
void (APIENTRY *GL_Rectd)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
void (APIENTRY *GL_Rectdv)(const GLdouble *v1, const GLdouble *v2);
void (APIENTRY *GL_Rectf)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void (APIENTRY *GL_Rectfv)(const GLfloat *v1, const GLfloat *v2);
void (APIENTRY *GL_Recti)(GLint x1, GLint y1, GLint x2, GLint y2);
void (APIENTRY *GL_Rectiv)(const GLint *v1, const GLint *v2);
void (APIENTRY *GL_Rects)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
void (APIENTRY *GL_Rectsv)(const GLshort *v1, const GLshort *v2);
GLint(APIENTRY *GL_RenderMode)(GLenum mode);
void (APIENTRY *GL_Rotated)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void (APIENTRY *GL_Rotatef)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void (APIENTRY *GL_Scaled)(GLdouble x, GLdouble y, GLdouble z);
void (APIENTRY *GL_Scalef)(GLfloat x, GLfloat y, GLfloat z);
void (APIENTRY *GL_Scissor)(GLint x, GLint y, GLsizei width, GLsizei height);
void (APIENTRY *GL_SelectBuffer)(GLsizei size, GLuint *buffer);
void (APIENTRY *GL_ShadeModel)(GLenum mode);
void (APIENTRY *GL_StencilFunc)(GLenum func, GLint ref, GLuint mask);
void (APIENTRY *GL_StencilMask)(GLuint mask);
void (APIENTRY *GL_StencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
void (APIENTRY *GL_TexCoord1d)(GLdouble s);
void (APIENTRY *GL_TexCoord1dv)(const GLdouble *v);
void (APIENTRY *GL_TexCoord1f)(GLfloat s);
void (APIENTRY *GL_TexCoord1fv)(const GLfloat *v);
void (APIENTRY *GL_TexCoord1i)(GLint s);
void (APIENTRY *GL_TexCoord1iv)(const GLint *v);
void (APIENTRY *GL_TexCoord1s)(GLshort s);
void (APIENTRY *GL_TexCoord1sv)(const GLshort *v);
void (APIENTRY *GL_TexCoord2d)(GLdouble s, GLdouble t);
void (APIENTRY *GL_TexCoord2dv)(const GLdouble *v);
void (APIENTRY *GL_TexCoord2f)(GLfloat s, GLfloat t);
void (APIENTRY *GL_TexCoord2fv)(const GLfloat *v);
void (APIENTRY *GL_TexCoord2i)(GLint s, GLint t);
void (APIENTRY *GL_TexCoord2iv)(const GLint *v);
void (APIENTRY *GL_TexCoord2s)(GLshort s, GLshort t);
void (APIENTRY *GL_TexCoord2sv)(const GLshort *v);
void (APIENTRY *GL_TexCoord3d)(GLdouble s, GLdouble t, GLdouble r);
void (APIENTRY *GL_TexCoord3dv)(const GLdouble *v);
void (APIENTRY *GL_TexCoord3f)(GLfloat s, GLfloat t, GLfloat r);
void (APIENTRY *GL_TexCoord3fv)(const GLfloat *v);
void (APIENTRY *GL_TexCoord3i)(GLint s, GLint t, GLint r);
void (APIENTRY *GL_TexCoord3iv)(const GLint *v);
void (APIENTRY *GL_TexCoord3s)(GLshort s, GLshort t, GLshort r);
void (APIENTRY *GL_TexCoord3sv)(const GLshort *v);
void (APIENTRY *GL_TexCoord4d)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void (APIENTRY *GL_TexCoord4dv)(const GLdouble *v);
void (APIENTRY *GL_TexCoord4f)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void (APIENTRY *GL_TexCoord4fv)(const GLfloat *v);
void (APIENTRY *GL_TexCoord4i)(GLint s, GLint t, GLint r, GLint q);
void (APIENTRY *GL_TexCoord4iv)(const GLint *v);
void (APIENTRY *GL_TexCoord4s)(GLshort s, GLshort t, GLshort r, GLshort q);
void (APIENTRY *GL_TexCoord4sv)(const GLshort *v);
void (APIENTRY *GL_TexCoordPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void (APIENTRY *GL_TexEnvf)(GLenum target, GLenum pname, GLfloat param);
void (APIENTRY *GL_TexEnvfv)(GLenum target, GLenum pname, const GLfloat *params);
void (APIENTRY *GL_TexEnvi)(GLenum target, GLenum pname, GLint param);
void (APIENTRY *GL_TexEnviv)(GLenum target, GLenum pname, const GLint *params);
void (APIENTRY *GL_TexGend)(GLenum coord, GLenum pname, GLdouble param);
void (APIENTRY *GL_TexGendv)(GLenum coord, GLenum pname, const GLdouble *params);
void (APIENTRY *GL_TexGenf)(GLenum coord, GLenum pname, GLfloat param);
void (APIENTRY *GL_TexGenfv)(GLenum coord, GLenum pname, const GLfloat *params);
void (APIENTRY *GL_TexGeni)(GLenum coord, GLenum pname, GLint param);
void (APIENTRY *GL_TexGeniv)(GLenum coord, GLenum pname, const GLint *params);
void (APIENTRY *GL_TexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void (APIENTRY *GL_TexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void (APIENTRY *GL_TexParameterf)(GLenum target, GLenum pname, GLfloat param);
void (APIENTRY *GL_TexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
void (APIENTRY *GL_TexParameteri)(GLenum target, GLenum pname, GLint param);
void (APIENTRY *GL_TexParameteriv)(GLenum target, GLenum pname, const GLint *params);
void (APIENTRY *GL_TexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
void (APIENTRY *GL_TexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void (APIENTRY *GL_Translated)(GLdouble x, GLdouble y, GLdouble z);
void (APIENTRY *GL_Translatef)(GLfloat x, GLfloat y, GLfloat z);
void (APIENTRY *GL_Vertex2d)(GLdouble x, GLdouble y);
void (APIENTRY *GL_Vertex2dv)(const GLdouble *v);
void (APIENTRY *GL_Vertex2f)(GLfloat x, GLfloat y);
void (APIENTRY *GL_Vertex2fv)(const GLfloat *v);
void (APIENTRY *GL_Vertex2i)(GLint x, GLint y);
void (APIENTRY *GL_Vertex2iv)(const GLint *v);
void (APIENTRY *GL_Vertex2s)(GLshort x, GLshort y);
void (APIENTRY *GL_Vertex2sv)(const GLshort *v);
void (APIENTRY *GL_Vertex3d)(GLdouble x, GLdouble y, GLdouble z);
void (APIENTRY *GL_Vertex3dv)(const GLdouble *v);
void (APIENTRY *GL_Vertex3f)(GLfloat x, GLfloat y, GLfloat z);
void (APIENTRY *GL_Vertex3fv)(const GLfloat *v);
void (APIENTRY *GL_Vertex3i)(GLint x, GLint y, GLint z);
void (APIENTRY *GL_Vertex3iv)(const GLint *v);
void (APIENTRY *GL_Vertex3s)(GLshort x, GLshort y, GLshort z);
void (APIENTRY *GL_Vertex3sv)(const GLshort *v);
void (APIENTRY *GL_Vertex4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void (APIENTRY *GL_Vertex4dv)(const GLdouble *v);
void (APIENTRY *GL_Vertex4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void (APIENTRY *GL_Vertex4fv)(const GLfloat *v);
void (APIENTRY *GL_Vertex4i)(GLint x, GLint y, GLint z, GLint w);
void (APIENTRY *GL_Vertex4iv)(const GLint *v);
void (APIENTRY *GL_Vertex4s)(GLshort x, GLshort y, GLshort z, GLshort w);
void (APIENTRY *GL_Vertex4sv)(const GLshort *v);
void (APIENTRY *GL_VertexPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void (APIENTRY *GL_Viewport)(GLint x, GLint y, GLsizei width, GLsizei height);

#define GET_FUNC(name) *(void **)(&GL_##name) = Plat_Dlsym(lib, "gl" #name)

void GL_Load(void)
{
	void *lib;

#if defined(__linux__)
	lib = Plat_Dlopen("libGL.so.1");
	if (!lib)
		lib = Plat_Dlopen("libGL.so");
	if (!lib)
		return;
#elif defined(_WIN32)
	lib = Plat_Dlopen("opengl32.dll");
	if (!lib)
		return;
#endif

	GET_FUNC(Accum);
	GET_FUNC(AlphaFunc);
	GET_FUNC(AreTexturesResident);
	GET_FUNC(ArrayElement);
	GET_FUNC(Begin);
	GET_FUNC(BindTexture);
	GET_FUNC(Bitmap);
	GET_FUNC(BlendFunc);
	GET_FUNC(CallList);
	GET_FUNC(CallLists);
	GET_FUNC(Clear);
	GET_FUNC(ClearAccum);
	GET_FUNC(ClearColor);
	GET_FUNC(ClearDepth);
	GET_FUNC(ClearIndex);
	GET_FUNC(ClearStencil);
	GET_FUNC(ClipPlane);
	GET_FUNC(Color3b);
	GET_FUNC(Color3bv);
	GET_FUNC(Color3d);
	GET_FUNC(Color3dv);
	GET_FUNC(Color3f);
	GET_FUNC(Color3fv);
	GET_FUNC(Color3i);
	GET_FUNC(Color3iv);
	GET_FUNC(Color3s);
	GET_FUNC(Color3sv);
	GET_FUNC(Color3ub);
	GET_FUNC(Color3ubv);
	GET_FUNC(Color3ui);
	GET_FUNC(Color3uiv);
	GET_FUNC(Color3us);
	GET_FUNC(Color3usv);
	GET_FUNC(Color4b);
	GET_FUNC(Color4bv);
	GET_FUNC(Color4d);
	GET_FUNC(Color4dv);
	GET_FUNC(Color4f);
	GET_FUNC(Color4fv);
	GET_FUNC(Color4i);
	GET_FUNC(Color4iv);
	GET_FUNC(Color4s);
	GET_FUNC(Color4sv);
	GET_FUNC(Color4ub);
	GET_FUNC(Color4ubv);
	GET_FUNC(Color4ui);
	GET_FUNC(Color4uiv);
	GET_FUNC(Color4us);
	GET_FUNC(Color4usv);
	GET_FUNC(ColorMask);
	GET_FUNC(ColorMaterial);
	GET_FUNC(ColorPointer);
	GET_FUNC(CopyPixels);
	GET_FUNC(CopyTexImage1D);
	GET_FUNC(CopyTexImage2D);
	GET_FUNC(CopyTexSubImage1D);
	GET_FUNC(CopyTexSubImage2D);
	GET_FUNC(CullFace);
	GET_FUNC(DeleteLists);
	GET_FUNC(DeleteTextures);
	GET_FUNC(DepthFunc);
	GET_FUNC(DepthMask);
	GET_FUNC(DepthRange);
	GET_FUNC(Disable);
	GET_FUNC(DisableClientState);
	GET_FUNC(DrawArrays);
	GET_FUNC(DrawBuffer);
	GET_FUNC(DrawElements);
	GET_FUNC(DrawPixels);
	GET_FUNC(EdgeFlag);
	GET_FUNC(EdgeFlagPointer);
	GET_FUNC(EdgeFlagv);
	GET_FUNC(Enable);
	GET_FUNC(EnableClientState);
	GET_FUNC(End);
	GET_FUNC(EndList);
	GET_FUNC(EvalCoord1d);
	GET_FUNC(EvalCoord1dv);
	GET_FUNC(EvalCoord1f);
	GET_FUNC(EvalCoord1fv);
	GET_FUNC(EvalCoord2d);
	GET_FUNC(EvalCoord2dv);
	GET_FUNC(EvalCoord2f);
	GET_FUNC(EvalCoord2fv);
	GET_FUNC(EvalMesh1);
	GET_FUNC(EvalMesh2);
	GET_FUNC(EvalPoint1);
	GET_FUNC(EvalPoint2);
	GET_FUNC(FeedbackBuffer);
	GET_FUNC(Finish);
	GET_FUNC(Flush);
	GET_FUNC(Fogf);
	GET_FUNC(Fogfv);
	GET_FUNC(Fogi);
	GET_FUNC(Fogiv);
	GET_FUNC(FrontFace);
	GET_FUNC(Frustum);
	GET_FUNC(GenLists);
	GET_FUNC(GenTextures);
	GET_FUNC(GetBooleanv);
	GET_FUNC(GetClipPlane);
	GET_FUNC(GetDoublev);
	GET_FUNC(GetError);
	GET_FUNC(GetFloatv);
	GET_FUNC(GetIntegerv);
	GET_FUNC(GetLightfv);
	GET_FUNC(GetLightiv);
	GET_FUNC(GetMapdv);
	GET_FUNC(GetMapfv);
	GET_FUNC(GetMapiv);
	GET_FUNC(GetMaterialfv);
	GET_FUNC(GetMaterialiv);
	GET_FUNC(GetPixelMapfv);
	GET_FUNC(GetPixelMapuiv);
	GET_FUNC(GetPixelMapusv);
	GET_FUNC(GetPointerv);
	GET_FUNC(GetPolygonStipple);
	GET_FUNC(GetString);
	GET_FUNC(GetTexEnvfv);
	GET_FUNC(GetTexEnviv);
	GET_FUNC(GetTexGendv);
	GET_FUNC(GetTexGenfv);
	GET_FUNC(GetTexGeniv);
	GET_FUNC(GetTexImage);
	GET_FUNC(GetTexLevelParameterfv);
	GET_FUNC(GetTexLevelParameteriv);
	GET_FUNC(GetTexParameterfv);
	GET_FUNC(GetTexParameteriv);
	GET_FUNC(Hint);
	GET_FUNC(IndexMask);
	GET_FUNC(IndexPointer);
	GET_FUNC(Indexd);
	GET_FUNC(Indexdv);
	GET_FUNC(Indexf);
	GET_FUNC(Indexfv);
	GET_FUNC(Indexi);
	GET_FUNC(Indexiv);
	GET_FUNC(Indexs);
	GET_FUNC(Indexsv);
	GET_FUNC(Indexub);
	GET_FUNC(Indexubv);
	GET_FUNC(InitNames);
	GET_FUNC(InterleavedArrays);
	GET_FUNC(IsEnabled);
	GET_FUNC(IsList);
	GET_FUNC(IsTexture);
	GET_FUNC(LightModelf);
	GET_FUNC(LightModelfv);
	GET_FUNC(LightModeli);
	GET_FUNC(LightModeliv);
	GET_FUNC(Lightf);
	GET_FUNC(Lightfv);
	GET_FUNC(Lighti);
	GET_FUNC(Lightiv);
	GET_FUNC(LineStipple);
	GET_FUNC(LineWidth);
	GET_FUNC(ListBase);
	GET_FUNC(LoadIdentity);
	GET_FUNC(LoadMatrixd);
	GET_FUNC(LoadMatrixf);
	GET_FUNC(LoadName);
	GET_FUNC(LogicOp);
	GET_FUNC(Map1d);
	GET_FUNC(Map1f);
	GET_FUNC(Map2d);
	GET_FUNC(Map2f);
	GET_FUNC(MapGrid1d);
	GET_FUNC(MapGrid1f);
	GET_FUNC(MapGrid2d);
	GET_FUNC(MapGrid2f);
	GET_FUNC(Materialf);
	GET_FUNC(Materialfv);
	GET_FUNC(Materiali);
	GET_FUNC(Materialiv);
	GET_FUNC(MatrixMode);
	GET_FUNC(MultMatrixd);
	GET_FUNC(MultMatrixf);
	GET_FUNC(NewList);
	GET_FUNC(Normal3b);
	GET_FUNC(Normal3bv);
	GET_FUNC(Normal3d);
	GET_FUNC(Normal3dv);
	GET_FUNC(Normal3f);
	GET_FUNC(Normal3fv);
	GET_FUNC(Normal3i);
	GET_FUNC(Normal3iv);
	GET_FUNC(Normal3s);
	GET_FUNC(Normal3sv);
	GET_FUNC(NormalPointer);
	GET_FUNC(Ortho);
	GET_FUNC(PassThrough);
	GET_FUNC(PixelMapfv);
	GET_FUNC(PixelMapuiv);
	GET_FUNC(PixelMapusv);
	GET_FUNC(PixelStoref);
	GET_FUNC(PixelStorei);
	GET_FUNC(PixelTransferf);
	GET_FUNC(PixelTransferi);
	GET_FUNC(PixelZoom);
	GET_FUNC(PointSize);
	GET_FUNC(PolygonMode);
	GET_FUNC(PolygonOffset);
	GET_FUNC(PolygonStipple);
	GET_FUNC(PopAttrib);
	GET_FUNC(PopClientAttrib);
	GET_FUNC(PopMatrix);
	GET_FUNC(PopName);
	GET_FUNC(PrioritizeTextures);
	GET_FUNC(PushAttrib);
	GET_FUNC(PushClientAttrib);
	GET_FUNC(PushMatrix);
	GET_FUNC(PushName);
	GET_FUNC(RasterPos2d);
	GET_FUNC(RasterPos2dv);
	GET_FUNC(RasterPos2f);
	GET_FUNC(RasterPos2fv);
	GET_FUNC(RasterPos2i);
	GET_FUNC(RasterPos2iv);
	GET_FUNC(RasterPos2s);
	GET_FUNC(RasterPos2sv);
	GET_FUNC(RasterPos3d);
	GET_FUNC(RasterPos3dv);
	GET_FUNC(RasterPos3f);
	GET_FUNC(RasterPos3fv);
	GET_FUNC(RasterPos3i);
	GET_FUNC(RasterPos3iv);
	GET_FUNC(RasterPos3s);
	GET_FUNC(RasterPos3sv);
	GET_FUNC(RasterPos4d);
	GET_FUNC(RasterPos4dv);
	GET_FUNC(RasterPos4f);
	GET_FUNC(RasterPos4fv);
	GET_FUNC(RasterPos4i);
	GET_FUNC(RasterPos4iv);
	GET_FUNC(RasterPos4s);
	GET_FUNC(RasterPos4sv);
	GET_FUNC(ReadBuffer);
	GET_FUNC(ReadPixels);
	GET_FUNC(Rectd);
	GET_FUNC(Rectdv);
	GET_FUNC(Rectf);
	GET_FUNC(Rectfv);
	GET_FUNC(Recti);
	GET_FUNC(Rectiv);
	GET_FUNC(Rects);
	GET_FUNC(Rectsv);
	GET_FUNC(RenderMode);
	GET_FUNC(Rotated);
	GET_FUNC(Rotatef);
	GET_FUNC(Scaled);
	GET_FUNC(Scalef);
	GET_FUNC(Scissor);
	GET_FUNC(SelectBuffer);
	GET_FUNC(ShadeModel);
	GET_FUNC(StencilFunc);
	GET_FUNC(StencilMask);
	GET_FUNC(StencilOp);
	GET_FUNC(TexCoord1d);
	GET_FUNC(TexCoord1dv);
	GET_FUNC(TexCoord1f);
	GET_FUNC(TexCoord1fv);
	GET_FUNC(TexCoord1i);
	GET_FUNC(TexCoord1iv);
	GET_FUNC(TexCoord1s);
	GET_FUNC(TexCoord1sv);
	GET_FUNC(TexCoord2d);
	GET_FUNC(TexCoord2dv);
	GET_FUNC(TexCoord2f);
	GET_FUNC(TexCoord2fv);
	GET_FUNC(TexCoord2i);
	GET_FUNC(TexCoord2iv);
	GET_FUNC(TexCoord2s);
	GET_FUNC(TexCoord2sv);
	GET_FUNC(TexCoord3d);
	GET_FUNC(TexCoord3dv);
	GET_FUNC(TexCoord3f);
	GET_FUNC(TexCoord3fv);
	GET_FUNC(TexCoord3i);
	GET_FUNC(TexCoord3iv);
	GET_FUNC(TexCoord3s);
	GET_FUNC(TexCoord3sv);
	GET_FUNC(TexCoord4d);
	GET_FUNC(TexCoord4dv);
	GET_FUNC(TexCoord4f);
	GET_FUNC(TexCoord4fv);
	GET_FUNC(TexCoord4i);
	GET_FUNC(TexCoord4iv);
	GET_FUNC(TexCoord4s);
	GET_FUNC(TexCoord4sv);
	GET_FUNC(TexCoordPointer);
	GET_FUNC(TexEnvf);
	GET_FUNC(TexEnvfv);
	GET_FUNC(TexEnvi);
	GET_FUNC(TexEnviv);
	GET_FUNC(TexGend);
	GET_FUNC(TexGendv);
	GET_FUNC(TexGenf);
	GET_FUNC(TexGenfv);
	GET_FUNC(TexGeni);
	GET_FUNC(TexGeniv);
	GET_FUNC(TexImage1D);
	GET_FUNC(TexImage2D);
	GET_FUNC(TexParameterf);
	GET_FUNC(TexParameterfv);
	GET_FUNC(TexParameteri);
	GET_FUNC(TexParameteriv);
	GET_FUNC(TexSubImage1D);
	GET_FUNC(TexSubImage2D);
	GET_FUNC(Translated);
	GET_FUNC(Translatef);
	GET_FUNC(Vertex2d);
	GET_FUNC(Vertex2dv);
	GET_FUNC(Vertex2f);
	GET_FUNC(Vertex2fv);
	GET_FUNC(Vertex2i);
	GET_FUNC(Vertex2iv);
	GET_FUNC(Vertex2s);
	GET_FUNC(Vertex2sv);
	GET_FUNC(Vertex3d);
	GET_FUNC(Vertex3dv);
	GET_FUNC(Vertex3f);
	GET_FUNC(Vertex3fv);
	GET_FUNC(Vertex3i);
	GET_FUNC(Vertex3iv);
	GET_FUNC(Vertex3s);
	GET_FUNC(Vertex3sv);
	GET_FUNC(Vertex4d);
	GET_FUNC(Vertex4dv);
	GET_FUNC(Vertex4f);
	GET_FUNC(Vertex4fv);
	GET_FUNC(Vertex4i);
	GET_FUNC(Vertex4iv);
	GET_FUNC(Vertex4s);
	GET_FUNC(Vertex4sv);
	GET_FUNC(VertexPointer);
	GET_FUNC(Viewport);
}