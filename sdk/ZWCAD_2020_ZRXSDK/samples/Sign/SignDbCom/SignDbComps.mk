
SignDbComps.dll: dlldata.obj SignDbCom_p.obj SignDbCom_i.obj
	link /dll /out:SignDbComps.dll /def:SignDbComps.def /entry:DllMain dlldata.obj SignDbCom_p.obj SignDbCom_i.obj \
		kernel32.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
.c.obj:
	cl /c /Ox /DREGISTER_PROXY_DLL \
		$<

clean:
	@del SignDbComps.dll
	@del SignDbComps.lib
	@del SignDbComps.exp
	@del dlldata.obj
	@del SignDbCom_p.obj
	@del SignDbCom_i.obj
