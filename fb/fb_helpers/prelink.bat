@echo on
pushd %1
for %%f in (Cadent.infra.gc.dll, Cadent.infra.gc.lib, Cadent.infra.threading.dll, Cadent.infra.threading.lib) do xcopy /y "%%f" %2
popd