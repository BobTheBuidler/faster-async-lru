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
PyObject *CPyDef__LRUCacheWrapper(PyObject *cpy_r_fn, PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl, PyObject *cpy_r_jitter);

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
    Py_VISIT(self->___name__);
    Py_VISIT(self->___qualname__);
    Py_VISIT(self->___wrapped__);
    Py_VISIT(self->___maxsize);
    Py_VISIT(self->___ttl);
    Py_VISIT(self->___jitter);
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
    Py_CLEAR(self->___name__);
    Py_CLEAR(self->___qualname__);
    Py_CLEAR(self->___wrapped__);
    Py_CLEAR(self->___maxsize);
    Py_CLEAR(self->___ttl);
    Py_CLEAR(self->___jitter);
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
_LRUCacheWrapper_get___3_name__(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_name__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_qualname__(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_qualname__(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
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
_LRUCacheWrapper_get___3_jitter(async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_jitter(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
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
    {"__name__",
     (getter)_LRUCacheWrapper_get___3_name__, (setter)_LRUCacheWrapper_set___3_name__,
     NULL, NULL},
    {"__qualname__",
     (getter)_LRUCacheWrapper_get___3_qualname__, (setter)_LRUCacheWrapper_set___3_qualname__,
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
    {"__jitter",
     (getter)_LRUCacheWrapper_get___3_jitter, (setter)_LRUCacheWrapper_set___3_jitter,
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
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__init__($self, fn, maxsize, typed, ttl, jitter)\n--\n\n")},
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
    .tp_doc = PyDoc_STR("_LRUCacheWrapper(fn, maxsize, typed, ttl, jitter)\n--\n\n"),
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

PyObject *CPyDef__LRUCacheWrapper(PyObject *cpy_r_fn, PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl, PyObject *cpy_r_jitter)
{
    PyObject *self = CPyDef___mypyc___3_LRUCacheWrapper_setup((PyObject *)CPyType__LRUCacheWrapper);
    if (self == NULL)
        return NULL;
    char res = CPyDef__LRUCacheWrapper_____init__(self, cpy_r_fn, cpy_r_maxsize, cpy_r_typed, cpy_r_ttl, cpy_r_jitter);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
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
    if (tmp != NULL) goto __LL2;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL2;
    CPy_TypeError("int or None", value); 
    tmp = NULL;
__LL2: ;
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
    if (tmp != NULL) goto __LL3;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL3;
    CPy_TypeError("float or None", value); 
    tmp = NULL;
__LL3: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___ttl = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_jitter(async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->___jitter == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__jitter' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPy_INCREF(self->___jitter);
    PyObject *retval = self->___jitter;
    return retval;
}

static int
_LRUCacheWrapper_set___3_jitter(async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '__jitter' cannot be deleted");
        return -1;
    }
    if (self->___jitter != NULL) {
        CPy_DECREF(self->___jitter);
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
    self->___jitter = tmp;
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
    Py_VISIT(self->___name__);
    Py_VISIT(self->___qualname__);
    Py_VISIT(self->___wrapped__);
    Py_VISIT(self->___instance);
    Py_VISIT(self->___wrapper);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
_LRUCacheWrapperInstanceMethod_clear(async_lru____LRUCacheWrapperInstanceMethodObject *self)
{
    Py_CLEAR(self->___name__);
    Py_CLEAR(self->___qualname__);
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
_LRUCacheWrapperInstanceMethod_get___3_name__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_name__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_qualname__(async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_qualname__(async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
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
    {"__name__",
     (getter)_LRUCacheWrapperInstanceMethod_get___3_name__, (setter)_LRUCacheWrapperInstanceMethod_set___3_name__,
     NULL, NULL},
    {"__qualname__",
     (getter)_LRUCacheWrapperInstanceMethod_get___3_qualname__, (setter)_LRUCacheWrapperInstanceMethod_set___3_qualname__,
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
    Py_VISIT(self->___mypyc_generator_attribute__loop);
    Py_VISIT(self->___mypyc_generator_attribute__key);
    Py_VISIT(self->___mypyc_generator_attribute__cache_item);
    Py_VISIT(self->___mypyc_temp__8);
    Py_VISIT(self->___mypyc_temp__9.f0);
    Py_VISIT(self->___mypyc_temp__9.f1);
    Py_VISIT(self->___mypyc_temp__9.f2);
    Py_VISIT(self->___mypyc_generator_attribute__coro);
    Py_VISIT(self->___mypyc_generator_attribute__task);
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
    Py_CLEAR(self->___mypyc_generator_attribute__loop);
    Py_CLEAR(self->___mypyc_generator_attribute__key);
    Py_CLEAR(self->___mypyc_generator_attribute__cache_item);
    Py_CLEAR(self->___mypyc_temp__8);
    Py_CLEAR(self->___mypyc_temp__9.f0);
    Py_CLEAR(self->___mypyc_temp__9.f1);
    Py_CLEAR(self->___mypyc_temp__9.f2);
    Py_CLEAR(self->___mypyc_generator_attribute__coro);
    Py_CLEAR(self->___mypyc_generator_attribute__task);
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
        Py_CLEAR(self->___mypyc_generator_attribute__loop);
        Py_CLEAR(self->___mypyc_generator_attribute__key);
        Py_CLEAR(self->___mypyc_generator_attribute__cache_item);
        Py_CLEAR(self->___mypyc_temp__8);
        Py_CLEAR(self->___mypyc_temp__9.f0);
        Py_CLEAR(self->___mypyc_temp__9.f1);
        Py_CLEAR(self->___mypyc_temp__9.f2);
        Py_CLEAR(self->___mypyc_generator_attribute__coro);
        Py_CLEAR(self->___mypyc_generator_attribute__task);
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
    Py_VISIT(self->_jitter);
    Py_VISIT(self->_wrapper);
    return 0;
}

static int
_make_wrapper_env_clear(async_lru____make_wrapper_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_maxsize);
    Py_CLEAR(self->_ttl);
    Py_CLEAR(self->_jitter);
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
        Py_CLEAR(self->_jitter);
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
    {"_make_wrapper", (PyCFunction)CPyPy__make_wrapper, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_make_wrapper(maxsize, typed, ttl=None, jitter=None)\n--\n\n") /* docstring */},
    {"alru_cache", (PyCFunction)CPyPy_alru_cache, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("alru_cache(maxsize=128, typed=False, *, ttl=None, jitter=None)\n--\n\n") /* docstring */},
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
        CPy_AttributeError("async_lru/__init__.py", "cancel", "_CacheItem", "later_call", 67, CPyStatic_globals);
        goto CPyL8;
    }
CPyL1: ;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (!cpy_r_r2) goto CPyL7;
    cpy_r_r3 = ((async_lru____CacheItemObject *)cpy_r_self)->_later_call;
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cancel", "_CacheItem", "later_call", 68, CPyStatic_globals);
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

char CPyDef__LRUCacheWrapper_____init__(PyObject *cpy_r_self, PyObject *cpy_r_fn, PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl, PyObject *cpy_r_jitter) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    int32_t cpy_r_r4;
    char cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    tuple_T3OOO cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    tuple_T3OOO cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    int32_t cpy_r_r35;
    char cpy_r_r36;
    tuple_T3OOO cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    char cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    int32_t cpy_r_r47;
    char cpy_r_r48;
    tuple_T3OOO cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    char cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    int32_t cpy_r_r61;
    char cpy_r_r62;
    tuple_T3OOO cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    char cpy_r_r67;
    char cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    tuple_T2II cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    char cpy_r_r76;
    char cpy_r_r77;
    char cpy_r_r78;
    char cpy_r_r79;
    char cpy_r_r80;
    char cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    char cpy_r_r88;
    char cpy_r_r89;
    char cpy_r_r90;
    char cpy_r_r91;
    PyObject *cpy_r_r92;
    char cpy_r_r93;
    char cpy_r_r94;
    cpy_r_r0 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_fn, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL4;
    }
    if (likely(PyUnicode_Check(cpy_r_r1)))
        cpy_r_r2 = cpy_r_r1;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 83, CPyStatic_globals, "str", cpy_r_r1);
        goto CPyL4;
    }
    cpy_r_r3 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r4 = PyObject_SetAttr(cpy_r_self, cpy_r_r3, cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    cpy_r_r5 = cpy_r_r4 >= 0;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL11;
CPyL4: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r10 = CPy_ExceptionMatches(cpy_r_r9);
    CPy_DecRef(cpy_r_r9);
    if (cpy_r_r10) goto CPyL8;
    CPy_Reraise();
    if (!0) {
        goto CPyL9;
    } else
        goto CPyL85;
CPyL7: ;
    CPy_Unreachable();
CPyL8: ;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DecRef(cpy_r_r6.f0);
    CPy_DecRef(cpy_r_r6.f1);
    CPy_DecRef(cpy_r_r6.f2);
    goto CPyL11;
CPyL9: ;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DecRef(cpy_r_r6.f0);
    CPy_DecRef(cpy_r_r6.f1);
    CPy_DecRef(cpy_r_r6.f2);
    cpy_r_r11 = CPy_KeepPropagating();
    if (!cpy_r_r11) goto CPyL84;
    CPy_Unreachable();
CPyL11: ;
    cpy_r_r12 = CPy_GetName(cpy_r_fn);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL14;
    }
    if (likely(PyUnicode_Check(cpy_r_r12)))
        cpy_r_r13 = cpy_r_r12;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 87, CPyStatic_globals, "str", cpy_r_r12);
        goto CPyL14;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___name__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___name__);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___name__ = cpy_r_r13;
    cpy_r_r14 = 1;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL21;
CPyL14: ;
    cpy_r_r15 = CPy_CatchError();
    cpy_r_r16 = CPyModule_builtins;
    cpy_r_r17 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r18 = CPyObject_GetAttr(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r19 = CPy_ExceptionMatches(cpy_r_r18);
    CPy_DecRef(cpy_r_r18);
    if (cpy_r_r19) goto CPyL18;
    CPy_Reraise();
    if (!0) {
        goto CPyL19;
    } else
        goto CPyL86;
CPyL17: ;
    CPy_Unreachable();
CPyL18: ;
    CPy_RestoreExcInfo(cpy_r_r15);
    CPy_DecRef(cpy_r_r15.f0);
    CPy_DecRef(cpy_r_r15.f1);
    CPy_DecRef(cpy_r_r15.f2);
    goto CPyL21;
CPyL19: ;
    CPy_RestoreExcInfo(cpy_r_r15);
    CPy_DecRef(cpy_r_r15.f0);
    CPy_DecRef(cpy_r_r15.f1);
    CPy_DecRef(cpy_r_r15.f2);
    cpy_r_r20 = CPy_KeepPropagating();
    if (!cpy_r_r20) goto CPyL84;
    CPy_Unreachable();
CPyL21: ;
    cpy_r_r21 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__qualname__' */
    cpy_r_r22 = CPyObject_GetAttr(cpy_r_fn, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL24;
    }
    if (likely(PyUnicode_Check(cpy_r_r22)))
        cpy_r_r23 = cpy_r_r22;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 91, CPyStatic_globals, "str", cpy_r_r22);
        goto CPyL24;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___qualname__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___qualname__);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___qualname__ = cpy_r_r23;
    cpy_r_r24 = 1;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL31;
CPyL24: ;
    cpy_r_r25 = CPy_CatchError();
    cpy_r_r26 = CPyModule_builtins;
    cpy_r_r27 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r28 = CPyObject_GetAttr(cpy_r_r26, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r29 = CPy_ExceptionMatches(cpy_r_r28);
    CPy_DecRef(cpy_r_r28);
    if (cpy_r_r29) goto CPyL28;
    CPy_Reraise();
    if (!0) {
        goto CPyL29;
    } else
        goto CPyL87;
CPyL27: ;
    CPy_Unreachable();
CPyL28: ;
    CPy_RestoreExcInfo(cpy_r_r25);
    CPy_DecRef(cpy_r_r25.f0);
    CPy_DecRef(cpy_r_r25.f1);
    CPy_DecRef(cpy_r_r25.f2);
    goto CPyL31;
CPyL29: ;
    CPy_RestoreExcInfo(cpy_r_r25);
    CPy_DecRef(cpy_r_r25.f0);
    CPy_DecRef(cpy_r_r25.f1);
    CPy_DecRef(cpy_r_r25.f2);
    cpy_r_r30 = CPy_KeepPropagating();
    if (!cpy_r_r30) goto CPyL84;
    CPy_Unreachable();
CPyL31: ;
    cpy_r_r31 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r32 = CPyObject_GetAttr(cpy_r_fn, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL34;
    }
    if (PyUnicode_Check(cpy_r_r32))
        cpy_r_r33 = cpy_r_r32;
    else {
        cpy_r_r33 = NULL;
    }
    if (cpy_r_r33 != NULL) goto __LL6;
    if (cpy_r_r32 == Py_None)
        cpy_r_r33 = cpy_r_r32;
    else {
        cpy_r_r33 = NULL;
    }
    if (cpy_r_r33 != NULL) goto __LL6;
    CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 95, CPyStatic_globals, "str or None", cpy_r_r32);
    goto CPyL34;
__LL6: ;
    cpy_r_r34 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r35 = PyObject_SetAttr(cpy_r_self, cpy_r_r34, cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r36 = cpy_r_r35 >= 0;
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL41;
CPyL34: ;
    cpy_r_r37 = CPy_CatchError();
    cpy_r_r38 = CPyModule_builtins;
    cpy_r_r39 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r41 = CPy_ExceptionMatches(cpy_r_r40);
    CPy_DecRef(cpy_r_r40);
    if (cpy_r_r41) goto CPyL38;
    CPy_Reraise();
    if (!0) {
        goto CPyL39;
    } else
        goto CPyL88;
CPyL37: ;
    CPy_Unreachable();
CPyL38: ;
    CPy_RestoreExcInfo(cpy_r_r37);
    CPy_DecRef(cpy_r_r37.f0);
    CPy_DecRef(cpy_r_r37.f1);
    CPy_DecRef(cpy_r_r37.f2);
    goto CPyL41;
CPyL39: ;
    CPy_RestoreExcInfo(cpy_r_r37);
    CPy_DecRef(cpy_r_r37.f0);
    CPy_DecRef(cpy_r_r37.f1);
    CPy_DecRef(cpy_r_r37.f2);
    cpy_r_r42 = CPy_KeepPropagating();
    if (!cpy_r_r42) goto CPyL84;
    CPy_Unreachable();
CPyL41: ;
    cpy_r_r43 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r44 = CPyObject_GetAttr(cpy_r_fn, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL44;
    }
    if (likely(PyDict_Check(cpy_r_r44)))
        cpy_r_r45 = cpy_r_r44;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 99, CPyStatic_globals, "dict", cpy_r_r44);
        goto CPyL44;
    }
    cpy_r_r46 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r47 = PyObject_SetAttr(cpy_r_self, cpy_r_r46, cpy_r_r45);
    CPy_DECREF(cpy_r_r45);
    cpy_r_r48 = cpy_r_r47 >= 0;
    if (unlikely(!cpy_r_r48)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL51;
CPyL44: ;
    cpy_r_r49 = CPy_CatchError();
    cpy_r_r50 = CPyModule_builtins;
    cpy_r_r51 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r52 = CPyObject_GetAttr(cpy_r_r50, cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r53 = CPy_ExceptionMatches(cpy_r_r52);
    CPy_DecRef(cpy_r_r52);
    if (cpy_r_r53) goto CPyL48;
    CPy_Reraise();
    if (!0) {
        goto CPyL49;
    } else
        goto CPyL89;
CPyL47: ;
    CPy_Unreachable();
CPyL48: ;
    CPy_RestoreExcInfo(cpy_r_r49);
    CPy_DecRef(cpy_r_r49.f0);
    CPy_DecRef(cpy_r_r49.f1);
    CPy_DecRef(cpy_r_r49.f2);
    goto CPyL51;
CPyL49: ;
    CPy_RestoreExcInfo(cpy_r_r49);
    CPy_DecRef(cpy_r_r49.f0);
    CPy_DecRef(cpy_r_r49.f1);
    CPy_DecRef(cpy_r_r49.f2);
    cpy_r_r54 = CPy_KeepPropagating();
    if (!cpy_r_r54) goto CPyL84;
    CPy_Unreachable();
CPyL51: ;
    cpy_r_r55 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r56 = CPyObject_GetAttr(cpy_r_self, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL56;
    }
    if (likely(PyDict_Check(cpy_r_r56)))
        cpy_r_r57 = cpy_r_r56;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 103, CPyStatic_globals, "dict", cpy_r_r56);
        goto CPyL56;
    }
    cpy_r_r58 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r59 = CPyObject_GetAttr(cpy_r_fn, cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL90;
    }
    if (likely(PyDict_Check(cpy_r_r59)))
        cpy_r_r60 = cpy_r_r59;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 103, CPyStatic_globals, "dict", cpy_r_r59);
        goto CPyL90;
    }
    cpy_r_r61 = CPyDict_Update(cpy_r_r57, cpy_r_r60);
    CPy_DECREF(cpy_r_r57);
    CPy_DECREF(cpy_r_r60);
    cpy_r_r62 = cpy_r_r61 >= 0;
    if (unlikely(!cpy_r_r62)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL63;
CPyL56: ;
    cpy_r_r63 = CPy_CatchError();
    cpy_r_r64 = CPyModule_builtins;
    cpy_r_r65 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r66 = CPyObject_GetAttr(cpy_r_r64, cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r67 = CPy_ExceptionMatches(cpy_r_r66);
    CPy_DecRef(cpy_r_r66);
    if (cpy_r_r67) goto CPyL60;
    CPy_Reraise();
    if (!0) {
        goto CPyL61;
    } else
        goto CPyL91;
CPyL59: ;
    CPy_Unreachable();
CPyL60: ;
    CPy_RestoreExcInfo(cpy_r_r63);
    CPy_DecRef(cpy_r_r63.f0);
    CPy_DecRef(cpy_r_r63.f1);
    CPy_DecRef(cpy_r_r63.f2);
    goto CPyL63;
CPyL61: ;
    CPy_RestoreExcInfo(cpy_r_r63);
    CPy_DecRef(cpy_r_r63.f0);
    CPy_DecRef(cpy_r_r63.f1);
    CPy_DecRef(cpy_r_r63.f2);
    cpy_r_r68 = CPy_KeepPropagating();
    if (!cpy_r_r68) goto CPyL84;
    CPy_Unreachable();
CPyL63: ;
    cpy_r_r69 = CPyModule_sys;
    cpy_r_r70 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r71 = CPyObject_GetAttr(cpy_r_r69, cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    if (likely(PyTuple_Check(cpy_r_r71)))
        cpy_r_r72 = cpy_r_r71;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 108, CPyStatic_globals, "tuple", cpy_r_r71);
        goto CPyL84;
    }
    cpy_r_r73.f0 = 6;
    cpy_r_r73.f1 = 28;
    cpy_r_r74 = PyTuple_New(2);
    if (unlikely(cpy_r_r74 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp7 = CPyTagged_StealAsObject(cpy_r_r73.f0);
    PyTuple_SET_ITEM(cpy_r_r74, 0, __tmp7);
    PyObject *__tmp8 = CPyTagged_StealAsObject(cpy_r_r73.f1);
    PyTuple_SET_ITEM(cpy_r_r74, 1, __tmp8);
    cpy_r_r75 = PyObject_RichCompare(cpy_r_r72, cpy_r_r74, 0);
    CPy_DECREF(cpy_r_r72);
    CPy_DECREF(cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    if (unlikely(!PyBool_Check(cpy_r_r75))) {
        CPy_TypeError("bool", cpy_r_r75); cpy_r_r76 = 2;
    } else
        cpy_r_r76 = cpy_r_r75 == Py_True;
    CPy_DECREF(cpy_r_r75);
    if (unlikely(cpy_r_r76 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    if (!cpy_r_r76) goto CPyL70;
    PyErr_SetString(PyExc_RuntimeError, "Reached allegedly unreachable code!");
    cpy_r_r77 = 0;
    if (unlikely(!cpy_r_r77)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    CPy_Unreachable();
CPyL70: ;
    CPy_INCREF(cpy_r_fn);
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___wrapped__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___wrapped__);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___wrapped__ = cpy_r_fn;
    cpy_r_r78 = 1;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    CPy_INCREF(cpy_r_maxsize);
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize = cpy_r_maxsize;
    cpy_r_r79 = 1;
    if (unlikely(!cpy_r_r79)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___typed = cpy_r_typed;
    cpy_r_r80 = 1;
    if (unlikely(!cpy_r_r80)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    CPy_INCREF(cpy_r_ttl);
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl = cpy_r_ttl;
    cpy_r_r81 = 1;
    if (unlikely(!cpy_r_r81)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    CPy_INCREF(cpy_r_jitter);
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___jitter != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___jitter);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___jitter = cpy_r_jitter;
    cpy_r_r82 = 1;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r83 = CPyStatic_globals;
    cpy_r_r84 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'OrderedDict' */
    cpy_r_r85 = CPyDict_GetItem(cpy_r_r83, cpy_r_r84);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r86 = PyObject_Vectorcall(cpy_r_r85, 0, 0, 0);
    CPy_DECREF(cpy_r_r85);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    if (likely(PyDict_Check(cpy_r_r86)))
        cpy_r_r87 = cpy_r_r86;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 115, CPyStatic_globals, "dict", cpy_r_r86);
        goto CPyL84;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache = cpy_r_r87;
    cpy_r_r88 = 1;
    if (unlikely(!cpy_r_r88)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___closed = 0;
    cpy_r_r89 = 1;
    if (unlikely(!cpy_r_r89)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits != CPY_INT_TAG) {
        CPyTagged_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits = 0;
    cpy_r_r90 = 1;
    if (unlikely(!cpy_r_r90)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses != CPY_INT_TAG) {
        CPyTagged_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses = 0;
    cpy_r_r91 = 1;
    if (unlikely(!cpy_r_r91)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r92 = Py_None;
    if (((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___first_loop != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___first_loop);
    }
    ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___first_loop = cpy_r_r92;
    cpy_r_r93 = 1;
    if (unlikely(!cpy_r_r93)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    return 1;
CPyL84: ;
    cpy_r_r94 = 2;
    return cpy_r_r94;
CPyL85: ;
    CPy_DecRef(cpy_r_r6.f0);
    CPy_DecRef(cpy_r_r6.f1);
    CPy_DecRef(cpy_r_r6.f2);
    goto CPyL7;
CPyL86: ;
    CPy_DecRef(cpy_r_r15.f0);
    CPy_DecRef(cpy_r_r15.f1);
    CPy_DecRef(cpy_r_r15.f2);
    goto CPyL17;
CPyL87: ;
    CPy_DecRef(cpy_r_r25.f0);
    CPy_DecRef(cpy_r_r25.f1);
    CPy_DecRef(cpy_r_r25.f2);
    goto CPyL27;
CPyL88: ;
    CPy_DecRef(cpy_r_r37.f0);
    CPy_DecRef(cpy_r_r37.f1);
    CPy_DecRef(cpy_r_r37.f2);
    goto CPyL37;
CPyL89: ;
    CPy_DecRef(cpy_r_r49.f0);
    CPy_DecRef(cpy_r_r49.f1);
    CPy_DecRef(cpy_r_r49.f2);
    goto CPyL47;
CPyL90: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL56;
CPyL91: ;
    CPy_DecRef(cpy_r_r63.f0);
    CPy_DecRef(cpy_r_r63.f1);
    CPy_DecRef(cpy_r_r63.f2);
    goto CPyL59;
}

PyObject *CPyPy__LRUCacheWrapper_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"fn", "maxsize", "typed", "ttl", "jitter", 0};
    PyObject *obj_fn;
    PyObject *obj_maxsize;
    PyObject *obj_typed;
    PyObject *obj_ttl;
    PyObject *obj_jitter;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "OOOOO", "__init__", kwlist, &obj_fn, &obj_maxsize, &obj_typed, &obj_ttl, &obj_jitter)) {
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
    if (arg_maxsize != NULL) goto __LL9;
    if (obj_maxsize == Py_None)
        arg_maxsize = obj_maxsize;
    else {
        arg_maxsize = NULL;
    }
    if (arg_maxsize != NULL) goto __LL9;
    CPy_TypeError("int or None", obj_maxsize); 
    goto fail;
__LL9: ;
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
    if (arg_ttl != NULL) goto __LL10;
    if (obj_ttl == Py_None)
        arg_ttl = obj_ttl;
    else {
        arg_ttl = NULL;
    }
    if (arg_ttl != NULL) goto __LL10;
    CPy_TypeError("float or None", obj_ttl); 
    goto fail;
__LL10: ;
    PyObject *arg_jitter;
    if (CPyFloat_Check(obj_jitter))
        arg_jitter = obj_jitter;
    else {
        arg_jitter = NULL;
    }
    if (arg_jitter != NULL) goto __LL11;
    if (obj_jitter == Py_None)
        arg_jitter = obj_jitter;
    else {
        arg_jitter = NULL;
    }
    if (arg_jitter != NULL) goto __LL11;
    CPy_TypeError("float or None", obj_jitter); 
    goto fail;
__LL11: ;
    char retval = CPyDef__LRUCacheWrapper_____init__(arg_self, arg_fn, arg_maxsize, arg_typed, arg_ttl, arg_jitter);
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
        CPy_AttributeError("async_lru/__init__.py", "__tasks", "_LRUCacheWrapper", "__cache", 128, CPyStatic_globals);
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
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__tasks", 126, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r8);
        goto CPyL19;
    }
    cpy_r_r10 = ((async_lru____CacheItemObject *)cpy_r_r9)->_task;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__tasks", "_CacheItem", "task", 129, CPyStatic_globals);
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
        CPy_AttributeError("async_lru/__init__.py", "_check_loop", "_LRUCacheWrapper", "__first_loop", 134, CPyStatic_globals);
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
        CPy_AttributeError("async_lru/__init__.py", "_check_loop", "_LRUCacheWrapper", "__first_loop", 136, CPyStatic_globals);
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
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___typed;
    if (unlikely(cpy_r_r0 == 2)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_invalidate", "_LRUCacheWrapper", "__typed", 144, CPyStatic_globals);
        goto CPyL11;
    }
CPyL1: ;
    cpy_r_r1 = CPyStatic_globals;
    cpy_r_r2 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_make_key' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r4 = cpy_r_r0 ? Py_True : Py_False;
    PyObject *cpy_r_r5[3] = {cpy_r_args, cpy_r_kwargs, cpy_r_r4};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = PyObject_Vectorcall(cpy_r_r3, cpy_r_r6, 3, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r8 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_invalidate", "_LRUCacheWrapper", "__cache", 146, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_INCREF(cpy_r_r8);
CPyL4: ;
    cpy_r_r9 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'pop' */
    cpy_r_r10 = Py_None;
    PyObject *cpy_r_r11[3] = {cpy_r_r8, cpy_r_r7, cpy_r_r10};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = PyObject_VectorcallMethod(cpy_r_r9, cpy_r_r12, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r7);
    if (Py_TYPE(cpy_r_r13) == CPyType__CacheItem)
        cpy_r_r14 = cpy_r_r13;
    else {
        cpy_r_r14 = NULL;
    }
    if (cpy_r_r14 != NULL) goto __LL12;
    if (cpy_r_r13 == Py_None)
        cpy_r_r14 = cpy_r_r13;
    else {
        cpy_r_r14 = NULL;
    }
    if (cpy_r_r14 != NULL) goto __LL12;
    CPy_TypeErrorTraceback("async_lru/__init__.py", "cache_invalidate", 146, CPyStatic_globals, "async_lru._CacheItem or None", cpy_r_r13);
    goto CPyL11;
__LL12: ;
    cpy_r_r15 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r16 = cpy_r_r14 == cpy_r_r15;
    if (cpy_r_r16) {
        goto CPyL14;
    } else
        goto CPyL8;
CPyL7: ;
    return 0;
CPyL8: ;
    if (likely(cpy_r_r14 != Py_None))
        cpy_r_r17 = cpy_r_r14;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "cache_invalidate", 150, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r14);
        goto CPyL11;
    }
    cpy_r_r18 = CPyDef__CacheItem___cancel(cpy_r_r17);
    CPy_DECREF_NO_IMM(cpy_r_r17);
    if (unlikely(cpy_r_r18 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL11;
    }
    return 1;
CPyL11: ;
    cpy_r_r19 = 2;
    return cpy_r_r19;
CPyL12: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL11;
CPyL13: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r8);
    goto CPyL11;
CPyL14: ;
    CPy_DECREF(cpy_r_r14);
    goto CPyL7;
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
        CPy_AttributeError("async_lru/__init__.py", "cache_clear", "_LRUCacheWrapper", "__cache", 157, CPyStatic_globals);
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
        CPy_TypeErrorTraceback("async_lru/__init__.py", "cache_clear", 157, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r9);
        goto CPyL23;
    }
    cpy_r_r11 = ((async_lru____CacheItemObject *)cpy_r_r10)->_later_call;
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_clear", "_CacheItem", "later_call", 158, CPyStatic_globals);
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
        CPy_AttributeError("async_lru/__init__.py", "cache_clear", "_LRUCacheWrapper", "__cache", 160, CPyStatic_globals);
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
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    CPyPtr cpy_r_r19;
    int64_t cpy_r_r20;
    CPyTagged cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    CPyPtr cpy_r_r30;
    int64_t cpy_r_r31;
    int64_t cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
    int64_t cpy_r_r35;
    CPyPtr cpy_r_r36;
    CPyPtr cpy_r_r37;
    int64_t cpy_r_r38;
    CPyPtr cpy_r_r39;
    PyObject *cpy_r_r40;
    char cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject **cpy_r_r45;
    PyObject *cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject **cpy_r_r51;
    PyObject *cpy_r_r52;
    int64_t cpy_r_r53;
    int64_t cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    char cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    char cpy_r_r74;
    PyObject *cpy_r_r75;
    char cpy_r_r76;
    PyObject *cpy_r_r77;
    char cpy_r_r78;
    tuple_T3OOO cpy_r_r79;
    char cpy_r_r80;
    PyObject **cpy_r_r81;
    PyObject *cpy_r_r82;
    char cpy_r_r83;
    tuple_T3OOO cpy_r_r84;
    tuple_T3OOO cpy_r_r85;
    tuple_T3OOO cpy_r_r86;
    char cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    char cpy_r_r92;
    char cpy_r_r93;
    char cpy_r_r94;
    char cpy_r_r95;
    PyObject *cpy_r_r96;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__;
    goto CPyL82;
CPyL1: ;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = cpy_r_type != cpy_r_r3;
    if (!cpy_r_r4) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r5 = CPyModule_asyncio;
    cpy_r_r6 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'get_running_loop' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r8 = PyObject_Vectorcall(cpy_r_r7, 0, 0, 0);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop != NULL) {
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop = cpy_r_r8;
    cpy_r_r9 = 1;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r10 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "self", 164, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF_NO_IMM(cpy_r_r10);
CPyL8: ;
    cpy_r_r11 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop;
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "loop", 164, CPyStatic_globals);
        goto CPyL87;
    }
    CPy_INCREF(cpy_r_r11);
CPyL9: ;
    cpy_r_r12 = CPyDef__LRUCacheWrapper____check_loop(cpy_r_r10, cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    if (unlikely(cpy_r_r12 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r13 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "self", 165, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF_NO_IMM(cpy_r_r13);
CPyL11: ;
    ((async_lru____LRUCacheWrapperObject *)cpy_r_r13)->___closed = 1;
    cpy_r_r14 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r13);
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r15 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "self", 167, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF_NO_IMM(cpy_r_r15);
CPyL13: ;
    cpy_r_r16 = CPyDef__LRUCacheWrapper_____tasks(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
CPyL14: ;
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks != NULL) {
        CPy_DECREF_NO_IMM(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks = cpy_r_r16;
    cpy_r_r17 = 1;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r18 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks;
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "tasks", 168, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF_NO_IMM(cpy_r_r18);
CPyL16: ;
    cpy_r_r19 = (CPyPtr)&((PyVarObject *)cpy_r_r18)->ob_size;
    cpy_r_r20 = *(int64_t *)cpy_r_r19;
    CPy_DECREF_NO_IMM(cpy_r_r18);
    cpy_r_r21 = cpy_r_r20 << 1;
    cpy_r_r22 = cpy_r_r21 != 0;
    if (cpy_r_r22) goto CPyL22;
    cpy_r_r23 = Py_None;
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL21;
    CPyGen_SetStopIterationValue(cpy_r_r23);
    if (!0) goto CPyL86;
    CPy_Unreachable();
CPyL21: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r23;
    return 0;
CPyL22: ;
    cpy_r_r25 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__wait;
    if (unlikely(cpy_r_r25 == 2)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "wait", 171, CPyStatic_globals);
        goto CPyL86;
    }
CPyL23: ;
    if (cpy_r_r25) goto CPyL42;
CPyL24: ;
    cpy_r_r26 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks;
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "tasks", 172, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF_NO_IMM(cpy_r_r26);
CPyL25: ;
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0 != NULL) {
        CPy_DECREF_NO_IMM(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0 = cpy_r_r26;
    cpy_r_r27 = 1;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL86;
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1 = 0;
    cpy_r_r28 = 1;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL86;
    }
CPyL27: ;
    cpy_r_r29 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0;
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__0", 172, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF_NO_IMM(cpy_r_r29);
CPyL28: ;
    cpy_r_r30 = (CPyPtr)&((PyVarObject *)cpy_r_r29)->ob_size;
    cpy_r_r31 = *(int64_t *)cpy_r_r30;
    CPy_DECREF_NO_IMM(cpy_r_r29);
    cpy_r_r32 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1;
    if (unlikely(cpy_r_r32 == -113)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__1", 172, CPyStatic_globals);
        goto CPyL86;
    }
CPyL29: ;
    cpy_r_r33 = cpy_r_r32 < cpy_r_r31;
    if (!cpy_r_r33) goto CPyL42;
    cpy_r_r34 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0;
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__0", 172, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF_NO_IMM(cpy_r_r34);
CPyL31: ;
    cpy_r_r35 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1;
    if (unlikely(cpy_r_r35 == -113)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__1", 172, CPyStatic_globals);
        goto CPyL88;
    }
CPyL32: ;
    cpy_r_r36 = (CPyPtr)&((PyListObject *)cpy_r_r34)->ob_item;
    cpy_r_r37 = *(CPyPtr *)cpy_r_r36;
    cpy_r_r38 = cpy_r_r35 * 8;
    cpy_r_r39 = cpy_r_r37 + cpy_r_r38;
    cpy_r_r40 = *(PyObject * *)cpy_r_r39;
    CPy_INCREF(cpy_r_r40);
    CPy_DECREF_NO_IMM(cpy_r_r34);
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task != NULL) {
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task = cpy_r_r40;
    cpy_r_r41 = 1;
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r42 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "task", 173, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF(cpy_r_r42);
CPyL34: ;
    cpy_r_r43 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'done' */
    PyObject *cpy_r_r44[1] = {cpy_r_r42};
    cpy_r_r45 = (PyObject **)&cpy_r_r44;
    cpy_r_r46 = PyObject_VectorcallMethod(cpy_r_r43, cpy_r_r45, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL89;
    }
    CPy_DECREF(cpy_r_r42);
    if (unlikely(!PyBool_Check(cpy_r_r46))) {
        CPy_TypeError("bool", cpy_r_r46); cpy_r_r47 = 2;
    } else
        cpy_r_r47 = cpy_r_r46 == Py_True;
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r47 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    if (cpy_r_r47) goto CPyL40;
    cpy_r_r48 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "task", 174, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF(cpy_r_r48);
CPyL38: ;
    cpy_r_r49 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cancel' */
    PyObject *cpy_r_r50[1] = {cpy_r_r48};
    cpy_r_r51 = (PyObject **)&cpy_r_r50;
    cpy_r_r52 = PyObject_VectorcallMethod(cpy_r_r49, cpy_r_r51, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL90;
    } else
        goto CPyL91;
CPyL39: ;
    CPy_DECREF(cpy_r_r48);
CPyL40: ;
    cpy_r_r53 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1;
    if (unlikely(cpy_r_r53 == -113)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__1", 172, CPyStatic_globals);
        goto CPyL86;
    }
CPyL41: ;
    cpy_r_r54 = cpy_r_r53 + 1;
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1 = cpy_r_r54;
    cpy_r_r55 = 1;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    } else
        goto CPyL27;
CPyL42: ;
    cpy_r_r56 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks;
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "tasks", 176, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF_NO_IMM(cpy_r_r56);
CPyL43: ;
    cpy_r_r57 = CPyModule_asyncio;
    cpy_r_r58 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'gather' */
    cpy_r_r59 = CPyObject_GetAttr(cpy_r_r57, cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL92;
    }
    cpy_r_r60 = PyList_New(0);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL93;
    }
    cpy_r_r61 = CPyList_Extend(cpy_r_r60, cpy_r_r56);
    CPy_DECREF_NO_IMM(cpy_r_r56);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL94;
    } else
        goto CPyL95;
CPyL46: ;
    cpy_r_r62 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'return_exceptions' */
    cpy_r_r63 = PyList_AsTuple(cpy_r_r60);
    CPy_DECREF_NO_IMM(cpy_r_r60);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r64 = 1 ? Py_True : Py_False;
    cpy_r_r65 = CPyDict_Build(1, cpy_r_r62, cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r66 = PyObject_Call(cpy_r_r59, cpy_r_r63, cpy_r_r65);
    CPy_DECREF(cpy_r_r59);
    CPy_DECREF(cpy_r_r63);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r67 = CPy_GetCoro(cpy_r_r66);
    CPy_DECREF(cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2 != NULL) {
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2 = cpy_r_r67;
    cpy_r_r68 = 1;
    if (unlikely(!cpy_r_r68)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r69 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2;
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__2", -1, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF(cpy_r_r69);
CPyL52: ;
    cpy_r_r70 = CPyIter_Next(cpy_r_r69);
    CPy_DECREF(cpy_r_r69);
    if (cpy_r_r70 != NULL) goto CPyL55;
    cpy_r_r71 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r72 = cpy_r_r71;
    CPy_DECREF(cpy_r_r72);
    cpy_r_r73 = NULL;
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2 != NULL) {
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2 = cpy_r_r73;
    cpy_r_r74 = 1;
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    } else
        goto CPyL77;
CPyL55: ;
    cpy_r_r75 = cpy_r_r70;
CPyL56: ;
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 1;
    return cpy_r_r75;
CPyL57: ;
    cpy_r_r77 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r78 = cpy_r_type != cpy_r_r77;
    if (!cpy_r_r78) goto CPyL98;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL61;
    } else
        goto CPyL99;
CPyL59: ;
    CPy_Unreachable();
CPyL60: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL72;
CPyL61: ;
    cpy_r_r79 = CPy_CatchError();
    if (((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3.f0 != NULL) {
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3.f0);
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3.f1);
        CPy_DECREF(((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3.f2);
    }
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3 = cpy_r_r79;
    cpy_r_r80 = 1;
    if (unlikely(!cpy_r_r80)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL100;
    }
    cpy_r_r81 = (PyObject **)&cpy_r_r1;
    cpy_r_r82 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2;
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__2", -1, CPyStatic_globals);
        goto CPyL100;
    }
    CPy_INCREF(cpy_r_r82);
CPyL63: ;
    cpy_r_r83 = CPy_YieldFromErrorHandle(cpy_r_r82, cpy_r_r81);
    CPy_DecRef(cpy_r_r82);
    if (unlikely(cpy_r_r83 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL100;
    }
    if (cpy_r_r83) goto CPyL67;
    cpy_r_r75 = cpy_r_r1;
    cpy_r_r84 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3;
    if (unlikely(cpy_r_r84.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL101;
    }
    CPy_INCREF(cpy_r_r84.f0);
    CPy_INCREF(cpy_r_r84.f1);
    CPy_INCREF(cpy_r_r84.f2);
CPyL66: ;
    CPy_RestoreExcInfo(cpy_r_r84);
    CPy_DecRef(cpy_r_r84.f0);
    CPy_DecRef(cpy_r_r84.f1);
    CPy_DecRef(cpy_r_r84.f2);
    goto CPyL56;
CPyL67: ;
    cpy_r_r72 = cpy_r_r1;
    CPy_DecRef(cpy_r_r72);
    cpy_r_r85 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3;
    if (unlikely(cpy_r_r85.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_INCREF(cpy_r_r85.f0);
    CPy_INCREF(cpy_r_r85.f1);
    CPy_INCREF(cpy_r_r85.f2);
CPyL68: ;
    CPy_RestoreExcInfo(cpy_r_r85);
    CPy_DecRef(cpy_r_r85.f0);
    CPy_DecRef(cpy_r_r85.f1);
    CPy_DecRef(cpy_r_r85.f2);
    goto CPyL77;
CPyL69: ;
    cpy_r_r86 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3;
    if (unlikely(cpy_r_r86.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_INCREF(cpy_r_r86.f0);
    CPy_INCREF(cpy_r_r86.f1);
    CPy_INCREF(cpy_r_r86.f2);
CPyL70: ;
    CPy_RestoreExcInfo(cpy_r_r86);
    CPy_DecRef(cpy_r_r86.f0);
    CPy_DecRef(cpy_r_r86.f1);
    CPy_DecRef(cpy_r_r86.f2);
    cpy_r_r87 = CPy_KeepPropagating();
    if (!cpy_r_r87) goto CPyL86;
    CPy_Unreachable();
CPyL72: ;
    cpy_r_r88 = ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2;
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__2", -1, CPyStatic_globals);
        goto CPyL102;
    }
    CPy_INCREF(cpy_r_r88);
CPyL73: ;
    cpy_r_r89 = CPyIter_Send(cpy_r_r88, cpy_r_arg);
    CPy_DECREF(cpy_r_r88);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r89 == NULL) goto CPyL75;
    cpy_r_r75 = cpy_r_r89;
    goto CPyL56;
CPyL75: ;
    cpy_r_r90 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r72 = cpy_r_r90;
    CPy_DECREF(cpy_r_r72);
CPyL77: ;
    cpy_r_r91 = Py_None;
    ((async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL81;
    CPyGen_SetStopIterationValue(cpy_r_r91);
    if (!0) goto CPyL86;
    CPy_Unreachable();
CPyL81: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r91;
    return 0;
CPyL82: ;
    cpy_r_r93 = cpy_r_r2 == 0;
    if (cpy_r_r93) goto CPyL103;
    cpy_r_r94 = cpy_r_r2 == 1;
    if (cpy_r_r94) {
        goto CPyL57;
    } else
        goto CPyL104;
CPyL84: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r95 = 0;
    if (unlikely(!cpy_r_r95)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_Unreachable();
CPyL86: ;
    cpy_r_r96 = NULL;
    return cpy_r_r96;
CPyL87: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL86;
CPyL88: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL86;
CPyL89: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL86;
CPyL90: ;
    CPy_DecRef(cpy_r_r48);
    goto CPyL86;
CPyL91: ;
    CPy_DECREF(cpy_r_r52);
    goto CPyL39;
CPyL92: ;
    CPy_DecRef(cpy_r_r56);
    goto CPyL86;
CPyL93: ;
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r59);
    goto CPyL86;
CPyL94: ;
    CPy_DecRef(cpy_r_r59);
    CPy_DecRef(cpy_r_r60);
    goto CPyL86;
CPyL95: ;
    CPy_DECREF(cpy_r_r61);
    goto CPyL46;
CPyL96: ;
    CPy_DecRef(cpy_r_r59);
    goto CPyL86;
CPyL97: ;
    CPy_DecRef(cpy_r_r59);
    CPy_DecRef(cpy_r_r63);
    goto CPyL86;
CPyL98: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL60;
CPyL99: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL59;
CPyL100: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL69;
CPyL101: ;
    CPy_DecRef(cpy_r_r75);
    goto CPyL69;
CPyL102: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL86;
CPyL103: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL1;
CPyL104: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL84;
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
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    cpy_r_r0 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_info", "_LRUCacheWrapper", "__hits", 180, CPyStatic_globals);
        goto CPyL8;
    }
    CPyTagged_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_info", "_LRUCacheWrapper", "__misses", 181, CPyStatic_globals);
        goto CPyL9;
    }
    CPyTagged_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_info", "_LRUCacheWrapper", "__maxsize", 182, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_INCREF(cpy_r_r2);
CPyL3: ;
    cpy_r_r3 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_info", "_LRUCacheWrapper", "__cache", 183, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_INCREF(cpy_r_r3);
CPyL4: ;
    cpy_r_r4 = PyDict_Size(cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    cpy_r_r5 = cpy_r_r4 << 1;
    cpy_r_r6 = CPyStatic_globals;
    cpy_r_r7 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheInfo' */
    cpy_r_r8 = CPyDict_GetItem(cpy_r_r6, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_info", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r9 = CPyTagged_StealAsObject(cpy_r_r0);
    cpy_r_r10 = CPyTagged_StealAsObject(cpy_r_r1);
    cpy_r_r11 = CPyTagged_StealAsObject(cpy_r_r5);
    PyObject *cpy_r_r12[4] = {cpy_r_r9, cpy_r_r10, cpy_r_r2, cpy_r_r11};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_Vectorcall(cpy_r_r8, cpy_r_r13, 4, 0);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "cache_info", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r11);
    if (likely(PyTuple_Check(cpy_r_r14)))
        cpy_r_r15 = cpy_r_r14;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "cache_info", 179, CPyStatic_globals, "tuple", cpy_r_r14);
        goto CPyL8;
    }
    return cpy_r_r15;
CPyL8: ;
    cpy_r_r16 = NULL;
    return cpy_r_r16;
CPyL9: ;
    CPyTagged_DecRef(cpy_r_r0);
    goto CPyL8;
CPyL10: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r1);
    goto CPyL8;
CPyL11: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL8;
CPyL12: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r11);
    goto CPyL8;
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
        CPy_AttributeError("async_lru/__init__.py", "cache_parameters", "_LRUCacheWrapper", "__maxsize", 188, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___typed;
    if (unlikely(cpy_r_r1 == 2)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_parameters", "_LRUCacheWrapper", "__typed", 189, CPyStatic_globals);
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
        CPy_AttributeError("async_lru/__init__.py", "cache_parameters", "_LRUCacheWrapper", "__closed", 191, CPyStatic_globals);
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
        CPy_TypeErrorTraceback("async_lru/__init__.py", "cache_parameters", 187, CPyStatic_globals, "dict", cpy_r_r16);
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
        CPy_AttributeError("async_lru/__init__.py", "_cache_hit", "_LRUCacheWrapper", "__hits", 195, CPyStatic_globals);
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
        CPy_AttributeError("async_lru/__init__.py", "_cache_hit", "_LRUCacheWrapper", "__cache", 196, CPyStatic_globals);
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
        CPy_AttributeError("async_lru/__init__.py", "_cache_miss", "_LRUCacheWrapper", "__misses", 199, CPyStatic_globals);
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
    double cpy_r_r24;
    char cpy_r_r25;
    double cpy_r_effective_ttl;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    double cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    double cpy_r_r42;
    char cpy_r_r43;
    double cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject **cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    char cpy_r_r60;
    char cpy_r_r61;
    cpy_r_r0 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cancelled' */
    PyObject *cpy_r_r1[1] = {cpy_r_task};
    cpy_r_r2 = (PyObject **)&cpy_r_r1;
    cpy_r_r3 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r2, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
    }
    if (unlikely(!PyBool_Check(cpy_r_r3))) {
        CPy_TypeError("bool", cpy_r_r3); cpy_r_r4 = 2;
    } else
        cpy_r_r4 = cpy_r_r3 == Py_True;
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
    }
    if (cpy_r_r4) goto CPyL5;
    cpy_r_r5 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_exception' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_task, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r7 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r8 = cpy_r_r6 != cpy_r_r7;
    CPy_DECREF(cpy_r_r6);
    if (!cpy_r_r8) goto CPyL8;
CPyL5: ;
    cpy_r_r9 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__cache", 206, CPyStatic_globals);
        goto CPyL36;
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
        goto CPyL37;
    } else
        goto CPyL38;
CPyL7: ;
    CPy_DECREF(cpy_r_r9);
    return 1;
CPyL8: ;
    cpy_r_r15 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__cache", 209, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_INCREF(cpy_r_r15);
CPyL9: ;
    cpy_r_r16 = CPyDict_GetWithNone(cpy_r_r15, cpy_r_key);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
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
    CPy_TypeErrorTraceback("async_lru/__init__.py", "_task_done_callback", 209, CPyStatic_globals, "async_lru._CacheItem or None", cpy_r_r16);
    goto CPyL36;
__LL15: ;
    cpy_r_r18 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl;
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__ttl", 210, CPyStatic_globals);
        goto CPyL39;
    }
CPyL12: ;
    cpy_r_r19 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r20 = cpy_r_r18 != cpy_r_r19;
    if (!cpy_r_r20) goto CPyL40;
    cpy_r_r21 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r22 = cpy_r_r17 != cpy_r_r21;
    if (!cpy_r_r22) goto CPyL40;
    cpy_r_r23 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl;
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__ttl", 211, CPyStatic_globals);
        goto CPyL39;
    }
    CPy_INCREF(cpy_r_r23);
CPyL15: ;
    cpy_r_r24 = PyFloat_AsDouble(cpy_r_r23);
    if (cpy_r_r24 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r23); cpy_r_r24 = -113.0;
    }
    CPy_DECREF(cpy_r_r23);
    cpy_r_r25 = cpy_r_r24 == -113.0;
    if (unlikely(cpy_r_r25)) goto CPyL17;
CPyL16: ;
    cpy_r_effective_ttl = cpy_r_r24;
    cpy_r_r26 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___jitter;
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__jitter", 212, CPyStatic_globals);
        goto CPyL39;
    }
    goto CPyL18;
CPyL17: ;
    cpy_r_r27 = PyErr_Occurred();
    if (unlikely(cpy_r_r27 != NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    } else
        goto CPyL16;
CPyL18: ;
    cpy_r_r28 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r29 = cpy_r_r26 != cpy_r_r28;
    if (!cpy_r_r29) goto CPyL27;
    cpy_r_r30 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___jitter;
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__jitter", 213, CPyStatic_globals);
        goto CPyL39;
    }
    CPy_INCREF(cpy_r_r30);
CPyL20: ;
    cpy_r_r31 = PyFloat_AsDouble(cpy_r_r30);
    if (cpy_r_r31 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r30); cpy_r_r31 = -113.0;
    }
    CPy_DECREF(cpy_r_r30);
    cpy_r_r32 = cpy_r_r31 == -113.0;
    if (unlikely(cpy_r_r32)) goto CPyL22;
CPyL21: ;
    cpy_r_r33 = CPyModule_random;
    cpy_r_r34 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'uniform' */
    cpy_r_r35 = CPyObject_GetAttr(cpy_r_r33, cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    } else
        goto CPyL23;
CPyL22: ;
    cpy_r_r36 = PyErr_Occurred();
    if (unlikely(cpy_r_r36 != NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    } else
        goto CPyL21;
CPyL23: ;
    cpy_r_r37 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 0 */
    cpy_r_r38 = PyFloat_FromDouble(cpy_r_r31);
    PyObject *cpy_r_r39[2] = {cpy_r_r37, cpy_r_r38};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = PyObject_Vectorcall(cpy_r_r35, cpy_r_r40, 2, 0);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_DECREF(cpy_r_r38);
    cpy_r_r42 = PyFloat_AsDouble(cpy_r_r41);
    if (cpy_r_r42 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r41); cpy_r_r42 = -113.0;
    }
    CPy_DECREF(cpy_r_r41);
    cpy_r_r43 = cpy_r_r42 == -113.0;
    if (unlikely(cpy_r_r43)) goto CPyL26;
CPyL25: ;
    cpy_r_r44 = cpy_r_effective_ttl + cpy_r_r42;
    cpy_r_effective_ttl = cpy_r_r44;
    goto CPyL27;
CPyL26: ;
    cpy_r_r45 = PyErr_Occurred();
    if (unlikely(cpy_r_r45 != NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    } else
        goto CPyL25;
CPyL27: ;
    cpy_r_r46 = CPyModule_asyncio;
    cpy_r_r47 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'get_running_loop' */
    cpy_r_r48 = CPyObject_GetAttr(cpy_r_r46, cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r49 = PyObject_Vectorcall(cpy_r_r48, 0, 0, 0);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r50 = ((async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__cache", 216, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_INCREF(cpy_r_r50);
CPyL30: ;
    cpy_r_r51 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'pop' */
    cpy_r_r52 = CPyObject_GetAttr(cpy_r_r50, cpy_r_r51);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r53 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'call_later' */
    cpy_r_r54 = PyFloat_FromDouble(cpy_r_effective_ttl);
    cpy_r_r55 = Py_None;
    PyObject *cpy_r_r56[5] = {cpy_r_r49, cpy_r_r54, cpy_r_r52, cpy_r_key, cpy_r_r55};
    cpy_r_r57 = (PyObject **)&cpy_r_r56;
    cpy_r_r58 = PyObject_VectorcallMethod(cpy_r_r53, cpy_r_r57, 9223372036854775813ULL, 0);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_DECREF(cpy_r_r49);
    CPy_DECREF(cpy_r_r54);
    CPy_DECREF(cpy_r_r52);
    if (likely(cpy_r_r17 != Py_None))
        cpy_r_r59 = cpy_r_r17;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "_task_done_callback", 215, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r17);
        goto CPyL44;
    }
    if (((async_lru____CacheItemObject *)cpy_r_r59)->_later_call != NULL) {
        CPy_DECREF(((async_lru____CacheItemObject *)cpy_r_r59)->_later_call);
    }
    ((async_lru____CacheItemObject *)cpy_r_r59)->_later_call = cpy_r_r58;
    cpy_r_r60 = 1;
    if (unlikely(!cpy_r_r60)) {
        CPy_AddTraceback("async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    }
    CPy_DECREF(cpy_r_r17);
CPyL35: ;
    return 1;
CPyL36: ;
    cpy_r_r61 = 2;
    return cpy_r_r61;
CPyL37: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL36;
CPyL38: ;
    CPy_DECREF(cpy_r_r14);
    goto CPyL7;
CPyL39: ;
    CPy_DecRef(cpy_r_r17);
    goto CPyL36;
CPyL40: ;
    CPy_DECREF(cpy_r_r17);
    goto CPyL35;
CPyL41: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r38);
    goto CPyL36;
CPyL42: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r49);
    goto CPyL36;
CPyL43: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r49);
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r54);
    goto CPyL36;
CPyL44: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r58);
    goto CPyL36;
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
    PyObject **cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject **cpy_r_r68;
    PyObject *cpy_r_r69;
    tuple_T3OOO cpy_r_r70;
    char cpy_r_r71;
    tuple_T3OOO cpy_r_r72;
    tuple_T3OOO cpy_r_r73;
    PyObject *cpy_r_r74;
    char cpy_r_r75;
    tuple_T3OOO cpy_r_r76;
    PyObject *cpy_r_r77;
    CPyTagged cpy_r_r78;
    CPyTagged cpy_r_r79;
    char cpy_r_r80;
    PyObject *cpy_r_r81;
    char cpy_r_r82;
    char cpy_r_r83;
    PyObject *cpy_r_r84;
    char cpy_r_r85;
    char cpy_r_r86;
    char cpy_r_r87;
    char cpy_r_r88;
    PyObject *cpy_r_r89;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__;
    goto CPyL89;
CPyL1: ;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = cpy_r_type != cpy_r_r3;
    if (!cpy_r_r4) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL93;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r5 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "cache_item", 222, CPyStatic_globals);
        goto CPyL93;
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
        goto CPyL93;
    }
CPyL6: ;
    if (((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task != NULL) {
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task);
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task = cpy_r_r6;
    cpy_r_r7 = 1;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL93;
    }
    cpy_r_r8 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "task", 225, CPyStatic_globals);
        goto CPyL39;
    }
    CPy_INCREF(cpy_r_r8);
CPyL8: ;
    cpy_r_r9 = CPyModule_asyncio;
    cpy_r_r10 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'shield' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL94;
    }
    PyObject *cpy_r_r12[1] = {cpy_r_r8};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_Vectorcall(cpy_r_r11, cpy_r_r13, 1, 0);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL94;
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
        goto CPyL95;
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
    if (!cpy_r_r26) goto CPyL96;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL22;
    } else
        goto CPyL97;
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
        goto CPyL98;
    }
    cpy_r_r29 = (PyObject **)&cpy_r_r1;
    cpy_r_r30 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4;
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL98;
    }
    CPy_INCREF(cpy_r_r30);
