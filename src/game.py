import ctypes

testlib = ctypes.cdll.LoadLibrary(".libs/libpygame.so")
print testlib.help
    
