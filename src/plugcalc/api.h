//
//  Copyright (c) uncle-vunkis 2009-2012 <uncle-vunkis@yandex.ru>
//  You can use, modify, distribute this code or any other part
//  of this program in sources or in binaries only according
//  to License (see /doc/license.txt for more information).
//

#ifndef _CALC_API_H_
#define _CALC_API_H_

#include <vector>
#include <string>

enum CalcDialogItemTypes
{
	CALC_DI_TEXT,
	CALC_DI_VTEXT,
	CALC_DI_SINGLEBOX,
	CALC_DI_DOUBLEBOX,
	CALC_DI_EDIT,
	CALC_DI_PSWEDIT,
	CALC_DI_FIXEDIT,
	CALC_DI_BUTTON,
	CALC_DI_CHECKBOX,
	CALC_DI_RADIOBUTTON,
	CALC_DI_COMBOBOX,
	CALC_DI_LISTBOX,

	CALC_DI_USERCONTROL=255,
};

typedef unsigned __int64 CalcDialogItemFlags;
static const CalcDialogItemFlags
	CALC_DIF_NONE                  = 0,
	CALC_DIF_BOXCOLOR              = 0x0000000000000200ULL,
	CALC_DIF_GROUP                 = 0x0000000000000400ULL,
	CALC_DIF_LEFTTEXT              = 0x0000000000000800ULL,
	CALC_DIF_MOVESELECT            = 0x0000000000001000ULL,
	CALC_DIF_SHOWAMPERSAND         = 0x0000000000002000ULL,
	CALC_DIF_CENTERGROUP           = 0x0000000000004000ULL,
	CALC_DIF_NOBRACKETS            = 0x0000000000008000ULL,
	CALC_DIF_MANUALADDHISTORY      = 0x0000000000008000ULL,
	CALC_DIF_SEPARATOR             = 0x0000000000010000ULL,
	CALC_DIF_SEPARATOR2            = 0x0000000000020000ULL,
	CALC_DIF_EDITOR                = 0x0000000000020000ULL,
	CALC_DIF_LISTNOAMPERSAND       = 0x0000000000020000ULL,
	CALC_DIF_LISTNOBOX             = 0x0000000000040000ULL,
	CALC_DIF_HISTORY               = 0x0000000000040000ULL,
	CALC_DIF_BTNNOCLOSE            = 0x0000000000040000ULL,
	CALC_DIF_CENTERTEXT            = 0x0000000000040000ULL,
	CALC_DIF_SETSHIELD             = 0x0000000000080000ULL,
	CALC_DIF_EDITEXPAND            = 0x0000000000080000ULL,
	CALC_DIF_DROPDOWNLIST          = 0x0000000000100000ULL,
	CALC_DIF_USELASTHISTORY        = 0x0000000000200000ULL,
	CALC_DIF_MASKEDIT              = 0x0000000000400000ULL,
	CALC_DIF_SELECTONENTRY         = 0x0000000000800000ULL,
	CALC_DIF_3STATE                = 0x0000000000800000ULL,
	CALC_DIF_EDITPATH              = 0x0000000001000000ULL,
	CALC_DIF_LISTWRAPMODE          = 0x0000000001000000ULL,
	CALC_DIF_NOAUTOCOMPLETE        = 0x0000000002000000ULL,
	CALC_DIF_LISTAUTOHIGHLIGHT     = 0x0000000002000000ULL,
	CALC_DIF_LISTNOCLOSE           = 0x0000000004000000ULL,
	CALC_DIF_HIDDEN                = 0x0000000010000000ULL,
	CALC_DIF_READONLY              = 0x0000000020000000ULL,
	CALC_DIF_NOFOCUS               = 0x0000000040000000ULL,
	CALC_DIF_DISABLE               = 0x0000000080000000ULL,
	CALC_DIF_DEFAULTBUTTON         = 0x0000000100000000ULL,
	CALC_DIF_FOCUS                 = 0x0000000200000000ULL;


enum CalcMenuFlags
{
	CALC_FMENU_SHOWAMPERSAND        = 0x00000001ULL,
	CALC_FMENU_WRAPMODE             = 0x00000002ULL,
	CALC_FMENU_AUTOHIGHLIGHT        = 0x00000004ULL,
	CALC_FMENU_REVERSEAUTOHIGHLIGHT = 0x00000008ULL,
};

enum CalcEditorBlockTypes
{
	CALC_BTYPE_NONE,
	CALC_BTYPE_STREAM,
	CALC_BTYPE_COLUMN
};

typedef unsigned __int64 CALCCOLORFLAGS;
static const CALCCOLORFLAGS
CALC_FCF_FG_4BIT  = 0x0000000000000001ULL,
CALC_FCF_BG_4BIT  = 0x0000000000000002ULL;