CPyL24: ;
    cpy_r_r31 = CPy_YieldFromErrorHandle(cpy_r_r30, cpy_r_r29);
    CPy_DecRef(cpy_r_r30);
    if (unlikely(cpy_r_r31 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL98;
    }
    if (cpy_r_r31) goto CPyL28;
    cpy_r_r23 = cpy_r_r1;
    cpy_r_r32 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5;
    if (unlikely(cpy_r_r32.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL99;
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
        goto CPyL100;
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
        goto CPyL101;
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
        goto CPyL65;
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
        goto CPyL62;
    }
    cpy_r_r42 = CPyModule_asyncio;
    cpy_r_r43 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'CancelledError' */
    cpy_r_r44 = CPyObject_GetAttr(cpy_r_r42, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r45 = CPy_ExceptionMatches(cpy_r_r44);
    CPy_DecRef(cpy_r_r44);
    if (!cpy_r_r45) goto CPyL60;
    cpy_r_r46 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "cache_item", 229, CPyStatic_globals);
        goto CPyL62;
    }
    CPy_INCREF_NO_IMM(cpy_r_r46);
CPyL43: ;
    cpy_r_r47 = ((async_lru____CacheItemObject *)cpy_r_r46)->_waiters;
    if (unlikely(cpy_r_r47 == CPY_INT_TAG)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_CacheItem", "waiters", 229, CPyStatic_globals);
        goto CPyL102;
    }
CPyL44: ;
    cpy_r_r48 = cpy_r_r47 == 2;
    CPy_DecRef(cpy_r_r46);
    if (!cpy_r_r48) goto CPyL58;
    cpy_r_r49 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "task", 229, CPyStatic_globals);
        goto CPyL62;
    }
    CPy_INCREF(cpy_r_r49);
