#include "pch.h"

#if !defined(_WIN32)
/* stub */
void *D3D_GL_GetProcAddress(const char *name)
{
	(void)name;
	return NULL;
}
#else

#include <windows.h>

typedef struct
{
	const char *fake;
	const char *real;
} remapName_t;

static const remapName_t remapNames[] =
{
	{"glAccum", "_glAccum@8"},
	{"glAlphaFunc", "_glAlphaFunc@8"},
	{"glAreTexturesResident", "_glAreTexturesResident@12"},
	{"glArrayElement", "_glArrayElement@4"},
	{"glBegin", "_glBegin@4"},
	{"glBindTexture", "_glBindTexture@8"},
	{"glBitmap", "_glBitmap@28"},
	{"glBlendFunc", "_glBlendFunc@8"},
	{"glCallList", "_glCallList@4"},
	{"glCallLists", "_glCallLists@12"},
	{"glClear", "_glClear@4"},
	{"glClearAccum", "_glClearAccum@16"},
	{"glClearColor", "_glClearColor@16"},
	{"glClearDepth", "_glClearDepth@8"},
	{"glClearIndex", "_glClearIndex@4"},
	{"glClearStencil", "_glClearStencil@4"},
	{"glClipPlane", "_glClipPlane@8"},
	{"glColor3b", "_glColor3b@12"},
	{"glColor3bv", "_glColor3bv@4"},
	{"glColor3d", "_glColor3d@24"},
	{"glColor3dv", "_glColor3dv@4"},
	{"glColor3f", "_glColor3f@12"},
	{"glColor3fv", "_glColor3fv@4"},
	{"glColor3i", "_glColor3i@12"},
	{"glColor3iv", "_glColor3iv@4"},
	{"glColor3s", "_glColor3s@12"},
	{"glColor3sv", "_glColor3sv@4"},
	{"glColor3ub", "_glColor3ub@12"},
	{"glColor3ubv", "_glColor3ubv@4"},
	{"glColor3ui", "_glColor3ui@12"},
	{"glColor3uiv", "_glColor3uiv@4"},
	{"glColor3us", "_glColor3us@12"},
	{"glColor3usv", "_glColor3usv@4"},
	{"glColor4b", "_glColor4b@16"},
	{"glColor4bv", "_glColor4bv@4"},
	{"glColor4d", "_glColor4d@32"},
	{"glColor4dv", "_glColor4dv@4"},
	{"glColor4f", "_glColor4f@16"},
	{"glColor4fv", "_glColor4fv@4"},
	{"glColor4i", "_glColor4i@16"},
	{"glColor4iv", "_glColor4iv@4"},
	{"glColor4s", "_glColor4s@16"},
	{"glColor4sv", "_glColor4sv@4"},
	{"glColor4ub", "_glColor4ub@16"},
	{"glColor4ubv", "_glColor4ubv@4"},
	{"glColor4ui", "_glColor4ui@16"},
	{"glColor4uiv", "_glColor4uiv@4"},
	{"glColor4us", "_glColor4us@16"},
	{"glColor4usv", "_glColor4usv@4"},
	{"glColorMask", "_glColorMask@16"},
	{"glColorMaterial", "_glColorMaterial@8"},
	{"glColorPointer", "_glColorPointer@16"},
	{"glCopyPixels", "_glCopyPixels@20"},
	{"glCopyTexImage1D", "_glCopyTexImage1D@28"},
	{"glCopyTexImage2D", "_glCopyTexImage2D@32"},
	{"glCopyTexSubImage1D", "_glCopyTexSubImage1D@24"},
	{"glCopyTexSubImage2D", "_glCopyTexSubImage2D@32"},
	{"glCullFace", "_glCullFace@4"},
	{"glDeleteLists", "_glDeleteLists@8"},
	{"glDeleteTextures", "_glDeleteTextures@8"},
	{"glDepthFunc", "_glDepthFunc@4"},
	{"glDepthMask", "_glDepthMask@4"},
	{"glDepthRange", "_glDepthRange@16"},
	{"glDisable", "_glDisable@4"},
	{"glDisableClientState", "_glDisableClientState@4"},
	{"glDrawArrays", "_glDrawArrays@12"},
	{"glDrawBuffer", "_glDrawBuffer@4"},
	{"glDrawElements", "_glDrawElements@16"},
	{"glDrawPixels", "_glDrawPixels@20"},
	{"glEdgeFlag", "_glEdgeFlag@4"},
	{"glEdgeFlagPointer", "_glEdgeFlagPointer@8"},
	{"glEdgeFlagv", "_glEdgeFlagv@4"},
	{"glEnable", "_glEnable@4"},
	{"glEnableClientState", "_glEnableClientState@4"},
	{"glEnd", "_glEnd@0"},
	{"glEndList", "_glEndList@0"},
	{"glEvalCoord1d", "_glEvalCoord1d@8"},
	{"glEvalCoord1dv", "_glEvalCoord1dv@4"},
	{"glEvalCoord1f", "_glEvalCoord1f@4"},
	{"glEvalCoord1fv", "_glEvalCoord1fv@4"},
	{"glEvalCoord2d", "_glEvalCoord2d@16"},
	{"glEvalCoord2dv", "_glEvalCoord2dv@4"},
	{"glEvalCoord2f", "_glEvalCoord2f@8"},
	{"glEvalCoord2fv", "_glEvalCoord2fv@4"},
	{"glEvalMesh1", "_glEvalMesh1@12"},
	{"glEvalMesh2", "_glEvalMesh2@20"},
	{"glEvalPoint1", "_glEvalPoint1@4"},
	{"glEvalPoint2", "_glEvalPoint2@8"},
	{"glFeedbackBuffer", "_glFeedbackBuffer@12"},
	{"glFinish", "_glFinish@0"},
	{"glFlush", "_glFlush@0"},
	{"glFogf", "_glFogf@8"},
	{"glFogfv", "_glFogfv@8"},
	{"glFogi", "_glFogi@8"},
	{"glFogiv", "_glFogiv@8"},
	{"glFrontFace", "_glFrontFace@4"},
	{"glFrustum", "_glFrustum@48"},
	{"glGenLists", "_glGenLists@4"},
	{"glGenTextures", "_glGenTextures@8"},
	{"glGetBooleanv", "_glGetBooleanv@8"},
	{"glGetClipPlane", "_glGetClipPlane@8"},
	{"glGetDoublev", "_glGetDoublev@8"},
	{"glGetError", "_glGetError@0"},
	{"glGetFloatv", "_glGetFloatv@8"},
	{"glGetIntegerv", "_glGetIntegerv@8"},
	{"glGetLightfv", "_glGetLightfv@12"},
	{"glGetLightiv", "_glGetLightiv@12"},
	{"glGetMapdv", "_glGetMapdv@12"},
	{"glGetMapfv", "_glGetMapfv@12"},
	{"glGetMapiv", "_glGetMapiv@12"},
	{"glGetMaterialfv", "_glGetMaterialfv@12"},
	{"glGetMaterialiv", "_glGetMaterialiv@12"},
	{"glGetPixelMapfv", "_glGetPixelMapfv@8"},
	{"glGetPixelMapuiv", "_glGetPixelMapuiv@8"},
	{"glGetPixelMapusv", "_glGetPixelMapusv@8"},
	{"glGetPointerv", "_glGetPointerv@8"},
	{"glGetPolygonStipple", "_glGetPolygonStipple@4"},
	{"glGetString", "_glGetString@4"},
	{"glGetTexEnvfv", "_glGetTexEnvfv@12"},
	{"glGetTexEnviv", "_glGetTexEnviv@12"},
	{"glGetTexGendv", "_glGetTexGendv@12"},
	{"glGetTexGenfv", "_glGetTexGenfv@12"},
	{"glGetTexGeniv", "_glGetTexGeniv@12"},
	{"glGetTexImage", "_glGetTexImage@20"},
	{"glGetTexLevelParameterfv", "_glGetTexLevelParameterfv@16"},
	{"glGetTexLevelParameteriv", "_glGetTexLevelParameteriv@16"},
	{"glGetTexParameterfv", "_glGetTexParameterfv@12"},
	{"glGetTexParameteriv", "_glGetTexParameteriv@12"},
	{"glHint", "_glHint@8"},
	{"glIndexMask", "_glIndexMask@4"},
	{"glIndexPointer", "_glIndexPointer@12"},
	{"glIndexd", "_glIndexd@8"},
	{"glIndexdv", "_glIndexdv@4"},
	{"glIndexf", "_glIndexf@4"},
	{"glIndexfv", "_glIndexfv@4"},
	{"glIndexi", "_glIndexi@4"},
	{"glIndexiv", "_glIndexiv@4"},
	{"glIndexs", "_glIndexs@4"},
	{"glIndexsv", "_glIndexsv@4"},
	{"glIndexub", "_glIndexub@4"},
	{"glIndexubv", "_glIndexubv@4"},
	{"glInitNames", "_glInitNames@0"},
	{"glInterleavedArrays", "_glInterleavedArrays@12"},
	{"glIsEnabled", "_glIsEnabled@4"},
	{"glIsList", "_glIsList@4"},
	{"glIsTexture", "_glIsTexture@4"},
	{"glLightModelf", "_glLightModelf@8"},
	{"glLightModelfv", "_glLightModelfv@8"},
	{"glLightModeli", "_glLightModeli@8"},
	{"glLightModeliv", "_glLightModeliv@8"},
	{"glLightf", "_glLightf@12"},
	{"glLightfv", "_glLightfv@12"},
	{"glLighti", "_glLighti@12"},
	{"glLightiv", "_glLightiv@12"},
	{"glLineStipple", "_glLineStipple@8"},
	{"glLineWidth", "_glLineWidth@4"},
	{"glListBase", "_glListBase@4"},
	{"glLoadIdentity", "_glLoadIdentity@0"},
	{"glLoadMatrixd", "_glLoadMatrixd@4"},
	{"glLoadMatrixf", "_glLoadMatrixf@4"},
	{"glLoadName", "_glLoadName@4"},
	{"glLogicOp", "_glLogicOp@4"},
	{"glMap1d", "_glMap1d@32"},
	{"glMap1f", "_glMap1f@24"},
	{"glMap2d", "_glMap2d@56"},
	{"glMap2f", "_glMap2f@40"},
	{"glMapGrid1d", "_glMapGrid1d@20"},
	{"glMapGrid1f", "_glMapGrid1f@12"},
	{"glMapGrid2d", "_glMapGrid2d@40"},
	{"glMapGrid2f", "_glMapGrid2f@24"},
	{"glMaterialf", "_glMaterialf@12"},
	{"glMaterialfv", "_glMaterialfv@12"},
	{"glMateriali", "_glMateriali@12"},
	{"glMaterialiv", "_glMaterialiv@12"},
	{"glMatrixMode", "_glMatrixMode@4"},
	{"glMultMatrixd", "_glMultMatrixd@4"},
	{"glMultMatrixf", "_glMultMatrixf@4"},
	{"glNewList", "_glNewList@8"},
	{"glNormal3b", "_glNormal3b@12"},
	{"glNormal3bv", "_glNormal3bv@4"},
	{"glNormal3d", "_glNormal3d@24"},
	{"glNormal3dv", "_glNormal3dv@4"},
	{"glNormal3f", "_glNormal3f@12"},
	{"glNormal3fv", "_glNormal3fv@4"},
	{"glNormal3i", "_glNormal3i@12"},
	{"glNormal3iv", "_glNormal3iv@4"},
	{"glNormal3s", "_glNormal3s@12"},
	{"glNormal3sv", "_glNormal3sv@4"},
	{"glNormalPointer", "_glNormalPointer@12"},
	{"glOrtho", "_glOrtho@48"},
	{"glPassThrough", "_glPassThrough@4"},
	{"glPixelMapfv", "_glPixelMapfv@12"},
	{"glPixelMapuiv", "_glPixelMapuiv@12"},
	{"glPixelMapusv", "_glPixelMapusv@12"},
	{"glPixelStoref", "_glPixelStoref@8"},
	{"glPixelStorei", "_glPixelStorei@8"},
	{"glPixelTransferf", "_glPixelTransferf@8"},
	{"glPixelTransferi", "_glPixelTransferi@8"},
	{"glPixelZoom", "_glPixelZoom@8"},
	{"glPointSize", "_glPointSize@4"},
	{"glPolygonMode", "_glPolygonMode@8"},
	{"glPolygonOffset", "_glPolygonOffset@8"},
	{"glPolygonStipple", "_glPolygonStipple@4"},
	{"glPopAttrib", "_glPopAttrib@0"},
	{"glPopClientAttrib", "_glPopClientAttrib@0"},
	{"glPopMatrix", "_glPopMatrix@0"},
	{"glPopName", "_glPopName@0"},
	{"glPrioritizeTextures", "_glPrioritizeTextures@12"},
	{"glPushAttrib", "_glPushAttrib@4"},
	{"glPushClientAttrib", "_glPushClientAttrib@4"},
	{"glPushMatrix", "_glPushMatrix@0"},
	{"glPushName", "_glPushName@4"},
	{"glRasterPos2d", "_glRasterPos2d@16"},
	{"glRasterPos2dv", "_glRasterPos2dv@4"},
	{"glRasterPos2f", "_glRasterPos2f@8"},
	{"glRasterPos2fv", "_glRasterPos2fv@4"},
	{"glRasterPos2i", "_glRasterPos2i@8"},
	{"glRasterPos2iv", "_glRasterPos2iv@4"},
	{"glRasterPos2s", "_glRasterPos2s@8"},
	{"glRasterPos2sv", "_glRasterPos2sv@4"},
	{"glRasterPos3d", "_glRasterPos3d@24"},
	{"glRasterPos3dv", "_glRasterPos3dv@4"},
	{"glRasterPos3f", "_glRasterPos3f@12"},
	{"glRasterPos3fv", "_glRasterPos3fv@4"},
	{"glRasterPos3i", "_glRasterPos3i@12"},
	{"glRasterPos3iv", "_glRasterPos3iv@4"},
	{"glRasterPos3s", "_glRasterPos3s@12"},
	{"glRasterPos3sv", "_glRasterPos3sv@4"},
	{"glRasterPos4d", "_glRasterPos4d@32"},
	{"glRasterPos4dv", "_glRasterPos4dv@4"},
	{"glRasterPos4f", "_glRasterPos4f@16"},
	{"glRasterPos4fv", "_glRasterPos4fv@4"},
	{"glRasterPos4i", "_glRasterPos4i@16"},
	{"glRasterPos4iv", "_glRasterPos4iv@4"},
	{"glRasterPos4s", "_glRasterPos4s@16"},
	{"glRasterPos4sv", "_glRasterPos4sv@4"},
	{"glReadBuffer", "_glReadBuffer@4"},
	{"glReadPixels", "_glReadPixels@28"},
	{"glRectd", "_glRectd@32"},
	{"glRectdv", "_glRectdv@8"},
	{"glRectf", "_glRectf@16"},
	{"glRectfv", "_glRectfv@8"},
	{"glRecti", "_glRecti@16"},
	{"glRectiv", "_glRectiv@8"},
	{"glRects", "_glRects@16"},
	{"glRectsv", "_glRectsv@8"},
	{"glRenderMode", "_glRenderMode@4"},
	{"glRotated", "_glRotated@32"},
	{"glRotatef", "_glRotatef@16"},
	{"glScaled", "_glScaled@24"},
	{"glScalef", "_glScalef@12"},
	{"glScissor", "_glScissor@16"},
	{"glSelectBuffer", "_glSelectBuffer@8"},
	{"glShadeModel", "_glShadeModel@4"},
	{"glStencilFunc", "_glStencilFunc@12"},
	{"glStencilMask", "_glStencilMask@4"},
	{"glStencilOp", "_glStencilOp@12"},
	{"glTexCoord1d", "_glTexCoord1d@8"},
	{"glTexCoord1dv", "_glTexCoord1dv@4"},
	{"glTexCoord1f", "_glTexCoord1f@4"},
	{"glTexCoord1fv", "_glTexCoord1fv@4"},
	{"glTexCoord1i", "_glTexCoord1i@4"},
	{"glTexCoord1iv", "_glTexCoord1iv@4"},
	{"glTexCoord1s", "_glTexCoord1s@4"},
	{"glTexCoord1sv", "_glTexCoord1sv@4"},
	{"glTexCoord2d", "_glTexCoord2d@16"},
	{"glTexCoord2dv", "_glTexCoord2dv@4"},
	{"glTexCoord2f", "_glTexCoord2f@8"},
	{"glTexCoord2fv", "_glTexCoord2fv@4"},
	{"glTexCoord2i", "_glTexCoord2i@8"},
	{"glTexCoord2iv", "_glTexCoord2iv@4"},
	{"glTexCoord2s", "_glTexCoord2s@8"},
	{"glTexCoord2sv", "_glTexCoord2sv@4"},
	{"glTexCoord3d", "_glTexCoord3d@24"},
	{"glTexCoord3dv", "_glTexCoord3dv@4"},
	{"glTexCoord3f", "_glTexCoord3f@12"},
	{"glTexCoord3fv", "_glTexCoord3fv@4"},
	{"glTexCoord3i", "_glTexCoord3i@12"},
	{"glTexCoord3iv", "_glTexCoord3iv@4"},
	{"glTexCoord3s", "_glTexCoord3s@12"},
	{"glTexCoord3sv", "_glTexCoord3sv@4"},
	{"glTexCoord4d", "_glTexCoord4d@32"},
	{"glTexCoord4dv", "_glTexCoord4dv@4"},
	{"glTexCoord4f", "_glTexCoord4f@16"},
	{"glTexCoord4fv", "_glTexCoord4fv@4"},
	{"glTexCoord4i", "_glTexCoord4i@16"},
	{"glTexCoord4iv", "_glTexCoord4iv@4"},
	{"glTexCoord4s", "_glTexCoord4s@16"},
	{"glTexCoord4sv", "_glTexCoord4sv@4"},
	{"glTexCoordPointer", "_glTexCoordPointer@16"},
	{"glTexEnvf", "_glTexEnvf@12"},
	{"glTexEnvfv", "_glTexEnvfv@12"},
	{"glTexEnvi", "_glTexEnvi@12"},
	{"glTexEnviv", "_glTexEnviv@12"},
	{"glTexGend", "_glTexGend@16"},
	{"glTexGendv", "_glTexGendv@12"},
	{"glTexGenf", "_glTexGenf@12"},
	{"glTexGenfv", "_glTexGenfv@12"},
	{"glTexGeni", "_glTexGeni@12"},
	{"glTexGeniv", "_glTexGeniv@12"},
	{"glTexImage1D", "_glTexImage1D@32"},
	{"glTexImage2D", "_glTexImage2D@36"},
	{"glTexParameterf", "_glTexParameterf@12"},
	{"glTexParameterfv", "_glTexParameterfv@12"},
	{"glTexParameteri", "_glTexParameteri@12"},
	{"glTexParameteriv", "_glTexParameteriv@12"},
	{"glTexSubImage1D", "_glTexSubImage1D@28"},
	{"glTexSubImage2D", "_glTexSubImage2D@36"},
	{"glTranslated", "_glTranslated@24"},
	{"glTranslatef", "_glTranslatef@12"},
	{"glVertex2d", "_glVertex2d@16"},
	{"glVertex2dv", "_glVertex2dv@4"},
	{"glVertex2f", "_glVertex2f@8"},
	{"glVertex2fv", "_glVertex2fv@4"},
	{"glVertex2i", "_glVertex2i@8"},
	{"glVertex2iv", "_glVertex2iv@4"},
	{"glVertex2s", "_glVertex2s@8"},
	{"glVertex2sv", "_glVertex2sv@4"},
	{"glVertex3d", "_glVertex3d@24"},
	{"glVertex3dv", "_glVertex3dv@4"},
	{"glVertex3f", "_glVertex3f@12"},
	{"glVertex3fv", "_glVertex3fv@4"},
	{"glVertex3i", "_glVertex3i@12"},
	{"glVertex3iv", "_glVertex3iv@4"},
	{"glVertex3s", "_glVertex3s@12"},
	{"glVertex3sv", "_glVertex3sv@4"},
	{"glVertex4d", "_glVertex4d@32"},
	{"glVertex4dv", "_glVertex4dv@4"},
	{"glVertex4f", "_glVertex4f@16"},
	{"glVertex4fv", "_glVertex4fv@4"},
	{"glVertex4i", "_glVertex4i@16"},
	{"glVertex4iv", "_glVertex4iv@4"},
	{"glVertex4s", "_glVertex4s@16"},
	{"glVertex4sv", "_glVertex4sv@4"},
	{"glVertexPointer", "_glVertexPointer@16"},
	{"glViewport", "_glViewport@16"}
};

static const GLubyte *APIENTRY My_glGetString(GLenum name)
{
	const char *result;

	switch (name)
	{
	case GL_VERSION:
		result = "1.1";
		break;

	default:
		result = "";
		break;
	}

	return (const GLubyte *)result;
}

void *D3D_GL_GetProcAddress(const char *name)
{
	static HMODULE hEngine;
	static BOOL bLoadedEngine;

	if (!bLoadedEngine)
	{
		hEngine = GetModuleHandleW(L"hw.dll");
		bLoadedEngine = TRUE;
	}

	if (!hEngine)
		return NULL;

	// glGetString(GL_VERSION) returns 6.0 so we need to replace it with a stub...
	if (!strcmp(name, "glGetString"))
		return (void *)My_glGetString;

	int numRemap = sizeof(remapNames) / sizeof(*remapNames);

	for (int i = 0; i < numRemap; i++)
	{
		if (!strcmp(remapNames[i].fake, name))
			return (void *)GetProcAddress(hEngine, remapNames[i].real);
	}

	return NULL;
}

#endif