struct CalcDialogItem
{
	CalcDialogItemTypes Type;

	int       X1, Y1, X2, Y2;
	union
	{
		intptr_t Reserved;
		intptr_t Selected;
	};
	unsigned long long Flags;
	const wchar_t *PtrData;
};

class CalcMenuItem
{
public:
	CalcMenuItem() { Text = NULL; Selected = 0; Checked = 0; Separator = 0; }
public:
	const wchar_t *Text;
	int  Selected;
	int  Checked;
	int  Separator;
};

struct CalcEditorInfo
{
	size_t StructSize;
	intptr_t EditorID;
	intptr_t WindowSizeX;
	intptr_t WindowSizeY;
	intptr_t TotalLines;
	intptr_t CurLine;
	intptr_t CurPos;
	intptr_t CurTabPos;
	intptr_t TopScreenLine;
	intptr_t LeftPos;
	intptr_t Overtype;
	intptr_t BlockType;
	intptr_t BlockStartLine;
	uintptr_t Options;
	intptr_t TabSize;
	size_t BookmarkCount;
	size_t SessionBookmarkCount;
	uintptr_t CurState;
	uintptr_t CodePage;
};

struct CalcEditorSelect
{
	size_t StructSize;
	intptr_t BlockType;
	intptr_t BlockStartLine;
	intptr_t BlockStartPos;
	intptr_t BlockWidth;
	intptr_t BlockHeight;
};

struct CalcEditorGetString
{
	size_t StructSize;
	intptr_t StringNumber;
	intptr_t StringLength;
	const wchar_t *StringText;
	const wchar_t *StringEOL;
	intptr_t SelStart;
	intptr_t SelEnd;
};

struct CalcCoord 
{
	short X;
	short Y;
};

struct CalcRect 
{
	short Left;
	short Top;
	short Right;
	short Bottom;
};

struct CalcColor
{
	unsigned __int64 Flags;
	unsigned int ForegroundColor;
	unsigned int BackgroundColor;
	void* Reserved;
};

struct CalcDialogItemColors
{
	size_t StructSize;
	unsigned __int64 Flags;
	size_t ColorsCount;
	struct CalcColor* Colors;
};


///////////////////////////////////////////////////////////////////////////////////

typedef void *DLGHANDLE;
#if defined(_WIN64)
typedef __int64 CALC_INT_PTR;
#else
typedef __int32 CALC_INT_PTR;
#endif
typedef CALC_INT_PTR (__stdcall *CALCDLGPROC)(DLGHANDLE hdlg, int msg, int param1, void *param2);


class CalcDialog
{
public:
	CalcDialog();
	virtual ~CalcDialog();

	bool Init(int id, int X1, int Y1, int X2, int Y2, const wchar_t *HelpTopic, 
					struct CalcDialogItem *Item, unsigned int ItemsNumber);
	intptr_t Run();

	void EnableRedraw(bool);
	void ResizeDialog(const CalcCoord & dims);
	void RedrawDialog();
	void GetDlgRect(CalcRect *rect);
	void Close(int exitcode);
	
	void GetDlgItemShort(int id, CalcDialogItem *item);
	void SetDlgItemShort(int id, const CalcDialogItem & item);
	void SetItemPosition(int id, const CalcRect & rect);
	int  GetFocus();
	void SetFocus(int id);
	void EditChange(int id, const CalcDialogItem & item);
	void SetSelection(int id, const CalcEditorSelect & sel);
	void SetCursorPos(int id, const CalcCoord & pos);
	void GetText(int id, std::wstring &str);
	void SetText(int id, const std::wstring & str);
	bool IsChecked(int id);
	void AddHistory(int id, const std::wstring & str);

public:
	virtual CALC_INT_PTR OnInitDialog(int param1, void *param2) { return -1; }
	virtual CALC_INT_PTR OnClose(int param1, void *param2) { return -1; }
	virtual CALC_INT_PTR OnResizeConsole(int param1, void *param2) { return -1; }
	virtual CALC_INT_PTR OnDrawDialog(int param1, void *param2) { return -1; }
	virtual CALC_INT_PTR OnButtonClick(int param1, void *param2) { return -1; }
	virtual CALC_INT_PTR OnGotFocus(int param1, void *param2) { return -1; }
	virtual CALC_INT_PTR OnEditChange(int param1, void *param2) { return -1; }
	virtual CALC_INT_PTR OnInput(int param1, void *param2) { return -1; }
	virtual CALC_INT_PTR OnCtrlColorDlgItem(int param1, void *param2) { return -1; }

public:
	typedef CALC_INT_PTR (CalcDialog::*CalcDialogCallback)(int param1, void *param2);
	CalcDialogCallback *msg_tbl;
protected:	
	DLGHANDLE hdlg;
};

