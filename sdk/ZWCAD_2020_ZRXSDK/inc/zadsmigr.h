

#ifndef _zdsmigr_h
#define _zdsmigr_h 1

#define zds_malloc	zcad_malloc
#define zds_free	zcad_free
#define zds__msize	zcad__msize
#define zds_realloc zcad_realloc
#define zds_calloc	zcad_calloc
#define zds_strdup	zcad__strdup

#define	zds_getappname	zcedGetAppName
#define	zds_update	zcedUpdate
#define	zds_command	zcedCommand
#define	zds_cmd	zcedCmd
#define	zds_regfunc	zcedRegFunc
#define	zds_usrbrk	zcedUsrBrk
#define	zds_defun	zcedDefun
#define	zds_setfunhelp	zcedSetFunHelp
#define	zds_undef	zcedUndef
#define	zds_getfuncode	zcedGetFunCode
#define	zds_getargs	zcedGetArgs
#define	zds_retlist	zcedRetList
#define	zds_retval	zcedRetVal
#define	zds_retpoint	zcedRetPoint
#define	zds_retstr	zcedRetStr
#define	zds_retname	zcedRetName
#define	zds_retint	zcedRetInt
#define	zds_retreal	zcedRetReal
#define	zds_rett	zcedRetT
#define	zds_retnil	zcedRetNil
#define	zds_retvoid	zcedRetVoid
#define	zds_entsel	zcedEntSel
#define	zds_nentsel	zcedNEntSel
#define	zds_nentselp	zcedNEntSelP
#define	zds_ssget	zcedSSGet

#define	zds_ssgetfirst	zcedSSGetFirst
#define	zds_sssetfirst	zcedSSSetFirst

#define	zds_ssfree	zcedSSFree
#define	zds_sslength	zcedSSLength
#define	zds_ssadd	zcedSSAdd
#define	zds_ssdel	zcedSSDel
#define	zds_ssmemb	zcedSSMemb
#define	zds_ssname	zcedSSName
#define	zds_ssnamex	zcedSSNameX
#define	zds_ssGetKwordCallbackPtr	zcedSSGetKwordCallbackPtr
#define	zds_ssSetKwordCallbackPtr	zcedSSSetKwordCallbackPtr
#define	zds_ssGetOtherCallbackPtr	zcedSSGetOtherCallbackPtr
#define	zds_ssSetOtherCallbackPtr	zcedSSSetOtherCallbackPtr
#define	zds_setvar	zcedSetVar
#define	zds_initget	zcedInitGet
#define	zds_getsym	zcedGetSym
#define	zds_putsym	zcedPutSym
#define	zds_help	zcedHelp
#define	zds_fnsplit	zcedFNSplit
#define	zds_trans	zcedTrans
#define	zds_zrxloaded	zcedZrxLoaded
#define	zds_zrxload	zcedZrxLoad
#define	zds_zrxunload	zcedZrxUnload
#define	zds_invoke	zcedInvoke
#define	zds_getvar	zcedGetVar
#define	zds_findfile	zcedFindFile
#define	zds_agetenv	zcedGetEnv
#define	zds_asetenv	zcedSetEnv
#define	zds_getenv	zcedGetEnv
#define	zds_setenv	zcedSetEnv
#define	zds_agetcfg	zcedGetCfg
#define	zds_asetcfg	zcedSetCfg
#define	zds_getcfg	zcedGetCfg
#define	zds_setcfg	zcedSetCfg
#define	zds_getstring	zcedGetString
#define	zds_getstringb	zcedGetStringB
#define	zds_menucmd	zcedMenuCmd
#define	zds_prompt	zcedPrompt
#define	zds_alert	zcedAlert
#define	zds_getangle	zcedGetAngle
#define	zds_getcorner	zcedGetCorner
#define	zds_getdist	zcedGetDist
#define	zds_getorient	zcedGetOrient
#define	zds_getpoint	zcedGetPoint
#define	zds_getint	zcedGetInt
#define	zds_getkword	zcedGetKword
#define	zds_getreal	zcedGetReal
#define	zds_getinput	zcedGetInput
#define	zds_vports	zcedVports
#define	zds_textscr	zcedTextScr
#define	zds_graphscr	zcedGraphScr
#define	zds_textpage	zcedTextPage
#define	zds_redraw	zcedRedraw
#define	zds_osnap	zcedOsnap
#define	zds_grread	zcedGrRead
#define	zds_grtext	zcedGrText
#define	zds_grdraw	zcedGrDraw
#define	zds_grvecs	zcedGrVecs
#define	zds_xformss	zcedXformSS
#define	zds_draggen	zcedDragGen
#define	zds_setview	zcedSetView
#define	zds_getfiled	zcedGetFileD
#define	zds_textbox	zcedTextBox
#define	zds_tablet	zcedTablet
#define	zds_getcname	zcedGetCName