CPyL46: ;
    cpy_r_r50 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'done' */
    PyObject *cpy_r_r51[1] = {cpy_r_r49};
    cpy_r_r52 = (PyObject **)&cpy_r_r51;
    cpy_r_r53 = PyObject_VectorcallMethod(cpy_r_r50, cpy_r_r52, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL103;
    }
    CPy_DecRef(cpy_r_r49);
    if (unlikely(!PyBool_Check(cpy_r_r53))) {
        CPy_TypeError("bool", cpy_r_r53); cpy_r_r54 = 2;
    } else
        cpy_r_r54 = cpy_r_r53 == Py_True;
    CPy_DecRef(cpy_r_r53);
    if (unlikely(cpy_r_r54 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL62;
    }
    if (cpy_r_r54) goto CPyL58;
    cpy_r_r55 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "cache_item", 230, CPyStatic_globals);
        goto CPyL62;
    }
    CPy_INCREF_NO_IMM(cpy_r_r55);
CPyL50: ;
    cpy_r_r56 = CPyDef__CacheItem___cancel(cpy_r_r55);
    CPy_DecRef(cpy_r_r55);
    if (unlikely(cpy_r_r56 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r57 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "task", 231, CPyStatic_globals);
        goto CPyL62;
    }
    CPy_INCREF(cpy_r_r57);
CPyL52: ;
    cpy_r_r58 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cancel' */
    PyObject *cpy_r_r59[1] = {cpy_r_r57};
    cpy_r_r60 = (PyObject **)&cpy_r_r59;
    cpy_r_r61 = PyObject_VectorcallMethod(cpy_r_r58, cpy_r_r60, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL104;
    } else
        goto CPyL105;
CPyL53: ;
    CPy_DecRef(cpy_r_r57);
    cpy_r_r62 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "self", 232, CPyStatic_globals);
        goto CPyL62;
    }
    CPy_INCREF_NO_IMM(cpy_r_r62);
CPyL54: ;
    cpy_r_r63 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r62)->___cache;
    if (unlikely(cpy_r_r63 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__cache' of '_LRUCacheWrapper' undefined");
    } else {
        CPy_INCREF(cpy_r_r63);
    }
    CPy_DecRef(cpy_r_r62);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL62;
    }
CPyL55: ;
    cpy_r_r64 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "key", 232, CPyStatic_globals);
        goto CPyL106;
    }
    CPy_INCREF(cpy_r_r64);
CPyL56: ;
    cpy_r_r65 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'pop' */
    cpy_r_r66 = Py_None;
    PyObject *cpy_r_r67[3] = {cpy_r_r63, cpy_r_r64, cpy_r_r66};
    cpy_r_r68 = (PyObject **)&cpy_r_r67;
    cpy_r_r69 = PyObject_VectorcallMethod(cpy_r_r65, cpy_r_r68, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL107;
    } else
        goto CPyL108;
CPyL57: ;
    CPy_DecRef(cpy_r_r63);
    CPy_DecRef(cpy_r_r64);
CPyL58: ;
    CPy_Reraise();
    if (!0) goto CPyL62;
    CPy_Unreachable();
CPyL60: ;
    CPy_Reraise();
    if (!0) goto CPyL62;
    CPy_Unreachable();
CPyL62: ;
    cpy_r_r70 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7;
    if (unlikely(cpy_r_r70.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__7", -1, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_INCREF(cpy_r_r70.f0);
    CPy_INCREF(cpy_r_r70.f1);
    CPy_INCREF(cpy_r_r70.f2);
CPyL63: ;
    CPy_RestoreExcInfo(cpy_r_r70);
    CPy_DecRef(cpy_r_r70.f0);
    CPy_DecRef(cpy_r_r70.f1);
    CPy_DecRef(cpy_r_r70.f2);
    cpy_r_r71 = CPy_KeepPropagating();
    if (!cpy_r_r71) goto CPyL66;
    CPy_Unreachable();
CPyL65: ;
    tuple_T3OOO __tmp16 = { NULL, NULL, NULL };
    cpy_r_r72 = __tmp16;
    cpy_r_r73 = cpy_r_r72;
    goto CPyL68;
CPyL66: ;
    cpy_r_r74 = NULL;
    if (((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6 != NULL) {
        CPy_DECREF(((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6);
    }
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6 = cpy_r_r74;
    cpy_r_r75 = 1;
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", -1, CPyStatic_globals);
        goto CPyL93;
    }
    cpy_r_r76 = CPy_CatchError();
    cpy_r_r73 = cpy_r_r76;
CPyL68: ;
    cpy_r_r77 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "cache_item", 236, CPyStatic_globals);
        goto CPyL80;
    }
    CPy_INCREF_NO_IMM(cpy_r_r77);
CPyL69: ;
    cpy_r_r78 = ((async_lru____CacheItemObject *)cpy_r_r77)->_waiters;
    if (unlikely(cpy_r_r78 == CPY_INT_TAG)) {
        CPy_AttributeError("async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_CacheItem", "waiters", 236, CPyStatic_globals);
        goto CPyL109;
    }
CPyL70: ;
    cpy_r_r79 = CPyTagged_Subtract(cpy_r_r78, 2);
    if (((async_lru____CacheItemObject *)cpy_r_r77)->_waiters != CPY_INT_TAG) {
        CPyTagged_DECREF(((async_lru____CacheItemObject *)cpy_r_r77)->_waiters);
    }
    ((async_lru____CacheItemObject *)cpy_r_r77)->_waiters = cpy_r_r79;
    cpy_r_r80 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r77);
    if (unlikely(!cpy_r_r80)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL80;
    }
    if (cpy_r_r73.f0 == NULL) goto CPyL74;
    CPy_Reraise();
    if (!0) {
        goto CPyL80;
    } else
        goto CPyL110;
CPyL73: ;
    CPy_Unreachable();
CPyL74: ;
    cpy_r_r81 = ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6;
    if (cpy_r_r81 != NULL) {
        CPy_INCREF(cpy_r_r81);
    }
    if (cpy_r_r81 == NULL) goto CPyL84;
CPyL75: ;
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL79;
    CPyGen_SetStopIterationValue(cpy_r_r81);
    CPy_DECREF(cpy_r_r81);
    if (!0) goto CPyL93;
    CPy_Unreachable();
CPyL79: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r81;
    return 0;
CPyL80: ;
    if (cpy_r_r73.f0 == NULL) goto CPyL82;
    CPy_RestoreExcInfo(cpy_r_r73);
    CPy_XDECREF(cpy_r_r73.f0);
    CPy_XDECREF(cpy_r_r73.f1);
    CPy_XDECREF(cpy_r_r73.f2);
CPyL82: ;
    cpy_r_r83 = CPy_KeepPropagating();
    if (!cpy_r_r83) goto CPyL93;
    CPy_Unreachable();
CPyL84: ;
    cpy_r_r84 = Py_None;
    ((async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL88;
    CPyGen_SetStopIterationValue(cpy_r_r84);
    if (!0) goto CPyL93;
    CPy_Unreachable();
CPyL88: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r84;
    return 0;
CPyL89: ;
    cpy_r_r86 = cpy_r_r2 == 0;
    if (cpy_r_r86) goto CPyL111;
    cpy_r_r87 = cpy_r_r2 == 1;
    if (cpy_r_r87) {
        goto CPyL18;
    } else
        goto CPyL112;
CPyL91: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r88 = 0;
    if (unlikely(!cpy_r_r88)) {
        CPy_AddTraceback("async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL93;
    }
    CPy_Unreachable();
CPyL93: ;
    cpy_r_r89 = NULL;
    return cpy_r_r89;
CPyL94: ;
    CPy_DecRef(cpy_r_r8);
    goto CPyL39;
CPyL95: ;
    CPy_DecRef(cpy_r_r20);
    goto CPyL39;
CPyL96: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL21;
CPyL97: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL20;
CPyL98: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL30;
CPyL99: ;
    CPy_DecRef(cpy_r_r23);
    goto CPyL30;
CPyL100: ;
    CPy_DecRef(cpy_r_r20);
    goto CPyL30;
CPyL101: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL39;
CPyL102: ;
    CPy_DecRef(cpy_r_r46);
    goto CPyL62;
CPyL103: ;
    CPy_DecRef(cpy_r_r49);
    goto CPyL62;
CPyL104: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL62;
CPyL105: ;
    CPy_DecRef(cpy_r_r61);
    goto CPyL53;
CPyL106: ;
    CPy_DecRef(cpy_r_r63);
    goto CPyL62;
CPyL107: ;
    CPy_DecRef(cpy_r_r63);
    CPy_DecRef(cpy_r_r64);
    goto CPyL62;
CPyL108: ;
    CPy_DecRef(cpy_r_r69);
    goto CPyL57;
CPyL109: ;
    CPy_DecRef(cpy_r_r77);
    goto CPyL80;
CPyL110: ;
    CPy_XDECREF(cpy_r_r73.f0);
    CPy_XDECREF(cpy_r_r73.f1);
    CPy_XDECREF(cpy_r_r73.f2);
    goto CPyL73;
CPyL111: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL1;
CPyL112: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL91;
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
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
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
    PyObject *cpy_r_r58;
    PyObject **cpy_r_r60;
    PyObject *cpy_r_r61;
    char cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    CPyTagged cpy_r_r65;
    CPyTagged cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    char cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject **cpy_r_r77;
    PyObject *cpy_r_r78;
    char cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    char cpy_r_r84;
    PyObject *cpy_r_r85;
    char cpy_r_r86;
    tuple_T3OOO cpy_r_r87;
    char cpy_r_r88;
    PyObject **cpy_r_r89;
    PyObject *cpy_r_r90;
    char cpy_r_r91;
    tuple_T3OOO cpy_r_r92;
    tuple_T3OOO cpy_r_r93;
    tuple_T3OOO cpy_r_r94;
    char cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    char cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject **cpy_r_r105;
    PyObject *cpy_r_r106;
    char cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    char cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject **cpy_r_r120;
    PyObject *cpy_r_r121;
    char cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject **cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject **cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    char cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    int32_t cpy_r_r150;
    char cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    char cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    int64_t cpy_r_r158;
    CPyTagged cpy_r_r159;
    PyObject *cpy_r_r160;
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
    PyObject *cpy_r_r173;
    PyObject **cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    tuple_T2OO cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    char cpy_r_r182;
    PyObject *cpy_r_r183;
    char cpy_r_r184;
    PyObject *cpy_r_r185;
    char cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    char cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    char cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject **cpy_r_r199;
    PyObject *cpy_r_r200;
    char cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    char cpy_r_r204;
    PyObject *cpy_r_r205;
    char cpy_r_r206;
    PyObject *cpy_r_r207;
    char cpy_r_r208;
    tuple_T3OOO cpy_r_r209;
    char cpy_r_r210;
    PyObject **cpy_r_r211;
    PyObject *cpy_r_r212;
    char cpy_r_r213;
    tuple_T3OOO cpy_r_r214;
    tuple_T3OOO cpy_r_r215;
    tuple_T3OOO cpy_r_r216;
    char cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject *cpy_r_r220;
    char cpy_r_r221;
    char cpy_r_r222;
    char cpy_r_r223;
    char cpy_r_r224;
    char cpy_r_r225;
    PyObject *cpy_r_r226;
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
    goto CPyL184;
CPyL1: ;
    cpy_r_r9 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r10 = cpy_r_type != cpy_r_r9;
    if (!cpy_r_r10) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r11 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 239, CPyStatic_globals);
        goto CPyL189;
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
        goto CPyL189;
    }
CPyL6: ;
    if (!cpy_r_r12) goto CPyL14;
CPyL7: ;
    cpy_r_r13 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'alru_cache is closed for ' */
    cpy_r_r14 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 240, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r14);
CPyL8: ;
    cpy_r_r15 = PyObject_Str(cpy_r_r14);
    CPy_DECREF_NO_IMM(cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r16 = CPyStr_Build(2, cpy_r_r13, cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'RuntimeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL190;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL190;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_Unreachable();
CPyL14: ;
    cpy_r_r23 = CPyModule_asyncio;
    cpy_r_r24 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'get_running_loop' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r26 = PyObject_Vectorcall(cpy_r_r25, 0, 0, 0);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop = cpy_r_r26;
    cpy_r_r27 = 1;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r28 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 243, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r28);
CPyL18: ;
    cpy_r_r29 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop;
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "loop", 243, CPyStatic_globals);
        goto CPyL191;
    }
    CPy_INCREF(cpy_r_r29);
CPyL19: ;
    cpy_r_r30 = CPyDef__LRUCacheWrapper____check_loop(cpy_r_r28, cpy_r_r29);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF_NO_IMM(cpy_r_r28);
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r31 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_args;
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "fn_args", 245, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF(cpy_r_r31);
CPyL21: ;
    cpy_r_r32 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_kwargs;
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "fn_kwargs", 245, CPyStatic_globals);
        goto CPyL192;
    }
    CPy_INCREF(cpy_r_r32);
CPyL22: ;
    cpy_r_r33 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 245, CPyStatic_globals);
        goto CPyL193;
    }
    CPy_INCREF_NO_IMM(cpy_r_r33);
CPyL23: ;
    cpy_r_r34 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r33)->___typed;
    if (unlikely(cpy_r_r34 == 2)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__typed' of '_LRUCacheWrapper' undefined");
    }
    CPy_DECREF_NO_IMM(cpy_r_r33);
    if (unlikely(cpy_r_r34 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL193;
    }
CPyL24: ;
    cpy_r_r35 = CPyStatic_globals;
    cpy_r_r36 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_make_key' */
    cpy_r_r37 = CPyDict_GetItem(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL193;
    }
    cpy_r_r38 = cpy_r_r34 ? Py_True : Py_False;
    PyObject *cpy_r_r39[3] = {cpy_r_r31, cpy_r_r32, cpy_r_r38};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = PyObject_Vectorcall(cpy_r_r37, cpy_r_r40, 3, 0);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL193;
    }
    CPy_DECREF(cpy_r_r31);
    CPy_DECREF(cpy_r_r32);
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key = cpy_r_r41;
    cpy_r_r42 = 1;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r43 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 247, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r43);
CPyL28: ;
    cpy_r_r44 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r43)->___cache;
    if (unlikely(cpy_r_r44 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__cache' of '_LRUCacheWrapper' undefined");
    } else {
        CPy_INCREF(cpy_r_r44);
    }
    CPy_DECREF_NO_IMM(cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
CPyL29: ;
    cpy_r_r45 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 247, CPyStatic_globals);
        goto CPyL194;
    }
    CPy_INCREF(cpy_r_r45);
CPyL30: ;
    cpy_r_r46 = CPyDict_GetWithNone(cpy_r_r44, cpy_r_r45);
    CPy_DECREF(cpy_r_r44);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
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
    CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 247, CPyStatic_globals, "async_lru._CacheItem or None", cpy_r_r46);
    goto CPyL189;
__LL19: ;
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item = cpy_r_r47;
    cpy_r_r48 = 1;
    if (unlikely(!cpy_r_r48)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r49 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 249, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF(cpy_r_r49);
CPyL34: ;
    cpy_r_r50 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r51 = cpy_r_r49 != cpy_r_r50;
    CPy_DECREF(cpy_r_r49);
    if (!cpy_r_r51) goto CPyL94;
    cpy_r_r52 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 250, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r52);
CPyL36: ;
    cpy_r_r53 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 250, CPyStatic_globals);
        goto CPyL195;
    }
    CPy_INCREF(cpy_r_r53);
CPyL37: ;
    cpy_r_r54 = CPyDef__LRUCacheWrapper____cache_hit(cpy_r_r52, cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    CPy_DECREF_NO_IMM(cpy_r_r52);
    if (unlikely(cpy_r_r54 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r55 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 251, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF(cpy_r_r55);
CPyL39: ;
    if (likely(cpy_r_r55 != Py_None))
        cpy_r_r56 = cpy_r_r55;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 251, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r55);
        goto CPyL196;
    }
    cpy_r_r57 = ((async_lru____CacheItemObject *)cpy_r_r56)->_task;
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "_CacheItem", "task", 251, CPyStatic_globals);
        goto CPyL196;
    }
    CPy_INCREF(cpy_r_r57);
CPyL41: ;
    CPy_DECREF(cpy_r_r55);
    cpy_r_r58 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'done' */
    PyObject *cpy_r_r59[1] = {cpy_r_r57};
    cpy_r_r60 = (PyObject **)&cpy_r_r59;
    cpy_r_r61 = PyObject_VectorcallMethod(cpy_r_r58, cpy_r_r60, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_DECREF(cpy_r_r57);
    if (unlikely(!PyBool_Check(cpy_r_r61))) {
        CPy_TypeError("bool", cpy_r_r61); cpy_r_r62 = 2;
    } else
        cpy_r_r62 = cpy_r_r61 == Py_True;
    CPy_DECREF(cpy_r_r61);
    if (unlikely(cpy_r_r62 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    if (cpy_r_r62) goto CPyL85;
    cpy_r_r63 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 253, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF(cpy_r_r63);
CPyL45: ;
    if (likely(cpy_r_r63 != Py_None))
        cpy_r_r64 = cpy_r_r63;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 253, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r63);
        goto CPyL198;
    }
    cpy_r_r65 = ((async_lru____CacheItemObject *)cpy_r_r64)->_waiters;
    if (unlikely(cpy_r_r65 == CPY_INT_TAG)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "_CacheItem", "waiters", 253, CPyStatic_globals);
        goto CPyL198;
    }
