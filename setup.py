# PURPOSE OF FILE: COMPILES AND LINKS TO THE RIGHT LIBRARIES IN THE 'Python.h' file. #

from distutils.core import setup, Extension

sum_module = Extension('cgetSum', 
                       sources = ['csum.c'],
                       extra_compile_args = ["-O0", "-g"]
                       ) 

setup (name = 'SumExtension',
       version = '1.1',
       description= 'This package returns the sum of an array in C.',
       ext_modules = [sum_module],
)