#define	zds_xdroom	zcdbXdRoom
#define	zds_xdsize	zcdbXdSize
#define	zds_regen	zcedRegen

#ifdef __STDC__
#define zds_name_set(from, to)  (memcpy(to, from, sizeof(zds_name)))
#define zds_point_set(from,to)  (memcpy(to, from, sizeof(zds_point)))
#else
#define zds_name_set(from, to)  (*(to)= *(from), (to)[1]=(from)[1])
#define zds_point_set(from, to) (*(to)= *(from), (to)[1]=(from)[1], (to)[2]=(from)[2])
#endif  

#define zds_name_clear(name)    name[0] = name[1] = 0
#define zds_name_nil(name)      (name[0] == 0 && name[1] == 0)
#define zds_name_equal(name1, name2)  (name1[0]==name2[0] \
                                       && name1[1]==name2[1])

#define	zds_entdel	zcdbEntDel
#define	zds_entgetx	zcdbEntGetX
#define	zds_entget	zcdbEntGet
#define	zds_entlast	zcdbEntLast
#define	zds_entnext	zcdbEntNext
#define	zds_entupd	zcdbEntUpd
#define	zds_entmod	zcdbEntMod
#define	zds_entmake	zcdbEntMake
#define	zds_entmakex	zcdbEntMakeX
#define	zds_tblnext	zcdbTblNext
#define	zds_tblsearch	zcdbTblSearch
#define	zds_namedobjdict	zcdbNamedObjDict
#define	zds_dictsearch	zcdbDictSearch
#define	zds_dictnext	zcdbDictNext
#define	zds_dictrename	zcdbDictRename
#define	zds_dictremove	zcdbDictRemove
#define	zds_dictadd	zcdbDictAdd
#define	zds_tblobjname	zcdbTblObjName
#define	zds_handent	zcdbHandEnt
#define	zds_inters	zcdbInters
#define	zds_snvalid	zcdbSNValid
#define	zds_xstrsave	zcdbXStrSave
#define	zds_xstrcase	zcdbXStrCase
#define	zds_regapp	zcdbRegApp
#define	zds_fail	zcdbFail
#define	zds_angtos	zcdbAngToS
#define	zds_rangtos	zcdbRawAngToS
#define	zds_rtos	zcdbRToS
#define	zds_angtof	zcdbAngToF
#define	zds_rangtof	zcdbRawAngToF
#define	zds_distof	zcdbDisToF

#define zds_regappx(appname, xsave12)   zcdbRegApp(appname)

#define	zds_printf	zcutPrintf
#define	zds_cvunit	zcutCvUnit
#define	zds_wcmatch	zcutWcMatch
#define	zds_angle	zcutAngle
#define	zds_distance	zcutDistance
#define	zds_polar	zcutPolar
#define	zds_isalpha	zcutIsAlpha
#define	zds_isupper	zcutIsUpper
#define	zds_islower	zcutIsLower
#define	zds_isdigit	zcutIsDigit
#define	zds_isxdigit	zcutIsXDigit
#define	zds_isspace	zcutIsSpace
#define	zds_ispunct	zcutIsPunct
#define	zds_isalnum	zcutIsAlNum
#define	zds_isprint	zcutIsPrint
#define	zds_isgraph	zcutIsGraph
#define	zds_iscntrl	zcutIsCntrl
#define	zds_toupper	zcutToUpper
#define	zds_tolower	zcutToLower
#define	zds_newrb	zcutNewRb
#define	zds_relrb	zcutRelRb
#define	zds_buildlist	zcutBuildList

#endif 