CPyL47: ;
    cpy_r_r66 = CPyTagged_Add(cpy_r_r65, 2);
    if (((async_lru____CacheItemObject *)cpy_r_r64)->_waiters != CPY_INT_TAG) {
        CPyTagged_DECREF(((async_lru____CacheItemObject *)cpy_r_r64)->_waiters);
    }
    ((async_lru____CacheItemObject *)cpy_r_r64)->_waiters = cpy_r_r66;
    cpy_r_r67 = 1;
    if (unlikely(!cpy_r_r67)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL198;
    }
    CPy_DECREF(cpy_r_r63);
    cpy_r_r68 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 254, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r68);
CPyL49: ;
    cpy_r_r69 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 254, CPyStatic_globals);
        goto CPyL199;
    }
    CPy_INCREF(cpy_r_r69);
CPyL50: ;
    if (likely(cpy_r_r69 != Py_None))
        cpy_r_r70 = cpy_r_r69;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 254, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r69);
        goto CPyL199;
    }
    cpy_r_r71 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 254, CPyStatic_globals);
        goto CPyL200;
    }
    CPy_INCREF(cpy_r_r71);
CPyL52: ;
    cpy_r_r72 = CPyDef__LRUCacheWrapper____shield_and_handle_cancelled_error(cpy_r_r68, cpy_r_r70, cpy_r_r71);
    CPy_DECREF_NO_IMM(cpy_r_r70);
    CPy_DECREF(cpy_r_r71);
    CPy_DECREF_NO_IMM(cpy_r_r68);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8 != NULL) {
        CPy_DECREF_NO_IMM(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8 = cpy_r_r72;
    cpy_r_r73 = 1;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r74 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8;
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r74);
CPyL55: ;
    cpy_r_r75 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r76 = NULL;
    cpy_r_r1 = cpy_r_r76;
    cpy_r_r77 = (PyObject **)&cpy_r_r1;
    cpy_r_r78 = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r_r74, cpy_r_r75, cpy_r_r75, cpy_r_r75, cpy_r_r75, cpy_r_r77);
    CPy_DECREF_NO_IMM(cpy_r_r74);
    if (cpy_r_r78 != NULL) goto CPyL201;
    cpy_r_r79 = cpy_r_r1 != 0;
    if (unlikely(!cpy_r_r79)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL202;
    }
    cpy_r_r80 = cpy_r_r1;
    cpy_r_r81 = NULL;
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8 != NULL) {
        CPy_DECREF_NO_IMM(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8 = cpy_r_r81;
    cpy_r_r82 = 1;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL203;
    } else
        goto CPyL80;
CPyL58: ;
    cpy_r_r83 = cpy_r_r78;
CPyL59: ;
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 1;
    return cpy_r_r83;
CPyL60: ;
    cpy_r_r85 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r86 = cpy_r_type != cpy_r_r85;
    if (!cpy_r_r86) goto CPyL204;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL64;
    } else
        goto CPyL205;
CPyL62: ;
    CPy_Unreachable();
CPyL63: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL75;
CPyL64: ;
    cpy_r_r87 = CPy_CatchError();
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9.f0 != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9.f0);
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9.f1);
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9.f2);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9 = cpy_r_r87;
    cpy_r_r88 = 1;
    if (unlikely(!cpy_r_r88)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL206;
    }
    cpy_r_r89 = (PyObject **)&cpy_r_r3;
    cpy_r_r90 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8;
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL206;
    }
    CPy_INCREF_NO_IMM(cpy_r_r90);
CPyL66: ;
    cpy_r_r91 = CPy_YieldFromErrorHandle(cpy_r_r90, cpy_r_r89);
    CPy_DecRef(cpy_r_r90);
    if (unlikely(cpy_r_r91 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL206;
    }
    if (cpy_r_r91) goto CPyL70;
    cpy_r_r83 = cpy_r_r3;
    cpy_r_r92 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9;
    if (unlikely(cpy_r_r92.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL207;
    }
    CPy_INCREF(cpy_r_r92.f0);
    CPy_INCREF(cpy_r_r92.f1);
    CPy_INCREF(cpy_r_r92.f2);
CPyL69: ;
    CPy_RestoreExcInfo(cpy_r_r92);
    CPy_DecRef(cpy_r_r92.f0);
    CPy_DecRef(cpy_r_r92.f1);
    CPy_DecRef(cpy_r_r92.f2);
    goto CPyL59;
CPyL70: ;
    cpy_r_r80 = cpy_r_r3;
    cpy_r_r93 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9;
    if (unlikely(cpy_r_r93.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL208;
    }
    CPy_INCREF(cpy_r_r93.f0);
    CPy_INCREF(cpy_r_r93.f1);
    CPy_INCREF(cpy_r_r93.f2);
CPyL71: ;
    CPy_RestoreExcInfo(cpy_r_r93);
    CPy_DecRef(cpy_r_r93.f0);
    CPy_DecRef(cpy_r_r93.f1);
    CPy_DecRef(cpy_r_r93.f2);
    goto CPyL80;
CPyL72: ;
    cpy_r_r94 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9;
    if (unlikely(cpy_r_r94.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF(cpy_r_r94.f0);
    CPy_INCREF(cpy_r_r94.f1);
    CPy_INCREF(cpy_r_r94.f2);
CPyL73: ;
    CPy_RestoreExcInfo(cpy_r_r94);
    CPy_DecRef(cpy_r_r94.f0);
    CPy_DecRef(cpy_r_r94.f1);
    CPy_DecRef(cpy_r_r94.f2);
    cpy_r_r95 = CPy_KeepPropagating();
    if (!cpy_r_r95) goto CPyL189;
    CPy_Unreachable();
CPyL75: ;
    cpy_r_r96 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8;
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL209;
    }
    CPy_INCREF_NO_IMM(cpy_r_r96);
CPyL76: ;
    cpy_r_r97 = CPyIter_Send(cpy_r_r96, cpy_r_arg);
    CPy_DECREF_NO_IMM(cpy_r_r96);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r97 == NULL) goto CPyL78;
    cpy_r_r83 = cpy_r_r97;
    goto CPyL59;
CPyL78: ;
    cpy_r_r98 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r80 = cpy_r_r98;
CPyL80: ;
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL84;
    CPyGen_SetStopIterationValue(cpy_r_r80);
    CPy_DECREF(cpy_r_r80);
    if (!0) goto CPyL189;
    CPy_Unreachable();
CPyL84: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r80;
    return 0;
CPyL85: ;
    cpy_r_r100 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 257, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF(cpy_r_r100);
CPyL86: ;
    if (likely(cpy_r_r100 != Py_None))
        cpy_r_r101 = cpy_r_r100;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 257, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r100);
        goto CPyL210;
    }
    cpy_r_r102 = ((async_lru____CacheItemObject *)cpy_r_r101)->_task;
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "_CacheItem", "task", 257, CPyStatic_globals);
        goto CPyL210;
    }
    CPy_INCREF(cpy_r_r102);
CPyL88: ;
    CPy_DECREF(cpy_r_r100);
    cpy_r_r103 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'result' */
    PyObject *cpy_r_r104[1] = {cpy_r_r102};
    cpy_r_r105 = (PyObject **)&cpy_r_r104;
    cpy_r_r106 = PyObject_VectorcallMethod(cpy_r_r103, cpy_r_r105, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL211;
    }
    CPy_DECREF(cpy_r_r102);
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL93;
    CPyGen_SetStopIterationValue(cpy_r_r106);
    CPy_DECREF(cpy_r_r106);
    if (!0) goto CPyL189;
    CPy_Unreachable();
CPyL93: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r106;
    return 0;
CPyL94: ;
    cpy_r_r108 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 259, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r108);
CPyL95: ;
    cpy_r_r109 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_args;
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "fn_args", 259, CPyStatic_globals);
        goto CPyL212;
    }
    CPy_INCREF(cpy_r_r109);
CPyL96: ;
    cpy_r_r110 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_kwargs;
    if (unlikely(cpy_r_r110 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "fn_kwargs", 259, CPyStatic_globals);
        goto CPyL213;
    }
    CPy_INCREF(cpy_r_r110);
CPyL97: ;
    cpy_r_r111 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapped__' */
    cpy_r_r112 = CPyObject_GetAttr(cpy_r_r108, cpy_r_r111);
    CPy_DECREF_NO_IMM(cpy_r_r108);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL214;
    }
    cpy_r_r113 = PyDict_Copy(cpy_r_r110);
    CPy_DECREF(cpy_r_r110);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL215;
    }
    cpy_r_r114 = PyObject_Call(cpy_r_r112, cpy_r_r109, cpy_r_r113);
    CPy_DECREF(cpy_r_r112);
    CPy_DECREF(cpy_r_r109);
    CPy_DECREF(cpy_r_r113);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__coro != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__coro);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__coro = cpy_r_r114;
    cpy_r_r115 = 1;
    if (unlikely(!cpy_r_r115)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r116 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop;
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "loop", 260, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF(cpy_r_r116);
CPyL102: ;
    cpy_r_r117 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__coro;
    if (unlikely(cpy_r_r117 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "coro", 260, CPyStatic_globals);
        goto CPyL216;
    }
    CPy_INCREF(cpy_r_r117);
CPyL103: ;
    cpy_r_r118 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'create_task' */
    PyObject *cpy_r_r119[2] = {cpy_r_r116, cpy_r_r117};
    cpy_r_r120 = (PyObject **)&cpy_r_r119;
    cpy_r_r121 = PyObject_VectorcallMethod(cpy_r_r118, cpy_r_r120, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r121 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL217;
    }
    CPy_DECREF(cpy_r_r116);
    CPy_DECREF(cpy_r_r117);
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task = cpy_r_r121;
    cpy_r_r122 = 1;
    if (unlikely(!cpy_r_r122)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r123 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "task", 261, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF(cpy_r_r123);
CPyL106: ;
    cpy_r_r124 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r124 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 261, CPyStatic_globals);
        goto CPyL218;
    }
    CPy_INCREF_NO_IMM(cpy_r_r124);
CPyL107: ;
    cpy_r_r125 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_task_done_callback' */
    cpy_r_r126 = CPyObject_GetAttr(cpy_r_r124, cpy_r_r125);
    CPy_DECREF_NO_IMM(cpy_r_r124);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL218;
    }
    cpy_r_r127 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 261, CPyStatic_globals);
        goto CPyL219;
    }
    CPy_INCREF(cpy_r_r127);
CPyL109: ;
    cpy_r_r128 = CPyStatic_globals;
    cpy_r_r129 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partial' */
    cpy_r_r130 = CPyDict_GetItem(cpy_r_r128, cpy_r_r129);
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL220;
    }
    PyObject *cpy_r_r131[2] = {cpy_r_r126, cpy_r_r127};
    cpy_r_r132 = (PyObject **)&cpy_r_r131;
    cpy_r_r133 = PyObject_Vectorcall(cpy_r_r130, cpy_r_r132, 2, 0);
    CPy_DECREF(cpy_r_r130);
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL220;
    }
    CPy_DECREF(cpy_r_r126);
    CPy_DECREF(cpy_r_r127);
    cpy_r_r134 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'add_done_callback' */
    PyObject *cpy_r_r135[2] = {cpy_r_r123, cpy_r_r133};
    cpy_r_r136 = (PyObject **)&cpy_r_r135;
    cpy_r_r137 = PyObject_VectorcallMethod(cpy_r_r134, cpy_r_r136, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL221;
    } else
        goto CPyL222;
CPyL112: ;
    CPy_DECREF(cpy_r_r123);
    CPy_DECREF(cpy_r_r133);
    cpy_r_r138 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "task", 263, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF(cpy_r_r138);
CPyL113: ;
    cpy_r_r139 = Py_None;
    cpy_r_r140 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 1 */
    cpy_r_r141 = PyTuple_Pack(3, cpy_r_r138, cpy_r_r139, cpy_r_r140);
    CPy_DECREF(cpy_r_r138);
    if (unlikely(cpy_r_r141 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r142 = PyDict_New();
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL223;
    }
    cpy_r_r143 = CPyDef__CacheItem(cpy_r_r141, cpy_r_r142);
    CPy_DECREF(cpy_r_r141);
    CPy_DECREF(cpy_r_r142);
    if (unlikely(cpy_r_r143 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item = cpy_r_r143;
    cpy_r_r144 = 1;
    if (unlikely(!cpy_r_r144)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r145 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r145 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 264, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF(cpy_r_r145);
CPyL118: ;
    if (likely(cpy_r_r145 != Py_None))
        cpy_r_r146 = cpy_r_r145;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 264, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r145);
        goto CPyL189;
    }
    cpy_r_r147 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r147 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 264, CPyStatic_globals);
        goto CPyL224;
    }
    CPy_INCREF_NO_IMM(cpy_r_r147);
CPyL120: ;
    cpy_r_r148 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r147)->___cache;
    if (unlikely(cpy_r_r148 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__cache' of '_LRUCacheWrapper' undefined");
    } else {
        CPy_INCREF(cpy_r_r148);
    }
    CPy_DECREF_NO_IMM(cpy_r_r147);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL224;
    }
CPyL121: ;
    cpy_r_r149 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r149 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 264, CPyStatic_globals);
        goto CPyL225;
    }
    CPy_INCREF(cpy_r_r149);
CPyL122: ;
    cpy_r_r150 = CPyDict_SetItem(cpy_r_r148, cpy_r_r149, cpy_r_r146);
    CPy_DECREF(cpy_r_r148);
    CPy_DECREF(cpy_r_r149);
    CPy_DECREF_NO_IMM(cpy_r_r146);
    cpy_r_r151 = cpy_r_r150 >= 0;
    if (unlikely(!cpy_r_r151)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r152 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 266, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r152);
CPyL124: ;
    cpy_r_r153 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r152)->___maxsize;
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "_LRUCacheWrapper", "__maxsize", 266, CPyStatic_globals);
        goto CPyL226;
    }
CPyL125: ;
    cpy_r_r154 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r155 = cpy_r_r153 != cpy_r_r154;
    CPy_DECREF_NO_IMM(cpy_r_r152);
    if (!cpy_r_r155) goto CPyL144;
    cpy_r_r156 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r156 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 266, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r156);
CPyL127: ;
    cpy_r_r157 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r156)->___cache;
    if (unlikely(cpy_r_r157 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__cache' of '_LRUCacheWrapper' undefined");
    } else {
        CPy_INCREF(cpy_r_r157);
    }
    CPy_DECREF_NO_IMM(cpy_r_r156);
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
CPyL128: ;
    cpy_r_r158 = PyDict_Size(cpy_r_r157);
    CPy_DECREF(cpy_r_r157);
    cpy_r_r159 = cpy_r_r158 << 1;
    cpy_r_r160 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r160 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 266, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r160);
CPyL129: ;
    cpy_r_r161 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r160)->___maxsize;
    if (unlikely(cpy_r_r161 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "_LRUCacheWrapper", "__maxsize", 266, CPyStatic_globals);
        goto CPyL227;
    }
CPyL130: ;
    if (likely(PyLong_Check(cpy_r_r161)))
        cpy_r_r162 = CPyTagged_FromObject(cpy_r_r161);
    else {
        CPy_TypeError("int", cpy_r_r161); cpy_r_r162 = CPY_INT_TAG;
    }
    if (unlikely(cpy_r_r162 == CPY_INT_TAG)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL227;
    }
    cpy_r_r163 = cpy_r_r159 & 1;
    cpy_r_r164 = cpy_r_r163 != 0;
    if (cpy_r_r164) goto CPyL133;
    cpy_r_r165 = cpy_r_r162 & 1;
    cpy_r_r166 = cpy_r_r165 != 0;
    if (!cpy_r_r166) goto CPyL134;
CPyL133: ;
    cpy_r_r167 = CPyTagged_IsLt_(cpy_r_r162, cpy_r_r159);
    cpy_r_r168 = cpy_r_r167;
    goto CPyL135;
CPyL134: ;
    cpy_r_r169 = (Py_ssize_t)cpy_r_r159 > (Py_ssize_t)cpy_r_r162;
    cpy_r_r168 = cpy_r_r169;
CPyL135: ;
    CPyTagged_DECREF(cpy_r_r162);
    CPy_DECREF_NO_IMM(cpy_r_r160);
    if (!cpy_r_r168) goto CPyL144;
    cpy_r_r170 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r170 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 267, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r170);
