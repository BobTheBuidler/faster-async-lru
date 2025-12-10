#include <Python.h>

PyMODINIT_FUNC
PyInit__nocompile(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("faster_async_lru__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_faster_async_lru____nocompile");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "faster_async_lru__mypyc.init_faster_async_lru____nocompile");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit__nocompile(); }
