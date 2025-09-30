cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
mv compile_commands.json ../compile_commands.json
make
./c_engine