CPyL137: ;
    cpy_r_r171 = ((async_lru____LRUCacheWrapperObject *)cpy_r_r170)->___cache;
    if (unlikely(cpy_r_r171 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__cache' of '_LRUCacheWrapper' undefined");
    } else {
        CPy_INCREF(cpy_r_r171);
    }
    CPy_DECREF_NO_IMM(cpy_r_r170);
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
CPyL138: ;
    cpy_r_r172 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'popitem' */
    cpy_r_r173 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r174[2] = {cpy_r_r171, cpy_r_r173};
    cpy_r_r175 = (PyObject **)&cpy_r_r174;
    cpy_r_r176 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('last',) */
    cpy_r_r177 = PyObject_VectorcallMethod(cpy_r_r172, cpy_r_r175, 9223372036854775809ULL, cpy_r_r176);
    if (unlikely(cpy_r_r177 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL228;
    }
    CPy_DECREF(cpy_r_r171);
    PyObject *__tmp20;
    if (unlikely(!(PyTuple_Check(cpy_r_r177) && PyTuple_GET_SIZE(cpy_r_r177) == 2))) {
        __tmp20 = NULL;
        goto __LL21;
    }
    __tmp20 = PyTuple_GET_ITEM(cpy_r_r177, 0);
    if (__tmp20 == NULL) goto __LL21;
    if (likely(Py_TYPE(PyTuple_GET_ITEM(cpy_r_r177, 1)) == CPyType__CacheItem))
        __tmp20 = PyTuple_GET_ITEM(cpy_r_r177, 1);
    else {
        __tmp20 = NULL;
    }
    if (__tmp20 == NULL) goto __LL21;
    __tmp20 = cpy_r_r177;
__LL21: ;
    if (unlikely(__tmp20 == NULL)) {
        CPy_TypeError("tuple[object, async_lru._CacheItem]", cpy_r_r177); cpy_r_r178 = (tuple_T2OO) { NULL, NULL };
    } else {
        PyObject *__tmp22 = PyTuple_GET_ITEM(cpy_r_r177, 0);
        CPy_INCREF(__tmp22);
        PyObject *__tmp23;
        __tmp23 = __tmp22;
        cpy_r_r178.f0 = __tmp23;
        PyObject *__tmp24 = PyTuple_GET_ITEM(cpy_r_r177, 1);
        CPy_INCREF(__tmp24);
        PyObject *__tmp25;
        if (likely(Py_TYPE(__tmp24) == CPyType__CacheItem))
            __tmp25 = __tmp24;
        else {
            CPy_TypeError("async_lru._CacheItem", __tmp24); 
            __tmp25 = NULL;
        }
        cpy_r_r178.f1 = __tmp25;
    }
    CPy_DECREF(cpy_r_r177);
    if (unlikely(cpy_r_r178.f0 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r179 = cpy_r_r178.f0;
    cpy_r_r180 = cpy_r_r178.f1;
    cpy_r_r181 = cpy_r_r179;
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_key != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_key);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_key = cpy_r_r181;
    cpy_r_r182 = 1;
    if (unlikely(!cpy_r_r182)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r183 = cpy_r_r180;
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_cache_item != NULL) {
        CPy_DECREF_NO_IMM(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_cache_item);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_cache_item = cpy_r_r183;
    cpy_r_r184 = 1;
    if (unlikely(!cpy_r_r184)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r185 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_cache_item;
    if (unlikely(cpy_r_r185 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "dropped_cache_item", 268, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r185);
CPyL143: ;
    cpy_r_r186 = CPyDef__CacheItem___cancel(cpy_r_r185);
    CPy_DECREF_NO_IMM(cpy_r_r185);
    if (unlikely(cpy_r_r186 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
CPyL144: ;
    cpy_r_r187 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r187 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 270, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r187);
CPyL145: ;
    cpy_r_r188 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r188 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 270, CPyStatic_globals);
        goto CPyL229;
    }
    CPy_INCREF(cpy_r_r188);
CPyL146: ;
    cpy_r_r189 = CPyDef__LRUCacheWrapper____cache_miss(cpy_r_r187, cpy_r_r188);
    CPy_DECREF(cpy_r_r188);
    CPy_DECREF_NO_IMM(cpy_r_r187);
    if (unlikely(cpy_r_r189 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r190 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r190 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 272, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r190);
CPyL148: ;
    cpy_r_r191 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r191 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 272, CPyStatic_globals);
        goto CPyL230;
    }
    CPy_INCREF(cpy_r_r191);
CPyL149: ;
    if (likely(cpy_r_r191 != Py_None))
        cpy_r_r192 = cpy_r_r191;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__call__", 272, CPyStatic_globals, "async_lru._CacheItem", cpy_r_r191);
        goto CPyL230;
    }
    cpy_r_r193 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 272, CPyStatic_globals);
        goto CPyL231;
    }
    CPy_INCREF(cpy_r_r193);
CPyL151: ;
    cpy_r_r194 = CPyDef__LRUCacheWrapper____shield_and_handle_cancelled_error(cpy_r_r190, cpy_r_r192, cpy_r_r193);
    CPy_DECREF_NO_IMM(cpy_r_r192);
    CPy_DECREF(cpy_r_r193);
    CPy_DECREF_NO_IMM(cpy_r_r190);
    if (unlikely(cpy_r_r194 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10 != NULL) {
        CPy_DECREF_NO_IMM(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10 = cpy_r_r194;
    cpy_r_r195 = 1;
    if (unlikely(!cpy_r_r195)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r196 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10;
    if (unlikely(cpy_r_r196 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF_NO_IMM(cpy_r_r196);
CPyL154: ;
    cpy_r_r197 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r198 = NULL;
    cpy_r_r5 = cpy_r_r198;
    cpy_r_r199 = (PyObject **)&cpy_r_r5;
    cpy_r_r200 = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r_r196, cpy_r_r197, cpy_r_r197, cpy_r_r197, cpy_r_r197, cpy_r_r199);
    CPy_DECREF_NO_IMM(cpy_r_r196);
    if (cpy_r_r200 != NULL) goto CPyL232;
    cpy_r_r201 = cpy_r_r5 != 0;
    if (unlikely(!cpy_r_r201)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL233;
    }
    cpy_r_r202 = cpy_r_r5;
    cpy_r_r203 = NULL;
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10 != NULL) {
        CPy_DECREF_NO_IMM(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10 = cpy_r_r203;
    cpy_r_r204 = 1;
    if (unlikely(!cpy_r_r204)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL234;
    } else
        goto CPyL179;
CPyL157: ;
    cpy_r_r205 = cpy_r_r200;
CPyL158: ;
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 2;
    return cpy_r_r205;
CPyL159: ;
    cpy_r_r207 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r208 = cpy_r_type != cpy_r_r207;
    if (!cpy_r_r208) goto CPyL235;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL163;
    } else
        goto CPyL236;
CPyL161: ;
    CPy_Unreachable();
CPyL162: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL174;
CPyL163: ;
    cpy_r_r209 = CPy_CatchError();
    if (((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11.f0 != NULL) {
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11.f0);
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11.f1);
        CPy_DECREF(((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11.f2);
    }
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11 = cpy_r_r209;
    cpy_r_r210 = 1;
    if (unlikely(!cpy_r_r210)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL237;
    }
    cpy_r_r211 = (PyObject **)&cpy_r_r7;
    cpy_r_r212 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10;
    if (unlikely(cpy_r_r212 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL237;
    }
    CPy_INCREF_NO_IMM(cpy_r_r212);
CPyL165: ;
    cpy_r_r213 = CPy_YieldFromErrorHandle(cpy_r_r212, cpy_r_r211);
    CPy_DecRef(cpy_r_r212);
    if (unlikely(cpy_r_r213 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL237;
    }
    if (cpy_r_r213) goto CPyL169;
    cpy_r_r205 = cpy_r_r7;
    cpy_r_r214 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11;
    if (unlikely(cpy_r_r214.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL238;
    }
    CPy_INCREF(cpy_r_r214.f0);
    CPy_INCREF(cpy_r_r214.f1);
    CPy_INCREF(cpy_r_r214.f2);
CPyL168: ;
    CPy_RestoreExcInfo(cpy_r_r214);
    CPy_DecRef(cpy_r_r214.f0);
    CPy_DecRef(cpy_r_r214.f1);
    CPy_DecRef(cpy_r_r214.f2);
    goto CPyL158;
CPyL169: ;
    cpy_r_r202 = cpy_r_r7;
    cpy_r_r215 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11;
    if (unlikely(cpy_r_r215.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL239;
    }
    CPy_INCREF(cpy_r_r215.f0);
    CPy_INCREF(cpy_r_r215.f1);
    CPy_INCREF(cpy_r_r215.f2);
CPyL170: ;
    CPy_RestoreExcInfo(cpy_r_r215);
    CPy_DecRef(cpy_r_r215.f0);
    CPy_DecRef(cpy_r_r215.f1);
    CPy_DecRef(cpy_r_r215.f2);
    goto CPyL179;
CPyL171: ;
    cpy_r_r216 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11;
    if (unlikely(cpy_r_r216.f0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_INCREF(cpy_r_r216.f0);
    CPy_INCREF(cpy_r_r216.f1);
    CPy_INCREF(cpy_r_r216.f2);
CPyL172: ;
    CPy_RestoreExcInfo(cpy_r_r216);
    CPy_DecRef(cpy_r_r216.f0);
    CPy_DecRef(cpy_r_r216.f1);
    CPy_DecRef(cpy_r_r216.f2);
    cpy_r_r217 = CPy_KeepPropagating();
    if (!cpy_r_r217) goto CPyL189;
    CPy_Unreachable();
CPyL174: ;
    cpy_r_r218 = ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10;
    if (unlikely(cpy_r_r218 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL240;
    }
    CPy_INCREF_NO_IMM(cpy_r_r218);
CPyL175: ;
    cpy_r_r219 = CPyIter_Send(cpy_r_r218, cpy_r_arg);
    CPy_DECREF_NO_IMM(cpy_r_r218);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r219 == NULL) goto CPyL177;
    cpy_r_r205 = cpy_r_r219;
    goto CPyL158;
CPyL177: ;
    cpy_r_r220 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r220 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r202 = cpy_r_r220;
CPyL179: ;
    ((async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL183;
    CPyGen_SetStopIterationValue(cpy_r_r202);
    CPy_DECREF(cpy_r_r202);
    if (!0) goto CPyL189;
    CPy_Unreachable();
CPyL183: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r202;
    return 0;
CPyL184: ;
    cpy_r_r222 = cpy_r_r8 == 0;
    if (cpy_r_r222) goto CPyL241;
    cpy_r_r223 = cpy_r_r8 == 1;
    if (cpy_r_r223) {
        goto CPyL242;
    } else
        goto CPyL243;
CPyL186: ;
    cpy_r_r224 = cpy_r_r8 == 2;
    if (cpy_r_r224) {
        goto CPyL159;
    } else
        goto CPyL244;
CPyL187: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r225 = 0;
    if (unlikely(!cpy_r_r225)) {
        CPy_AddTraceback("async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_Unreachable();
CPyL189: ;
    cpy_r_r226 = NULL;
    return cpy_r_r226;
CPyL190: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL189;
CPyL191: ;
    CPy_DecRef(cpy_r_r28);
    goto CPyL189;
CPyL192: ;
    CPy_DecRef(cpy_r_r31);
    goto CPyL189;
CPyL193: ;
    CPy_DecRef(cpy_r_r31);
    CPy_DecRef(cpy_r_r32);
    goto CPyL189;
CPyL194: ;
    CPy_DecRef(cpy_r_r44);
    goto CPyL189;
CPyL195: ;
    CPy_DecRef(cpy_r_r52);
    goto CPyL189;
CPyL196: ;
    CPy_DecRef(cpy_r_r55);
    goto CPyL189;
CPyL197: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL189;
CPyL198: ;
    CPy_DecRef(cpy_r_r63);
    goto CPyL189;
CPyL199: ;
    CPy_DecRef(cpy_r_r68);
    goto CPyL189;
CPyL200: ;
    CPy_DecRef(cpy_r_r68);
    CPy_DecRef(cpy_r_r70);
    goto CPyL189;
CPyL201: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL58;
CPyL202: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL189;
CPyL203: ;
    CPy_DecRef(cpy_r_r80);
    goto CPyL189;
CPyL204: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL63;
CPyL205: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL62;
CPyL206: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL72;
CPyL207: ;
    CPy_DecRef(cpy_r_r83);
    goto CPyL72;
CPyL208: ;
    CPy_DecRef(cpy_r_r80);
    goto CPyL72;
CPyL209: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL189;
CPyL210: ;
    CPy_DecRef(cpy_r_r100);
    goto CPyL189;
CPyL211: ;
    CPy_DecRef(cpy_r_r102);
    goto CPyL189;
CPyL212: ;
    CPy_DecRef(cpy_r_r108);
    goto CPyL189;
CPyL213: ;
    CPy_DecRef(cpy_r_r108);
    CPy_DecRef(cpy_r_r109);
    goto CPyL189;
CPyL214: ;
    CPy_DecRef(cpy_r_r109);
    CPy_DecRef(cpy_r_r110);
    goto CPyL189;
CPyL215: ;
    CPy_DecRef(cpy_r_r109);
    CPy_DecRef(cpy_r_r112);
    goto CPyL189;
CPyL216: ;
    CPy_DecRef(cpy_r_r116);
    goto CPyL189;
CPyL217: ;
    CPy_DecRef(cpy_r_r116);
    CPy_DecRef(cpy_r_r117);
    goto CPyL189;
CPyL218: ;
    CPy_DecRef(cpy_r_r123);
    goto CPyL189;
CPyL219: ;
    CPy_DecRef(cpy_r_r123);
    CPy_DecRef(cpy_r_r126);
    goto CPyL189;
CPyL220: ;
    CPy_DecRef(cpy_r_r123);
    CPy_DecRef(cpy_r_r126);
    CPy_DecRef(cpy_r_r127);
    goto CPyL189;
CPyL221: ;
    CPy_DecRef(cpy_r_r123);
    CPy_DecRef(cpy_r_r133);
    goto CPyL189;
CPyL222: ;
    CPy_DECREF(cpy_r_r137);
    goto CPyL112;
CPyL223: ;
    CPy_DecRef(cpy_r_r141);
    goto CPyL189;
CPyL224: ;
    CPy_DecRef(cpy_r_r146);
    goto CPyL189;
CPyL225: ;
    CPy_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r148);
    goto CPyL189;
CPyL226: ;
    CPy_DecRef(cpy_r_r152);
    goto CPyL189;
CPyL227: ;
    CPy_DecRef(cpy_r_r160);
    goto CPyL189;
CPyL228: ;
    CPy_DecRef(cpy_r_r171);
    goto CPyL189;
CPyL229: ;
    CPy_DecRef(cpy_r_r187);
    goto CPyL189;
CPyL230: ;
    CPy_DecRef(cpy_r_r190);
    goto CPyL189;
CPyL231: ;
    CPy_DecRef(cpy_r_r190);
    CPy_DecRef(cpy_r_r192);
    goto CPyL189;
CPyL232: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL157;
CPyL233: ;
    CPy_XDecRef(cpy_r_r5);
    goto CPyL189;
CPyL234: ;
    CPy_DecRef(cpy_r_r202);
    goto CPyL189;
CPyL235: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL162;
CPyL236: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL161;
CPyL237: ;
    CPy_XDecRef(cpy_r_r7);
    goto CPyL171;
CPyL238: ;
    CPy_DecRef(cpy_r_r205);
    goto CPyL171;
CPyL239: ;
    CPy_DecRef(cpy_r_r202);
    goto CPyL171;
CPyL240: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL189;
CPyL241: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r7);
    goto CPyL1;
CPyL242: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL60;
CPyL243: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL186;
CPyL244: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL187;
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
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    int32_t cpy_r_r4;
    char cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    tuple_T3OOO cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    char cpy_r_r21;
    tuple_T3OOO cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    int32_t cpy_r_r32;
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
    int32_t cpy_r_r44;
    char cpy_r_r45;
    tuple_T3OOO cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    char cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    int32_t cpy_r_r58;
    char cpy_r_r59;
    tuple_T3OOO cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    char cpy_r_r64;
    char cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    tuple_T2II cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    char cpy_r_r73;
    char cpy_r_r74;
    PyObject *cpy_r_r75;
    char cpy_r_r76;
    char cpy_r_r77;
    char cpy_r_r78;
    char cpy_r_r79;
    cpy_r_r0 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_wrapper, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL4;
    }
    if (likely(PyUnicode_Check(cpy_r_r1)))
        cpy_r_r2 = cpy_r_r1;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 291, CPyStatic_globals, "str", cpy_r_r1);
        goto CPyL4;
    }
    cpy_r_r3 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r4 = PyObject_SetAttr(cpy_r_self, cpy_r_r3, cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    cpy_r_r5 = cpy_r_r4 >= 0;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL11;
CPyL4: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r10 = CPy_ExceptionMatches(cpy_r_r9);
    CPy_DecRef(cpy_r_r9);
    if (cpy_r_r10) goto CPyL8;
    CPy_Reraise();
    if (!0) {
        goto CPyL9;
    } else
        goto CPyL74;
CPyL7: ;
    CPy_Unreachable();
CPyL8: ;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DecRef(cpy_r_r6.f0);
    CPy_DecRef(cpy_r_r6.f1);
    CPy_DecRef(cpy_r_r6.f2);
    goto CPyL11;
CPyL9: ;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DecRef(cpy_r_r6.f0);
    CPy_DecRef(cpy_r_r6.f1);
    CPy_DecRef(cpy_r_r6.f2);
    cpy_r_r11 = CPy_KeepPropagating();
    if (!cpy_r_r11) goto CPyL73;
    CPy_Unreachable();
CPyL11: ;
    cpy_r_r12 = ((async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___name__;
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__name__", 295, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_INCREF(cpy_r_r12);
CPyL12: ;
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___name__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___name__);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___name__ = cpy_r_r12;
    cpy_r_r13 = 1;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL20;
CPyL13: ;
    cpy_r_r14 = CPy_CatchError();
    cpy_r_r15 = CPyModule_builtins;
    cpy_r_r16 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r17 = CPyObject_GetAttr(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r18 = CPy_ExceptionMatches(cpy_r_r17);
    CPy_DecRef(cpy_r_r17);
    if (cpy_r_r18) goto CPyL17;
    CPy_Reraise();
    if (!0) {
        goto CPyL18;
    } else
        goto CPyL75;
CPyL16: ;
    CPy_Unreachable();
CPyL17: ;
    CPy_RestoreExcInfo(cpy_r_r14);
    CPy_DecRef(cpy_r_r14.f0);
    CPy_DecRef(cpy_r_r14.f1);
    CPy_DecRef(cpy_r_r14.f2);
    goto CPyL20;
CPyL18: ;
    CPy_RestoreExcInfo(cpy_r_r14);
    CPy_DecRef(cpy_r_r14.f0);
    CPy_DecRef(cpy_r_r14.f1);
    CPy_DecRef(cpy_r_r14.f2);
    cpy_r_r19 = CPy_KeepPropagating();
    if (!cpy_r_r19) goto CPyL73;
    CPy_Unreachable();
CPyL20: ;
    cpy_r_r20 = ((async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___qualname__;
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__qualname__", 299, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_INCREF(cpy_r_r20);
CPyL21: ;
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___qualname__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___qualname__);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___qualname__ = cpy_r_r20;
    cpy_r_r21 = 1;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL29;
CPyL22: ;
    cpy_r_r22 = CPy_CatchError();
    cpy_r_r23 = CPyModule_builtins;
    cpy_r_r24 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r26 = CPy_ExceptionMatches(cpy_r_r25);
    CPy_DecRef(cpy_r_r25);
    if (cpy_r_r26) goto CPyL26;
    CPy_Reraise();
    if (!0) {
        goto CPyL27;
    } else
        goto CPyL76;
CPyL25: ;
    CPy_Unreachable();
CPyL26: ;
    CPy_RestoreExcInfo(cpy_r_r22);
    CPy_DecRef(cpy_r_r22.f0);
    CPy_DecRef(cpy_r_r22.f1);
    CPy_DecRef(cpy_r_r22.f2);
    goto CPyL29;
CPyL27: ;
    CPy_RestoreExcInfo(cpy_r_r22);
    CPy_DecRef(cpy_r_r22.f0);
    CPy_DecRef(cpy_r_r22.f1);
    CPy_DecRef(cpy_r_r22.f2);
    cpy_r_r27 = CPy_KeepPropagating();
    if (!cpy_r_r27) goto CPyL73;
    CPy_Unreachable();
CPyL29: ;
    cpy_r_r28 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r29 = CPyObject_GetAttr(cpy_r_wrapper, cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    }
    if (PyUnicode_Check(cpy_r_r29))
        cpy_r_r30 = cpy_r_r29;
    else {
        cpy_r_r30 = NULL;
    }
    if (cpy_r_r30 != NULL) goto __LL29;
    if (cpy_r_r29 == Py_None)
        cpy_r_r30 = cpy_r_r29;
    else {
        cpy_r_r30 = NULL;
    }
    if (cpy_r_r30 != NULL) goto __LL29;
    CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 303, CPyStatic_globals, "str or None", cpy_r_r29);
    goto CPyL32;
__LL29: ;
    cpy_r_r31 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r32 = PyObject_SetAttr(cpy_r_self, cpy_r_r31, cpy_r_r30);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r33 = cpy_r_r32 >= 0;
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL39;
CPyL32: ;
    cpy_r_r34 = CPy_CatchError();
    cpy_r_r35 = CPyModule_builtins;
    cpy_r_r36 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r38 = CPy_ExceptionMatches(cpy_r_r37);
    CPy_DecRef(cpy_r_r37);
    if (cpy_r_r38) goto CPyL36;
    CPy_Reraise();
    if (!0) {
        goto CPyL37;
    } else
        goto CPyL77;
CPyL35: ;
    CPy_Unreachable();
CPyL36: ;
    CPy_RestoreExcInfo(cpy_r_r34);
    CPy_DecRef(cpy_r_r34.f0);
    CPy_DecRef(cpy_r_r34.f1);
    CPy_DecRef(cpy_r_r34.f2);
    goto CPyL39;
CPyL37: ;
    CPy_RestoreExcInfo(cpy_r_r34);
    CPy_DecRef(cpy_r_r34.f0);
    CPy_DecRef(cpy_r_r34.f1);
    CPy_DecRef(cpy_r_r34.f2);
    cpy_r_r39 = CPy_KeepPropagating();
    if (!cpy_r_r39) goto CPyL73;
    CPy_Unreachable();
CPyL39: ;
    cpy_r_r40 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r41 = CPyObject_GetAttr(cpy_r_wrapper, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL42;
    }
    if (likely(PyDict_Check(cpy_r_r41)))
        cpy_r_r42 = cpy_r_r41;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 307, CPyStatic_globals, "dict", cpy_r_r41);
        goto CPyL42;
    }
    cpy_r_r43 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r44 = PyObject_SetAttr(cpy_r_self, cpy_r_r43, cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r45 = cpy_r_r44 >= 0;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL49;
CPyL42: ;
    cpy_r_r46 = CPy_CatchError();
    cpy_r_r47 = CPyModule_builtins;
    cpy_r_r48 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r49 = CPyObject_GetAttr(cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r50 = CPy_ExceptionMatches(cpy_r_r49);
    CPy_DecRef(cpy_r_r49);
    if (cpy_r_r50) goto CPyL46;
    CPy_Reraise();
    if (!0) {
        goto CPyL47;
    } else
        goto CPyL78;
CPyL45: ;
    CPy_Unreachable();
CPyL46: ;
    CPy_RestoreExcInfo(cpy_r_r46);
    CPy_DecRef(cpy_r_r46.f0);
    CPy_DecRef(cpy_r_r46.f1);
    CPy_DecRef(cpy_r_r46.f2);
    goto CPyL49;
CPyL47: ;
    CPy_RestoreExcInfo(cpy_r_r46);
    CPy_DecRef(cpy_r_r46.f0);
    CPy_DecRef(cpy_r_r46.f1);
    CPy_DecRef(cpy_r_r46.f2);
    cpy_r_r51 = CPy_KeepPropagating();
    if (!cpy_r_r51) goto CPyL73;
    CPy_Unreachable();
CPyL49: ;
    cpy_r_r52 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r53 = CPyObject_GetAttr(cpy_r_self, cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL54;
    }
    if (likely(PyDict_Check(cpy_r_r53)))
        cpy_r_r54 = cpy_r_r53;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 311, CPyStatic_globals, "dict", cpy_r_r53);
        goto CPyL54;
    }
    cpy_r_r55 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r56 = CPyObject_GetAttr(cpy_r_wrapper, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL79;
    }
    if (likely(PyDict_Check(cpy_r_r56)))
        cpy_r_r57 = cpy_r_r56;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 311, CPyStatic_globals, "dict", cpy_r_r56);
        goto CPyL79;
    }
    cpy_r_r58 = CPyDict_Update(cpy_r_r54, cpy_r_r57);
    CPy_DECREF(cpy_r_r54);
    CPy_DECREF(cpy_r_r57);
    cpy_r_r59 = cpy_r_r58 >= 0;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL61;
CPyL54: ;
    cpy_r_r60 = CPy_CatchError();
    cpy_r_r61 = CPyModule_builtins;
    cpy_r_r62 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r63 = CPyObject_GetAttr(cpy_r_r61, cpy_r_r62);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r64 = CPy_ExceptionMatches(cpy_r_r63);
    CPy_DecRef(cpy_r_r63);
    if (cpy_r_r64) goto CPyL58;
    CPy_Reraise();
    if (!0) {
        goto CPyL59;
    } else
        goto CPyL80;
CPyL57: ;
    CPy_Unreachable();
CPyL58: ;
    CPy_RestoreExcInfo(cpy_r_r60);
    CPy_DecRef(cpy_r_r60.f0);
    CPy_DecRef(cpy_r_r60.f1);
    CPy_DecRef(cpy_r_r60.f2);
    goto CPyL61;
CPyL59: ;
    CPy_RestoreExcInfo(cpy_r_r60);
    CPy_DecRef(cpy_r_r60.f0);
    CPy_DecRef(cpy_r_r60.f1);
    CPy_DecRef(cpy_r_r60.f2);
    cpy_r_r65 = CPy_KeepPropagating();
    if (!cpy_r_r65) goto CPyL73;
    CPy_Unreachable();
CPyL61: ;
    cpy_r_r66 = CPyModule_sys;
    cpy_r_r67 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r68 = CPyObject_GetAttr(cpy_r_r66, cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL73;
    }
    if (likely(PyTuple_Check(cpy_r_r68)))
        cpy_r_r69 = cpy_r_r68;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "__init__", 316, CPyStatic_globals, "tuple", cpy_r_r68);
        goto CPyL73;
    }
    cpy_r_r70.f0 = 6;
    cpy_r_r70.f1 = 28;
    cpy_r_r71 = PyTuple_New(2);
    if (unlikely(cpy_r_r71 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp30 = CPyTagged_StealAsObject(cpy_r_r70.f0);
    PyTuple_SET_ITEM(cpy_r_r71, 0, __tmp30);
    PyObject *__tmp31 = CPyTagged_StealAsObject(cpy_r_r70.f1);
    PyTuple_SET_ITEM(cpy_r_r71, 1, __tmp31);
    cpy_r_r72 = PyObject_RichCompare(cpy_r_r69, cpy_r_r71, 0);
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL73;
    }
    if (unlikely(!PyBool_Check(cpy_r_r72))) {
        CPy_TypeError("bool", cpy_r_r72); cpy_r_r73 = 2;
    } else
        cpy_r_r73 = cpy_r_r72 == Py_True;
    CPy_DECREF(cpy_r_r72);
    if (unlikely(cpy_r_r73 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL73;
    }
    if (!cpy_r_r73) goto CPyL68;
    PyErr_SetString(PyExc_RuntimeError, "Reached allegedly unreachable code!");
    cpy_r_r74 = 0;
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL73;
    }
    CPy_Unreachable();
CPyL68: ;
    cpy_r_r75 = ((async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___wrapped__;
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__wrapped__", 318, CPyStatic_globals);
        goto CPyL73;
    }
    CPy_INCREF(cpy_r_r75);
CPyL69: ;
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapped__ != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapped__);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapped__ = cpy_r_r75;
    cpy_r_r76 = 1;
    if (unlikely(!cpy_r_r76)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL73;
    }
    CPy_INCREF(cpy_r_instance);
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___instance != NULL) {
        CPy_DECREF(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___instance);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___instance = cpy_r_instance;
    cpy_r_r77 = 1;
    if (unlikely(!cpy_r_r77)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL73;
    }
    CPy_INCREF_NO_IMM(cpy_r_wrapper);
    if (((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper != NULL) {
        CPy_DECREF_NO_IMM(((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper);
    }
    ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper = cpy_r_wrapper;
    cpy_r_r78 = 1;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL73;
    }
    return 1;
CPyL73: ;
    cpy_r_r79 = 2;
    return cpy_r_r79;
CPyL74: ;
    CPy_DecRef(cpy_r_r6.f0);
    CPy_DecRef(cpy_r_r6.f1);
    CPy_DecRef(cpy_r_r6.f2);
    goto CPyL7;
CPyL75: ;
    CPy_DecRef(cpy_r_r14.f0);
    CPy_DecRef(cpy_r_r14.f1);
    CPy_DecRef(cpy_r_r14.f2);
    goto CPyL16;
CPyL76: ;
    CPy_DecRef(cpy_r_r22.f0);
    CPy_DecRef(cpy_r_r22.f1);
    CPy_DecRef(cpy_r_r22.f2);
    goto CPyL25;
CPyL77: ;
    CPy_DecRef(cpy_r_r34.f0);
    CPy_DecRef(cpy_r_r34.f1);
    CPy_DecRef(cpy_r_r34.f2);
    goto CPyL35;
CPyL78: ;
    CPy_DecRef(cpy_r_r46.f0);
    CPy_DecRef(cpy_r_r46.f1);
    CPy_DecRef(cpy_r_r46.f2);
    goto CPyL45;
CPyL79: ;
    CPy_DecRef(cpy_r_r54);
    goto CPyL54;
CPyL80: ;
    CPy_DecRef(cpy_r_r60.f0);
    CPy_DecRef(cpy_r_r60.f1);
    CPy_DecRef(cpy_r_r60.f2);
    goto CPyL57;
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
        CPy_AttributeError("async_lru/__init__.py", "cache_invalidate", "_LRUCacheWrapperInstanceMethod", "__wrapper", 323, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___instance;
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "cache_invalidate", "_LRUCacheWrapperInstanceMethod", "__instance", 323, CPyStatic_globals);
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
        CPy_AttributeError("async_lru/__init__.py", "cache_clear", "_LRUCacheWrapperInstanceMethod", "__wrapper", 326, CPyStatic_globals);
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
        CPy_AttributeError("async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "self", 331, CPyStatic_globals);
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
    PyObject *__tmp32 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp32);
    PyObject *__tmp33 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp33);
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
        CPy_AttributeError("async_lru/__init__.py", "cache_info", "_LRUCacheWrapperInstanceMethod", "__wrapper", 334, CPyStatic_globals);
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
        CPy_AttributeError("async_lru/__init__.py", "cache_parameters", "_LRUCacheWrapperInstanceMethod", "__wrapper", 337, CPyStatic_globals);
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
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "self", 340, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_INCREF_NO_IMM(cpy_r_r5);
CPyL5: ;
    cpy_r_r6 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "self", 340, CPyStatic_globals);
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
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "fn_args", 340, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_INCREF(cpy_r_r8);
CPyL8: ;
    cpy_r_r9 = ((async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_kwargs;
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "fn_kwargs", 340, CPyStatic_globals);
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
    PyObject *__tmp34 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp34);
    PyObject *__tmp35 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp35);
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
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    tuple_T2OO cpy_r_r7;
    PyObject *cpy_r_r8;
    int32_t cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject **cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    CPyPtr cpy_r_r39;
    CPyPtr cpy_r_r40;
    CPyPtr cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    char cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject **cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_wrapper;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    tuple_T2II cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject **cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    cpy_r_r0 = ((async_lru___wrapper__make_wrapper_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "wrapper", "wrapper__make_wrapper_obj", "__mypyc_env__", 354, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    CPy_INCREF(cpy_r_fn);
    cpy_r_origin = cpy_r_fn;
CPyL2: ;
    cpy_r_r1 = CPyStatic_globals;
    cpy_r_r2 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partial' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r4 = CPyStatic_globals;
    cpy_r_r5 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partialmethod' */
    cpy_r_r6 = CPyDict_GetItem(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r7.f0 = cpy_r_r3;
    cpy_r_r7.f1 = cpy_r_r6;
    cpy_r_r8 = PyTuple_New(2);
    if (unlikely(cpy_r_r8 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp36 = cpy_r_r7.f0;
    PyTuple_SET_ITEM(cpy_r_r8, 0, __tmp36);
    PyObject *__tmp37 = cpy_r_r7.f1;
    PyTuple_SET_ITEM(cpy_r_r8, 1, __tmp37);
    cpy_r_r9 = PyObject_IsInstance(cpy_r_origin, cpy_r_r8);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r10 = cpy_r_r9 >= 0;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r11 = cpy_r_r9;
    if (!cpy_r_r11) goto CPyL8;
    cpy_r_r12 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'func' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_origin, cpy_r_r12);
    CPy_DECREF(cpy_r_origin);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_origin = cpy_r_r13;
    goto CPyL2;
CPyL8: ;
    cpy_r_r14 = CPyModule_inspect;
    cpy_r_r15 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'iscoroutinefunction' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL44;
    }
    PyObject *cpy_r_r17[1] = {cpy_r_origin};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = PyObject_Vectorcall(cpy_r_r16, cpy_r_r18, 1, 0);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL44;
    }
    CPy_DECREF(cpy_r_origin);
    if (unlikely(!PyBool_Check(cpy_r_r19))) {
        CPy_TypeError("bool", cpy_r_r19); cpy_r_r20 = 2;
    } else
        cpy_r_r20 = cpy_r_r19 == Py_True;
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL46;
    }
    if (cpy_r_r20) goto CPyL25;
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'ALLOW_SYNC' */
    cpy_r_r23 = CPyDict_GetItem(cpy_r_r21, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL46;
    }
    if (PyUnicode_Check(cpy_r_r23))
        cpy_r_r24 = cpy_r_r23;
    else {
        cpy_r_r24 = NULL;
    }
    if (cpy_r_r24 != NULL) goto __LL38;
    if (cpy_r_r23 == Py_None)
        cpy_r_r24 = cpy_r_r23;
    else {
        cpy_r_r24 = NULL;
    }
    if (cpy_r_r24 != NULL) goto __LL38;
    CPy_TypeErrorTraceback("async_lru/__init__.py", "wrapper", 360, CPyStatic_globals, "str or None", cpy_r_r23);
    goto CPyL46;
__LL38: ;
    cpy_r_r25 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r26 = cpy_r_r24 != cpy_r_r25;
    if (!cpy_r_r26) goto CPyL47;
    if (likely(cpy_r_r24 != Py_None))
        cpy_r_r27 = cpy_r_r24;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "wrapper", 360, CPyStatic_globals, "str", cpy_r_r24);
        goto CPyL46;
    }
    cpy_r_r28 = CPyStr_IsTrue(cpy_r_r27);
    CPy_DECREF(cpy_r_r27);
    if (cpy_r_r28) {
        goto CPyL25;
    } else
        goto CPyL48;
CPyL17: ;
    cpy_r_r29 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '' */
    cpy_r_r30 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Coroutine function is required, got ' */
    cpy_r_r31 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '{!r:{}}' */
    cpy_r_r32 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '' */
    cpy_r_r33 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'format' */
    PyObject *cpy_r_r34[3] = {cpy_r_r31, cpy_r_fn, cpy_r_r32};
    cpy_r_r35 = (PyObject **)&cpy_r_r34;
    cpy_r_r36 = PyObject_VectorcallMethod(cpy_r_r33, cpy_r_r35, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
    if (likely(PyUnicode_Check(cpy_r_r36)))
        cpy_r_r37 = cpy_r_r36;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "wrapper", 361, CPyStatic_globals, "str", cpy_r_r36);
        goto CPyL43;
    }
    cpy_r_r38 = PyList_New(2);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r39 = (CPyPtr)&((PyListObject *)cpy_r_r38)->ob_item;
    cpy_r_r40 = *(CPyPtr *)cpy_r_r39;
    CPy_INCREF(cpy_r_r30);
    *(PyObject * *)cpy_r_r40 = cpy_r_r30;
    cpy_r_r41 = cpy_r_r40 + 8;
    *(PyObject * *)cpy_r_r41 = cpy_r_r37;
    cpy_r_r42 = PyUnicode_Join(cpy_r_r29, cpy_r_r38);
    CPy_DECREF_NO_IMM(cpy_r_r38);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r43 = CPyModule_builtins;
    cpy_r_r44 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'RuntimeError' */
    cpy_r_r45 = CPyObject_GetAttr(cpy_r_r43, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    PyObject *cpy_r_r46[1] = {cpy_r_r42};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = PyObject_Vectorcall(cpy_r_r45, cpy_r_r47, 1, 0);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_DECREF(cpy_r_r42);
    CPy_Raise(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_Unreachable();
CPyL25: ;
    cpy_r_r49 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_make_unbound_method' */
    cpy_r_r50 = PyObject_HasAttr(cpy_r_fn, cpy_r_r49);
    if (!cpy_r_r50) goto CPyL51;
    cpy_r_r51 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_make_unbound_method' */
    PyObject *cpy_r_r52[1] = {cpy_r_fn};
    cpy_r_r53 = (PyObject **)&cpy_r_r52;
    cpy_r_r54 = PyObject_VectorcallMethod(cpy_r_r51, cpy_r_r53, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_fn = cpy_r_r54;
CPyL28: ;
    cpy_r_r55 = ((async_lru____make_wrapper_envObject *)cpy_r_r0)->_maxsize;
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "wrapper", "_make_wrapper_env", "maxsize", 366, CPyStatic_globals);
        goto CPyL52;
    }
    CPy_INCREF(cpy_r_r55);
CPyL29: ;
    cpy_r_r56 = ((async_lru____make_wrapper_envObject *)cpy_r_r0)->_typed;
    if (unlikely(cpy_r_r56 == 2)) {
        CPy_AttributeError("async_lru/__init__.py", "wrapper", "_make_wrapper_env", "typed", 366, CPyStatic_globals);
        goto CPyL53;
    }
CPyL30: ;
    cpy_r_r57 = ((async_lru____make_wrapper_envObject *)cpy_r_r0)->_ttl;
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "wrapper", "_make_wrapper_env", "ttl", 366, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_INCREF(cpy_r_r57);
CPyL31: ;
    cpy_r_r58 = ((async_lru____make_wrapper_envObject *)cpy_r_r0)->_jitter;
    if (unlikely(cpy_r_r58 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'jitter' of '_make_wrapper_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r58);
    }
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL54;
    }
CPyL32: ;
    cpy_r_r59 = CPyDef__LRUCacheWrapper(cpy_r_fn, cpy_r_r55, cpy_r_r56, cpy_r_r57, cpy_r_r58);
    CPy_DECREF(cpy_r_fn);
    CPy_DECREF(cpy_r_r55);
    CPy_DECREF(cpy_r_r57);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_wrapper = cpy_r_r59;
    cpy_r_r60 = CPyModule_sys;
    cpy_r_r61 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r62 = CPyObject_GetAttr(cpy_r_r60, cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL55;
    }
    if (likely(PyTuple_Check(cpy_r_r62)))
        cpy_r_r63 = cpy_r_r62;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "wrapper", 367, CPyStatic_globals, "tuple", cpy_r_r62);
        goto CPyL55;
    }
    cpy_r_r64.f0 = 6;
    cpy_r_r64.f1 = 24;
    cpy_r_r65 = PyTuple_New(2);
    if (unlikely(cpy_r_r65 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp39 = CPyTagged_StealAsObject(cpy_r_r64.f0);
    PyTuple_SET_ITEM(cpy_r_r65, 0, __tmp39);
    PyObject *__tmp40 = CPyTagged_StealAsObject(cpy_r_r64.f1);
    PyTuple_SET_ITEM(cpy_r_r65, 1, __tmp40);
    cpy_r_r66 = PyObject_RichCompare(cpy_r_r63, cpy_r_r65, 5);
    CPy_DECREF(cpy_r_r63);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL55;
    }
    if (unlikely(!PyBool_Check(cpy_r_r66))) {
        CPy_TypeError("bool", cpy_r_r66); cpy_r_r67 = 2;
    } else
        cpy_r_r67 = cpy_r_r66 == Py_True;
    CPy_DECREF(cpy_r_r66);
    if (unlikely(cpy_r_r67 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL55;
    }
    if (!cpy_r_r67) goto CPyL42;
    cpy_r_r68 = CPyModule_inspect;
    cpy_r_r69 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'markcoroutinefunction' */
    cpy_r_r70 = CPyObject_GetAttr(cpy_r_r68, cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL55;
    }
    PyObject *cpy_r_r71[1] = {cpy_r_wrapper};
    cpy_r_r72 = (PyObject **)&cpy_r_r71;
    cpy_r_r73 = PyObject_Vectorcall(cpy_r_r70, cpy_r_r72, 1, 0);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_DECREF_NO_IMM(cpy_r_wrapper);
    if (likely(Py_TYPE(cpy_r_r73) == CPyType__LRUCacheWrapper))
        cpy_r_r74 = cpy_r_r73;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "wrapper", 368, CPyStatic_globals, "async_lru._LRUCacheWrapper", cpy_r_r73);
        goto CPyL43;
    }
    cpy_r_wrapper = cpy_r_r74;
CPyL42: ;
    return cpy_r_wrapper;
CPyL43: ;
    cpy_r_r75 = NULL;
    return cpy_r_r75;
CPyL44: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_origin);
    goto CPyL43;
CPyL45: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_origin);
    CPy_DecRef(cpy_r_r3);
    goto CPyL43;
CPyL46: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL43;
CPyL47: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    CPy_DECREF(cpy_r_r24);
    goto CPyL17;
CPyL48: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    goto CPyL17;
CPyL49: ;
    CPy_DecRef(cpy_r_r37);
    goto CPyL43;
CPyL50: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL43;
CPyL51: ;
    CPy_INCREF(cpy_r_fn);
    goto CPyL28;
CPyL52: ;
    CPy_DecRef(cpy_r_fn);
    CPy_DecRef(cpy_r_r0);
    goto CPyL43;
CPyL53: ;
    CPy_DecRef(cpy_r_fn);
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r55);
    goto CPyL43;
CPyL54: ;
    CPy_DecRef(cpy_r_fn);
    CPy_DecRef(cpy_r_r55);
    CPy_DecRef(cpy_r_r57);
    goto CPyL43;
CPyL55: ;
    CPy_DecRef(cpy_r_wrapper);
    goto CPyL43;
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

PyObject *CPyDef__make_wrapper(PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl, PyObject *cpy_r_jitter) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    double cpy_r_r24;
    char cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    char cpy_r_r36;
    PyObject *cpy_r_wrapper;
    PyObject *cpy_r_r37;
    if (cpy_r_ttl != NULL) goto CPyL31;
    cpy_r_r0 = Py_None;
    cpy_r_ttl = cpy_r_r0;
CPyL2: ;
    if (cpy_r_jitter != NULL) goto CPyL32;
    cpy_r_r1 = Py_None;
    cpy_r_jitter = cpy_r_r1;
CPyL4: ;
    cpy_r_r2 = CPyDef__make_wrapper_env();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL33;
    }
    CPy_INCREF(cpy_r_maxsize);
    if (((async_lru____make_wrapper_envObject *)cpy_r_r2)->_maxsize != NULL) {
        CPy_DECREF(((async_lru____make_wrapper_envObject *)cpy_r_r2)->_maxsize);
    }
    ((async_lru____make_wrapper_envObject *)cpy_r_r2)->_maxsize = cpy_r_maxsize;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL34;
    }
    ((async_lru____make_wrapper_envObject *)cpy_r_r2)->_typed = cpy_r_typed;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL34;
    }
    if (((async_lru____make_wrapper_envObject *)cpy_r_r2)->_ttl != NULL) {
        CPy_DECREF(((async_lru____make_wrapper_envObject *)cpy_r_r2)->_ttl);
    }
    ((async_lru____make_wrapper_envObject *)cpy_r_r2)->_ttl = cpy_r_ttl;
    cpy_r_r5 = 1;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL35;
    }
    if (((async_lru____make_wrapper_envObject *)cpy_r_r2)->_jitter != NULL) {
        CPy_DECREF(((async_lru____make_wrapper_envObject *)cpy_r_r2)->_jitter);
    }
    ((async_lru____make_wrapper_envObject *)cpy_r_r2)->_jitter = cpy_r_jitter;
    cpy_r_r6 = 1;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r7 = ((async_lru____make_wrapper_envObject *)cpy_r_r2)->_jitter;
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_make_wrapper", "_make_wrapper_env", "jitter", 349, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_INCREF(cpy_r_r7);
CPyL10: ;
    cpy_r_r8 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r9 = cpy_r_r7 != cpy_r_r8;
    CPy_DECREF(cpy_r_r7);
    if (!cpy_r_r9) goto CPyL17;
    cpy_r_r10 = ((async_lru____make_wrapper_envObject *)cpy_r_r2)->_ttl;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_make_wrapper", "_make_wrapper_env", "ttl", 349, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_INCREF(cpy_r_r10);
CPyL12: ;
    cpy_r_r11 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r12 = cpy_r_r10 == cpy_r_r11;
    CPy_DECREF(cpy_r_r10);
    if (cpy_r_r12) {
        goto CPyL37;
    } else
        goto CPyL17;
CPyL13: ;
    cpy_r_r13 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'jitter requires ttl to be set' */
    cpy_r_r14 = CPyModule_builtins;
    cpy_r_r15 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'ValueError' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL30;
    }
    PyObject *cpy_r_r17[1] = {cpy_r_r13};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = PyObject_Vectorcall(cpy_r_r16, cpy_r_r18, 1, 0);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_Raise(cpy_r_r19);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_Unreachable();
