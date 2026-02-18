#ifndef DIFFCHECK_PLACEHOLDER
#define DIFFCHECK_PLACEHOLDER 0
#endif
#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "pythonsupport.c"
#include "__native.h"
#include "__native_internal.h"

PyObject *CPyDef___mypyc___3_CacheItem_setup(PyObject *cpy_r_type);
PyObject *CPyDef__CacheItem(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);

static PyObject *
_CacheItem_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__CacheItem) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc___3_CacheItem_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
_CacheItem_traverse(async_lru____CacheItemObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_task);
    Py_VISIT(self->_later_call);
    if (CPyTagged_CheckLong(self->_waiters)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_waiters));
    }
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
_CacheItem_clear(async_lru____CacheItemObject *self)
{
    Py_CLEAR(self->_task);
    Py_CLEAR(self->_later_call);
    if (CPyTagged_CheckLong(self->_waiters)) {
        CPyTagged __tmp = self->_waiters;
        self->_waiters = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
_CacheItem_dealloc(async_lru____CacheItemObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _CacheItem_dealloc)
    _CacheItem_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem _CacheItem_vtable[1];
static bool
CPyDef__CacheItem_trait_vtable_setup(void)
{
    CPyVTableItem _CacheItem_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__CacheItem___cancel,
    };
    memcpy(_CacheItem_vtable, _CacheItem_vtable_scratch, sizeof(_CacheItem_vtable));
    return 1;
}

static PyObject *
_CacheItem_get_task(async_lru____CacheItemObject *self, void *closure);
static int
_CacheItem_set_task(async_lru____CacheItemObject *self, PyObject *value, void *closure);
static PyObject *
_CacheItem_get_later_call(async_lru____CacheItemObject *self, void *closure);
static int
_CacheItem_set_later_call(async_lru____CacheItemObject *self, PyObject *value, void *closure);
static PyObject *
_CacheItem_get_waiters(async_lru____CacheItemObject *self, void *closure);
static int
_CacheItem_set_waiters(async_lru____CacheItemObject *self, PyObject *value, void *closure);

static PyGetSetDef _CacheItem_getseters[] = {
    {"task",
     (getter)_CacheItem_get_task, (setter)_CacheItem_set_task,
     NULL, NULL},
    {"later_call",
     (getter)_CacheItem_get_later_call, (setter)_CacheItem_set_later_call,
     NULL, NULL},
    {"waiters",
     (getter)_CacheItem_get_waiters, (setter)_CacheItem_set_waiters,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef _CacheItem_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc___3_CacheItem_setup, METH_O, NULL},
    {"cancel",
     (PyCFunction)CPyPy__CacheItem___cancel,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("cancel($self)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__CacheItem_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_CacheItem",
    .tp_new = _CacheItem_new,
    .tp_dealloc = (destructor)_CacheItem_dealloc,
    .tp_traverse = (traverseproc)_CacheItem_traverse,
    .tp_clear = (inquiry)_CacheItem_clear,
    .tp_getset = _CacheItem_getseters,
    .tp_methods = _CacheItem_methods,
    .tp_basicsize = sizeof(async_lru____CacheItemObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("_CacheItem()\n--\n\n"),
};
static PyTypeObject *CPyType__CacheItem_template = &CPyType__CacheItem_template_;

PyObject *CPyDef___mypyc___3_CacheItem_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    async_lru____CacheItemObject *self;
    self = (async_lru____CacheItemObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _CacheItem_vtable;
    self->_waiters = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef__CacheItem(PyObject *cpy_r_args, PyObject *cpy_r_kwargs)
{
    PyObject *self = CPyDef___mypyc___3_CacheItem_setup((PyObject *)CPyType__CacheItem);
    if (self == NULL)
        return NULL;
    int res = CPyType__CacheItem->tp_init(self, cpy_r_args, cpy_r_kwargs);
    if (res < 0) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
_CacheItem_get_task(async_lru____CacheItemObject *self, void *closure)
{
    if (unlikely(self->_task == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'task' of '_CacheItem' undefined");
        return NULL;
    }
    CPy_INCREF(self->_task);
    PyObject *retval = self->_task;
    return retval;
}

static int
_CacheItem_set_task(async_lru____CacheItemObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_CacheItem' object attribute 'task' cannot be deleted");
        return -1;
    }
    if (self->_task != NULL) {
        CPy_DECREF(self->_task);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_task = tmp;
    return 0;
}

static PyObject *
_CacheItem_get_later_call(async_lru____CacheItemObject *self, void *closure)
{
    if (unlikely(self->_later_call == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'later_call' of '_CacheItem' undefined");
        return NULL;
    }
    CPy_INCREF(self->_later_call);
    PyObject *retval = self->_later_call;
    return retval;
}

static int
_CacheItem_set_later_call(async_lru____CacheItemObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_CacheItem' object attribute 'later_call' cannot be deleted");
        return -1;
    }
    if (self->_later_call != NULL) {
        CPy_DECREF(self->_later_call);
    }
    PyObject *tmp;
    tmp = value;
    if (tmp != NULL) goto __LL1;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL1;
    CPy_TypeError("object or None", value); 
    tmp = NULL;
__LL1: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_later_call = tmp;
    return 0;
}

static PyObject *
_CacheItem_get_waiters(async_lru____CacheItemObject *self, void *closure)
{
    if (unlikely(self->_waiters == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'waiters' of '_CacheItem' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_waiters);
    PyObject *retval = CPyTagged_StealAsObject(self->_waiters);
    return retval;
}

static int
_CacheItem_set_waiters(async_lru____CacheItemObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_CacheItem' object attribute 'waiters' cannot be deleted");
        return -1;
    }
    if (self->_waiters != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_waiters);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_waiters = tmp;
    return 0;
}

static PyObject *CPyDunder___get___LRUCacheWrapper(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef__LRUCacheWrapper_____get__(self, instance, owner);
}
static int
_LRUCacheWrapper_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
PyObject *CPyDef___mypyc___3_LRUCacheWrapper_setup(PyObject *cpy_r_type);
PyObject *CPyDef__LRUCacheWrapper(PyObject *cpy_r_fn, PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl);

static PyObject *
_LRUCacheWrapper_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__LRUCacheWrapper) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc___3_LRUCacheWrapper_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy__LRUCacheWrapper_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
_LRUCacheWrapper_traverse(async_lru____LRUCacheWrapperObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___module__);
    Py_VISIT(self->___name__);
    Py_VISIT(self->___qualname__);
    Py_VISIT(self->___doc__);
    Py_VISIT(self->___annotations__);
    Py_VISIT(self->___wrapped__);
    Py_VISIT(self->___maxsize);
    Py_VISIT(self->___ttl);
    Py_VISIT(self->___cache);
    if (CPyTagged_CheckLong(self->___hits)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___hits));
    }
    if (CPyTagged_CheckLong(self->___misses)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___misses));
    }
    Py_VISIT(self->___first_loop);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
_LRUCacheWrapper_clear(async_lru____LRUCacheWrapperObject *self)
{
    Py_CLEAR(self->___module__);
    Py_CLEAR(self->___name__);
    Py_CLEAR(self->___qualname__);
    Py_CLEAR(self->___doc__);
    Py_CLEAR(self->___annotations__);
    Py_CLEAR(self->___wrapped__);
    Py_CLEAR(self->___maxsize);
    Py_CLEAR(self->___ttl);
    Py_CLEAR(self->___cache);
    if (CPyTagged_CheckLong(self->___hits)) {
        CPyTagged __tmp = self->___hits;
        self->___hits = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->___misses)) {
        CPyTagged __tmp = self->___misses;
        self->___misses = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->___first_loop);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
_LRUCacheWrapper_dealloc(async_lru____LRUCacheWrapperObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _LRUCacheWrapper_dealloc)
    _LRUCacheWrapper_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem _LRUCacheWrapper_vtable[14];
static bool
CPyDef__LRUCacheWrapper_trait_vtable_setup(void)
{
    CPyVTableItem _LRUCacheWrapper_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__LRUCacheWrapper_____init__,
        (CPyVTableItem)CPyDef__LRUCacheWrapper_____tasks,
        (CPyVTableItem)CPyDef__LRUCacheWrapper____check_loop,
        (CPyVTableItem)CPyDef__LRUCacheWrapper___cache_invalidate,
        (CPyVTableItem)CPyDef__LRUCacheWrapper___cache_clear,
        (CPyVTableItem)CPyDef__LRUCacheWrapper___cache_close,
        (CPyVTableItem)CPyDef__LRUCacheWrapper___cache_info,
        (CPyVTableItem)CPyDef__LRUCacheWrapper___cache_parameters,
        (CPyVTableItem)CPyDef__LRUCacheWrapper____cache_hit,
        (CPyVTableItem)CPyDef__LRUCacheWrapper____cache_miss,
        (CPyVTableItem)CPyDef__LRUCacheWrapper____task_done_callback,
        (CPyVTableItem)CPyDef__LRUCacheWrapper____shield_and_handle_cancelled_error,
        (CPyVTableItem)CPyDef__LRUCacheWrapper_____call__,
        (CPyVTableItem)CPyDef__LRUCacheWrapper_____get__,
    };
    memcpy(_LRUCacheWrapper_vtable, _LRUCacheWrapper_vtable_scratch, sizeof(_LRUCacheWrapper_vtable));
    return 1;
}

static PyObject *
_LRUCacheWrapper_get___3_module__(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_module__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_name__(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_name__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_qualname__(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_qualname__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_doc__(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_doc__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_annotations__(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_annotations__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_wrapped__(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_wrapped__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_maxsize(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_maxsize(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_typed(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_typed(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_ttl(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_ttl(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_cache(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_cache(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_closed(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_closed(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_hits(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_hits(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_misses(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_misses(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_first_loop(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_first_loop(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_tasks(async_lru____LRUCacheWrapperObject *self, void *closure);

static PyGetSetDef _LRUCacheWrapper_getseters[] = {
    {"__module__",
     (getter)_LRUCacheWrapper_get___3_module__, (setter)_LRUCacheWrapper_set___3_module__,
     NULL, NULL},
    {"__name__",
     (getter)_LRUCacheWrapper_get___3_name__, (setter)_LRUCacheWrapper_set___3_name__,
     NULL, NULL},
    {"__qualname__",
     (getter)_LRUCacheWrapper_get___3_qualname__, (setter)_LRUCacheWrapper_set___3_qualname__,
     NULL, NULL},
    {"__doc__",
     (getter)_LRUCacheWrapper_get___3_doc__, (setter)_LRUCacheWrapper_set___3_doc__,
     NULL, NULL},
    {"__annotations__",
     (getter)_LRUCacheWrapper_get___3_annotations__, (setter)_LRUCacheWrapper_set___3_annotations__,
     NULL, NULL},
    {"__wrapped__",
     (getter)_LRUCacheWrapper_get___3_wrapped__, (setter)_LRUCacheWrapper_set___3_wrapped__,
     NULL, NULL},
    {"__maxsize",
     (getter)_LRUCacheWrapper_get___3_maxsize, (setter)_LRUCacheWrapper_set___3_maxsize,
     NULL, NULL},
    {"__typed",
     (getter)_LRUCacheWrapper_get___3_typed, (setter)_LRUCacheWrapper_set___3_typed,
     NULL, NULL},
    {"__ttl",
     (getter)_LRUCacheWrapper_get___3_ttl, (setter)_LRUCacheWrapper_set___3_ttl,
     NULL, NULL},
    {"__cache",
     (getter)_LRUCacheWrapper_get___3_cache, (setter)_LRUCacheWrapper_set___3_cache,
     NULL, NULL},
    {"__closed",
     (getter)_LRUCacheWrapper_get___3_closed, (setter)_LRUCacheWrapper_set___3_closed,
     NULL, NULL},
    {"__hits",
     (getter)_LRUCacheWrapper_get___3_hits, (setter)_LRUCacheWrapper_set___3_hits,
     NULL, NULL},
    {"__misses",
     (getter)_LRUCacheWrapper_get___3_misses, (setter)_LRUCacheWrapper_set___3_misses,
     NULL, NULL},
    {"__first_loop",
     (getter)_LRUCacheWrapper_get___3_first_loop, (setter)_LRUCacheWrapper_set___3_first_loop,
     NULL, NULL},
    {"__tasks",
     (getter)_LRUCacheWrapper_get___3_tasks,
    NULL, NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef _LRUCacheWrapper_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc___3_LRUCacheWrapper_setup, METH_O, NULL},
    {"__init__",
     (PyCFunction)CPyPy__LRUCacheWrapper_____init__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__init__($self, fn, maxsize, typed, ttl)\n--\n\n")},
    {"_check_loop",
     (PyCFunction)CPyPy__LRUCacheWrapper____check_loop,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_check_loop($self, loop)\n--\n\n")},
    {"cache_invalidate",
     (PyCFunction)CPyPy__LRUCacheWrapper___cache_invalidate,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("cache_invalidate($self, /, *args, **kwargs)\n--\n\n")},
    {"cache_clear",
     (PyCFunction)CPyPy__LRUCacheWrapper___cache_clear,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("cache_clear($self)\n--\n\n")},
    {"cache_close",
     (PyCFunction)CPyPy__LRUCacheWrapper___cache_close,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("cache_close($self, *, wait=False)\n--\n\n")},
    {"cache_info",
     (PyCFunction)CPyPy__LRUCacheWrapper___cache_info,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("cache_info($self)\n--\n\n")},
    {"cache_parameters",
     (PyCFunction)CPyPy__LRUCacheWrapper___cache_parameters,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("cache_parameters($self)\n--\n\n")},
    {"_cache_hit",
     (PyCFunction)CPyPy__LRUCacheWrapper____cache_hit,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_cache_hit($self, key)\n--\n\n")},
    {"_cache_miss",
     (PyCFunction)CPyPy__LRUCacheWrapper____cache_miss,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_cache_miss($self, key)\n--\n\n")},
    {"_task_done_callback",
     (PyCFunction)CPyPy__LRUCacheWrapper____task_done_callback,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_task_done_callback($self, key, task)\n--\n\n")},
    {"_shield_and_handle_cancelled_error",
     (PyCFunction)CPyPy__LRUCacheWrapper____shield_and_handle_cancelled_error,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_shield_and_handle_cancelled_error($self, cache_item, key)\n--\n\n")},
    {"__call__",
     (PyCFunction)CPyPy__LRUCacheWrapper_____call__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__call__($self, /, *fn_args, **fn_kwargs)\n--\n\n")},
    {"__get__",
     (PyCFunction)CPyPy__LRUCacheWrapper_____get__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__get__($self, instance, owner)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__LRUCacheWrapper_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_LRUCacheWrapper",
    .tp_new = _LRUCacheWrapper_new,
    .tp_dealloc = (destructor)_LRUCacheWrapper_dealloc,
    .tp_traverse = (traverseproc)_LRUCacheWrapper_traverse,
    .tp_clear = (inquiry)_LRUCacheWrapper_clear,
    .tp_getset = _LRUCacheWrapper_getseters,
    .tp_methods = _LRUCacheWrapper_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get___LRUCacheWrapper,
    .tp_init = _LRUCacheWrapper_init,
    .tp_basicsize = sizeof(async_lru____LRUCacheWrapperObject),
    .tp_vectorcall_offset = offsetof(async_lru____LRUCacheWrapperObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("_LRUCacheWrapper(fn, maxsize, typed, ttl)\n--\n\n"),
};
static PyTypeObject *CPyType__LRUCacheWrapper_template = &CPyType__LRUCacheWrapper_template_;

PyObject *CPyDef___mypyc___3_LRUCacheWrapper_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    async_lru____LRUCacheWrapperObject *self;
    self = (async_lru____LRUCacheWrapperObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _LRUCacheWrapper_vtable;
    self->vectorcall = CPyPy__LRUCacheWrapper_____call__;
    self->___typed = 2;
    self->___closed = 2;
    self->___hits = CPY_INT_TAG;
    self->___misses = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef__LRUCacheWrapper(PyObject *cpy_r_fn, PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl)
{
    PyObject *self = CPyDef___mypyc___3_LRUCacheWrapper_setup((PyObject *)CPyType__LRUCacheWrapper);
    if (self == NULL)
        return NULL;
    char res = CPyDef__LRUCacheWrapper_____init__(self, cpy_r_fn, cpy_r_maxsize, cpy_r_typed, cpy_r_ttl);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
_LRUCacheWrapper_get___3_module__(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___module__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__module__' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPy_INCREF(self->___module__);
    PyObject *retval = self->___module__;
    return retval;
}

static int
_LRUCacheWrapper_set___3_module__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__module__' cannot be deleted");
        return -1;
    }
    if (self->___module__ != NULL) {
        CPy_DECREF(self->___module__);
    }
    PyObject *tmp;
    if (likely(PyUnicode_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("str", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___module__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_name__(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___name__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__name__' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPy_INCREF(self->___name__);
    PyObject *retval = self->___name__;
    return retval;
}

static int
_LRUCacheWrapper_set___3_name__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__name__' cannot be deleted");
        return -1;
    }
    if (self->___name__ != NULL) {
        CPy_DECREF(self->___name__);
    }
    PyObject *tmp;
    if (likely(PyUnicode_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("str", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___name__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_qualname__(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___qualname__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__qualname__' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPy_INCREF(self->___qualname__);
    PyObject *retval = self->___qualname__;
    return retval;
}

static int
_LRUCacheWrapper_set___3_qualname__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__qualname__' cannot be deleted");
        return -1;
    }
    if (self->___qualname__ != NULL) {
        CPy_DECREF(self->___qualname__);
    }
    PyObject *tmp;
    if (likely(PyUnicode_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("str", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___qualname__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_doc__(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___doc__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__doc__' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPy_INCREF(self->___doc__);
    PyObject *retval = self->___doc__;
    return retval;
}

static int
_LRUCacheWrapper_set___3_doc__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__doc__' cannot be deleted");
        return -1;
    }
    if (self->___doc__ != NULL) {
        CPy_DECREF(self->___doc__);
    }
    PyObject *tmp;
    if (PyUnicode_Check(value))
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL2;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL2;
    CPy_TypeError("str or None", value); 
    tmp = NULL;
__LL2: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___doc__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_annotations__(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___annotations__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__annotations__' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPy_INCREF(self->___annotations__);
    PyObject *retval = self->___annotations__;
    return retval;
}

static int
_LRUCacheWrapper_set___3_annotations__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__annotations__' cannot be deleted");
        return -1;
    }
    if (self->___annotations__ != NULL) {
        CPy_DECREF(self->___annotations__);
    }
    PyObject *tmp;
    if (likely(PyDict_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("dict", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___annotations__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_wrapped__(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___wrapped__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__wrapped__' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPy_INCREF(self->___wrapped__);
    PyObject *retval = self->___wrapped__;
    return retval;
}

static int
_LRUCacheWrapper_set___3_wrapped__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__wrapped__' cannot be deleted");
        return -1;
    }
    if (self->___wrapped__ != NULL) {
        CPy_DECREF(self->___wrapped__);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->___wrapped__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_maxsize(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___maxsize == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__maxsize' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPy_INCREF(self->___maxsize);
    PyObject *retval = self->___maxsize;
    return retval;
}

static int
_LRUCacheWrapper_set___3_maxsize(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__maxsize' cannot be deleted");
        return -1;
    }
    if (self->___maxsize != NULL) {
        CPy_DECREF(self->___maxsize);
    }
    PyObject *tmp;
    if (PyLong_Check(value))
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL3;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL3;
    CPy_TypeError("int or None", value); 
    tmp = NULL;
__LL3: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___maxsize = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_typed(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___typed == 2)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__typed' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    PyObject *retval = self->___typed ? Py_True : Py_False;
    CPy_INCREF(retval);
    return retval;
}

static int
_LRUCacheWrapper_set___3_typed(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__typed' cannot be deleted");
        return -1;
    }
    char tmp;
    if (unlikely(!PyBool_Check(value))) {
        CPy_TypeError("bool", value); return -1;
    } else
        tmp = value == Py_True;
    self->___typed = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_ttl(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___ttl == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__ttl' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPy_INCREF(self->___ttl);
    PyObject *retval = self->___ttl;
    return retval;
}

static int
_LRUCacheWrapper_set___3_ttl(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__ttl' cannot be deleted");
        return -1;
    }
    if (self->___ttl != NULL) {
        CPy_DECREF(self->___ttl);
    }
    PyObject *tmp;
    if (CPyFloat_Check(value))
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL4;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL4;
    CPy_TypeError("float or None", value); 
    tmp = NULL;
__LL4: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___ttl = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_cache(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___cache == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__cache' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPy_INCREF(self->___cache);
    PyObject *retval = self->___cache;
    return retval;
}

static int
_LRUCacheWrapper_set___3_cache(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__cache' cannot be deleted");
        return -1;
    }
    if (self->___cache != NULL) {
        CPy_DECREF(self->___cache);
    }
    PyObject *tmp;
    if (likely(PyDict_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("dict", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___cache = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_closed(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___closed == 2)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__closed' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    PyObject *retval = self->___closed ? Py_True : Py_False;
    CPy_INCREF(retval);
    return retval;
}

static int
_LRUCacheWrapper_set___3_closed(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__closed' cannot be deleted");
        return -1;
    }
    char tmp;
    if (unlikely(!PyBool_Check(value))) {
        CPy_TypeError("bool", value); return -1;
    } else
        tmp = value == Py_True;
    self->___closed = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_hits(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___hits == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__hits' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->___hits);
    PyObject *retval = CPyTagged_StealAsObject(self->___hits);
    return retval;
}

static int
_LRUCacheWrapper_set___3_hits(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__hits' cannot be deleted");
        return -1;
    }
    if (self->___hits != CPY_INT_TAG) {
        CPyTagged_DECREF(self->___hits);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->___hits = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_misses(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___misses == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__misses' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->___misses);
    PyObject *retval = CPyTagged_StealAsObject(self->___misses);
    return retval;
}

static int
_LRUCacheWrapper_set___3_misses(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__misses' cannot be deleted");
        return -1;
    }
    if (self->___misses != CPY_INT_TAG) {
        CPyTagged_DECREF(self->___misses);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->___misses = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_first_loop(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___first_loop == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__first_loop' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPy_INCREF(self->___first_loop);
    PyObject *retval = self->___first_loop;
    return retval;
}

static int
_LRUCacheWrapper_set___3_first_loop(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__first_loop' cannot be deleted");
        return -1;
    }
    if (self->___first_loop != NULL) {
        CPy_DECREF(self->___first_loop);
    }
    PyObject *tmp;
    tmp = value;
    if (tmp != NULL) goto __LL5;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL5;
    CPy_TypeError("object or None", value); 
    tmp = NULL;
__LL5: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___first_loop = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_tasks(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    return CPyDef__LRUCacheWrapper_____tasks((PyObject *) self);
}

static int
_LRUCacheWrapperInstanceMethod_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
PyObject *CPyDef___mypyc___3_LRUCacheWrapperInstanceMethod_setup(PyObject *cpy_r_type);
PyObject *CPyDef__LRUCacheWrapperInstanceMethod(PyObject *cpy_r_wrapper, PyObject *cpy_r_instance);

static PyObject *
_LRUCacheWrapperInstanceMethod_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__LRUCacheWrapperInstanceMethod) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc___3_LRUCacheWrapperInstanceMethod_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy__LRUCacheWrapperInstanceMethod_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
_LRUCacheWrapperInstanceMethod_traverse(async_lru____LRUCacheWrapperInstanceMethodObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___module__);
    Py_VISIT(self->___name__);
    Py_VISIT(self->___qualname__);
    Py_VISIT(self->___doc__);
    Py_VISIT(self->___annotations__);
    Py_VISIT(self->___wrapped__);
    Py_VISIT(self->___instance);
    Py_VISIT(self->___wrapper);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
_LRUCacheWrapperInstanceMethod_clear(async_lru____LRUCacheWrapperInstanceMethodObject *self)
{
    Py_CLEAR(self->___module__);
    Py_CLEAR(self->___name__);
    Py_CLEAR(self->___qualname__);
    Py_CLEAR(self->___doc__);
    Py_CLEAR(self->___annotations__);
    Py_CLEAR(self->___wrapped__);
    Py_CLEAR(self->___instance);
    Py_CLEAR(self->___wrapper);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
_LRUCacheWrapperInstanceMethod_dealloc(async_lru____LRUCacheWrapperInstanceMethodObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _LRUCacheWrapperInstanceMethod_dealloc)
    _LRUCacheWrapperInstanceMethod_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem _LRUCacheWrapperInstanceMethod_vtable[7];
static bool
CPyDef__LRUCacheWrapperInstanceMethod_trait_vtable_setup(void)
{
    CPyVTableItem _LRUCacheWrapperInstanceMethod_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__LRUCacheWrapperInstanceMethod_____init__,
        (CPyVTableItem)CPyDef__LRUCacheWrapperInstanceMethod___cache_invalidate,
        (CPyVTableItem)CPyDef__LRUCacheWrapperInstanceMethod___cache_clear,
        (CPyVTableItem)CPyDef__LRUCacheWrapperInstanceMethod___cache_close,
        (CPyVTableItem)CPyDef__LRUCacheWrapperInstanceMethod___cache_info,
        (CPyVTableItem)CPyDef__LRUCacheWrapperInstanceMethod___cache_parameters,
        (CPyVTableItem)CPyDef__LRUCacheWrapperInstanceMethod_____call__,
    };
    memcpy(_LRUCacheWrapperInstanceMethod_vtable, _LRUCacheWrapperInstanceMethod_vtable_scratch, sizeof(_LRUCacheWrapperInstanceMethod_vtable));
    return 1;
}

static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_module__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_module__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_name__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_name__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_qualname__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_qualname__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_doc__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_doc__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_annotations__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_annotations__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_wrapped__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_wrapped__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_instance(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_instance(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_wrapper(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_wrapper(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);

static PyGetSetDef _LRUCacheWrapperInstanceMethod_getseters[] = {
    {"__module__",
     (getter)_LRUCacheWrapperInstanceMethod_get___3_module__, (setter)_LRUCacheWrapperInstanceMethod_set___3_module__,
     NULL, NULL},
    {"__name__",
     (getter)_LRUCacheWrapperInstanceMethod_get___3_name__, (setter)_LRUCacheWrapperInstanceMethod_set___3_name__,
     NULL, NULL},
    {"__qualname__",
     (getter)_LRUCacheWrapperInstanceMethod_get___3_qualname__, (setter)_LRUCacheWrapperInstanceMethod_set___3_qualname__,
     NULL, NULL},
    {"__doc__",
     (getter)_LRUCacheWrapperInstanceMethod_get___3_doc__, (setter)_LRUCacheWrapperInstanceMethod_set___3_doc__,
     NULL, NULL},
    {"__annotations__",
     (getter)_LRUCacheWrapperInstanceMethod_get___3_annotations__, (setter)_LRUCacheWrapperInstanceMethod_set___3_annotations__,
     NULL, NULL},
    {"__wrapped__",
     (getter)_LRUCacheWrapperInstanceMethod_get___3_wrapped__, (setter)_LRUCacheWrapperInstanceMethod_set___3_wrapped__,
     NULL, NULL},
    {"__instance",
     (getter)_LRUCacheWrapperInstanceMethod_get___3_instance, (setter)_LRUCacheWrapperInstanceMethod_set___3_instance,
     NULL, NULL},
    {"__wrapper",
     (getter)_LRUCacheWrapperInstanceMethod_get___3_wrapper, (setter)_LRUCacheWrapperInstanceMethod_set___3_wrapper,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef _LRUCacheWrapperInstanceMethod_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc___3_LRUCacheWrapperInstanceMethod_setup, METH_O, NULL},
    {"__init__",
     (PyCFunction)CPyPy__LRUCacheWrapperInstanceMethod_____init__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__init__($self, wrapper, instance)\n--\n\n")},
    {"cache_invalidate",
     (PyCFunction)CPyPy__LRUCacheWrapperInstanceMethod___cache_invalidate,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("cache_invalidate($self, /, *args, **kwargs)\n--\n\n")},
    {"cache_clear",
     (PyCFunction)CPyPy__LRUCacheWrapperInstanceMethod___cache_clear,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("cache_clear($self)\n--\n\n")},
    {"cache_close",
     (PyCFunction)CPyPy__LRUCacheWrapperInstanceMethod___cache_close,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("cache_close($self, *, cancel=False, return_exceptions=True)\n--\n\n")},
    {"cache_info",
     (PyCFunction)CPyPy__LRUCacheWrapperInstanceMethod___cache_info,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("cache_info($self)\n--\n\n")},
    {"cache_parameters",
     (PyCFunction)CPyPy__LRUCacheWrapperInstanceMethod___cache_parameters,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("cache_parameters($self)\n--\n\n")},
    {"__call__",
     (PyCFunction)CPyPy__LRUCacheWrapperInstanceMethod_____call__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__call__($self, /, *fn_args, **fn_kwargs)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__LRUCacheWrapperInstanceMethod_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_LRUCacheWrapperInstanceMethod",
    .tp_new = _LRUCacheWrapperInstanceMethod_new,
    .tp_dealloc = (destructor)_LRUCacheWrapperInstanceMethod_dealloc,
    .tp_traverse = (traverseproc)_LRUCacheWrapperInstanceMethod_traverse,
    .tp_clear = (inquiry)_LRUCacheWrapperInstanceMethod_clear,
    .tp_getset = _LRUCacheWrapperInstanceMethod_getseters,
    .tp_methods = _LRUCacheWrapperInstanceMethod_methods,
    .tp_call = PyVectorcall_Call,
    .tp_init = _LRUCacheWrapperInstanceMethod_init,
    .tp_basicsize = sizeof(async_lru____LRUCacheWrapperInstanceMethodObject),
    .tp_vectorcall_offset = offsetof(async_lru____LRUCacheWrapperInstanceMethodObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("_LRUCacheWrapperInstanceMethod(wrapper, instance)\n--\n\n"),
};
static PyTypeObject *CPyType__LRUCacheWrapperInstanceMethod_template = &CPyType__LRUCacheWrapperInstanceMethod_template_;

PyObject *CPyDef___mypyc___3_LRUCacheWrapperInstanceMethod_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    async_lru____LRUCacheWrapperInstanceMethodObject *self;
    self = (async_lru____LRUCacheWrapperInstanceMethodObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _LRUCacheWrapperInstanceMethod_vtable;
    self->vectorcall = CPyPy__LRUCacheWrapperInstanceMethod_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef__LRUCacheWrapperInstanceMethod(PyObject *cpy_r_wrapper, PyObject *cpy_r_instance)
{
    PyObject *self = CPyDef___mypyc___3_LRUCacheWrapperInstanceMethod_setup((PyObject *)CPyType__LRUCacheWrapperInstanceMethod);
    if (self == NULL)
        return NULL;
    char res = CPyDef__LRUCacheWrapperInstanceMethod_____init__(self, cpy_r_wrapper, cpy_r_instance);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_module__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
{
    if (unlikely(self->___module__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__module__' of '_LRUCacheWrapperInstanceMethod' undefined");
        return NULL;
    }
    CPy_INCREF(self->___module__);
    PyObject *retval = self->___module__;
    return retval;
}

static int
_LRUCacheWrapperInstanceMethod_set___3_module__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapperInstanceMethod' object attribute '__module__' cannot be deleted");
        return -1;
    }
    if (self->___module__ != NULL) {
        CPy_DECREF(self->___module__);
    }
    PyObject *tmp;
    if (likely(PyUnicode_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("str", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___module__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_name__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
{
    if (unlikely(self->___name__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__name__' of '_LRUCacheWrapperInstanceMethod' undefined");
        return NULL;
    }
    CPy_INCREF(self->___name__);
    PyObject *retval = self->___name__;
    return retval;
}

static int
_LRUCacheWrapperInstanceMethod_set___3_name__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapperInstanceMethod' object attribute '__name__' cannot be deleted");
        return -1;
    }
    if (self->___name__ != NULL) {
        CPy_DECREF(self->___name__);
    }
    PyObject *tmp;
    if (likely(PyUnicode_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("str", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___name__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_qualname__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
{
    if (unlikely(self->___qualname__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__qualname__' of '_LRUCacheWrapperInstanceMethod' undefined");
        return NULL;
    }
    CPy_INCREF(self->___qualname__);
    PyObject *retval = self->___qualname__;
    return retval;
}

static int
_LRUCacheWrapperInstanceMethod_set___3_qualname__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapperInstanceMethod' object attribute '__qualname__' cannot be deleted");
        return -1;
    }
    if (self->___qualname__ != NULL) {
        CPy_DECREF(self->___qualname__);
    }
    PyObject *tmp;
    if (likely(PyUnicode_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("str", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___qualname__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_doc__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
{
    if (unlikely(self->___doc__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__doc__' of '_LRUCacheWrapperInstanceMethod' undefined");
        return NULL;
    }
    CPy_INCREF(self->___doc__);
    PyObject *retval = self->___doc__;
    return retval;
}

static int
_LRUCacheWrapperInstanceMethod_set___3_doc__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapperInstanceMethod' object attribute '__doc__' cannot be deleted");
        return -1;
    }
    if (self->___doc__ != NULL) {
        CPy_DECREF(self->___doc__);
    }
    PyObject *tmp;
    if (PyUnicode_Check(value))
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL6;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL6;
    CPy_TypeError("str or None", value); 
    tmp = NULL;
__LL6: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___doc__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_annotations__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
{
    if (unlikely(self->___annotations__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__annotations__' of '_LRUCacheWrapperInstanceMethod' undefined");
        return NULL;
    }
    CPy_INCREF(self->___annotations__);
    PyObject *retval = self->___annotations__;
    return retval;
}

static int
_LRUCacheWrapperInstanceMethod_set___3_annotations__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapperInstanceMethod' object attribute '__annotations__' cannot be deleted");
        return -1;
    }
    if (self->___annotations__ != NULL) {
        CPy_DECREF(self->___annotations__);
    }
    PyObject *tmp;
    if (likely(PyDict_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("dict", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___annotations__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_wrapped__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
{
    if (unlikely(self->___wrapped__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__wrapped__' of '_LRUCacheWrapperInstanceMethod' undefined");
        return NULL;
    }
    CPy_INCREF(self->___wrapped__);
    PyObject *retval = self->___wrapped__;
    return retval;
}

static int
_LRUCacheWrapperInstanceMethod_set___3_wrapped__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapperInstanceMethod' object attribute '__wrapped__' cannot be deleted");
        return -1;
    }
    if (self->___wrapped__ != NULL) {
        CPy_DECREF(self->___wrapped__);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->___wrapped__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_instance(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
{
    if (unlikely(self->___instance == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__instance' of '_LRUCacheWrapperInstanceMethod' undefined");
        return NULL;
    }
    CPy_INCREF(self->___instance);
    PyObject *retval = self->___instance;
    return retval;
}

static int
_LRUCacheWrapperInstanceMethod_set___3_instance(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapperInstanceMethod' object attribute '__instance' cannot be deleted");
        return -1;
    }
    if (self->___instance != NULL) {
        CPy_DECREF(self->___instance);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->___instance = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_wrapper(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
{
    if (unlikely(self->___wrapper == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__wrapper' of '_LRUCacheWrapperInstanceMethod' undefined");
        return NULL;
    }
    CPy_INCREF_NO_IMM(self->___wrapper);
    PyObject *retval = self->___wrapper;
    return retval;
}

static int
_LRUCacheWrapperInstanceMethod_set___3_wrapper(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapperInstanceMethod' object attribute '__wrapper' cannot be deleted");
        return -1;
    }
    if (self->___wrapper != NULL) {
        CPy_DECREF_NO_IMM(self->___wrapper);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType__LRUCacheWrapper))
        tmp = value;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF_NO_IMM(tmp);
    self->___wrapper = tmp;
    return 0;
}

static PyAsyncMethods cache_close__LRUCacheWrapper_gen_as_async = {
    .am_await = CPyDef_cache_close__LRUCacheWrapper_gen_____await__,
};
PyObject *CPyDef___mypyc__cache_close__LRUCacheWrapper_gen_setup(PyObject *cpy_r_type);
PyObject *CPyDef_cache_close__LRUCacheWrapper_gen(void);

static PyObject *
cache_close__LRUCacheWrapper_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_cache_close__LRUCacheWrapper_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__cache_close__LRUCacheWrapper_gen_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
cache_close__LRUCacheWrapper_gen_traverse(async_lru___cache_close__LRUCacheWrapper_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_generator_attribute__self);
    Py_VISIT(self->___mypyc_generator_attribute__loop);
    Py_VISIT(self->___mypyc_generator_attribute__tasks);
    Py_VISIT(self->___mypyc_generator_attribute__cancel_msg);
    Py_VISIT(self->___mypyc_temp__0);
    Py_VISIT(self->___mypyc_generator_attribute__task);
    Py_VISIT(self->___mypyc_temp__2);
    Py_VISIT(self->___mypyc_temp__3.f0);
    Py_VISIT(self->___mypyc_temp__3.f1);
    Py_VISIT(self->___mypyc_temp__3.f2);
    return 0;
}

static int
cache_close__LRUCacheWrapper_gen_clear(async_lru___cache_close__LRUCacheWrapper_genObject *self)
{
    Py_CLEAR(self->___mypyc_generator_attribute__self);
    Py_CLEAR(self->___mypyc_generator_attribute__loop);
    Py_CLEAR(self->___mypyc_generator_attribute__tasks);
    Py_CLEAR(self->___mypyc_generator_attribute__cancel_msg);
    Py_CLEAR(self->___mypyc_temp__0);
    Py_CLEAR(self->___mypyc_generator_attribute__task);
    Py_CLEAR(self->___mypyc_temp__2);
    Py_CLEAR(self->___mypyc_temp__3.f0);
    Py_CLEAR(self->___mypyc_temp__3.f1);
    Py_CLEAR(self->___mypyc_temp__3.f2);
    return 0;
}

static void
cache_close__LRUCacheWrapper_gen_dealloc(async_lru___cache_close__LRUCacheWrapper_genObject *self)
{
    PyObject_GC_UnTrack(self);
    if (cache_close__LRUCacheWrapper_gen_free_instance == NULL) {
        cache_close__LRUCacheWrapper_gen_free_instance = self;
        Py_CLEAR(self->___mypyc_generator_attribute__self);
        self->___mypyc_generator_attribute__wait = 2;
        self->___mypyc_next_label__ = -113;
        Py_CLEAR(self->___mypyc_generator_attribute__loop);
        Py_CLEAR(self->___mypyc_generator_attribute__tasks);
        Py_CLEAR(self->___mypyc_generator_attribute__cancel_msg);
        Py_CLEAR(self->___mypyc_temp__0);
        self->___mypyc_temp__1 = -113;
        Py_CLEAR(self->___mypyc_generator_attribute__task);
        Py_CLEAR(self->___mypyc_temp__2);
        Py_CLEAR(self->___mypyc_temp__3.f0);
        Py_CLEAR(self->___mypyc_temp__3.f1);
        Py_CLEAR(self->___mypyc_temp__3.f2);
        return;
    }
    CPy_TRASHCAN_BEGIN(self, cache_close__LRUCacheWrapper_gen_dealloc)
    cache_close__LRUCacheWrapper_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem cache_close__LRUCacheWrapper_gen_vtable[7];
static bool
CPyDef_cache_close__LRUCacheWrapper_gen_trait_vtable_setup(void)
{
    CPyVTableItem cache_close__LRUCacheWrapper_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapper_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapper_gen_____next__,
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapper_gen___send,
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapper_gen_____iter__,
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapper_gen___throw,
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapper_gen___close,
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapper_gen_____await__,
    };
    memcpy(cache_close__LRUCacheWrapper_gen_vtable, cache_close__LRUCacheWrapper_gen_vtable_scratch, sizeof(cache_close__LRUCacheWrapper_gen_vtable));
    return 1;
}

static PyMethodDef cache_close__LRUCacheWrapper_gen_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__cache_close__LRUCacheWrapper_gen_setup, METH_O, NULL},
    {"__next__",
     (PyCFunction)CPyPy_cache_close__LRUCacheWrapper_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__next__()\n--\n\n")},
    {"send",
     (PyCFunction)CPyPy_cache_close__LRUCacheWrapper_gen___send,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("send($arg)\n--\n\n")},
    {"__iter__",
     (PyCFunction)CPyPy_cache_close__LRUCacheWrapper_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__iter__()\n--\n\n")},
    {"throw",
     (PyCFunction)CPyPy_cache_close__LRUCacheWrapper_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR(NULL)},
    {"close",
     (PyCFunction)CPyPy_cache_close__LRUCacheWrapper_gen___close,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("close()\n--\n\n")},
    {"__await__",
     (PyCFunction)CPyPy_cache_close__LRUCacheWrapper_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__await__()\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_cache_close__LRUCacheWrapper_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cache_close__LRUCacheWrapper_gen",
    .tp_new = cache_close__LRUCacheWrapper_gen_new,
    .tp_dealloc = (destructor)cache_close__LRUCacheWrapper_gen_dealloc,
    .tp_traverse = (traverseproc)cache_close__LRUCacheWrapper_gen_traverse,
    .tp_clear = (inquiry)cache_close__LRUCacheWrapper_gen_clear,
    .tp_methods = cache_close__LRUCacheWrapper_gen_methods,
    .tp_iter = CPyDef_cache_close__LRUCacheWrapper_gen_____iter__,
    .tp_iternext = CPyDef_cache_close__LRUCacheWrapper_gen_____next__,
    .tp_as_async = &cache_close__LRUCacheWrapper_gen_as_async,
    .tp_basicsize = sizeof(async_lru___cache_close__LRUCacheWrapper_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("cache_close__LRUCacheWrapper_gen()\n--\n\n"),
};
static PyTypeObject *CPyType_cache_close__LRUCacheWrapper_gen_template = &CPyType_cache_close__LRUCacheWrapper_gen_template_;

PyObject *CPyDef___mypyc__cache_close__LRUCacheWrapper_gen_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    async_lru___cache_close__LRUCacheWrapper_genObject *self;
    if (cache_close__LRUCacheWrapper_gen_free_instance != NULL) {
        self = cache_close__LRUCacheWrapper_gen_free_instance;
        cache_close__LRUCacheWrapper_gen_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (async_lru___cache_close__LRUCacheWrapper_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = cache_close__LRUCacheWrapper_gen_vtable;
    self->___mypyc_generator_attribute__wait = 2;
    self->___mypyc_next_label__ = -113;
    self->___mypyc_temp__1 = -113;
    self->___mypyc_temp__3 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef_cache_close__LRUCacheWrapper_gen(void)
{
    PyObject *self = CPyDef___mypyc__cache_close__LRUCacheWrapper_gen_setup((PyObject *)CPyType_cache_close__LRUCacheWrapper_gen);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_as_async = {
    .am_await = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____await__,
};
PyObject *CPyDef___mypyc___3_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_setup(PyObject *cpy_r_type);
PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen(void);

static PyObject *
_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc___3_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_traverse(async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_generator_attribute__self);
    Py_VISIT(self->___mypyc_generator_attribute__cache_item);
    Py_VISIT(self->___mypyc_generator_attribute__key);
    Py_VISIT(self->___mypyc_generator_attribute__task);
    Py_VISIT(self->___mypyc_temp__4);
    Py_VISIT(self->___mypyc_temp__5.f0);
    Py_VISIT(self->___mypyc_temp__5.f1);
    Py_VISIT(self->___mypyc_temp__5.f2);
    Py_VISIT(self->___mypyc_temp__6);
    Py_VISIT(self->___mypyc_temp__7.f0);
    Py_VISIT(self->___mypyc_temp__7.f1);
    Py_VISIT(self->___mypyc_temp__7.f2);
    return 0;
}

static int
_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_clear(async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *self)
{
    Py_CLEAR(self->___mypyc_generator_attribute__self);
    Py_CLEAR(self->___mypyc_generator_attribute__cache_item);
    Py_CLEAR(self->___mypyc_generator_attribute__key);
    Py_CLEAR(self->___mypyc_generator_attribute__task);
    Py_CLEAR(self->___mypyc_temp__4);
    Py_CLEAR(self->___mypyc_temp__5.f0);
    Py_CLEAR(self->___mypyc_temp__5.f1);
    Py_CLEAR(self->___mypyc_temp__5.f2);
    Py_CLEAR(self->___mypyc_temp__6);
    Py_CLEAR(self->___mypyc_temp__7.f0);
    Py_CLEAR(self->___mypyc_temp__7.f1);
    Py_CLEAR(self->___mypyc_temp__7.f2);
    return 0;
}

static void
_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_dealloc(async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *self)
{
    PyObject_GC_UnTrack(self);
    if (_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_free_instance == NULL) {
        _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_free_instance = self;
        Py_CLEAR(self->___mypyc_generator_attribute__self);
        Py_CLEAR(self->___mypyc_generator_attribute__cache_item);
        Py_CLEAR(self->___mypyc_generator_attribute__key);
        self->___mypyc_next_label__ = -113;
        Py_CLEAR(self->___mypyc_generator_attribute__task);
        Py_CLEAR(self->___mypyc_temp__4);
        Py_CLEAR(self->___mypyc_temp__5.f0);
        Py_CLEAR(self->___mypyc_temp__5.f1);
        Py_CLEAR(self->___mypyc_temp__5.f2);
        Py_CLEAR(self->___mypyc_temp__6);
        Py_CLEAR(self->___mypyc_temp__7.f0);
        Py_CLEAR(self->___mypyc_temp__7.f1);
        Py_CLEAR(self->___mypyc_temp__7.f2);
        return;
    }
    CPy_TRASHCAN_BEGIN(self, _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_dealloc)
    _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_vtable[7];
static bool
CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_trait_vtable_setup(void)
{
    CPyVTableItem _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____next__,
        (CPyVTableItem)CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___send,
        (CPyVTableItem)CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____iter__,
        (CPyVTableItem)CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___throw,
        (CPyVTableItem)CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___close,
        (CPyVTableItem)CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____await__,
    };
    memcpy(_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_vtable, _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_vtable_scratch, sizeof(_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_vtable));
    return 1;
}

static PyMethodDef _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc___3_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_setup, METH_O, NULL},
    {"__next__",
     (PyCFunction)CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__next__()\n--\n\n")},
    {"send",
     (PyCFunction)CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___send,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("send($arg)\n--\n\n")},
    {"__iter__",
     (PyCFunction)CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__iter__()\n--\n\n")},
    {"throw",
     (PyCFunction)CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR(NULL)},
    {"close",
     (PyCFunction)CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___close,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("close()\n--\n\n")},
    {"__await__",
     (PyCFunction)CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__await__()\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen",
    .tp_new = _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_new,
    .tp_dealloc = (destructor)_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_dealloc,
    .tp_traverse = (traverseproc)_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_traverse,
    .tp_clear = (inquiry)_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_clear,
    .tp_methods = _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_methods,
    .tp_iter = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____iter__,
    .tp_iternext = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____next__,
    .tp_as_async = &_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_as_async,
    .tp_basicsize = sizeof(async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("_shield_and_handle_cancelled_error__LRUCacheWrapper_gen()\n--\n\n"),
};
static PyTypeObject *CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_template = &CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_template_;

PyObject *CPyDef___mypyc___3_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *self;
    if (_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_free_instance != NULL) {
        self = _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_free_instance;
        _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_vtable;
    self->___mypyc_next_label__ = -113;
    self->___mypyc_temp__5 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__7 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen(void)
{
    PyObject *self = CPyDef___mypyc___3_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_setup((PyObject *)CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods __call___3__LRUCacheWrapper_gen_as_async = {
    .am_await = CPyDef___call___3__LRUCacheWrapper_gen_____await__,
};
PyObject *CPyDef___mypyc___3__call___3__LRUCacheWrapper_gen_setup(PyObject *cpy_r_type);
PyObject *CPyDef___call___3__LRUCacheWrapper_gen(void);

static PyObject *
__call___3__LRUCacheWrapper_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___call___3__LRUCacheWrapper_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc___3__call___3__LRUCacheWrapper_gen_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
__call___3__LRUCacheWrapper_gen_traverse(async_lru_____call___3__LRUCacheWrapper_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_generator_attribute__self);
    Py_VISIT(self->___mypyc_generator_attribute__fn_args);
    Py_VISIT(self->___mypyc_generator_attribute__fn_kwargs);
    Py_VISIT(self->___mypyc_generator_attribute__task);
    Py_VISIT(self->___mypyc_generator_attribute__loop);
    Py_VISIT(self->___mypyc_generator_attribute__key);
    Py_VISIT(self->___mypyc_generator_attribute__cache);
    Py_VISIT(self->___mypyc_generator_attribute__cache_item);
    Py_VISIT(self->___mypyc_temp__8);
    Py_VISIT(self->___mypyc_temp__9.f0);
    Py_VISIT(self->___mypyc_temp__9.f1);
    Py_VISIT(self->___mypyc_temp__9.f2);
    Py_VISIT(self->___mypyc_generator_attribute__coro);
    Py_VISIT(self->___mypyc_generator_attribute__maxsize);
    Py_VISIT(self->___mypyc_generator_attribute__dropped_key);
    Py_VISIT(self->___mypyc_generator_attribute__dropped_cache_item);
    Py_VISIT(self->___mypyc_temp__10);
    Py_VISIT(self->___mypyc_temp__11.f0);
    Py_VISIT(self->___mypyc_temp__11.f1);
    Py_VISIT(self->___mypyc_temp__11.f2);
    return 0;
}

static int
__call___3__LRUCacheWrapper_gen_clear(async_lru_____call___3__LRUCacheWrapper_genObject *self)
{
    Py_CLEAR(self->___mypyc_generator_attribute__self);
    Py_CLEAR(self->___mypyc_generator_attribute__fn_args);
    Py_CLEAR(self->___mypyc_generator_attribute__fn_kwargs);
    Py_CLEAR(self->___mypyc_generator_attribute__task);
    Py_CLEAR(self->___mypyc_generator_attribute__loop);
    Py_CLEAR(self->___mypyc_generator_attribute__key);
    Py_CLEAR(self->___mypyc_generator_attribute__cache);
    Py_CLEAR(self->___mypyc_generator_attribute__cache_item);
    Py_CLEAR(self->___mypyc_temp__8);
    Py_CLEAR(self->___mypyc_temp__9.f0);
    Py_CLEAR(self->___mypyc_temp__9.f1);
    Py_CLEAR(self->___mypyc_temp__9.f2);
    Py_CLEAR(self->___mypyc_generator_attribute__coro);
    Py_CLEAR(self->___mypyc_generator_attribute__maxsize);
    Py_CLEAR(self->___mypyc_generator_attribute__dropped_key);
    Py_CLEAR(self->___mypyc_generator_attribute__dropped_cache_item);
    Py_CLEAR(self->___mypyc_temp__10);
    Py_CLEAR(self->___mypyc_temp__11.f0);
    Py_CLEAR(self->___mypyc_temp__11.f1);
    Py_CLEAR(self->___mypyc_temp__11.f2);
    return 0;
}

static void
__call___3__LRUCacheWrapper_gen_dealloc(async_lru_____call___3__LRUCacheWrapper_genObject *self)
{
    PyObject_GC_UnTrack(self);
    if (__call___3__LRUCacheWrapper_gen_free_instance == NULL) {
        __call___3__LRUCacheWrapper_gen_free_instance = self;
        Py_CLEAR(self->___mypyc_generator_attribute__self);
        Py_CLEAR(self->___mypyc_generator_attribute__fn_args);
        Py_CLEAR(self->___mypyc_generator_attribute__fn_kwargs);
        self->___mypyc_next_label__ = -113;
        Py_CLEAR(self->___mypyc_generator_attribute__task);
        Py_CLEAR(self->___mypyc_generator_attribute__loop);
        Py_CLEAR(self->___mypyc_generator_attribute__key);
        Py_CLEAR(self->___mypyc_generator_attribute__cache);
        Py_CLEAR(self->___mypyc_generator_attribute__cache_item);
        Py_CLEAR(self->___mypyc_temp__8);
        Py_CLEAR(self->___mypyc_temp__9.f0);
        Py_CLEAR(self->___mypyc_temp__9.f1);
        Py_CLEAR(self->___mypyc_temp__9.f2);
        Py_CLEAR(self->___mypyc_generator_attribute__coro);
        Py_CLEAR(self->___mypyc_generator_attribute__maxsize);
        Py_CLEAR(self->___mypyc_generator_attribute__dropped_key);
        Py_CLEAR(self->___mypyc_generator_attribute__dropped_cache_item);
        Py_CLEAR(self->___mypyc_temp__10);
        Py_CLEAR(self->___mypyc_temp__11.f0);
        Py_CLEAR(self->___mypyc_temp__11.f1);
        Py_CLEAR(self->___mypyc_temp__11.f2);
        return;
    }
    CPy_TRASHCAN_BEGIN(self, __call___3__LRUCacheWrapper_gen_dealloc)
    __call___3__LRUCacheWrapper_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem __call___3__LRUCacheWrapper_gen_vtable[7];
static bool
CPyDef___call___3__LRUCacheWrapper_gen_trait_vtable_setup(void)
{
    CPyVTableItem __call___3__LRUCacheWrapper_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapper_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapper_gen_____next__,
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapper_gen___send,
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapper_gen_____iter__,
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapper_gen___throw,
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapper_gen___close,
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapper_gen_____await__,
    };
    memcpy(__call___3__LRUCacheWrapper_gen_vtable, __call___3__LRUCacheWrapper_gen_vtable_scratch, sizeof(__call___3__LRUCacheWrapper_gen_vtable));
    return 1;
}

static PyMethodDef __call___3__LRUCacheWrapper_gen_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc___3__call___3__LRUCacheWrapper_gen_setup, METH_O, NULL},
    {"__next__",
     (PyCFunction)CPyPy___call___3__LRUCacheWrapper_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__next__()\n--\n\n")},
    {"send",
     (PyCFunction)CPyPy___call___3__LRUCacheWrapper_gen___send,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("send($arg)\n--\n\n")},
    {"__iter__",
     (PyCFunction)CPyPy___call___3__LRUCacheWrapper_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__iter__()\n--\n\n")},
    {"throw",
     (PyCFunction)CPyPy___call___3__LRUCacheWrapper_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR(NULL)},
    {"close",
     (PyCFunction)CPyPy___call___3__LRUCacheWrapper_gen___close,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("close()\n--\n\n")},
    {"__await__",
     (PyCFunction)CPyPy___call___3__LRUCacheWrapper_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__await__()\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___call___3__LRUCacheWrapper_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__call____LRUCacheWrapper_gen",
    .tp_new = __call___3__LRUCacheWrapper_gen_new,
    .tp_dealloc = (destructor)__call___3__LRUCacheWrapper_gen_dealloc,
    .tp_traverse = (traverseproc)__call___3__LRUCacheWrapper_gen_traverse,
    .tp_clear = (inquiry)__call___3__LRUCacheWrapper_gen_clear,
    .tp_methods = __call___3__LRUCacheWrapper_gen_methods,
    .tp_iter = CPyDef___call___3__LRUCacheWrapper_gen_____iter__,
    .tp_iternext = CPyDef___call___3__LRUCacheWrapper_gen_____next__,
    .tp_as_async = &__call___3__LRUCacheWrapper_gen_as_async,
    .tp_basicsize = sizeof(async_lru_____call___3__LRUCacheWrapper_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("__call____LRUCacheWrapper_gen()\n--\n\n"),
};
static PyTypeObject *CPyType___call___3__LRUCacheWrapper_gen_template = &CPyType___call___3__LRUCacheWrapper_gen_template_;

PyObject *CPyDef___mypyc___3__call___3__LRUCacheWrapper_gen_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    async_lru_____call___3__LRUCacheWrapper_genObject *self;
    if (__call___3__LRUCacheWrapper_gen_free_instance != NULL) {
        self = __call___3__LRUCacheWrapper_gen_free_instance;
        __call___3__LRUCacheWrapper_gen_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (async_lru_____call___3__LRUCacheWrapper_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __call___3__LRUCacheWrapper_gen_vtable;
    self->___mypyc_next_label__ = -113;
    self->___mypyc_temp__9 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__11 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef___call___3__LRUCacheWrapper_gen(void)
{
    PyObject *self = CPyDef___mypyc___3__call___3__LRUCacheWrapper_gen_setup((PyObject *)CPyType___call___3__LRUCacheWrapper_gen);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods cache_close__LRUCacheWrapperInstanceMethod_gen_as_async = {
    .am_await = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____await__,
};
PyObject *CPyDef___mypyc__cache_close__LRUCacheWrapperInstanceMethod_gen_setup(PyObject *cpy_r_type);
PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen(void);

static PyObject *
cache_close__LRUCacheWrapperInstanceMethod_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__cache_close__LRUCacheWrapperInstanceMethod_gen_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
cache_close__LRUCacheWrapperInstanceMethod_gen_traverse(async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_generator_attribute__self);
    Py_VISIT(self->___mypyc_temp__12);
    Py_VISIT(self->___mypyc_temp__13.f0);
    Py_VISIT(self->___mypyc_temp__13.f1);
    Py_VISIT(self->___mypyc_temp__13.f2);
    return 0;
}

static int
cache_close__LRUCacheWrapperInstanceMethod_gen_clear(async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *self)
{
    Py_CLEAR(self->___mypyc_generator_attribute__self);
    Py_CLEAR(self->___mypyc_temp__12);
    Py_CLEAR(self->___mypyc_temp__13.f0);
    Py_CLEAR(self->___mypyc_temp__13.f1);
    Py_CLEAR(self->___mypyc_temp__13.f2);
    return 0;
}

static void
cache_close__LRUCacheWrapperInstanceMethod_gen_dealloc(async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *self)
{
    PyObject_GC_UnTrack(self);
    if (cache_close__LRUCacheWrapperInstanceMethod_gen_free_instance == NULL) {
        cache_close__LRUCacheWrapperInstanceMethod_gen_free_instance = self;
        Py_CLEAR(self->___mypyc_generator_attribute__self);
        self->___mypyc_generator_attribute__cancel = 2;
        self->___mypyc_generator_attribute__return_exceptions = 2;
        self->___mypyc_next_label__ = -113;
        Py_CLEAR(self->___mypyc_temp__12);
        Py_CLEAR(self->___mypyc_temp__13.f0);
        Py_CLEAR(self->___mypyc_temp__13.f1);
        Py_CLEAR(self->___mypyc_temp__13.f2);
        return;
    }
    CPy_TRASHCAN_BEGIN(self, cache_close__LRUCacheWrapperInstanceMethod_gen_dealloc)
    cache_close__LRUCacheWrapperInstanceMethod_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem cache_close__LRUCacheWrapperInstanceMethod_gen_vtable[7];
static bool
CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_trait_vtable_setup(void)
{
    CPyVTableItem cache_close__LRUCacheWrapperInstanceMethod_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____next__,
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___send,
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____iter__,
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___throw,
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___close,
        (CPyVTableItem)CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____await__,
    };
    memcpy(cache_close__LRUCacheWrapperInstanceMethod_gen_vtable, cache_close__LRUCacheWrapperInstanceMethod_gen_vtable_scratch, sizeof(cache_close__LRUCacheWrapperInstanceMethod_gen_vtable));
    return 1;
}

static PyMethodDef cache_close__LRUCacheWrapperInstanceMethod_gen_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__cache_close__LRUCacheWrapperInstanceMethod_gen_setup, METH_O, NULL},
    {"__next__",
     (PyCFunction)CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__next__()\n--\n\n")},
    {"send",
     (PyCFunction)CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen___send,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("send($arg)\n--\n\n")},
    {"__iter__",
     (PyCFunction)CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__iter__()\n--\n\n")},
    {"throw",
     (PyCFunction)CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR(NULL)},
    {"close",
     (PyCFunction)CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen___close,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("close()\n--\n\n")},
    {"__await__",
     (PyCFunction)CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__await__()\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cache_close__LRUCacheWrapperInstanceMethod_gen",
    .tp_new = cache_close__LRUCacheWrapperInstanceMethod_gen_new,
    .tp_dealloc = (destructor)cache_close__LRUCacheWrapperInstanceMethod_gen_dealloc,
    .tp_traverse = (traverseproc)cache_close__LRUCacheWrapperInstanceMethod_gen_traverse,
    .tp_clear = (inquiry)cache_close__LRUCacheWrapperInstanceMethod_gen_clear,
    .tp_methods = cache_close__LRUCacheWrapperInstanceMethod_gen_methods,
    .tp_iter = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____iter__,
    .tp_iternext = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____next__,
    .tp_as_async = &cache_close__LRUCacheWrapperInstanceMethod_gen_as_async,
    .tp_basicsize = sizeof(async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("cache_close__LRUCacheWrapperInstanceMethod_gen()\n--\n\n"),
};
static PyTypeObject *CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen_template = &CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen_template_;

PyObject *CPyDef___mypyc__cache_close__LRUCacheWrapperInstanceMethod_gen_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *self;
    if (cache_close__LRUCacheWrapperInstanceMethod_gen_free_instance != NULL) {
        self = cache_close__LRUCacheWrapperInstanceMethod_gen_free_instance;
        cache_close__LRUCacheWrapperInstanceMethod_gen_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = cache_close__LRUCacheWrapperInstanceMethod_gen_vtable;
    self->___mypyc_generator_attribute__cancel = 2;
    self->___mypyc_generator_attribute__return_exceptions = 2;
    self->___mypyc_next_label__ = -113;
    self->___mypyc_temp__13 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen(void)
{
    PyObject *self = CPyDef___mypyc__cache_close__LRUCacheWrapperInstanceMethod_gen_setup((PyObject *)CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods __call___3__LRUCacheWrapperInstanceMethod_gen_as_async = {
    .am_await = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____await__,
};
PyObject *CPyDef___mypyc___3__call___3__LRUCacheWrapperInstanceMethod_gen_setup(PyObject *cpy_r_type);
PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen(void);

static PyObject *
__call___3__LRUCacheWrapperInstanceMethod_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___call___3__LRUCacheWrapperInstanceMethod_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc___3__call___3__LRUCacheWrapperInstanceMethod_gen_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
__call___3__LRUCacheWrapperInstanceMethod_gen_traverse(async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_generator_attribute__self);
    Py_VISIT(self->___mypyc_generator_attribute__fn_args);
    Py_VISIT(self->___mypyc_generator_attribute__fn_kwargs);
    Py_VISIT(self->___mypyc_temp__14);
    Py_VISIT(self->___mypyc_temp__15.f0);
    Py_VISIT(self->___mypyc_temp__15.f1);
    Py_VISIT(self->___mypyc_temp__15.f2);
    return 0;
}

static int
__call___3__LRUCacheWrapperInstanceMethod_gen_clear(async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *self)
{
    Py_CLEAR(self->___mypyc_generator_attribute__self);
    Py_CLEAR(self->___mypyc_generator_attribute__fn_args);
    Py_CLEAR(self->___mypyc_generator_attribute__fn_kwargs);
    Py_CLEAR(self->___mypyc_temp__14);
    Py_CLEAR(self->___mypyc_temp__15.f0);
    Py_CLEAR(self->___mypyc_temp__15.f1);
    Py_CLEAR(self->___mypyc_temp__15.f2);
    return 0;
}

static void
__call___3__LRUCacheWrapperInstanceMethod_gen_dealloc(async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *self)
{
    PyObject_GC_UnTrack(self);
    if (__call___3__LRUCacheWrapperInstanceMethod_gen_free_instance == NULL) {
        __call___3__LRUCacheWrapperInstanceMethod_gen_free_instance = self;
        Py_CLEAR(self->___mypyc_generator_attribute__self);
        Py_CLEAR(self->___mypyc_generator_attribute__fn_args);
        Py_CLEAR(self->___mypyc_generator_attribute__fn_kwargs);
        self->___mypyc_next_label__ = -113;
        Py_CLEAR(self->___mypyc_temp__14);
        Py_CLEAR(self->___mypyc_temp__15.f0);
        Py_CLEAR(self->___mypyc_temp__15.f1);
        Py_CLEAR(self->___mypyc_temp__15.f2);
        return;
    }
    CPy_TRASHCAN_BEGIN(self, __call___3__LRUCacheWrapperInstanceMethod_gen_dealloc)
    __call___3__LRUCacheWrapperInstanceMethod_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem __call___3__LRUCacheWrapperInstanceMethod_gen_vtable[7];
static bool
CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_trait_vtable_setup(void)
{
    CPyVTableItem __call___3__LRUCacheWrapperInstanceMethod_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____next__,
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___send,
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____iter__,
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___throw,
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___close,
        (CPyVTableItem)CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____await__,
    };
    memcpy(__call___3__LRUCacheWrapperInstanceMethod_gen_vtable, __call___3__LRUCacheWrapperInstanceMethod_gen_vtable_scratch, sizeof(__call___3__LRUCacheWrapperInstanceMethod_gen_vtable));
    return 1;
}

static PyMethodDef __call___3__LRUCacheWrapperInstanceMethod_gen_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc___3__call___3__LRUCacheWrapperInstanceMethod_gen_setup, METH_O, NULL},
    {"__next__",
     (PyCFunction)CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__next__()\n--\n\n")},
    {"send",
     (PyCFunction)CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen___send,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("send($arg)\n--\n\n")},
    {"__iter__",
     (PyCFunction)CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__iter__()\n--\n\n")},
    {"throw",
     (PyCFunction)CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR(NULL)},
    {"close",
     (PyCFunction)CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen___close,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("close()\n--\n\n")},
    {"__await__",
     (PyCFunction)CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__await__()\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___call___3__LRUCacheWrapperInstanceMethod_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__call____LRUCacheWrapperInstanceMethod_gen",
    .tp_new = __call___3__LRUCacheWrapperInstanceMethod_gen_new,
    .tp_dealloc = (destructor)__call___3__LRUCacheWrapperInstanceMethod_gen_dealloc,
    .tp_traverse = (traverseproc)__call___3__LRUCacheWrapperInstanceMethod_gen_traverse,
    .tp_clear = (inquiry)__call___3__LRUCacheWrapperInstanceMethod_gen_clear,
    .tp_methods = __call___3__LRUCacheWrapperInstanceMethod_gen_methods,
    .tp_iter = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____iter__,
    .tp_iternext = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____next__,
    .tp_as_async = &__call___3__LRUCacheWrapperInstanceMethod_gen_as_async,
    .tp_basicsize = sizeof(async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("__call____LRUCacheWrapperInstanceMethod_gen()\n--\n\n"),
};
static PyTypeObject *CPyType___call___3__LRUCacheWrapperInstanceMethod_gen_template = &CPyType___call___3__LRUCacheWrapperInstanceMethod_gen_template_;

PyObject *CPyDef___mypyc___3__call___3__LRUCacheWrapperInstanceMethod_gen_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *self;
    if (__call___3__LRUCacheWrapperInstanceMethod_gen_free_instance != NULL) {
        self = __call___3__LRUCacheWrapperInstanceMethod_gen_free_instance;
        __call___3__LRUCacheWrapperInstanceMethod_gen_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __call___3__LRUCacheWrapperInstanceMethod_gen_vtable;
    self->___mypyc_next_label__ = -113;
    self->___mypyc_temp__15 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen(void)
{
    PyObject *self = CPyDef___mypyc___3__call___3__LRUCacheWrapperInstanceMethod_gen_setup((PyObject *)CPyType___call___3__LRUCacheWrapperInstanceMethod_gen);
    if (self == NULL)
        return NULL;
    return self;
}


PyObject *CPyDef___mypyc___3_make_wrapper_env_setup(PyObject *cpy_r_type);
PyObject *CPyDef__make_wrapper_env(void);

static PyObject *
_make_wrapper_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__make_wrapper_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc___3_make_wrapper_env_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
_make_wrapper_env_traverse(async_lru____make_wrapper_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_maxsize);
    Py_VISIT(self->_ttl);
    Py_VISIT(self->_wrapper);
    return 0;
}

static int
_make_wrapper_env_clear(async_lru____make_wrapper_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_maxsize);
    Py_CLEAR(self->_ttl);
    Py_CLEAR(self->_wrapper);
    return 0;
}

static void
_make_wrapper_env_dealloc(async_lru____make_wrapper_envObject *self)
{
    PyObject_GC_UnTrack(self);
    if (_make_wrapper_env_free_instance == NULL) {
        _make_wrapper_env_free_instance = self;
        Py_CLEAR(self->___mypyc_self__);
        Py_CLEAR(self->_maxsize);
        self->_typed = 2;
        Py_CLEAR(self->_ttl);
        Py_CLEAR(self->_wrapper);
        return;
    }
    CPy_TRASHCAN_BEGIN(self, _make_wrapper_env_dealloc)
    _make_wrapper_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem _make_wrapper_env_vtable[1];
static bool
CPyDef__make_wrapper_env_trait_vtable_setup(void)
{
    CPyVTableItem _make_wrapper_env_vtable_scratch[] = {
        NULL
    };
    memcpy(_make_wrapper_env_vtable, _make_wrapper_env_vtable_scratch, sizeof(_make_wrapper_env_vtable));
    return 1;
}

static PyMethodDef _make_wrapper_env_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc___3_make_wrapper_env_setup, METH_O, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__make_wrapper_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_make_wrapper_env",
    .tp_new = _make_wrapper_env_new,
    .tp_dealloc = (destructor)_make_wrapper_env_dealloc,
    .tp_traverse = (traverseproc)_make_wrapper_env_traverse,
    .tp_clear = (inquiry)_make_wrapper_env_clear,
    .tp_methods = _make_wrapper_env_methods,
    .tp_basicsize = sizeof(async_lru____make_wrapper_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("_make_wrapper_env()\n--\n\n"),
};
static PyTypeObject *CPyType__make_wrapper_env_template = &CPyType__make_wrapper_env_template_;

PyObject *CPyDef___mypyc___3_make_wrapper_env_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    async_lru____make_wrapper_envObject *self;
    if (_make_wrapper_env_free_instance != NULL) {
        self = _make_wrapper_env_free_instance;
        _make_wrapper_env_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (async_lru____make_wrapper_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _make_wrapper_env_vtable;
    self->_typed = 2;
    return (PyObject *)self;
}

PyObject *CPyDef__make_wrapper_env(void)
{
    PyObject *self = CPyDef___mypyc___3_make_wrapper_env_setup((PyObject *)CPyType__make_wrapper_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get__wrapper__make_wrapper_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef_wrapper__make_wrapper_obj_____get__(self, instance, owner);
}
PyObject *CPyDef___mypyc__wrapper__make_wrapper_obj_setup(PyObject *cpy_r_type);
PyObject *CPyDef_wrapper__make_wrapper_obj(void);

static PyObject *
wrapper__make_wrapper_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_wrapper__make_wrapper_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__wrapper__make_wrapper_obj_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
wrapper__make_wrapper_obj_traverse(async_lru___wrapper__make_wrapper_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
wrapper__make_wrapper_obj_clear(async_lru___wrapper__make_wrapper_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
wrapper__make_wrapper_obj_dealloc(async_lru___wrapper__make_wrapper_objObject *self)
{
    PyObject_GC_UnTrack(self);
    if (wrapper__make_wrapper_obj_free_instance == NULL) {
        wrapper__make_wrapper_obj_free_instance = self;
        Py_CLEAR(self->___mypyc_env__);
        return;
    }
    CPy_TRASHCAN_BEGIN(self, wrapper__make_wrapper_obj_dealloc)
    wrapper__make_wrapper_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem wrapper__make_wrapper_obj_vtable[2];
static bool
CPyDef_wrapper__make_wrapper_obj_trait_vtable_setup(void)
{
    CPyVTableItem wrapper__make_wrapper_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_wrapper__make_wrapper_obj_____call__,
        (CPyVTableItem)CPyDef_wrapper__make_wrapper_obj_____get__,
    };
    memcpy(wrapper__make_wrapper_obj_vtable, wrapper__make_wrapper_obj_vtable_scratch, sizeof(wrapper__make_wrapper_obj_vtable));
    return 1;
}

static PyObject *
wrapper__make_wrapper_obj_get___3_mypyc_env__(async_lru___wrapper__make_wrapper_objObject *self, void *closure);
static int
wrapper__make_wrapper_obj_set___3_mypyc_env__(async_lru___wrapper__make_wrapper_objObject *self, PyObject *value, void *closure);

static PyGetSetDef wrapper__make_wrapper_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)wrapper__make_wrapper_obj_get___3_mypyc_env__, (setter)wrapper__make_wrapper_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef wrapper__make_wrapper_obj_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__wrapper__make_wrapper_obj_setup, METH_O, NULL},
    {"__call__",
     (PyCFunction)CPyPy_wrapper__make_wrapper_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__call__($fn)\n--\n\n")},
    {"__get__",
     (PyCFunction)CPyPy_wrapper__make_wrapper_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__get__($instance, owner)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_wrapper__make_wrapper_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "wrapper__make_wrapper_obj",
    .tp_new = wrapper__make_wrapper_obj_new,
    .tp_dealloc = (destructor)wrapper__make_wrapper_obj_dealloc,
    .tp_traverse = (traverseproc)wrapper__make_wrapper_obj_traverse,
    .tp_clear = (inquiry)wrapper__make_wrapper_obj_clear,
    .tp_getset = wrapper__make_wrapper_obj_getseters,
    .tp_methods = wrapper__make_wrapper_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get__wrapper__make_wrapper_obj,
    .tp_basicsize = sizeof(async_lru___wrapper__make_wrapper_objObject),
    .tp_vectorcall_offset = offsetof(async_lru___wrapper__make_wrapper_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("wrapper__make_wrapper_obj()\n--\n\n"),
};
static PyTypeObject *CPyType_wrapper__make_wrapper_obj_template = &CPyType_wrapper__make_wrapper_obj_template_;

PyObject *CPyDef___mypyc__wrapper__make_wrapper_obj_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    async_lru___wrapper__make_wrapper_objObject *self;
    if (wrapper__make_wrapper_obj_free_instance != NULL) {
        self = wrapper__make_wrapper_obj_free_instance;
        wrapper__make_wrapper_obj_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (async_lru___wrapper__make_wrapper_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = wrapper__make_wrapper_obj_vtable;
    self->vectorcall = CPyPy_wrapper__make_wrapper_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef_wrapper__make_wrapper_obj(void)
{
    PyObject *self = CPyDef___mypyc__wrapper__make_wrapper_obj_setup((PyObject *)CPyType_wrapper__make_wrapper_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
wrapper__make_wrapper_obj_get___3_mypyc_env__(async_lru___wrapper__make_wrapper_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of 'wrapper__make_wrapper_obj' undefined");
        return NULL;
    }
    CPy_INCREF_NO_IMM(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
wrapper__make_wrapper_obj_set___3_mypyc_env__(async_lru___wrapper__make_wrapper_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'wrapper__make_wrapper_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType__make_wrapper_env))
        tmp = value;
    else {
        CPy_TypeError("async_lru._make_wrapper_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF_NO_IMM(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}
static PyMethodDef module_methods[] = {
    {"_make_wrapper", (PyCFunction)CPyPy__make_wrapper, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_make_wrapper(maxsize, typed, ttl=None)\n--\n\n") /* docstring */},
    {"alru_cache", (PyCFunction)CPyPy_alru_cache, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("alru_cache(maxsize=128, typed=False, *, ttl=None)\n--\n\n") /* docstring */},
    {NULL, NULL, 0, NULL}
};

int CPyExec_async_lru(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_async_lru__internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_async_lru__internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    CPyType_cache_close__LRUCacheWrapper_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_cache_close__LRUCacheWrapper_gen_template, NULL, modname);
    if (unlikely(!CPyType_cache_close__LRUCacheWrapper_gen))
        goto fail;
    CPyDef_cache_close__LRUCacheWrapper_gen_trait_vtable_setup();
    CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_template, NULL, modname);
    if (unlikely(!CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen))
        goto fail;
    CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_trait_vtable_setup();
    CPyType___call___3__LRUCacheWrapper_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___call___3__LRUCacheWrapper_gen_template, NULL, modname);
    if (unlikely(!CPyType___call___3__LRUCacheWrapper_gen))
        goto fail;
    CPyDef___call___3__LRUCacheWrapper_gen_trait_vtable_setup();
    CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen_template, NULL, modname);
    if (unlikely(!CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen))
        goto fail;
    CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_trait_vtable_setup();
    CPyType___call___3__LRUCacheWrapperInstanceMethod_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___call___3__LRUCacheWrapperInstanceMethod_gen_template, NULL, modname);
    if (unlikely(!CPyType___call___3__LRUCacheWrapperInstanceMethod_gen))
        goto fail;
    CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_trait_vtable_setup();
    CPyType__make_wrapper_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__make_wrapper_env_template, NULL, modname);
    if (unlikely(!CPyType__make_wrapper_env))
        goto fail;
    CPyDef__make_wrapper_env_trait_vtable_setup();
    CPyType_wrapper__make_wrapper_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_wrapper__make_wrapper_obj_template, NULL, modname);
    if (unlikely(!CPyType_wrapper__make_wrapper_obj))
        goto fail;
    CPyDef_wrapper__make_wrapper_obj_trait_vtable_setup();
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_async_lru__internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic_ALLOW_SYNC);
    CPyStatic_ALLOW_SYNC = NULL;
    CPyStatic__PYTHON_GTE_312 = 2;
    CPy_XDECREF(CPyStatic__CacheInfo);
    CPyStatic__CacheInfo = NULL;
    CPy_XDECREF(CPyStatic_partial);
    CPyStatic_partial = NULL;
    CPy_XDECREF(CPyStatic_partialmethod);
    CPyStatic_partialmethod = NULL;
    CPy_XDECREF(CPyStatic__make_key);
    CPyStatic__make_key = NULL;
    CPy_XDECREF(CPyStatic_gather);
    CPyStatic_gather = NULL;
    CPy_XDECREF(CPyStatic_get_running_loop);
    CPyStatic_get_running_loop = NULL;
    CPy_XDECREF(CPyStatic_shield);
    CPyStatic_shield = NULL;
    CPy_XDECREF(CPyStatic_markcoroutinefunction);
    CPyStatic_markcoroutinefunction = NULL;
    CPy_XDECREF(CPyStatic_iscoroutinefunction);
    CPyStatic_iscoroutinefunction = NULL;
    CPy_XDECREF(CPyStatic_logger);
    CPyStatic_logger = NULL;
    Py_CLEAR(CPyType__CacheParameters);
    Py_CLEAR(CPyType__CacheItem);
    Py_CLEAR(CPyType__LRUCacheWrapper);
    Py_CLEAR(CPyType__LRUCacheWrapperInstanceMethod);
    Py_CLEAR(CPyType_cache_close__LRUCacheWrapper_gen);
    Py_CLEAR(CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen);
    Py_CLEAR(CPyType___call___3__LRUCacheWrapper_gen);
    Py_CLEAR(CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen);
    Py_CLEAR(CPyType___call___3__LRUCacheWrapperInstanceMethod_gen);
    Py_CLEAR(CPyType__make_wrapper_env);
    Py_CLEAR(CPyType_wrapper__make_wrapper_obj);
    return -1;
}
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "async_lru",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    module_methods,
    NULL,
};

PyMODINIT_FUNC PyInit_async_lru(void)
{
    if (CPyModule_async_lru__internal) {
        Py_INCREF(CPyModule_async_lru__internal);
        return CPyModule_async_lru__internal;
    }
    CPyModule_async_lru__internal = PyModule_Create(&module);
    if (unlikely(CPyModule_async_lru__internal == NULL))
        goto fail;
    if (CPyExec_async_lru(CPyModule_async_lru__internal) != 0)
        goto fail;
    return CPyModule_async_lru__internal;
    fail:
    return NULL;
}

char CPyDef__CacheItem___cancel(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    cpy_r_r0 = ((async_lru____CacheItemObject *)cpy_r_self)->_later_call;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cancel", "_CacheItem", "later_call", 88, CPyStatic_globals);
        goto CPyL8;
    }
CPyL1: ;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (!cpy_r_r2) goto CPyL7;
    cpy_r_r3 = ((async_lru____CacheItemObject *)cpy_r_self)->_later_call;
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cancel", "_CacheItem", "later_call", 89, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_INCREF(cpy_r_r3);
CPyL3: ;
    cpy_r_r4 = cpy_r_r3;
    cpy_r_r5 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cancel' */
    PyObject *cpy_r_r6[1] = {cpy_r_r4};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = PyObject_VectorcallMethod(cpy_r_r5, cpy_r_r7, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cancel", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL9;
    }
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r8 != Py_None)) {
        CPy_TypeError("None", cpy_r_r8); cpy_r_r9 = 2;
    } else
        cpy_r_r9 = 1;
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r9 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cancel", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r10 = Py_None;
    if (((async_lru____CacheItemObject *)cpy_r_self)->_later_call != NULL) {
        CPy_DECREF(((async_lru____CacheItemObject *)cpy_r_self)->_later_call);
    }
    ((async_lru____CacheItemObject *)cpy_r_self)->_later_call = cpy_r_r10;
    cpy_r_r11 = 1;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("async_lru/__init__.py", "cancel", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL8;
    }
CPyL7: ;
    return 1;
CPyL8: ;
    cpy_r_r12 = 2;
    return cpy_r_r12;
CPyL9: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL8;
}

PyObject *CPyPy__CacheItem___cancel(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":cancel", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__CacheItem))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._CacheItem", obj_self); 
        goto fail;
    }
    char retval = CPyDef__CacheItem___cancel(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "cancel", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef__LRUCacheWrapper_____init__(PyObject *cpy_r_self, PyObject *cpy_r_fn, PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    tuple_T3OOO cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    tuple_T3OOO cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
    tuple_T3OOO cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    char cpy_r_r32;
    tuple_T3OOO cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    char cpy_r_r37;
    char cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    char cpy_r_r42;
    tuple_T3OOO cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    char cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    int32_t cpy_r_r54;
    char cpy_r_r55;
    tuple_T3OOO cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    char cpy_r_r60;
    char cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    tuple_T2II cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    char cpy_r_r69;
    char cpy_r_r70;
    char cpy_r_r71;
    char cpy_r_r72;
    char cpy_r_r73;
    char cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    char cpy_r_r80;
    char cpy_r_r81;
    char cpy_r_r82;
    char cpy_r_r83;
    PyObject *cpy_r_r84;
    char cpy_r_r85;
    char cpy_r_r86;
    cpy_r_r0 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_fn, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL4;
    }
    if (likely(PyUnicode_Check(cpy_r_r1)))
        cpy_r_r2 = cpy_r_r1;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 104, CPyStatic_globals, "str", cpy_r_r1);
        goto CPyL4;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___module__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___module__);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___module__ = cpy_r_r2;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL11;
CPyL4: ;
    cpy_r_r4 = CPy_CatchError();
    cpy_r_r5 = CPyModule_builtins;
    cpy_r_r6 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r8 = CPy_ExceptionMatches(cpy_r_r7);
    CPy_DecRef(cpy_r_r7);
    if (cpy_r_r8) goto CPyL8;
    CPy_Reraise();
    if (!0) {
        goto CPyL9;
    } else
        goto CPyL83;
CPyL7: ;
    CPy_Unreachable();
CPyL8: ;
    CPy_RestoreExcInfo(cpy_r_r4);
    CPy_DecRef(cpy_r_r4.f0);
    CPy_DecRef(cpy_r_r4.f1);
    CPy_DecRef(cpy_r_r4.f2);
    goto CPyL11;
CPyL9: ;
    CPy_RestoreExcInfo(cpy_r_r4);
    CPy_DecRef(cpy_r_r4.f0);
    CPy_DecRef(cpy_r_r4.f1);
    CPy_DecRef(cpy_r_r4.f2);
    cpy_r_r9 = CPy_KeepPropagating();
    if (!cpy_r_r9) goto CPyL82;
    CPy_Unreachable();
CPyL11: ;
    cpy_r_r10 = CPy_GetName(cpy_r_fn);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL14;
    }
    if (likely(PyUnicode_Check(cpy_r_r10)))
        cpy_r_r11 = cpy_r_r10;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 108, CPyStatic_globals, "str", cpy_r_r10);
        goto CPyL14;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___name__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___name__);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___name__ = cpy_r_r11;
    cpy_r_r12 = 1;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL21;
CPyL14: ;
    cpy_r_r13 = CPy_CatchError();
    cpy_r_r14 = CPyModule_builtins;
    cpy_r_r15 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r17 = CPy_ExceptionMatches(cpy_r_r16);
    CPy_DecRef(cpy_r_r16);
    if (cpy_r_r17) goto CPyL18;
    CPy_Reraise();
    if (!0) {
        goto CPyL19;
    } else
        goto CPyL84;
CPyL17: ;
    CPy_Unreachable();
CPyL18: ;
    CPy_RestoreExcInfo(cpy_r_r13);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r13.f2);
    goto CPyL21;
CPyL19: ;
    CPy_RestoreExcInfo(cpy_r_r13);
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r13.f2);
    cpy_r_r18 = CPy_KeepPropagating();
    if (!cpy_r_r18) goto CPyL82;
    CPy_Unreachable();
CPyL21: ;
    cpy_r_r19 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__qualname__' */
    cpy_r_r20 = CPyObject_GetAttr(cpy_r_fn, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL24;
    }
    if (likely(PyUnicode_Check(cpy_r_r20)))
        cpy_r_r21 = cpy_r_r20;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 112, CPyStatic_globals, "str", cpy_r_r20);
        goto CPyL24;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___qualname__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___qualname__);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___qualname__ = cpy_r_r21;
    cpy_r_r22 = 1;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL31;
CPyL24: ;
    cpy_r_r23 = CPy_CatchError();
    cpy_r_r24 = CPyModule_builtins;
    cpy_r_r25 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r26 = CPyObject_GetAttr(cpy_r_r24, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r27 = CPy_ExceptionMatches(cpy_r_r26);
    CPy_DecRef(cpy_r_r26);
    if (cpy_r_r27) goto CPyL28;
    CPy_Reraise();
    if (!0) {
        goto CPyL29;
    } else
        goto CPyL85;
CPyL27: ;
    CPy_Unreachable();
CPyL28: ;
    CPy_RestoreExcInfo(cpy_r_r23);
    CPy_DecRef(cpy_r_r23.f0);
    CPy_DecRef(cpy_r_r23.f1);
    CPy_DecRef(cpy_r_r23.f2);
    goto CPyL31;
CPyL29: ;
    CPy_RestoreExcInfo(cpy_r_r23);
    CPy_DecRef(cpy_r_r23.f0);
    CPy_DecRef(cpy_r_r23.f1);
    CPy_DecRef(cpy_r_r23.f2);
    cpy_r_r28 = CPy_KeepPropagating();
    if (!cpy_r_r28) goto CPyL82;
    CPy_Unreachable();
CPyL31: ;
    cpy_r_r29 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r30 = CPyObject_GetAttr(cpy_r_fn, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL34;
    }
    if (PyUnicode_Check(cpy_r_r30))
        cpy_r_r31 = cpy_r_r30;
    else {
        cpy_r_r31 = NULL;
    }
    if (cpy_r_r31 != NULL) goto __LL7;
    if (cpy_r_r30 == Py_None)
        cpy_r_r31 = cpy_r_r30;
    else {
        cpy_r_r31 = NULL;
    }
    if (cpy_r_r31 != NULL) goto __LL7;
    CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 116, CPyStatic_globals, "str or None", cpy_r_r30);
    goto CPyL34;
__LL7: ;
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___doc__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___doc__);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___doc__ = cpy_r_r31;
    cpy_r_r32 = 1;
    if (unlikely(!cpy_r_r32)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL41;
CPyL34: ;
    cpy_r_r33 = CPy_CatchError();
    cpy_r_r34 = CPyModule_builtins;
    cpy_r_r35 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r36 = CPyObject_GetAttr(cpy_r_r34, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r37 = CPy_ExceptionMatches(cpy_r_r36);
    CPy_DecRef(cpy_r_r36);
    if (cpy_r_r37) goto CPyL38;
    CPy_Reraise();
    if (!0) {
        goto CPyL39;
    } else
        goto CPyL86;
CPyL37: ;
    CPy_Unreachable();
CPyL38: ;
    CPy_RestoreExcInfo(cpy_r_r33);
    CPy_DecRef(cpy_r_r33.f0);
    CPy_DecRef(cpy_r_r33.f1);
    CPy_DecRef(cpy_r_r33.f2);
    goto CPyL41;
CPyL39: ;
    CPy_RestoreExcInfo(cpy_r_r33);
    CPy_DecRef(cpy_r_r33.f0);
    CPy_DecRef(cpy_r_r33.f1);
    CPy_DecRef(cpy_r_r33.f2);
    cpy_r_r38 = CPy_KeepPropagating();
    if (!cpy_r_r38) goto CPyL82;
    CPy_Unreachable();
CPyL41: ;
    cpy_r_r39 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_fn, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL44;
    }
    if (likely(PyDict_Check(cpy_r_r40)))
        cpy_r_r41 = cpy_r_r40;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 120, CPyStatic_globals, "dict", cpy_r_r40);
        goto CPyL44;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___annotations__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___annotations__);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___annotations__ = cpy_r_r41;
    cpy_r_r42 = 1;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL51;
CPyL44: ;
    cpy_r_r43 = CPy_CatchError();
    cpy_r_r44 = CPyModule_builtins;
    cpy_r_r45 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r46 = CPyObject_GetAttr(cpy_r_r44, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r47 = CPy_ExceptionMatches(cpy_r_r46);
    CPy_DecRef(cpy_r_r46);
    if (cpy_r_r47) goto CPyL48;
    CPy_Reraise();
    if (!0) {
        goto CPyL49;
    } else
        goto CPyL87;
CPyL47: ;
    CPy_Unreachable();
CPyL48: ;
    CPy_RestoreExcInfo(cpy_r_r43);
    CPy_DecRef(cpy_r_r43.f0);
    CPy_DecRef(cpy_r_r43.f1);
    CPy_DecRef(cpy_r_r43.f2);
    goto CPyL51;
CPyL49: ;
    CPy_RestoreExcInfo(cpy_r_r43);
    CPy_DecRef(cpy_r_r43.f0);
    CPy_DecRef(cpy_r_r43.f1);
    CPy_DecRef(cpy_r_r43.f2);
    cpy_r_r48 = CPy_KeepPropagating();
    if (!cpy_r_r48) goto CPyL82;
    CPy_Unreachable();
CPyL51: ;
    cpy_r_r49 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_fn, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL55;
    }
    if (likely(PyDict_Check(cpy_r_r50)))
        cpy_r_r51 = cpy_r_r50;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 124, CPyStatic_globals, "dict", cpy_r_r50);
        goto CPyL55;
    }
    cpy_r_r52 = PyDict_Copy(cpy_r_r51);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r53 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r54 = PyObject_SetAttr(cpy_r_self, cpy_r_r53, cpy_r_r52);
    CPy_DECREF(cpy_r_r52);
    cpy_r_r55 = cpy_r_r54 >= 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL62;
CPyL55: ;
    cpy_r_r56 = CPy_CatchError();
    cpy_r_r57 = CPyModule_builtins;
    cpy_r_r58 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r59 = CPyObject_GetAttr(cpy_r_r57, cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r60 = CPy_ExceptionMatches(cpy_r_r59);
    CPy_DecRef(cpy_r_r59);
    if (cpy_r_r60) goto CPyL59;
    CPy_Reraise();
    if (!0) {
        goto CPyL60;
    } else
        goto CPyL88;
CPyL58: ;
    CPy_Unreachable();
CPyL59: ;
    CPy_RestoreExcInfo(cpy_r_r56);
    CPy_DecRef(cpy_r_r56.f0);
    CPy_DecRef(cpy_r_r56.f1);
    CPy_DecRef(cpy_r_r56.f2);
    goto CPyL62;
CPyL60: ;
    CPy_RestoreExcInfo(cpy_r_r56);
    CPy_DecRef(cpy_r_r56.f0);
    CPy_DecRef(cpy_r_r56.f1);
    CPy_DecRef(cpy_r_r56.f2);
    cpy_r_r61 = CPy_KeepPropagating();
    if (!cpy_r_r61) goto CPyL82;
    CPy_Unreachable();
CPyL62: ;
    cpy_r_r62 = CPyModule_sys;
    cpy_r_r63 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r64 = CPyObject_GetAttr(cpy_r_r62, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    if (likely(PyTuple_Check(cpy_r_r64)))
        cpy_r_r65 = cpy_r_r64;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 129, CPyStatic_globals, "tuple", cpy_r_r64);
        goto CPyL82;
    }
    cpy_r_r66.f0 = 6;
    cpy_r_r66.f1 = 28;
    cpy_r_r67 = PyTuple_New(2);
    if (unlikely(cpy_r_r67 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp8 = CPyTagged_StealAsObject(cpy_r_r66.f0);
    PyTuple_SET_ITEM(cpy_r_r67, 0, __tmp8);
    PyObject *__tmp9 = CPyTagged_StealAsObject(cpy_r_r66.f1);
    PyTuple_SET_ITEM(cpy_r_r67, 1, __tmp9);
    cpy_r_r68 = PyObject_RichCompare(cpy_r_r65, cpy_r_r67, 0);
    CPy_DECREF(cpy_r_r65);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    if (unlikely(!PyBool_Check(cpy_r_r68))) {
        CPy_TypeError("bool", cpy_r_r68); cpy_r_r69 = 2;
    } else
        cpy_r_r69 = cpy_r_r68 == Py_True;
    CPy_DECREF(cpy_r_r68);
    if (unlikely(cpy_r_r69 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    if (!cpy_r_r69) goto CPyL69;
    PyErr_SetString(PyExc_RuntimeError, "Reached allegedly unreachable code!");
    cpy_r_r70 = 0;
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_Unreachable();
CPyL69: ;
    CPy_INCREF(cpy_r_fn);
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___wrapped__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___wrapped__);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___wrapped__ = cpy_r_fn;
    cpy_r_r71 = 1;
    if (unlikely(!cpy_r_r71)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF(cpy_r_maxsize);
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize = cpy_r_maxsize;
    cpy_r_r72 = 1;
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___typed = cpy_r_typed;
    cpy_r_r73 = 1;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF(cpy_r_ttl);
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl = cpy_r_ttl;
    cpy_r_r74 = 1;
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r75 = CPyStatic_globals;
    cpy_r_r76 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'OrderedDict' */
    cpy_r_r77 = CPyDict_GetItem(cpy_r_r75, cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r78 = PyObject_Vectorcall(cpy_r_r77, 0, 0, 0);
    CPy_DECREF(cpy_r_r77);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    if (likely(PyDict_Check(cpy_r_r78)))
        cpy_r_r79 = cpy_r_r78;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 135, CPyStatic_globals, "dict", cpy_r_r78);
        goto CPyL82;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache = cpy_r_r79;
    cpy_r_r80 = 1;
    if (unlikely(!cpy_r_r80)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___closed = 0;
    cpy_r_r81 = 1;
    if (unlikely(!cpy_r_r81)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits != CPY_INT_TAG) {
        CPyTagged_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits = 0;
    cpy_r_r82 = 1;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses != CPY_INT_TAG) {
        CPyTagged_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses = 0;
    cpy_r_r83 = 1;
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r84 = Py_None;
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___first_loop != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___first_loop);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___first_loop = cpy_r_r84;
    cpy_r_r85 = 1;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    return 1;
CPyL82: ;
    cpy_r_r86 = 2;
    return cpy_r_r86;
CPyL83: ;
    CPy_DecRef(cpy_r_r4.f0);
    CPy_DecRef(cpy_r_r4.f1);
    CPy_DecRef(cpy_r_r4.f2);
    goto CPyL7;
CPyL84: ;
    CPy_DecRef(cpy_r_r13.f0);
    CPy_DecRef(cpy_r_r13.f1);
    CPy_DecRef(cpy_r_r13.f2);
    goto CPyL17;
CPyL85: ;
    CPy_DecRef(cpy_r_r23.f0);
    CPy_DecRef(cpy_r_r23.f1);
    CPy_DecRef(cpy_r_r23.f2);
    goto CPyL27;
CPyL86: ;
    CPy_DecRef(cpy_r_r33.f0);
    CPy_DecRef(cpy_r_r33.f1);
    CPy_DecRef(cpy_r_r33.f2);
    goto CPyL37;
CPyL87: ;
    CPy_DecRef(cpy_r_r43.f0);
    CPy_DecRef(cpy_r_r43.f1);
    CPy_DecRef(cpy_r_r43.f2);
    goto CPyL47;
CPyL88: ;
    CPy_DecRef(cpy_r_r56.f0);
    CPy_DecRef(cpy_r_r56.f1);
    CPy_DecRef(cpy_r_r56.f2);
    goto CPyL58;
}

PyObject *CPyPy__LRUCacheWrapper_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"fn", "maxsize", "typed", "ttl", 0};
    PyObject *obj_fn;
    PyObject *obj_maxsize;
    PyObject *obj_typed;
    PyObject *obj_ttl;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "OOOO", "__init__", kwlist, &obj_fn, &obj_maxsize, &obj_typed, &obj_ttl)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *arg_fn = obj_fn;
    PyObject *arg_maxsize;
    if (PyLong_Check(obj_maxsize))
        arg_maxsize = obj_maxsize;
    else {
        arg_maxsize = NULL;
    }
    if (arg_maxsize != NULL) goto __LL10;
    if (obj_maxsize == Py_None)
        arg_maxsize = obj_maxsize;
    else {
        arg_maxsize = NULL;
    }
    if (arg_maxsize != NULL) goto __LL10;
    CPy_TypeError("int or None", obj_maxsize); 
    goto fail;
__LL10: ;
    char arg_typed;
    if (unlikely(!PyBool_Check(obj_typed))) {
        CPy_TypeError("bool", obj_typed); goto fail;
    } else
        arg_typed = obj_typed == Py_True;
    PyObject *arg_ttl;
    if (CPyFloat_Check(obj_ttl))
        arg_ttl = obj_ttl;
    else {
        arg_ttl = NULL;
    }
    if (arg_ttl != NULL) goto __LL11;
    if (obj_ttl == Py_None)
        arg_ttl = obj_ttl;
    else {
        arg_ttl = NULL;
    }
    if (arg_ttl != NULL) goto __LL11;
    CPy_TypeError("float or None", obj_ttl); 
    goto fail;
__LL11: ;
    char retval = CPyDef__LRUCacheWrapper_____init__(arg_self, arg_fn, arg_maxsize, arg_typed, arg_ttl);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapper_____tasks(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    CPyTagged cpy_r_r2;
    int64_t cpy_r_r3;
    PyObject *cpy_r_r4;
    tuple_T3CIO cpy_r_r5;
    CPyTagged cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    int32_t cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    cpy_r_r0 = PySet_New(NULL);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r1 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__tasks", "_LRUCacheWrapper", "__cache", 147, CPyStatic_globals);
        goto CPyL16;
    }
    CPy_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = 0;
    cpy_r_r3 = PyDict_Size(cpy_r_r1);
    cpy_r_r4 = CPyDict_GetValuesIter(cpy_r_r1);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL17;
    }
CPyL3: ;
    cpy_r_r5 = CPyDict_NextValue(cpy_r_r4, cpy_r_r2);
    cpy_r_r6 = cpy_r_r5.f1;
    cpy_r_r2 = cpy_r_r6;
    cpy_r_r7 = cpy_r_r5.f0;
    if (!cpy_r_r7) goto CPyL18;
    cpy_r_r8 = cpy_r_r5.f2;
    CPy_INCREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r5.f2);
    if (likely(Py_TYPE(cpy_r_r8) == CPyType__CacheItem))
        cpy_r_r9 = cpy_r_r8;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__tasks", 145, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r8);
        goto CPyL19;
    }
    cpy_r_r10 = ((async_lru____CacheItemObject *)cpy_r_r9)->_task;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__tasks", "_CacheItem", "task", 148, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_INCREF(cpy_r_r10);
CPyL6: ;
    cpy_r_r11 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'done' */
    PyObject *cpy_r_r12[1] = {cpy_r_r10};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_VectorcallMethod(cpy_r_r11, cpy_r_r13, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_DECREF(cpy_r_r10);
    if (unlikely(!PyBool_Check(cpy_r_r14))) {
        CPy_TypeError("bool", cpy_r_r14); cpy_r_r15 = 2;
    } else
        cpy_r_r15 = cpy_r_r14 == Py_True;
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r15 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r16 = cpy_r_r15 ^ 1;
    if (!cpy_r_r16) goto CPyL22;
    cpy_r_r17 = ((async_lru____CacheItemObject *)cpy_r_r9)->_task;
    if (unlikely(cpy_r_r17 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'task' of '_CacheItem' undefined");
    } else {
        CPy_INCREF(cpy_r_r17);
    }
    CPy_DECREF_NO_IMM(cpy_r_r9);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL19;
    }
CPyL10: ;
    cpy_r_r18 = PySet_Add(cpy_r_r0, cpy_r_r17);
    CPy_DECREF(cpy_r_r17);
    cpy_r_r19 = cpy_r_r18 >= 0;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL19;
    }
CPyL11: ;
    cpy_r_r20 = CPyDict_CheckSize(cpy_r_r1, cpy_r_r3);
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL19;
    } else
        goto CPyL3;
CPyL12: ;
    cpy_r_r21 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r22 = PySequence_List(cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL15;
    }
    return cpy_r_r22;
CPyL15: ;
    cpy_r_r23 = NULL;
    return cpy_r_r23;
CPyL16: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL15;
CPyL17: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    goto CPyL15;
CPyL18: ;
    CPy_DECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r5.f2);
    goto CPyL12;
CPyL19: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r4);
    goto CPyL15;
CPyL20: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r9);
    goto CPyL15;
CPyL21: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    goto CPyL15;
CPyL22: ;
    CPy_DECREF_NO_IMM(cpy_r_r9);
    goto CPyL11;
}

PyObject *CPyPy__LRUCacheWrapper_____tasks(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__tasks", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef__LRUCacheWrapper_____tasks(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef__LRUCacheWrapper____check_loop(PyObject *cpy_r_self, PyObject *cpy_r_loop) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___first_loop;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_check_loop", "_LRUCacheWrapper", "__first_loop", 153, CPyStatic_globals);
        goto CPyL10;
    }
CPyL1: ;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 == cpy_r_r1;
    if (!cpy_r_r2) goto CPyL3;
    CPy_INCREF(cpy_r_loop);
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___first_loop != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___first_loop);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___first_loop = cpy_r_loop;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("async_lru/__init__.py", "_check_loop", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    } else
        goto CPyL9;
CPyL3: ;
    cpy_r_r4 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___first_loop;
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_check_loop", "_LRUCacheWrapper", "__first_loop", 155, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_INCREF(cpy_r_r4);
CPyL4: ;
    cpy_r_r5 = cpy_r_r4 == cpy_r_loop;
    CPy_DECREF(cpy_r_r4);
    cpy_r_r6 = cpy_r_r5 ^ 1;
    if (!cpy_r_r6) goto CPyL9;
    cpy_r_r7 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('alru_cache is not safe to use across event loops: this '
                                  'cache instance was first used with a different event '
                                  'loop. Use separate cache instances per event loop.') */
    cpy_r_r8 = CPyModule_builtins;
    cpy_r_r9 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'RuntimeError' */
    cpy_r_r10 = CPyObject_GetAttr(cpy_r_r8, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_check_loop", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    PyObject *cpy_r_r11[1] = {cpy_r_r7};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = PyObject_Vectorcall(cpy_r_r10, cpy_r_r12, 1, 0);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_check_loop", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_Raise(cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "_check_loop", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_Unreachable();
CPyL9: ;
    return 1;
CPyL10: ;
    cpy_r_r14 = 2;
    return cpy_r_r14;
}

PyObject *CPyPy__LRUCacheWrapper____check_loop(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"loop", 0};
    static CPyArg_Parser parser = {"O:_check_loop", kwlist, 0};
    PyObject *obj_loop;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_loop)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *arg_loop = obj_loop;
    char retval = CPyDef__LRUCacheWrapper____check_loop(arg_self, arg_loop);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "_check_loop", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef__LRUCacheWrapper___cache_invalidate(PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_kwargs) {
    char cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___typed;
    if (unlikely(cpy_r_r0 == 2)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_invalidate", "_LRUCacheWrapper", "__typed", 163, CPyStatic_globals);
        goto CPyL13;
    }
CPyL1: ;
    cpy_r_r1 = CPyStatic__make_key;
    if (likely(cpy_r_r1 != NULL)) goto CPyL4;
    PyErr_SetString(PyExc_NameError, "value for final name \"_make_key\" was not set");
    cpy_r_r2 = 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r3 = cpy_r_r0 ? Py_True : Py_False;
    PyObject *cpy_r_r4[3] = {cpy_r_args, cpy_r_kwargs, cpy_r_r3};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_Vectorcall(cpy_r_r1, cpy_r_r5, 3, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r7 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_invalidate", "_LRUCacheWrapper", "__cache", 165, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_INCREF(cpy_r_r7);
CPyL6: ;
    cpy_r_r8 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'pop' */
    cpy_r_r9 = Py_None;
    PyObject *cpy_r_r10[3] = {cpy_r_r7, cpy_r_r6, cpy_r_r9};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_VectorcallMethod(cpy_r_r8, cpy_r_r11, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL15;
    }
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r6);
    if (Py_TYPE(cpy_r_r12) == CPyType__CacheItem)
        cpy_r_r13 = cpy_r_r12;
    else {
        cpy_r_r13 = NULL;
    }
    if (cpy_r_r13 != NULL) goto __LL12;
    if (cpy_r_r12 == Py_None)
        cpy_r_r13 = cpy_r_r12;
    else {
        cpy_r_r13 = NULL;
    }
    if (cpy_r_r13 != NULL) goto __LL12;
    CPy_TypeErrorTraceback("async_lru/__init__.py", "cache_invalidate", 165, CPyStatic_globals, "async_lru._CacheItem or None", cpy_r_r12);
    goto CPyL13;
__LL12: ;
    cpy_r_r14 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r15 = cpy_r_r13 == cpy_r_r14;
    if (cpy_r_r15) {
        goto CPyL16;
    } else
        goto CPyL10;
CPyL9: ;
    return 0;
CPyL10: ;
    if (likely(cpy_r_r13 != Py_None))
        cpy_r_r16 = cpy_r_r13;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "cache_invalidate", 169, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r13);
        goto CPyL13;
    }
    cpy_r_r17 = CPyDef__CacheItem___cancel(cpy_r_r16);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    if (unlikely(cpy_r_r17 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL13;
    }
    return 1;
CPyL13: ;
    cpy_r_r18 = 2;
    return cpy_r_r18;
CPyL14: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL13;
CPyL15: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    goto CPyL13;
CPyL16: ;
    CPy_DECREF(cpy_r_r13);
    goto CPyL9;
}

PyObject *CPyPy__LRUCacheWrapper___cache_invalidate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {"%:cache_invalidate", kwlist, 0};
    PyObject *obj_args;
    PyObject *obj_kwargs;
    if (!CPyArg_ParseStackAndKeywords(args, nargs, kwnames, &parser, &obj_args, &obj_kwargs)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *arg_args = obj_args;
    PyObject *arg_kwargs = obj_kwargs;
    char retval = CPyDef__LRUCacheWrapper___cache_invalidate(arg_self, arg_args, arg_kwargs);
    CPy_DECREF(obj_args);
    CPy_DECREF(obj_kwargs);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_DECREF(obj_args);
    CPy_DECREF(obj_kwargs);
    CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef__LRUCacheWrapper___cache_clear(PyObject *cpy_r_self) {
    char cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    int64_t cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3CIO cpy_r_r6;
    CPyTagged cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    int32_t cpy_r_r15;
    char cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    char cpy_r_r28;
    char cpy_r_r29;
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits != CPY_INT_TAG) {
        CPyTagged_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits = 0;
    cpy_r_r0 = 1;
    if (unlikely(!cpy_r_r0)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL20;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses != CPY_INT_TAG) {
        CPyTagged_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses = 0;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r2 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_clear", "_LRUCacheWrapper", "__cache", 176, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_INCREF(cpy_r_r2);
CPyL3: ;
    cpy_r_r3 = 0;
    cpy_r_r4 = PyDict_Size(cpy_r_r2);
    cpy_r_r5 = CPyDict_GetValuesIter(cpy_r_r2);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL21;
    }
CPyL4: ;
    cpy_r_r6 = CPyDict_NextValue(cpy_r_r5, cpy_r_r3);
    cpy_r_r7 = cpy_r_r6.f1;
    cpy_r_r3 = cpy_r_r7;
    cpy_r_r8 = cpy_r_r6.f0;
    if (!cpy_r_r8) goto CPyL22;
    cpy_r_r9 = cpy_r_r6.f2;
    CPy_INCREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r6.f2);
    if (likely(Py_TYPE(cpy_r_r9) == CPyType__CacheItem))
        cpy_r_r10 = cpy_r_r9;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "cache_clear", 176, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r9);
        goto CPyL23;
    }
    cpy_r_r11 = ((async_lru____CacheItemObject *)cpy_r_r10)->_later_call;
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_clear", "_CacheItem", "later_call", 177, CPyStatic_globals);
        goto CPyL24;
    }
    CPy_INCREF(cpy_r_r11);
CPyL7: ;
    cpy_r_r12 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r13 = cpy_r_r11 != cpy_r_r12;
    if (!cpy_r_r13) goto CPyL25;
    cpy_r_r14 = cpy_r_r11;
    cpy_r_r15 = PyObject_IsTrue(cpy_r_r14);
    CPy_DECREF(cpy_r_r14);
    cpy_r_r16 = cpy_r_r15 >= 0;
    if (unlikely(!cpy_r_r16)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r17 = cpy_r_r15;
    if (!cpy_r_r17) goto CPyL26;
    cpy_r_r18 = ((async_lru____CacheItemObject *)cpy_r_r10)->_later_call;
    if (unlikely(cpy_r_r18 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'later_call' of '_CacheItem' undefined");
    } else {
        CPy_INCREF(cpy_r_r18);
    }
    CPy_DECREF_NO_IMM(cpy_r_r10);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL23;
    }
CPyL12: ;
    cpy_r_r19 = cpy_r_r18;
    cpy_r_r20 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cancel' */
    PyObject *cpy_r_r21[1] = {cpy_r_r19};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = PyObject_VectorcallMethod(cpy_r_r20, cpy_r_r22, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r23 != Py_None)) {
        CPy_TypeError("None", cpy_r_r23); cpy_r_r24 = 2;
    } else
        cpy_r_r24 = 1;
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r24 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL23;
    }
CPyL15: ;
    cpy_r_r25 = CPyDict_CheckSize(cpy_r_r2, cpy_r_r4);
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL23;
    } else
        goto CPyL4;
CPyL16: ;
    cpy_r_r26 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r27 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_clear", "_LRUCacheWrapper", "__cache", 179, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_INCREF(cpy_r_r27);
CPyL18: ;
    cpy_r_r28 = CPyDict_Clear(cpy_r_r27);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL20;
    }
    return 1;
CPyL20: ;
    cpy_r_r29 = 2;
    return cpy_r_r29;
CPyL21: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL20;
CPyL22: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL16;
CPyL23: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r5);
    goto CPyL20;
CPyL24: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r10);
    goto CPyL20;
CPyL25: ;
    CPy_DECREF_NO_IMM(cpy_r_r10);
    CPy_DECREF(cpy_r_r11);
    goto CPyL15;
CPyL26: ;
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL15;
CPyL27: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r19);
    goto CPyL20;
}

PyObject *CPyPy__LRUCacheWrapper___cache_clear(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":cache_clear", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    char retval = CPyDef__LRUCacheWrapper___cache_clear(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_cache_close__LRUCacheWrapper_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg, PyObject **cpy_r_stop_iter_ptr) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    int32_t cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    CPyPtr cpy_r_r18;
    int64_t cpy_r_r19;
    CPyTagged cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    char cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    CPyPtr cpy_r_r34;
    int64_t cpy_r_r35;
    int64_t cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    int64_t cpy_r_r39;
    CPyPtr cpy_r_r40;
    CPyPtr cpy_r_r41;
    int64_t cpy_r_r42;
    CPyPtr cpy_r_r43;
    PyObject *cpy_r_r44;
    char cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject **cpy_r_r49;
    PyObject *cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject **cpy_r_r56;
    PyObject *cpy_r_r57;
    int64_t cpy_r_r58;
    int64_t cpy_r_r59;
    char cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    char cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    char cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    char cpy_r_r80;
    PyObject *cpy_r_r81;
    char cpy_r_r82;
    tuple_T3OOO cpy_r_r83;
    char cpy_r_r84;
    PyObject **cpy_r_r85;
    PyObject *cpy_r_r86;
    char cpy_r_r87;
    tuple_T3OOO cpy_r_r88;
    tuple_T3OOO cpy_r_r89;
    tuple_T3OOO cpy_r_r90;
    char cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    char cpy_r_r96;
    char cpy_r_r97;
    char cpy_r_r98;
    char cpy_r_r99;
    PyObject *cpy_r_r100;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__;
    goto CPyL91;
CPyL1: ;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = cpy_r_type != cpy_r_r3;
    if (!cpy_r_r4) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r5 = CPyStatic_get_running_loop;
    if (likely(cpy_r_r5 != NULL)) goto CPyL7;
    PyErr_SetString(PyExc_NameError, "value for final name \"get_running_loop\" was not set");
    cpy_r_r6 = 0;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_Unreachable();
CPyL7: ;
    cpy_r_r7 = PyObject_Vectorcall(cpy_r_r5, 0, 0, 0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop != NULL) {
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop = cpy_r_r7;
    cpy_r_r8 = 1;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r9 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "self", 183, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF_NO_IMM(cpy_r_r9);
CPyL10: ;
    cpy_r_r10 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "loop", 183, CPyStatic_globals);
        goto CPyL96;
    }
    CPy_INCREF(cpy_r_r10);
CPyL11: ;
    cpy_r_r11 = CPyDef__LRUCacheWrapper____check_loop(cpy_r_r9, cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF_NO_IMM(cpy_r_r9);
    if (unlikely(cpy_r_r11 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r12 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "self", 184, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF_NO_IMM(cpy_r_r12);
CPyL13: ;
    ((async_lru____LRUCacheWrapperObject *)cpy_r_r12)->___closed = 1;
    cpy_r_r13 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r12);
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r14 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "self", 186, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF_NO_IMM(cpy_r_r14);
CPyL15: ;
    cpy_r_r15 = CPyDef__LRUCacheWrapper_____tasks(cpy_r_r14);
    CPy_DECREF_NO_IMM(cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
CPyL16: ;
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks != NULL) {
        CPy_DECREF_NO_IMM(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks = cpy_r_r15;
    cpy_r_r16 = 1;
    if (unlikely(!cpy_r_r16)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r17 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks;
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "tasks", 187, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF_NO_IMM(cpy_r_r17);
CPyL18: ;
    cpy_r_r18 = (CPyPtr)&((PyVarObject *)cpy_r_r17)->ob_size;
    cpy_r_r19 = *(int64_t *)cpy_r_r18;
    CPy_DECREF_NO_IMM(cpy_r_r17);
    cpy_r_r20 = cpy_r_r19 << 1;
    cpy_r_r21 = cpy_r_r20 != 0;
    if (cpy_r_r21) goto CPyL24;
    cpy_r_r22 = Py_None;
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL23;
    CPyGen_SetStopIterationValue(cpy_r_r22);
    if (!0) goto CPyL95;
    CPy_Unreachable();
CPyL23: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r22;
    return 0;
CPyL24: ;
    cpy_r_r24 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__wait;
    if (unlikely(cpy_r_r24 == 2)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "wait", 190, CPyStatic_globals);
        goto CPyL95;
    }
CPyL25: ;
    if (cpy_r_r24) goto CPyL49;
CPyL26: ;
    cpy_r_r25 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "self", 191, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF_NO_IMM(cpy_r_r25);
CPyL27: ;
    cpy_r_r26 = PyObject_Str(cpy_r_r25);
    CPy_DECREF_NO_IMM(cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r27 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ' is closed' */
    cpy_r_r28 = CPyStr_Build(2, cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cancel_msg != NULL) {
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cancel_msg);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cancel_msg = cpy_r_r28;
    cpy_r_r29 = 1;
    if (unlikely(!cpy_r_r29)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r30 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks;
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "tasks", 192, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF_NO_IMM(cpy_r_r30);
CPyL31: ;
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0 != NULL) {
        CPy_DECREF_NO_IMM(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0 = cpy_r_r30;
    cpy_r_r31 = 1;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL95;
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1 = 0;
    cpy_r_r32 = 1;
    if (unlikely(!cpy_r_r32)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL95;
    }
CPyL33: ;
    cpy_r_r33 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0;
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__0", 192, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF_NO_IMM(cpy_r_r33);
CPyL34: ;
    cpy_r_r34 = (CPyPtr)&((PyVarObject *)cpy_r_r33)->ob_size;
    cpy_r_r35 = *(int64_t *)cpy_r_r34;
    CPy_DECREF_NO_IMM(cpy_r_r33);
    cpy_r_r36 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1;
    if (unlikely(cpy_r_r36 == -113)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__1", 192, CPyStatic_globals);
        goto CPyL95;
    }
CPyL35: ;
    cpy_r_r37 = cpy_r_r36 < cpy_r_r35;
    if (!cpy_r_r37) goto CPyL49;
    cpy_r_r38 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0;
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__0", 192, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF_NO_IMM(cpy_r_r38);
CPyL37: ;
    cpy_r_r39 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1;
    if (unlikely(cpy_r_r39 == -113)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__1", 192, CPyStatic_globals);
        goto CPyL97;
    }
CPyL38: ;
    cpy_r_r40 = (CPyPtr)&((PyListObject *)cpy_r_r38)->ob_item;
    cpy_r_r41 = *(CPyPtr *)cpy_r_r40;
    cpy_r_r42 = cpy_r_r39 * 8;
    cpy_r_r43 = cpy_r_r41 + cpy_r_r42;
    cpy_r_r44 = *(PyObject * *)cpy_r_r43;
    CPy_INCREF(cpy_r_r44);
    CPy_DECREF_NO_IMM(cpy_r_r38);
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task != NULL) {
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task = cpy_r_r44;
    cpy_r_r45 = 1;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r46 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "task", 193, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF(cpy_r_r46);
CPyL40: ;
    cpy_r_r47 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'done' */
    PyObject *cpy_r_r48[1] = {cpy_r_r46};
    cpy_r_r49 = (PyObject **)&cpy_r_r48;
    cpy_r_r50 = PyObject_VectorcallMethod(cpy_r_r47, cpy_r_r49, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL98;
    }
    CPy_DECREF(cpy_r_r46);
    if (unlikely(!PyBool_Check(cpy_r_r50))) {
        CPy_TypeError("bool", cpy_r_r50); cpy_r_r51 = 2;
    } else
        cpy_r_r51 = cpy_r_r50 == Py_True;
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r51 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    if (cpy_r_r51) goto CPyL47;
    cpy_r_r52 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "task", 194, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF(cpy_r_r52);
CPyL44: ;
    cpy_r_r53 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cancel_msg;
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "cancel_msg", 194, CPyStatic_globals);
        goto CPyL99;
    }
    CPy_INCREF(cpy_r_r53);
CPyL45: ;
    cpy_r_r54 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cancel' */
    PyObject *cpy_r_r55[2] = {cpy_r_r52, cpy_r_r53};
    cpy_r_r56 = (PyObject **)&cpy_r_r55;
    cpy_r_r57 = PyObject_VectorcallMethod(cpy_r_r54, cpy_r_r56, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL100;
    } else
        goto CPyL101;
CPyL46: ;
    CPy_DECREF(cpy_r_r52);
    CPy_DECREF(cpy_r_r53);
CPyL47: ;
    cpy_r_r58 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1;
    if (unlikely(cpy_r_r58 == -113)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__1", 192, CPyStatic_globals);
        goto CPyL95;
    }
CPyL48: ;
    cpy_r_r59 = cpy_r_r58 + 1;
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1 = cpy_r_r59;
    cpy_r_r60 = 1;
    if (unlikely(!cpy_r_r60)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    } else
        goto CPyL33;
CPyL49: ;
    cpy_r_r61 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks;
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "tasks", 196, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF_NO_IMM(cpy_r_r61);
CPyL50: ;
    cpy_r_r62 = CPyStatic_gather;
    if (unlikely(cpy_r_r62 == NULL)) {
        goto CPyL102;
    } else
        goto CPyL53;
CPyL51: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"gather\" was not set");
    cpy_r_r63 = 0;
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_Unreachable();
CPyL53: ;
    cpy_r_r64 = PyList_New(0);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r65 = CPyList_Extend(cpy_r_r64, cpy_r_r61);
    CPy_DECREF_NO_IMM(cpy_r_r61);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL104;
    } else
        goto CPyL105;
CPyL55: ;
    cpy_r_r66 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'return_exceptions' */
    cpy_r_r67 = PyList_AsTuple(cpy_r_r64);
    CPy_DECREF_NO_IMM(cpy_r_r64);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r68 = 1 ? Py_True : Py_False;
    cpy_r_r69 = CPyDict_Build(1, cpy_r_r66, cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL106;
    }
    cpy_r_r70 = PyObject_Call(cpy_r_r62, cpy_r_r67, cpy_r_r69);
    CPy_DECREF(cpy_r_r67);
    CPy_DECREF(cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r71 = CPy_GetCoro(cpy_r_r70);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2 != NULL) {
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2 = cpy_r_r71;
    cpy_r_r72 = 1;
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r73 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2;
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__2", -1, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF(cpy_r_r73);
CPyL61: ;
    cpy_r_r74 = CPyIter_Next(cpy_r_r73);
    CPy_DECREF(cpy_r_r73);
    if (cpy_r_r74 != NULL) goto CPyL64;
    cpy_r_r75 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r76 = cpy_r_r75;
    CPy_DECREF(cpy_r_r76);
    cpy_r_r77 = NULL;
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2 != NULL) {
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2 = cpy_r_r77;
    cpy_r_r78 = 1;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    } else
        goto CPyL86;
CPyL64: ;
    cpy_r_r79 = cpy_r_r74;
CPyL65: ;
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 1;
    return cpy_r_r79;
CPyL66: ;
    cpy_r_r81 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r82 = cpy_r_type != cpy_r_r81;
    if (!cpy_r_r82) goto CPyL107;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL70;
    } else
        goto CPyL108;
CPyL68: ;
    CPy_Unreachable();
CPyL69: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL81;
CPyL70: ;
    cpy_r_r83 = CPy_CatchError();
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3.f0 != NULL) {
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3.f0);
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3.f1);
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3.f2);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3 = cpy_r_r83;
    cpy_r_r84 = 1;
    if (unlikely(!cpy_r_r84)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL109;
    }
    cpy_r_r85 = (PyObject **)&cpy_r_r1;
    cpy_r_r86 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2;
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__2", -1, CPyStatic_globals);
        goto CPyL109;
    }
    CPy_INCREF(cpy_r_r86);
CPyL72: ;
    cpy_r_r87 = CPy_YieldFromErrorHandle(cpy_r_r86, cpy_r_r85);
    CPy_DecRef(cpy_r_r86);
    if (unlikely(cpy_r_r87 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL109;
    }
    if (cpy_r_r87) goto CPyL76;
    cpy_r_r79 = cpy_r_r1;
    cpy_r_r88 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3;
    if (unlikely(cpy_r_r88.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL110;
    }
    CPy_INCREF(cpy_r_r88.f0);
    CPy_INCREF(cpy_r_r88.f1);
    CPy_INCREF(cpy_r_r88.f2);
CPyL75: ;
    CPy_RestoreExcInfo(cpy_r_r88);
    CPy_DecRef(cpy_r_r88.f0);
    CPy_DecRef(cpy_r_r88.f1);
    CPy_DecRef(cpy_r_r88.f2);
    goto CPyL65;
CPyL76: ;
    cpy_r_r76 = cpy_r_r1;
    CPy_DecRef(cpy_r_r76);
    cpy_r_r89 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3;
    if (unlikely(cpy_r_r89.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_INCREF(cpy_r_r89.f0);
    CPy_INCREF(cpy_r_r89.f1);
    CPy_INCREF(cpy_r_r89.f2);
CPyL77: ;
    CPy_RestoreExcInfo(cpy_r_r89);
    CPy_DecRef(cpy_r_r89.f0);
    CPy_DecRef(cpy_r_r89.f1);
    CPy_DecRef(cpy_r_r89.f2);
    goto CPyL86;
CPyL78: ;
    cpy_r_r90 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3;
    if (unlikely(cpy_r_r90.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF(cpy_r_r90.f0);
    CPy_INCREF(cpy_r_r90.f1);
    CPy_INCREF(cpy_r_r90.f2);
CPyL79: ;
    CPy_RestoreExcInfo(cpy_r_r90);
    CPy_DecRef(cpy_r_r90.f0);
    CPy_DecRef(cpy_r_r90.f1);
    CPy_DecRef(cpy_r_r90.f2);
    cpy_r_r91 = CPy_KeepPropagating();
    if (!cpy_r_r91) goto CPyL95;
    CPy_Unreachable();
CPyL81: ;
    cpy_r_r92 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2;
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__2", -1, CPyStatic_globals);
        goto CPyL111;
    }
    CPy_INCREF(cpy_r_r92);
CPyL82: ;
    cpy_r_r93 = CPyIter_Send(cpy_r_r92, cpy_r_arg);
    CPy_DECREF(cpy_r_r92);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r93 == NULL) goto CPyL84;
    cpy_r_r79 = cpy_r_r93;
    goto CPyL65;
CPyL84: ;
    cpy_r_r94 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r76 = cpy_r_r94;
    CPy_DECREF(cpy_r_r76);
CPyL86: ;
    cpy_r_r95 = Py_None;
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL90;
    CPyGen_SetStopIterationValue(cpy_r_r95);
    if (!0) goto CPyL95;
    CPy_Unreachable();
CPyL90: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r95;
    return 0;
CPyL91: ;
    cpy_r_r97 = cpy_r_r2 == 0;
    if (cpy_r_r97) goto CPyL112;
    cpy_r_r98 = cpy_r_r2 == 1;
    if (cpy_r_r98) {
        goto CPyL66;
    } else
        goto CPyL113;
CPyL93: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r99 = 0;
    if (unlikely(!cpy_r_r99)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_Unreachable();
CPyL95: ;
    cpy_r_r100 = NULL;
    return cpy_r_r100;
CPyL96: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL95;
CPyL97: ;
    CPy_DecRef(cpy_r_r38);
    goto CPyL95;
CPyL98: ;
    CPy_DecRef(cpy_r_r46);
    goto CPyL95;
CPyL99: ;
    CPy_DecRef(cpy_r_r52);
    goto CPyL95;
CPyL100: ;
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r53);
    goto CPyL95;
CPyL101: ;
    CPy_DECREF(cpy_r_r57);
    goto CPyL46;
CPyL102: ;
    CPy_DecRef(cpy_r_r61);
    goto CPyL51;
CPyL103: ;
    CPy_DecRef(cpy_r_r61);
    goto CPyL95;
CPyL104: ;
    CPy_DecRef(cpy_r_r64);
    goto CPyL95;
CPyL105: ;
    CPy_DECREF(cpy_r_r65);
    goto CPyL55;
CPyL106: ;
    CPy_DecRef(cpy_r_r67);
    goto CPyL95;
CPyL107: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL69;
CPyL108: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL68;
CPyL109: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL78;
CPyL110: ;
    CPy_DecRef(cpy_r_r79);
    goto CPyL78;
CPyL111: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL95;
CPyL112: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL1;
CPyL113: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL93;
}

PyObject *CPyDef_cache_close__LRUCacheWrapper_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_cache_close__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0, 0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_cache_close__LRUCacheWrapper_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_cache_close__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.cache_close__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapper_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_cache_close__LRUCacheWrapper_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_cache_close__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg, 0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_cache_close__LRUCacheWrapper_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_cache_close__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.cache_close__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapper_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_cache_close__LRUCacheWrapper_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_cache_close__LRUCacheWrapper_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_cache_close__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.cache_close__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapper_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_cache_close__LRUCacheWrapper_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef_cache_close__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0, 0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy_cache_close__LRUCacheWrapper_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_cache_close__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.cache_close__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapper_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_cache_close__LRUCacheWrapper_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_cache_close__LRUCacheWrapper_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp13 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp13);
    PyObject *__tmp14 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp14);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy_cache_close__LRUCacheWrapper_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_cache_close__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.cache_close__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapper_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_cache_close__LRUCacheWrapper_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_cache_close__LRUCacheWrapper_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_cache_close__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.cache_close__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapper_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__await__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapper___cache_close(PyObject *cpy_r_self, char cpy_r_wait) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    if (cpy_r_wait != 2) goto CPyL2;
    cpy_r_wait = 0;
CPyL2: ;
    cpy_r_r0 = CPyDef_cache_close__LRUCacheWrapper_gen();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    CPy_INCREF_NO_IMM(cpy_r_self);
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self != NULL) {
        CPy_DECREF_NO_IMM(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self = cpy_r_self;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL7;
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__wait = cpy_r_wait;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL7;
    }
    return cpy_r_r0;
CPyL6: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
CPyL7: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL6;
}

PyObject *CPyPy__LRUCacheWrapper___cache_close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"wait", 0};
    static CPyArg_Parser parser = {"|$O:cache_close", kwlist, 0};
    PyObject *obj_wait = NULL;
    if (!CPyArg_ParseStackAndKeywords(args, nargs, kwnames, &parser, &obj_wait)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    char arg_wait;
    if (obj_wait == NULL) {
        arg_wait = 2;
    } else if (unlikely(!PyBool_Check(obj_wait))) {
        CPy_TypeError("bool", obj_wait); goto fail;
    } else
        arg_wait = obj_wait == Py_True;
    PyObject *retval = CPyDef__LRUCacheWrapper___cache_close(arg_self, arg_wait);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapper___cache_info(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    int64_t cpy_r_r4;
    CPyTagged cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_info", "_LRUCacheWrapper", "__hits", 200, CPyStatic_globals);
        goto CPyL10;
    }
    CPyTagged_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_info", "_LRUCacheWrapper", "__misses", 201, CPyStatic_globals);
        goto CPyL11;
    }
    CPyTagged_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_info", "_LRUCacheWrapper", "__maxsize", 202, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_INCREF(cpy_r_r2);
CPyL3: ;
    cpy_r_r3 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_info", "_LRUCacheWrapper", "__cache", 203, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_INCREF(cpy_r_r3);
CPyL4: ;
    cpy_r_r4 = PyDict_Size(cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    cpy_r_r5 = cpy_r_r4 << 1;
    cpy_r_r6 = CPyStatic__CacheInfo;
    if (unlikely(cpy_r_r6 == NULL)) {
        goto CPyL14;
    } else
        goto CPyL7;
CPyL5: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_CacheInfo\" was not set");
    cpy_r_r7 = 0;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_info", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_Unreachable();
CPyL7: ;
    cpy_r_r8 = CPyTagged_StealAsObject(cpy_r_r0);
    cpy_r_r9 = CPyTagged_StealAsObject(cpy_r_r1);
    cpy_r_r10 = CPyTagged_StealAsObject(cpy_r_r5);
    PyObject *cpy_r_r11[4] = {cpy_r_r8, cpy_r_r9, cpy_r_r2, cpy_r_r10};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = PyObject_Vectorcall(cpy_r_r6, cpy_r_r12, 4, 0);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_info", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL15;
    }
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r10);
    if (likely(PyTuple_Check(cpy_r_r13)))
        cpy_r_r14 = cpy_r_r13;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "cache_info", 199, CPyStatic_globals, "tuple", cpy_r_r13);
        goto CPyL10;
    }
    return cpy_r_r14;
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPyTagged_DecRef(cpy_r_r0);
    goto CPyL10;
CPyL12: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r1);
    goto CPyL10;
CPyL13: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL10;
CPyL14: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL5;
CPyL15: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    goto CPyL10;
}

PyObject *CPyPy__LRUCacheWrapper___cache_info(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":cache_info", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef__LRUCacheWrapper___cache_info(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "cache_info", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapper___cache_parameters(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyPtr cpy_r_r3;
    int64_t cpy_r_r4;
    CPyTagged cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_parameters", "_LRUCacheWrapper", "__maxsize", 208, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___typed;
    if (unlikely(cpy_r_r1 == 2)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_parameters", "_LRUCacheWrapper", "__typed", 209, CPyStatic_globals);
        goto CPyL9;
    }
CPyL2: ;
    cpy_r_r2 = CPyDef__LRUCacheWrapper_____tasks(cpy_r_self);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_parameters", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL9;
    }
CPyL3: ;
    cpy_r_r3 = (CPyPtr)&((PyVarObject *)cpy_r_r2)->ob_size;
    cpy_r_r4 = *(int64_t *)cpy_r_r3;
    CPy_DECREF_NO_IMM(cpy_r_r2);
    cpy_r_r5 = cpy_r_r4 << 1;
    cpy_r_r6 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___closed;
    if (unlikely(cpy_r_r6 == 2)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_parameters", "_LRUCacheWrapper", "__closed", 211, CPyStatic_globals);
        goto CPyL9;
    }
CPyL4: ;
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheParameters' */
    cpy_r_r9 = CPyDict_GetItem(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_parameters", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r10 = cpy_r_r1 ? Py_True : Py_False;
    cpy_r_r11 = CPyTagged_StealAsObject(cpy_r_r5);
    cpy_r_r12 = cpy_r_r6 ? Py_True : Py_False;
    PyObject *cpy_r_r13[4] = {cpy_r_r0, cpy_r_r10, cpy_r_r11, cpy_r_r12};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('maxsize', 'typed', 'tasks', 'closed') */
    cpy_r_r16 = PyObject_Vectorcall(cpy_r_r9, cpy_r_r14, 0, cpy_r_r15);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_parameters", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r11);
    if (likely(PyDict_Check(cpy_r_r16)))
        cpy_r_r17 = cpy_r_r16;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "cache_parameters", 207, CPyStatic_globals, "dict", cpy_r_r16);
        goto CPyL8;
    }
    return cpy_r_r17;
CPyL8: ;
    cpy_r_r18 = NULL;
    return cpy_r_r18;
CPyL9: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL8;
CPyL10: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r11);
    goto CPyL8;
}

PyObject *CPyPy__LRUCacheWrapper___cache_parameters(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":cache_parameters", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef__LRUCacheWrapper___cache_parameters(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "cache_parameters", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef__LRUCacheWrapper____cache_hit(PyObject *cpy_r_self, PyObject *cpy_r_key) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("async_lru/__init__.py", "_cache_hit", "_LRUCacheWrapper", "__hits", 215, CPyStatic_globals);
        goto CPyL5;
    }
CPyL1: ;
    cpy_r_r1 = CPyTagged_Add(cpy_r_r0, 2);
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits != CPY_INT_TAG) {
        CPyTagged_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits = cpy_r_r1;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("async_lru/__init__.py", "_cache_hit", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r3 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_cache_hit", "_LRUCacheWrapper", "__cache", 216, CPyStatic_globals);
        goto CPyL5;
    }
    CPy_INCREF(cpy_r_r3);
CPyL3: ;
    cpy_r_r4 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'move_to_end' */
    PyObject *cpy_r_r5[2] = {cpy_r_r3, cpy_r_key};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = PyObject_VectorcallMethod(cpy_r_r4, cpy_r_r6, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_cache_hit", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    } else
        goto CPyL7;
CPyL4: ;
    CPy_DECREF(cpy_r_r3);
    return 1;
CPyL5: ;
    cpy_r_r8 = 2;
    return cpy_r_r8;
CPyL6: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL5;
CPyL7: ;
    CPy_DECREF(cpy_r_r7);
    goto CPyL4;
}

PyObject *CPyPy__LRUCacheWrapper____cache_hit(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"key", 0};
    static CPyArg_Parser parser = {"O:_cache_hit", kwlist, 0};
    PyObject *obj_key;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_key)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *arg_key = obj_key;
    char retval = CPyDef__LRUCacheWrapper____cache_hit(arg_self, arg_key);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "_cache_hit", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef__LRUCacheWrapper____cache_miss(PyObject *cpy_r_self, PyObject *cpy_r_key) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("async_lru/__init__.py", "_cache_miss", "_LRUCacheWrapper", "__misses", 219, CPyStatic_globals);
        goto CPyL3;
    }
CPyL1: ;
    cpy_r_r1 = CPyTagged_Add(cpy_r_r0, 2);
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses != CPY_INT_TAG) {
        CPyTagged_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses = cpy_r_r1;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("async_lru/__init__.py", "_cache_miss", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL3;
    }
    return 1;
CPyL3: ;
    cpy_r_r3 = 2;
    return cpy_r_r3;
}

PyObject *CPyPy__LRUCacheWrapper____cache_miss(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"key", 0};
    static CPyArg_Parser parser = {"O:_cache_miss", kwlist, 0};
    PyObject *obj_key;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_key)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *arg_key = obj_key;
    char retval = CPyDef__LRUCacheWrapper____cache_miss(arg_self, arg_key);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "_cache_miss", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef__LRUCacheWrapper____task_done_callback(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_task) {
    PyObject *cpy_r_r0;
    PyObject **cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    double cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject **cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    char cpy_r_r39;
    char cpy_r_r40;
    cpy_r_r0 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cancelled' */
    PyObject *cpy_r_r1[1] = {cpy_r_task};
    cpy_r_r2 = (PyObject **)&cpy_r_r1;
    cpy_r_r3 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r2, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL24;
    }
    if (unlikely(!PyBool_Check(cpy_r_r3))) {
        CPy_TypeError("bool", cpy_r_r3); cpy_r_r4 = 2;
    } else
        cpy_r_r4 = cpy_r_r3 == Py_True;
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL24;
    }
    if (cpy_r_r4) goto CPyL5;
    cpy_r_r5 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_exception' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_task, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r7 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r8 = cpy_r_r6 != cpy_r_r7;
    CPy_DECREF(cpy_r_r6);
    if (!cpy_r_r8) goto CPyL8;
CPyL5: ;
    cpy_r_r9 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__cache", 226, CPyStatic_globals);
        goto CPyL24;
    }
    CPy_INCREF(cpy_r_r9);
CPyL6: ;
    cpy_r_r10 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'pop' */
    cpy_r_r11 = Py_None;
    PyObject *cpy_r_r12[3] = {cpy_r_r9, cpy_r_key, cpy_r_r11};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_VectorcallMethod(cpy_r_r10, cpy_r_r13, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL25;
    } else
        goto CPyL26;
CPyL7: ;
    CPy_DECREF(cpy_r_r9);
    return 1;
CPyL8: ;
    cpy_r_r15 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__cache", 229, CPyStatic_globals);
        goto CPyL24;
    }
    CPy_INCREF(cpy_r_r15);
CPyL9: ;
    cpy_r_r16 = CPyDict_GetWithNone(cpy_r_r15, cpy_r_key);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL27;
    }
    if (Py_TYPE(cpy_r_r16) == CPyType__CacheItem)
        cpy_r_r17 = cpy_r_r16;
    else {
        cpy_r_r17 = NULL;
    }
    if (cpy_r_r17 != NULL) goto __LL15;
    if (cpy_r_r16 == Py_None)
        cpy_r_r17 = cpy_r_r16;
    else {
        cpy_r_r17 = NULL;
    }
    if (cpy_r_r17 != NULL) goto __LL15;
    CPy_TypeErrorTraceback("async_lru/__init__.py", "_task_done_callback", 230, CPyStatic_globals, "async_lru._CacheItem or None", cpy_r_r16);
    goto CPyL27;
__LL15: ;
    cpy_r_r18 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl;
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__ttl", 231, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_INCREF(cpy_r_r18);
CPyL12: ;
    cpy_r_r19 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r20 = cpy_r_r18 != cpy_r_r19;
    if (!cpy_r_r20) goto CPyL29;
    cpy_r_r21 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r22 = cpy_r_r17 != cpy_r_r21;
    if (!cpy_r_r22) goto CPyL29;
    cpy_r_r23 = CPyModule_asyncio;
    cpy_r_r24 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'get_running_loop' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r26 = PyObject_Vectorcall(cpy_r_r25, 0, 0, 0);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r27 = PyFloat_AsDouble(cpy_r_r18);
    if (cpy_r_r27 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r18); cpy_r_r27 = -113.0;
    }
    CPy_DECREF(cpy_r_r18);
    cpy_r_r28 = cpy_r_r27 == -113.0;
    if (unlikely(cpy_r_r28)) goto CPyL18;
CPyL17: ;
    cpy_r_r29 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'pop' */
    cpy_r_r30 = CPyObject_GetAttr(cpy_r_r15, cpy_r_r29);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL31;
    } else
        goto CPyL19;
CPyL18: ;
    cpy_r_r31 = PyErr_Occurred();
    if (unlikely(cpy_r_r31 != NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    } else
        goto CPyL17;
CPyL19: ;
    cpy_r_r32 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'call_later' */
    cpy_r_r33 = PyFloat_FromDouble(cpy_r_r27);
    cpy_r_r34 = Py_None;
    PyObject *cpy_r_r35[5] = {cpy_r_r26, cpy_r_r33, cpy_r_r30, cpy_r_key, cpy_r_r34};
    cpy_r_r36 = (PyObject **)&cpy_r_r35;
    cpy_r_r37 = PyObject_VectorcallMethod(cpy_r_r32, cpy_r_r36, 9223372036854775813ULL, 0);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL33;
    }
    CPy_DECREF(cpy_r_r26);
    CPy_DECREF(cpy_r_r33);
    CPy_DECREF(cpy_r_r30);
    if (likely(cpy_r_r17 != Py_None))
        cpy_r_r38 = cpy_r_r17;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "_task_done_callback", 234, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r17);
        goto CPyL34;
    }
    if (((async_lru____CacheItemObject *)cpy_r_r38)->_later_call != NULL) {
        CPy_DECREF(((async_lru____CacheItemObject *)cpy_r_r38)->_later_call);
    }
    ((async_lru____CacheItemObject *)cpy_r_r38)->_later_call = cpy_r_r37;
    cpy_r_r39 = 1;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL35;
    }
    CPy_DECREF(cpy_r_r17);
CPyL23: ;
    return 1;
CPyL24: ;
    cpy_r_r40 = 2;
    return cpy_r_r40;
CPyL25: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL24;
CPyL26: ;
    CPy_DECREF(cpy_r_r14);
    goto CPyL7;
CPyL27: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL24;
CPyL28: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r17);
    goto CPyL24;
CPyL29: ;
    CPy_DECREF(cpy_r_r15);
    CPy_DECREF(cpy_r_r17);
    CPy_DECREF(cpy_r_r18);
    goto CPyL23;
CPyL30: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r18);
    goto CPyL24;
CPyL31: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r26);
    goto CPyL24;
CPyL32: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r26);
    goto CPyL24;
CPyL33: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r26);
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r33);
    goto CPyL24;
CPyL34: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r37);
    goto CPyL24;
CPyL35: ;
    CPy_DecRef(cpy_r_r17);
    goto CPyL24;
}

PyObject *CPyPy__LRUCacheWrapper____task_done_callback(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"key", "task", 0};
    static CPyArg_Parser parser = {"OO:_task_done_callback", kwlist, 0};
    PyObject *obj_key;
    PyObject *obj_task;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_key, &obj_task)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *arg_key = obj_key;
    PyObject *arg_task = obj_task;
    char retval = CPyDef__LRUCacheWrapper____task_done_callback(arg_self, arg_key, arg_task);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg, PyObject **cpy_r_stop_iter_ptr) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    int32_t cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    tuple_T3OOO cpy_r_r27;
    char cpy_r_r28;
    PyObject **cpy_r_r29;
    PyObject *cpy_r_r30;
    char cpy_r_r31;
    tuple_T3OOO cpy_r_r32;
    tuple_T3OOO cpy_r_r33;
    tuple_T3OOO cpy_r_r34;
    char cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    char cpy_r_r39;
    tuple_T3OOO cpy_r_r40;
    char cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    char cpy_r_r45;
    PyObject *cpy_r_r46;
    CPyTagged cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject **cpy_r_r52;
    PyObject *cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject **cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject **cpy_r_r73;
    PyObject *cpy_r_r74;
    tuple_T3OOO cpy_r_r75;
    char cpy_r_r76;
    tuple_T3OOO cpy_r_r77;
    tuple_T3OOO cpy_r_r78;
    PyObject *cpy_r_r79;
    char cpy_r_r80;
    tuple_T3OOO cpy_r_r81;
    PyObject *cpy_r_r82;
    CPyTagged cpy_r_r83;
    CPyTagged cpy_r_r84;
    char cpy_r_r85;
    PyObject *cpy_r_r86;
    char cpy_r_r87;
    char cpy_r_r88;
    PyObject *cpy_r_r89;
    char cpy_r_r90;
    char cpy_r_r91;
    char cpy_r_r92;
    char cpy_r_r93;
    PyObject *cpy_r_r94;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__;
    goto CPyL92;
CPyL1: ;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = cpy_r_type != cpy_r_r3;
    if (!cpy_r_r4) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL96;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r5 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "cache_item", 241, CPyStatic_globals);
        goto CPyL96;
    }
    CPy_INCREF_NO_IMM(cpy_r_r5);
CPyL5: ;
    cpy_r_r6 = ((async_lru____CacheItemObject *)cpy_r_r5)->_task;
    if (unlikely(cpy_r_r6 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'task' of '_CacheItem' undefined");
    } else {
        CPy_INCREF(cpy_r_r6);
    }
    CPy_DECREF_NO_IMM(cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL96;
    }
CPyL6: ;
    if (((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task != NULL) {
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task);
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task = cpy_r_r6;
    cpy_r_r7 = 1;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r8 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "task", 244, CPyStatic_globals);
        goto CPyL39;
    }
    CPy_INCREF(cpy_r_r8);
CPyL8: ;
    cpy_r_r9 = CPyModule_asyncio;
    cpy_r_r10 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'shield' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL97;
    }
    PyObject *cpy_r_r12[1] = {cpy_r_r8};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_Vectorcall(cpy_r_r11, cpy_r_r13, 1, 0);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL97;
    }
    CPy_DECREF(cpy_r_r8);
    cpy_r_r15 = CPy_GetCoro(cpy_r_r14);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    }
    if (((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4 != NULL) {
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4);
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4 = cpy_r_r15;
    cpy_r_r16 = 1;
    if (unlikely(!cpy_r_r16)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", -1, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r17 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4;
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL39;
    }
    CPy_INCREF(cpy_r_r17);
CPyL13: ;
    cpy_r_r18 = CPyIter_Next(cpy_r_r17);
    CPy_DECREF(cpy_r_r17);
    if (cpy_r_r18 != NULL) goto CPyL16;
    cpy_r_r19 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r20 = cpy_r_r19;
    cpy_r_r21 = NULL;
    if (((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4 != NULL) {
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4);
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4 = cpy_r_r21;
    cpy_r_r22 = 1;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL98;
    } else
        goto CPyL38;
CPyL16: ;
    cpy_r_r23 = cpy_r_r18;
CPyL17: ;
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 1;
    return cpy_r_r23;
CPyL18: ;
    cpy_r_r25 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r26 = cpy_r_type != cpy_r_r25;
    if (!cpy_r_r26) goto CPyL99;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL22;
    } else
        goto CPyL100;
CPyL20: ;
    CPy_Unreachable();
CPyL21: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL33;
CPyL22: ;
    cpy_r_r27 = CPy_CatchError();
    if (((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5.f0 != NULL) {
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5.f0);
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5.f1);
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5.f2);
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5 = cpy_r_r27;
    cpy_r_r28 = 1;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", -1, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r29 = (PyObject **)&cpy_r_r1;
    cpy_r_r30 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4;
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL101;
    }
    CPy_INCREF(cpy_r_r30);
CPyL24: ;
    cpy_r_r31 = CPy_YieldFromErrorHandle(cpy_r_r30, cpy_r_r29);
    CPy_DecRef(cpy_r_r30);
    if (unlikely(cpy_r_r31 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL101;
    }
    if (cpy_r_r31) goto CPyL28;
    cpy_r_r23 = cpy_r_r1;
    cpy_r_r32 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5;
    if (unlikely(cpy_r_r32.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL102;
    }
    CPy_INCREF(cpy_r_r32.f0);
    CPy_INCREF(cpy_r_r32.f1);
    CPy_INCREF(cpy_r_r32.f2);
CPyL27: ;
    CPy_RestoreExcInfo(cpy_r_r32);
    CPy_DecRef(cpy_r_r32.f0);
    CPy_DecRef(cpy_r_r32.f1);
    CPy_DecRef(cpy_r_r32.f2);
    goto CPyL17;
CPyL28: ;
    cpy_r_r20 = cpy_r_r1;
    cpy_r_r33 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5;
    if (unlikely(cpy_r_r33.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL103;
    }
    CPy_INCREF(cpy_r_r33.f0);
    CPy_INCREF(cpy_r_r33.f1);
    CPy_INCREF(cpy_r_r33.f2);
CPyL29: ;
    CPy_RestoreExcInfo(cpy_r_r33);
    CPy_DecRef(cpy_r_r33.f0);
    CPy_DecRef(cpy_r_r33.f1);
    CPy_DecRef(cpy_r_r33.f2);
    goto CPyL38;
CPyL30: ;
    cpy_r_r34 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5;
    if (unlikely(cpy_r_r34.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL39;
    }
    CPy_INCREF(cpy_r_r34.f0);
    CPy_INCREF(cpy_r_r34.f1);
    CPy_INCREF(cpy_r_r34.f2);
CPyL31: ;
    CPy_RestoreExcInfo(cpy_r_r34);
    CPy_DecRef(cpy_r_r34.f0);
    CPy_DecRef(cpy_r_r34.f1);
    CPy_DecRef(cpy_r_r34.f2);
    cpy_r_r35 = CPy_KeepPropagating();
    if (!cpy_r_r35) goto CPyL39;
    CPy_Unreachable();
CPyL33: ;
    cpy_r_r36 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4;
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL104;
    }
    CPy_INCREF(cpy_r_r36);
CPyL34: ;
    cpy_r_r37 = CPyIter_Send(cpy_r_r36, cpy_r_arg);
    CPy_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r37 == NULL) goto CPyL36;
    cpy_r_r23 = cpy_r_r37;
    goto CPyL17;
CPyL36: ;
    cpy_r_r38 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r20 = cpy_r_r38;
CPyL38: ;
    if (((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6 != NULL) {
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6);
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6 = cpy_r_r20;
    cpy_r_r39 = 1;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL68;
CPyL39: ;
    cpy_r_r40 = CPy_CatchError();
    if (((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7.f0 != NULL) {
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7.f0);
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7.f1);
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7.f2);
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7 = cpy_r_r40;
    cpy_r_r41 = 1;
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", -1, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r42 = CPyModule_asyncio;
    cpy_r_r43 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'CancelledError' */
    cpy_r_r44 = CPyObject_GetAttr(cpy_r_r42, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r45 = CPy_ExceptionMatches(cpy_r_r44);
    CPy_DecRef(cpy_r_r44);
    if (!cpy_r_r45) goto CPyL63;
    cpy_r_r46 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "cache_item", 248, CPyStatic_globals);
        goto CPyL65;
    }
    CPy_INCREF_NO_IMM(cpy_r_r46);
CPyL43: ;
    cpy_r_r47 = ((async_lru____CacheItemObject *)cpy_r_r46)->_waiters;
    if (unlikely(cpy_r_r47 == CPY_INT_TAG)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_CacheItem", "waiters", 248, CPyStatic_globals);
        goto CPyL105;
    }
CPyL44: ;
    cpy_r_r48 = cpy_r_r47 == 2;
    CPy_DecRef(cpy_r_r46);
    if (!cpy_r_r48) goto CPyL61;
    cpy_r_r49 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "task", 248, CPyStatic_globals);
        goto CPyL65;
    }
    CPy_INCREF(cpy_r_r49);
CPyL46: ;
    cpy_r_r50 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'done' */
    PyObject *cpy_r_r51[1] = {cpy_r_r49};
    cpy_r_r52 = (PyObject **)&cpy_r_r51;
    cpy_r_r53 = PyObject_VectorcallMethod(cpy_r_r50, cpy_r_r52, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL106;
    }
    CPy_DecRef(cpy_r_r49);
    if (unlikely(!PyBool_Check(cpy_r_r53))) {
        CPy_TypeError("bool", cpy_r_r53); cpy_r_r54 = 2;
    } else
        cpy_r_r54 = cpy_r_r53 == Py_True;
    CPy_DecRef(cpy_r_r53);
    if (unlikely(cpy_r_r54 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL65;
    }
    if (cpy_r_r54) goto CPyL61;
    cpy_r_r55 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "cache_item", 249, CPyStatic_globals);
        goto CPyL65;
    }
    CPy_INCREF_NO_IMM(cpy_r_r55);
CPyL50: ;
    cpy_r_r56 = CPyDef__CacheItem___cancel(cpy_r_r55);
    CPy_DecRef(cpy_r_r55);
    if (unlikely(cpy_r_r56 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r57 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "task", 250, CPyStatic_globals);
        goto CPyL65;
    }
    CPy_INCREF(cpy_r_r57);
CPyL52: ;
    cpy_r_r58 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'alru_cache ' */
    cpy_r_r59 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "task", 250, CPyStatic_globals);
        goto CPyL107;
    }
    CPy_INCREF(cpy_r_r59);
CPyL53: ;
    cpy_r_r60 = PyObject_Str(cpy_r_r59);
    CPy_DecRef(cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL107;
    }
    cpy_r_r61 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ' has no more waiters' */
    cpy_r_r62 = CPyStr_Build(3, cpy_r_r58, cpy_r_r60, cpy_r_r61);
    CPy_DecRef(cpy_r_r60);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL107;
    }
    cpy_r_r63 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cancel' */
    PyObject *cpy_r_r64[2] = {cpy_r_r57, cpy_r_r62};
    cpy_r_r65 = (PyObject **)&cpy_r_r64;
    cpy_r_r66 = PyObject_VectorcallMethod(cpy_r_r63, cpy_r_r65, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL108;
    } else
        goto CPyL109;
CPyL56: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r62);
    cpy_r_r67 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "self", 251, CPyStatic_globals);
        goto CPyL65;
    }
    CPy_INCREF_NO_IMM(cpy_r_r67);
CPyL57: ;
    cpy_r_r68 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r67)->___cache;
    if (unlikely(cpy_r_r68 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__cache' of '_LRUCacheWrapper' undefined");
    } else {
        CPy_INCREF(cpy_r_r68);
    }
    CPy_DecRef(cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL65;
    }
CPyL58: ;
    cpy_r_r69 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "key", 251, CPyStatic_globals);
        goto CPyL110;
    }
    CPy_INCREF(cpy_r_r69);
CPyL59: ;
    cpy_r_r70 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'pop' */
    cpy_r_r71 = Py_None;
    PyObject *cpy_r_r72[3] = {cpy_r_r68, cpy_r_r69, cpy_r_r71};
    cpy_r_r73 = (PyObject **)&cpy_r_r72;
    cpy_r_r74 = PyObject_VectorcallMethod(cpy_r_r70, cpy_r_r73, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL111;
    } else
        goto CPyL112;
CPyL60: ;
    CPy_DecRef(cpy_r_r68);
    CPy_DecRef(cpy_r_r69);
CPyL61: ;
    CPy_Reraise();
    if (!0) goto CPyL65;
    CPy_Unreachable();
CPyL63: ;
    CPy_Reraise();
    if (!0) goto CPyL65;
    CPy_Unreachable();
CPyL65: ;
    cpy_r_r75 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7;
    if (unlikely(cpy_r_r75.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__7", -1, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_INCREF(cpy_r_r75.f0);
    CPy_INCREF(cpy_r_r75.f1);
    CPy_INCREF(cpy_r_r75.f2);
CPyL66: ;
    CPy_RestoreExcInfo(cpy_r_r75);
    CPy_DecRef(cpy_r_r75.f0);
    CPy_DecRef(cpy_r_r75.f1);
    CPy_DecRef(cpy_r_r75.f2);
    cpy_r_r76 = CPy_KeepPropagating();
    if (!cpy_r_r76) goto CPyL69;
    CPy_Unreachable();
CPyL68: ;
    tuple_T3OOO __tmp16 = { NULL, NULL, NULL };
    cpy_r_r77 = __tmp16;
    cpy_r_r78 = cpy_r_r77;
    goto CPyL71;
CPyL69: ;
    cpy_r_r79 = NULL;
    if (((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6 != NULL) {
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6);
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6 = cpy_r_r79;
    cpy_r_r80 = 1;
    if (unlikely(!cpy_r_r80)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", -1, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r81 = CPy_CatchError();
    cpy_r_r78 = cpy_r_r81;
CPyL71: ;
    cpy_r_r82 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "cache_item", 255, CPyStatic_globals);
        goto CPyL83;
    }
    CPy_INCREF_NO_IMM(cpy_r_r82);
CPyL72: ;
    cpy_r_r83 = ((async_lru____CacheItemObject *)cpy_r_r82)->_waiters;
    if (unlikely(cpy_r_r83 == CPY_INT_TAG)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_CacheItem", "waiters", 255, CPyStatic_globals);
        goto CPyL113;
    }
CPyL73: ;
    cpy_r_r84 = CPyTagged_Subtract(cpy_r_r83, 2);
    if (((async_lru____CacheItemObject *)cpy_r_r82)->_waiters != CPY_INT_TAG) {
        CPyTagged_DECREF(((async_lru____CacheItemObject *)cpy_r_r82)->_waiters);
    }
    ((async_lru____CacheItemObject *)cpy_r_r82)->_waiters = cpy_r_r84;
    cpy_r_r85 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r82);
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL83;
    }
    if (cpy_r_r78.f0 == NULL) goto CPyL77;
    CPy_Reraise();
    if (!0) {
        goto CPyL83;
    } else
        goto CPyL114;
CPyL76: ;
    CPy_Unreachable();
CPyL77: ;
    cpy_r_r86 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6;
    if (cpy_r_r86 != NULL) {
        CPy_INCREF(cpy_r_r86);
    }
    if (cpy_r_r86 == NULL) goto CPyL87;
CPyL78: ;
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL82;
    CPyGen_SetStopIterationValue(cpy_r_r86);
    CPy_DECREF(cpy_r_r86);
    if (!0) goto CPyL96;
    CPy_Unreachable();
CPyL82: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r86;
    return 0;
CPyL83: ;
    if (cpy_r_r78.f0 == NULL) goto CPyL85;
    CPy_RestoreExcInfo(cpy_r_r78);
    CPy_XDECREF(cpy_r_r78.f0);
    CPy_XDECREF(cpy_r_r78.f1);
    CPy_XDECREF(cpy_r_r78.f2);
CPyL85: ;
    cpy_r_r88 = CPy_KeepPropagating();
    if (!cpy_r_r88) goto CPyL96;
    CPy_Unreachable();
CPyL87: ;
    cpy_r_r89 = Py_None;
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL91;
    CPyGen_SetStopIterationValue(cpy_r_r89);
    if (!0) goto CPyL96;
    CPy_Unreachable();
CPyL91: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r89;
    return 0;
CPyL92: ;
    cpy_r_r91 = cpy_r_r2 == 0;
    if (cpy_r_r91) goto CPyL115;
    cpy_r_r92 = cpy_r_r2 == 1;
    if (cpy_r_r92) {
        goto CPyL18;
    } else
        goto CPyL116;
CPyL94: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r93 = 0;
    if (unlikely(!cpy_r_r93)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL96;
    }
    CPy_Unreachable();
CPyL96: ;
    cpy_r_r94 = NULL;
    return cpy_r_r94;
CPyL97: ;
    CPy_DecRef(cpy_r_r8);
    goto CPyL39;
CPyL98: ;
    CPy_DecRef(cpy_r_r20);
    goto CPyL39;
CPyL99: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL21;
CPyL100: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL20;
CPyL101: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL30;
CPyL102: ;
    CPy_DecRef(cpy_r_r23);
    goto CPyL30;
CPyL103: ;
    CPy_DecRef(cpy_r_r20);
    goto CPyL30;
CPyL104: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL39;
CPyL105: ;
    CPy_DecRef(cpy_r_r46);
    goto CPyL65;
CPyL106: ;
    CPy_DecRef(cpy_r_r49);
    goto CPyL65;
CPyL107: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL65;
CPyL108: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r62);
    goto CPyL65;
CPyL109: ;
    CPy_DecRef(cpy_r_r66);
    goto CPyL56;
CPyL110: ;
    CPy_DecRef(cpy_r_r68);
    goto CPyL65;
CPyL111: ;
    CPy_DecRef(cpy_r_r68);
    CPy_DecRef(cpy_r_r69);
    goto CPyL65;
CPyL112: ;
    CPy_DecRef(cpy_r_r74);
    goto CPyL60;
CPyL113: ;
    CPy_DecRef(cpy_r_r82);
    goto CPyL83;
CPyL114: ;
    CPy_XDECREF(cpy_r_r78.f0);
    CPy_XDECREF(cpy_r_r78.f1);
    CPy_XDECREF(cpy_r_r78.f2);
    goto CPyL76;
CPyL115: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL1;
CPyL116: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL94;
}

PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0, 0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru._shield_and_handle_cancelled_error__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg, 0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru._shield_and_handle_cancelled_error__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru._shield_and_handle_cancelled_error__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0, 0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru._shield_and_handle_cancelled_error__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp17 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp17);
    PyObject *__tmp18 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp18);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru._shield_and_handle_cancelled_error__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru._shield_and_handle_cancelled_error__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__await__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapper____shield_and_handle_cancelled_error(PyObject *cpy_r_self, PyObject *cpy_r_cache_item, PyObject *cpy_r_key) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    cpy_r_r0 = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL5;
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    CPy_INCREF_NO_IMM(cpy_r_self);
    if (((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self != NULL) {
        CPy_DECREF_NO_IMM(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self);
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self = cpy_r_self;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF_NO_IMM(cpy_r_cache_item);
    if (((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__cache_item != NULL) {
        CPy_DECREF_NO_IMM(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__cache_item);
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__cache_item = cpy_r_cache_item;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_key);
    if (((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__key != NULL) {
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__key);
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__key = cpy_r_key;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    return cpy_r_r0;
CPyL5: ;
    cpy_r_r5 = NULL;
    return cpy_r_r5;
CPyL6: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy__LRUCacheWrapper____shield_and_handle_cancelled_error(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"cache_item", "key", 0};
    static CPyArg_Parser parser = {"OO:_shield_and_handle_cancelled_error", kwlist, 0};
    PyObject *obj_cache_item;
    PyObject *obj_key;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_cache_item, &obj_key)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *arg_cache_item;
    if (likely(Py_TYPE(obj_cache_item) == CPyType__CacheItem))
        arg_cache_item = obj_cache_item;
    else {
        CPy_TypeError("async_lru._CacheItem", obj_cache_item); 
        goto fail;
    }
    PyObject *arg_key = obj_key;
    PyObject *retval = CPyDef__LRUCacheWrapper____shield_and_handle_cancelled_error(arg_self, arg_cache_item, arg_key);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___call___3__LRUCacheWrapper_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg, PyObject **cpy_r_stop_iter_ptr) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    int32_t cpy_r_r8;
    PyObject *cpy_r_r9;
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
    char cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject **cpy_r_r38;
    PyObject *cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    char cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject **cpy_r_r64;
    PyObject *cpy_r_r65;
    char cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    CPyTagged cpy_r_r69;
    CPyTagged cpy_r_r70;
    char cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    char cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject **cpy_r_r81;
    PyObject *cpy_r_r82;
    char cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    char cpy_r_r88;
    PyObject *cpy_r_r89;
    char cpy_r_r90;
    tuple_T3OOO cpy_r_r91;
    char cpy_r_r92;
    PyObject **cpy_r_r93;
    PyObject *cpy_r_r94;
    char cpy_r_r95;
    tuple_T3OOO cpy_r_r96;
    tuple_T3OOO cpy_r_r97;
    tuple_T3OOO cpy_r_r98;
    char cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    char cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject **cpy_r_r107;
    PyObject *cpy_r_r108;
    char cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    char cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject **cpy_r_r122;
    PyObject *cpy_r_r123;
    char cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    char cpy_r_r131;
    PyObject **cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject **cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    char cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    int32_t cpy_r_r150;
    char cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    char cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    char cpy_r_r157;
    PyObject *cpy_r_r158;
    int64_t cpy_r_r159;
    CPyTagged cpy_r_r160;
    PyObject *cpy_r_r161;
    CPyTagged cpy_r_r162;
    int64_t cpy_r_r163;
    char cpy_r_r164;
    int64_t cpy_r_r165;
    char cpy_r_r166;
    char cpy_r_r167;
    char cpy_r_r168;
    char cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject **cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    tuple_T2OO cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    char cpy_r_r181;
    PyObject *cpy_r_r182;
    char cpy_r_r183;
    PyObject *cpy_r_r184;
    char cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    char cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    char cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject **cpy_r_r198;
    PyObject *cpy_r_r199;
    char cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    char cpy_r_r203;
    PyObject *cpy_r_r204;
    char cpy_r_r205;
    PyObject *cpy_r_r206;
    char cpy_r_r207;
    tuple_T3OOO cpy_r_r208;
    char cpy_r_r209;
    PyObject **cpy_r_r210;
    PyObject *cpy_r_r211;
    char cpy_r_r212;
    tuple_T3OOO cpy_r_r213;
    tuple_T3OOO cpy_r_r214;
    tuple_T3OOO cpy_r_r215;
    char cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    char cpy_r_r220;
    char cpy_r_r221;
    char cpy_r_r222;
    char cpy_r_r223;
    char cpy_r_r224;
    PyObject *cpy_r_r225;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    CPy_XDECREF(cpy_r_r1);
    cpy_r_r2 = NULL;
    cpy_r_r3 = cpy_r_r2;
    cpy_r_r4 = NULL;
    cpy_r_r5 = cpy_r_r4;
    CPy_XDECREF(cpy_r_r5);
    cpy_r_r6 = NULL;
    cpy_r_r7 = cpy_r_r6;
    cpy_r_r8 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__;
    goto CPyL192;
CPyL1: ;
    cpy_r_r9 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r10 = cpy_r_type != cpy_r_r9;
    if (!cpy_r_r10) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r11 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 260, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r11);
CPyL5: ;
    cpy_r_r12 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r11)->___closed;
    if (unlikely(cpy_r_r12 == 2)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__closed' of '_LRUCacheWrapper' undefined");
    }
    CPy_DECREF_NO_IMM(cpy_r_r11);
    if (unlikely(cpy_r_r12 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
CPyL6: ;
    if (!cpy_r_r12) goto CPyL14;
CPyL7: ;
    cpy_r_r13 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'alru_cache is closed for ' */
    cpy_r_r14 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 261, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r14);
CPyL8: ;
    cpy_r_r15 = PyObject_Str(cpy_r_r14);
    CPy_DECREF_NO_IMM(cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r16 = CPyStr_Build(2, cpy_r_r13, cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'RuntimeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL198;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL198;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_Unreachable();
CPyL14: ;
    cpy_r_r23 = CPyStatic_get_running_loop;
    if (likely(cpy_r_r23 != NULL)) goto CPyL17;
    PyErr_SetString(PyExc_NameError, "value for final name \"get_running_loop\" was not set");
    cpy_r_r24 = 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_Unreachable();
CPyL17: ;
    cpy_r_r25 = PyObject_Vectorcall(cpy_r_r23, 0, 0, 0);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop = cpy_r_r25;
    cpy_r_r26 = 1;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r27 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 264, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r27);
CPyL20: ;
    cpy_r_r28 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop;
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "loop", 264, CPyStatic_globals);
        goto CPyL199;
    }
    CPy_INCREF(cpy_r_r28);
CPyL21: ;
    cpy_r_r29 = CPyDef__LRUCacheWrapper____check_loop(cpy_r_r27, cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    CPy_DECREF_NO_IMM(cpy_r_r27);
    if (unlikely(cpy_r_r29 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r30 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_args;
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "fn_args", 266, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r30);
CPyL23: ;
    cpy_r_r31 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_kwargs;
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "fn_kwargs", 266, CPyStatic_globals);
        goto CPyL200;
    }
    CPy_INCREF(cpy_r_r31);
CPyL24: ;
    cpy_r_r32 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 266, CPyStatic_globals);
        goto CPyL201;
    }
    CPy_INCREF_NO_IMM(cpy_r_r32);
CPyL25: ;
    cpy_r_r33 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r32)->___typed;
    if (unlikely(cpy_r_r33 == 2)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__typed' of '_LRUCacheWrapper' undefined");
    }
    CPy_DECREF_NO_IMM(cpy_r_r32);
    if (unlikely(cpy_r_r33 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL201;
    }
CPyL26: ;
    cpy_r_r34 = CPyStatic__make_key;
    if (unlikely(cpy_r_r34 == NULL)) {
        goto CPyL202;
    } else
        goto CPyL29;
CPyL27: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_make_key\" was not set");
    cpy_r_r35 = 0;
    if (unlikely(!cpy_r_r35)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_Unreachable();
CPyL29: ;
    cpy_r_r36 = cpy_r_r33 ? Py_True : Py_False;
    PyObject *cpy_r_r37[3] = {cpy_r_r30, cpy_r_r31, cpy_r_r36};
    cpy_r_r38 = (PyObject **)&cpy_r_r37;
    cpy_r_r39 = PyObject_Vectorcall(cpy_r_r34, cpy_r_r38, 3, 0);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL201;
    }
    CPy_DECREF(cpy_r_r30);
    CPy_DECREF(cpy_r_r31);
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key = cpy_r_r39;
    cpy_r_r40 = 1;
    if (unlikely(!cpy_r_r40)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r41 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 268, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r41);
CPyL32: ;
    cpy_r_r42 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r41)->___cache;
    if (unlikely(cpy_r_r42 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__cache' of '_LRUCacheWrapper' undefined");
    } else {
        CPy_INCREF(cpy_r_r42);
    }
    CPy_DECREF_NO_IMM(cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
CPyL33: ;
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache = cpy_r_r42;
    cpy_r_r43 = 1;
    if (unlikely(!cpy_r_r43)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r44 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache;
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache", 270, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r44);
CPyL35: ;
    cpy_r_r45 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 270, CPyStatic_globals);
        goto CPyL203;
    }
    CPy_INCREF(cpy_r_r45);
CPyL36: ;
    cpy_r_r46 = CPyDict_GetWithNone(cpy_r_r44, cpy_r_r45);
    CPy_DECREF(cpy_r_r44);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    if (Py_TYPE(cpy_r_r46) == CPyType__CacheItem)
        cpy_r_r47 = cpy_r_r46;
    else {
        cpy_r_r47 = NULL;
    }
    if (cpy_r_r47 != NULL) goto __LL19;
    if (cpy_r_r46 == Py_None)
        cpy_r_r47 = cpy_r_r46;
    else {
        cpy_r_r47 = NULL;
    }
    if (cpy_r_r47 != NULL) goto __LL19;
    CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 270, CPyStatic_globals, "async_lru._CacheItem or None", cpy_r_r46);
    goto CPyL197;
__LL19: ;
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item = cpy_r_r47;
    cpy_r_r48 = 1;
    if (unlikely(!cpy_r_r48)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r49 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 272, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r49);
CPyL40: ;
    cpy_r_r50 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r51 = cpy_r_r49 != cpy_r_r50;
    CPy_DECREF(cpy_r_r49);
    if (!cpy_r_r51) goto CPyL102;
    cpy_r_r52 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 273, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r52);
CPyL42: ;
    cpy_r_r53 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 273, CPyStatic_globals);
        goto CPyL204;
    }
    CPy_INCREF(cpy_r_r53);
CPyL43: ;
    cpy_r_r54 = CPyDef__LRUCacheWrapper____cache_hit(cpy_r_r52, cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    CPy_DECREF_NO_IMM(cpy_r_r52);
    if (unlikely(cpy_r_r54 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r55 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 274, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r55);
CPyL45: ;
    if (likely(cpy_r_r55 != Py_None))
        cpy_r_r56 = cpy_r_r55;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 274, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r55);
        goto CPyL205;
    }
    cpy_r_r57 = ((async_lru____CacheItemObject *)cpy_r_r56)->_task;
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "_CacheItem", "task", 274, CPyStatic_globals);
        goto CPyL205;
    }
    CPy_INCREF(cpy_r_r57);
CPyL47: ;
    CPy_DECREF(cpy_r_r55);
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task = cpy_r_r57;
    cpy_r_r58 = 1;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r59 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 275, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r59);
CPyL49: ;
    if (likely(cpy_r_r59 != Py_None))
        cpy_r_r60 = cpy_r_r59;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 275, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r59);
        goto CPyL206;
    }
    cpy_r_r61 = ((async_lru____CacheItemObject *)cpy_r_r60)->_task;
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "_CacheItem", "task", 275, CPyStatic_globals);
        goto CPyL206;
    }
    CPy_INCREF(cpy_r_r61);
CPyL51: ;
    CPy_DECREF(cpy_r_r59);
    cpy_r_r62 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'done' */
    PyObject *cpy_r_r63[1] = {cpy_r_r61};
    cpy_r_r64 = (PyObject **)&cpy_r_r63;
    cpy_r_r65 = PyObject_VectorcallMethod(cpy_r_r62, cpy_r_r64, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL207;
    }
    CPy_DECREF(cpy_r_r61);
    if (unlikely(!PyBool_Check(cpy_r_r65))) {
        CPy_TypeError("bool", cpy_r_r65); cpy_r_r66 = 2;
    } else
        cpy_r_r66 = cpy_r_r65 == Py_True;
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r66 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    if (cpy_r_r66) goto CPyL95;
    cpy_r_r67 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 277, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r67);
CPyL55: ;
    if (likely(cpy_r_r67 != Py_None))
        cpy_r_r68 = cpy_r_r67;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 277, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r67);
        goto CPyL208;
    }
    cpy_r_r69 = ((async_lru____CacheItemObject *)cpy_r_r68)->_waiters;
    if (unlikely(cpy_r_r69 == CPY_INT_TAG)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "_CacheItem", "waiters", 277, CPyStatic_globals);
        goto CPyL208;
    }
CPyL57: ;
    cpy_r_r70 = CPyTagged_Add(cpy_r_r69, 2);
    if (((async_lru____CacheItemObject *)cpy_r_r68)->_waiters != CPY_INT_TAG) {
        CPyTagged_DECREF(((async_lru____CacheItemObject *)cpy_r_r68)->_waiters);
    }
    ((async_lru____CacheItemObject *)cpy_r_r68)->_waiters = cpy_r_r70;
    cpy_r_r71 = 1;
    if (unlikely(!cpy_r_r71)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL208;
    }
    CPy_DECREF(cpy_r_r67);
    cpy_r_r72 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 278, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r72);
CPyL59: ;
    cpy_r_r73 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 278, CPyStatic_globals);
        goto CPyL209;
    }
    CPy_INCREF(cpy_r_r73);
CPyL60: ;
    if (likely(cpy_r_r73 != Py_None))
        cpy_r_r74 = cpy_r_r73;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 278, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r73);
        goto CPyL209;
    }
    cpy_r_r75 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 278, CPyStatic_globals);
        goto CPyL210;
    }
    CPy_INCREF(cpy_r_r75);
CPyL62: ;
    cpy_r_r76 = CPyDef__LRUCacheWrapper____shield_and_handle_cancelled_error(cpy_r_r72, cpy_r_r74, cpy_r_r75);
    CPy_DECREF_NO_IMM(cpy_r_r74);
    CPy_DECREF(cpy_r_r75);
    CPy_DECREF_NO_IMM(cpy_r_r72);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8 != NULL) {
        CPy_DECREF_NO_IMM(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8 = cpy_r_r76;
    cpy_r_r77 = 1;
    if (unlikely(!cpy_r_r77)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r78 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8;
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r78);
CPyL65: ;
    cpy_r_r79 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r80 = NULL;
    cpy_r_r1 = cpy_r_r80;
    cpy_r_r81 = (PyObject **)&cpy_r_r1;
    cpy_r_r82 = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r_r78, cpy_r_r79, cpy_r_r79, cpy_r_r79, cpy_r_r79, cpy_r_r81);
    CPy_DECREF_NO_IMM(cpy_r_r78);
    if (cpy_r_r82 != NULL) goto CPyL211;
    cpy_r_r83 = cpy_r_r1 != 0;
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL212;
    }
    cpy_r_r84 = cpy_r_r1;
    cpy_r_r85 = NULL;
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8 != NULL) {
        CPy_DECREF_NO_IMM(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8 = cpy_r_r85;
    cpy_r_r86 = 1;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL213;
    } else
        goto CPyL90;
CPyL68: ;
    cpy_r_r87 = cpy_r_r82;
CPyL69: ;
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 1;
    return cpy_r_r87;
CPyL70: ;
    cpy_r_r89 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r90 = cpy_r_type != cpy_r_r89;
    if (!cpy_r_r90) goto CPyL214;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL74;
    } else
        goto CPyL215;
CPyL72: ;
    CPy_Unreachable();
CPyL73: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL85;
CPyL74: ;
    cpy_r_r91 = CPy_CatchError();
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9.f0 != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9.f0);
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9.f1);
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9.f2);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9 = cpy_r_r91;
    cpy_r_r92 = 1;
    if (unlikely(!cpy_r_r92)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL216;
    }
    cpy_r_r93 = (PyObject **)&cpy_r_r3;
    cpy_r_r94 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8;
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL216;
    }
    CPy_INCREF_NO_IMM(cpy_r_r94);
CPyL76: ;
    cpy_r_r95 = CPy_YieldFromErrorHandle(cpy_r_r94, cpy_r_r93);
    CPy_DecRef(cpy_r_r94);
    if (unlikely(cpy_r_r95 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL216;
    }
    if (cpy_r_r95) goto CPyL80;
    cpy_r_r87 = cpy_r_r3;
    cpy_r_r96 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9;
    if (unlikely(cpy_r_r96.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL217;
    }
    CPy_INCREF(cpy_r_r96.f0);
    CPy_INCREF(cpy_r_r96.f1);
    CPy_INCREF(cpy_r_r96.f2);
CPyL79: ;
    CPy_RestoreExcInfo(cpy_r_r96);
    CPy_DecRef(cpy_r_r96.f0);
    CPy_DecRef(cpy_r_r96.f1);
    CPy_DecRef(cpy_r_r96.f2);
    goto CPyL69;
CPyL80: ;
    cpy_r_r84 = cpy_r_r3;
    cpy_r_r97 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9;
    if (unlikely(cpy_r_r97.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL218;
    }
    CPy_INCREF(cpy_r_r97.f0);
    CPy_INCREF(cpy_r_r97.f1);
    CPy_INCREF(cpy_r_r97.f2);
CPyL81: ;
    CPy_RestoreExcInfo(cpy_r_r97);
    CPy_DecRef(cpy_r_r97.f0);
    CPy_DecRef(cpy_r_r97.f1);
    CPy_DecRef(cpy_r_r97.f2);
    goto CPyL90;
CPyL82: ;
    cpy_r_r98 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9;
    if (unlikely(cpy_r_r98.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r98.f0);
    CPy_INCREF(cpy_r_r98.f1);
    CPy_INCREF(cpy_r_r98.f2);
CPyL83: ;
    CPy_RestoreExcInfo(cpy_r_r98);
    CPy_DecRef(cpy_r_r98.f0);
    CPy_DecRef(cpy_r_r98.f1);
    CPy_DecRef(cpy_r_r98.f2);
    cpy_r_r99 = CPy_KeepPropagating();
    if (!cpy_r_r99) goto CPyL197;
    CPy_Unreachable();
CPyL85: ;
    cpy_r_r100 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8;
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL219;
    }
    CPy_INCREF_NO_IMM(cpy_r_r100);
CPyL86: ;
    cpy_r_r101 = CPyIter_Send(cpy_r_r100, cpy_r_arg);
    CPy_DECREF_NO_IMM(cpy_r_r100);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r101 == NULL) goto CPyL88;
    cpy_r_r87 = cpy_r_r101;
    goto CPyL69;
CPyL88: ;
    cpy_r_r102 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r84 = cpy_r_r102;
CPyL90: ;
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL94;
    CPyGen_SetStopIterationValue(cpy_r_r84);
    CPy_DECREF(cpy_r_r84);
    if (!0) goto CPyL197;
    CPy_Unreachable();
CPyL94: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r84;
    return 0;
CPyL95: ;
    cpy_r_r104 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "task", 281, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r104);
CPyL96: ;
    cpy_r_r105 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'result' */
    PyObject *cpy_r_r106[1] = {cpy_r_r104};
    cpy_r_r107 = (PyObject **)&cpy_r_r106;
    cpy_r_r108 = PyObject_VectorcallMethod(cpy_r_r105, cpy_r_r107, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL220;
    }
    CPy_DECREF(cpy_r_r104);
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL101;
    CPyGen_SetStopIterationValue(cpy_r_r108);
    CPy_DECREF(cpy_r_r108);
    if (!0) goto CPyL197;
    CPy_Unreachable();
CPyL101: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r108;
    return 0;
CPyL102: ;
    cpy_r_r110 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r110 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 283, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r110);
CPyL103: ;
    cpy_r_r111 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_args;
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "fn_args", 283, CPyStatic_globals);
        goto CPyL221;
    }
    CPy_INCREF(cpy_r_r111);
CPyL104: ;
    cpy_r_r112 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_kwargs;
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "fn_kwargs", 283, CPyStatic_globals);
        goto CPyL222;
    }
    CPy_INCREF(cpy_r_r112);
CPyL105: ;
    cpy_r_r113 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapped__' */
    cpy_r_r114 = CPyObject_GetAttr(cpy_r_r110, cpy_r_r113);
    CPy_DECREF_NO_IMM(cpy_r_r110);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL223;
    }
    cpy_r_r115 = PyDict_Copy(cpy_r_r112);
    CPy_DECREF(cpy_r_r112);
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL224;
    }
    cpy_r_r116 = PyObject_Call(cpy_r_r114, cpy_r_r111, cpy_r_r115);
    CPy_DECREF(cpy_r_r114);
    CPy_DECREF(cpy_r_r111);
    CPy_DECREF(cpy_r_r115);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__coro != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__coro);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__coro = cpy_r_r116;
    cpy_r_r117 = 1;
    if (unlikely(!cpy_r_r117)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r118 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop;
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "loop", 284, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r118);
CPyL110: ;
    cpy_r_r119 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__coro;
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "coro", 284, CPyStatic_globals);
        goto CPyL225;
    }
    CPy_INCREF(cpy_r_r119);
CPyL111: ;
    cpy_r_r120 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'create_task' */
    PyObject *cpy_r_r121[2] = {cpy_r_r118, cpy_r_r119};
    cpy_r_r122 = (PyObject **)&cpy_r_r121;
    cpy_r_r123 = PyObject_VectorcallMethod(cpy_r_r120, cpy_r_r122, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL226;
    }
    CPy_DECREF(cpy_r_r118);
    CPy_DECREF(cpy_r_r119);
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task = cpy_r_r123;
    cpy_r_r124 = 1;
    if (unlikely(!cpy_r_r124)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r125 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "task", 285, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r125);
CPyL114: ;
    cpy_r_r126 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 285, CPyStatic_globals);
        goto CPyL227;
    }
    CPy_INCREF_NO_IMM(cpy_r_r126);
CPyL115: ;
    cpy_r_r127 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_task_done_callback' */
    cpy_r_r128 = CPyObject_GetAttr(cpy_r_r126, cpy_r_r127);
    CPy_DECREF_NO_IMM(cpy_r_r126);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL227;
    }
    cpy_r_r129 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 285, CPyStatic_globals);
        goto CPyL228;
    }
    CPy_INCREF(cpy_r_r129);
CPyL117: ;
    cpy_r_r130 = CPyStatic_partial;
    if (unlikely(cpy_r_r130 == NULL)) {
        goto CPyL229;
    } else
        goto CPyL120;
CPyL118: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"partial\" was not set");
    cpy_r_r131 = 0;
    if (unlikely(!cpy_r_r131)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_Unreachable();
CPyL120: ;
    PyObject *cpy_r_r132[2] = {cpy_r_r128, cpy_r_r129};
    cpy_r_r133 = (PyObject **)&cpy_r_r132;
    cpy_r_r134 = PyObject_Vectorcall(cpy_r_r130, cpy_r_r133, 2, 0);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL230;
    }
    CPy_DECREF(cpy_r_r128);
    CPy_DECREF(cpy_r_r129);
    cpy_r_r135 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'add_done_callback' */
    PyObject *cpy_r_r136[2] = {cpy_r_r125, cpy_r_r134};
    cpy_r_r137 = (PyObject **)&cpy_r_r136;
    cpy_r_r138 = PyObject_VectorcallMethod(cpy_r_r135, cpy_r_r137, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL231;
    } else
        goto CPyL232;
CPyL122: ;
    CPy_DECREF(cpy_r_r125);
    CPy_DECREF(cpy_r_r134);
    cpy_r_r139 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r139 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "task", 287, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r139);
CPyL123: ;
    cpy_r_r140 = Py_None;
    cpy_r_r141 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 1 */
    cpy_r_r142 = PyTuple_Pack(3, cpy_r_r139, cpy_r_r140, cpy_r_r141);
    CPy_DECREF(cpy_r_r139);
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r143 = PyDict_New();
    if (unlikely(cpy_r_r143 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL233;
    }
    cpy_r_r144 = CPyDef__CacheItem(cpy_r_r142, cpy_r_r143);
    CPy_DECREF(cpy_r_r142);
    CPy_DECREF(cpy_r_r143);
    if (unlikely(cpy_r_r144 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item = cpy_r_r144;
    cpy_r_r145 = 1;
    if (unlikely(!cpy_r_r145)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r146 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r146 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 288, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r146);
CPyL128: ;
    if (likely(cpy_r_r146 != Py_None))
        cpy_r_r147 = cpy_r_r146;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 288, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r146);
        goto CPyL197;
    }
    cpy_r_r148 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache;
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache", 288, CPyStatic_globals);
        goto CPyL234;
    }
    CPy_INCREF(cpy_r_r148);
CPyL130: ;
    cpy_r_r149 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r149 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 288, CPyStatic_globals);
        goto CPyL235;
    }
    CPy_INCREF(cpy_r_r149);
CPyL131: ;
    cpy_r_r150 = CPyDict_SetItem(cpy_r_r148, cpy_r_r149, cpy_r_r147);
    CPy_DECREF(cpy_r_r148);
    CPy_DECREF(cpy_r_r149);
    CPy_DECREF_NO_IMM(cpy_r_r147);
    cpy_r_r151 = cpy_r_r150 >= 0;
    if (unlikely(!cpy_r_r151)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r152 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 290, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r152);
CPyL133: ;
    cpy_r_r153 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r152)->___maxsize;
    if (unlikely(cpy_r_r153 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__maxsize' of '_LRUCacheWrapper' undefined");
    } else {
        CPy_INCREF(cpy_r_r153);
    }
    CPy_DECREF_NO_IMM(cpy_r_r152);
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
CPyL134: ;
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__maxsize != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__maxsize);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__maxsize = cpy_r_r153;
    cpy_r_r154 = 1;
    if (unlikely(!cpy_r_r154)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r155 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__maxsize;
    if (unlikely(cpy_r_r155 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "maxsize", 291, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r155);
CPyL136: ;
    cpy_r_r156 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r157 = cpy_r_r155 != cpy_r_r156;
    CPy_DECREF(cpy_r_r155);
    if (!cpy_r_r157) goto CPyL152;
    cpy_r_r158 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache;
    if (unlikely(cpy_r_r158 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache", 291, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r158);
CPyL138: ;
    cpy_r_r159 = PyDict_Size(cpy_r_r158);
    CPy_DECREF(cpy_r_r158);
    cpy_r_r160 = cpy_r_r159 << 1;
    cpy_r_r161 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__maxsize;
    if (unlikely(cpy_r_r161 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "maxsize", 291, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r161);
CPyL139: ;
    if (likely(PyLong_Check(cpy_r_r161)))
        cpy_r_r162 = CPyTagged_FromObject(cpy_r_r161);
    else {
        CPy_TypeError("int", cpy_r_r161); cpy_r_r162 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r161);
    if (unlikely(cpy_r_r162 == CPY_INT_TAG)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r163 = cpy_r_r160 & 1;
    cpy_r_r164 = cpy_r_r163 != 0;
    if (cpy_r_r164) goto CPyL142;
    cpy_r_r165 = cpy_r_r162 & 1;
    cpy_r_r166 = cpy_r_r165 != 0;
    if (!cpy_r_r166) goto CPyL143;
CPyL142: ;
    cpy_r_r167 = CPyTagged_IsLt_(cpy_r_r162, cpy_r_r160);
    cpy_r_r168 = cpy_r_r167;
    goto CPyL144;
CPyL143: ;
    cpy_r_r169 = (Py_ssize_t)cpy_r_r160 > (Py_ssize_t)cpy_r_r162;
    cpy_r_r168 = cpy_r_r169;
CPyL144: ;
    CPyTagged_DECREF(cpy_r_r162);
    if (!cpy_r_r168) goto CPyL152;
    cpy_r_r170 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache;
    if (unlikely(cpy_r_r170 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache", 292, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r170);
CPyL146: ;
    cpy_r_r171 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'popitem' */
    cpy_r_r172 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r173[2] = {cpy_r_r170, cpy_r_r172};
    cpy_r_r174 = (PyObject **)&cpy_r_r173;
    cpy_r_r175 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('last',) */
    cpy_r_r176 = PyObject_VectorcallMethod(cpy_r_r171, cpy_r_r174, 9223372036854775809ULL, cpy_r_r175);
    if (unlikely(cpy_r_r176 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL236;
    }
    CPy_DECREF(cpy_r_r170);
    PyObject *__tmp20;
    if (unlikely(!(PyTuple_Check(cpy_r_r176) && PyTuple_GET_SIZE(cpy_r_r176) == 2))) {
        __tmp20 = NULL;
        goto __LL21;
    }
    __tmp20 = PyTuple_GET_ITEM(cpy_r_r176, 0);
    if (__tmp20 == NULL) goto __LL21;
    if (likely(Py_TYPE(PyTuple_GET_ITEM(cpy_r_r176, 1)) == CPyType__CacheItem))
        __tmp20 = PyTuple_GET_ITEM(cpy_r_r176, 1);
    else {
        __tmp20 = NULL;
    }
    if (__tmp20 == NULL) goto __LL21;
    __tmp20 = cpy_r_r176;
__LL21: ;
    if (unlikely(__tmp20 == NULL)) {
        CPy_TypeError("tuple[object, async_lru._CacheItem]", cpy_r_r176); cpy_r_r177 = (tuple_T2OO) { NULL, NULL };
    } else {
        PyObject *__tmp22 = PyTuple_GET_ITEM(cpy_r_r176, 0);
        CPy_INCREF(__tmp22);
        PyObject *__tmp23;
        __tmp23 = __tmp22;
        cpy_r_r177.f0 = __tmp23;
        PyObject *__tmp24 = PyTuple_GET_ITEM(cpy_r_r176, 1);
        CPy_INCREF(__tmp24);
        PyObject *__tmp25;
        if (likely(Py_TYPE(__tmp24) == CPyType__CacheItem))
            __tmp25 = __tmp24;
        else {
            CPy_TypeError("async_lru._CacheItem", __tmp24); 
            __tmp25 = NULL;
        }
        cpy_r_r177.f1 = __tmp25;
    }
    CPy_DECREF(cpy_r_r176);
    if (unlikely(cpy_r_r177.f0 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r178 = cpy_r_r177.f0;
    cpy_r_r179 = cpy_r_r177.f1;
    cpy_r_r180 = cpy_r_r178;
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_key != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_key);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_key = cpy_r_r180;
    cpy_r_r181 = 1;
    if (unlikely(!cpy_r_r181)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r182 = cpy_r_r179;
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_cache_item != NULL) {
        CPy_DECREF_NO_IMM(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_cache_item);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_cache_item = cpy_r_r182;
    cpy_r_r183 = 1;
    if (unlikely(!cpy_r_r183)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r184 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_cache_item;
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "dropped_cache_item", 293, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r184);
CPyL151: ;
    cpy_r_r185 = CPyDef__CacheItem___cancel(cpy_r_r184);
    CPy_DECREF_NO_IMM(cpy_r_r184);
    if (unlikely(cpy_r_r185 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
CPyL152: ;
    cpy_r_r186 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r186 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 295, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r186);
CPyL153: ;
    cpy_r_r187 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r187 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 295, CPyStatic_globals);
        goto CPyL237;
    }
    CPy_INCREF(cpy_r_r187);
CPyL154: ;
    cpy_r_r188 = CPyDef__LRUCacheWrapper____cache_miss(cpy_r_r186, cpy_r_r187);
    CPy_DECREF(cpy_r_r187);
    CPy_DECREF_NO_IMM(cpy_r_r186);
    if (unlikely(cpy_r_r188 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r189 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r189 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 297, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r189);
CPyL156: ;
    cpy_r_r190 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r190 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 297, CPyStatic_globals);
        goto CPyL238;
    }
    CPy_INCREF(cpy_r_r190);
CPyL157: ;
    if (likely(cpy_r_r190 != Py_None))
        cpy_r_r191 = cpy_r_r190;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 297, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r190);
        goto CPyL238;
    }
    cpy_r_r192 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r192 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 297, CPyStatic_globals);
        goto CPyL239;
    }
    CPy_INCREF(cpy_r_r192);
CPyL159: ;
    cpy_r_r193 = CPyDef__LRUCacheWrapper____shield_and_handle_cancelled_error(cpy_r_r189, cpy_r_r191, cpy_r_r192);
    CPy_DECREF_NO_IMM(cpy_r_r191);
    CPy_DECREF(cpy_r_r192);
    CPy_DECREF_NO_IMM(cpy_r_r189);
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10 != NULL) {
        CPy_DECREF_NO_IMM(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10 = cpy_r_r193;
    cpy_r_r194 = 1;
    if (unlikely(!cpy_r_r194)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r195 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10;
    if (unlikely(cpy_r_r195 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF_NO_IMM(cpy_r_r195);
CPyL162: ;
    cpy_r_r196 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r197 = NULL;
    cpy_r_r5 = cpy_r_r197;
    cpy_r_r198 = (PyObject **)&cpy_r_r5;
    cpy_r_r199 = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r_r195, cpy_r_r196, cpy_r_r196, cpy_r_r196, cpy_r_r196, cpy_r_r198);
    CPy_DECREF_NO_IMM(cpy_r_r195);
    if (cpy_r_r199 != NULL) goto CPyL240;
    cpy_r_r200 = cpy_r_r5 != 0;
    if (unlikely(!cpy_r_r200)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL241;
    }
    cpy_r_r201 = cpy_r_r5;
    cpy_r_r202 = NULL;
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10 != NULL) {
        CPy_DECREF_NO_IMM(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10 = cpy_r_r202;
    cpy_r_r203 = 1;
    if (unlikely(!cpy_r_r203)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL242;
    } else
        goto CPyL187;
CPyL165: ;
    cpy_r_r204 = cpy_r_r199;
CPyL166: ;
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 2;
    return cpy_r_r204;
CPyL167: ;
    cpy_r_r206 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r207 = cpy_r_type != cpy_r_r206;
    if (!cpy_r_r207) goto CPyL243;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL171;
    } else
        goto CPyL244;
CPyL169: ;
    CPy_Unreachable();
CPyL170: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL182;
CPyL171: ;
    cpy_r_r208 = CPy_CatchError();
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11.f0 != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11.f0);
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11.f1);
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11.f2);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11 = cpy_r_r208;
    cpy_r_r209 = 1;
    if (unlikely(!cpy_r_r209)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL245;
    }
    cpy_r_r210 = (PyObject **)&cpy_r_r7;
    cpy_r_r211 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10;
    if (unlikely(cpy_r_r211 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL245;
    }
    CPy_INCREF_NO_IMM(cpy_r_r211);
CPyL173: ;
    cpy_r_r212 = CPy_YieldFromErrorHandle(cpy_r_r211, cpy_r_r210);
    CPy_DecRef(cpy_r_r211);
    if (unlikely(cpy_r_r212 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL245;
    }
    if (cpy_r_r212) goto CPyL177;
    cpy_r_r204 = cpy_r_r7;
    cpy_r_r213 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11;
    if (unlikely(cpy_r_r213.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL246;
    }
    CPy_INCREF(cpy_r_r213.f0);
    CPy_INCREF(cpy_r_r213.f1);
    CPy_INCREF(cpy_r_r213.f2);
CPyL176: ;
    CPy_RestoreExcInfo(cpy_r_r213);
    CPy_DecRef(cpy_r_r213.f0);
    CPy_DecRef(cpy_r_r213.f1);
    CPy_DecRef(cpy_r_r213.f2);
    goto CPyL166;
CPyL177: ;
    cpy_r_r201 = cpy_r_r7;
    cpy_r_r214 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11;
    if (unlikely(cpy_r_r214.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL247;
    }
    CPy_INCREF(cpy_r_r214.f0);
    CPy_INCREF(cpy_r_r214.f1);
    CPy_INCREF(cpy_r_r214.f2);
CPyL178: ;
    CPy_RestoreExcInfo(cpy_r_r214);
    CPy_DecRef(cpy_r_r214.f0);
    CPy_DecRef(cpy_r_r214.f1);
    CPy_DecRef(cpy_r_r214.f2);
    goto CPyL187;
CPyL179: ;
    cpy_r_r215 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11;
    if (unlikely(cpy_r_r215.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r215.f0);
    CPy_INCREF(cpy_r_r215.f1);
    CPy_INCREF(cpy_r_r215.f2);
CPyL180: ;
    CPy_RestoreExcInfo(cpy_r_r215);
    CPy_DecRef(cpy_r_r215.f0);
    CPy_DecRef(cpy_r_r215.f1);
    CPy_DecRef(cpy_r_r215.f2);
    cpy_r_r216 = CPy_KeepPropagating();
    if (!cpy_r_r216) goto CPyL197;
    CPy_Unreachable();
CPyL182: ;
    cpy_r_r217 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10;
    if (unlikely(cpy_r_r217 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL248;
    }
    CPy_INCREF_NO_IMM(cpy_r_r217);
CPyL183: ;
    cpy_r_r218 = CPyIter_Send(cpy_r_r217, cpy_r_arg);
    CPy_DECREF_NO_IMM(cpy_r_r217);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r218 == NULL) goto CPyL185;
    cpy_r_r204 = cpy_r_r218;
    goto CPyL166;
CPyL185: ;
    cpy_r_r219 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r219 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r201 = cpy_r_r219;
CPyL187: ;
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL191;
    CPyGen_SetStopIterationValue(cpy_r_r201);
    CPy_DECREF(cpy_r_r201);
    if (!0) goto CPyL197;
    CPy_Unreachable();
CPyL191: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r201;
    return 0;
CPyL192: ;
    cpy_r_r221 = cpy_r_r8 == 0;
    if (cpy_r_r221) goto CPyL249;
    cpy_r_r222 = cpy_r_r8 == 1;
    if (cpy_r_r222) {
        goto CPyL250;
    } else
        goto CPyL251;
CPyL194: ;
    cpy_r_r223 = cpy_r_r8 == 2;
    if (cpy_r_r223) {
        goto CPyL167;
    } else
        goto CPyL252;
CPyL195: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r224 = 0;
    if (unlikely(!cpy_r_r224)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_Unreachable();
CPyL197: ;
    cpy_r_r225 = NULL;
    return cpy_r_r225;
CPyL198: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL197;
CPyL199: ;
    CPy_DecRef(cpy_r_r27);
    goto CPyL197;
CPyL200: ;
    CPy_DecRef(cpy_r_r30);
    goto CPyL197;
CPyL201: ;
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r31);
    goto CPyL197;
CPyL202: ;
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r31);
    goto CPyL27;
CPyL203: ;
    CPy_DecRef(cpy_r_r44);
    goto CPyL197;
CPyL204: ;
    CPy_DecRef(cpy_r_r52);
    goto CPyL197;
CPyL205: ;
    CPy_DecRef(cpy_r_r55);
    goto CPyL197;
CPyL206: ;
    CPy_DecRef(cpy_r_r59);
    goto CPyL197;
CPyL207: ;
    CPy_DecRef(cpy_r_r61);
    goto CPyL197;
CPyL208: ;
    CPy_DecRef(cpy_r_r67);
    goto CPyL197;
CPyL209: ;
    CPy_DecRef(cpy_r_r72);
    goto CPyL197;
CPyL210: ;
    CPy_DecRef(cpy_r_r72);
    CPy_DecRef(cpy_r_r74);
    goto CPyL197;
CPyL211: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL68;
CPyL212: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL197;
CPyL213: ;
    CPy_DecRef(cpy_r_r84);
    goto CPyL197;
CPyL214: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL73;
CPyL215: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL72;
CPyL216: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL82;
CPyL217: ;
    CPy_DecRef(cpy_r_r87);
    goto CPyL82;
CPyL218: ;
    CPy_DecRef(cpy_r_r84);
    goto CPyL82;
CPyL219: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL197;
CPyL220: ;
    CPy_DecRef(cpy_r_r104);
    goto CPyL197;
CPyL221: ;
    CPy_DecRef(cpy_r_r110);
    goto CPyL197;
CPyL222: ;
    CPy_DecRef(cpy_r_r110);
    CPy_DecRef(cpy_r_r111);
    goto CPyL197;
CPyL223: ;
    CPy_DecRef(cpy_r_r111);
    CPy_DecRef(cpy_r_r112);
    goto CPyL197;
CPyL224: ;
    CPy_DecRef(cpy_r_r111);
    CPy_DecRef(cpy_r_r114);
    goto CPyL197;
CPyL225: ;
    CPy_DecRef(cpy_r_r118);
    goto CPyL197;
CPyL226: ;
    CPy_DecRef(cpy_r_r118);
    CPy_DecRef(cpy_r_r119);
    goto CPyL197;
CPyL227: ;
    CPy_DecRef(cpy_r_r125);
    goto CPyL197;
CPyL228: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r128);
    goto CPyL197;
CPyL229: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r128);
    CPy_DecRef(cpy_r_r129);
    goto CPyL118;
CPyL230: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r128);
    CPy_DecRef(cpy_r_r129);
    goto CPyL197;
CPyL231: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r134);
    goto CPyL197;
CPyL232: ;
    CPy_DECREF(cpy_r_r138);
    goto CPyL122;
CPyL233: ;
    CPy_DecRef(cpy_r_r142);
    goto CPyL197;
CPyL234: ;
    CPy_DecRef(cpy_r_r147);
    goto CPyL197;
CPyL235: ;
    CPy_DecRef(cpy_r_r147);
    CPy_DecRef(cpy_r_r148);
    goto CPyL197;
CPyL236: ;
    CPy_DecRef(cpy_r_r170);
    goto CPyL197;
CPyL237: ;
    CPy_DecRef(cpy_r_r186);
    goto CPyL197;
CPyL238: ;
    CPy_DecRef(cpy_r_r189);
    goto CPyL197;
CPyL239: ;
    CPy_DecRef(cpy_r_r189);
    CPy_DecRef(cpy_r_r191);
    goto CPyL197;
CPyL240: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL165;
CPyL241: ;
    CPy_XDecRef(cpy_r_r5);
    goto CPyL197;
CPyL242: ;
    CPy_DecRef(cpy_r_r201);
    goto CPyL197;
CPyL243: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL170;
CPyL244: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL169;
CPyL245: ;
    CPy_XDecRef(cpy_r_r7);
    goto CPyL179;
CPyL246: ;
    CPy_DecRef(cpy_r_r204);
    goto CPyL179;
CPyL247: ;
    CPy_DecRef(cpy_r_r201);
    goto CPyL179;
CPyL248: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL197;
CPyL249: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r7);
    goto CPyL1;
CPyL250: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL70;
CPyL251: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL194;
CPyL252: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL195;
}

PyObject *CPyDef___call___3__LRUCacheWrapper_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef___call___3__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0, 0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy___call___3__LRUCacheWrapper_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___call___3__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.__call____LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapper_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___call___3__LRUCacheWrapper_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef___call___3__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg, 0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy___call___3__LRUCacheWrapper_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___call___3__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.__call____LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef___call___3__LRUCacheWrapper_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___call___3__LRUCacheWrapper_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy___call___3__LRUCacheWrapper_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___call___3__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.__call____LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapper_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___call___3__LRUCacheWrapper_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef___call___3__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0, 0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy___call___3__LRUCacheWrapper_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___call___3__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.__call____LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapper_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___call___3__LRUCacheWrapper_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef___call___3__LRUCacheWrapper_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp26 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp26);
    PyObject *__tmp27 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp27);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy___call___3__LRUCacheWrapper_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___call___3__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.__call____LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapper_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___call___3__LRUCacheWrapper_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy___call___3__LRUCacheWrapper_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___call___3__LRUCacheWrapper_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.__call____LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapper_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__await__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapper_____call__(PyObject *cpy_r_self, PyObject *cpy_r_fn_args, PyObject *cpy_r_fn_kwargs) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    cpy_r_r0 = CPyDef___call___3__LRUCacheWrapper_gen();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL5;
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    CPy_INCREF_NO_IMM(cpy_r_self);
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self != NULL) {
        CPy_DECREF_NO_IMM(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self = cpy_r_self;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_fn_args);
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_args != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_args);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_args = cpy_r_fn_args;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_fn_kwargs);
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_kwargs != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_kwargs);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_kwargs = cpy_r_fn_kwargs;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    return cpy_r_r0;
CPyL5: ;
    cpy_r_r5 = NULL;
    return cpy_r_r5;
CPyL6: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy__LRUCacheWrapper_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {"%:__call__", kwlist, 0};
    PyObject *obj_fn_args;
    PyObject *obj_fn_kwargs;
    if (!CPyArg_ParseStackAndKeywords(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_fn_args, &obj_fn_kwargs)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *arg_fn_args = obj_fn_args;
    PyObject *arg_fn_kwargs = obj_fn_kwargs;
    PyObject *retval = CPyDef__LRUCacheWrapper_____call__(arg_self, arg_fn_args, arg_fn_kwargs);
    CPy_DECREF(obj_fn_args);
    CPy_DECREF(obj_fn_kwargs);
    return retval;
fail: ;
    CPy_DECREF(obj_fn_args);
    CPy_DECREF(obj_fn_kwargs);
    CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapper_____get__(PyObject *cpy_r_self, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = cpy_r_owner == cpy_r_r0;
    if (!cpy_r_r1) goto CPyL2;
    CPy_INCREF_NO_IMM(cpy_r_self);
    return cpy_r_self;
CPyL2: ;
    cpy_r_r2 = CPyDef__LRUCacheWrapperInstanceMethod(cpy_r_self, cpy_r_instance);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__get__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL4;
    }
    return cpy_r_r2;
CPyL4: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy__LRUCacheWrapper_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"instance", "owner", 0};
    static CPyArg_Parser parser = {"OO:__get__", kwlist, 0};
    PyObject *obj_instance;
    PyObject *obj_owner;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_instance, &obj_owner)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapper))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *arg_instance = obj_instance;
    PyObject *arg_owner;
    arg_owner = obj_owner;
    if (arg_owner != NULL) goto __LL28;
    if (obj_owner == Py_None)
        arg_owner = obj_owner;
    else {
        arg_owner = NULL;
    }
    if (arg_owner != NULL) goto __LL28;
    CPy_TypeError("object or None", obj_owner); 
    goto fail;
__LL28: ;
    PyObject *retval = CPyDef__LRUCacheWrapper_____get__(arg_self, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__get__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef__LRUCacheWrapperInstanceMethod_____init__(PyObject *cpy_r_self, PyObject *cpy_r_wrapper, PyObject *cpy_r_instance) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    tuple_T3OOO cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    tuple_T3OOO cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    tuple_T3OOO cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    char cpy_r_r25;
    tuple_T3OOO cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    char cpy_r_r33;
    tuple_T3OOO cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    char cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    int32_t cpy_r_r45;
    char cpy_r_r46;
    tuple_T3OOO cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    char cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    tuple_T2II cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    char cpy_r_r60;
    char cpy_r_r61;
    PyObject *cpy_r_r62;
    char cpy_r_r63;
    char cpy_r_r64;
    char cpy_r_r65;
    char cpy_r_r66;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___module__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__module__", 317, CPyStatic_globals);
        goto CPyL3;
    }
    CPy_INCREF(cpy_r_r0);
CPyL2: ;
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___module__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___module__);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___module__ = cpy_r_r0;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL10;
CPyL3: ;
    cpy_r_r2 = CPy_CatchError();
    cpy_r_r3 = CPyModule_builtins;
    cpy_r_r4 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r6 = CPy_ExceptionMatches(cpy_r_r5);
    CPy_DecRef(cpy_r_r5);
    if (cpy_r_r6) goto CPyL7;
    CPy_Reraise();
    if (!0) {
        goto CPyL8;
    } else
        goto CPyL70;
CPyL6: ;
    CPy_Unreachable();
CPyL7: ;
    CPy_RestoreExcInfo(cpy_r_r2);
    CPy_DecRef(cpy_r_r2.f0);
    CPy_DecRef(cpy_r_r2.f1);
    CPy_DecRef(cpy_r_r2.f2);
    goto CPyL10;
CPyL8: ;
    CPy_RestoreExcInfo(cpy_r_r2);
    CPy_DecRef(cpy_r_r2.f0);
    CPy_DecRef(cpy_r_r2.f1);
    CPy_DecRef(cpy_r_r2.f2);
    cpy_r_r7 = CPy_KeepPropagating();
    if (!cpy_r_r7) goto CPyL69;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r8 = ((async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___name__;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__name__", 321, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_INCREF(cpy_r_r8);
CPyL11: ;
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___name__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___name__);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___name__ = cpy_r_r8;
    cpy_r_r9 = 1;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL19;
CPyL12: ;
    cpy_r_r10 = CPy_CatchError();
    cpy_r_r11 = CPyModule_builtins;
    cpy_r_r12 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_r11, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r14 = CPy_ExceptionMatches(cpy_r_r13);
    CPy_DecRef(cpy_r_r13);
    if (cpy_r_r14) goto CPyL16;
    CPy_Reraise();
    if (!0) {
        goto CPyL17;
    } else
        goto CPyL71;
CPyL15: ;
    CPy_Unreachable();
CPyL16: ;
    CPy_RestoreExcInfo(cpy_r_r10);
    CPy_DecRef(cpy_r_r10.f0);
    CPy_DecRef(cpy_r_r10.f1);
    CPy_DecRef(cpy_r_r10.f2);
    goto CPyL19;
CPyL17: ;
    CPy_RestoreExcInfo(cpy_r_r10);
    CPy_DecRef(cpy_r_r10.f0);
    CPy_DecRef(cpy_r_r10.f1);
    CPy_DecRef(cpy_r_r10.f2);
    cpy_r_r15 = CPy_KeepPropagating();
    if (!cpy_r_r15) goto CPyL69;
    CPy_Unreachable();
CPyL19: ;
    cpy_r_r16 = ((async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___qualname__;
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__qualname__", 325, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_INCREF(cpy_r_r16);
CPyL20: ;
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___qualname__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___qualname__);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___qualname__ = cpy_r_r16;
    cpy_r_r17 = 1;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL28;
CPyL21: ;
    cpy_r_r18 = CPy_CatchError();
    cpy_r_r19 = CPyModule_builtins;
    cpy_r_r20 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r22 = CPy_ExceptionMatches(cpy_r_r21);
    CPy_DecRef(cpy_r_r21);
    if (cpy_r_r22) goto CPyL25;
    CPy_Reraise();
    if (!0) {
        goto CPyL26;
    } else
        goto CPyL72;
CPyL24: ;
    CPy_Unreachable();
CPyL25: ;
    CPy_RestoreExcInfo(cpy_r_r18);
    CPy_DecRef(cpy_r_r18.f0);
    CPy_DecRef(cpy_r_r18.f1);
    CPy_DecRef(cpy_r_r18.f2);
    goto CPyL28;
CPyL26: ;
    CPy_RestoreExcInfo(cpy_r_r18);
    CPy_DecRef(cpy_r_r18.f0);
    CPy_DecRef(cpy_r_r18.f1);
    CPy_DecRef(cpy_r_r18.f2);
    cpy_r_r23 = CPy_KeepPropagating();
    if (!cpy_r_r23) goto CPyL69;
    CPy_Unreachable();
CPyL28: ;
    cpy_r_r24 = ((async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___doc__;
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__doc__", 329, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_INCREF(cpy_r_r24);
CPyL29: ;
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___doc__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___doc__);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___doc__ = cpy_r_r24;
    cpy_r_r25 = 1;
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL37;
CPyL30: ;
    cpy_r_r26 = CPy_CatchError();
    cpy_r_r27 = CPyModule_builtins;
    cpy_r_r28 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r29 = CPyObject_GetAttr(cpy_r_r27, cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r30 = CPy_ExceptionMatches(cpy_r_r29);
    CPy_DecRef(cpy_r_r29);
    if (cpy_r_r30) goto CPyL34;
    CPy_Reraise();
    if (!0) {
        goto CPyL35;
    } else
        goto CPyL73;
CPyL33: ;
    CPy_Unreachable();
CPyL34: ;
    CPy_RestoreExcInfo(cpy_r_r26);
    CPy_DecRef(cpy_r_r26.f0);
    CPy_DecRef(cpy_r_r26.f1);
    CPy_DecRef(cpy_r_r26.f2);
    goto CPyL37;
CPyL35: ;
    CPy_RestoreExcInfo(cpy_r_r26);
    CPy_DecRef(cpy_r_r26.f0);
    CPy_DecRef(cpy_r_r26.f1);
    CPy_DecRef(cpy_r_r26.f2);
    cpy_r_r31 = CPy_KeepPropagating();
    if (!cpy_r_r31) goto CPyL69;
    CPy_Unreachable();
CPyL37: ;
    cpy_r_r32 = ((async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___annotations__;
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__annotations__", 333, CPyStatic_globals);
        goto CPyL39;
    }
    CPy_INCREF(cpy_r_r32);
CPyL38: ;
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___annotations__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___annotations__);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___annotations__ = cpy_r_r32;
    cpy_r_r33 = 1;
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL46;
CPyL39: ;
    cpy_r_r34 = CPy_CatchError();
    cpy_r_r35 = CPyModule_builtins;
    cpy_r_r36 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r38 = CPy_ExceptionMatches(cpy_r_r37);
    CPy_DecRef(cpy_r_r37);
    if (cpy_r_r38) goto CPyL43;
    CPy_Reraise();
    if (!0) {
        goto CPyL44;
    } else
        goto CPyL74;
CPyL42: ;
    CPy_Unreachable();
CPyL43: ;
    CPy_RestoreExcInfo(cpy_r_r34);
    CPy_DecRef(cpy_r_r34.f0);
    CPy_DecRef(cpy_r_r34.f1);
    CPy_DecRef(cpy_r_r34.f2);
    goto CPyL46;
CPyL44: ;
    CPy_RestoreExcInfo(cpy_r_r34);
    CPy_DecRef(cpy_r_r34.f0);
    CPy_DecRef(cpy_r_r34.f1);
    CPy_DecRef(cpy_r_r34.f2);
    cpy_r_r39 = CPy_KeepPropagating();
    if (!cpy_r_r39) goto CPyL69;
    CPy_Unreachable();
CPyL46: ;
    cpy_r_r40 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r41 = CPyObject_GetAttr(cpy_r_wrapper, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    if (likely(PyDict_Check(cpy_r_r41)))
        cpy_r_r42 = cpy_r_r41;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 337, CPyStatic_globals, "dict", cpy_r_r41);
        goto CPyL50;
    }
    cpy_r_r43 = PyDict_Copy(cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r44 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r45 = PyObject_SetAttr(cpy_r_self, cpy_r_r44, cpy_r_r43);
    CPy_DECREF(cpy_r_r43);
    cpy_r_r46 = cpy_r_r45 >= 0;
    if (unlikely(!cpy_r_r46)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL57;
CPyL50: ;
    cpy_r_r47 = CPy_CatchError();
    cpy_r_r48 = CPyModule_builtins;
    cpy_r_r49 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_r48, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r51 = CPy_ExceptionMatches(cpy_r_r50);
    CPy_DecRef(cpy_r_r50);
    if (cpy_r_r51) goto CPyL54;
    CPy_Reraise();
    if (!0) {
        goto CPyL55;
    } else
        goto CPyL75;
CPyL53: ;
    CPy_Unreachable();
CPyL54: ;
    CPy_RestoreExcInfo(cpy_r_r47);
    CPy_DecRef(cpy_r_r47.f0);
    CPy_DecRef(cpy_r_r47.f1);
    CPy_DecRef(cpy_r_r47.f2);
    goto CPyL57;
CPyL55: ;
    CPy_RestoreExcInfo(cpy_r_r47);
    CPy_DecRef(cpy_r_r47.f0);
    CPy_DecRef(cpy_r_r47.f1);
    CPy_DecRef(cpy_r_r47.f2);
    cpy_r_r52 = CPy_KeepPropagating();
    if (!cpy_r_r52) goto CPyL69;
    CPy_Unreachable();
CPyL57: ;
    cpy_r_r53 = CPyModule_sys;
    cpy_r_r54 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r55 = CPyObject_GetAttr(cpy_r_r53, cpy_r_r54);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL69;
    }
    if (likely(PyTuple_Check(cpy_r_r55)))
        cpy_r_r56 = cpy_r_r55;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 342, CPyStatic_globals, "tuple", cpy_r_r55);
        goto CPyL69;
    }
    cpy_r_r57.f0 = 6;
    cpy_r_r57.f1 = 28;
    cpy_r_r58 = PyTuple_New(2);
    if (unlikely(cpy_r_r58 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp29 = CPyTagged_StealAsObject(cpy_r_r57.f0);
    PyTuple_SET_ITEM(cpy_r_r58, 0, __tmp29);
    PyObject *__tmp30 = CPyTagged_StealAsObject(cpy_r_r57.f1);
    PyTuple_SET_ITEM(cpy_r_r58, 1, __tmp30);
    cpy_r_r59 = PyObject_RichCompare(cpy_r_r56, cpy_r_r58, 0);
    CPy_DECREF(cpy_r_r56);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL69;
    }
    if (unlikely(!PyBool_Check(cpy_r_r59))) {
        CPy_TypeError("bool", cpy_r_r59); cpy_r_r60 = 2;
    } else
        cpy_r_r60 = cpy_r_r59 == Py_True;
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r60 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL69;
    }
    if (!cpy_r_r60) goto CPyL64;
    PyErr_SetString(PyExc_RuntimeError, "Reached allegedly unreachable code!");
    cpy_r_r61 = 0;
    if (unlikely(!cpy_r_r61)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_Unreachable();
CPyL64: ;
    cpy_r_r62 = ((async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___wrapped__;
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__wrapped__", 344, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_INCREF(cpy_r_r62);
CPyL65: ;
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapped__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapped__);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapped__ = cpy_r_r62;
    cpy_r_r63 = 1;
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_INCREF(cpy_r_instance);
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___instance != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___instance);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___instance = cpy_r_instance;
    cpy_r_r64 = 1;
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_INCREF_NO_IMM(cpy_r_wrapper);
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper != NULL) {
        CPy_DECREF_NO_IMM(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper = cpy_r_wrapper;
    cpy_r_r65 = 1;
    if (unlikely(!cpy_r_r65)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL69;
    }
    return 1;
CPyL69: ;
    cpy_r_r66 = 2;
    return cpy_r_r66;
CPyL70: ;
    CPy_DecRef(cpy_r_r2.f0);
    CPy_DecRef(cpy_r_r2.f1);
    CPy_DecRef(cpy_r_r2.f2);
    goto CPyL6;
CPyL71: ;
    CPy_DecRef(cpy_r_r10.f0);
    CPy_DecRef(cpy_r_r10.f1);
    CPy_DecRef(cpy_r_r10.f2);
    goto CPyL15;
CPyL72: ;
    CPy_DecRef(cpy_r_r18.f0);
    CPy_DecRef(cpy_r_r18.f1);
    CPy_DecRef(cpy_r_r18.f2);
    goto CPyL24;
CPyL73: ;
    CPy_DecRef(cpy_r_r26.f0);
    CPy_DecRef(cpy_r_r26.f1);
    CPy_DecRef(cpy_r_r26.f2);
    goto CPyL33;
CPyL74: ;
    CPy_DecRef(cpy_r_r34.f0);
    CPy_DecRef(cpy_r_r34.f1);
    CPy_DecRef(cpy_r_r34.f2);
    goto CPyL42;
CPyL75: ;
    CPy_DecRef(cpy_r_r47.f0);
    CPy_DecRef(cpy_r_r47.f1);
    CPy_DecRef(cpy_r_r47.f2);
    goto CPyL53;
}

PyObject *CPyPy__LRUCacheWrapperInstanceMethod_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"wrapper", "instance", 0};
    PyObject *obj_wrapper;
    PyObject *obj_instance;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "OO", "__init__", kwlist, &obj_wrapper, &obj_instance)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapperInstanceMethod))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
        goto fail;
    }
    PyObject *arg_wrapper;
    if (likely(Py_TYPE(obj_wrapper) == CPyType__LRUCacheWrapper))
        arg_wrapper = obj_wrapper;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapper", obj_wrapper); 
        goto fail;
    }
    PyObject *arg_instance = obj_instance;
    char retval = CPyDef__LRUCacheWrapperInstanceMethod_____init__(arg_self, arg_wrapper, arg_instance);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef__LRUCacheWrapperInstanceMethod___cache_invalidate(PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_kwargs) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    CPyPtr cpy_r_r5;
    CPyPtr cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    int32_t cpy_r_r9;
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    char cpy_r_r14;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_invalidate", "_LRUCacheWrapperInstanceMethod", "__wrapper", 349, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___instance;
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_invalidate", "_LRUCacheWrapperInstanceMethod", "__instance", 349, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cache_invalidate' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r2);
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r4 = PyList_New(1);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r5 = (CPyPtr)&((PyListObject *)cpy_r_r4)->ob_item;
    cpy_r_r6 = *(CPyPtr *)cpy_r_r5;
    *(PyObject * *)cpy_r_r6 = cpy_r_r1;
    cpy_r_r7 = CPyList_Extend(cpy_r_r4, cpy_r_args);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL15;
    } else
        goto CPyL16;
CPyL5: ;
    cpy_r_r8 = PyDict_New();
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r9 = CPyDict_UpdateInDisplay(cpy_r_r8, cpy_r_kwargs);
    cpy_r_r10 = cpy_r_r9 >= 0;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r11 = PyList_AsTuple(cpy_r_r4);
    CPy_DECREF_NO_IMM(cpy_r_r4);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r12 = PyObject_Call(cpy_r_r3, cpy_r_r11, cpy_r_r8);
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL11;
    }
    if (unlikely(!PyBool_Check(cpy_r_r12))) {
        CPy_TypeError("bool", cpy_r_r12); cpy_r_r13 = 2;
    } else
        cpy_r_r13 = cpy_r_r12 == Py_True;
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r13 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL11;
    }
    return cpy_r_r13;
CPyL11: ;
    cpy_r_r14 = 2;
    return cpy_r_r14;
CPyL12: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL11;
CPyL13: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL11;
CPyL14: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r3);
    goto CPyL11;
CPyL15: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL11;
CPyL16: ;
    CPy_DECREF(cpy_r_r7);
    goto CPyL5;
CPyL17: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r8);
    goto CPyL11;
CPyL18: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r8);
    goto CPyL11;
}

PyObject *CPyPy__LRUCacheWrapperInstanceMethod___cache_invalidate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {"%:cache_invalidate", kwlist, 0};
    PyObject *obj_args;
    PyObject *obj_kwargs;
    if (!CPyArg_ParseStackAndKeywords(args, nargs, kwnames, &parser, &obj_args, &obj_kwargs)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapperInstanceMethod))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
        goto fail;
    }
    PyObject *arg_args = obj_args;
    PyObject *arg_kwargs = obj_kwargs;
    char retval = CPyDef__LRUCacheWrapperInstanceMethod___cache_invalidate(arg_self, arg_args, arg_kwargs);
    CPy_DECREF(obj_args);
    CPy_DECREF(obj_kwargs);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_DECREF(obj_args);
    CPy_DECREF(obj_kwargs);
    CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef__LRUCacheWrapperInstanceMethod___cache_clear(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_clear", "_LRUCacheWrapperInstanceMethod", "__wrapper", 352, CPyStatic_globals);
        goto CPyL3;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyDef__LRUCacheWrapper___cache_clear(cpy_r_r0);
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r1 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL3;
    }
    return 1;
CPyL3: ;
    cpy_r_r2 = 2;
    return cpy_r_r2;
}

PyObject *CPyPy__LRUCacheWrapperInstanceMethod___cache_clear(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":cache_clear", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapperInstanceMethod))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
        goto fail;
    }
    char retval = CPyDef__LRUCacheWrapperInstanceMethod___cache_clear(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg, PyObject **cpy_r_stop_iter_ptr) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    int32_t cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject **cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    tuple_T3OOO cpy_r_r25;
    char cpy_r_r26;
    PyObject **cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    tuple_T3OOO cpy_r_r30;
    tuple_T3OOO cpy_r_r31;
    tuple_T3OOO cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    char cpy_r_r38;
    char cpy_r_r39;
    char cpy_r_r40;
    char cpy_r_r41;
    PyObject *cpy_r_r42;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    CPy_XDECREF(cpy_r_r1);
    cpy_r_r2 = NULL;
    cpy_r_r3 = cpy_r_r2;
    cpy_r_r4 = ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__;
    goto CPyL39;
CPyL1: ;
    cpy_r_r5 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r6 = cpy_r_type != cpy_r_r5;
    if (!cpy_r_r6) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r7 = ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "self", 357, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_INCREF_NO_IMM(cpy_r_r7);
CPyL5: ;
    cpy_r_r8 = ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_r7)->___wrapper;
    if (unlikely(cpy_r_r8 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__wrapper' of '_LRUCacheWrapperInstanceMethod' undefined");
    } else {
        CPy_INCREF_NO_IMM(cpy_r_r8);
    }
    CPy_DECREF_NO_IMM(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
CPyL6: ;
    cpy_r_r9 = 2;
    cpy_r_r10 = CPyDef__LRUCacheWrapper___cache_close(cpy_r_r8, cpy_r_r9);
    CPy_DECREF_NO_IMM(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
    if (((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12 != NULL) {
        CPy_DECREF_NO_IMM(((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12);
    }
    ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12 = cpy_r_r10;
    cpy_r_r11 = 1;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r12 = ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12;
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__12", -1, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_INCREF_NO_IMM(cpy_r_r12);
CPyL9: ;
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r14 = NULL;
    cpy_r_r1 = cpy_r_r14;
    cpy_r_r15 = (PyObject **)&cpy_r_r1;
    cpy_r_r16 = CPyDef_cache_close__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r_r12, cpy_r_r13, cpy_r_r13, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r12);
    if (cpy_r_r16 != NULL) goto CPyL44;
    cpy_r_r17 = cpy_r_r1 != 0;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r18 = cpy_r_r1;
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = NULL;
    if (((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12 != NULL) {
        CPy_DECREF_NO_IMM(((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12);
    }
    ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12 = cpy_r_r19;
    cpy_r_r20 = 1;
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    } else
        goto CPyL34;
CPyL12: ;
    cpy_r_r21 = cpy_r_r16;
CPyL13: ;
    ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 1;
    return cpy_r_r21;
CPyL14: ;
    cpy_r_r23 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r24 = cpy_r_type != cpy_r_r23;
    if (!cpy_r_r24) goto CPyL46;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL18;
    } else
        goto CPyL47;
CPyL16: ;
    CPy_Unreachable();
CPyL17: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL29;
CPyL18: ;
    cpy_r_r25 = CPy_CatchError();
    if (((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13.f0 != NULL) {
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13.f0);
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13.f1);
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13.f2);
    }
    ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13 = cpy_r_r25;
    cpy_r_r26 = 1;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r27 = (PyObject **)&cpy_r_r3;
    cpy_r_r28 = ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12;
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__12", -1, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_INCREF_NO_IMM(cpy_r_r28);
CPyL20: ;
    cpy_r_r29 = CPy_YieldFromErrorHandle(cpy_r_r28, cpy_r_r27);
    CPy_DecRef(cpy_r_r28);
    if (unlikely(cpy_r_r29 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL48;
    }
    if (cpy_r_r29) goto CPyL24;
    cpy_r_r21 = cpy_r_r3;
    cpy_r_r30 = ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13;
    if (unlikely(cpy_r_r30.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__13", -1, CPyStatic_globals);
        goto CPyL49;
    }
    CPy_INCREF(cpy_r_r30.f0);
    CPy_INCREF(cpy_r_r30.f1);
    CPy_INCREF(cpy_r_r30.f2);
CPyL23: ;
    CPy_RestoreExcInfo(cpy_r_r30);
    CPy_DecRef(cpy_r_r30.f0);
    CPy_DecRef(cpy_r_r30.f1);
    CPy_DecRef(cpy_r_r30.f2);
    goto CPyL13;
CPyL24: ;
    cpy_r_r18 = cpy_r_r3;
    CPy_DecRef(cpy_r_r18);
    cpy_r_r31 = ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13;
    if (unlikely(cpy_r_r31.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__13", -1, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_INCREF(cpy_r_r31.f0);
    CPy_INCREF(cpy_r_r31.f1);
    CPy_INCREF(cpy_r_r31.f2);
CPyL25: ;
    CPy_RestoreExcInfo(cpy_r_r31);
    CPy_DecRef(cpy_r_r31.f0);
    CPy_DecRef(cpy_r_r31.f1);
    CPy_DecRef(cpy_r_r31.f2);
    goto CPyL34;
CPyL26: ;
    cpy_r_r32 = ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13;
    if (unlikely(cpy_r_r32.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__13", -1, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_INCREF(cpy_r_r32.f0);
    CPy_INCREF(cpy_r_r32.f1);
    CPy_INCREF(cpy_r_r32.f2);
CPyL27: ;
    CPy_RestoreExcInfo(cpy_r_r32);
    CPy_DecRef(cpy_r_r32.f0);
    CPy_DecRef(cpy_r_r32.f1);
    CPy_DecRef(cpy_r_r32.f2);
    cpy_r_r33 = CPy_KeepPropagating();
    if (!cpy_r_r33) goto CPyL43;
    CPy_Unreachable();
CPyL29: ;
    cpy_r_r34 = ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12;
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__12", -1, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_INCREF_NO_IMM(cpy_r_r34);
CPyL30: ;
    cpy_r_r35 = CPyIter_Send(cpy_r_r34, cpy_r_arg);
    CPy_DECREF_NO_IMM(cpy_r_r34);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r35 == NULL) goto CPyL32;
    cpy_r_r21 = cpy_r_r35;
    goto CPyL13;
CPyL32: ;
    cpy_r_r36 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r18 = cpy_r_r36;
    CPy_DECREF(cpy_r_r18);
CPyL34: ;
    cpy_r_r37 = Py_None;
    ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL38;
    CPyGen_SetStopIterationValue(cpy_r_r37);
    if (!0) goto CPyL43;
    CPy_Unreachable();
CPyL38: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r37;
    return 0;
CPyL39: ;
    cpy_r_r39 = cpy_r_r4 == 0;
    if (cpy_r_r39) goto CPyL51;
    cpy_r_r40 = cpy_r_r4 == 1;
    if (cpy_r_r40) {
        goto CPyL14;
    } else
        goto CPyL52;
CPyL41: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r41 = 0;
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_Unreachable();
CPyL43: ;
    cpy_r_r42 = NULL;
    return cpy_r_r42;
CPyL44: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL12;
CPyL45: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL43;
CPyL46: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL17;
CPyL47: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL16;
CPyL48: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL26;
CPyL49: ;
    CPy_DecRef(cpy_r_r21);
    goto CPyL26;
CPyL50: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL43;
CPyL51: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL1;
CPyL52: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL41;
}

PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0, 0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.cache_close__LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg, 0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.cache_close__LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.cache_close__LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0, 0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.cache_close__LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp31 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp31);
    PyObject *__tmp32 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp32);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.cache_close__LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.cache_close__LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__await__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapperInstanceMethod___cache_close(PyObject *cpy_r_self, char cpy_r_cancel, char cpy_r_return_exceptions) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    if (cpy_r_cancel != 2) goto CPyL2;
    cpy_r_cancel = 0;
CPyL2: ;
    if (cpy_r_return_exceptions != 2) goto CPyL4;
    cpy_r_return_exceptions = 1;
CPyL4: ;
    cpy_r_r0 = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL9;
    }
    ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    CPy_INCREF_NO_IMM(cpy_r_self);
    if (((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self != NULL) {
        CPy_DECREF_NO_IMM(((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self);
    }
    ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self = cpy_r_self;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__cancel = cpy_r_cancel;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    ((async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__return_exceptions = cpy_r_return_exceptions;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    return cpy_r_r0;
CPyL9: ;
    cpy_r_r5 = NULL;
    return cpy_r_r5;
CPyL10: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL9;
}

PyObject *CPyPy__LRUCacheWrapperInstanceMethod___cache_close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"cancel", "return_exceptions", 0};
    static CPyArg_Parser parser = {"|$OO:cache_close", kwlist, 0};
    PyObject *obj_cancel = NULL;
    PyObject *obj_return_exceptions = NULL;
    if (!CPyArg_ParseStackAndKeywords(args, nargs, kwnames, &parser, &obj_cancel, &obj_return_exceptions)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapperInstanceMethod))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
        goto fail;
    }
    char arg_cancel;
    if (obj_cancel == NULL) {
        arg_cancel = 2;
    } else if (unlikely(!PyBool_Check(obj_cancel))) {
        CPy_TypeError("bool", obj_cancel); goto fail;
    } else
        arg_cancel = obj_cancel == Py_True;
    char arg_return_exceptions;
    if (obj_return_exceptions == NULL) {
        arg_return_exceptions = 2;
    } else if (unlikely(!PyBool_Check(obj_return_exceptions))) {
        CPy_TypeError("bool", obj_return_exceptions); goto fail;
    } else
        arg_return_exceptions = obj_return_exceptions == Py_True;
    PyObject *retval = CPyDef__LRUCacheWrapperInstanceMethod___cache_close(arg_self, arg_cancel, arg_return_exceptions);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapperInstanceMethod___cache_info(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_info", "_LRUCacheWrapperInstanceMethod", "__wrapper", 360, CPyStatic_globals);
        goto CPyL3;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyDef__LRUCacheWrapper___cache_info(cpy_r_r0);
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_info", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL3;
    }
    return cpy_r_r1;
CPyL3: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__LRUCacheWrapperInstanceMethod___cache_info(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":cache_info", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapperInstanceMethod))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef__LRUCacheWrapperInstanceMethod___cache_info(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "cache_info", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapperInstanceMethod___cache_parameters(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_parameters", "_LRUCacheWrapperInstanceMethod", "__wrapper", 363, CPyStatic_globals);
        goto CPyL3;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyDef__LRUCacheWrapper___cache_parameters(cpy_r_r0);
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_parameters", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL3;
    }
    return cpy_r_r1;
CPyL3: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__LRUCacheWrapperInstanceMethod___cache_parameters(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":cache_parameters", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapperInstanceMethod))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef__LRUCacheWrapperInstanceMethod___cache_parameters(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "cache_parameters", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg, PyObject **cpy_r_stop_iter_ptr) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    int32_t cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    int32_t cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    char cpy_r_r32;
    tuple_T3OOO cpy_r_r33;
    char cpy_r_r34;
    PyObject **cpy_r_r35;
    PyObject *cpy_r_r36;
    char cpy_r_r37;
    tuple_T3OOO cpy_r_r38;
    tuple_T3OOO cpy_r_r39;
    tuple_T3OOO cpy_r_r40;
    char cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    char cpy_r_r45;
    char cpy_r_r46;
    char cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__;
    goto CPyL49;
CPyL1: ;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = cpy_r_type != cpy_r_r3;
    if (!cpy_r_r4) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r5 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "self", 366, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_INCREF_NO_IMM(cpy_r_r5);
CPyL5: ;
    cpy_r_r6 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "self", 366, CPyStatic_globals);
        goto CPyL54;
    }
    CPy_INCREF_NO_IMM(cpy_r_r6);
CPyL6: ;
    cpy_r_r7 = ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_r6)->___instance;
    if (unlikely(cpy_r_r7 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__instance' of '_LRUCacheWrapperInstanceMethod' undefined");
    } else {
        CPy_INCREF(cpy_r_r7);
    }
    CPy_DECREF_NO_IMM(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL54;
    }
CPyL7: ;
    cpy_r_r8 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_args;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "fn_args", 366, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_INCREF(cpy_r_r8);
CPyL8: ;
    cpy_r_r9 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_kwargs;
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "fn_kwargs", 366, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_INCREF(cpy_r_r9);
CPyL9: ;
    cpy_r_r10 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapper' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r10);
    CPy_DECREF_NO_IMM(cpy_r_r5);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r12 = PyList_New(1);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r7;
    cpy_r_r15 = CPyList_Extend(cpy_r_r12, cpy_r_r8);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL59;
    } else
        goto CPyL60;
CPyL12: ;
    cpy_r_r16 = PyDict_New();
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r17 = CPyDict_UpdateInDisplay(cpy_r_r16, cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r18 = cpy_r_r17 >= 0;
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r19 = PyList_AsTuple(cpy_r_r12);
    CPy_DECREF_NO_IMM(cpy_r_r12);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r20 = PyObject_Call(cpy_r_r11, cpy_r_r19, cpy_r_r16);
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r19);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r21 = CPy_GetCoro(cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    if (((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14 != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14);
    }
    ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14 = cpy_r_r21;
    cpy_r_r22 = 1;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r23 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14;
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__14", -1, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_INCREF(cpy_r_r23);
CPyL19: ;
    cpy_r_r24 = CPyIter_Next(cpy_r_r23);
    CPy_DECREF(cpy_r_r23);
    if (cpy_r_r24 != NULL) goto CPyL22;
    cpy_r_r25 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r26 = cpy_r_r25;
    cpy_r_r27 = NULL;
    if (((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14 != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14);
    }
    ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14 = cpy_r_r27;
    cpy_r_r28 = 1;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL63;
    } else
        goto CPyL44;
CPyL22: ;
    cpy_r_r29 = cpy_r_r24;
CPyL23: ;
    ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 1;
    return cpy_r_r29;
CPyL24: ;
    cpy_r_r31 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r32 = cpy_r_type != cpy_r_r31;
    if (!cpy_r_r32) goto CPyL64;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL28;
    } else
        goto CPyL65;
CPyL26: ;
    CPy_Unreachable();
CPyL27: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL39;
CPyL28: ;
    cpy_r_r33 = CPy_CatchError();
    if (((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15.f0 != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15.f0);
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15.f1);
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15.f2);
    }
    ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15 = cpy_r_r33;
    cpy_r_r34 = 1;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r35 = (PyObject **)&cpy_r_r1;
    cpy_r_r36 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14;
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__14", -1, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_INCREF(cpy_r_r36);
CPyL30: ;
    cpy_r_r37 = CPy_YieldFromErrorHandle(cpy_r_r36, cpy_r_r35);
    CPy_DecRef(cpy_r_r36);
    if (unlikely(cpy_r_r37 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL66;
    }
    if (cpy_r_r37) goto CPyL34;
    cpy_r_r29 = cpy_r_r1;
    cpy_r_r38 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15;
    if (unlikely(cpy_r_r38.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__15", -1, CPyStatic_globals);
        goto CPyL67;
    }
    CPy_INCREF(cpy_r_r38.f0);
    CPy_INCREF(cpy_r_r38.f1);
    CPy_INCREF(cpy_r_r38.f2);
CPyL33: ;
    CPy_RestoreExcInfo(cpy_r_r38);
    CPy_DecRef(cpy_r_r38.f0);
    CPy_DecRef(cpy_r_r38.f1);
    CPy_DecRef(cpy_r_r38.f2);
    goto CPyL23;
CPyL34: ;
    cpy_r_r26 = cpy_r_r1;
    cpy_r_r39 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15;
    if (unlikely(cpy_r_r39.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__15", -1, CPyStatic_globals);
        goto CPyL68;
    }
    CPy_INCREF(cpy_r_r39.f0);
    CPy_INCREF(cpy_r_r39.f1);
    CPy_INCREF(cpy_r_r39.f2);
CPyL35: ;
    CPy_RestoreExcInfo(cpy_r_r39);
    CPy_DecRef(cpy_r_r39.f0);
    CPy_DecRef(cpy_r_r39.f1);
    CPy_DecRef(cpy_r_r39.f2);
    goto CPyL44;
CPyL36: ;
    cpy_r_r40 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15;
    if (unlikely(cpy_r_r40.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__15", -1, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_INCREF(cpy_r_r40.f0);
    CPy_INCREF(cpy_r_r40.f1);
    CPy_INCREF(cpy_r_r40.f2);
CPyL37: ;
    CPy_RestoreExcInfo(cpy_r_r40);
    CPy_DecRef(cpy_r_r40.f0);
    CPy_DecRef(cpy_r_r40.f1);
    CPy_DecRef(cpy_r_r40.f2);
    cpy_r_r41 = CPy_KeepPropagating();
    if (!cpy_r_r41) goto CPyL53;
    CPy_Unreachable();
CPyL39: ;
    cpy_r_r42 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14;
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__14", -1, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_INCREF(cpy_r_r42);
CPyL40: ;
    cpy_r_r43 = CPyIter_Send(cpy_r_r42, cpy_r_arg);
    CPy_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r43 == NULL) goto CPyL42;
    cpy_r_r29 = cpy_r_r43;
    goto CPyL23;
CPyL42: ;
    cpy_r_r44 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r26 = cpy_r_r44;
CPyL44: ;
    ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL48;
    CPyGen_SetStopIterationValue(cpy_r_r26);
    CPy_DECREF(cpy_r_r26);
    if (!0) goto CPyL53;
    CPy_Unreachable();
CPyL48: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r26;
    return 0;
CPyL49: ;
    cpy_r_r46 = cpy_r_r2 == 0;
    if (cpy_r_r46) goto CPyL70;
    cpy_r_r47 = cpy_r_r2 == 1;
    if (cpy_r_r47) {
        goto CPyL24;
    } else
        goto CPyL71;
CPyL51: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r48 = 0;
    if (unlikely(!cpy_r_r48)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_Unreachable();
CPyL53: ;
    cpy_r_r49 = NULL;
    return cpy_r_r49;
CPyL54: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL53;
CPyL55: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r7);
    goto CPyL53;
CPyL56: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r8);
    goto CPyL53;
CPyL57: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    goto CPyL53;
CPyL58: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r11);
    goto CPyL53;
CPyL59: ;
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r12);
    goto CPyL53;
CPyL60: ;
    CPy_DECREF(cpy_r_r15);
    goto CPyL12;
CPyL61: ;
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r16);
    goto CPyL53;
CPyL62: ;
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r16);
    goto CPyL53;
CPyL63: ;
    CPy_DecRef(cpy_r_r26);
    goto CPyL53;
CPyL64: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL27;
CPyL65: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL26;
CPyL66: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL36;
CPyL67: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL36;
CPyL68: ;
    CPy_DecRef(cpy_r_r26);
    goto CPyL36;
CPyL69: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL53;
CPyL70: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL1;
CPyL71: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL51;
}

PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0, 0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___call___3__LRUCacheWrapperInstanceMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.__call____LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__next__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg, 0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___call___3__LRUCacheWrapperInstanceMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.__call____LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "send", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___call___3__LRUCacheWrapperInstanceMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.__call____LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__iter__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0, 0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___call___3__LRUCacheWrapperInstanceMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.__call____LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "throw", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp33 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp33);
    PyObject *__tmp34 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp34);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___call___3__LRUCacheWrapperInstanceMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.__call____LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "close", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType___call___3__LRUCacheWrapperInstanceMethod_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("async_lru.__call____LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__await__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapperInstanceMethod_____call__(PyObject *cpy_r_self, PyObject *cpy_r_fn_args, PyObject *cpy_r_fn_kwargs) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    cpy_r_r0 = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL5;
    }
    ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    CPy_INCREF_NO_IMM(cpy_r_self);
    if (((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self != NULL) {
        CPy_DECREF_NO_IMM(((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self);
    }
    ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self = cpy_r_self;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_fn_args);
    if (((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_args != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_args);
    }
    ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_args = cpy_r_fn_args;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_fn_kwargs);
    if (((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_kwargs != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_kwargs);
    }
    ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_kwargs = cpy_r_fn_kwargs;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    return cpy_r_r0;
CPyL5: ;
    cpy_r_r5 = NULL;
    return cpy_r_r5;
CPyL6: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy__LRUCacheWrapperInstanceMethod_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {"%:__call__", kwlist, 0};
    PyObject *obj_fn_args;
    PyObject *obj_fn_kwargs;
    if (!CPyArg_ParseStackAndKeywords(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_fn_args, &obj_fn_kwargs)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__LRUCacheWrapperInstanceMethod))
        arg_self = obj_self;
    else {
        CPy_TypeError("async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
        goto fail;
    }
    PyObject *arg_fn_args = obj_fn_args;
    PyObject *arg_fn_kwargs = obj_fn_kwargs;
    PyObject *retval = CPyDef__LRUCacheWrapperInstanceMethod_____call__(arg_self, arg_fn_args, arg_fn_kwargs);
    CPy_DECREF(obj_fn_args);
    CPy_DECREF(obj_fn_kwargs);
    return retval;
fail: ;
    CPy_DECREF(obj_fn_args);
    CPy_DECREF(obj_fn_kwargs);
    CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_wrapper__make_wrapper_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = cpy_r_instance == cpy_r_r0;
    if (!cpy_r_r1) goto CPyL2;
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
CPyL2: ;
    cpy_r_r2 = PyMethod_New(cpy_r___mypyc_self__, cpy_r_instance);
    if (cpy_r_r2 == NULL) goto CPyL4;
    return cpy_r_r2;
CPyL4: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy_wrapper__make_wrapper_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"instance", "owner", 0};
    static CPyArg_Parser parser = {"OO:__get__", kwlist, 0};
    PyObject *obj_instance;
    PyObject *obj_owner;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_instance, &obj_owner)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_instance = obj_instance;
    PyObject *arg_owner = obj_owner;
    PyObject *retval = CPyDef_wrapper__make_wrapper_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_wrapper__make_wrapper_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_fn) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_origin;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    tuple_T2OO cpy_r_r5;
    PyObject *cpy_r_r6;
    int32_t cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject **cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject **cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    CPyPtr cpy_r_r34;
    CPyPtr cpy_r_r35;
    CPyPtr cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject **cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    char cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject **cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_wrapper;
    char cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    char cpy_r_r57;
    PyObject **cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    cpy_r_r0 = ((async_lru___wrapper__make_wrapper_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "wrapper", "wrapper__make_wrapper_obj", "__mypyc_env__", 374, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    CPy_INCREF(cpy_r_fn);
    cpy_r_origin = cpy_r_fn;
CPyL2: ;
    cpy_r_r1 = CPyStatic_partial;
    if (unlikely(cpy_r_r1 == NULL)) {
        goto CPyL51;
    } else
        goto CPyL5;
CPyL3: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"partial\" was not set");
    cpy_r_r2 = 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r3 = CPyStatic_partialmethod;
    if (unlikely(cpy_r_r3 == NULL)) {
        goto CPyL52;
    } else
        goto CPyL8;
CPyL6: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"partialmethod\" was not set");
    cpy_r_r4 = 0;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL8: ;
    CPy_INCREF(cpy_r_r1);
    CPy_INCREF(cpy_r_r3);
    cpy_r_r5.f0 = cpy_r_r1;
    cpy_r_r5.f1 = cpy_r_r3;
    cpy_r_r6 = PyTuple_New(2);
    if (unlikely(cpy_r_r6 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp35 = cpy_r_r5.f0;
    PyTuple_SET_ITEM(cpy_r_r6, 0, __tmp35);
    PyObject *__tmp36 = cpy_r_r5.f1;
    PyTuple_SET_ITEM(cpy_r_r6, 1, __tmp36);
    cpy_r_r7 = PyObject_IsInstance(cpy_r_origin, cpy_r_r6);
    CPy_DECREF(cpy_r_r6);
    cpy_r_r8 = cpy_r_r7 >= 0;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r9 = cpy_r_r7;
    if (!cpy_r_r9) goto CPyL12;
    cpy_r_r10 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'func' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_origin, cpy_r_r10);
    CPy_DECREF(cpy_r_origin);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_origin = cpy_r_r11;
    goto CPyL2;
CPyL12: ;
    cpy_r_r12 = CPyStatic_iscoroutinefunction;
    if (unlikely(cpy_r_r12 == NULL)) {
        goto CPyL55;
    } else
        goto CPyL15;
CPyL13: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"iscoroutinefunction\" was not set");
    cpy_r_r13 = 0;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL15: ;
    PyObject *cpy_r_r14[1] = {cpy_r_origin};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = PyObject_Vectorcall(cpy_r_r12, cpy_r_r15, 1, 0);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_DECREF(cpy_r_origin);
    if (unlikely(!PyBool_Check(cpy_r_r16))) {
        CPy_TypeError("bool", cpy_r_r16); cpy_r_r17 = 2;
    } else
        cpy_r_r17 = cpy_r_r16 == Py_True;
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL54;
    }
    if (cpy_r_r17) goto CPyL32;
    cpy_r_r18 = CPyStatic_ALLOW_SYNC;
    if (unlikely(cpy_r_r18 == NULL)) {
        goto CPyL56;
    } else
        goto CPyL21;
CPyL19: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"ALLOW_SYNC\" was not set");
    cpy_r_r19 = 0;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL21: ;
    cpy_r_r20 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r21 = cpy_r_r18 != cpy_r_r20;
    if (!cpy_r_r21) goto CPyL57;
    CPy_INCREF(cpy_r_r18);
    if (likely(cpy_r_r18 != Py_None))
        cpy_r_r22 = cpy_r_r18;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "wrapper", 380, CPyStatic_globals, "str", cpy_r_r18);
        goto CPyL54;
    }
    cpy_r_r23 = CPyStr_IsTrue(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (cpy_r_r23) {
        goto CPyL32;
    } else
        goto CPyL57;
CPyL24: ;
    cpy_r_r24 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '' */
    cpy_r_r25 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Coroutine function is required, got ' */
    cpy_r_r26 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '{!r:{}}' */
    cpy_r_r27 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '' */
    cpy_r_r28 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'format' */
    PyObject *cpy_r_r29[3] = {cpy_r_r26, cpy_r_fn, cpy_r_r27};
    cpy_r_r30 = (PyObject **)&cpy_r_r29;
    cpy_r_r31 = PyObject_VectorcallMethod(cpy_r_r28, cpy_r_r30, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    if (likely(PyUnicode_Check(cpy_r_r31)))
        cpy_r_r32 = cpy_r_r31;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "wrapper", 381, CPyStatic_globals, "str", cpy_r_r31);
        goto CPyL50;
    }
    cpy_r_r33 = PyList_New(2);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r34 = (CPyPtr)&((PyListObject *)cpy_r_r33)->ob_item;
    cpy_r_r35 = *(CPyPtr *)cpy_r_r34;
    CPy_INCREF(cpy_r_r25);
    *(PyObject * *)cpy_r_r35 = cpy_r_r25;
    cpy_r_r36 = cpy_r_r35 + 8;
    *(PyObject * *)cpy_r_r36 = cpy_r_r32;
    cpy_r_r37 = PyUnicode_Join(cpy_r_r24, cpy_r_r33);
    CPy_DECREF_NO_IMM(cpy_r_r33);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r38 = CPyModule_builtins;
    cpy_r_r39 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'RuntimeError' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL59;
    }
    PyObject *cpy_r_r41[1] = {cpy_r_r37};
    cpy_r_r42 = (PyObject **)&cpy_r_r41;
    cpy_r_r43 = PyObject_Vectorcall(cpy_r_r40, cpy_r_r42, 1, 0);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL59;
    }
    CPy_DECREF(cpy_r_r37);
    CPy_Raise(cpy_r_r43);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL32: ;
    cpy_r_r44 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_make_unbound_method' */
    cpy_r_r45 = PyObject_HasAttr(cpy_r_fn, cpy_r_r44);
    if (!cpy_r_r45) goto CPyL60;
    cpy_r_r46 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_make_unbound_method' */
    PyObject *cpy_r_r47[1] = {cpy_r_fn};
    cpy_r_r48 = (PyObject **)&cpy_r_r47;
    cpy_r_r49 = PyObject_VectorcallMethod(cpy_r_r46, cpy_r_r48, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_fn = cpy_r_r49;
CPyL35: ;
    cpy_r_r50 = ((async_lru____make_wrapper_envObject *)cpy_r_r0)->_maxsize;
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "wrapper", "_make_wrapper_env", "maxsize", 387, CPyStatic_globals);
        goto CPyL61;
    }
    CPy_INCREF(cpy_r_r50);
CPyL36: ;
    cpy_r_r51 = ((async_lru____make_wrapper_envObject *)cpy_r_r0)->_typed;
    if (unlikely(cpy_r_r51 == 2)) {
        CPy_AttributeError("async_lru/__init__.py", "wrapper", "_make_wrapper_env", "typed", 387, CPyStatic_globals);
        goto CPyL62;
    }
CPyL37: ;
    cpy_r_r52 = ((async_lru____make_wrapper_envObject *)cpy_r_r0)->_ttl;
    if (unlikely(cpy_r_r52 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'ttl' of '_make_wrapper_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r52);
    }
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL63;
    }
CPyL38: ;
    cpy_r_r53 = CPyDef__LRUCacheWrapper(cpy_r_fn, cpy_r_r50, cpy_r_r51, cpy_r_r52);
    CPy_DECREF(cpy_r_fn);
    CPy_DECREF(cpy_r_r50);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_wrapper = cpy_r_r53;
    cpy_r_r54 = CPyStatic__PYTHON_GTE_312;
    if (unlikely(cpy_r_r54 == 2)) {
        goto CPyL64;
    } else
        goto CPyL42;
CPyL40: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_PYTHON_GTE_312\" was not set");
    cpy_r_r55 = 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL42: ;
    if (!cpy_r_r54) goto CPyL49;
    cpy_r_r56 = CPyStatic_markcoroutinefunction;
    if (unlikely(cpy_r_r56 == NULL)) {
        goto CPyL65;
    } else
        goto CPyL46;
CPyL44: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"markcoroutinefunction\" was not set");
    cpy_r_r57 = 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL46: ;
    PyObject *cpy_r_r58[1] = {cpy_r_wrapper};
    cpy_r_r59 = (PyObject **)&cpy_r_r58;
    cpy_r_r60 = PyObject_Vectorcall(cpy_r_r56, cpy_r_r59, 1, 0);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_DECREF_NO_IMM(cpy_r_wrapper);
    if (likely(Py_TYPE(cpy_r_r60) == CPyType__LRUCacheWrapper))
        cpy_r_r61 = cpy_r_r60;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "wrapper", 389, CPyStatic_globals, "async_lru._LRUCacheWrapper", cpy_r_r60);
        goto CPyL50;
    }
    cpy_r_wrapper = cpy_r_r61;
CPyL49: ;
    return cpy_r_wrapper;
CPyL50: ;
    cpy_r_r62 = NULL;
    return cpy_r_r62;
CPyL51: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_origin);
    goto CPyL3;
CPyL52: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_origin);
    goto CPyL6;
CPyL53: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_origin);
    goto CPyL50;
CPyL54: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL50;
CPyL55: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_origin);
    goto CPyL13;
CPyL56: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL19;
CPyL57: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    goto CPyL24;
CPyL58: ;
    CPy_DecRef(cpy_r_r32);
    goto CPyL50;
CPyL59: ;
    CPy_DecRef(cpy_r_r37);
    goto CPyL50;
CPyL60: ;
    CPy_INCREF(cpy_r_fn);
    goto CPyL35;
CPyL61: ;
    CPy_DecRef(cpy_r_fn);
    CPy_DecRef(cpy_r_r0);
    goto CPyL50;
CPyL62: ;
    CPy_DecRef(cpy_r_fn);
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r50);
    goto CPyL50;
CPyL63: ;
    CPy_DecRef(cpy_r_fn);
    CPy_DecRef(cpy_r_r50);
    goto CPyL50;
CPyL64: ;
    CPy_DecRef(cpy_r_wrapper);
    goto CPyL40;
CPyL65: ;
    CPy_DecRef(cpy_r_wrapper);
    goto CPyL44;
CPyL66: ;
    CPy_DecRef(cpy_r_wrapper);
    goto CPyL50;
}

PyObject *CPyPy_wrapper__make_wrapper_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"fn", 0};
    static CPyArg_Parser parser = {"O:__call__", kwlist, 0};
    PyObject *obj_fn;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_fn)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_fn = obj_fn;
    PyObject *retval = CPyDef_wrapper__make_wrapper_obj_____call__(arg___mypyc_self__, arg_fn);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__make_wrapper(PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_wrapper;
    PyObject *cpy_r_r7;
    if (cpy_r_ttl != NULL) goto CPyL10;
    cpy_r_r0 = Py_None;
    cpy_r_ttl = cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = CPyDef__make_wrapper_env();
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_INCREF(cpy_r_maxsize);
    if (((async_lru____make_wrapper_envObject *)cpy_r_r1)->_maxsize != NULL) {
        CPy_DECREF(((async_lru____make_wrapper_envObject *)cpy_r_r1)->_maxsize);
    }
    ((async_lru____make_wrapper_envObject *)cpy_r_r1)->_maxsize = cpy_r_maxsize;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL12;
    }
    ((async_lru____make_wrapper_envObject *)cpy_r_r1)->_typed = cpy_r_typed;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL12;
    }
    if (((async_lru____make_wrapper_envObject *)cpy_r_r1)->_ttl != NULL) {
        CPy_DECREF(((async_lru____make_wrapper_envObject *)cpy_r_r1)->_ttl);
    }
    ((async_lru____make_wrapper_envObject *)cpy_r_r1)->_ttl = cpy_r_ttl;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r5 = CPyDef_wrapper__make_wrapper_obj();
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL13;
    }
    if (((async_lru___wrapper__make_wrapper_objObject *)cpy_r_r5)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((async_lru___wrapper__make_wrapper_objObject *)cpy_r_r5)->___mypyc_env__);
    }
    ((async_lru___wrapper__make_wrapper_objObject *)cpy_r_r5)->___mypyc_env__ = cpy_r_r1;
    cpy_r_r6 = 1;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_wrapper = cpy_r_r5;
    return cpy_r_wrapper;
CPyL9: ;
    cpy_r_r7 = NULL;
    return cpy_r_r7;
CPyL10: ;
    CPy_INCREF(cpy_r_ttl);
    goto CPyL2;
CPyL11: ;
    CPy_DecRef(cpy_r_ttl);
    goto CPyL9;
CPyL12: ;
    CPy_DecRef(cpy_r_ttl);
    CPy_DecRef(cpy_r_r1);
    goto CPyL9;
CPyL13: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL9;
CPyL14: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL9;
}

PyObject *CPyPy__make_wrapper(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"maxsize", "typed", "ttl", 0};
    static CPyArg_Parser parser = {"OO|O:_make_wrapper", kwlist, 0};
    PyObject *obj_maxsize;
    PyObject *obj_typed;
    PyObject *obj_ttl = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_maxsize, &obj_typed, &obj_ttl)) {
        return NULL;
    }
    PyObject *arg_maxsize;
    if (PyLong_Check(obj_maxsize))
        arg_maxsize = obj_maxsize;
    else {
        arg_maxsize = NULL;
    }
    if (arg_maxsize != NULL) goto __LL37;
    if (obj_maxsize == Py_None)
        arg_maxsize = obj_maxsize;
    else {
        arg_maxsize = NULL;
    }
    if (arg_maxsize != NULL) goto __LL37;
    CPy_TypeError("int or None", obj_maxsize); 
    goto fail;
__LL37: ;
    char arg_typed;
    if (unlikely(!PyBool_Check(obj_typed))) {
        CPy_TypeError("bool", obj_typed); goto fail;
    } else
        arg_typed = obj_typed == Py_True;
    PyObject *arg_ttl;
    if (obj_ttl == NULL) {
        arg_ttl = NULL;
        goto __LL38;
    }
    if (CPyFloat_Check(obj_ttl))
        arg_ttl = obj_ttl;
    else {
        arg_ttl = NULL;
    }
    if (arg_ttl != NULL) goto __LL38;
    if (obj_ttl == Py_None)
        arg_ttl = obj_ttl;
    else {
        arg_ttl = NULL;
    }
    if (arg_ttl != NULL) goto __LL38;
    CPy_TypeError("float or None", obj_ttl); 
    goto fail;
__LL38: ;
    PyObject *retval = CPyDef__make_wrapper(arg_maxsize, arg_typed, arg_ttl);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_alru_cache(PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_fn;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject **cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    CPyPtr cpy_r_r32;
    CPyPtr cpy_r_r33;
    CPyPtr cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    if (cpy_r_maxsize != NULL) goto CPyL28;
    cpy_r_r0 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 128 */
    cpy_r_maxsize = cpy_r_r0;
CPyL2: ;
    if (cpy_r_typed != 2) goto CPyL4;
    cpy_r_typed = 0;
CPyL4: ;
    if (cpy_r_ttl != NULL) goto CPyL29;
    cpy_r_r1 = Py_None;
    cpy_r_ttl = cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r3 = cpy_r_maxsize == cpy_r_r2;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = PyLong_Check(cpy_r_maxsize);
    if (!cpy_r_r4) goto CPyL30;
CPyL8: ;
    if (PyLong_Check(cpy_r_maxsize))
        cpy_r_r5 = cpy_r_maxsize;
    else {
        cpy_r_r5 = NULL;
    }
    if (cpy_r_r5 != NULL) goto __LL39;
    if (cpy_r_maxsize == Py_None)
        cpy_r_r5 = cpy_r_maxsize;
    else {
        cpy_r_r5 = NULL;
    }
    if (cpy_r_r5 != NULL) goto __LL39;
    CPy_TypeErrorTraceback("async_lru/__init__.py", "alru_cache", 420, CPyStatic_globals, "int or None", cpy_r_maxsize);
    goto CPyL31;
__LL39: ;
    cpy_r_r6 = CPyDef__make_wrapper(cpy_r_r5, cpy_r_typed, cpy_r_ttl);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_ttl);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL27;
    }
    return cpy_r_r6;
CPyL11: ;
    cpy_r_fn = cpy_r_maxsize;
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'callable' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    }
    PyObject *cpy_r_r10[1] = {cpy_r_fn};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_Vectorcall(cpy_r_r9, cpy_r_r11, 1, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    }
    if (unlikely(!PyBool_Check(cpy_r_r12))) {
        CPy_TypeError("bool", cpy_r_r12); cpy_r_r13 = 2;
    } else
        cpy_r_r13 = cpy_r_r12 == Py_True;
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r13 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    }
    if (cpy_r_r13) goto CPyL16;
    cpy_r_r14 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_make_unbound_method' */
    cpy_r_r15 = PyObject_HasAttr(cpy_r_fn, cpy_r_r14);
    if (!cpy_r_r15) goto CPyL20;
CPyL16: ;
    cpy_r_r16 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 128 */
    cpy_r_r17 = Py_None;
    cpy_r_r18 = CPyDef__make_wrapper(cpy_r_r16, 0, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    }
    PyObject *cpy_r_r19[1] = {cpy_r_fn};
    cpy_r_r20 = (PyObject **)&cpy_r_r19;
    cpy_r_r21 = PyObject_Vectorcall(cpy_r_r18, cpy_r_r20, 1, 0);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_DECREF(cpy_r_fn);
    if (likely(Py_TYPE(cpy_r_r21) == CPyType__LRUCacheWrapper))
        cpy_r_r22 = cpy_r_r21;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "alru_cache", 425, CPyStatic_globals, "async_lru._LRUCacheWrapper", cpy_r_r21);
        goto CPyL27;
    }
    return cpy_r_r22;
CPyL20: ;
    cpy_r_r23 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '' */
    cpy_r_r24 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '{!r:{}}' */
    cpy_r_r25 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '' */
    cpy_r_r26 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'format' */
    PyObject *cpy_r_r27[3] = {cpy_r_r24, cpy_r_fn, cpy_r_r25};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = PyObject_VectorcallMethod(cpy_r_r26, cpy_r_r28, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_DECREF(cpy_r_fn);
    cpy_r_r30 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ' decorating is not supported' */
    cpy_r_r31 = PyList_New(2);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r32 = (CPyPtr)&((PyListObject *)cpy_r_r31)->ob_item;
    cpy_r_r33 = *(CPyPtr *)cpy_r_r32;
    *(PyObject * *)cpy_r_r33 = cpy_r_r29;
    CPy_INCREF(cpy_r_r30);
    cpy_r_r34 = cpy_r_r33 + 8;
    *(PyObject * *)cpy_r_r34 = cpy_r_r30;
    cpy_r_r35 = PyUnicode_Join(cpy_r_r23, cpy_r_r31);
    CPy_DECREF_NO_IMM(cpy_r_r31);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r36 = CPyModule_builtins;
    cpy_r_r37 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'NotImplementedError' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_r36, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL34;
    }
    PyObject *cpy_r_r39[1] = {cpy_r_r35};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = PyObject_Vectorcall(cpy_r_r38, cpy_r_r40, 1, 0);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_DECREF(cpy_r_r35);
    CPy_Raise(cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_Unreachable();
CPyL27: ;
    cpy_r_r42 = NULL;
    return cpy_r_r42;
CPyL28: ;
    CPy_INCREF(cpy_r_maxsize);
    goto CPyL2;
CPyL29: ;
    CPy_INCREF(cpy_r_ttl);
    goto CPyL6;
CPyL30: ;
    CPy_DECREF(cpy_r_ttl);
    goto CPyL11;
CPyL31: ;
    CPy_DecRef(cpy_r_ttl);
    goto CPyL27;
CPyL32: ;
    CPy_DecRef(cpy_r_fn);
    goto CPyL27;
CPyL33: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL27;
CPyL34: ;
    CPy_DecRef(cpy_r_r35);
    goto CPyL27;
}

PyObject *CPyPy_alru_cache(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"maxsize", "typed", "ttl", 0};
    static CPyArg_Parser parser = {"|OO$O:alru_cache", kwlist, 0};
    PyObject *obj_maxsize = NULL;
    PyObject *obj_typed = NULL;
    PyObject *obj_ttl = NULL;
    if (!CPyArg_ParseStackAndKeywords(args, nargs, kwnames, &parser, &obj_maxsize, &obj_typed, &obj_ttl)) {
        return NULL;
    }
    PyObject *arg_maxsize;
    if (obj_maxsize == NULL) {
        arg_maxsize = NULL;
        goto __LL40;
    }
    if (PyLong_Check(obj_maxsize))
        arg_maxsize = obj_maxsize;
    else {
        arg_maxsize = NULL;
    }
    if (arg_maxsize != NULL) goto __LL40;
    if (obj_maxsize == Py_None)
        arg_maxsize = obj_maxsize;
    else {
        arg_maxsize = NULL;
    }
    if (arg_maxsize != NULL) goto __LL40;
    arg_maxsize = obj_maxsize;
    if (arg_maxsize != NULL) goto __LL40;
    CPy_TypeError("union[int, None, object]", obj_maxsize); 
    goto fail;
__LL40: ;
    char arg_typed;
    if (obj_typed == NULL) {
        arg_typed = 2;
    } else if (unlikely(!PyBool_Check(obj_typed))) {
        CPy_TypeError("bool", obj_typed); goto fail;
    } else
        arg_typed = obj_typed == Py_True;
    PyObject *arg_ttl;
    if (obj_ttl == NULL) {
        arg_ttl = NULL;
        goto __LL41;
    }
    if (CPyFloat_Check(obj_ttl))
        arg_ttl = obj_ttl;
    else {
        arg_ttl = NULL;
    }
    if (arg_ttl != NULL) goto __LL41;
    if (obj_ttl == Py_None)
        arg_ttl = obj_ttl;
    else {
        arg_ttl = NULL;
    }
    if (arg_ttl != NULL) goto __LL41;
    CPy_TypeError("float or None", obj_ttl); 
    goto fail;
__LL41: ;
    PyObject *retval = CPyDef_alru_cache(arg_maxsize, arg_typed, arg_ttl);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    PyObject **cpy_r_r6;
    PyObject **cpy_r_r7;
    PyObject **cpy_r_r8;
    PyObject **cpy_r_r9;
    PyObject **cpy_r_r10;
    PyObject **cpy_r_r11;
    void *cpy_r_r13;
    void *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    tuple_T2II cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    char cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    char cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    tuple_T2II cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    char cpy_r_r49;
    char cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    int32_t cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    tuple_T1O cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    int32_t cpy_r_r61;
    char cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject **cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    int32_t cpy_r_r74;
    char cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject **cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    int32_t cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject **cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    int32_t cpy_r_r96;
    char cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    tuple_T3OOO cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    int32_t cpy_r_r115;
    char cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    tuple_T2OO cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    int32_t cpy_r_r133;
    char cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    tuple_T3OOO cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    int32_t cpy_r_r172;
    char cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    tuple_T2II cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    char cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    int32_t cpy_r_r185;
    char cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    int32_t cpy_r_r192;
    char cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    int32_t cpy_r_r199;
    char cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    int32_t cpy_r_r206;
    char cpy_r_r207;
    PyObject *cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    int32_t cpy_r_r213;
    char cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    int32_t cpy_r_r220;
    char cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject *cpy_r_r225;
    PyObject *cpy_r_r226;
    int32_t cpy_r_r227;
    char cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject *cpy_r_r230;
    PyObject *cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject *cpy_r_r233;
    int32_t cpy_r_r234;
    char cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_r238;
    PyObject *cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    int32_t cpy_r_r242;
    char cpy_r_r243;
    PyObject *cpy_r_r244;
    PyObject *cpy_r_r245;
    PyObject *cpy_r_r246;
    PyObject *cpy_r_r247;
    tuple_T2II cpy_r_r248;
    PyObject *cpy_r_r249;
    PyObject *cpy_r_r250;
    char cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_r255;
    PyObject *cpy_r_r256;
    int32_t cpy_r_r257;
    char cpy_r_r258;
    char cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject *cpy_r_r262;
    PyObject *cpy_r_r263;
    PyObject **cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    int32_t cpy_r_r269;
    char cpy_r_r270;
    PyObject *cpy_r_r271;
    PyObject *cpy_r_r272;
    char cpy_r_r273;
    PyObject *cpy_r_r274;
    PyObject *cpy_r_r275;
    PyObject *cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject *cpy_r_r278;
    PyObject *cpy_r_r279;
    PyObject *cpy_r_r280;
    PyObject *cpy_r_r281;
    PyObject *cpy_r_r282;
    PyObject *cpy_r_r283;
    char cpy_r_r284;
    PyObject *cpy_r_r285;
    PyObject *cpy_r_r286;
    PyObject *cpy_r_r287;
    PyObject *cpy_r_r288;
    PyObject *cpy_r_r289;
    PyObject *cpy_r_r290;
    PyObject *cpy_r_r291;
    PyObject *cpy_r_r292;
    char cpy_r_r293;
    PyObject *cpy_r_r294;
    PyObject *cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject **cpy_r_r298;
    PyObject *cpy_r_r299;
    PyObject *cpy_r_r300;
    PyObject *cpy_r_r301;
    PyObject *cpy_r_r302;
    PyObject *cpy_r_r303;
    PyObject *cpy_r_r304;
    PyObject *cpy_r_r305;
    int32_t cpy_r_r306;
    char cpy_r_r307;
    PyObject *cpy_r_r308;
    PyObject *cpy_r_r309;
    int32_t cpy_r_r310;
    char cpy_r_r311;
    PyObject *cpy_r_r312;
    PyObject *cpy_r_r313;
    int32_t cpy_r_r314;
    char cpy_r_r315;
    PyObject *cpy_r_r316;
    PyObject *cpy_r_r317;
    int32_t cpy_r_r318;
    char cpy_r_r319;
    PyObject *cpy_r_r320;
    PyObject *cpy_r_r321;
    int32_t cpy_r_r322;
    char cpy_r_r323;
    PyObject *cpy_r_r324;
    PyObject *cpy_r_r325;
    int32_t cpy_r_r326;
    char cpy_r_r327;
    PyObject *cpy_r_r328;
    PyObject *cpy_r_r329;
    int32_t cpy_r_r330;
    char cpy_r_r331;
    PyObject **cpy_r_r333;
    PyObject *cpy_r_r334;
    PyObject *cpy_r_r335;
    PyObject *cpy_r_r336;
    PyObject *cpy_r_r337;
    PyObject **cpy_r_r339;
    PyObject *cpy_r_r340;
    PyObject *cpy_r_r341;
    PyObject *cpy_r_r342;
    int32_t cpy_r_r343;
    char cpy_r_r344;
    PyObject *cpy_r_r345;
    PyObject *cpy_r_r346;
    PyObject *cpy_r_r347;
    PyObject *cpy_r_r348;
    PyObject *cpy_r_r349;
    PyObject *cpy_r_r350;
    PyObject *cpy_r_r351;
    PyObject *cpy_r_r352;
    PyObject *cpy_r_r353;
    PyObject *cpy_r_r354;
    PyObject *cpy_r_r355;
    PyObject *cpy_r_r356;
    char cpy_r_r357;
    PyObject *cpy_r_r358;
    PyObject *cpy_r_r359;
    PyObject *cpy_r_r360;
    PyObject *cpy_r_r361;
    PyObject *cpy_r_r362;
    PyObject *cpy_r_r363;
    int32_t cpy_r_r364;
    char cpy_r_r365;
    PyObject *cpy_r_r366;
    PyObject *cpy_r_r367;
    int32_t cpy_r_r368;
    char cpy_r_r369;
    PyObject *cpy_r_r370;
    tuple_T0 cpy_r_r371;
    PyObject *cpy_r_r372;
    PyObject *cpy_r_r373;
    PyObject *cpy_r_r374;
    PyObject *cpy_r_r375;
    PyObject *cpy_r_r376;
    PyObject *cpy_r_r377;
    int32_t cpy_r_r378;
    char cpy_r_r379;
    PyObject *cpy_r_r380;
    PyObject *cpy_r_r381;
    int32_t cpy_r_r382;
    char cpy_r_r383;
    PyObject *cpy_r_r384;
    PyObject *cpy_r_r385;
    int32_t cpy_r_r386;
    char cpy_r_r387;
    PyObject *cpy_r_r388;
    int32_t cpy_r_r389;
    char cpy_r_r390;
    PyObject *cpy_r_r391;
    PyObject *cpy_r_r392;
    int32_t cpy_r_r393;
    char cpy_r_r394;
    PyObject *cpy_r_r395;
    PyObject *cpy_r_r396;
    int32_t cpy_r_r397;
    char cpy_r_r398;
    PyObject *cpy_r_r399;
    PyObject *cpy_r_r400;
    PyObject *cpy_r_r401;
    PyObject *cpy_r_r402;
    char cpy_r_r403;
    PyObject *cpy_r_r404;
    PyObject *cpy_r_r405;
    PyObject *cpy_r_r406;
    PyObject *cpy_r_r407;
    PyObject *cpy_r_r408;
    PyObject *cpy_r_r409;
    PyObject *cpy_r_r410;
    PyObject *cpy_r_r411;
    PyObject *cpy_r_r412;
    PyObject *cpy_r_r413;
    PyObject *cpy_r_r414;
    char cpy_r_r415;
    PyObject *cpy_r_r416;
    PyObject *cpy_r_r417;
    PyObject *cpy_r_r418;
    PyObject *cpy_r_r419;
    PyObject *cpy_r_r420;
    PyObject *cpy_r_r421;
    PyObject *cpy_r_r422;
    PyObject *cpy_r_r423;
    PyObject *cpy_r_r424;
    PyObject *cpy_r_r425;
    PyObject *cpy_r_r426;
    PyObject *cpy_r_r427;
    PyObject *cpy_r_r428;
    PyObject *cpy_r_r429;
    PyObject *cpy_r_r430;
    PyObject *cpy_r_r431;
    PyObject *cpy_r_r432;
    int32_t cpy_r_r433;
    char cpy_r_r434;
    PyObject *cpy_r_r435;
    PyObject *cpy_r_r436;
    int32_t cpy_r_r437;
    char cpy_r_r438;
    PyObject *cpy_r_r439;
    PyObject *cpy_r_r440;
    PyObject *cpy_r_r441;
    PyObject *cpy_r_r442;
    PyObject *cpy_r_r443;
    PyObject *cpy_r_r444;
    PyObject *cpy_r_r445;
    PyObject *cpy_r_r446;
    PyObject *cpy_r_r447;
    tuple_T2OO cpy_r_r448;
    PyObject *cpy_r_r449;
    PyObject *cpy_r_r450;
    PyObject *cpy_r_r451;
    PyObject *cpy_r_r452;
    PyObject *cpy_r_r453;
    PyObject *cpy_r_r454;
    char cpy_r_r455;
    PyObject *cpy_r_r456;
    PyObject *cpy_r_r457;
    PyObject *cpy_r_r458;
    PyObject *cpy_r_r459;
    PyObject *cpy_r_r460;
    PyObject *cpy_r_r461;
    PyObject *cpy_r_r462;
    PyObject *cpy_r_r463;
    PyObject *cpy_r_r464;
    PyObject *cpy_r_r465;
    PyObject *cpy_r_r466;
    int32_t cpy_r_r467;
    char cpy_r_r468;
    PyObject *cpy_r_r469;
    PyObject *cpy_r_r470;
    int32_t cpy_r_r471;
    char cpy_r_r472;
    char cpy_r_r473;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL165;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_asyncio;
    cpy_r_r6 = (PyObject **)&CPyModule_dataclasses;
    cpy_r_r7 = (PyObject **)&CPyModule_functools;
    cpy_r_r8 = (PyObject **)&CPyModule_inspect;
    cpy_r_r9 = (PyObject **)&CPyModule_logging;
    cpy_r_r10 = (PyObject **)&CPyModule_os;
    cpy_r_r11 = (PyObject **)&CPyModule_sys;
    PyObject **cpy_r_r12[7] = {
        cpy_r_r5, cpy_r_r6, cpy_r_r7, cpy_r_r8, cpy_r_r9, cpy_r_r10,
        cpy_r_r11
    };
    cpy_r_r13 = (void *)&cpy_r_r12;
    int64_t cpy_r_r14[7] = {1, 2, 3, 4, 5, 6, 7};
    cpy_r_r15 = (void *)&cpy_r_r14;
    cpy_r_r16 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* (('asyncio', 'asyncio', 'asyncio'),
                                    ('dataclasses', 'dataclasses', 'dataclasses'),
                                    ('functools', 'functools', 'functools'),
                                    ('inspect', 'inspect', 'inspect'),
                                    ('logging', 'logging', 'logging'), ('os', 'os', 'os'),
                                    ('sys', 'sys', 'sys')) */
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru/__init__.py' */
    cpy_r_r19 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '<module>' */
    cpy_r_r20 = CPyImport_ImportMany(cpy_r_r16, cpy_r_r13, cpy_r_r17, cpy_r_r18, cpy_r_r19, cpy_r_r15);
    if (!cpy_r_r20) goto CPyL165;
    cpy_r_r21 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('_is_coroutine',) */
    cpy_r_r22 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'asyncio.coroutines' */
    cpy_r_r23 = CPyStatic_globals;
    cpy_r_r24 = CPyImport_ImportFromMany(cpy_r_r22, cpy_r_r21, cpy_r_r21, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyModule_asyncio___coroutines = cpy_r_r24;
    CPy_INCREF(CPyModule_asyncio___coroutines);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r25 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('Any', 'Callable', 'Coroutine', 'Final', 'Generic',
                                    'Hashable', 'List', 'Optional', 'OrderedDict', 'Type',
                                    'TypedDict', 'TypeVar', 'Union', 'cast', 'final',
                                    'overload') */
    cpy_r_r26 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r27 = CPyStatic_globals;
    cpy_r_r28 = CPyImport_ImportFromMany(cpy_r_r26, cpy_r_r25, cpy_r_r25, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyModule_typing = cpy_r_r28;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r28);
    cpy_r_r29 = CPyModule_sys;
    cpy_r_r30 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r31 = CPyObject_GetAttr(cpy_r_r29, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    if (likely(PyTuple_Check(cpy_r_r31)))
        cpy_r_r32 = cpy_r_r31;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "<module>", 29, CPyStatic_globals, "tuple", cpy_r_r31);
        goto CPyL165;
    }
    cpy_r_r33.f0 = 6;
    cpy_r_r33.f1 = 22;
    cpy_r_r34 = PyTuple_New(2);
    if (unlikely(cpy_r_r34 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp42 = CPyTagged_StealAsObject(cpy_r_r33.f0);
    PyTuple_SET_ITEM(cpy_r_r34, 0, __tmp42);
    PyObject *__tmp43 = CPyTagged_StealAsObject(cpy_r_r33.f1);
    PyTuple_SET_ITEM(cpy_r_r34, 1, __tmp43);
    cpy_r_r35 = PyObject_RichCompare(cpy_r_r32, cpy_r_r34, 5);
    CPy_DECREF(cpy_r_r32);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    if (unlikely(!PyBool_Check(cpy_r_r35))) {
        CPy_TypeError("bool", cpy_r_r35); cpy_r_r36 = 2;
    } else
        cpy_r_r36 = cpy_r_r35 == Py_True;
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r36 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    if (!cpy_r_r36) goto CPyL13;
    cpy_r_r37 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('Self',) */
    cpy_r_r38 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r39 = CPyStatic_globals;
    cpy_r_r40 = CPyImport_ImportFromMany(cpy_r_r38, cpy_r_r37, cpy_r_r37, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyModule_typing = cpy_r_r40;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r40);
    goto CPyL15;
CPyL13: ;
    PyErr_SetString(PyExc_RuntimeError, "Reached allegedly unreachable code!");
    cpy_r_r41 = 0;
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPy_Unreachable();
CPyL15: ;
    cpy_r_r42 = CPyModule_sys;
    cpy_r_r43 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r44 = CPyObject_GetAttr(cpy_r_r42, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    if (likely(PyTuple_Check(cpy_r_r44)))
        cpy_r_r45 = cpy_r_r44;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "<module>", 34, CPyStatic_globals, "tuple", cpy_r_r44);
        goto CPyL165;
    }
    cpy_r_r46.f0 = 6;
    cpy_r_r46.f1 = 28;
    cpy_r_r47 = PyTuple_New(2);
    if (unlikely(cpy_r_r47 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp44 = CPyTagged_StealAsObject(cpy_r_r46.f0);
    PyTuple_SET_ITEM(cpy_r_r47, 0, __tmp44);
    PyObject *__tmp45 = CPyTagged_StealAsObject(cpy_r_r46.f1);
    PyTuple_SET_ITEM(cpy_r_r47, 1, __tmp45);
    cpy_r_r48 = PyObject_RichCompare(cpy_r_r45, cpy_r_r47, 0);
    CPy_DECREF(cpy_r_r45);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    if (unlikely(!PyBool_Check(cpy_r_r48))) {
        CPy_TypeError("bool", cpy_r_r48); cpy_r_r49 = 2;
    } else
        cpy_r_r49 = cpy_r_r48 == Py_True;
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r49 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    if (!cpy_r_r49) goto CPyL22;
    PyErr_SetString(PyExc_RuntimeError, "Reached allegedly unreachable code!");
    cpy_r_r50 = 0;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPy_Unreachable();
CPyL22: ;
    cpy_r_r51 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '2.0.5' */
    cpy_r_r52 = CPyStatic_globals;
    cpy_r_r53 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__version__' */
    cpy_r_r54 = CPyDict_SetItem(cpy_r_r52, cpy_r_r53, cpy_r_r51);
    cpy_r_r55 = cpy_r_r54 >= 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r56 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'alru_cache' */
    CPy_INCREF(cpy_r_r56);
    cpy_r_r57.f0 = cpy_r_r56;
    cpy_r_r58 = CPyStatic_globals;
    cpy_r_r59 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__all__' */
    cpy_r_r60 = PyTuple_New(1);
    if (unlikely(cpy_r_r60 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp46 = cpy_r_r57.f0;
    PyTuple_SET_ITEM(cpy_r_r60, 0, __tmp46);
    cpy_r_r61 = CPyDict_SetItem(cpy_r_r58, cpy_r_r59, cpy_r_r60);
    CPy_DECREF(cpy_r_r60);
    cpy_r_r62 = cpy_r_r61 >= 0;
    if (unlikely(!cpy_r_r62)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r63 = CPyModule_os;
    cpy_r_r64 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'environ' */
    cpy_r_r65 = CPyObject_GetAttr(cpy_r_r63, cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r66 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'ASYNC_LRU_ALLOW_SYNC' */
    cpy_r_r67 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'get' */
    PyObject *cpy_r_r68[2] = {cpy_r_r65, cpy_r_r66};
    cpy_r_r69 = (PyObject **)&cpy_r_r68;
    cpy_r_r70 = PyObject_VectorcallMethod(cpy_r_r67, cpy_r_r69, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL166;
    }
    CPy_DECREF(cpy_r_r65);
    if (PyUnicode_Check(cpy_r_r70))
        cpy_r_r71 = cpy_r_r70;
    else {
        cpy_r_r71 = NULL;
    }
    if (cpy_r_r71 != NULL) goto __LL47;
    if (cpy_r_r70 == Py_None)
        cpy_r_r71 = cpy_r_r70;
    else {
        cpy_r_r71 = NULL;
    }
    if (cpy_r_r71 != NULL) goto __LL47;
    CPy_TypeErrorTraceback("async_lru/__init__.py", "<module>", 43, CPyStatic_globals, "str or None", cpy_r_r70);
    goto CPyL165;
__LL47: ;
    CPyStatic_ALLOW_SYNC = cpy_r_r71;
    CPy_INCREF(CPyStatic_ALLOW_SYNC);
    cpy_r_r72 = CPyStatic_globals;
    cpy_r_r73 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'ALLOW_SYNC' */
    cpy_r_r74 = CPyDict_SetItem(cpy_r_r72, cpy_r_r73, cpy_r_r71);
    CPy_DECREF(cpy_r_r71);
    cpy_r_r75 = cpy_r_r74 >= 0;
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r76 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_T' */
    cpy_r_r77 = CPyStatic_globals;
    cpy_r_r78 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'TypeVar' */
    cpy_r_r79 = CPyDict_GetItem(cpy_r_r77, cpy_r_r78);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    PyObject *cpy_r_r80[1] = {cpy_r_r76};
    cpy_r_r81 = (PyObject **)&cpy_r_r80;
    cpy_r_r82 = PyObject_Vectorcall(cpy_r_r79, cpy_r_r81, 1, 0);
    CPy_DECREF(cpy_r_r79);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r83 = CPyStatic_globals;
    cpy_r_r84 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_T' */
    cpy_r_r85 = CPyDict_SetItem(cpy_r_r83, cpy_r_r84, cpy_r_r82);
    CPy_DECREF(cpy_r_r82);
    cpy_r_r86 = cpy_r_r85 >= 0;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r87 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r88 = CPyStatic_globals;
    cpy_r_r89 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'TypeVar' */
    cpy_r_r90 = CPyDict_GetItem(cpy_r_r88, cpy_r_r89);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    PyObject *cpy_r_r91[1] = {cpy_r_r87};
    cpy_r_r92 = (PyObject **)&cpy_r_r91;
    cpy_r_r93 = PyObject_Vectorcall(cpy_r_r90, cpy_r_r92, 1, 0);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r94 = CPyStatic_globals;
    cpy_r_r95 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r96 = CPyDict_SetItem(cpy_r_r94, cpy_r_r95, cpy_r_r93);
    CPy_DECREF(cpy_r_r93);
    cpy_r_r97 = cpy_r_r96 >= 0;
    if (unlikely(!cpy_r_r97)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r98 = CPyStatic_globals;
    cpy_r_r99 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Coroutine' */
    cpy_r_r100 = CPyDict_GetItem(cpy_r_r98, cpy_r_r99);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r101 = CPyStatic_globals;
    cpy_r_r102 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Any' */
    cpy_r_r103 = CPyDict_GetItem(cpy_r_r101, cpy_r_r102);
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL167;
    }
    cpy_r_r104 = CPyStatic_globals;
    cpy_r_r105 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Any' */
    cpy_r_r106 = CPyDict_GetItem(cpy_r_r104, cpy_r_r105);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL168;
    }
    cpy_r_r107 = CPyStatic_globals;
    cpy_r_r108 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r109 = CPyDict_GetItem(cpy_r_r107, cpy_r_r108);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r110.f0 = cpy_r_r103;
    cpy_r_r110.f1 = cpy_r_r106;
    cpy_r_r110.f2 = cpy_r_r109;
    cpy_r_r111 = PyTuple_New(3);
    if (unlikely(cpy_r_r111 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp48 = cpy_r_r110.f0;
    PyTuple_SET_ITEM(cpy_r_r111, 0, __tmp48);
    PyObject *__tmp49 = cpy_r_r110.f1;
    PyTuple_SET_ITEM(cpy_r_r111, 1, __tmp49);
    PyObject *__tmp50 = cpy_r_r110.f2;
    PyTuple_SET_ITEM(cpy_r_r111, 2, __tmp50);
    cpy_r_r112 = PyObject_GetItem(cpy_r_r100, cpy_r_r111);
    CPy_DECREF(cpy_r_r100);
    CPy_DECREF(cpy_r_r111);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r113 = CPyStatic_globals;
    cpy_r_r114 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_Coro' */
    cpy_r_r115 = CPyDict_SetItem(cpy_r_r113, cpy_r_r114, cpy_r_r112);
    CPy_DECREF(cpy_r_r112);
    cpy_r_r116 = cpy_r_r115 >= 0;
    if (unlikely(!cpy_r_r116)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r117 = CPyStatic_globals;
    cpy_r_r118 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Callable' */
    cpy_r_r119 = CPyDict_GetItem(cpy_r_r117, cpy_r_r118);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r120 = (PyObject *)&_Py_EllipsisObject;
    cpy_r_r121 = CPyStatic_globals;
    cpy_r_r122 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_Coro' */
    cpy_r_r123 = CPyDict_GetItem(cpy_r_r121, cpy_r_r122);
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL170;
    }
    cpy_r_r124 = CPyStatic_globals;
    cpy_r_r125 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r126 = CPyDict_GetItem(cpy_r_r124, cpy_r_r125);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r127 = PyObject_GetItem(cpy_r_r123, cpy_r_r126);
    CPy_DECREF(cpy_r_r123);
    CPy_DECREF(cpy_r_r126);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL170;
    }
    CPy_INCREF(cpy_r_r120);
    cpy_r_r128.f0 = cpy_r_r120;
    cpy_r_r128.f1 = cpy_r_r127;
    cpy_r_r129 = PyTuple_New(2);
    if (unlikely(cpy_r_r129 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp51 = cpy_r_r128.f0;
    PyTuple_SET_ITEM(cpy_r_r129, 0, __tmp51);
    PyObject *__tmp52 = cpy_r_r128.f1;
    PyTuple_SET_ITEM(cpy_r_r129, 1, __tmp52);
    cpy_r_r130 = PyObject_GetItem(cpy_r_r119, cpy_r_r129);
    CPy_DECREF(cpy_r_r119);
    CPy_DECREF(cpy_r_r129);
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r131 = CPyStatic_globals;
    cpy_r_r132 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CB' */
    cpy_r_r133 = CPyDict_SetItem(cpy_r_r131, cpy_r_r132, cpy_r_r130);
    CPy_DECREF(cpy_r_r130);
    cpy_r_r134 = cpy_r_r133 >= 0;
    if (unlikely(!cpy_r_r134)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r135 = CPyStatic_globals;
    cpy_r_r136 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Union' */
    cpy_r_r137 = CPyDict_GetItem(cpy_r_r135, cpy_r_r136);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r138 = CPyStatic_globals;
    cpy_r_r139 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CB' */
    cpy_r_r140 = CPyDict_GetItem(cpy_r_r138, cpy_r_r139);
    if (unlikely(cpy_r_r140 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL172;
    }
    cpy_r_r141 = CPyStatic_globals;
    cpy_r_r142 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r143 = CPyDict_GetItem(cpy_r_r141, cpy_r_r142);
    if (unlikely(cpy_r_r143 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r144 = PyObject_GetItem(cpy_r_r140, cpy_r_r143);
    CPy_DECREF(cpy_r_r140);
    CPy_DECREF(cpy_r_r143);
    if (unlikely(cpy_r_r144 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL172;
    }
    cpy_r_r145 = CPyModule_functools;
    cpy_r_r146 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partial' */
    cpy_r_r147 = CPyObject_GetAttr(cpy_r_r145, cpy_r_r146);
    if (unlikely(cpy_r_r147 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL174;
    }
    cpy_r_r148 = CPyStatic_globals;
    cpy_r_r149 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_Coro' */
    cpy_r_r150 = CPyDict_GetItem(cpy_r_r148, cpy_r_r149);
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL175;
    }
    cpy_r_r151 = CPyStatic_globals;
    cpy_r_r152 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r153 = CPyDict_GetItem(cpy_r_r151, cpy_r_r152);
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL176;
    }
    cpy_r_r154 = PyObject_GetItem(cpy_r_r150, cpy_r_r153);
    CPy_DECREF(cpy_r_r150);
    CPy_DECREF(cpy_r_r153);
    if (unlikely(cpy_r_r154 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL175;
    }
    cpy_r_r155 = PyObject_GetItem(cpy_r_r147, cpy_r_r154);
    CPy_DECREF(cpy_r_r147);
    CPy_DECREF(cpy_r_r154);
    if (unlikely(cpy_r_r155 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL174;
    }
    cpy_r_r156 = CPyModule_functools;
    cpy_r_r157 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partialmethod' */
    cpy_r_r158 = CPyObject_GetAttr(cpy_r_r156, cpy_r_r157);
    if (unlikely(cpy_r_r158 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r159 = CPyStatic_globals;
    cpy_r_r160 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_Coro' */
    cpy_r_r161 = CPyDict_GetItem(cpy_r_r159, cpy_r_r160);
    if (unlikely(cpy_r_r161 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL178;
    }
    cpy_r_r162 = CPyStatic_globals;
    cpy_r_r163 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r164 = CPyDict_GetItem(cpy_r_r162, cpy_r_r163);
    if (unlikely(cpy_r_r164 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL179;
    }
    cpy_r_r165 = PyObject_GetItem(cpy_r_r161, cpy_r_r164);
    CPy_DECREF(cpy_r_r161);
    CPy_DECREF(cpy_r_r164);
    if (unlikely(cpy_r_r165 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL178;
    }
    cpy_r_r166 = PyObject_GetItem(cpy_r_r158, cpy_r_r165);
    CPy_DECREF(cpy_r_r158);
    CPy_DECREF(cpy_r_r165);
    if (unlikely(cpy_r_r166 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r167.f0 = cpy_r_r144;
    cpy_r_r167.f1 = cpy_r_r155;
    cpy_r_r167.f2 = cpy_r_r166;
    cpy_r_r168 = PyTuple_New(3);
    if (unlikely(cpy_r_r168 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp53 = cpy_r_r167.f0;
    PyTuple_SET_ITEM(cpy_r_r168, 0, __tmp53);
    PyObject *__tmp54 = cpy_r_r167.f1;
    PyTuple_SET_ITEM(cpy_r_r168, 1, __tmp54);
    PyObject *__tmp55 = cpy_r_r167.f2;
    PyTuple_SET_ITEM(cpy_r_r168, 2, __tmp55);
    cpy_r_r169 = PyObject_GetItem(cpy_r_r137, cpy_r_r168);
    CPy_DECREF(cpy_r_r137);
    CPy_DECREF(cpy_r_r168);
    if (unlikely(cpy_r_r169 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r170 = CPyStatic_globals;
    cpy_r_r171 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CBP' */
    cpy_r_r172 = CPyDict_SetItem(cpy_r_r170, cpy_r_r171, cpy_r_r169);
    CPy_DECREF(cpy_r_r169);
    cpy_r_r173 = cpy_r_r172 >= 0;
    if (unlikely(!cpy_r_r173)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r174 = CPyModule_sys;
    cpy_r_r175 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r176 = CPyObject_GetAttr(cpy_r_r174, cpy_r_r175);
    if (unlikely(cpy_r_r176 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    if (likely(PyTuple_Check(cpy_r_r176)))
        cpy_r_r177 = cpy_r_r176;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "<module>", 52, CPyStatic_globals, "tuple", cpy_r_r176);
        goto CPyL165;
    }
    cpy_r_r178.f0 = 6;
    cpy_r_r178.f1 = 24;
    cpy_r_r179 = PyTuple_New(2);
    if (unlikely(cpy_r_r179 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp56 = CPyTagged_StealAsObject(cpy_r_r178.f0);
    PyTuple_SET_ITEM(cpy_r_r179, 0, __tmp56);
    PyObject *__tmp57 = CPyTagged_StealAsObject(cpy_r_r178.f1);
    PyTuple_SET_ITEM(cpy_r_r179, 1, __tmp57);
    cpy_r_r180 = PyObject_RichCompare(cpy_r_r177, cpy_r_r179, 5);
    CPy_DECREF(cpy_r_r177);
    CPy_DECREF(cpy_r_r179);
    if (unlikely(cpy_r_r180 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    if (unlikely(!PyBool_Check(cpy_r_r180))) {
        CPy_TypeError("bool", cpy_r_r180); cpy_r_r181 = 2;
    } else
        cpy_r_r181 = cpy_r_r180 == Py_True;
    CPy_DECREF(cpy_r_r180);
    if (unlikely(cpy_r_r181 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyStatic__PYTHON_GTE_312 = cpy_r_r181;
    cpy_r_r182 = CPyStatic_globals;
    cpy_r_r183 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_PYTHON_GTE_312' */
    cpy_r_r184 = cpy_r_r181 ? Py_True : Py_False;
    cpy_r_r185 = CPyDict_SetItem(cpy_r_r182, cpy_r_r183, cpy_r_r184);
    cpy_r_r186 = cpy_r_r185 >= 0;
    if (unlikely(!cpy_r_r186)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r187 = CPyModule_functools;
    cpy_r_r188 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheInfo' */
    cpy_r_r189 = CPyObject_GetAttr(cpy_r_r187, cpy_r_r188);
    if (unlikely(cpy_r_r189 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyStatic__CacheInfo = cpy_r_r189;
    CPy_INCREF(CPyStatic__CacheInfo);
    cpy_r_r190 = CPyStatic_globals;
    cpy_r_r191 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheInfo' */
    cpy_r_r192 = CPyDict_SetItem(cpy_r_r190, cpy_r_r191, cpy_r_r189);
    CPy_DECREF(cpy_r_r189);
    cpy_r_r193 = cpy_r_r192 >= 0;
    if (unlikely(!cpy_r_r193)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r194 = CPyModule_functools;
    cpy_r_r195 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partial' */
    cpy_r_r196 = CPyObject_GetAttr(cpy_r_r194, cpy_r_r195);
    if (unlikely(cpy_r_r196 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyStatic_partial = cpy_r_r196;
    CPy_INCREF(CPyStatic_partial);
    cpy_r_r197 = CPyStatic_globals;
    cpy_r_r198 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partial' */
    cpy_r_r199 = CPyDict_SetItem(cpy_r_r197, cpy_r_r198, cpy_r_r196);
    CPy_DECREF(cpy_r_r196);
    cpy_r_r200 = cpy_r_r199 >= 0;
    if (unlikely(!cpy_r_r200)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r201 = CPyModule_functools;
    cpy_r_r202 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partialmethod' */
    cpy_r_r203 = CPyObject_GetAttr(cpy_r_r201, cpy_r_r202);
    if (unlikely(cpy_r_r203 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyStatic_partialmethod = cpy_r_r203;
    CPy_INCREF(CPyStatic_partialmethod);
    cpy_r_r204 = CPyStatic_globals;
    cpy_r_r205 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partialmethod' */
    cpy_r_r206 = CPyDict_SetItem(cpy_r_r204, cpy_r_r205, cpy_r_r203);
    CPy_DECREF(cpy_r_r203);
    cpy_r_r207 = cpy_r_r206 >= 0;
    if (unlikely(!cpy_r_r207)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r208 = CPyModule_functools;
    cpy_r_r209 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_make_key' */
    cpy_r_r210 = CPyObject_GetAttr(cpy_r_r208, cpy_r_r209);
    if (unlikely(cpy_r_r210 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyStatic__make_key = cpy_r_r210;
    CPy_INCREF(CPyStatic__make_key);
    cpy_r_r211 = CPyStatic_globals;
    cpy_r_r212 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_make_key' */
    cpy_r_r213 = CPyDict_SetItem(cpy_r_r211, cpy_r_r212, cpy_r_r210);
    CPy_DECREF(cpy_r_r210);
    cpy_r_r214 = cpy_r_r213 >= 0;
    if (unlikely(!cpy_r_r214)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r215 = CPyModule_asyncio;
    cpy_r_r216 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'gather' */
    cpy_r_r217 = CPyObject_GetAttr(cpy_r_r215, cpy_r_r216);
    if (unlikely(cpy_r_r217 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyStatic_gather = cpy_r_r217;
    CPy_INCREF(CPyStatic_gather);
    cpy_r_r218 = CPyStatic_globals;
    cpy_r_r219 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'gather' */
    cpy_r_r220 = CPyDict_SetItem(cpy_r_r218, cpy_r_r219, cpy_r_r217);
    CPy_DECREF(cpy_r_r217);
    cpy_r_r221 = cpy_r_r220 >= 0;
    if (unlikely(!cpy_r_r221)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r222 = CPyModule_asyncio;
    cpy_r_r223 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'get_running_loop' */
    cpy_r_r224 = CPyObject_GetAttr(cpy_r_r222, cpy_r_r223);
    if (unlikely(cpy_r_r224 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyStatic_get_running_loop = cpy_r_r224;
    CPy_INCREF(CPyStatic_get_running_loop);
    cpy_r_r225 = CPyStatic_globals;
    cpy_r_r226 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'get_running_loop' */
    cpy_r_r227 = CPyDict_SetItem(cpy_r_r225, cpy_r_r226, cpy_r_r224);
    CPy_DECREF(cpy_r_r224);
    cpy_r_r228 = cpy_r_r227 >= 0;
    if (unlikely(!cpy_r_r228)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r229 = CPyModule_asyncio;
    cpy_r_r230 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'shield' */
    cpy_r_r231 = CPyObject_GetAttr(cpy_r_r229, cpy_r_r230);
    if (unlikely(cpy_r_r231 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyStatic_shield = cpy_r_r231;
    CPy_INCREF(CPyStatic_shield);
    cpy_r_r232 = CPyStatic_globals;
    cpy_r_r233 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'shield' */
    cpy_r_r234 = CPyDict_SetItem(cpy_r_r232, cpy_r_r233, cpy_r_r231);
    CPy_DECREF(cpy_r_r231);
    cpy_r_r235 = cpy_r_r234 >= 0;
    if (unlikely(!cpy_r_r235)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r236 = CPyModule_inspect;
    cpy_r_r237 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'markcoroutinefunction' */
    cpy_r_r238 = Py_None;
    cpy_r_r239 = CPyObject_GetAttr3(cpy_r_r236, cpy_r_r237, cpy_r_r238);
    if (unlikely(cpy_r_r239 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyStatic_markcoroutinefunction = cpy_r_r239;
    CPy_INCREF(CPyStatic_markcoroutinefunction);
    cpy_r_r240 = CPyStatic_globals;
    cpy_r_r241 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'markcoroutinefunction' */
    cpy_r_r242 = CPyDict_SetItem(cpy_r_r240, cpy_r_r241, cpy_r_r239);
    CPy_DECREF(cpy_r_r239);
    cpy_r_r243 = cpy_r_r242 >= 0;
    if (unlikely(!cpy_r_r243)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r244 = CPyModule_sys;
    cpy_r_r245 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r246 = CPyObject_GetAttr(cpy_r_r244, cpy_r_r245);
    if (unlikely(cpy_r_r246 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    if (likely(PyTuple_Check(cpy_r_r246)))
        cpy_r_r247 = cpy_r_r246;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "<module>", 64, CPyStatic_globals, "tuple", cpy_r_r246);
        goto CPyL165;
    }
    cpy_r_r248.f0 = 6;
    cpy_r_r248.f1 = 28;
    cpy_r_r249 = PyTuple_New(2);
    if (unlikely(cpy_r_r249 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp58 = CPyTagged_StealAsObject(cpy_r_r248.f0);
    PyTuple_SET_ITEM(cpy_r_r249, 0, __tmp58);
    PyObject *__tmp59 = CPyTagged_StealAsObject(cpy_r_r248.f1);
    PyTuple_SET_ITEM(cpy_r_r249, 1, __tmp59);
    cpy_r_r250 = PyObject_RichCompare(cpy_r_r247, cpy_r_r249, 5);
    CPy_DECREF(cpy_r_r247);
    CPy_DECREF(cpy_r_r249);
    if (unlikely(cpy_r_r250 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    if (unlikely(!PyBool_Check(cpy_r_r250))) {
        CPy_TypeError("bool", cpy_r_r250); cpy_r_r251 = 2;
    } else
        cpy_r_r251 = cpy_r_r250 == Py_True;
    CPy_DECREF(cpy_r_r250);
    if (unlikely(cpy_r_r251 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    if (!cpy_r_r251) goto CPyL90;
    cpy_r_r252 = CPyModule_inspect;
    cpy_r_r253 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'iscoroutinefunction' */
    cpy_r_r254 = CPyObject_GetAttr(cpy_r_r252, cpy_r_r253);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyStatic_iscoroutinefunction = cpy_r_r254;
    CPy_INCREF(CPyStatic_iscoroutinefunction);
    cpy_r_r255 = CPyStatic_globals;
    cpy_r_r256 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'iscoroutinefunction' */
    cpy_r_r257 = CPyDict_SetItem(cpy_r_r255, cpy_r_r256, cpy_r_r254);
    CPy_DECREF(cpy_r_r254);
    cpy_r_r258 = cpy_r_r257 >= 0;
    if (unlikely(!cpy_r_r258)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    } else
        goto CPyL92;
CPyL90: ;
    PyErr_SetString(PyExc_RuntimeError, "Reached allegedly unreachable code!");
    cpy_r_r259 = 0;
    if (unlikely(!cpy_r_r259)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPy_Unreachable();
CPyL92: ;
    cpy_r_r260 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru_threadsafe' */
    cpy_r_r261 = CPyModule_logging;
    cpy_r_r262 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'getLogger' */
    cpy_r_r263 = CPyObject_GetAttr(cpy_r_r261, cpy_r_r262);
    if (unlikely(cpy_r_r263 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    PyObject *cpy_r_r264[1] = {cpy_r_r260};
    cpy_r_r265 = (PyObject **)&cpy_r_r264;
    cpy_r_r266 = PyObject_Vectorcall(cpy_r_r263, cpy_r_r265, 1, 0);
    CPy_DECREF(cpy_r_r263);
    if (unlikely(cpy_r_r266 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyStatic_logger = cpy_r_r266;
    CPy_INCREF(CPyStatic_logger);
    cpy_r_r267 = CPyStatic_globals;
    cpy_r_r268 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'logger' */
    cpy_r_r269 = CPyDict_SetItem(cpy_r_r267, cpy_r_r268, cpy_r_r266);
    CPy_DECREF(cpy_r_r266);
    cpy_r_r270 = cpy_r_r269 >= 0;
    if (unlikely(!cpy_r_r270)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r271 = CPyModule_typing;
    cpy_r_r272 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r273 = cpy_r_r271 != cpy_r_r272;
    if (cpy_r_r273) goto CPyL98;
    cpy_r_r274 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r275 = PyImport_Import(cpy_r_r274);
    if (unlikely(cpy_r_r275 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    CPyModule_typing = cpy_r_r275;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r275);
CPyL98: ;
    cpy_r_r276 = PyImport_GetModuleDict();
    cpy_r_r277 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r278 = CPyDict_GetItem(cpy_r_r276, cpy_r_r277);
    if (unlikely(cpy_r_r278 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r279 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_TypedDict' */
    cpy_r_r280 = CPyObject_GetAttr(cpy_r_r278, cpy_r_r279);
    CPy_DECREF(cpy_r_r278);
    if (unlikely(cpy_r_r280 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r281 = PyTuple_Pack(1, cpy_r_r280);
    CPy_DECREF(cpy_r_r280);
    if (unlikely(cpy_r_r281 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r282 = CPyModule_typing;
    cpy_r_r283 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r284 = cpy_r_r282 != cpy_r_r283;
    if (cpy_r_r284) goto CPyL104;
    cpy_r_r285 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r286 = PyImport_Import(cpy_r_r285);
    if (unlikely(cpy_r_r286 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL180;
    }
    CPyModule_typing = cpy_r_r286;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r286);
CPyL104: ;
    cpy_r_r287 = PyImport_GetModuleDict();
    cpy_r_r288 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r289 = CPyDict_GetItem(cpy_r_r287, cpy_r_r288);
    if (unlikely(cpy_r_r289 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL180;
    }
    cpy_r_r290 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_TypedDictMeta' */
    cpy_r_r291 = CPyObject_GetAttr(cpy_r_r289, cpy_r_r290);
    CPy_DECREF(cpy_r_r289);
    if (unlikely(cpy_r_r291 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL180;
    }
    cpy_r_r292 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__prepare__' */
    cpy_r_r293 = PyObject_HasAttr(cpy_r_r291, cpy_r_r292);
    if (!cpy_r_r293) goto CPyL111;
    cpy_r_r294 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheParameters' */
    cpy_r_r295 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__prepare__' */
    cpy_r_r296 = CPyObject_GetAttr(cpy_r_r291, cpy_r_r295);
    if (unlikely(cpy_r_r296 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL181;
    }
    PyObject *cpy_r_r297[2] = {cpy_r_r294, cpy_r_r281};
    cpy_r_r298 = (PyObject **)&cpy_r_r297;
    cpy_r_r299 = PyObject_Vectorcall(cpy_r_r296, cpy_r_r298, 2, 0);
    CPy_DECREF(cpy_r_r296);
    if (unlikely(cpy_r_r299 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL181;
    }
    if (likely(PyDict_Check(cpy_r_r299)))
        cpy_r_r300 = cpy_r_r299;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "<module>", 73, CPyStatic_globals, "dict", cpy_r_r299);
        goto CPyL181;
    }
    cpy_r_r301 = cpy_r_r300;
    goto CPyL113;
CPyL111: ;
    cpy_r_r302 = PyDict_New();
    if (unlikely(cpy_r_r302 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL181;
    }
    cpy_r_r301 = cpy_r_r302;
CPyL113: ;
    cpy_r_r303 = PyDict_New();
    if (unlikely(cpy_r_r303 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL182;
    }
    cpy_r_r304 = (PyObject *)&PyBool_Type;
    cpy_r_r305 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typed' */
    cpy_r_r306 = PyDict_SetItem(cpy_r_r303, cpy_r_r305, cpy_r_r304);
    cpy_r_r307 = cpy_r_r306 >= 0;
    if (unlikely(!cpy_r_r307)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL183;
    }
    cpy_r_r308 = (PyObject *)&PyType_Type;
    cpy_r_r309 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'maxsize' */
    cpy_r_r310 = PyDict_SetItem(cpy_r_r303, cpy_r_r309, cpy_r_r308);
    cpy_r_r311 = cpy_r_r310 >= 0;
    if (unlikely(!cpy_r_r311)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL183;
    }
    cpy_r_r312 = (PyObject *)&PyLong_Type;
    cpy_r_r313 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'tasks' */
    cpy_r_r314 = PyDict_SetItem(cpy_r_r303, cpy_r_r313, cpy_r_r312);
    cpy_r_r315 = cpy_r_r314 >= 0;
    if (unlikely(!cpy_r_r315)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL183;
    }
    cpy_r_r316 = (PyObject *)&PyBool_Type;
    cpy_r_r317 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'closed' */
    cpy_r_r318 = PyDict_SetItem(cpy_r_r303, cpy_r_r317, cpy_r_r316);
    cpy_r_r319 = cpy_r_r318 >= 0;
    if (unlikely(!cpy_r_r319)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL183;
    }
    cpy_r_r320 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheParameters' */
    cpy_r_r321 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r322 = CPyDict_SetItem(cpy_r_r301, cpy_r_r321, cpy_r_r303);
    CPy_DECREF(cpy_r_r303);
    cpy_r_r323 = cpy_r_r322 >= 0;
    if (unlikely(!cpy_r_r323)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL182;
    }
    cpy_r_r324 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'mypyc filler docstring' */
    cpy_r_r325 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r326 = CPyDict_SetItem(cpy_r_r301, cpy_r_r325, cpy_r_r324);
    cpy_r_r327 = cpy_r_r326 >= 0;
    if (unlikely(!cpy_r_r327)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL182;
    }
    cpy_r_r328 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru' */
    cpy_r_r329 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r330 = CPyDict_SetItem(cpy_r_r301, cpy_r_r329, cpy_r_r328);
    cpy_r_r331 = cpy_r_r330 >= 0;
    if (unlikely(!cpy_r_r331)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL182;
    }
    PyObject *cpy_r_r332[3] = {cpy_r_r320, cpy_r_r281, cpy_r_r301};
    cpy_r_r333 = (PyObject **)&cpy_r_r332;
    cpy_r_r334 = PyObject_Vectorcall(cpy_r_r291, cpy_r_r333, 3, 0);
    CPy_DECREF(cpy_r_r291);
    if (unlikely(cpy_r_r334 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL184;
    }
    CPy_DECREF(cpy_r_r281);
    CPy_DECREF(cpy_r_r301);
    cpy_r_r335 = CPyStatic_globals;
    cpy_r_r336 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'final' */
    cpy_r_r337 = CPyDict_GetItem(cpy_r_r335, cpy_r_r336);
    if (unlikely(cpy_r_r337 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL185;
    }
    PyObject *cpy_r_r338[1] = {cpy_r_r334};
    cpy_r_r339 = (PyObject **)&cpy_r_r338;
    cpy_r_r340 = PyObject_Vectorcall(cpy_r_r337, cpy_r_r339, 1, 0);
    CPy_DECREF(cpy_r_r337);
    if (unlikely(cpy_r_r340 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL185;
    }
    CPy_DECREF(cpy_r_r334);
    CPyType__CacheParameters = (PyTypeObject *)cpy_r_r340;
    CPy_INCREF(CPyType__CacheParameters);
    cpy_r_r341 = CPyStatic_globals;
    cpy_r_r342 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheParameters' */
    cpy_r_r343 = PyDict_SetItem(cpy_r_r341, cpy_r_r342, cpy_r_r340);
    CPy_DECREF(cpy_r_r340);
    cpy_r_r344 = cpy_r_r343 >= 0;
    if (unlikely(!cpy_r_r344)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r345 = (PyObject *)CPyType__CacheParameters;
    cpy_r_r346 = CPyStatic_globals;
    cpy_r_r347 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Generic' */
    cpy_r_r348 = CPyDict_GetItem(cpy_r_r346, cpy_r_r347);
    if (unlikely(cpy_r_r348 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r349 = CPyStatic_globals;
    cpy_r_r350 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r351 = CPyDict_GetItem(cpy_r_r349, cpy_r_r350);
    if (unlikely(cpy_r_r351 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r352 = PyObject_GetItem(cpy_r_r348, cpy_r_r351);
    CPy_DECREF(cpy_r_r348);
    CPy_DECREF(cpy_r_r351);
    if (unlikely(cpy_r_r352 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r353 = PyTuple_Pack(1, cpy_r_r352);
    CPy_DECREF(cpy_r_r352);
    if (unlikely(cpy_r_r353 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r354 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru' */
    cpy_r_r355 = (PyObject *)CPyType__CacheItem_template;
    cpy_r_r356 = CPyType_FromTemplate(cpy_r_r355, cpy_r_r353, cpy_r_r354);
    CPy_DECREF(cpy_r_r353);
    if (unlikely(cpy_r_r356 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r357 = CPyDef__CacheItem_trait_vtable_setup();
    if (unlikely(cpy_r_r357 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r358 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__mypyc_attrs__' */
    cpy_r_r359 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'task' */
    cpy_r_r360 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'later_call' */
    cpy_r_r361 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'waiters' */
    cpy_r_r362 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r363 = PyTuple_Pack(4, cpy_r_r359, cpy_r_r360, cpy_r_r361, cpy_r_r362);
    if (unlikely(cpy_r_r363 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r364 = PyObject_SetAttr(cpy_r_r356, cpy_r_r358, cpy_r_r363);
    CPy_DECREF(cpy_r_r363);
    cpy_r_r365 = cpy_r_r364 >= 0;
    if (unlikely(!cpy_r_r365)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL187;
    }
    CPyType__CacheItem = (PyTypeObject *)cpy_r_r356;
    CPy_INCREF(CPyType__CacheItem);
    cpy_r_r366 = CPyStatic_globals;
    cpy_r_r367 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheItem' */
    cpy_r_r368 = PyDict_SetItem(cpy_r_r366, cpy_r_r367, cpy_r_r356);
    cpy_r_r369 = cpy_r_r368 >= 0;
    if (unlikely(!cpy_r_r369)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r370 = PyDict_New();
    if (unlikely(cpy_r_r370 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r371.empty_struct_error_flag = 0;
    cpy_r_r372 = PyDict_New();
    if (unlikely(cpy_r_r372 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r373 = (PyObject *)&PyType_Type;
    cpy_r_r374 = CPyModule_asyncio;
    cpy_r_r375 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Task' */
    cpy_r_r376 = CPyObject_GetAttr(cpy_r_r374, cpy_r_r375);
    if (unlikely(cpy_r_r376 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r377 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'task' */
    cpy_r_r378 = PyDict_SetItem(cpy_r_r372, cpy_r_r377, cpy_r_r376);
    CPy_DECREF(cpy_r_r376);
    cpy_r_r379 = cpy_r_r378 >= 0;
    if (unlikely(!cpy_r_r379)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r380 = (PyObject *)&PyType_Type;
    cpy_r_r381 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'later_call' */
    cpy_r_r382 = PyDict_SetItem(cpy_r_r372, cpy_r_r381, cpy_r_r380);
    cpy_r_r383 = cpy_r_r382 >= 0;
    if (unlikely(!cpy_r_r383)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r384 = (PyObject *)&PyLong_Type;
    cpy_r_r385 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'waiters' */
    cpy_r_r386 = PyDict_SetItem(cpy_r_r372, cpy_r_r385, cpy_r_r384);
    cpy_r_r387 = cpy_r_r386 >= 0;
    if (unlikely(!cpy_r_r387)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r388 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r389 = CPyDict_SetItem(cpy_r_r370, cpy_r_r388, cpy_r_r372);
    cpy_r_r390 = cpy_r_r389 >= 0;
    if (unlikely(!cpy_r_r390)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r391 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'mypyc filler docstring' */
    cpy_r_r392 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r393 = CPyDict_SetItem(cpy_r_r370, cpy_r_r392, cpy_r_r391);
    cpy_r_r394 = cpy_r_r393 >= 0;
    if (unlikely(!cpy_r_r394)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r395 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru' */
    cpy_r_r396 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r397 = CPyDict_SetItem(cpy_r_r370, cpy_r_r396, cpy_r_r395);
    cpy_r_r398 = cpy_r_r397 >= 0;
    if (unlikely(!cpy_r_r398)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r399 = CPyModule_dataclasses;
    cpy_r_r400 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'dataclass' */
    cpy_r_r401 = CPyObject_GetAttr(cpy_r_r399, cpy_r_r400);
    if (unlikely(cpy_r_r401 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r402 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'dataclasses' */
    cpy_r_r403 = CPyDataclass_SleightOfHand(cpy_r_r401, cpy_r_r356, cpy_r_r370, cpy_r_r372, cpy_r_r402);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r356);
    CPy_DECREF(cpy_r_r370);
    CPy_DECREF(cpy_r_r372);
    if (unlikely(!cpy_r_r403)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r404 = CPyStatic_globals;
    cpy_r_r405 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Generic' */
    cpy_r_r406 = CPyDict_GetItem(cpy_r_r404, cpy_r_r405);
    if (unlikely(cpy_r_r406 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r407 = CPyStatic_globals;
    cpy_r_r408 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r409 = CPyDict_GetItem(cpy_r_r407, cpy_r_r408);
    if (unlikely(cpy_r_r409 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL190;
    }
    cpy_r_r410 = PyObject_GetItem(cpy_r_r406, cpy_r_r409);
    CPy_DECREF(cpy_r_r406);
    CPy_DECREF(cpy_r_r409);
    if (unlikely(cpy_r_r410 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r411 = PyTuple_Pack(1, cpy_r_r410);
    CPy_DECREF(cpy_r_r410);
    if (unlikely(cpy_r_r411 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r412 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru' */
    cpy_r_r413 = (PyObject *)CPyType__LRUCacheWrapper_template;
    cpy_r_r414 = CPyType_FromTemplate(cpy_r_r413, cpy_r_r411, cpy_r_r412);
    CPy_DECREF(cpy_r_r411);
    if (unlikely(cpy_r_r414 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r415 = CPyDef__LRUCacheWrapper_trait_vtable_setup();
    if (unlikely(cpy_r_r415 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL191;
    }
    cpy_r_r416 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__mypyc_attrs__' */
    cpy_r_r417 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r418 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__name__' */
    cpy_r_r419 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__qualname__' */
    cpy_r_r420 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r421 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r422 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapped__' */
    cpy_r_r423 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__maxsize' */
    cpy_r_r424 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__typed' */
    cpy_r_r425 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__ttl' */
    cpy_r_r426 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__cache' */
    cpy_r_r427 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__closed' */
    cpy_r_r428 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__hits' */
    cpy_r_r429 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__misses' */
    cpy_r_r430 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__first_loop' */
    cpy_r_r431 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r432 = PyTuple_Pack(15, cpy_r_r417, cpy_r_r418, cpy_r_r419, cpy_r_r420, cpy_r_r421, cpy_r_r422, cpy_r_r423, cpy_r_r424, cpy_r_r425, cpy_r_r426, cpy_r_r427, cpy_r_r428, cpy_r_r429, cpy_r_r430, cpy_r_r431);
    if (unlikely(cpy_r_r432 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL191;
    }
    cpy_r_r433 = PyObject_SetAttr(cpy_r_r414, cpy_r_r416, cpy_r_r432);
    CPy_DECREF(cpy_r_r432);
    cpy_r_r434 = cpy_r_r433 >= 0;
    if (unlikely(!cpy_r_r434)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL191;
    }
    CPyType__LRUCacheWrapper = (PyTypeObject *)cpy_r_r414;
    CPy_INCREF(CPyType__LRUCacheWrapper);
    cpy_r_r435 = CPyStatic_globals;
    cpy_r_r436 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_LRUCacheWrapper' */
    cpy_r_r437 = PyDict_SetItem(cpy_r_r435, cpy_r_r436, cpy_r_r414);
    CPy_DECREF(cpy_r_r414);
    cpy_r_r438 = cpy_r_r437 >= 0;
    if (unlikely(!cpy_r_r438)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r439 = CPyStatic_globals;
    cpy_r_r440 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Generic' */
    cpy_r_r441 = CPyDict_GetItem(cpy_r_r439, cpy_r_r440);
    if (unlikely(cpy_r_r441 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r442 = CPyStatic_globals;
    cpy_r_r443 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r444 = CPyDict_GetItem(cpy_r_r442, cpy_r_r443);
    if (unlikely(cpy_r_r444 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL192;
    }
    cpy_r_r445 = CPyStatic_globals;
    cpy_r_r446 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_T' */
    cpy_r_r447 = CPyDict_GetItem(cpy_r_r445, cpy_r_r446);
    if (unlikely(cpy_r_r447 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL193;
    }
    cpy_r_r448.f0 = cpy_r_r444;
    cpy_r_r448.f1 = cpy_r_r447;
    cpy_r_r449 = PyTuple_New(2);
    if (unlikely(cpy_r_r449 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp60 = cpy_r_r448.f0;
    PyTuple_SET_ITEM(cpy_r_r449, 0, __tmp60);
    PyObject *__tmp61 = cpy_r_r448.f1;
    PyTuple_SET_ITEM(cpy_r_r449, 1, __tmp61);
    cpy_r_r450 = PyObject_GetItem(cpy_r_r441, cpy_r_r449);
    CPy_DECREF(cpy_r_r441);
    CPy_DECREF(cpy_r_r449);
    if (unlikely(cpy_r_r450 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r451 = PyTuple_Pack(1, cpy_r_r450);
    CPy_DECREF(cpy_r_r450);
    if (unlikely(cpy_r_r451 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r452 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru' */
    cpy_r_r453 = (PyObject *)CPyType__LRUCacheWrapperInstanceMethod_template;
    cpy_r_r454 = CPyType_FromTemplate(cpy_r_r453, cpy_r_r451, cpy_r_r452);
    CPy_DECREF(cpy_r_r451);
    if (unlikely(cpy_r_r454 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    cpy_r_r455 = CPyDef__LRUCacheWrapperInstanceMethod_trait_vtable_setup();
    if (unlikely(cpy_r_r455 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL194;
    }
    cpy_r_r456 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__mypyc_attrs__' */
    cpy_r_r457 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r458 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__name__' */
    cpy_r_r459 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__qualname__' */
    cpy_r_r460 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r461 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r462 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapped__' */
    cpy_r_r463 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__instance' */
    cpy_r_r464 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapper' */
    cpy_r_r465 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r466 = PyTuple_Pack(9, cpy_r_r457, cpy_r_r458, cpy_r_r459, cpy_r_r460, cpy_r_r461, cpy_r_r462, cpy_r_r463, cpy_r_r464, cpy_r_r465);
    if (unlikely(cpy_r_r466 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL194;
    }
    cpy_r_r467 = PyObject_SetAttr(cpy_r_r454, cpy_r_r456, cpy_r_r466);
    CPy_DECREF(cpy_r_r466);
    cpy_r_r468 = cpy_r_r467 >= 0;
    if (unlikely(!cpy_r_r468)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL194;
    }
    CPyType__LRUCacheWrapperInstanceMethod = (PyTypeObject *)cpy_r_r454;
    CPy_INCREF(CPyType__LRUCacheWrapperInstanceMethod);
    cpy_r_r469 = CPyStatic_globals;
    cpy_r_r470 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_LRUCacheWrapperInstanceMethod' */
    cpy_r_r471 = PyDict_SetItem(cpy_r_r469, cpy_r_r470, cpy_r_r454);
    CPy_DECREF(cpy_r_r454);
    cpy_r_r472 = cpy_r_r471 >= 0;
    if (unlikely(!cpy_r_r472)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL165;
    }
    return 1;
CPyL165: ;
    cpy_r_r473 = 2;
    return cpy_r_r473;
CPyL166: ;
    CPy_DecRef(cpy_r_r65);
    goto CPyL165;
CPyL167: ;
    CPy_DecRef(cpy_r_r100);
    goto CPyL165;
CPyL168: ;
    CPy_DecRef(cpy_r_r100);
    CPy_DecRef(cpy_r_r103);
    goto CPyL165;
CPyL169: ;
    CPy_DecRef(cpy_r_r100);
    CPy_DecRef(cpy_r_r103);
    CPy_DecRef(cpy_r_r106);
    goto CPyL165;
CPyL170: ;
    CPy_DecRef(cpy_r_r119);
    goto CPyL165;
CPyL171: ;
    CPy_DecRef(cpy_r_r119);
    CPy_DecRef(cpy_r_r123);
    goto CPyL165;
CPyL172: ;
    CPy_DecRef(cpy_r_r137);
    goto CPyL165;
CPyL173: ;
    CPy_DecRef(cpy_r_r137);
    CPy_DecRef(cpy_r_r140);
    goto CPyL165;
CPyL174: ;
    CPy_DecRef(cpy_r_r137);
    CPy_DecRef(cpy_r_r144);
    goto CPyL165;
CPyL175: ;
    CPy_DecRef(cpy_r_r137);
    CPy_DecRef(cpy_r_r144);
    CPy_DecRef(cpy_r_r147);
    goto CPyL165;
CPyL176: ;
    CPy_DecRef(cpy_r_r137);
    CPy_DecRef(cpy_r_r144);
    CPy_DecRef(cpy_r_r147);
    CPy_DecRef(cpy_r_r150);
    goto CPyL165;
CPyL177: ;
    CPy_DecRef(cpy_r_r137);
    CPy_DecRef(cpy_r_r144);
    CPy_DecRef(cpy_r_r155);
    goto CPyL165;
CPyL178: ;
    CPy_DecRef(cpy_r_r137);
    CPy_DecRef(cpy_r_r144);
    CPy_DecRef(cpy_r_r155);
    CPy_DecRef(cpy_r_r158);
    goto CPyL165;
CPyL179: ;
    CPy_DecRef(cpy_r_r137);
    CPy_DecRef(cpy_r_r144);
    CPy_DecRef(cpy_r_r155);
    CPy_DecRef(cpy_r_r158);
    CPy_DecRef(cpy_r_r161);
    goto CPyL165;
CPyL180: ;
    CPy_DecRef(cpy_r_r281);
    goto CPyL165;
CPyL181: ;
    CPy_DecRef(cpy_r_r281);
    CPy_DecRef(cpy_r_r291);
    goto CPyL165;
CPyL182: ;
    CPy_DecRef(cpy_r_r281);
    CPy_DecRef(cpy_r_r291);
    CPy_DecRef(cpy_r_r301);
    goto CPyL165;
CPyL183: ;
    CPy_DecRef(cpy_r_r281);
    CPy_DecRef(cpy_r_r291);
    CPy_DecRef(cpy_r_r301);
    CPy_DecRef(cpy_r_r303);
    goto CPyL165;
CPyL184: ;
    CPy_DecRef(cpy_r_r281);
    CPy_DecRef(cpy_r_r301);
    goto CPyL165;
CPyL185: ;
    CPy_DecRef(cpy_r_r334);
    goto CPyL165;
CPyL186: ;
    CPy_DecRef(cpy_r_r348);
    goto CPyL165;
CPyL187: ;
    CPy_DecRef(cpy_r_r356);
    goto CPyL165;
CPyL188: ;
    CPy_DecRef(cpy_r_r356);
    CPy_DecRef(cpy_r_r370);
    goto CPyL165;
CPyL189: ;
    CPy_DecRef(cpy_r_r356);
    CPy_DecRef(cpy_r_r370);
    CPy_DecRef(cpy_r_r372);
    goto CPyL165;
CPyL190: ;
    CPy_DecRef(cpy_r_r406);
    goto CPyL165;
CPyL191: ;
    CPy_DecRef(cpy_r_r414);
    goto CPyL165;
CPyL192: ;
    CPy_DecRef(cpy_r_r441);
    goto CPyL165;
CPyL193: ;
    CPy_DecRef(cpy_r_r441);
    CPy_DecRef(cpy_r_r444);
    goto CPyL165;
CPyL194: ;
    CPy_DecRef(cpy_r_r454);
    goto CPyL165;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_async_lru = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_asyncio = Py_None;
    CPyModule_dataclasses = Py_None;
    CPyModule_functools = Py_None;
    CPyModule_inspect = Py_None;
    CPyModule_logging = Py_None;
    CPyModule_os = Py_None;
    CPyModule_sys = Py_None;
    CPyModule_asyncio___coroutines = Py_None;
    CPyModule_typing = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[DIFFCHECK_PLACEHOLDER];
const char * const CPyLit_Str[] = {
    "\006\006cancel\n__module__\016AttributeError\f__qualname__\a__doc__\017__annotations__",
    "\004\b__dict__\fversion_info\vOrderedDict\004done",
    "\001\201\036alru_cache is not safe to use across event loops: this cache instance was first used with a different event loop. Use separate cache instances per event loop.",
    "\005\fRuntimeError\003pop\n is closed\021return_exceptions\rGeneratorExit",
    "\a\rStopIteration\020_CacheParameters\amaxsize\005typed\005tasks\006closed\vmove_to_end",
    "\005\tcancelled\n_exception\020get_running_loop\ncall_later\006shield",
    "\003\016CancelledError\valru_cache \024 has no more waiters",
    "\004\031alru_cache is closed for \006result\v__wrapped__\vcreate_task",
    "\005\023_task_done_callback\021add_done_callback\apopitem\004last\020cache_invalidate",
    "\006\t__wrapper\004func\000$Coroutine function is required, got \a{!r:{}}\006format",
    "\003\024_make_unbound_method\bcallable\034 decorating is not supported",
    "\006\023NotImplementedError\bbuiltins\aasyncio\vdataclasses\tfunctools\ainspect",
    "\006\alogging\002os\003sys\025async_lru/__init__.py\b<module>\r_is_coroutine",
    "\b\022asyncio.coroutines\003Any\bCallable\tCoroutine\005Final\aGeneric\bHashable\004List",
    "\n\bOptional\004Type\tTypedDict\aTypeVar\005Union\004cast\005final\boverload\006typing\004Self",
    "\a\0052.0.5\v__version__\nalru_cache\a__all__\aenviron\024ASYNC_LRU_ALLOW_SYNC\003get",
    "\t\nALLOW_SYNC\002_T\002_R\005_Coro\003_CB\apartial\rpartialmethod\004_CBP\017_PYTHON_GTE_312",
    "\005\n_CacheInfo\t_make_key\006gather\025markcoroutinefunction\023iscoroutinefunction",
    "\005\024async_lru_threadsafe\tgetLogger\006logger\n_TypedDict\016_TypedDictMeta",
    "\005\v__prepare__\026mypyc filler docstring\tasync_lru\017__mypyc_attrs__\004task",
    "\a\nlater_call\awaiters\n_CacheItem\004Task\tdataclass\b__name__\t__maxsize",
    "\a\a__typed\005__ttl\a__cache\b__closed\006__hits\b__misses\f__first_loop",
    "\003\020_LRUCacheWrapper\n__instance\036_LRUCacheWrapperInstanceMethod",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0021\000128",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    13, 4, 21, 22, 23, 24, 1, 41, 3, 54, 54, 54, 3, 55, 55, 55, 3, 56,
    56, 56, 3, 57, 57, 57, 3, 58, 58, 58, 3, 59, 59, 59, 3, 60, 60, 60, 7,
    134, 135, 136, 137, 138, 139, 140, 1, 63, 16, 65, 66, 67, 68, 69, 70,
    71, 72, 11, 73, 74, 75, 76, 77, 78, 79, 1, 81
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_async_lru__internal = NULL;
CPyModule *CPyModule_async_lru;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_asyncio;
CPyModule *CPyModule_dataclasses;
CPyModule *CPyModule_functools;
CPyModule *CPyModule_inspect;
CPyModule *CPyModule_logging;
CPyModule *CPyModule_os;
CPyModule *CPyModule_sys;
CPyModule *CPyModule_asyncio___coroutines;
CPyModule *CPyModule_typing;
PyObject *CPyStatic_ALLOW_SYNC = NULL;
char CPyStatic__PYTHON_GTE_312 = 2;
PyObject *CPyStatic__CacheInfo = NULL;
PyObject *CPyStatic_partial = NULL;
PyObject *CPyStatic_partialmethod = NULL;
PyObject *CPyStatic__make_key = NULL;
PyObject *CPyStatic_gather = NULL;
PyObject *CPyStatic_get_running_loop = NULL;
PyObject *CPyStatic_shield = NULL;
PyObject *CPyStatic_markcoroutinefunction = NULL;
PyObject *CPyStatic_iscoroutinefunction = NULL;
PyObject *CPyStatic_logger = NULL;
PyTypeObject *CPyType__CacheParameters;
PyTypeObject *CPyType__CacheItem;
PyObject *CPyDef__CacheItem(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
PyTypeObject *CPyType__LRUCacheWrapper;
PyObject *CPyDef__LRUCacheWrapper(PyObject *cpy_r_fn, PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl);
PyTypeObject *CPyType__LRUCacheWrapperInstanceMethod;
PyObject *CPyDef__LRUCacheWrapperInstanceMethod(PyObject *cpy_r_wrapper, PyObject *cpy_r_instance);
PyTypeObject *CPyType_cache_close__LRUCacheWrapper_gen;
PyObject *CPyDef_cache_close__LRUCacheWrapper_gen(void);
CPyThreadLocal async_lru___cache_close__LRUCacheWrapper_genObject *cache_close__LRUCacheWrapper_gen_free_instance;
PyTypeObject *CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen;
PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen(void);
CPyThreadLocal async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_free_instance;
PyTypeObject *CPyType___call___3__LRUCacheWrapper_gen;
PyObject *CPyDef___call___3__LRUCacheWrapper_gen(void);
CPyThreadLocal async_lru_____call___3__LRUCacheWrapper_genObject *__call___3__LRUCacheWrapper_gen_free_instance;
PyTypeObject *CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen;
PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen(void);
CPyThreadLocal async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *cache_close__LRUCacheWrapperInstanceMethod_gen_free_instance;
PyTypeObject *CPyType___call___3__LRUCacheWrapperInstanceMethod_gen;
PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen(void);
CPyThreadLocal async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *__call___3__LRUCacheWrapperInstanceMethod_gen_free_instance;
PyTypeObject *CPyType__make_wrapper_env;
PyObject *CPyDef__make_wrapper_env(void);
CPyThreadLocal async_lru____make_wrapper_envObject *_make_wrapper_env_free_instance;
PyTypeObject *CPyType_wrapper__make_wrapper_obj;
PyObject *CPyDef_wrapper__make_wrapper_obj(void);
CPyThreadLocal async_lru___wrapper__make_wrapper_objObject *wrapper__make_wrapper_obj_free_instance;
char CPyDef__CacheItem___cancel(PyObject *cpy_r_self);
PyObject *CPyPy__CacheItem___cancel(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__LRUCacheWrapper_____init__(PyObject *cpy_r_self, PyObject *cpy_r_fn, PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl);
PyObject *CPyPy__LRUCacheWrapper_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef__LRUCacheWrapper_____tasks(PyObject *cpy_r_self);
PyObject *CPyPy__LRUCacheWrapper_____tasks(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__LRUCacheWrapper____check_loop(PyObject *cpy_r_self, PyObject *cpy_r_loop);
PyObject *CPyPy__LRUCacheWrapper____check_loop(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__LRUCacheWrapper___cache_invalidate(PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
PyObject *CPyPy__LRUCacheWrapper___cache_invalidate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__LRUCacheWrapper___cache_clear(PyObject *cpy_r_self);
PyObject *CPyPy__LRUCacheWrapper___cache_clear(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_cache_close__LRUCacheWrapper_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg, PyObject **cpy_r_stop_iter_ptr);
PyObject *CPyDef_cache_close__LRUCacheWrapper_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_cache_close__LRUCacheWrapper_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_cache_close__LRUCacheWrapper_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy_cache_close__LRUCacheWrapper_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_cache_close__LRUCacheWrapper_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_cache_close__LRUCacheWrapper_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_cache_close__LRUCacheWrapper_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy_cache_close__LRUCacheWrapper_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_cache_close__LRUCacheWrapper_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_cache_close__LRUCacheWrapper_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_cache_close__LRUCacheWrapper_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_cache_close__LRUCacheWrapper_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__LRUCacheWrapper___cache_close(PyObject *cpy_r_self, char cpy_r_wait);
PyObject *CPyPy__LRUCacheWrapper___cache_close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__LRUCacheWrapper___cache_info(PyObject *cpy_r_self);
PyObject *CPyPy__LRUCacheWrapper___cache_info(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__LRUCacheWrapper___cache_parameters(PyObject *cpy_r_self);
PyObject *CPyPy__LRUCacheWrapper___cache_parameters(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__LRUCacheWrapper____cache_hit(PyObject *cpy_r_self, PyObject *cpy_r_key);
PyObject *CPyPy__LRUCacheWrapper____cache_hit(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__LRUCacheWrapper____cache_miss(PyObject *cpy_r_self, PyObject *cpy_r_key);
PyObject *CPyPy__LRUCacheWrapper____cache_miss(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__LRUCacheWrapper____task_done_callback(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_task);
PyObject *CPyPy__LRUCacheWrapper____task_done_callback(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg, PyObject **cpy_r_stop_iter_ptr);
PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__LRUCacheWrapper____shield_and_handle_cancelled_error(PyObject *cpy_r_self, PyObject *cpy_r_cache_item, PyObject *cpy_r_key);
PyObject *CPyPy__LRUCacheWrapper____shield_and_handle_cancelled_error(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___call___3__LRUCacheWrapper_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg, PyObject **cpy_r_stop_iter_ptr);
PyObject *CPyDef___call___3__LRUCacheWrapper_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___call___3__LRUCacheWrapper_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___call___3__LRUCacheWrapper_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy___call___3__LRUCacheWrapper_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___call___3__LRUCacheWrapper_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___call___3__LRUCacheWrapper_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___call___3__LRUCacheWrapper_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy___call___3__LRUCacheWrapper_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___call___3__LRUCacheWrapper_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___call___3__LRUCacheWrapper_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___call___3__LRUCacheWrapper_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___call___3__LRUCacheWrapper_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__LRUCacheWrapper_____call__(PyObject *cpy_r_self, PyObject *cpy_r_fn_args, PyObject *cpy_r_fn_kwargs);
PyObject *CPyPy__LRUCacheWrapper_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__LRUCacheWrapper_____get__(PyObject *cpy_r_self, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy__LRUCacheWrapper_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__LRUCacheWrapperInstanceMethod_____init__(PyObject *cpy_r_self, PyObject *cpy_r_wrapper, PyObject *cpy_r_instance);
PyObject *CPyPy__LRUCacheWrapperInstanceMethod_____init__(PyObject *self, PyObject *args, PyObject *kw);
char CPyDef__LRUCacheWrapperInstanceMethod___cache_invalidate(PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
PyObject *CPyPy__LRUCacheWrapperInstanceMethod___cache_invalidate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__LRUCacheWrapperInstanceMethod___cache_clear(PyObject *cpy_r_self);
PyObject *CPyPy__LRUCacheWrapperInstanceMethod___cache_clear(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg, PyObject **cpy_r_stop_iter_ptr);
PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_cache_close__LRUCacheWrapperInstanceMethod_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__LRUCacheWrapperInstanceMethod___cache_close(PyObject *cpy_r_self, char cpy_r_cancel, char cpy_r_return_exceptions);
PyObject *CPyPy__LRUCacheWrapperInstanceMethod___cache_close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__LRUCacheWrapperInstanceMethod___cache_info(PyObject *cpy_r_self);
PyObject *CPyPy__LRUCacheWrapperInstanceMethod___cache_info(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__LRUCacheWrapperInstanceMethod___cache_parameters(PyObject *cpy_r_self);
PyObject *CPyPy__LRUCacheWrapperInstanceMethod___cache_parameters(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg, PyObject **cpy_r_stop_iter_ptr);
PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___call___3__LRUCacheWrapperInstanceMethod_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__LRUCacheWrapperInstanceMethod_____call__(PyObject *cpy_r_self, PyObject *cpy_r_fn_args, PyObject *cpy_r_fn_kwargs);
PyObject *CPyPy__LRUCacheWrapperInstanceMethod_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_wrapper__make_wrapper_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy_wrapper__make_wrapper_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_wrapper__make_wrapper_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_fn);
PyObject *CPyPy_wrapper__make_wrapper_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__make_wrapper(PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl);
PyObject *CPyPy__make_wrapper(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_alru_cache(PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl);
PyObject *CPyPy_alru_cache(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