///////////////////////////////////////////////////////////////////////////////////

class CalcDialogFuncs
{
public:
	virtual void EnableRedraw(DLGHANDLE, bool) = 0;
	virtual void ResizeDialog(DLGHANDLE, const CalcCoord & dims) = 0;
	virtual void RedrawDialog(DLGHANDLE) = 0;
	virtual void Close(DLGHANDLE, int exitcode) = 0;
	virtual void GetDlgRect(DLGHANDLE, CalcRect *rect) = 0;

	virtual void GetDlgItemShort(DLGHANDLE, int id, CalcDialogItem *item) = 0;
	virtual void SetDlgItemShort(DLGHANDLE, int id, const CalcDialogItem & item) = 0;
	virtual void SetItemPosition(DLGHANDLE, int id, const CalcRect & rect) = 0;
	virtual int  GetFocus(DLGHANDLE) = 0;
	virtual void SetFocus(DLGHANDLE, int id) = 0;
	virtual void EditChange(DLGHANDLE, int id, const CalcDialogItem & item) = 0;
	virtual void SetSelection(DLGHANDLE, int id, const CalcEditorSelect & sel) = 0;
	virtual void SetCursorPos(DLGHANDLE, int id, const CalcCoord & pos) = 0;
	virtual void GetText(DLGHANDLE, int id, std::wstring &str) = 0;
	virtual void SetText(DLGHANDLE, int id, const std::wstring & str) = 0;
	virtual void AddHistory(DLGHANDLE, int id, const std::wstring & str) = 0;
	virtual bool IsChecked(DLGHANDLE, int id) = 0;

public:
	virtual DLGHANDLE DialogInit(int id, int X1, int Y1, int X2, int Y2, const wchar_t *HelpTopic, 
								struct CalcDialogItem *Item, unsigned int ItemsNumber, 
								CALCDLGPROC dlgProc) = 0;
	virtual intptr_t DialogRun(DLGHANDLE) = 0;
	virtual void DialogFree(DLGHANDLE) = 0;
	virtual CALC_INT_PTR DefDlgProc(DLGHANDLE hdlg, int msg, int param1, void *param2) = 0;
	virtual void ConvertToDlgItem(void *, CalcDialogItem *) = 0;
	virtual void ConvertFromDlgItem(const CalcDialogItem *, void *) = 0;

	virtual CALC_INT_PTR PreProcessMessage(DLGHANDLE hdlg, int msg, int &param1, void * &param2) = 0;
	virtual CALC_INT_PTR PostProcessMessage(DLGHANDLE hdlg, int msg, CALC_INT_PTR &ret, int &param1, void * &param2) = 0;

	virtual CalcDialog::CalcDialogCallback *GetMessageTable() = 0;
};

///////////////////////////////////////////////////////////////////////////////////

class CalcApi
{
public:
	virtual void GetPluginInfo(void *pinfo, const wchar_t *name) = 0;
	virtual bool IsOpenedFromEditor(void *oinfo, int OpenFrom) = 0;
	virtual const wchar_t *GetMsg(int MsgId) = 0;
	virtual int GetMinVersion(void *ver) = 0;
	virtual CalcDialogFuncs *GetDlgFuncs() = 0;

	virtual intptr_t Message(unsigned long Flags, const wchar_t *HelpTopic, const wchar_t * const *Items,
						int ItemsNumber, int ButtonsNumber) = 0;

	virtual intptr_t Menu(int X, int Y, int MaxHeight, unsigned long long Flags,
					const wchar_t *Title, const wchar_t *HelpTopic, 
					const std::vector<CalcMenuItem> & Items) = 0;

	virtual void EditorGet(CalcEditorGetString *string, CalcEditorInfo *info) = 0;
	virtual void EditorSelect(const CalcEditorSelect & sel) = 0;
	virtual void EditorInsert(const wchar_t *text) = 0;
	virtual void EditorRedraw() = 0;

	virtual void GetDlgColors(CalcColor *edit_color, CalcColor *sel_color, CalcColor *highlight_color) = 0;

	virtual int  GetCmdLine(std::wstring &cmd) = 0;
	virtual void SetCmdLine(const std::wstring & cmd) = 0;

	virtual bool SettingsBegin() = 0;
	virtual bool SettingsEnd() = 0;
	virtual bool SettingsGet(const wchar_t *name, std::wstring *sval, unsigned long *ival) = 0;
	virtual bool SettingsSet(const wchar_t *name, const std::wstring *sval, const unsigned long *ival) = 0;

	virtual const wchar_t *GetModuleName() = 0;

	
};

extern CalcApi *CreateApiFar3(void *info);
extern void GetGlobalInfoFar3(void *ginfo, const wchar_t *name);

extern CalcApi *api;

#endif
