// Copyright 2014 Vladimir Alyamkin. All Rights Reserved.

#ifndef VAQUOLEUILIB_H
#define VAQUOLEUILIB_H

#include "VaQuolePublicPCH.h"

class VaQuoleWebView;

namespace VaQuole
{

/**
 * Common library functions
 */
extern "C"
{
	/** Initialize QApplication */
	void Init();

	/** Process Qt events (we have to use it because lib lives in main thread */
	void Update();

	/** Clean all Qt and lib related data */
	void Cleanup();
}


/**
 * Class that handles view of one web page
 */
class VaQuoleUI
{

public:
	VaQuoleUI();

	/** Destroy web view and clear memory */
	void Destroy();

	/** Open URL in the View */
	void OpenURL(const TCHAR *NewURL);

	/** Load page with HTML5 benchmark */
	void OpenBenchmark();

	/** Evaluate JS script on current page */
	void EvaluateJavaScript(const TCHAR *ScriptSource);

	/** Get reference to grabbed screen texture */
	const uchar * GrabView();

	/** Change background transparency */
	void SetTransparent(bool transparent = true);

	/** Set desired few size */
	void Resize(int w, int h);


	//////////////////////////////////////////////////////////////////////////
	// JS commands callback

	/** Count cached commands */
	int GetCachedCommandsNumber();

	/** Get one particular command */
	TCHAR * GetCachedCommand(int Index);

	/** Clear commands cache */
	void ClearCachedCommands();


	//////////////////////////////////////////////////////////////////////////
	// Player input

	void MouseMove(int x, int y);
	void MouseClick(int x, int y, VaQuole::EMouseButton::Type button,
					bool bPressed = true,
					unsigned int modifiers = VaQuole::EKeyboardModifier::NoModifier);

	void InputKey(	const unsigned int key,
					const bool bPressed = true,
					const unsigned int modifiers = VaQuole::EKeyboardModifier::NoModifier);

private:
	/** Widget that operates web view */
	VaQuoleWebView *WebView;

};


} // namespace VaQuole

#endif // VAQUOLEUILIB_H
