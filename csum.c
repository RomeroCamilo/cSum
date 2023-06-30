#include <Python3.97/Python.h>
#include <stdlib.h>

/* 
 * self points to the Module Object. args are the arguments 
 * that get passed into the python script later. 
 */

/*
 * cSum is the name of the function you will call when accessing the module in a Python file.
 */

/* 
 * TODO: Clean code up to have 3 base if statements ( 0 arguments, 1 argument, arbitrary arguments ).
 */

void error_check(int x){
     if( PyErr_Occurred()){
            //PyObject *ptype, *pvalue, *ptraceback;

            //PyErr_Fetch(&ptype, &pvalue, &ptraceback);

            printf("Error occurred on line %d", x);

            PyErr_PrintEx(0);

            PyErr_Clear(); /* Clears the error */
            //break;
        }
}

static PyObject* cSum( PyObject* self, PyObject* args ) {

    error_check(__LINE__);

    double sum = 0;
    
    Py_ssize_t amt_args = PySequence_Size( args ); /* Getting the amount of arguments user input */
    PyObject *elem;
    PyObject *word = PySequence_GetItem(args,0);
    size_t i;
    
    if(amt_args == 1){

        if(!PyArg_ParseTuple(args,"s", word)){ /* Checking for potential .txt */
            if(PyErr_Occurred()){
                PyErr_Clear();
            }
        }
        else{ /* If arg contains a string */
            printf("%s\n","a potential file.");
            printf("Amount of args: %lu\n",amt_args);
            //printf("%s\n",PyUnicode_AsUTF8(PySequence_GetItem(args,0))); /* Gets the name of txt, now use it to open the file and you're in */
            //char* file[] = PyUnicode_AsUTF8(PySequence_GetItem(args,0));
            return Py_BuildValue("d", 1.1);
        }
        
    }

    error_check(__LINE__);
    
    if (amt_args == 1) { 
        elem = PySequence_GetItem(args, 0);
        if (PySequence_Check(elem))
            return cSum(self, elem);
        if (PyNumber_Check(elem))
            return elem;
        
        //PyErr_SetString(PyExc_TypeError, "Invalid");
        if (PyErr_Occurred()){
            return NULL;
        } 
    }
    

    error_check(__LINE__);

    for (i = 0;  ; i++) { /* ERROR IS THAT IT GOES OUT OF BOUNDS (test with i < 3) */
    
        elem = PySequence_GetItem(args, i);

        //printf("%s\n",elem->ob_type->tp_name);

        if (elem == NULL || PyErr_Occurred()) { /* If an error occurred, clear it and break */
            
            PyErr_Clear();
            break;
        }

        sum += PyFloat_AsDouble(elem);
        
        if (PyErr_Occurred()){
            //PyErr_SetString(PyExc_TypeError, "Invalid case");
            return NULL;
        }

    }

    Py_DECREF( args ); /* Decrement reference count to release args tuple user has input. */ 
    
    return Py_BuildValue("d", sum);

}

static PyMethodDef mainMethods[] = {
        { "cSum",cSum,METH_VARARGS,"Calculate the sum of a list in C" }, 
        { NULL,NULL,0,NULL }
};

/* Module definition */
static struct PyModuleDef cgetSum = {
        PyModuleDef_HEAD_INIT,
        "cgetSum" , /* give module name here */
        "Python interface for calculating the sum of a list in C." , /* module docstring */
        -1 , /* Amount of memory needed to store the programs state */
        mainMethods
};

/* Gets executed when the Python program gets called by a script to import the module */
PyMODINIT_FUNC PyInit_cgetSum( void ){
        Py_Initialize();
        return PyModule_Create( &cgetSum );
}


