﻿/*	@(#)Copyright (C) H.Shirouzu 2013-2017   miscfunc.h	Ver4.50 */
/* ========================================================================
	Project  Name			: IP Messenger for Win32
	Module Name				: Misc functions
	Create					: 2013-03-03(Sun)
	Update					: 2017-06-12(Mon)
	Copyright				: H.Shirouzu
	Reference				: 
	======================================================================== */

#ifndef MISCFUNC_H
#define MISCFUNC_H

BOOL IsImageInClipboard(HWND hWnd, UINT *cf_type=NULL);
BOOL IsTextInClipboard(HWND hWnd);

BOOL SetFileButton(TDlg *dlg, int buttonID, ShareInfo *info, const char *auto_saved=NULL);
BOOL PrepareBmp(int cx, int cy, int *_aligned_line_size, VBuf *vbuf);
HBITMAP FinishBmp(VBuf *vbuf);

#define MSS_SPACE	0x00000001
#define MSS_NOPOINT	0x00000002
int MakeSizeString(char *buf, int64 size, int flg=0);

BOOL IsUserNameExt(Cfg *cfg);
BOOL MakeClipPathW(WCHAR *clip_path, Cfg *cfg, const WCHAR *fname);
BOOL IsValidFileName(char *fname);
const char *GetUserNameDigestField(const char *user);
BOOL VerifyUserNameExtension(Cfg *cfg, MsgBuf *msg);
BOOL GenUserNameDigestVal(const BYTE *key, BYTE *digest);
BOOL GenUserNameDigest(char *org_name, const BYTE *key, char *new_name);
int VerifyUserNameDigest(const char *user, const BYTE *key);

void MsgToHost(const MsgBuf *msg, Host *host, Time_t t=0);
BOOL DictPubToHost(IPDict *dict, Host *host);
BOOL NeedUpdateHost(Host *h1, Host *h2);
size_t MakeHostDict(Host *host, std::shared_ptr<IPDict> dict);
BOOL DictToHost(std::shared_ptr<IPDict> dict, Host *host);
int MakeHostListStr(char *buf, Host *host);


BOOL MakeDirU8(char *dir);
BOOL MakeDirW(WCHAR *dir);
BOOL MakeDirAllU8(char *dir);
BOOL MakeDirAllW(WCHAR *dir);
HANDLE CreateFileWithDirU8(const char *path, DWORD flg, DWORD share, SECURITY_ATTRIBUTES *sa,
	DWORD create_flg, DWORD attr, HANDLE hTmpl);
void MakeClipFileName(int id, int pos, int prefix, char *buf);
BOOL MakeImageFolderName(Cfg *, char *dir);
BOOL MakeImageTmpFileName(const char *dir, char *fname);
BOOL MakeNonExistFileName(const char *dir, char *path);
BOOL MakeAutoSaveDir(Cfg *cfg, char *dir);
int MakeDownloadLinkRootDirW(Cfg *cfg, WCHAR *dir);
BOOL MakeDownloadLinkDirW(Cfg *cfg, Time_t t, WCHAR *dir);
BOOL MakeDownloadLinkW(Cfg *cfg, const WCHAR *fname, Time_t t, BOOL is_recv, WCHAR *link);
BOOL CreateDownloadLinkW(Cfg *cfg, const WCHAR *link, const WCHAR *target, Time_t t, BOOL is_recv);
BOOL CreateDownloadLinkU8(Cfg *cfg, const char *link, const char *target, Time_t t, BOOL is_recv);
BOOL ConfirmDownloadLinkW(Cfg *cfg, const WCHAR *link_path, BOOL is_update=TRUE,
	WCHAR *targ=NULL, WCHAR *linked_targ=NULL);

BOOL SaveImageFile(Cfg *cfg, const char *target_fname, VBuf *buf);
VBuf *LoadImageFile(Cfg *cfg, const char *fname);
BOOL LoadImageFile(Cfg *cfg, const char *fname, VBuf *vbuf);

UrlObj *SearchUrlObj(TListEx<UrlObj> *list, char *protocol);
void SetDlgIcon(HWND hWnd);
int MakeListString(Cfg *cfg, HostSub *hostSub, THosts *hosts, char *buf, BOOL is_log=FALSE);
int MakeListString(Cfg *cfg, Host *host, char *buf, BOOL is_log=FALSE);

