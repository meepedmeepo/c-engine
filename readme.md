## Compilation

cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
mv compile_commands.json ../compile_commands.json

This series of commands is also found in build.sh which will run
the program after the build completes.