CPyL17: ;
    cpy_r_r20 = ((async_lru____make_wrapper_envObject *)cpy_r_r2)->_jitter;
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_make_wrapper", "_make_wrapper_env", "jitter", 351, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_INCREF(cpy_r_r20);
CPyL18: ;
    cpy_r_r21 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r22 = cpy_r_r20 != cpy_r_r21;
    CPy_DECREF(cpy_r_r20);
    if (!cpy_r_r22) goto CPyL27;
    cpy_r_r23 = ((async_lru____make_wrapper_envObject *)cpy_r_r2)->_jitter;
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AttributeError("async_lru/__init__.py", "_make_wrapper", "_make_wrapper_env", "jitter", 351, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_INCREF(cpy_r_r23);
CPyL20: ;
    cpy_r_r24 = PyFloat_AsDouble(cpy_r_r23);
    if (cpy_r_r24 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r23); cpy_r_r24 = -113.0;
    }
    CPy_DECREF(cpy_r_r23);
    cpy_r_r25 = cpy_r_r24 == -113.0;
    if (unlikely(cpy_r_r25)) goto CPyL22;
CPyL21: ;
    cpy_r_r26 = cpy_r_r24 < 0.0;
    if (cpy_r_r26) {
        goto CPyL38;
    } else
        goto CPyL27;
CPyL22: ;
    cpy_r_r27 = PyErr_Occurred();
    if (unlikely(cpy_r_r27 != NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
    } else
        goto CPyL21;
CPyL23: ;
    cpy_r_r28 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'jitter must be non-negative' */
    cpy_r_r29 = CPyModule_builtins;
    cpy_r_r30 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'ValueError' */
    cpy_r_r31 = CPyObject_GetAttr(cpy_r_r29, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL30;
    }
    PyObject *cpy_r_r32[1] = {cpy_r_r28};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = PyObject_Vectorcall(cpy_r_r31, cpy_r_r33, 1, 0);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_Raise(cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_Unreachable();
CPyL27: ;
    cpy_r_r35 = CPyDef_wrapper__make_wrapper_obj();
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
    }
    if (((async_lru___wrapper__make_wrapper_objObject *)cpy_r_r35)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((async_lru___wrapper__make_wrapper_objObject *)cpy_r_r35)->___mypyc_env__);
    }
    ((async_lru___wrapper__make_wrapper_objObject *)cpy_r_r35)->___mypyc_env__ = cpy_r_r2;
    cpy_r_r36 = 1;
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_wrapper = cpy_r_r35;
    return cpy_r_wrapper;
CPyL30: ;
    cpy_r_r37 = NULL;
    return cpy_r_r37;
CPyL31: ;
    CPy_INCREF(cpy_r_ttl);
    goto CPyL2;
CPyL32: ;
    CPy_INCREF(cpy_r_jitter);
    goto CPyL4;
CPyL33: ;
    CPy_DecRef(cpy_r_ttl);
    CPy_DecRef(cpy_r_jitter);
    goto CPyL30;
CPyL34: ;
    CPy_DecRef(cpy_r_ttl);
    CPy_DecRef(cpy_r_jitter);
    CPy_DecRef(cpy_r_r2);
    goto CPyL30;
CPyL35: ;
    CPy_DecRef(cpy_r_jitter);
    CPy_DecRef(cpy_r_r2);
    goto CPyL30;
CPyL36: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL30;
CPyL37: ;
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL13;
CPyL38: ;
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL23;
CPyL39: ;
    CPy_DecRef(cpy_r_r35);
    goto CPyL30;
}

PyObject *CPyPy__make_wrapper(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"maxsize", "typed", "ttl", "jitter", 0};
    static CPyArg_Parser parser = {"OO|OO:_make_wrapper", kwlist, 0};
    PyObject *obj_maxsize;
    PyObject *obj_typed;
    PyObject *obj_ttl = NULL;
    PyObject *obj_jitter = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_maxsize, &obj_typed, &obj_ttl, &obj_jitter)) {
        return NULL;
    }
    PyObject *arg_maxsize;
    if (PyLong_Check(obj_maxsize))
        arg_maxsize = obj_maxsize;
    else {
        arg_maxsize = NULL;
    }
    if (arg_maxsize != NULL) goto __LL41;
    if (obj_maxsize == Py_None)
        arg_maxsize = obj_maxsize;
    else {
        arg_maxsize = NULL;
    }
    if (arg_maxsize != NULL) goto __LL41;
    CPy_TypeError("int or None", obj_maxsize); 
    goto fail;
__LL41: ;
    char arg_typed;
    if (unlikely(!PyBool_Check(obj_typed))) {
        CPy_TypeError("bool", obj_typed); goto fail;
    } else
        arg_typed = obj_typed == Py_True;
    PyObject *arg_ttl;
    if (obj_ttl == NULL) {
        arg_ttl = NULL;
        goto __LL42;
    }
    if (CPyFloat_Check(obj_ttl))
        arg_ttl = obj_ttl;
    else {
        arg_ttl = NULL;
    }
    if (arg_ttl != NULL) goto __LL42;
    if (obj_ttl == Py_None)
        arg_ttl = obj_ttl;
    else {
        arg_ttl = NULL;
    }
    if (arg_ttl != NULL) goto __LL42;
    CPy_TypeError("float or None", obj_ttl); 
    goto fail;
__LL42: ;
    PyObject *arg_jitter;
    if (obj_jitter == NULL) {
        arg_jitter = NULL;
        goto __LL43;
    }
    if (CPyFloat_Check(obj_jitter))
        arg_jitter = obj_jitter;
    else {
        arg_jitter = NULL;
    }
    if (arg_jitter != NULL) goto __LL43;
    if (obj_jitter == Py_None)
        arg_jitter = obj_jitter;
    else {
        arg_jitter = NULL;
    }
    if (arg_jitter != NULL) goto __LL43;
    CPy_TypeError("float or None", obj_jitter); 
    goto fail;
__LL43: ;
    PyObject *retval = CPyDef__make_wrapper(arg_maxsize, arg_typed, arg_ttl, arg_jitter);
    return retval;
fail: ;
    CPy_AddTraceback("async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_alru_cache(PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl, PyObject *cpy_r_jitter) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_fn;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
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
    if (cpy_r_maxsize != NULL) goto CPyL30;
    cpy_r_r0 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 128 */
    cpy_r_maxsize = cpy_r_r0;
CPyL2: ;
    if (cpy_r_typed != 2) goto CPyL4;
    cpy_r_typed = 0;
CPyL4: ;
    if (cpy_r_ttl != NULL) goto CPyL31;
    cpy_r_r1 = Py_None;
    cpy_r_ttl = cpy_r_r1;
CPyL6: ;
    if (cpy_r_jitter != NULL) goto CPyL32;
    cpy_r_r2 = Py_None;
    cpy_r_jitter = cpy_r_r2;
CPyL8: ;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = cpy_r_maxsize == cpy_r_r3;
    if (cpy_r_r4) goto CPyL10;
    cpy_r_r5 = PyLong_Check(cpy_r_maxsize);
    if (!cpy_r_r5) goto CPyL33;
CPyL10: ;
    if (PyLong_Check(cpy_r_maxsize))
        cpy_r_r6 = cpy_r_maxsize;
    else {
        cpy_r_r6 = NULL;
    }
    if (cpy_r_r6 != NULL) goto __LL44;
    if (cpy_r_maxsize == Py_None)
        cpy_r_r6 = cpy_r_maxsize;
    else {
        cpy_r_r6 = NULL;
    }
    if (cpy_r_r6 != NULL) goto __LL44;
    CPy_TypeErrorTraceback("async_lru/__init__.py", "alru_cache", 401, CPyStatic_globals, "int or None", cpy_r_maxsize);
    goto CPyL34;
__LL44: ;
    cpy_r_r7 = CPyDef__make_wrapper(cpy_r_r6, cpy_r_typed, cpy_r_ttl, cpy_r_jitter);
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_ttl);
    CPy_DECREF(cpy_r_jitter);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL29;
    }
    return cpy_r_r7;
CPyL13: ;
    cpy_r_fn = cpy_r_maxsize;
    cpy_r_r8 = CPyModule_builtins;
    cpy_r_r9 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'callable' */
    cpy_r_r10 = CPyObject_GetAttr(cpy_r_r8, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL35;
    }
    PyObject *cpy_r_r11[1] = {cpy_r_fn};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = PyObject_Vectorcall(cpy_r_r10, cpy_r_r12, 1, 0);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL35;
    }
    if (unlikely(!PyBool_Check(cpy_r_r13))) {
        CPy_TypeError("bool", cpy_r_r13); cpy_r_r14 = 2;
    } else
        cpy_r_r14 = cpy_r_r13 == Py_True;
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r14 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL35;
    }
    if (cpy_r_r14) goto CPyL18;
    cpy_r_r15 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_make_unbound_method' */
    cpy_r_r16 = PyObject_HasAttr(cpy_r_fn, cpy_r_r15);
    if (!cpy_r_r16) goto CPyL22;
CPyL18: ;
    cpy_r_r17 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 128 */
    cpy_r_r18 = Py_None;
    cpy_r_r19 = Py_None;
    cpy_r_r20 = CPyDef__make_wrapper(cpy_r_r17, 0, cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL35;
    }
    PyObject *cpy_r_r21[1] = {cpy_r_fn};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = PyObject_Vectorcall(cpy_r_r20, cpy_r_r22, 1, 0);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL35;
    }
    CPy_DECREF(cpy_r_fn);
    if (likely(Py_TYPE(cpy_r_r23) == CPyType__LRUCacheWrapper))
        cpy_r_r24 = cpy_r_r23;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "alru_cache", 406, CPyStatic_globals, "async_lru._LRUCacheWrapper", cpy_r_r23);
        goto CPyL29;
    }
    return cpy_r_r24;
CPyL22: ;
    cpy_r_r25 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '' */
    cpy_r_r26 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '{!r:{}}' */
    cpy_r_r27 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '' */
    cpy_r_r28 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'format' */
    PyObject *cpy_r_r29[3] = {cpy_r_r26, cpy_r_fn, cpy_r_r27};
    cpy_r_r30 = (PyObject **)&cpy_r_r29;
    cpy_r_r31 = PyObject_VectorcallMethod(cpy_r_r28, cpy_r_r30, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL35;
    }
    CPy_DECREF(cpy_r_fn);
    cpy_r_r32 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ' decorating is not supported' */
    cpy_r_r33 = PyList_New(2);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r34 = (CPyPtr)&((PyListObject *)cpy_r_r33)->ob_item;
    cpy_r_r35 = *(CPyPtr *)cpy_r_r34;
    *(PyObject * *)cpy_r_r35 = cpy_r_r31;
    CPy_INCREF(cpy_r_r32);
    cpy_r_r36 = cpy_r_r35 + 8;
    *(PyObject * *)cpy_r_r36 = cpy_r_r32;
    cpy_r_r37 = PyUnicode_Join(cpy_r_r25, cpy_r_r33);
    CPy_DECREF_NO_IMM(cpy_r_r33);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r38 = CPyModule_builtins;
    cpy_r_r39 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'NotImplementedError' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL37;
    }
    PyObject *cpy_r_r41[1] = {cpy_r_r37};
    cpy_r_r42 = (PyObject **)&cpy_r_r41;
    cpy_r_r43 = PyObject_Vectorcall(cpy_r_r40, cpy_r_r42, 1, 0);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL37;
    }
    CPy_DECREF(cpy_r_r37);
    CPy_Raise(cpy_r_r43);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(!0)) {
        CPy_AddTraceback("async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL29;
    }
    CPy_Unreachable();
CPyL29: ;
    cpy_r_r44 = NULL;
    return cpy_r_r44;
CPyL30: ;
    CPy_INCREF(cpy_r_maxsize);
    goto CPyL2;
CPyL31: ;
    CPy_INCREF(cpy_r_ttl);
    goto CPyL6;
CPyL32: ;
    CPy_INCREF(cpy_r_jitter);
    goto CPyL8;
CPyL33: ;
    CPy_DECREF(cpy_r_ttl);
    CPy_DECREF(cpy_r_jitter);
    goto CPyL13;
CPyL34: ;
    CPy_DecRef(cpy_r_ttl);
    CPy_DecRef(cpy_r_jitter);
    goto CPyL29;
CPyL35: ;
    CPy_DecRef(cpy_r_fn);
    goto CPyL29;
CPyL36: ;
    CPy_DecRef(cpy_r_r31);
    goto CPyL29;
CPyL37: ;
    CPy_DecRef(cpy_r_r37);
    goto CPyL29;
}

