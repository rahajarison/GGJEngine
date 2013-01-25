FILE(REMOVE_RECURSE
  "CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj"
  "HelloWorld.pdb"
  "HelloWorld.exe"
  "HelloWorld.exe.manifest"
  "libHelloWorld.dll.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/HelloWorld.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
