# HelloWorldConsole

## Set PATH environment (cpptestcli, cpptesttrace)
``` 
P=/opt/parasoft/cpptest_professional-2025.1.0-linux.x86_64
export PATH=$P:$P/bin:$PATH
```

## CMake build prepare
```
cmake -B build -S .
```

## Generate bdf file
```
cd build/
cpptesttrace make
```

## Create Eclipse workspace
```
mkdir ~/workspace1/
cpptestcli -data ~/workspace1/HelloWorldConsole -property bdf.import.compiler.family=gcc_13-64 -property bdf.import.c.compiler.exec=gcc -property bdf.import.cpp.compiler.exec=g++ -property bdf.import.linker.exec=g++ -bdf cpptestscan.bdf
```

## Generate Unit Tests
```
cpptestcli -data ~/workspace1/HelloWorldConsole -config "builtin://Generate Unit Tests" -report report1
```

## Set Qt compiler and linker options in .parasoft file
Append `-std=c++20 -I/opt/qt/6.8.2/include/ -I/opt/qt/6.8.2/include/QtWidgets -I/opt/qt/6.8.2/include/QtGui -I/opt/qt/6.8.2/include/QtCore/6.8.2/QtCore` to `compiler.options`

Append `-lQt6Widgets -lQt6Gui -lQt6Core` to `linker.options`

Edited file looks like:
```
cat ~/workspace1/HelloWorldConsole/build/.parasoft

/build//com.parasoft.xtest.checkers.api.cpp.options.compiler.command.c.linux.x86=gcc
/build//com.parasoft.xtest.checkers.api.cpp.options.compiler.command.cpp.linux.x86=g++
/build//com.parasoft.xtest.checkers.api.cpp.options.compiler.family.linux.x86=gcc_13-64
/build//com.parasoft.xtest.checkers.api.cpp.options.compiler.options.linux.x86=${cpptest\:original_options} -DPARASOFT_CPPTEST -std=c++20 -I/opt/qt/6.8.2/include/ -I/opt/qt/6.8.2/include/QtWidgets -I/opt/qt/6.8.2/include/QtGui -I/opt/qt/6.8.2/include/QtCore/6.8.2/QtCore
/build//com.parasoft.xtest.checkers.api.cpp.options.extractor.id=options_dir_extractor_id
/build//com.parasoft.xtest.checkers.api.cpp.options.linker.command.linux.x86=g++
/build//com.parasoft.xtest.checkers.api.cpp.options.linker.options.linux.x86=${cpptest\:original_options} -lQt6Widgets -lQt6Gui -lQt6Core
/build//com.parasoft.xtest.checkers.api.cpp.options.ode_auto_scan_mode=never
/build//com.parasoft.xtest.checkers.api.cpp.options.ode_options_dir=/home/dx/src/qt/HelloWorldConsole/build/cpptestscan.bdf
/build//com.parasoft.xtest.checkers.api.cpp.options.preference.store.version=1.1
project.path=/build
```

## Run Unit Tests
```
cpptestcli -data ~/workspace1/HelloWorldConsole -config "builtin://Run Unit Tests" -report report2
```

## View line coverage result.html
```
google-chrome report2/result.html
```