PyObject *CPyPy_alru_cache(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"maxsize", "typed", "ttl", "jitter", 0};
    static CPyArg_Parser parser = {"|OO$OO:alru_cache", kwlist, 0};
    PyObject *obj_maxsize = NULL;
    PyObject *obj_typed = NULL;
    PyObject *obj_ttl = NULL;
    PyObject *obj_jitter = NULL;
    if (!CPyArg_ParseStackAndKeywords(args, nargs, kwnames, &parser, &obj_maxsize, &obj_typed, &obj_ttl, &obj_jitter)) {
        return NULL;
    }
    PyObject *arg_maxsize;
    if (obj_maxsize == NULL) {
        arg_maxsize = NULL;
        goto __LL45;
    }
    if (PyLong_Check(obj_maxsize))
        arg_maxsize = obj_maxsize;
    else {
        arg_maxsize = NULL;
    }
    if (arg_maxsize != NULL) goto __LL45;
    if (obj_maxsize == Py_None)
        arg_maxsize = obj_maxsize;
    else {
        arg_maxsize = NULL;
    }
    if (arg_maxsize != NULL) goto __LL45;
    arg_maxsize = obj_maxsize;
    if (arg_maxsize != NULL) goto __LL45;
    CPy_TypeError("union[int, None, object]", obj_maxsize); 
    goto fail;
__LL45: ;
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
        goto __LL46;
    }
    if (CPyFloat_Check(obj_ttl))
        arg_ttl = obj_ttl;
    else {
        arg_ttl = NULL;
    }
    if (arg_ttl != NULL) goto __LL46;
    if (obj_ttl == Py_None)
        arg_ttl = obj_ttl;
    else {
        arg_ttl = NULL;
    }
    if (arg_ttl != NULL) goto __LL46;
    CPy_TypeError("float or None", obj_ttl); 
    goto fail;
__LL46: ;
    PyObject *arg_jitter;
    if (obj_jitter == NULL) {
        arg_jitter = NULL;
        goto __LL47;
    }
    if (CPyFloat_Check(obj_jitter))
        arg_jitter = obj_jitter;
    else {
        arg_jitter = NULL;
    }
    if (arg_jitter != NULL) goto __LL47;
    if (obj_jitter == Py_None)
        arg_jitter = obj_jitter;
    else {
        arg_jitter = NULL;
    }
    if (arg_jitter != NULL) goto __LL47;
    CPy_TypeError("float or None", obj_jitter); 
    goto fail;
