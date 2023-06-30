This repo contains a C extension module 'cGetSum' which can be utilized in Python, which allows Python to have access to functions with C/C++ speed and high performance.

This module was built utilizing the PYTHON/C API : https://docs.python.org/3/c-api/index.html

#HOW TO COMPILE on Ubuntu Linux:

sudo apt-get install python3-dev

in the terminal at directory of code, type: python3 setup.py build

a folder named build should be created, that will contain another folder starting with lib.linux with a .so file inside.

create a test.py file.

import the name of that .so only for example, 'import cgetSum'

you will now be able to run the file python file 'python3 test.py'

code is complete so you can look at how it works.

EXAMPLE: inside of test.py which should be inside build/lib.linux.... directory:

import cgetSum

print(cgetSum.cSum([1,2,3]))