enum LinkKind { LK_NONE, LK_FILE, LK_FILE_URL, LK_URL };
enum LinkActKind { LAK_NONE, LAK_CLICK, LAK_DBLCLICK };
enum JumpLinkFlg { JLF_NONE=0, JLF_DBLCLICK=1, JLF_VIEWER=2 };
enum JumpLinkRes { JLR_SKIP, JLR_OK, JLR_FAIL };
LinkKind GetLinkKind(Cfg *cfg, const WCHAR *s);
LinkActKind GetLinkActKind(Cfg *cfg, LinkKind lk, BOOL is_logview);
BOOL CheckExtW(Cfg *cfg, const WCHAR *s, BOOL *is_dir=NULL);
BOOL CheckExtU8(Cfg *cfg, const char *s, BOOL *is_dir=NULL);
JumpLinkRes JumpLinkWithCheck(TWin *parent, Cfg *cfg, const WCHAR *s, DWORD flg=JLF_NONE);


BOOL CheckPassword(const char *cfgPasswd, const char *inputPasswd);
void MakePassword(const char *inputPasswd, char *outputPasswd);

BOOL SetImeOpenStatus(HWND hWnd, BOOL flg);
BOOL GetImeOpenStatus(HWND hWnd);

BOOL SetHotKey(Cfg *cfg);
BOOL IsSameHost(HostSub *host, HostSub *host2);
inline BOOL IsSameAddrPort(HostSub *host, HostSub *host2) {
	return host->addr == host2->addr && host->portNo == host2->portNo ? TRUE : FALSE;
}
inline BOOL IsSameHostEx(HostSub *host, HostSub *host2) {
	return IsSameHost(host, host2) && IsSameAddrPort(host, host2) ? TRUE : FALSE;
}
void RectToWinPos(const RECT *rect, WINPOS *wpos);
Time_t Time(void);
const char *Ctime(SYSTEMTIME *st=NULL);
const char *Ctime(Time_t *t);
const WCHAR *CtimeW(time_t t=-1);
BOOL BrowseDirDlg(TWin *parentWin, const char *title, const char *defaultDir, char *buf,
	int bufsize, DWORD flags=BIF_RETURNONLYFSDIRS|BIF_SHAREABLE|BIF_BROWSEINCLUDEFILES|BIF_USENEWUI);
BOOL PathToFname(const char *org_path, char *target_fname);
void ForcePathToFname(const char *org_path, char *target_fname);
void ConvertShareMsgEscape(char *str);
BOOL IsSafePath(const char *fullpath, const char *fname);

BOOL GetLastErrorMsg(const char *msg=NULL, TWin *win=NULL);
BOOL GetSockErrorMsg(const char *msg=NULL, TWin *win=NULL);
//int MakePath(char *dest, const char *dir, const char *file);


char *separate_token(char *buf, char separetor, char **handle=NULL);
#define sep_tok separate_token
WCHAR *quote_tok(WCHAR *buf, WCHAR separetor, WCHAR **handle);
BOOL VerifyHash(const BYTE *data, int len, const char *orgHash);

char *LoadStrAsFilterU8(UINT id);
BOOL GetCurrentScreenSize(RECT *rect, HWND hRefWnd = NULL);

void GenRemoteKey(char *key);
int CALLBACK EditNoWordBreakProc(LPTSTR str, int cur, int len, int action);

enum MakeDateStrFlags { MDS_WITH_SEC=0x0001, MDS_WITH_DAYWEEK };
int MakeDateStr(time_t t, WCHAR *buf, DWORD flags=0);
int MakeDateStrEx(time_t t, WCHAR *buf, SYSTEMTIME *lt);

int get_linenum(const WCHAR *s);
int get_linenum_n(const WCHAR *s, int max_len);
ssize_t comma_int64(WCHAR *s, int64 val);
ssize_t comma_double(WCHAR *s, double val, int precision);
ssize_t comma_int64(char *s, int64 val);
ssize_t comma_double(char *s, double val, int precision);

BOOL GetPngDimension(WCHAR *fname, TSize *sz);
BOOL IsNetVolume(const char *path);
void TruncateMsg(char *msg, BOOL is_mbcs, int max_len);

#endif