__LL47: ;
    PyObject *retval = CPyDef_alru_cache(arg_maxsize, arg_typed, arg_ttl, arg_jitter);
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
    void *cpy_r_r12;
    void *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
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
    tuple_T2II cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    char cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    tuple_T2II cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    char cpy_r_r48;
    char cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    int32_t cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_r55;
    tuple_T1O cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    int32_t cpy_r_r60;
    char cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject **cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    int32_t cpy_r_r73;
    char cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject **cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    int32_t cpy_r_r84;
    char cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject **cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    int32_t cpy_r_r95;
    char cpy_r_r96;
    PyObject *cpy_r_r97;
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
    tuple_T3OOO cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    int32_t cpy_r_r114;
    char cpy_r_r115;
    PyObject *cpy_r_r116;
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
    tuple_T2OO cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    int32_t cpy_r_r132;
    char cpy_r_r133;
    PyObject *cpy_r_r134;
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
    tuple_T3OOO cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    int32_t cpy_r_r151;
    char cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    char cpy_r_r155;
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
    char cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    char cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject **cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    int32_t cpy_r_r188;
    char cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    int32_t cpy_r_r192;
    char cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    int32_t cpy_r_r196;
    char cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject *cpy_r_r199;
    int32_t cpy_r_r200;
    char cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    int32_t cpy_r_r204;
    char cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    int32_t cpy_r_r208;
    char cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    int32_t cpy_r_r212;
    char cpy_r_r213;
    PyObject **cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject **cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    PyObject *cpy_r_r224;
    int32_t cpy_r_r225;
    char cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject *cpy_r_r230;
    PyObject *cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_r238;
    char cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    PyObject *cpy_r_r245;
    int32_t cpy_r_r246;
    char cpy_r_r247;
    PyObject *cpy_r_r248;
    PyObject *cpy_r_r249;
    int32_t cpy_r_r250;
    char cpy_r_r251;
    PyObject *cpy_r_r252;
    tuple_T0 cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_r255;
    PyObject *cpy_r_r256;
    PyObject *cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    int32_t cpy_r_r260;
    char cpy_r_r261;
    PyObject *cpy_r_r262;
    PyObject *cpy_r_r263;
    int32_t cpy_r_r264;
    char cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject *cpy_r_r267;
    int32_t cpy_r_r268;
    char cpy_r_r269;
    PyObject *cpy_r_r270;
    int32_t cpy_r_r271;
    char cpy_r_r272;
    PyObject *cpy_r_r273;
    PyObject *cpy_r_r274;
    int32_t cpy_r_r275;
    char cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject *cpy_r_r278;
    int32_t cpy_r_r279;
    char cpy_r_r280;
    PyObject *cpy_r_r281;
    PyObject *cpy_r_r282;
    PyObject *cpy_r_r283;
    PyObject *cpy_r_r284;
    char cpy_r_r285;
    PyObject *cpy_r_r286;
    PyObject *cpy_r_r287;
    PyObject *cpy_r_r288;
    PyObject *cpy_r_r289;
    PyObject *cpy_r_r290;
    PyObject *cpy_r_r291;
    PyObject *cpy_r_r292;
    PyObject *cpy_r_r293;
    PyObject *cpy_r_r294;
    PyObject *cpy_r_r295;
    PyObject *cpy_r_r296;
    char cpy_r_r297;
    PyObject *cpy_r_r298;
    PyObject *cpy_r_r299;
    PyObject *cpy_r_r300;
    PyObject *cpy_r_r301;
    PyObject *cpy_r_r302;
    PyObject *cpy_r_r303;
    PyObject *cpy_r_r304;
    PyObject *cpy_r_r305;
    PyObject *cpy_r_r306;
    PyObject *cpy_r_r307;
    PyObject *cpy_r_r308;
    PyObject *cpy_r_r309;
    PyObject *cpy_r_r310;
    PyObject *cpy_r_r311;
    PyObject *cpy_r_r312;
    int32_t cpy_r_r313;
    char cpy_r_r314;
    PyObject *cpy_r_r315;
    PyObject *cpy_r_r316;
    int32_t cpy_r_r317;
    char cpy_r_r318;
    PyObject *cpy_r_r319;
    PyObject *cpy_r_r320;
    PyObject *cpy_r_r321;
    PyObject *cpy_r_r322;
    PyObject *cpy_r_r323;
    PyObject *cpy_r_r324;
    PyObject *cpy_r_r325;
    PyObject *cpy_r_r326;
    PyObject *cpy_r_r327;
    tuple_T2OO cpy_r_r328;
    PyObject *cpy_r_r329;
    PyObject *cpy_r_r330;
    PyObject *cpy_r_r331;
    PyObject *cpy_r_r332;
    PyObject *cpy_r_r333;
    PyObject *cpy_r_r334;
    char cpy_r_r335;
    PyObject *cpy_r_r336;
    PyObject *cpy_r_r337;
    PyObject *cpy_r_r338;
    PyObject *cpy_r_r339;
    PyObject *cpy_r_r340;
    PyObject *cpy_r_r341;
    PyObject *cpy_r_r342;
    PyObject *cpy_r_r343;
    int32_t cpy_r_r344;
    char cpy_r_r345;
    PyObject *cpy_r_r346;
    PyObject *cpy_r_r347;
    int32_t cpy_r_r348;
    char cpy_r_r349;
    char cpy_r_r350;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL122;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_asyncio;
    cpy_r_r6 = (PyObject **)&CPyModule_dataclasses;
    cpy_r_r7 = (PyObject **)&CPyModule_inspect;
    cpy_r_r8 = (PyObject **)&CPyModule_os;
    cpy_r_r9 = (PyObject **)&CPyModule_random;
    cpy_r_r10 = (PyObject **)&CPyModule_sys;
    PyObject **cpy_r_r11[6] = {cpy_r_r5, cpy_r_r6, cpy_r_r7, cpy_r_r8, cpy_r_r9, cpy_r_r10};
    cpy_r_r12 = (void *)&cpy_r_r11;
    int64_t cpy_r_r13[6] = {1, 2, 3, 4, 5, 6};
    cpy_r_r14 = (void *)&cpy_r_r13;
    cpy_r_r15 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* (('asyncio', 'asyncio', 'asyncio'),
                                    ('dataclasses', 'dataclasses', 'dataclasses'),
                                    ('inspect', 'inspect', 'inspect'), ('os', 'os', 'os'),
                                    ('random', 'random', 'random'), ('sys', 'sys', 'sys')) */
    cpy_r_r16 = CPyStatic_globals;
    cpy_r_r17 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru/__init__.py' */
    cpy_r_r18 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '<module>' */
    cpy_r_r19 = CPyImport_ImportMany(cpy_r_r15, cpy_r_r12, cpy_r_r16, cpy_r_r17, cpy_r_r18, cpy_r_r14);
    if (!cpy_r_r19) goto CPyL122;
    cpy_r_r20 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('_CacheInfo', '_make_key', 'partial', 'partialmethod') */
    cpy_r_r21 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'functools' */
    cpy_r_r22 = CPyStatic_globals;
    cpy_r_r23 = CPyImport_ImportFromMany(cpy_r_r21, cpy_r_r20, cpy_r_r20, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    CPyModule_functools = cpy_r_r23;
    CPy_INCREF(CPyModule_functools);
    CPy_DECREF(cpy_r_r23);
    cpy_r_r24 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('Any', 'Callable', 'Coroutine', 'Generic', 'Hashable',
                                    'List', 'Optional', 'OrderedDict', 'Type', 'TypedDict',
                                    'TypeVar', 'Union', 'cast', 'final', 'overload') */
    cpy_r_r25 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r26 = CPyStatic_globals;
    cpy_r_r27 = CPyImport_ImportFromMany(cpy_r_r25, cpy_r_r24, cpy_r_r24, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    CPyModule_typing = cpy_r_r27;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r27);
    cpy_r_r28 = CPyModule_sys;
    cpy_r_r29 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r30 = CPyObject_GetAttr(cpy_r_r28, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    if (likely(PyTuple_Check(cpy_r_r30)))
        cpy_r_r31 = cpy_r_r30;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "<module>", 27, CPyStatic_globals, "tuple", cpy_r_r30);
        goto CPyL122;
    }
    cpy_r_r32.f0 = 6;
    cpy_r_r32.f1 = 22;
    cpy_r_r33 = PyTuple_New(2);
    if (unlikely(cpy_r_r33 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp48 = CPyTagged_StealAsObject(cpy_r_r32.f0);
    PyTuple_SET_ITEM(cpy_r_r33, 0, __tmp48);
    PyObject *__tmp49 = CPyTagged_StealAsObject(cpy_r_r32.f1);
    PyTuple_SET_ITEM(cpy_r_r33, 1, __tmp49);
    cpy_r_r34 = PyObject_RichCompare(cpy_r_r31, cpy_r_r33, 5);
    CPy_DECREF(cpy_r_r31);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    if (unlikely(!PyBool_Check(cpy_r_r34))) {
        CPy_TypeError("bool", cpy_r_r34); cpy_r_r35 = 2;
    } else
        cpy_r_r35 = cpy_r_r34 == Py_True;
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    if (!cpy_r_r35) goto CPyL13;
    cpy_r_r36 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('Self',) */
    cpy_r_r37 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r38 = CPyStatic_globals;
    cpy_r_r39 = CPyImport_ImportFromMany(cpy_r_r37, cpy_r_r36, cpy_r_r36, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    CPyModule_typing = cpy_r_r39;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r39);
    goto CPyL15;
CPyL13: ;
    PyErr_SetString(PyExc_RuntimeError, "Reached allegedly unreachable code!");
    cpy_r_r40 = 0;
    if (unlikely(!cpy_r_r40)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    CPy_Unreachable();
CPyL15: ;
    cpy_r_r41 = CPyModule_sys;
    cpy_r_r42 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r43 = CPyObject_GetAttr(cpy_r_r41, cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    if (likely(PyTuple_Check(cpy_r_r43)))
        cpy_r_r44 = cpy_r_r43;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "<module>", 32, CPyStatic_globals, "tuple", cpy_r_r43);
        goto CPyL122;
    }
    cpy_r_r45.f0 = 6;
    cpy_r_r45.f1 = 28;
    cpy_r_r46 = PyTuple_New(2);
    if (unlikely(cpy_r_r46 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp50 = CPyTagged_StealAsObject(cpy_r_r45.f0);
    PyTuple_SET_ITEM(cpy_r_r46, 0, __tmp50);
    PyObject *__tmp51 = CPyTagged_StealAsObject(cpy_r_r45.f1);
    PyTuple_SET_ITEM(cpy_r_r46, 1, __tmp51);
    cpy_r_r47 = PyObject_RichCompare(cpy_r_r44, cpy_r_r46, 0);
    CPy_DECREF(cpy_r_r44);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    if (unlikely(!PyBool_Check(cpy_r_r47))) {
        CPy_TypeError("bool", cpy_r_r47); cpy_r_r48 = 2;
    } else
        cpy_r_r48 = cpy_r_r47 == Py_True;
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r48 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    if (!cpy_r_r48) goto CPyL22;
    PyErr_SetString(PyExc_RuntimeError, "Reached allegedly unreachable code!");
    cpy_r_r49 = 0;
    if (unlikely(!cpy_r_r49)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    CPy_Unreachable();
CPyL22: ;
    cpy_r_r50 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '2.1.0' */
    cpy_r_r51 = CPyStatic_globals;
    cpy_r_r52 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__version__' */
    cpy_r_r53 = CPyDict_SetItem(cpy_r_r51, cpy_r_r52, cpy_r_r50);
    cpy_r_r54 = cpy_r_r53 >= 0;
    if (unlikely(!cpy_r_r54)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r55 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'alru_cache' */
    CPy_INCREF(cpy_r_r55);
    cpy_r_r56.f0 = cpy_r_r55;
    cpy_r_r57 = CPyStatic_globals;
    cpy_r_r58 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__all__' */
    cpy_r_r59 = PyTuple_New(1);
    if (unlikely(cpy_r_r59 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp52 = cpy_r_r56.f0;
    PyTuple_SET_ITEM(cpy_r_r59, 0, __tmp52);
    cpy_r_r60 = CPyDict_SetItem(cpy_r_r57, cpy_r_r58, cpy_r_r59);
    CPy_DECREF(cpy_r_r59);
    cpy_r_r61 = cpy_r_r60 >= 0;
    if (unlikely(!cpy_r_r61)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r62 = CPyModule_os;
    cpy_r_r63 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'environ' */
    cpy_r_r64 = CPyObject_GetAttr(cpy_r_r62, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r65 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'ASYNC_LRU_ALLOW_SYNC' */
    cpy_r_r66 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'get' */
    PyObject *cpy_r_r67[2] = {cpy_r_r64, cpy_r_r65};
    cpy_r_r68 = (PyObject **)&cpy_r_r67;
    cpy_r_r69 = PyObject_VectorcallMethod(cpy_r_r66, cpy_r_r68, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL123;
    }
    CPy_DECREF(cpy_r_r64);
    if (PyUnicode_Check(cpy_r_r69))
        cpy_r_r70 = cpy_r_r69;
    else {
        cpy_r_r70 = NULL;
    }
    if (cpy_r_r70 != NULL) goto __LL53;
    if (cpy_r_r69 == Py_None)
        cpy_r_r70 = cpy_r_r69;
    else {
        cpy_r_r70 = NULL;
    }
    if (cpy_r_r70 != NULL) goto __LL53;
    CPy_TypeErrorTraceback("async_lru/__init__.py", "<module>", 40, CPyStatic_globals, "str or None", cpy_r_r69);
    goto CPyL122;
__LL53: ;
    cpy_r_r71 = CPyStatic_globals;
    cpy_r_r72 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'ALLOW_SYNC' */
    cpy_r_r73 = CPyDict_SetItem(cpy_r_r71, cpy_r_r72, cpy_r_r70);
    CPy_DECREF(cpy_r_r70);
    cpy_r_r74 = cpy_r_r73 >= 0;
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r75 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_T' */
    cpy_r_r76 = CPyStatic_globals;
    cpy_r_r77 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'TypeVar' */
    cpy_r_r78 = CPyDict_GetItem(cpy_r_r76, cpy_r_r77);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    PyObject *cpy_r_r79[1] = {cpy_r_r75};
    cpy_r_r80 = (PyObject **)&cpy_r_r79;
    cpy_r_r81 = PyObject_Vectorcall(cpy_r_r78, cpy_r_r80, 1, 0);
    CPy_DECREF(cpy_r_r78);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r82 = CPyStatic_globals;
    cpy_r_r83 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_T' */
    cpy_r_r84 = CPyDict_SetItem(cpy_r_r82, cpy_r_r83, cpy_r_r81);
    CPy_DECREF(cpy_r_r81);
    cpy_r_r85 = cpy_r_r84 >= 0;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r86 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r87 = CPyStatic_globals;
    cpy_r_r88 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'TypeVar' */
    cpy_r_r89 = CPyDict_GetItem(cpy_r_r87, cpy_r_r88);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    PyObject *cpy_r_r90[1] = {cpy_r_r86};
    cpy_r_r91 = (PyObject **)&cpy_r_r90;
    cpy_r_r92 = PyObject_Vectorcall(cpy_r_r89, cpy_r_r91, 1, 0);
    CPy_DECREF(cpy_r_r89);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r93 = CPyStatic_globals;
    cpy_r_r94 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r95 = CPyDict_SetItem(cpy_r_r93, cpy_r_r94, cpy_r_r92);
    CPy_DECREF(cpy_r_r92);
    cpy_r_r96 = cpy_r_r95 >= 0;
    if (unlikely(!cpy_r_r96)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r97 = CPyStatic_globals;
    cpy_r_r98 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Coroutine' */
    cpy_r_r99 = CPyDict_GetItem(cpy_r_r97, cpy_r_r98);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r100 = CPyStatic_globals;
    cpy_r_r101 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Any' */
    cpy_r_r102 = CPyDict_GetItem(cpy_r_r100, cpy_r_r101);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL124;
    }
    cpy_r_r103 = CPyStatic_globals;
    cpy_r_r104 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Any' */
    cpy_r_r105 = CPyDict_GetItem(cpy_r_r103, cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL125;
    }
    cpy_r_r106 = CPyStatic_globals;
    cpy_r_r107 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r108 = CPyDict_GetItem(cpy_r_r106, cpy_r_r107);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL126;
    }
    cpy_r_r109.f0 = cpy_r_r102;
    cpy_r_r109.f1 = cpy_r_r105;
    cpy_r_r109.f2 = cpy_r_r108;
    cpy_r_r110 = PyTuple_New(3);
    if (unlikely(cpy_r_r110 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp54 = cpy_r_r109.f0;
    PyTuple_SET_ITEM(cpy_r_r110, 0, __tmp54);
    PyObject *__tmp55 = cpy_r_r109.f1;
    PyTuple_SET_ITEM(cpy_r_r110, 1, __tmp55);
    PyObject *__tmp56 = cpy_r_r109.f2;
    PyTuple_SET_ITEM(cpy_r_r110, 2, __tmp56);
    cpy_r_r111 = PyObject_GetItem(cpy_r_r99, cpy_r_r110);
    CPy_DECREF(cpy_r_r99);
    CPy_DECREF(cpy_r_r110);
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r112 = CPyStatic_globals;
    cpy_r_r113 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_Coro' */
    cpy_r_r114 = CPyDict_SetItem(cpy_r_r112, cpy_r_r113, cpy_r_r111);
    CPy_DECREF(cpy_r_r111);
    cpy_r_r115 = cpy_r_r114 >= 0;
    if (unlikely(!cpy_r_r115)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r116 = CPyStatic_globals;
    cpy_r_r117 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Callable' */
    cpy_r_r118 = CPyDict_GetItem(cpy_r_r116, cpy_r_r117);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r119 = (PyObject *)&_Py_EllipsisObject;
    cpy_r_r120 = CPyStatic_globals;
    cpy_r_r121 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_Coro' */
    cpy_r_r122 = CPyDict_GetItem(cpy_r_r120, cpy_r_r121);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL127;
    }
    cpy_r_r123 = CPyStatic_globals;
    cpy_r_r124 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r125 = CPyDict_GetItem(cpy_r_r123, cpy_r_r124);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL128;
    }
    cpy_r_r126 = PyObject_GetItem(cpy_r_r122, cpy_r_r125);
    CPy_DECREF(cpy_r_r122);
    CPy_DECREF(cpy_r_r125);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL127;
    }
    CPy_INCREF(cpy_r_r119);
    cpy_r_r127.f0 = cpy_r_r119;
    cpy_r_r127.f1 = cpy_r_r126;
    cpy_r_r128 = PyTuple_New(2);
    if (unlikely(cpy_r_r128 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp57 = cpy_r_r127.f0;
    PyTuple_SET_ITEM(cpy_r_r128, 0, __tmp57);
    PyObject *__tmp58 = cpy_r_r127.f1;
    PyTuple_SET_ITEM(cpy_r_r128, 1, __tmp58);
    cpy_r_r129 = PyObject_GetItem(cpy_r_r118, cpy_r_r128);
    CPy_DECREF(cpy_r_r118);
    CPy_DECREF(cpy_r_r128);
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r130 = CPyStatic_globals;
    cpy_r_r131 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CB' */
    cpy_r_r132 = CPyDict_SetItem(cpy_r_r130, cpy_r_r131, cpy_r_r129);
    CPy_DECREF(cpy_r_r129);
    cpy_r_r133 = cpy_r_r132 >= 0;
    if (unlikely(!cpy_r_r133)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r134 = CPyStatic_globals;
    cpy_r_r135 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Union' */
    cpy_r_r136 = CPyDict_GetItem(cpy_r_r134, cpy_r_r135);
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r137 = CPyStatic_globals;
    cpy_r_r138 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CB' */
    cpy_r_r139 = CPyDict_GetItem(cpy_r_r137, cpy_r_r138);
    if (unlikely(cpy_r_r139 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL129;
    }
    cpy_r_r140 = CPyStatic_globals;
    cpy_r_r141 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r142 = CPyDict_GetItem(cpy_r_r140, cpy_r_r141);
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL130;
    }
    cpy_r_r143 = PyObject_GetItem(cpy_r_r139, cpy_r_r142);
    CPy_DECREF(cpy_r_r139);
    CPy_DECREF(cpy_r_r142);
    if (unlikely(cpy_r_r143 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL129;
    }
    cpy_r_r144 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partial[_Coro[_R]]' */
    cpy_r_r145 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partialmethod[_Coro[_R]]' */
    CPy_INCREF(cpy_r_r144);
    CPy_INCREF(cpy_r_r145);
    cpy_r_r146.f0 = cpy_r_r143;
    cpy_r_r146.f1 = cpy_r_r144;
    cpy_r_r146.f2 = cpy_r_r145;
    cpy_r_r147 = PyTuple_New(3);
    if (unlikely(cpy_r_r147 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp59 = cpy_r_r146.f0;
    PyTuple_SET_ITEM(cpy_r_r147, 0, __tmp59);
    PyObject *__tmp60 = cpy_r_r146.f1;
    PyTuple_SET_ITEM(cpy_r_r147, 1, __tmp60);
    PyObject *__tmp61 = cpy_r_r146.f2;
    PyTuple_SET_ITEM(cpy_r_r147, 2, __tmp61);
    cpy_r_r148 = PyObject_GetItem(cpy_r_r136, cpy_r_r147);
    CPy_DECREF(cpy_r_r136);
    CPy_DECREF(cpy_r_r147);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r149 = CPyStatic_globals;
    cpy_r_r150 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CBP' */
    cpy_r_r151 = CPyDict_SetItem(cpy_r_r149, cpy_r_r150, cpy_r_r148);
    CPy_DECREF(cpy_r_r148);
    cpy_r_r152 = cpy_r_r151 >= 0;
    if (unlikely(!cpy_r_r152)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r153 = CPyModule_typing;
    cpy_r_r154 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r155 = cpy_r_r153 != cpy_r_r154;
    if (cpy_r_r155) goto CPyL55;
    cpy_r_r156 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r157 = PyImport_Import(cpy_r_r156);
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    CPyModule_typing = cpy_r_r157;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r157);
CPyL55: ;
    cpy_r_r158 = PyImport_GetModuleDict();
    cpy_r_r159 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r160 = CPyDict_GetItem(cpy_r_r158, cpy_r_r159);
    if (unlikely(cpy_r_r160 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r161 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_TypedDict' */
    cpy_r_r162 = CPyObject_GetAttr(cpy_r_r160, cpy_r_r161);
    CPy_DECREF(cpy_r_r160);
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r163 = PyTuple_Pack(1, cpy_r_r162);
    CPy_DECREF(cpy_r_r162);
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r164 = CPyModule_typing;
    cpy_r_r165 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r166 = cpy_r_r164 != cpy_r_r165;
    if (cpy_r_r166) goto CPyL61;
    cpy_r_r167 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r168 = PyImport_Import(cpy_r_r167);
    if (unlikely(cpy_r_r168 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL131;
    }
    CPyModule_typing = cpy_r_r168;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r168);
CPyL61: ;
    cpy_r_r169 = PyImport_GetModuleDict();
    cpy_r_r170 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r171 = CPyDict_GetItem(cpy_r_r169, cpy_r_r170);
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL131;
    }
    cpy_r_r172 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_TypedDictMeta' */
    cpy_r_r173 = CPyObject_GetAttr(cpy_r_r171, cpy_r_r172);
    CPy_DECREF(cpy_r_r171);
    if (unlikely(cpy_r_r173 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL131;
    }
    cpy_r_r174 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__prepare__' */
    cpy_r_r175 = PyObject_HasAttr(cpy_r_r173, cpy_r_r174);
    if (!cpy_r_r175) goto CPyL68;
    cpy_r_r176 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheParameters' */
    cpy_r_r177 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__prepare__' */
    cpy_r_r178 = CPyObject_GetAttr(cpy_r_r173, cpy_r_r177);
    if (unlikely(cpy_r_r178 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL132;
    }
    PyObject *cpy_r_r179[2] = {cpy_r_r176, cpy_r_r163};
    cpy_r_r180 = (PyObject **)&cpy_r_r179;
    cpy_r_r181 = PyObject_Vectorcall(cpy_r_r178, cpy_r_r180, 2, 0);
    CPy_DECREF(cpy_r_r178);
    if (unlikely(cpy_r_r181 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL132;
    }
    if (likely(PyDict_Check(cpy_r_r181)))
        cpy_r_r182 = cpy_r_r181;
    else {
        CPy_TypeErrorTraceback("async_lru/__init__.py", "<module>", 52, CPyStatic_globals, "dict", cpy_r_r181);
        goto CPyL132;
    }
    cpy_r_r183 = cpy_r_r182;
    goto CPyL70;
CPyL68: ;
    cpy_r_r184 = PyDict_New();
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL132;
    }
    cpy_r_r183 = cpy_r_r184;
CPyL70: ;
    cpy_r_r185 = PyDict_New();
    if (unlikely(cpy_r_r185 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL133;
    }
    cpy_r_r186 = (PyObject *)&PyBool_Type;
    cpy_r_r187 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typed' */
    cpy_r_r188 = PyDict_SetItem(cpy_r_r185, cpy_r_r187, cpy_r_r186);
    cpy_r_r189 = cpy_r_r188 >= 0;
    if (unlikely(!cpy_r_r189)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL134;
    }
    cpy_r_r190 = (PyObject *)&PyType_Type;
    cpy_r_r191 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'maxsize' */
    cpy_r_r192 = PyDict_SetItem(cpy_r_r185, cpy_r_r191, cpy_r_r190);
    cpy_r_r193 = cpy_r_r192 >= 0;
    if (unlikely(!cpy_r_r193)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL134;
    }
    cpy_r_r194 = (PyObject *)&PyLong_Type;
    cpy_r_r195 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'tasks' */
    cpy_r_r196 = PyDict_SetItem(cpy_r_r185, cpy_r_r195, cpy_r_r194);
    cpy_r_r197 = cpy_r_r196 >= 0;
    if (unlikely(!cpy_r_r197)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL134;
    }
    cpy_r_r198 = (PyObject *)&PyBool_Type;
    cpy_r_r199 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'closed' */
    cpy_r_r200 = PyDict_SetItem(cpy_r_r185, cpy_r_r199, cpy_r_r198);
    cpy_r_r201 = cpy_r_r200 >= 0;
    if (unlikely(!cpy_r_r201)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL134;
    }
    cpy_r_r202 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheParameters' */
    cpy_r_r203 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r204 = CPyDict_SetItem(cpy_r_r183, cpy_r_r203, cpy_r_r185);
    CPy_DECREF(cpy_r_r185);
    cpy_r_r205 = cpy_r_r204 >= 0;
    if (unlikely(!cpy_r_r205)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL133;
    }
    cpy_r_r206 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'mypyc filler docstring' */
    cpy_r_r207 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r208 = CPyDict_SetItem(cpy_r_r183, cpy_r_r207, cpy_r_r206);
    cpy_r_r209 = cpy_r_r208 >= 0;
    if (unlikely(!cpy_r_r209)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL133;
    }
    cpy_r_r210 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru' */
    cpy_r_r211 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r212 = CPyDict_SetItem(cpy_r_r183, cpy_r_r211, cpy_r_r210);
    cpy_r_r213 = cpy_r_r212 >= 0;
    if (unlikely(!cpy_r_r213)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL133;
    }
    PyObject *cpy_r_r214[3] = {cpy_r_r202, cpy_r_r163, cpy_r_r183};
    cpy_r_r215 = (PyObject **)&cpy_r_r214;
    cpy_r_r216 = PyObject_Vectorcall(cpy_r_r173, cpy_r_r215, 3, 0);
    CPy_DECREF(cpy_r_r173);
    if (unlikely(cpy_r_r216 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL135;
    }
    CPy_DECREF(cpy_r_r163);
    CPy_DECREF(cpy_r_r183);
    cpy_r_r217 = CPyStatic_globals;
    cpy_r_r218 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'final' */
    cpy_r_r219 = CPyDict_GetItem(cpy_r_r217, cpy_r_r218);
    if (unlikely(cpy_r_r219 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL136;
    }
    PyObject *cpy_r_r220[1] = {cpy_r_r216};
    cpy_r_r221 = (PyObject **)&cpy_r_r220;
    cpy_r_r222 = PyObject_Vectorcall(cpy_r_r219, cpy_r_r221, 1, 0);
    CPy_DECREF(cpy_r_r219);
    if (unlikely(cpy_r_r222 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL136;
    }
    CPy_DECREF(cpy_r_r216);
    CPyType__CacheParameters = (PyTypeObject *)cpy_r_r222;
    CPy_INCREF(CPyType__CacheParameters);
    cpy_r_r223 = CPyStatic_globals;
    cpy_r_r224 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheParameters' */
    cpy_r_r225 = PyDict_SetItem(cpy_r_r223, cpy_r_r224, cpy_r_r222);
    CPy_DECREF(cpy_r_r222);
    cpy_r_r226 = cpy_r_r225 >= 0;
    if (unlikely(!cpy_r_r226)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r227 = (PyObject *)CPyType__CacheParameters;
    cpy_r_r228 = CPyStatic_globals;
    cpy_r_r229 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Generic' */
    cpy_r_r230 = CPyDict_GetItem(cpy_r_r228, cpy_r_r229);
    if (unlikely(cpy_r_r230 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r231 = CPyStatic_globals;
    cpy_r_r232 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r233 = CPyDict_GetItem(cpy_r_r231, cpy_r_r232);
    if (unlikely(cpy_r_r233 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL137;
    }
    cpy_r_r234 = PyObject_GetItem(cpy_r_r230, cpy_r_r233);
    CPy_DECREF(cpy_r_r230);
    CPy_DECREF(cpy_r_r233);
    if (unlikely(cpy_r_r234 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r235 = PyTuple_Pack(1, cpy_r_r234);
    CPy_DECREF(cpy_r_r234);
    if (unlikely(cpy_r_r235 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r236 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru' */
    cpy_r_r237 = (PyObject *)CPyType__CacheItem_template;
    cpy_r_r238 = CPyType_FromTemplate(cpy_r_r237, cpy_r_r235, cpy_r_r236);
    CPy_DECREF(cpy_r_r235);
    if (unlikely(cpy_r_r238 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r239 = CPyDef__CacheItem_trait_vtable_setup();
    if (unlikely(cpy_r_r239 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL138;
    }
    cpy_r_r240 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__mypyc_attrs__' */
    cpy_r_r241 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'task' */
    cpy_r_r242 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'later_call' */
    cpy_r_r243 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'waiters' */
    cpy_r_r244 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r245 = PyTuple_Pack(4, cpy_r_r241, cpy_r_r242, cpy_r_r243, cpy_r_r244);
    if (unlikely(cpy_r_r245 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL138;
    }
    cpy_r_r246 = PyObject_SetAttr(cpy_r_r238, cpy_r_r240, cpy_r_r245);
    CPy_DECREF(cpy_r_r245);
    cpy_r_r247 = cpy_r_r246 >= 0;
    if (unlikely(!cpy_r_r247)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL138;
    }
    CPyType__CacheItem = (PyTypeObject *)cpy_r_r238;
    CPy_INCREF(CPyType__CacheItem);
    cpy_r_r248 = CPyStatic_globals;
    cpy_r_r249 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheItem' */
    cpy_r_r250 = PyDict_SetItem(cpy_r_r248, cpy_r_r249, cpy_r_r238);
    cpy_r_r251 = cpy_r_r250 >= 0;
    if (unlikely(!cpy_r_r251)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL138;
    }
    cpy_r_r252 = PyDict_New();
    if (unlikely(cpy_r_r252 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL138;
    }
    cpy_r_r253.empty_struct_error_flag = 0;
    cpy_r_r254 = PyDict_New();
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL139;
    }
    cpy_r_r255 = (PyObject *)&PyType_Type;
    cpy_r_r256 = CPyModule_asyncio;
    cpy_r_r257 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Task' */
    cpy_r_r258 = CPyObject_GetAttr(cpy_r_r256, cpy_r_r257);
    if (unlikely(cpy_r_r258 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL140;
    }
    cpy_r_r259 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'task' */
    cpy_r_r260 = PyDict_SetItem(cpy_r_r254, cpy_r_r259, cpy_r_r258);
    CPy_DECREF(cpy_r_r258);
    cpy_r_r261 = cpy_r_r260 >= 0;
    if (unlikely(!cpy_r_r261)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL140;
    }
    cpy_r_r262 = (PyObject *)&PyType_Type;
    cpy_r_r263 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'later_call' */
    cpy_r_r264 = PyDict_SetItem(cpy_r_r254, cpy_r_r263, cpy_r_r262);
    cpy_r_r265 = cpy_r_r264 >= 0;
    if (unlikely(!cpy_r_r265)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL140;
    }
    cpy_r_r266 = (PyObject *)&PyLong_Type;
    cpy_r_r267 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'waiters' */
    cpy_r_r268 = PyDict_SetItem(cpy_r_r254, cpy_r_r267, cpy_r_r266);
    cpy_r_r269 = cpy_r_r268 >= 0;
    if (unlikely(!cpy_r_r269)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL140;
    }
    cpy_r_r270 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r271 = CPyDict_SetItem(cpy_r_r252, cpy_r_r270, cpy_r_r254);
    cpy_r_r272 = cpy_r_r271 >= 0;
    if (unlikely(!cpy_r_r272)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL140;
    }
    cpy_r_r273 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'mypyc filler docstring' */
    cpy_r_r274 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r275 = CPyDict_SetItem(cpy_r_r252, cpy_r_r274, cpy_r_r273);
    cpy_r_r276 = cpy_r_r275 >= 0;
    if (unlikely(!cpy_r_r276)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL140;
    }
    cpy_r_r277 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru' */
    cpy_r_r278 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r279 = CPyDict_SetItem(cpy_r_r252, cpy_r_r278, cpy_r_r277);
    cpy_r_r280 = cpy_r_r279 >= 0;
    if (unlikely(!cpy_r_r280)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL140;
    }
    cpy_r_r281 = CPyModule_dataclasses;
    cpy_r_r282 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'dataclass' */
    cpy_r_r283 = CPyObject_GetAttr(cpy_r_r281, cpy_r_r282);
    if (unlikely(cpy_r_r283 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL140;
    }
    cpy_r_r284 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'dataclasses' */
    cpy_r_r285 = CPyDataclass_SleightOfHand(cpy_r_r283, cpy_r_r238, cpy_r_r252, cpy_r_r254, cpy_r_r284);
    CPy_DECREF(cpy_r_r283);
    CPy_DECREF(cpy_r_r238);
    CPy_DECREF(cpy_r_r252);
    CPy_DECREF(cpy_r_r254);
    if (unlikely(!cpy_r_r285)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r286 = CPyStatic_globals;
    cpy_r_r287 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Generic' */
    cpy_r_r288 = CPyDict_GetItem(cpy_r_r286, cpy_r_r287);
    if (unlikely(cpy_r_r288 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r289 = CPyStatic_globals;
    cpy_r_r290 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r291 = CPyDict_GetItem(cpy_r_r289, cpy_r_r290);
    if (unlikely(cpy_r_r291 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL141;
    }
    cpy_r_r292 = PyObject_GetItem(cpy_r_r288, cpy_r_r291);
    CPy_DECREF(cpy_r_r288);
    CPy_DECREF(cpy_r_r291);
    if (unlikely(cpy_r_r292 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r293 = PyTuple_Pack(1, cpy_r_r292);
    CPy_DECREF(cpy_r_r292);
    if (unlikely(cpy_r_r293 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r294 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru' */
    cpy_r_r295 = (PyObject *)CPyType__LRUCacheWrapper_template;
    cpy_r_r296 = CPyType_FromTemplate(cpy_r_r295, cpy_r_r293, cpy_r_r294);
    CPy_DECREF(cpy_r_r293);
    if (unlikely(cpy_r_r296 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r297 = CPyDef__LRUCacheWrapper_trait_vtable_setup();
    if (unlikely(cpy_r_r297 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL142;
    }
    cpy_r_r298 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__mypyc_attrs__' */
    cpy_r_r299 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__name__' */
    cpy_r_r300 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__qualname__' */
    cpy_r_r301 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapped__' */
    cpy_r_r302 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__maxsize' */
    cpy_r_r303 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__typed' */
    cpy_r_r304 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__ttl' */
    cpy_r_r305 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__jitter' */
    cpy_r_r306 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__cache' */
    cpy_r_r307 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__closed' */
    cpy_r_r308 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__hits' */
    cpy_r_r309 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__misses' */
    cpy_r_r310 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__first_loop' */
    cpy_r_r311 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r312 = PyTuple_Pack(13, cpy_r_r299, cpy_r_r300, cpy_r_r301, cpy_r_r302, cpy_r_r303, cpy_r_r304, cpy_r_r305, cpy_r_r306, cpy_r_r307, cpy_r_r308, cpy_r_r309, cpy_r_r310, cpy_r_r311);
    if (unlikely(cpy_r_r312 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL142;
    }
    cpy_r_r313 = PyObject_SetAttr(cpy_r_r296, cpy_r_r298, cpy_r_r312);
    CPy_DECREF(cpy_r_r312);
    cpy_r_r314 = cpy_r_r313 >= 0;
    if (unlikely(!cpy_r_r314)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL142;
    }
    CPyType__LRUCacheWrapper = (PyTypeObject *)cpy_r_r296;
    CPy_INCREF(CPyType__LRUCacheWrapper);
    cpy_r_r315 = CPyStatic_globals;
    cpy_r_r316 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_LRUCacheWrapper' */
    cpy_r_r317 = PyDict_SetItem(cpy_r_r315, cpy_r_r316, cpy_r_r296);
    CPy_DECREF(cpy_r_r296);
    cpy_r_r318 = cpy_r_r317 >= 0;
    if (unlikely(!cpy_r_r318)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r319 = CPyStatic_globals;
    cpy_r_r320 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Generic' */
    cpy_r_r321 = CPyDict_GetItem(cpy_r_r319, cpy_r_r320);
    if (unlikely(cpy_r_r321 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r322 = CPyStatic_globals;
    cpy_r_r323 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r324 = CPyDict_GetItem(cpy_r_r322, cpy_r_r323);
    if (unlikely(cpy_r_r324 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL143;
    }
    cpy_r_r325 = CPyStatic_globals;
    cpy_r_r326 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_T' */
    cpy_r_r327 = CPyDict_GetItem(cpy_r_r325, cpy_r_r326);
    if (unlikely(cpy_r_r327 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL144;
    }
    cpy_r_r328.f0 = cpy_r_r324;
    cpy_r_r328.f1 = cpy_r_r327;
    cpy_r_r329 = PyTuple_New(2);
    if (unlikely(cpy_r_r329 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp62 = cpy_r_r328.f0;
    PyTuple_SET_ITEM(cpy_r_r329, 0, __tmp62);
    PyObject *__tmp63 = cpy_r_r328.f1;
    PyTuple_SET_ITEM(cpy_r_r329, 1, __tmp63);
    cpy_r_r330 = PyObject_GetItem(cpy_r_r321, cpy_r_r329);
    CPy_DECREF(cpy_r_r321);
    CPy_DECREF(cpy_r_r329);
    if (unlikely(cpy_r_r330 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r331 = PyTuple_Pack(1, cpy_r_r330);
    CPy_DECREF(cpy_r_r330);
    if (unlikely(cpy_r_r331 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r332 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'async_lru' */
    cpy_r_r333 = (PyObject *)CPyType__LRUCacheWrapperInstanceMethod_template;
    cpy_r_r334 = CPyType_FromTemplate(cpy_r_r333, cpy_r_r331, cpy_r_r332);
    CPy_DECREF(cpy_r_r331);
    if (unlikely(cpy_r_r334 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r335 = CPyDef__LRUCacheWrapperInstanceMethod_trait_vtable_setup();
    if (unlikely(cpy_r_r335 == 2)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL145;
    }
    cpy_r_r336 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__mypyc_attrs__' */
    cpy_r_r337 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__name__' */
    cpy_r_r338 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__qualname__' */
    cpy_r_r339 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapped__' */
    cpy_r_r340 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__instance' */
    cpy_r_r341 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapper' */
    cpy_r_r342 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r343 = PyTuple_Pack(6, cpy_r_r337, cpy_r_r338, cpy_r_r339, cpy_r_r340, cpy_r_r341, cpy_r_r342);
    if (unlikely(cpy_r_r343 == NULL)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL145;
    }
    cpy_r_r344 = PyObject_SetAttr(cpy_r_r334, cpy_r_r336, cpy_r_r343);
    CPy_DECREF(cpy_r_r343);
    cpy_r_r345 = cpy_r_r344 >= 0;
    if (unlikely(!cpy_r_r345)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL145;
    }
    CPyType__LRUCacheWrapperInstanceMethod = (PyTypeObject *)cpy_r_r334;
    CPy_INCREF(CPyType__LRUCacheWrapperInstanceMethod);
    cpy_r_r346 = CPyStatic_globals;
    cpy_r_r347 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_LRUCacheWrapperInstanceMethod' */
    cpy_r_r348 = PyDict_SetItem(cpy_r_r346, cpy_r_r347, cpy_r_r334);
    CPy_DECREF(cpy_r_r334);
    cpy_r_r349 = cpy_r_r348 >= 0;
    if (unlikely(!cpy_r_r349)) {
        CPy_AddTraceback("async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL122;
    }
    return 1;
CPyL122: ;
    cpy_r_r350 = 2;
    return cpy_r_r350;
CPyL123: ;
    CPy_DecRef(cpy_r_r64);
    goto CPyL122;
CPyL124: ;
    CPy_DecRef(cpy_r_r99);
    goto CPyL122;
CPyL125: ;
    CPy_DecRef(cpy_r_r99);
    CPy_DecRef(cpy_r_r102);
    goto CPyL122;
CPyL126: ;
    CPy_DecRef(cpy_r_r99);
    CPy_DecRef(cpy_r_r102);
    CPy_DecRef(cpy_r_r105);
    goto CPyL122;
CPyL127: ;
    CPy_DecRef(cpy_r_r118);
    goto CPyL122;
CPyL128: ;
    CPy_DecRef(cpy_r_r118);
    CPy_DecRef(cpy_r_r122);
    goto CPyL122;
CPyL129: ;
    CPy_DecRef(cpy_r_r136);
    goto CPyL122;
CPyL130: ;
    CPy_DecRef(cpy_r_r136);
    CPy_DecRef(cpy_r_r139);
    goto CPyL122;
CPyL131: ;
    CPy_DecRef(cpy_r_r163);
    goto CPyL122;
CPyL132: ;
    CPy_DecRef(cpy_r_r163);
    CPy_DecRef(cpy_r_r173);
    goto CPyL122;
CPyL133: ;
    CPy_DecRef(cpy_r_r163);
    CPy_DecRef(cpy_r_r173);
    CPy_DecRef(cpy_r_r183);
    goto CPyL122;
CPyL134: ;
    CPy_DecRef(cpy_r_r163);
    CPy_DecRef(cpy_r_r173);
    CPy_DecRef(cpy_r_r183);
    CPy_DecRef(cpy_r_r185);
    goto CPyL122;
CPyL135: ;
    CPy_DecRef(cpy_r_r163);
    CPy_DecRef(cpy_r_r183);
    goto CPyL122;
CPyL136: ;
    CPy_DecRef(cpy_r_r216);
    goto CPyL122;
CPyL137: ;
    CPy_DecRef(cpy_r_r230);
    goto CPyL122;
CPyL138: ;
    CPy_DecRef(cpy_r_r238);
    goto CPyL122;
CPyL139: ;
    CPy_DecRef(cpy_r_r238);
    CPy_DecRef(cpy_r_r252);
    goto CPyL122;
CPyL140: ;
    CPy_DecRef(cpy_r_r238);
    CPy_DecRef(cpy_r_r252);
    CPy_DecRef(cpy_r_r254);
    goto CPyL122;
CPyL141: ;
    CPy_DecRef(cpy_r_r288);
    goto CPyL122;
CPyL142: ;
    CPy_DecRef(cpy_r_r296);
    goto CPyL122;
CPyL143: ;
    CPy_DecRef(cpy_r_r321);
    goto CPyL122;
CPyL144: ;
    CPy_DecRef(cpy_r_r321);
    CPy_DecRef(cpy_r_r324);
    goto CPyL122;
CPyL145: ;
    CPy_DecRef(cpy_r_r334);
    goto CPyL122;
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
    CPyModule_inspect = Py_None;
    CPyModule_os = Py_None;
    CPyModule_random = Py_None;
    CPyModule_sys = Py_None;
    CPyModule_functools = Py_None;
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
    "\006\fRuntimeError\t_make_key\003pop\020get_running_loop\006gather\021return_exceptions",
    "\006\rGeneratorExit\rStopIteration\n_CacheInfo\020_CacheParameters\amaxsize\005typed",
    "\a\005tasks\006closed\vmove_to_end\tcancelled\n_exception\auniform\ncall_later",
    "\005\006shield\016CancelledError\031alru_cache is closed for \006result\v__wrapped__",
    "\005\vcreate_task\023_task_done_callback\apartial\021add_done_callback\apopitem",
    "\005\004last\020cache_invalidate\t__wrapper\rpartialmethod\004func",
    "\004\023iscoroutinefunction\nALLOW_SYNC\000$Coroutine function is required, got ",
    "\004\a{!r:{}}\006format\024_make_unbound_method\025markcoroutinefunction",
    "\003\035jitter requires ttl to be set\nValueError\033jitter must be non-negative",
    "\004\bcallable\034 decorating is not supported\023NotImplementedError\bbuiltins",
    "\a\aasyncio\vdataclasses\ainspect\002os\006random\003sys\025async_lru/__init__.py",
    "\b\b<module>\tfunctools\003Any\bCallable\tCoroutine\aGeneric\bHashable\004List",
    "\n\bOptional\004Type\tTypedDict\aTypeVar\005Union\004cast\005final\boverload\006typing\004Self",
    "\a\0052.1.0\v__version__\nalru_cache\a__all__\aenviron\024ASYNC_LRU_ALLOW_SYNC\003get",
    "\a\002_T\002_R\005_Coro\003_CB\022partial[_Coro[_R]]\030partialmethod[_Coro[_R]]\004_CBP",
    "\004\n_TypedDict\016_TypedDictMeta\v__prepare__\026mypyc filler docstring",
    "\a\tasync_lru\017__mypyc_attrs__\004task\nlater_call\awaiters\n_CacheItem\004Task",
    "\b\tdataclass\b__name__\t__maxsize\a__typed\005__ttl\b__jitter\a__cache\b__closed",
    "\005\006__hits\b__misses\f__first_loop\020_LRUCacheWrapper\n__instance",
    "\001\036_LRUCacheWrapperInstanceMethod",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0030\0001\000128",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    12, 4, 24, 25, 26, 27, 1, 43, 3, 63, 63, 63, 3, 64, 64, 64, 3, 65,
    65, 65, 3, 66, 66, 66, 3, 67, 67, 67, 3, 68, 68, 68, 6, 132, 133, 134,
    135, 136, 137, 4, 22, 15, 40, 46, 15, 72, 73, 74, 75, 76, 77, 78, 11,
    79, 80, 81, 82, 83, 84, 85, 1, 87
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_async_lru__internal = NULL;
CPyModule *CPyModule_async_lru;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_asyncio;
CPyModule *CPyModule_dataclasses;
CPyModule *CPyModule_inspect;
CPyModule *CPyModule_os;
CPyModule *CPyModule_random;
CPyModule *CPyModule_sys;
CPyModule *CPyModule_functools;
CPyModule *CPyModule_typing;
PyTypeObject *CPyType__CacheParameters;
PyTypeObject *CPyType__CacheItem;
PyObject *CPyDef__CacheItem(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
PyTypeObject *CPyType__LRUCacheWrapper;
PyObject *CPyDef__LRUCacheWrapper(PyObject *cpy_r_fn, PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl, PyObject *cpy_r_jitter);
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
char CPyDef__LRUCacheWrapper_____init__(PyObject *cpy_r_self, PyObject *cpy_r_fn, PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl, PyObject *cpy_r_jitter);
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
PyObject *CPyDef__make_wrapper(PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl, PyObject *cpy_r_jitter);
PyObject *CPyPy__make_wrapper(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_alru_cache(PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl, PyObject *cpy_r_jitter);
PyObject *CPyPy_alru_cache(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
