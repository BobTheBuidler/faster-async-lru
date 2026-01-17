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

static int
_CacheItem_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
PyObject *CPyDef___mypyc___3_CacheItem_setup(PyObject *cpy_r_type);
PyObject *CPyDef__CacheItem(PyObject *cpy_r_task);

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
    PyObject *ret = CPyPy__CacheItem_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
_CacheItem_traverse(faster_async_lru____CacheItemObject *self, visitproc visit, void *arg)
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
_CacheItem_clear(faster_async_lru____CacheItemObject *self)
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
_CacheItem_dealloc(faster_async_lru____CacheItemObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _CacheItem_dealloc)
    _CacheItem_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem _CacheItem_vtable[2];
static bool
CPyDef__CacheItem_trait_vtable_setup(void)
{
    CPyVTableItem _CacheItem_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__CacheItem_____init__,
        (CPyVTableItem)CPyDef__CacheItem___cancel,
    };
    memcpy(_CacheItem_vtable, _CacheItem_vtable_scratch, sizeof(_CacheItem_vtable));
    return 1;
}

static PyObject *
_CacheItem_get_task(faster_async_lru____CacheItemObject *self, void *closure);
static int
_CacheItem_set_task(faster_async_lru____CacheItemObject *self, PyObject *value, void *closure);
static PyObject *
_CacheItem_get_later_call(faster_async_lru____CacheItemObject *self, void *closure);
static int
_CacheItem_set_later_call(faster_async_lru____CacheItemObject *self, PyObject *value, void *closure);
static PyObject *
_CacheItem_get_waiters(faster_async_lru____CacheItemObject *self, void *closure);
static int
_CacheItem_set_waiters(faster_async_lru____CacheItemObject *self, PyObject *value, void *closure);

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
    {"__init__",
     (PyCFunction)CPyPy__CacheItem_____init__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__init__($self, task)\n--\n\n")},
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
    .tp_init = _CacheItem_init,
    .tp_basicsize = sizeof(faster_async_lru____CacheItemObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("_CacheItem(task)\n--\n\n"),
};
static PyTypeObject *CPyType__CacheItem_template = &CPyType__CacheItem_template_;

PyObject *CPyDef___mypyc___3_CacheItem_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    faster_async_lru____CacheItemObject *self;
    self = (faster_async_lru____CacheItemObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _CacheItem_vtable;
    self->_waiters = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef__CacheItem(PyObject *cpy_r_task)
{
    PyObject *self = CPyDef___mypyc___3_CacheItem_setup((PyObject *)CPyType__CacheItem);
    if (self == NULL)
        return NULL;
    char res = CPyDef__CacheItem_____init__(self, cpy_r_task);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
_CacheItem_get_task(faster_async_lru____CacheItemObject *self, void *closure)
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
_CacheItem_set_task(faster_async_lru____CacheItemObject *self, PyObject *value, void *closure)
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
_CacheItem_get_later_call(faster_async_lru____CacheItemObject *self, void *closure)
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
_CacheItem_set_later_call(faster_async_lru____CacheItemObject *self, PyObject *value, void *closure)
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
_CacheItem_get_waiters(faster_async_lru____CacheItemObject *self, void *closure)
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
_CacheItem_set_waiters(faster_async_lru____CacheItemObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_traverse(faster_async_lru____LRUCacheWrapperObject *self, visitproc visit, void *arg)
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
    Py_VISIT(self->__is_coroutine);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
_LRUCacheWrapper_clear(faster_async_lru____LRUCacheWrapperObject *self)
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
    Py_CLEAR(self->__is_coroutine);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
_LRUCacheWrapper_dealloc(faster_async_lru____LRUCacheWrapperObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _LRUCacheWrapper_dealloc)
    _LRUCacheWrapper_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem _LRUCacheWrapper_vtable[13];
static bool
CPyDef__LRUCacheWrapper_trait_vtable_setup(void)
{
    CPyVTableItem _LRUCacheWrapper_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__LRUCacheWrapper_____init__,
        (CPyVTableItem)CPyDef__LRUCacheWrapper_____tasks,
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
_LRUCacheWrapper_get___3_module__(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_module__(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_name__(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_name__(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_qualname__(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_qualname__(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_doc__(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_doc__(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_annotations__(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_annotations__(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_wrapped__(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_wrapped__(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_maxsize(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_maxsize(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_typed(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_typed(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_ttl(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_ttl(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_cache(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_cache(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_closed(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_closed(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_hits(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_hits(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_misses(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set___3_misses(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get__is_coroutine(faster_async_lru____LRUCacheWrapperObject *self, void *closure);
static int
_LRUCacheWrapper_set__is_coroutine(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapper_get___3_tasks(faster_async_lru____LRUCacheWrapperObject *self, void *closure);

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
    {"_is_coroutine",
     (getter)_LRUCacheWrapper_get__is_coroutine, (setter)_LRUCacheWrapper_set__is_coroutine,
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
    .tp_basicsize = sizeof(faster_async_lru____LRUCacheWrapperObject),
    .tp_vectorcall_offset = offsetof(faster_async_lru____LRUCacheWrapperObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("_LRUCacheWrapper(fn, maxsize, typed, ttl)\n--\n\n"),
};
static PyTypeObject *CPyType__LRUCacheWrapper_template = &CPyType__LRUCacheWrapper_template_;

PyObject *CPyDef___mypyc___3_LRUCacheWrapper_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    faster_async_lru____LRUCacheWrapperObject *self;
    self = (faster_async_lru____LRUCacheWrapperObject *)type->tp_alloc(type, 0);
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
_LRUCacheWrapper_get___3_module__(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_module__(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get___3_name__(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_name__(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get___3_qualname__(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_qualname__(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get___3_doc__(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_doc__(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get___3_annotations__(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_annotations__(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get___3_wrapped__(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_wrapped__(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get___3_maxsize(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_maxsize(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get___3_typed(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_typed(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get___3_ttl(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_ttl(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get___3_cache(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_cache(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get___3_closed(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_closed(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get___3_hits(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_hits(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get___3_misses(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapper_set___3_misses(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapper_get__is_coroutine(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
{
    if (unlikely(self->__is_coroutine == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_is_coroutine' of '_LRUCacheWrapper' undefined");
        return NULL;
    }
    CPy_INCREF(self->__is_coroutine);
    PyObject *retval = self->__is_coroutine;
    return retval;
}

static int
_LRUCacheWrapper_set__is_coroutine(faster_async_lru____LRUCacheWrapperObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapper' object attribute '_is_coroutine' cannot be deleted");
        return -1;
    }
    if (self->__is_coroutine != NULL) {
        CPy_DECREF(self->__is_coroutine);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->__is_coroutine = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapper_get___3_tasks(faster_async_lru____LRUCacheWrapperObject *self, void *closure)
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
_LRUCacheWrapperInstanceMethod_traverse(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___module__);
    Py_VISIT(self->___name__);
    Py_VISIT(self->___qualname__);
    Py_VISIT(self->___doc__);
    Py_VISIT(self->___annotations__);
    Py_VISIT(self->___wrapped__);
    Py_VISIT(self->___instance);
    Py_VISIT(self->___wrapper);
    Py_VISIT(self->__is_coroutine);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
_LRUCacheWrapperInstanceMethod_clear(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self)
{
    Py_CLEAR(self->___module__);
    Py_CLEAR(self->___name__);
    Py_CLEAR(self->___qualname__);
    Py_CLEAR(self->___doc__);
    Py_CLEAR(self->___annotations__);
    Py_CLEAR(self->___wrapped__);
    Py_CLEAR(self->___instance);
    Py_CLEAR(self->___wrapper);
    Py_CLEAR(self->__is_coroutine);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
_LRUCacheWrapperInstanceMethod_dealloc(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self)
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
_LRUCacheWrapperInstanceMethod_get___3_module__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_module__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_name__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_name__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_qualname__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_qualname__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_doc__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_doc__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_annotations__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_annotations__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_wrapped__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_wrapped__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_instance(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_instance(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_wrapper(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set___3_wrapper(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);
static PyObject *
_LRUCacheWrapperInstanceMethod_get__is_coroutine(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure);
static int
_LRUCacheWrapperInstanceMethod_set__is_coroutine(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure);

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
    {"_is_coroutine",
     (getter)_LRUCacheWrapperInstanceMethod_get__is_coroutine, (setter)_LRUCacheWrapperInstanceMethod_set__is_coroutine,
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
    .tp_basicsize = sizeof(faster_async_lru____LRUCacheWrapperInstanceMethodObject),
    .tp_vectorcall_offset = offsetof(faster_async_lru____LRUCacheWrapperInstanceMethodObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("_LRUCacheWrapperInstanceMethod(wrapper, instance)\n--\n\n"),
};
static PyTypeObject *CPyType__LRUCacheWrapperInstanceMethod_template = &CPyType__LRUCacheWrapperInstanceMethod_template_;

PyObject *CPyDef___mypyc___3_LRUCacheWrapperInstanceMethod_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    faster_async_lru____LRUCacheWrapperInstanceMethodObject *self;
    self = (faster_async_lru____LRUCacheWrapperInstanceMethodObject *)type->tp_alloc(type, 0);
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
_LRUCacheWrapperInstanceMethod_get___3_module__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
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
_LRUCacheWrapperInstanceMethod_set___3_module__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapperInstanceMethod_get___3_name__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
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
_LRUCacheWrapperInstanceMethod_set___3_name__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapperInstanceMethod_get___3_qualname__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
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
_LRUCacheWrapperInstanceMethod_set___3_qualname__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapperInstanceMethod_get___3_doc__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
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
_LRUCacheWrapperInstanceMethod_set___3_doc__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
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
    if (tmp != NULL) goto __LL5;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL5;
    CPy_TypeError("str or None", value); 
    tmp = NULL;
__LL5: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___doc__ = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapperInstanceMethod_get___3_annotations__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
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
_LRUCacheWrapperInstanceMethod_set___3_annotations__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapperInstanceMethod_get___3_wrapped__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
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
_LRUCacheWrapperInstanceMethod_set___3_wrapped__(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapperInstanceMethod_get___3_instance(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
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
_LRUCacheWrapperInstanceMethod_set___3_instance(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
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
_LRUCacheWrapperInstanceMethod_get___3_wrapper(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
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
_LRUCacheWrapperInstanceMethod_set___3_wrapper(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF_NO_IMM(tmp);
    self->___wrapper = tmp;
    return 0;
}

static PyObject *
_LRUCacheWrapperInstanceMethod_get__is_coroutine(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, void *closure)
{
    if (unlikely(self->__is_coroutine == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_is_coroutine' of '_LRUCacheWrapperInstanceMethod' undefined");
        return NULL;
    }
    CPy_INCREF(self->__is_coroutine);
    PyObject *retval = self->__is_coroutine;
    return retval;
}

static int
_LRUCacheWrapperInstanceMethod_set__is_coroutine(faster_async_lru____LRUCacheWrapperInstanceMethodObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'_LRUCacheWrapperInstanceMethod' object attribute '_is_coroutine' cannot be deleted");
        return -1;
    }
    if (self->__is_coroutine != NULL) {
        CPy_DECREF(self->__is_coroutine);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->__is_coroutine = tmp;
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
cache_close__LRUCacheWrapper_gen_traverse(faster_async_lru___cache_close__LRUCacheWrapper_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_generator_attribute__self);
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
cache_close__LRUCacheWrapper_gen_clear(faster_async_lru___cache_close__LRUCacheWrapper_genObject *self)
{
    Py_CLEAR(self->___mypyc_generator_attribute__self);
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
cache_close__LRUCacheWrapper_gen_dealloc(faster_async_lru___cache_close__LRUCacheWrapper_genObject *self)
{
    PyObject_GC_UnTrack(self);
    if (cache_close__LRUCacheWrapper_gen_free_instance == NULL) {
        cache_close__LRUCacheWrapper_gen_free_instance = self;
        Py_CLEAR(self->___mypyc_generator_attribute__self);
        self->___mypyc_generator_attribute__wait = 2;
        self->___mypyc_next_label__ = -113;
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
    .tp_basicsize = sizeof(faster_async_lru___cache_close__LRUCacheWrapper_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("cache_close__LRUCacheWrapper_gen()\n--\n\n"),
};
static PyTypeObject *CPyType_cache_close__LRUCacheWrapper_gen_template = &CPyType_cache_close__LRUCacheWrapper_gen_template_;

PyObject *CPyDef___mypyc__cache_close__LRUCacheWrapper_gen_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    faster_async_lru___cache_close__LRUCacheWrapper_genObject *self;
    if (cache_close__LRUCacheWrapper_gen_free_instance != NULL) {
        self = cache_close__LRUCacheWrapper_gen_free_instance;
        cache_close__LRUCacheWrapper_gen_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (faster_async_lru___cache_close__LRUCacheWrapper_genObject *)type->tp_alloc(type, 0);
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
_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_traverse(faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *self, visitproc visit, void *arg)
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
_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_clear(faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *self)
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
_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_dealloc(faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *self)
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
    .tp_basicsize = sizeof(faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("_shield_and_handle_cancelled_error__LRUCacheWrapper_gen()\n--\n\n"),
};
static PyTypeObject *CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_template = &CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_template_;

PyObject *CPyDef___mypyc___3_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *self;
    if (_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_free_instance != NULL) {
        self = _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_free_instance;
        _shield_and_handle_cancelled_error__LRUCacheWrapper_gen_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)type->tp_alloc(type, 0);
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
__call___3__LRUCacheWrapper_gen_traverse(faster_async_lru_____call___3__LRUCacheWrapper_genObject *self, visitproc visit, void *arg)
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
__call___3__LRUCacheWrapper_gen_clear(faster_async_lru_____call___3__LRUCacheWrapper_genObject *self)
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
__call___3__LRUCacheWrapper_gen_dealloc(faster_async_lru_____call___3__LRUCacheWrapper_genObject *self)
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
    .tp_basicsize = sizeof(faster_async_lru_____call___3__LRUCacheWrapper_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("__call____LRUCacheWrapper_gen()\n--\n\n"),
};
static PyTypeObject *CPyType___call___3__LRUCacheWrapper_gen_template = &CPyType___call___3__LRUCacheWrapper_gen_template_;

PyObject *CPyDef___mypyc___3__call___3__LRUCacheWrapper_gen_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    faster_async_lru_____call___3__LRUCacheWrapper_genObject *self;
    if (__call___3__LRUCacheWrapper_gen_free_instance != NULL) {
        self = __call___3__LRUCacheWrapper_gen_free_instance;
        __call___3__LRUCacheWrapper_gen_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (faster_async_lru_____call___3__LRUCacheWrapper_genObject *)type->tp_alloc(type, 0);
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
cache_close__LRUCacheWrapperInstanceMethod_gen_traverse(faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_generator_attribute__self);
    Py_VISIT(self->___mypyc_temp__12);
    Py_VISIT(self->___mypyc_temp__13.f0);
    Py_VISIT(self->___mypyc_temp__13.f1);
    Py_VISIT(self->___mypyc_temp__13.f2);
    return 0;
}

static int
cache_close__LRUCacheWrapperInstanceMethod_gen_clear(faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *self)
{
    Py_CLEAR(self->___mypyc_generator_attribute__self);
    Py_CLEAR(self->___mypyc_temp__12);
    Py_CLEAR(self->___mypyc_temp__13.f0);
    Py_CLEAR(self->___mypyc_temp__13.f1);
    Py_CLEAR(self->___mypyc_temp__13.f2);
    return 0;
}

static void
cache_close__LRUCacheWrapperInstanceMethod_gen_dealloc(faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *self)
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
    .tp_basicsize = sizeof(faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("cache_close__LRUCacheWrapperInstanceMethod_gen()\n--\n\n"),
};
static PyTypeObject *CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen_template = &CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen_template_;

PyObject *CPyDef___mypyc__cache_close__LRUCacheWrapperInstanceMethod_gen_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *self;
    if (cache_close__LRUCacheWrapperInstanceMethod_gen_free_instance != NULL) {
        self = cache_close__LRUCacheWrapperInstanceMethod_gen_free_instance;
        cache_close__LRUCacheWrapperInstanceMethod_gen_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)type->tp_alloc(type, 0);
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
__call___3__LRUCacheWrapperInstanceMethod_gen_traverse(faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *self, visitproc visit, void *arg)
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
__call___3__LRUCacheWrapperInstanceMethod_gen_clear(faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *self)
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
__call___3__LRUCacheWrapperInstanceMethod_gen_dealloc(faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *self)
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
    .tp_basicsize = sizeof(faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("__call____LRUCacheWrapperInstanceMethod_gen()\n--\n\n"),
};
static PyTypeObject *CPyType___call___3__LRUCacheWrapperInstanceMethod_gen_template = &CPyType___call___3__LRUCacheWrapperInstanceMethod_gen_template_;

PyObject *CPyDef___mypyc___3__call___3__LRUCacheWrapperInstanceMethod_gen_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *self;
    if (__call___3__LRUCacheWrapperInstanceMethod_gen_free_instance != NULL) {
        self = __call___3__LRUCacheWrapperInstanceMethod_gen_free_instance;
        __call___3__LRUCacheWrapperInstanceMethod_gen_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)type->tp_alloc(type, 0);
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
_make_wrapper_env_traverse(faster_async_lru____make_wrapper_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_maxsize);
    Py_VISIT(self->_ttl);
    Py_VISIT(self->_wrapper);
    return 0;
}

static int
_make_wrapper_env_clear(faster_async_lru____make_wrapper_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_maxsize);
    Py_CLEAR(self->_ttl);
    Py_CLEAR(self->_wrapper);
    return 0;
}

static void
_make_wrapper_env_dealloc(faster_async_lru____make_wrapper_envObject *self)
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
    .tp_basicsize = sizeof(faster_async_lru____make_wrapper_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("_make_wrapper_env()\n--\n\n"),
};
static PyTypeObject *CPyType__make_wrapper_env_template = &CPyType__make_wrapper_env_template_;

PyObject *CPyDef___mypyc___3_make_wrapper_env_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    faster_async_lru____make_wrapper_envObject *self;
    if (_make_wrapper_env_free_instance != NULL) {
        self = _make_wrapper_env_free_instance;
        _make_wrapper_env_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (faster_async_lru____make_wrapper_envObject *)type->tp_alloc(type, 0);
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
wrapper__make_wrapper_obj_traverse(faster_async_lru___wrapper__make_wrapper_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
wrapper__make_wrapper_obj_clear(faster_async_lru___wrapper__make_wrapper_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
wrapper__make_wrapper_obj_dealloc(faster_async_lru___wrapper__make_wrapper_objObject *self)
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
wrapper__make_wrapper_obj_get___3_mypyc_env__(faster_async_lru___wrapper__make_wrapper_objObject *self, void *closure);
static int
wrapper__make_wrapper_obj_set___3_mypyc_env__(faster_async_lru___wrapper__make_wrapper_objObject *self, PyObject *value, void *closure);

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
    .tp_basicsize = sizeof(faster_async_lru___wrapper__make_wrapper_objObject),
    .tp_vectorcall_offset = offsetof(faster_async_lru___wrapper__make_wrapper_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("wrapper__make_wrapper_obj()\n--\n\n"),
};
static PyTypeObject *CPyType_wrapper__make_wrapper_obj_template = &CPyType_wrapper__make_wrapper_obj_template_;

PyObject *CPyDef___mypyc__wrapper__make_wrapper_obj_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    faster_async_lru___wrapper__make_wrapper_objObject *self;
    if (wrapper__make_wrapper_obj_free_instance != NULL) {
        self = wrapper__make_wrapper_obj_free_instance;
        wrapper__make_wrapper_obj_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (faster_async_lru___wrapper__make_wrapper_objObject *)type->tp_alloc(type, 0);
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
wrapper__make_wrapper_obj_get___3_mypyc_env__(faster_async_lru___wrapper__make_wrapper_objObject *self, void *closure)
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
wrapper__make_wrapper_obj_set___3_mypyc_env__(faster_async_lru___wrapper__make_wrapper_objObject *self, PyObject *value, void *closure)
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
        CPy_TypeError("faster_async_lru._make_wrapper_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF_NO_IMM(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}

static PyObject *CPyDunder___get____init___3__HashedSeq_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef___init___3__HashedSeq_obj_____get__(self, instance, owner);
}
PyObject *CPyDef___mypyc___3__init___3__HashedSeq_obj_setup(PyObject *cpy_r_type);
PyObject *CPyDef___init___3__HashedSeq_obj(void);

static PyObject *
__init___3__HashedSeq_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___init___3__HashedSeq_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc___3__init___3__HashedSeq_obj_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
__init___3__HashedSeq_obj_traverse(faster_async_lru_____init___3__HashedSeq_objObject *self, visitproc visit, void *arg)
{
    return 0;
}

static int
__init___3__HashedSeq_obj_clear(faster_async_lru_____init___3__HashedSeq_objObject *self)
{
    return 0;
}

static void
__init___3__HashedSeq_obj_dealloc(faster_async_lru_____init___3__HashedSeq_objObject *self)
{
    PyObject_GC_UnTrack(self);
    if (__init___3__HashedSeq_obj_free_instance == NULL) {
        __init___3__HashedSeq_obj_free_instance = self;
        return;
    }
    CPy_TRASHCAN_BEGIN(self, __init___3__HashedSeq_obj_dealloc)
    __init___3__HashedSeq_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem __init___3__HashedSeq_obj_vtable[2];
static bool
CPyDef___init___3__HashedSeq_obj_trait_vtable_setup(void)
{
    CPyVTableItem __init___3__HashedSeq_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___init___3__HashedSeq_obj_____call__,
        (CPyVTableItem)CPyDef___init___3__HashedSeq_obj_____get__,
    };
    memcpy(__init___3__HashedSeq_obj_vtable, __init___3__HashedSeq_obj_vtable_scratch, sizeof(__init___3__HashedSeq_obj_vtable));
    return 1;
}

static PyMethodDef __init___3__HashedSeq_obj_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc___3__init___3__HashedSeq_obj_setup, METH_O, NULL},
    {"__call__",
     (PyCFunction)CPyPy___init___3__HashedSeq_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__call__($self, tup)\n--\n\n")},
    {"__get__",
     (PyCFunction)CPyPy___init___3__HashedSeq_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__get__($instance, owner)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___init___3__HashedSeq_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__init____HashedSeq_obj",
    .tp_new = __init___3__HashedSeq_obj_new,
    .tp_dealloc = (destructor)__init___3__HashedSeq_obj_dealloc,
    .tp_traverse = (traverseproc)__init___3__HashedSeq_obj_traverse,
    .tp_clear = (inquiry)__init___3__HashedSeq_obj_clear,
    .tp_methods = __init___3__HashedSeq_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get____init___3__HashedSeq_obj,
    .tp_basicsize = sizeof(faster_async_lru_____init___3__HashedSeq_objObject),
    .tp_vectorcall_offset = offsetof(faster_async_lru_____init___3__HashedSeq_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
    .tp_doc = PyDoc_STR("__init____HashedSeq_obj()\n--\n\n"),
};
static PyTypeObject *CPyType___init___3__HashedSeq_obj_template = &CPyType___init___3__HashedSeq_obj_template_;

PyObject *CPyDef___mypyc___3__init___3__HashedSeq_obj_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    faster_async_lru_____init___3__HashedSeq_objObject *self;
    if (__init___3__HashedSeq_obj_free_instance != NULL) {
        self = __init___3__HashedSeq_obj_free_instance;
        __init___3__HashedSeq_obj_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (faster_async_lru_____init___3__HashedSeq_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __init___3__HashedSeq_obj_vtable;
    self->vectorcall = CPyPy___init___3__HashedSeq_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef___init___3__HashedSeq_obj(void)
{
    PyObject *self = CPyDef___mypyc___3__init___3__HashedSeq_obj_setup((PyObject *)CPyType___init___3__HashedSeq_obj);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get____hash___3__HashedSeq_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef___hash___3__HashedSeq_obj_____get__(self, instance, owner);
}
PyObject *CPyDef___mypyc___3__hash___3__HashedSeq_obj_setup(PyObject *cpy_r_type);
PyObject *CPyDef___hash___3__HashedSeq_obj(void);

static PyObject *
__hash___3__HashedSeq_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___hash___3__HashedSeq_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc___3__hash___3__HashedSeq_obj_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
__hash___3__HashedSeq_obj_traverse(faster_async_lru_____hash___3__HashedSeq_objObject *self, visitproc visit, void *arg)
{
    return 0;
}

static int
__hash___3__HashedSeq_obj_clear(faster_async_lru_____hash___3__HashedSeq_objObject *self)
{
    return 0;
}

static void
__hash___3__HashedSeq_obj_dealloc(faster_async_lru_____hash___3__HashedSeq_objObject *self)
{
    PyObject_GC_UnTrack(self);
    if (__hash___3__HashedSeq_obj_free_instance == NULL) {
        __hash___3__HashedSeq_obj_free_instance = self;
        return;
    }
    CPy_TRASHCAN_BEGIN(self, __hash___3__HashedSeq_obj_dealloc)
    __hash___3__HashedSeq_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem __hash___3__HashedSeq_obj_vtable[2];
static bool
CPyDef___hash___3__HashedSeq_obj_trait_vtable_setup(void)
{
    CPyVTableItem __hash___3__HashedSeq_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___hash___3__HashedSeq_obj_____call__,
        (CPyVTableItem)CPyDef___hash___3__HashedSeq_obj_____get__,
    };
    memcpy(__hash___3__HashedSeq_obj_vtable, __hash___3__HashedSeq_obj_vtable_scratch, sizeof(__hash___3__HashedSeq_obj_vtable));
    return 1;
}

static PyMethodDef __hash___3__HashedSeq_obj_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc___3__hash___3__HashedSeq_obj_setup, METH_O, NULL},
    {"__call__",
     (PyCFunction)CPyPy___hash___3__HashedSeq_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__call__($self)\n--\n\n")},
    {"__get__",
     (PyCFunction)CPyPy___hash___3__HashedSeq_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__get__($instance, owner)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___hash___3__HashedSeq_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__hash____HashedSeq_obj",
    .tp_new = __hash___3__HashedSeq_obj_new,
    .tp_dealloc = (destructor)__hash___3__HashedSeq_obj_dealloc,
    .tp_traverse = (traverseproc)__hash___3__HashedSeq_obj_traverse,
    .tp_clear = (inquiry)__hash___3__HashedSeq_obj_clear,
    .tp_methods = __hash___3__HashedSeq_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get____hash___3__HashedSeq_obj,
    .tp_basicsize = sizeof(faster_async_lru_____hash___3__HashedSeq_objObject),
    .tp_vectorcall_offset = offsetof(faster_async_lru_____hash___3__HashedSeq_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
    .tp_doc = PyDoc_STR("__hash____HashedSeq_obj()\n--\n\n"),
};
static PyTypeObject *CPyType___hash___3__HashedSeq_obj_template = &CPyType___hash___3__HashedSeq_obj_template_;

PyObject *CPyDef___mypyc___3__hash___3__HashedSeq_obj_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    faster_async_lru_____hash___3__HashedSeq_objObject *self;
    if (__hash___3__HashedSeq_obj_free_instance != NULL) {
        self = __hash___3__HashedSeq_obj_free_instance;
        __hash___3__HashedSeq_obj_free_instance = NULL;
        Py_SET_REFCNT(self, 1);
        PyObject_GC_Track(self);
        return (PyObject *)self;
    }
    self = (faster_async_lru_____hash___3__HashedSeq_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __hash___3__HashedSeq_obj_vtable;
    self->vectorcall = CPyPy___hash___3__HashedSeq_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef___hash___3__HashedSeq_obj(void)
{
    PyObject *self = CPyDef___mypyc___3__hash___3__HashedSeq_obj_setup((PyObject *)CPyType___hash___3__HashedSeq_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyMethodDef module_methods[] = {
    {"_make_wrapper", (PyCFunction)CPyPy__make_wrapper, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_make_wrapper(maxsize, typed, ttl=None)\n--\n\n") /* docstring */},
    {"alru_cache", (PyCFunction)CPyPy_alru_cache, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("alru_cache(maxsize=128, typed=False, *, ttl=None)\n--\n\n") /* docstring */},
    {"_make_key", (PyCFunction)CPyPy__make_key, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_make_key(args, kwds, typed)\n--\n\n") /* docstring */},
    {NULL, NULL, 0, NULL}
};

int CPyExec_faster_async_lru(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_async_lru__internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_faster_async_lru__internal);
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
    CPyType___init___3__HashedSeq_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___init___3__HashedSeq_obj_template, NULL, modname);
    if (unlikely(!CPyType___init___3__HashedSeq_obj))
        goto fail;
    CPyDef___init___3__HashedSeq_obj_trait_vtable_setup();
    CPyType___hash___3__HashedSeq_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___hash___3__HashedSeq_obj_template, NULL, modname);
    if (unlikely(!CPyType___hash___3__HashedSeq_obj))
        goto fail;
    CPyDef___hash___3__HashedSeq_obj_trait_vtable_setup();
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_async_lru__internal);
    Py_CLEAR(modname);
    CPyStatic__PYTHON_GTE_312 = 2;
    CPyStatic__PYTHON_LT_314 = 2;
    CPy_XDECREF(CPyStatic_CancelledError);
    CPyStatic_CancelledError = NULL;
    CPy_XDECREF(CPyStatic_partial);
    CPyStatic_partial = NULL;
    CPy_XDECREF(CPyStatic_partialmethod);
    CPyStatic_partialmethod = NULL;
    CPy_XDECREF(CPyStatic_gather);
    CPyStatic_gather = NULL;
    CPy_XDECREF(CPyStatic_get_running_loop);
    CPyStatic_get_running_loop = NULL;
    CPy_XDECREF(CPyStatic_shield);
    CPyStatic_shield = NULL;
    CPy_XDECREF(CPyStatic_markcoroutinefunction);
    CPyStatic_markcoroutinefunction = NULL;
    CPy_XDECREF(CPyStatic__KW_MARK.f0);
    CPyStatic__KW_MARK = (tuple_T1O) { NULL };
    Py_CLEAR(CPyType__CacheParameters);
    Py_CLEAR(CPyType__CacheItem);
    Py_CLEAR(CPyType__LRUCacheWrapper);
    Py_CLEAR(CPyType__LRUCacheWrapperInstanceMethod);
    Py_CLEAR(CPyType__HashedSeq);
    Py_CLEAR(CPyType_cache_close__LRUCacheWrapper_gen);
    Py_CLEAR(CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen);
    Py_CLEAR(CPyType___call___3__LRUCacheWrapper_gen);
    Py_CLEAR(CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen);
    Py_CLEAR(CPyType___call___3__LRUCacheWrapperInstanceMethod_gen);
    Py_CLEAR(CPyType__make_wrapper_env);
    Py_CLEAR(CPyType_wrapper__make_wrapper_obj);
    Py_CLEAR(CPyType___init___3__HashedSeq_obj);
    Py_CLEAR(CPyType___hash___3__HashedSeq_obj);
    return -1;
}
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "faster_async_lru",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    module_methods,
    NULL,
};

PyMODINIT_FUNC PyInit_faster_async_lru(void)
{
    if (CPyModule_faster_async_lru__internal) {
        Py_INCREF(CPyModule_faster_async_lru__internal);
        return CPyModule_faster_async_lru__internal;
    }
    CPyModule_faster_async_lru__internal = PyModule_Create(&module);
    if (unlikely(CPyModule_faster_async_lru__internal == NULL))
        goto fail;
    if (CPyExec_faster_async_lru(CPyModule_faster_async_lru__internal) != 0)
        goto fail;
    return CPyModule_faster_async_lru__internal;
    fail:
    return NULL;
}

char CPyDef__CacheItem_____init__(PyObject *cpy_r_self, PyObject *cpy_r_task) {
    char cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    CPy_INCREF(cpy_r_task);
    if (((faster_async_lru____CacheItemObject *)cpy_r_self)->_task != NULL) {
        CPy_DECREF(((faster_async_lru____CacheItemObject *)cpy_r_self)->_task);
    }
    ((faster_async_lru____CacheItemObject *)cpy_r_self)->_task = cpy_r_task;
    cpy_r_r0 = 1;
    if (unlikely(!cpy_r_r0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r1 = Py_None;
    if (((faster_async_lru____CacheItemObject *)cpy_r_self)->_later_call != NULL) {
        CPy_DECREF(((faster_async_lru____CacheItemObject *)cpy_r_self)->_later_call);
    }
    ((faster_async_lru____CacheItemObject *)cpy_r_self)->_later_call = cpy_r_r1;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL4;
    }
    if (((faster_async_lru____CacheItemObject *)cpy_r_self)->_waiters != CPY_INT_TAG) {
        CPyTagged_DECREF(((faster_async_lru____CacheItemObject *)cpy_r_self)->_waiters);
    }
    ((faster_async_lru____CacheItemObject *)cpy_r_self)->_waiters = 2;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL4;
    }
    return 1;
CPyL4: ;
    cpy_r_r4 = 2;
    return cpy_r_r4;
}

PyObject *CPyPy__CacheItem_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"task", 0};
    PyObject *obj_task;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "O", "__init__", kwlist, &obj_task)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__CacheItem))
        arg_self = obj_self;
    else {
        CPy_TypeError("faster_async_lru._CacheItem", obj_self); 
        goto fail;
    }
    PyObject *arg_task = obj_task;
    char retval = CPyDef__CacheItem_____init__(arg_self, arg_task);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    cpy_r_r0 = ((faster_async_lru____CacheItemObject *)cpy_r_self)->_later_call;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cancel", "_CacheItem", "later_call", 77, CPyStatic_globals);
        goto CPyL8;
    }
CPyL1: ;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (!cpy_r_r2) goto CPyL7;
    cpy_r_r3 = ((faster_async_lru____CacheItemObject *)cpy_r_self)->_later_call;
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cancel", "_CacheItem", "later_call", 78, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "cancel", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL9;
    }
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r8 != Py_None)) {
        CPy_TypeError("None", cpy_r_r8); cpy_r_r9 = 2;
    } else
        cpy_r_r9 = 1;
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r9 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cancel", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r10 = Py_None;
    if (((faster_async_lru____CacheItemObject *)cpy_r_self)->_later_call != NULL) {
        CPy_DECREF(((faster_async_lru____CacheItemObject *)cpy_r_self)->_later_call);
    }
    ((faster_async_lru____CacheItemObject *)cpy_r_self)->_later_call = cpy_r_r10;
    cpy_r_r11 = 1;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cancel", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._CacheItem", obj_self); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "cancel", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    PyObject *cpy_r_r54;
    int32_t cpy_r_r55;
    char cpy_r_r56;
    tuple_T3OOO cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    tuple_T2OO cpy_r_r64;
    PyObject *cpy_r_r65;
    char cpy_r_r66;
    char cpy_r_r67;
    char cpy_r_r68;
    char cpy_r_r69;
    char cpy_r_r70;
    PyObject *cpy_r_r71;
    char cpy_r_r72;
    char cpy_r_r73;
    char cpy_r_r74;
    char cpy_r_r75;
    char cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    char cpy_r_r82;
    char cpy_r_r83;
    char cpy_r_r84;
    char cpy_r_r85;
    char cpy_r_r86;
    cpy_r_r0 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_fn, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL4;
    }
    if (likely(PyUnicode_Check(cpy_r_r1)))
        cpy_r_r2 = cpy_r_r1;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__init__", 92, CPyStatic_globals, "str", cpy_r_r1);
        goto CPyL4;
    }
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___module__ != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___module__);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___module__ = cpy_r_r2;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL11;
CPyL4: ;
    cpy_r_r4 = CPy_CatchError();
    cpy_r_r5 = CPyModule_builtins;
    cpy_r_r6 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL14;
    }
    if (likely(PyUnicode_Check(cpy_r_r10)))
        cpy_r_r11 = cpy_r_r10;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__init__", 96, CPyStatic_globals, "str", cpy_r_r10);
        goto CPyL14;
    }
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___name__ != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___name__);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___name__ = cpy_r_r11;
    cpy_r_r12 = 1;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL21;
CPyL14: ;
    cpy_r_r13 = CPy_CatchError();
    cpy_r_r14 = CPyModule_builtins;
    cpy_r_r15 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL24;
    }
    if (likely(PyUnicode_Check(cpy_r_r20)))
        cpy_r_r21 = cpy_r_r20;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__init__", 100, CPyStatic_globals, "str", cpy_r_r20);
        goto CPyL24;
    }
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___qualname__ != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___qualname__);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___qualname__ = cpy_r_r21;
    cpy_r_r22 = 1;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL31;
CPyL24: ;
    cpy_r_r23 = CPy_CatchError();
    cpy_r_r24 = CPyModule_builtins;
    cpy_r_r25 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r26 = CPyObject_GetAttr(cpy_r_r24, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL34;
    }
    if (PyUnicode_Check(cpy_r_r30))
        cpy_r_r31 = cpy_r_r30;
    else {
        cpy_r_r31 = NULL;
    }
    if (cpy_r_r31 != NULL) goto __LL6;
    if (cpy_r_r30 == Py_None)
        cpy_r_r31 = cpy_r_r30;
    else {
        cpy_r_r31 = NULL;
    }
    if (cpy_r_r31 != NULL) goto __LL6;
    CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__init__", 104, CPyStatic_globals, "str or None", cpy_r_r30);
    goto CPyL34;
__LL6: ;
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___doc__ != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___doc__);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___doc__ = cpy_r_r31;
    cpy_r_r32 = 1;
    if (unlikely(!cpy_r_r32)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL41;
CPyL34: ;
    cpy_r_r33 = CPy_CatchError();
    cpy_r_r34 = CPyModule_builtins;
    cpy_r_r35 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r36 = CPyObject_GetAttr(cpy_r_r34, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL44;
    }
    if (likely(PyDict_Check(cpy_r_r40)))
        cpy_r_r41 = cpy_r_r40;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__init__", 108, CPyStatic_globals, "dict", cpy_r_r40);
        goto CPyL44;
    }
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___annotations__ != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___annotations__);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___annotations__ = cpy_r_r41;
    cpy_r_r42 = 1;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL51;
CPyL44: ;
    cpy_r_r43 = CPy_CatchError();
    cpy_r_r44 = CPyModule_builtins;
    cpy_r_r45 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r46 = CPyObject_GetAttr(cpy_r_r44, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_self, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL56;
    }
    if (likely(PyDict_Check(cpy_r_r50)))
        cpy_r_r51 = cpy_r_r50;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__init__", 112, CPyStatic_globals, "dict", cpy_r_r50);
        goto CPyL56;
    }
    cpy_r_r52 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r53 = CPyObject_GetAttr(cpy_r_fn, cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL88;
    }
    if (likely(PyDict_Check(cpy_r_r53)))
        cpy_r_r54 = cpy_r_r53;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__init__", 112, CPyStatic_globals, "dict", cpy_r_r53);
        goto CPyL88;
    }
    cpy_r_r55 = CPyDict_Update(cpy_r_r51, cpy_r_r54);
    CPy_DECREF(cpy_r_r51);
    CPy_DECREF(cpy_r_r54);
    cpy_r_r56 = cpy_r_r55 >= 0;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL64;
CPyL56: ;
    cpy_r_r57 = CPy_CatchError();
    cpy_r_r58 = CPyModule_builtins;
    cpy_r_r59 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r60 = CPyObject_GetAttr(cpy_r_r58, cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r61 = CPyModule_builtins;
    cpy_r_r62 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'TypeError' */
    cpy_r_r63 = CPyObject_GetAttr(cpy_r_r61, cpy_r_r62);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL89;
    }
    cpy_r_r64.f0 = cpy_r_r60;
    cpy_r_r64.f1 = cpy_r_r63;
    cpy_r_r65 = PyTuple_New(2);
    if (unlikely(cpy_r_r65 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp7 = cpy_r_r64.f0;
    PyTuple_SET_ITEM(cpy_r_r65, 0, __tmp7);
    PyObject *__tmp8 = cpy_r_r64.f1;
    PyTuple_SET_ITEM(cpy_r_r65, 1, __tmp8);
    cpy_r_r66 = CPy_ExceptionMatches(cpy_r_r65);
    CPy_DecRef(cpy_r_r65);
    if (cpy_r_r66) goto CPyL61;
    CPy_Reraise();
    if (!0) {
        goto CPyL62;
    } else
        goto CPyL90;
CPyL60: ;
    CPy_Unreachable();
CPyL61: ;
    CPy_RestoreExcInfo(cpy_r_r57);
    CPy_DecRef(cpy_r_r57.f0);
    CPy_DecRef(cpy_r_r57.f1);
    CPy_DecRef(cpy_r_r57.f2);
    goto CPyL64;
CPyL62: ;
    CPy_RestoreExcInfo(cpy_r_r57);
    CPy_DecRef(cpy_r_r57.f0);
    CPy_DecRef(cpy_r_r57.f1);
    CPy_DecRef(cpy_r_r57.f2);
    cpy_r_r67 = CPy_KeepPropagating();
    if (!cpy_r_r67) goto CPyL82;
    CPy_Unreachable();
CPyL64: ;
    cpy_r_r68 = CPyStatic__PYTHON_LT_314;
    if (likely(cpy_r_r68 != 2)) goto CPyL67;
    PyErr_SetString(PyExc_NameError, "value for final name \"_PYTHON_LT_314\" was not set");
    cpy_r_r69 = 0;
    if (unlikely(!cpy_r_r69)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_Unreachable();
CPyL67: ;
    if (!cpy_r_r68) goto CPyL70;
    PyErr_SetString(PyExc_NameError, "name \"_is_coroutine\" is not defined");
    cpy_r_r70 = 0;
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r71 = Py_None;
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->__is_coroutine != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->__is_coroutine);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->__is_coroutine = cpy_r_r71;
    cpy_r_r72 = 1;
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
CPyL70: ;
    CPy_INCREF(cpy_r_fn);
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___wrapped__ != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___wrapped__);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___wrapped__ = cpy_r_fn;
    cpy_r_r73 = 1;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF(cpy_r_maxsize);
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize = cpy_r_maxsize;
    cpy_r_r74 = 1;
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___typed = cpy_r_typed;
    cpy_r_r75 = 1;
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF(cpy_r_ttl);
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl = cpy_r_ttl;
    cpy_r_r76 = 1;
    if (unlikely(!cpy_r_r76)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r77 = CPyStatic_globals;
    cpy_r_r78 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'OrderedDict' */
    cpy_r_r79 = CPyDict_GetItem(cpy_r_r77, cpy_r_r78);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r80 = PyObject_Vectorcall(cpy_r_r79, 0, 0, 0);
    CPy_DECREF(cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    if (likely(PyDict_Check(cpy_r_r80)))
        cpy_r_r81 = cpy_r_r80;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__init__", 123, CPyStatic_globals, "dict", cpy_r_r80);
        goto CPyL82;
    }
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache = cpy_r_r81;
    cpy_r_r82 = 1;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___closed = 0;
    cpy_r_r83 = 1;
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits != CPY_INT_TAG) {
        CPyTagged_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits = 0;
    cpy_r_r84 = 1;
    if (unlikely(!cpy_r_r84)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses != CPY_INT_TAG) {
        CPyTagged_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses = 0;
    cpy_r_r85 = 1;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    CPy_DecRef(cpy_r_r51);
    goto CPyL56;
CPyL89: ;
    CPy_DecRef(cpy_r_r60);
    goto CPyL62;
CPyL90: ;
    CPy_DecRef(cpy_r_r57.f0);
    CPy_DecRef(cpy_r_r57.f1);
    CPy_DecRef(cpy_r_r57.f2);
    goto CPyL60;
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
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
    char retval = CPyDef__LRUCacheWrapper_____init__(arg_self, arg_fn, arg_maxsize, arg_typed, arg_ttl);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r1 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__tasks", "_LRUCacheWrapper", "__cache", 134, CPyStatic_globals);
        goto CPyL16;
    }
    CPy_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = 0;
    cpy_r_r3 = PyDict_Size(cpy_r_r1);
    cpy_r_r4 = CPyDict_GetValuesIter(cpy_r_r1);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__tasks", 132, CPyStatic_globals, "faster_async_lru._CacheItem", cpy_r_r8);
        goto CPyL19;
    }
    cpy_r_r10 = ((faster_async_lru____CacheItemObject *)cpy_r_r9)->_task;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__tasks", "_CacheItem", "task", 135, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_INCREF(cpy_r_r10);
CPyL6: ;
    cpy_r_r11 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'done' */
    PyObject *cpy_r_r12[1] = {cpy_r_r10};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_VectorcallMethod(cpy_r_r11, cpy_r_r13, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_DECREF(cpy_r_r10);
    if (unlikely(!PyBool_Check(cpy_r_r14))) {
        CPy_TypeError("bool", cpy_r_r14); cpy_r_r15 = 2;
    } else
        cpy_r_r15 = cpy_r_r14 == Py_True;
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r15 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r16 = cpy_r_r15 ^ 1;
    if (!cpy_r_r16) goto CPyL22;
    cpy_r_r17 = ((faster_async_lru____CacheItemObject *)cpy_r_r9)->_task;
    if (unlikely(cpy_r_r17 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'task' of '_CacheItem' undefined");
    } else {
        CPy_INCREF(cpy_r_r17);
    }
    CPy_DECREF_NO_IMM(cpy_r_r9);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL19;
    }
CPyL10: ;
    cpy_r_r18 = PySet_Add(cpy_r_r0, cpy_r_r17);
    CPy_DECREF(cpy_r_r17);
    cpy_r_r19 = cpy_r_r18 >= 0;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL19;
    }
CPyL11: ;
    cpy_r_r20 = CPyDict_CheckSize(cpy_r_r1, cpy_r_r3);
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL19;
    } else
        goto CPyL3;
CPyL12: ;
    cpy_r_r21 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r22 = PySequence_List(cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef__LRUCacheWrapper_____tasks(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__tasks", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    char cpy_r_r13;
    cpy_r_r0 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___typed;
    if (unlikely(cpy_r_r0 == 2)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_invalidate", "_LRUCacheWrapper", "__typed", 140, CPyStatic_globals);
        goto CPyL10;
    }
CPyL1: ;
    cpy_r_r1 = CPyDef__make_key(cpy_r_args, cpy_r_kwargs, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r2 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_invalidate", "_LRUCacheWrapper", "__cache", 142, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_INCREF(cpy_r_r2);
CPyL3: ;
    cpy_r_r3 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'pop' */
    cpy_r_r4 = Py_None;
    PyObject *cpy_r_r5[3] = {cpy_r_r2, cpy_r_r1, cpy_r_r4};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = PyObject_VectorcallMethod(cpy_r_r3, cpy_r_r6, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r1);
    if (Py_TYPE(cpy_r_r7) == CPyType__CacheItem)
        cpy_r_r8 = cpy_r_r7;
    else {
        cpy_r_r8 = NULL;
    }
    if (cpy_r_r8 != NULL) goto __LL11;
    if (cpy_r_r7 == Py_None)
        cpy_r_r8 = cpy_r_r7;
    else {
        cpy_r_r8 = NULL;
    }
    if (cpy_r_r8 != NULL) goto __LL11;
    CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "cache_invalidate", 142, CPyStatic_globals, "faster_async_lru._CacheItem or None", cpy_r_r7);
    goto CPyL10;
__LL11: ;
    cpy_r_r9 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r10 = cpy_r_r8 == cpy_r_r9;
    if (cpy_r_r10) {
        goto CPyL13;
    } else
        goto CPyL7;
CPyL6: ;
    return 0;
CPyL7: ;
    if (likely(cpy_r_r8 != Py_None))
        cpy_r_r11 = cpy_r_r8;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "cache_invalidate", 146, CPyStatic_globals, "faster_async_lru._CacheItem", cpy_r_r8);
        goto CPyL10;
    }
    cpy_r_r12 = CPyDef__CacheItem___cancel(cpy_r_r11);
    CPy_DECREF_NO_IMM(cpy_r_r11);
    if (unlikely(cpy_r_r12 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    return 1;
CPyL10: ;
    cpy_r_r13 = 2;
    return cpy_r_r13;
CPyL11: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL10;
CPyL12: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r8);
    goto CPyL6;
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits != CPY_INT_TAG) {
        CPyTagged_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits = 0;
    cpy_r_r0 = 1;
    if (unlikely(!cpy_r_r0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL20;
    }
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses != CPY_INT_TAG) {
        CPyTagged_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses = 0;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r2 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_clear", "_LRUCacheWrapper", "__cache", 153, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_INCREF(cpy_r_r2);
CPyL3: ;
    cpy_r_r3 = 0;
    cpy_r_r4 = PyDict_Size(cpy_r_r2);
    cpy_r_r5 = CPyDict_GetValuesIter(cpy_r_r2);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "cache_clear", 153, CPyStatic_globals, "faster_async_lru._CacheItem", cpy_r_r9);
        goto CPyL23;
    }
    cpy_r_r11 = ((faster_async_lru____CacheItemObject *)cpy_r_r10)->_later_call;
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_clear", "_CacheItem", "later_call", 154, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r17 = cpy_r_r15;
    if (!cpy_r_r17) goto CPyL26;
    cpy_r_r18 = ((faster_async_lru____CacheItemObject *)cpy_r_r10)->_later_call;
    if (unlikely(cpy_r_r18 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'later_call' of '_CacheItem' undefined");
    } else {
        CPy_INCREF(cpy_r_r18);
    }
    CPy_DECREF_NO_IMM(cpy_r_r10);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL23;
    }
CPyL12: ;
    cpy_r_r19 = cpy_r_r18;
    cpy_r_r20 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cancel' */
    PyObject *cpy_r_r21[1] = {cpy_r_r19};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = PyObject_VectorcallMethod(cpy_r_r20, cpy_r_r22, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r23 != Py_None)) {
        CPy_TypeError("None", cpy_r_r23); cpy_r_r24 = 2;
    } else
        cpy_r_r24 = 1;
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r24 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL23;
    }
CPyL15: ;
    cpy_r_r25 = CPyDict_CheckSize(cpy_r_r2, cpy_r_r4);
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL23;
    } else
        goto CPyL4;
CPyL16: ;
    cpy_r_r26 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r27 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_clear", "_LRUCacheWrapper", "__cache", 156, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_INCREF(cpy_r_r27);
CPyL18: ;
    cpy_r_r28 = CPyDict_Clear(cpy_r_r27);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    CPyPtr cpy_r_r11;
    int64_t cpy_r_r12;
    CPyTagged cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    CPyPtr cpy_r_r22;
    int64_t cpy_r_r23;
    int64_t cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    int64_t cpy_r_r27;
    CPyPtr cpy_r_r28;
    CPyPtr cpy_r_r29;
    int64_t cpy_r_r30;
    CPyPtr cpy_r_r31;
    PyObject *cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject **cpy_r_r37;
    PyObject *cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject **cpy_r_r43;
    PyObject *cpy_r_r44;
    int64_t cpy_r_r45;
    int64_t cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    char cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    char cpy_r_r65;
    PyObject *cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    char cpy_r_r69;
    tuple_T3OOO cpy_r_r70;
    char cpy_r_r71;
    PyObject **cpy_r_r72;
    PyObject *cpy_r_r73;
    char cpy_r_r74;
    tuple_T3OOO cpy_r_r75;
    tuple_T3OOO cpy_r_r76;
    tuple_T3OOO cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    char cpy_r_r83;
    char cpy_r_r84;
    char cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__;
    goto CPyL78;
CPyL1: ;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = cpy_r_type != cpy_r_r3;
    if (!cpy_r_r4) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r5 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "self", 159, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF_NO_IMM(cpy_r_r5);
CPyL5: ;
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_r5)->___closed = 1;
    cpy_r_r6 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r5);
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r7 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "self", 161, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF_NO_IMM(cpy_r_r7);
CPyL7: ;
    cpy_r_r8 = CPyDef__LRUCacheWrapper_____tasks(cpy_r_r7);
    CPy_DECREF_NO_IMM(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
CPyL8: ;
    if (((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks);
    }
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks = cpy_r_r8;
    cpy_r_r9 = 1;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r10 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "tasks", 162, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF_NO_IMM(cpy_r_r10);
CPyL10: ;
    cpy_r_r11 = (CPyPtr)&((PyVarObject *)cpy_r_r10)->ob_size;
    cpy_r_r12 = *(int64_t *)cpy_r_r11;
    CPy_DECREF_NO_IMM(cpy_r_r10);
    cpy_r_r13 = cpy_r_r12 << 1;
    cpy_r_r14 = cpy_r_r13 != 0;
    if (cpy_r_r14) goto CPyL16;
    cpy_r_r15 = Py_None;
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL15;
    CPyGen_SetStopIterationValue(cpy_r_r15);
    if (!0) goto CPyL82;
    CPy_Unreachable();
CPyL15: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r15;
    return 0;
CPyL16: ;
    cpy_r_r17 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__wait;
    if (unlikely(cpy_r_r17 == 2)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "wait", 165, CPyStatic_globals);
        goto CPyL82;
    }
CPyL17: ;
    if (cpy_r_r17) goto CPyL36;
CPyL18: ;
    cpy_r_r18 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks;
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "tasks", 166, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF_NO_IMM(cpy_r_r18);
CPyL19: ;
    if (((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0 != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0);
    }
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0 = cpy_r_r18;
    cpy_r_r19 = 1;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL82;
    }
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1 = 0;
    cpy_r_r20 = 1;
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL82;
    }
CPyL21: ;
    cpy_r_r21 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0;
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__0", 166, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF_NO_IMM(cpy_r_r21);
CPyL22: ;
    cpy_r_r22 = (CPyPtr)&((PyVarObject *)cpy_r_r21)->ob_size;
    cpy_r_r23 = *(int64_t *)cpy_r_r22;
    CPy_DECREF_NO_IMM(cpy_r_r21);
    cpy_r_r24 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1;
    if (unlikely(cpy_r_r24 == -113)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__1", 166, CPyStatic_globals);
        goto CPyL82;
    }
CPyL23: ;
    cpy_r_r25 = cpy_r_r24 < cpy_r_r23;
    if (!cpy_r_r25) goto CPyL36;
    cpy_r_r26 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__0;
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__0", 166, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF_NO_IMM(cpy_r_r26);
CPyL25: ;
    cpy_r_r27 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1;
    if (unlikely(cpy_r_r27 == -113)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__1", 166, CPyStatic_globals);
        goto CPyL83;
    }
CPyL26: ;
    cpy_r_r28 = (CPyPtr)&((PyListObject *)cpy_r_r26)->ob_item;
    cpy_r_r29 = *(CPyPtr *)cpy_r_r28;
    cpy_r_r30 = cpy_r_r27 * 8;
    cpy_r_r31 = cpy_r_r29 + cpy_r_r30;
    cpy_r_r32 = *(PyObject * *)cpy_r_r31;
    CPy_INCREF(cpy_r_r32);
    CPy_DECREF_NO_IMM(cpy_r_r26);
    if (((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task != NULL) {
        CPy_DECREF(((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task);
    }
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task = cpy_r_r32;
    cpy_r_r33 = 1;
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r34 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "task", 167, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF(cpy_r_r34);
CPyL28: ;
    cpy_r_r35 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'done' */
    PyObject *cpy_r_r36[1] = {cpy_r_r34};
    cpy_r_r37 = (PyObject **)&cpy_r_r36;
    cpy_r_r38 = PyObject_VectorcallMethod(cpy_r_r35, cpy_r_r37, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    CPy_DECREF(cpy_r_r34);
    if (unlikely(!PyBool_Check(cpy_r_r38))) {
        CPy_TypeError("bool", cpy_r_r38); cpy_r_r39 = 2;
    } else
        cpy_r_r39 = cpy_r_r38 == Py_True;
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r39 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    if (cpy_r_r39) goto CPyL34;
    cpy_r_r40 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "task", 168, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF(cpy_r_r40);
CPyL32: ;
    cpy_r_r41 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cancel' */
    PyObject *cpy_r_r42[1] = {cpy_r_r40};
    cpy_r_r43 = (PyObject **)&cpy_r_r42;
    cpy_r_r44 = PyObject_VectorcallMethod(cpy_r_r41, cpy_r_r43, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL85;
    } else
        goto CPyL86;
CPyL33: ;
    CPy_DECREF(cpy_r_r40);
CPyL34: ;
    cpy_r_r45 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1;
    if (unlikely(cpy_r_r45 == -113)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__1", 166, CPyStatic_globals);
        goto CPyL82;
    }
CPyL35: ;
    cpy_r_r46 = cpy_r_r45 + 1;
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__1 = cpy_r_r46;
    cpy_r_r47 = 1;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    } else
        goto CPyL21;
CPyL36: ;
    cpy_r_r48 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__tasks;
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "tasks", 170, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF_NO_IMM(cpy_r_r48);
CPyL37: ;
    cpy_r_r49 = CPyStatic_gather;
    if (unlikely(cpy_r_r49 == NULL)) {
        goto CPyL87;
    } else
        goto CPyL40;
CPyL38: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"gather\" was not set");
    cpy_r_r50 = 0;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_Unreachable();
CPyL40: ;
    cpy_r_r51 = PyList_New(0);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL88;
    }
    cpy_r_r52 = CPyList_Extend(cpy_r_r51, cpy_r_r48);
    CPy_DECREF_NO_IMM(cpy_r_r48);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL89;
    } else
        goto CPyL90;
CPyL42: ;
    cpy_r_r53 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'return_exceptions' */
    cpy_r_r54 = PyList_AsTuple(cpy_r_r51);
    CPy_DECREF_NO_IMM(cpy_r_r51);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r55 = 1 ? Py_True : Py_False;
    cpy_r_r56 = CPyDict_Build(1, cpy_r_r53, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL91;
    }
    cpy_r_r57 = PyObject_Call(cpy_r_r49, cpy_r_r54, cpy_r_r56);
    CPy_DECREF(cpy_r_r54);
    CPy_DECREF(cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r58 = CPy_GetCoro(cpy_r_r57);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    if (((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2 != NULL) {
        CPy_DECREF(((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2);
    }
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2 = cpy_r_r58;
    cpy_r_r59 = 1;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r60 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2;
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__2", -1, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF(cpy_r_r60);
CPyL48: ;
    cpy_r_r61 = CPyIter_Next(cpy_r_r60);
    CPy_DECREF(cpy_r_r60);
    if (cpy_r_r61 != NULL) goto CPyL51;
    cpy_r_r62 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r63 = cpy_r_r62;
    CPy_DECREF(cpy_r_r63);
    cpy_r_r64 = NULL;
    if (((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2 != NULL) {
        CPy_DECREF(((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2);
    }
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2 = cpy_r_r64;
    cpy_r_r65 = 1;
    if (unlikely(!cpy_r_r65)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    } else
        goto CPyL73;
CPyL51: ;
    cpy_r_r66 = cpy_r_r61;
CPyL52: ;
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 1;
    return cpy_r_r66;
CPyL53: ;
    cpy_r_r68 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r69 = cpy_r_type != cpy_r_r68;
    if (!cpy_r_r69) goto CPyL92;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL57;
    } else
        goto CPyL93;
CPyL55: ;
    CPy_Unreachable();
CPyL56: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL68;
CPyL57: ;
    cpy_r_r70 = CPy_CatchError();
    if (((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3.f0 != NULL) {
        CPy_DECREF(((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3.f0);
        CPy_DECREF(((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3.f1);
        CPy_DECREF(((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3.f2);
    }
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3 = cpy_r_r70;
    cpy_r_r71 = 1;
    if (unlikely(!cpy_r_r71)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL94;
    }
    cpy_r_r72 = (PyObject **)&cpy_r_r1;
    cpy_r_r73 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2;
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__2", -1, CPyStatic_globals);
        goto CPyL94;
    }
    CPy_INCREF(cpy_r_r73);
CPyL59: ;
    cpy_r_r74 = CPy_YieldFromErrorHandle(cpy_r_r73, cpy_r_r72);
    CPy_DecRef(cpy_r_r73);
    if (unlikely(cpy_r_r74 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL94;
    }
    if (cpy_r_r74) goto CPyL63;
    cpy_r_r66 = cpy_r_r1;
    cpy_r_r75 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3;
    if (unlikely(cpy_r_r75.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF(cpy_r_r75.f0);
    CPy_INCREF(cpy_r_r75.f1);
    CPy_INCREF(cpy_r_r75.f2);
CPyL62: ;
    CPy_RestoreExcInfo(cpy_r_r75);
    CPy_DecRef(cpy_r_r75.f0);
    CPy_DecRef(cpy_r_r75.f1);
    CPy_DecRef(cpy_r_r75.f2);
    goto CPyL52;
CPyL63: ;
    cpy_r_r63 = cpy_r_r1;
    CPy_DecRef(cpy_r_r63);
    cpy_r_r76 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3;
    if (unlikely(cpy_r_r76.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL65;
    }
    CPy_INCREF(cpy_r_r76.f0);
    CPy_INCREF(cpy_r_r76.f1);
    CPy_INCREF(cpy_r_r76.f2);
CPyL64: ;
    CPy_RestoreExcInfo(cpy_r_r76);
    CPy_DecRef(cpy_r_r76.f0);
    CPy_DecRef(cpy_r_r76.f1);
    CPy_DecRef(cpy_r_r76.f2);
    goto CPyL73;
CPyL65: ;
    cpy_r_r77 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__3;
    if (unlikely(cpy_r_r77.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__3", -1, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_INCREF(cpy_r_r77.f0);
    CPy_INCREF(cpy_r_r77.f1);
    CPy_INCREF(cpy_r_r77.f2);
CPyL66: ;
    CPy_RestoreExcInfo(cpy_r_r77);
    CPy_DecRef(cpy_r_r77.f0);
    CPy_DecRef(cpy_r_r77.f1);
    CPy_DecRef(cpy_r_r77.f2);
    cpy_r_r78 = CPy_KeepPropagating();
    if (!cpy_r_r78) goto CPyL82;
    CPy_Unreachable();
CPyL68: ;
    cpy_r_r79 = ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__2;
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapper_gen", "__mypyc_temp__2", -1, CPyStatic_globals);
        goto CPyL96;
    }
    CPy_INCREF(cpy_r_r79);
CPyL69: ;
    cpy_r_r80 = CPyIter_Send(cpy_r_r79, cpy_r_arg);
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r80 == NULL) goto CPyL71;
    cpy_r_r66 = cpy_r_r80;
    goto CPyL52;
CPyL71: ;
    cpy_r_r81 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r63 = cpy_r_r81;
    CPy_DECREF(cpy_r_r63);
CPyL73: ;
    cpy_r_r82 = Py_None;
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL77;
    CPyGen_SetStopIterationValue(cpy_r_r82);
    if (!0) goto CPyL82;
    CPy_Unreachable();
CPyL77: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r82;
    return 0;
CPyL78: ;
    cpy_r_r84 = cpy_r_r2 == 0;
    if (cpy_r_r84) goto CPyL97;
    cpy_r_r85 = cpy_r_r2 == 1;
    if (cpy_r_r85) {
        goto CPyL53;
    } else
        goto CPyL98;
CPyL80: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r86 = 0;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_Unreachable();
CPyL82: ;
    cpy_r_r87 = NULL;
    return cpy_r_r87;
CPyL83: ;
    CPy_DecRef(cpy_r_r26);
    goto CPyL82;
CPyL84: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL82;
CPyL85: ;
    CPy_DecRef(cpy_r_r40);
    goto CPyL82;
CPyL86: ;
    CPy_DECREF(cpy_r_r44);
    goto CPyL33;
CPyL87: ;
    CPy_DecRef(cpy_r_r48);
    goto CPyL38;
CPyL88: ;
    CPy_DecRef(cpy_r_r48);
    goto CPyL82;
CPyL89: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL82;
CPyL90: ;
    CPy_DECREF(cpy_r_r52);
    goto CPyL42;
CPyL91: ;
    CPy_DecRef(cpy_r_r54);
    goto CPyL82;
CPyL92: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL56;
CPyL93: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL55;
CPyL94: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL65;
CPyL95: ;
    CPy_DecRef(cpy_r_r66);
    goto CPyL65;
CPyL96: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL82;
CPyL97: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL1;
CPyL98: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL80;
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
        CPy_TypeError("faster_async_lru.cache_close__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapper_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__next__", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.cache_close__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapper_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "send", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.cache_close__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapper_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__iter__", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.cache_close__LRUCacheWrapper_gen", obj___mypyc_self__); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "throw", -1, CPyStatic_globals);
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
    PyObject *__tmp12 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp12);
    PyObject *__tmp13 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp13);
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
        CPy_TypeError("faster_async_lru.cache_close__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapper_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "close", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.cache_close__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapper_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__await__", -1, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    CPy_INCREF_NO_IMM(cpy_r_self);
    if (((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self);
    }
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self = cpy_r_self;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL7;
    }
    ((faster_async_lru___cache_close__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__wait = cpy_r_wait;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    cpy_r_r0 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_info", "_LRUCacheWrapper", "__hits", 174, CPyStatic_globals);
        goto CPyL8;
    }
    CPyTagged_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_info", "_LRUCacheWrapper", "__misses", 175, CPyStatic_globals);
        goto CPyL9;
    }
    CPyTagged_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_info", "_LRUCacheWrapper", "__maxsize", 176, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_INCREF(cpy_r_r2);
CPyL3: ;
    cpy_r_r3 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_info", "_LRUCacheWrapper", "__cache", 177, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_info", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_info", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r11);
    if (likely(PyTuple_Check(cpy_r_r14)))
        cpy_r_r15 = cpy_r_r14;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "cache_info", 173, CPyStatic_globals, "tuple", cpy_r_r14);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef__LRUCacheWrapper___cache_info(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "cache_info", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    cpy_r_r0 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___maxsize;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_parameters", "_LRUCacheWrapper", "__maxsize", 182, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___typed;
    if (unlikely(cpy_r_r1 == 2)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_parameters", "_LRUCacheWrapper", "__typed", 183, CPyStatic_globals);
        goto CPyL9;
    }
CPyL2: ;
    cpy_r_r2 = CPyDef__LRUCacheWrapper_____tasks(cpy_r_self);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_parameters", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL9;
    }
CPyL3: ;
    cpy_r_r3 = (CPyPtr)&((PyVarObject *)cpy_r_r2)->ob_size;
    cpy_r_r4 = *(int64_t *)cpy_r_r3;
    CPy_DECREF_NO_IMM(cpy_r_r2);
    cpy_r_r5 = cpy_r_r4 << 1;
    cpy_r_r6 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___closed;
    if (unlikely(cpy_r_r6 == 2)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_parameters", "_LRUCacheWrapper", "__closed", 185, CPyStatic_globals);
        goto CPyL9;
    }
CPyL4: ;
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheParameters' */
    cpy_r_r9 = CPyDict_GetItem(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_parameters", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_parameters", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r11);
    if (likely(PyDict_Check(cpy_r_r16)))
        cpy_r_r17 = cpy_r_r16;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "cache_parameters", 181, CPyStatic_globals, "dict", cpy_r_r16);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef__LRUCacheWrapper___cache_parameters(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "cache_parameters", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    cpy_r_r0 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_cache_hit", "_LRUCacheWrapper", "__hits", 189, CPyStatic_globals);
        goto CPyL5;
    }
CPyL1: ;
    cpy_r_r1 = CPyTagged_Add(cpy_r_r0, 2);
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits != CPY_INT_TAG) {
        CPyTagged_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___hits = cpy_r_r1;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_cache_hit", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r3 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_cache_hit", "_LRUCacheWrapper", "__cache", 190, CPyStatic_globals);
        goto CPyL5;
    }
    CPy_INCREF(cpy_r_r3);
CPyL3: ;
    cpy_r_r4 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'move_to_end' */
    PyObject *cpy_r_r5[2] = {cpy_r_r3, cpy_r_key};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = PyObject_VectorcallMethod(cpy_r_r4, cpy_r_r6, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_cache_hit", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "_cache_hit", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef__LRUCacheWrapper____cache_miss(PyObject *cpy_r_self, PyObject *cpy_r_key) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    cpy_r_r0 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_cache_miss", "_LRUCacheWrapper", "__misses", 193, CPyStatic_globals);
        goto CPyL3;
    }
CPyL1: ;
    cpy_r_r1 = CPyTagged_Add(cpy_r_r0, 2);
    if (((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses != CPY_INT_TAG) {
        CPyTagged_DECREF(((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses);
    }
    ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___misses = cpy_r_r1;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_cache_miss", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "_cache_miss", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    double cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject **cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    char cpy_r_r38;
    char cpy_r_r39;
    cpy_r_r0 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cancelled' */
    PyObject *cpy_r_r1[1] = {cpy_r_task};
    cpy_r_r2 = (PyObject **)&cpy_r_r1;
    cpy_r_r3 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r2, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL26;
    }
    if (unlikely(!PyBool_Check(cpy_r_r3))) {
        CPy_TypeError("bool", cpy_r_r3); cpy_r_r4 = 2;
    } else
        cpy_r_r4 = cpy_r_r3 == Py_True;
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL26;
    }
    if (cpy_r_r4) goto CPyL5;
    cpy_r_r5 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_exception' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_task, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r7 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r8 = cpy_r_r6 != cpy_r_r7;
    CPy_DECREF(cpy_r_r6);
    if (!cpy_r_r8) goto CPyL8;
CPyL5: ;
    cpy_r_r9 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__cache", 200, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_INCREF(cpy_r_r9);
CPyL6: ;
    cpy_r_r10 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'pop' */
    cpy_r_r11 = Py_None;
    PyObject *cpy_r_r12[3] = {cpy_r_r9, cpy_r_key, cpy_r_r11};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_VectorcallMethod(cpy_r_r10, cpy_r_r13, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL27;
    } else
        goto CPyL28;
CPyL7: ;
    CPy_DECREF(cpy_r_r9);
    return 1;
CPyL8: ;
    cpy_r_r15 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___cache;
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__cache", 203, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_INCREF(cpy_r_r15);
CPyL9: ;
    cpy_r_r16 = CPyDict_GetWithNone(cpy_r_r15, cpy_r_key);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL29;
    }
    if (Py_TYPE(cpy_r_r16) == CPyType__CacheItem)
        cpy_r_r17 = cpy_r_r16;
    else {
        cpy_r_r17 = NULL;
    }
    if (cpy_r_r17 != NULL) goto __LL14;
    if (cpy_r_r16 == Py_None)
        cpy_r_r17 = cpy_r_r16;
    else {
        cpy_r_r17 = NULL;
    }
    if (cpy_r_r17 != NULL) goto __LL14;
    CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "_task_done_callback", 204, CPyStatic_globals, "faster_async_lru._CacheItem or None", cpy_r_r16);
    goto CPyL29;
__LL14: ;
    cpy_r_r18 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_self)->___ttl;
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_task_done_callback", "_LRUCacheWrapper", "__ttl", 205, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_INCREF(cpy_r_r18);
CPyL12: ;
    cpy_r_r19 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r20 = cpy_r_r18 != cpy_r_r19;
    if (!cpy_r_r20) goto CPyL31;
    cpy_r_r21 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r22 = cpy_r_r17 != cpy_r_r21;
    if (!cpy_r_r22) goto CPyL31;
    cpy_r_r23 = CPyStatic_get_running_loop;
    if (unlikely(cpy_r_r23 == NULL)) {
        goto CPyL32;
    } else
        goto CPyL17;
CPyL15: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"get_running_loop\" was not set");
    cpy_r_r24 = 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_Unreachable();
CPyL17: ;
    cpy_r_r25 = PyObject_Vectorcall(cpy_r_r23, 0, 0, 0);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r26 = PyFloat_AsDouble(cpy_r_r18);
    if (cpy_r_r26 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r18); cpy_r_r26 = -113.0;
    }
    CPy_DECREF(cpy_r_r18);
    cpy_r_r27 = cpy_r_r26 == -113.0;
    if (unlikely(cpy_r_r27)) goto CPyL20;
CPyL19: ;
    cpy_r_r28 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'pop' */
    cpy_r_r29 = CPyObject_GetAttr(cpy_r_r15, cpy_r_r28);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL34;
    } else
        goto CPyL21;
CPyL20: ;
    cpy_r_r30 = PyErr_Occurred();
    if (unlikely(cpy_r_r30 != NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL35;
    } else
        goto CPyL19;
CPyL21: ;
    cpy_r_r31 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'call_later' */
    cpy_r_r32 = PyFloat_FromDouble(cpy_r_r26);
    cpy_r_r33 = Py_None;
    PyObject *cpy_r_r34[5] = {cpy_r_r25, cpy_r_r32, cpy_r_r29, cpy_r_key, cpy_r_r33};
    cpy_r_r35 = (PyObject **)&cpy_r_r34;
    cpy_r_r36 = PyObject_VectorcallMethod(cpy_r_r31, cpy_r_r35, 9223372036854775813ULL, 0);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r32);
    CPy_DECREF(cpy_r_r29);
    if (likely(cpy_r_r17 != Py_None))
        cpy_r_r37 = cpy_r_r17;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "_task_done_callback", 208, CPyStatic_globals, "faster_async_lru._CacheItem", cpy_r_r17);
        goto CPyL37;
    }
    if (((faster_async_lru____CacheItemObject *)cpy_r_r37)->_later_call != NULL) {
        CPy_DECREF(((faster_async_lru____CacheItemObject *)cpy_r_r37)->_later_call);
    }
    ((faster_async_lru____CacheItemObject *)cpy_r_r37)->_later_call = cpy_r_r36;
    cpy_r_r38 = 1;
    if (unlikely(!cpy_r_r38)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_DECREF(cpy_r_r17);
CPyL25: ;
    return 1;
CPyL26: ;
    cpy_r_r39 = 2;
    return cpy_r_r39;
CPyL27: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL26;
CPyL28: ;
    CPy_DECREF(cpy_r_r14);
    goto CPyL7;
CPyL29: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL26;
CPyL30: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r17);
    goto CPyL26;
CPyL31: ;
    CPy_DECREF(cpy_r_r15);
    CPy_DECREF(cpy_r_r17);
    CPy_DECREF(cpy_r_r18);
    goto CPyL25;
CPyL32: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r18);
    goto CPyL15;
CPyL33: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r18);
    goto CPyL26;
CPyL34: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r25);
    goto CPyL26;
CPyL35: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r25);
    goto CPyL26;
CPyL36: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r32);
    goto CPyL26;
CPyL37: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r36);
    goto CPyL26;
CPyL38: ;
    CPy_DecRef(cpy_r_r17);
    goto CPyL26;
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "_task_done_callback", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    char cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    char cpy_r_r25;
    tuple_T3OOO cpy_r_r26;
    char cpy_r_r27;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
    tuple_T3OOO cpy_r_r31;
    tuple_T3OOO cpy_r_r32;
    tuple_T3OOO cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    char cpy_r_r38;
    tuple_T3OOO cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    char cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    CPyTagged cpy_r_r45;
    char cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject **cpy_r_r50;
    PyObject *cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject **cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject **cpy_r_r66;
    PyObject *cpy_r_r67;
    tuple_T3OOO cpy_r_r68;
    char cpy_r_r69;
    tuple_T3OOO cpy_r_r70;
    tuple_T3OOO cpy_r_r71;
    PyObject *cpy_r_r72;
    char cpy_r_r73;
    tuple_T3OOO cpy_r_r74;
    PyObject *cpy_r_r75;
    CPyTagged cpy_r_r76;
    CPyTagged cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    char cpy_r_r80;
    char cpy_r_r81;
    PyObject *cpy_r_r82;
    char cpy_r_r83;
    char cpy_r_r84;
    char cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__;
    goto CPyL93;
CPyL1: ;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = cpy_r_type != cpy_r_r3;
    if (!cpy_r_r4) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL97;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r5 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "cache_item", 215, CPyStatic_globals);
        goto CPyL97;
    }
    CPy_INCREF_NO_IMM(cpy_r_r5);
CPyL5: ;
    cpy_r_r6 = ((faster_async_lru____CacheItemObject *)cpy_r_r5)->_task;
    if (unlikely(cpy_r_r6 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'task' of '_CacheItem' undefined");
    } else {
        CPy_INCREF(cpy_r_r6);
    }
    CPy_DECREF_NO_IMM(cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL97;
    }
CPyL6: ;
    if (((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task != NULL) {
        CPy_DECREF(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task);
    }
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task = cpy_r_r6;
    cpy_r_r7 = 1;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r8 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "task", 218, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_INCREF(cpy_r_r8);
CPyL8: ;
    cpy_r_r9 = CPyStatic_shield;
    if (unlikely(cpy_r_r9 == NULL)) {
        goto CPyL98;
    } else
        goto CPyL11;
CPyL9: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"shield\" was not set");
    cpy_r_r10 = 0;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_Unreachable();
CPyL11: ;
    PyObject *cpy_r_r11[1] = {cpy_r_r8};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = PyObject_Vectorcall(cpy_r_r9, cpy_r_r12, 1, 0);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL99;
    }
    CPy_DECREF(cpy_r_r8);
    cpy_r_r14 = CPy_GetCoro(cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL41;
    }
    if (((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4 != NULL) {
        CPy_DECREF(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4);
    }
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4 = cpy_r_r14;
    cpy_r_r15 = 1;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", -1, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r16 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4;
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_INCREF(cpy_r_r16);
CPyL15: ;
    cpy_r_r17 = CPyIter_Next(cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    if (cpy_r_r17 != NULL) goto CPyL18;
    cpy_r_r18 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r19 = cpy_r_r18;
    cpy_r_r20 = NULL;
    if (((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4 != NULL) {
        CPy_DECREF(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4);
    }
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4 = cpy_r_r20;
    cpy_r_r21 = 1;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL100;
    } else
        goto CPyL40;
CPyL18: ;
    cpy_r_r22 = cpy_r_r17;
CPyL19: ;
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 1;
    return cpy_r_r22;
CPyL20: ;
    cpy_r_r24 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r25 = cpy_r_type != cpy_r_r24;
    if (!cpy_r_r25) goto CPyL101;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL24;
    } else
        goto CPyL102;
CPyL22: ;
    CPy_Unreachable();
CPyL23: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL35;
CPyL24: ;
    cpy_r_r26 = CPy_CatchError();
    if (((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5.f0 != NULL) {
        CPy_DECREF(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5.f0);
        CPy_DECREF(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5.f1);
        CPy_DECREF(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5.f2);
    }
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5 = cpy_r_r26;
    cpy_r_r27 = 1;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", -1, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r28 = (PyObject **)&cpy_r_r1;
    cpy_r_r29 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4;
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL103;
    }
    CPy_INCREF(cpy_r_r29);
CPyL26: ;
    cpy_r_r30 = CPy_YieldFromErrorHandle(cpy_r_r29, cpy_r_r28);
    CPy_DecRef(cpy_r_r29);
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL103;
    }
    if (cpy_r_r30) goto CPyL30;
    cpy_r_r22 = cpy_r_r1;
    cpy_r_r31 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5;
    if (unlikely(cpy_r_r31.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL104;
    }
    CPy_INCREF(cpy_r_r31.f0);
    CPy_INCREF(cpy_r_r31.f1);
    CPy_INCREF(cpy_r_r31.f2);
CPyL29: ;
    CPy_RestoreExcInfo(cpy_r_r31);
    CPy_DecRef(cpy_r_r31.f0);
    CPy_DecRef(cpy_r_r31.f1);
    CPy_DecRef(cpy_r_r31.f2);
    goto CPyL19;
CPyL30: ;
    cpy_r_r19 = cpy_r_r1;
    cpy_r_r32 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5;
    if (unlikely(cpy_r_r32.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL105;
    }
    CPy_INCREF(cpy_r_r32.f0);
    CPy_INCREF(cpy_r_r32.f1);
    CPy_INCREF(cpy_r_r32.f2);
CPyL31: ;
    CPy_RestoreExcInfo(cpy_r_r32);
    CPy_DecRef(cpy_r_r32.f0);
    CPy_DecRef(cpy_r_r32.f1);
    CPy_DecRef(cpy_r_r32.f2);
    goto CPyL40;
CPyL32: ;
    cpy_r_r33 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__5;
    if (unlikely(cpy_r_r33.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__5", -1, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_INCREF(cpy_r_r33.f0);
    CPy_INCREF(cpy_r_r33.f1);
    CPy_INCREF(cpy_r_r33.f2);
CPyL33: ;
    CPy_RestoreExcInfo(cpy_r_r33);
    CPy_DecRef(cpy_r_r33.f0);
    CPy_DecRef(cpy_r_r33.f1);
    CPy_DecRef(cpy_r_r33.f2);
    cpy_r_r34 = CPy_KeepPropagating();
    if (!cpy_r_r34) goto CPyL41;
    CPy_Unreachable();
CPyL35: ;
    cpy_r_r35 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__4;
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__4", -1, CPyStatic_globals);
        goto CPyL106;
    }
    CPy_INCREF(cpy_r_r35);
CPyL36: ;
    cpy_r_r36 = CPyIter_Send(cpy_r_r35, cpy_r_arg);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r36 == NULL) goto CPyL38;
    cpy_r_r22 = cpy_r_r36;
    goto CPyL19;
CPyL38: ;
    cpy_r_r37 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r19 = cpy_r_r37;
CPyL40: ;
    if (((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6 != NULL) {
        CPy_DECREF(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6);
    }
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6 = cpy_r_r19;
    cpy_r_r38 = 1;
    if (unlikely(!cpy_r_r38)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL69;
CPyL41: ;
    cpy_r_r39 = CPy_CatchError();
    if (((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7.f0 != NULL) {
        CPy_DECREF(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7.f0);
        CPy_DECREF(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7.f1);
        CPy_DECREF(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7.f2);
    }
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7 = cpy_r_r39;
    cpy_r_r40 = 1;
    if (unlikely(!cpy_r_r40)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", -1, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r41 = CPyStatic_CancelledError;
    if (likely(cpy_r_r41 != NULL)) goto CPyL45;
    PyErr_SetString(PyExc_NameError, "value for final name \"CancelledError\" was not set");
    cpy_r_r42 = 0;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_Unreachable();
CPyL45: ;
    cpy_r_r43 = CPy_ExceptionMatches(cpy_r_r41);
    if (!cpy_r_r43) goto CPyL64;
    cpy_r_r44 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "cache_item", 222, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_INCREF_NO_IMM(cpy_r_r44);
CPyL47: ;
    cpy_r_r45 = ((faster_async_lru____CacheItemObject *)cpy_r_r44)->_waiters;
    if (unlikely(cpy_r_r45 == CPY_INT_TAG)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_CacheItem", "waiters", 222, CPyStatic_globals);
        goto CPyL107;
    }
CPyL48: ;
    cpy_r_r46 = cpy_r_r45 == 2;
    CPy_DecRef(cpy_r_r44);
    if (!cpy_r_r46) goto CPyL62;
    cpy_r_r47 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "task", 222, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_INCREF(cpy_r_r47);
CPyL50: ;
    cpy_r_r48 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'done' */
    PyObject *cpy_r_r49[1] = {cpy_r_r47};
    cpy_r_r50 = (PyObject **)&cpy_r_r49;
    cpy_r_r51 = PyObject_VectorcallMethod(cpy_r_r48, cpy_r_r50, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL108;
    }
    CPy_DecRef(cpy_r_r47);
    if (unlikely(!PyBool_Check(cpy_r_r51))) {
        CPy_TypeError("bool", cpy_r_r51); cpy_r_r52 = 2;
    } else
        cpy_r_r52 = cpy_r_r51 == Py_True;
    CPy_DecRef(cpy_r_r51);
    if (unlikely(cpy_r_r52 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL66;
    }
    if (cpy_r_r52) goto CPyL62;
    cpy_r_r53 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "cache_item", 223, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_INCREF_NO_IMM(cpy_r_r53);
CPyL54: ;
    cpy_r_r54 = CPyDef__CacheItem___cancel(cpy_r_r53);
    CPy_DecRef(cpy_r_r53);
    if (unlikely(cpy_r_r54 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r55 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "task", 224, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_INCREF(cpy_r_r55);
CPyL56: ;
    cpy_r_r56 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cancel' */
    PyObject *cpy_r_r57[1] = {cpy_r_r55};
    cpy_r_r58 = (PyObject **)&cpy_r_r57;
    cpy_r_r59 = PyObject_VectorcallMethod(cpy_r_r56, cpy_r_r58, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL109;
    } else
        goto CPyL110;
CPyL57: ;
    CPy_DecRef(cpy_r_r55);
    cpy_r_r60 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "self", 225, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_INCREF_NO_IMM(cpy_r_r60);
CPyL58: ;
    cpy_r_r61 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_r60)->___cache;
    if (unlikely(cpy_r_r61 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__cache' of '_LRUCacheWrapper' undefined");
    } else {
        CPy_INCREF(cpy_r_r61);
    }
    CPy_DecRef(cpy_r_r60);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL66;
    }
CPyL59: ;
    cpy_r_r62 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "key", 225, CPyStatic_globals);
        goto CPyL111;
    }
    CPy_INCREF(cpy_r_r62);
CPyL60: ;
    cpy_r_r63 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'pop' */
    cpy_r_r64 = Py_None;
    PyObject *cpy_r_r65[3] = {cpy_r_r61, cpy_r_r62, cpy_r_r64};
    cpy_r_r66 = (PyObject **)&cpy_r_r65;
    cpy_r_r67 = PyObject_VectorcallMethod(cpy_r_r63, cpy_r_r66, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL112;
    } else
        goto CPyL113;
CPyL61: ;
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r62);
CPyL62: ;
    CPy_Reraise();
    if (!0) goto CPyL66;
    CPy_Unreachable();
CPyL64: ;
    CPy_Reraise();
    if (!0) goto CPyL66;
    CPy_Unreachable();
CPyL66: ;
    cpy_r_r68 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__7;
    if (unlikely(cpy_r_r68.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "__mypyc_temp__7", -1, CPyStatic_globals);
        goto CPyL70;
    }
    CPy_INCREF(cpy_r_r68.f0);
    CPy_INCREF(cpy_r_r68.f1);
    CPy_INCREF(cpy_r_r68.f2);
CPyL67: ;
    CPy_RestoreExcInfo(cpy_r_r68);
    CPy_DecRef(cpy_r_r68.f0);
    CPy_DecRef(cpy_r_r68.f1);
    CPy_DecRef(cpy_r_r68.f2);
    cpy_r_r69 = CPy_KeepPropagating();
    if (!cpy_r_r69) goto CPyL70;
    CPy_Unreachable();
CPyL69: ;
    tuple_T3OOO __tmp15 = { NULL, NULL, NULL };
    cpy_r_r70 = __tmp15;
    cpy_r_r71 = cpy_r_r70;
    goto CPyL72;
CPyL70: ;
    cpy_r_r72 = NULL;
    if (((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6 != NULL) {
        CPy_DECREF(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6);
    }
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6 = cpy_r_r72;
    cpy_r_r73 = 1;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", -1, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r74 = CPy_CatchError();
    cpy_r_r71 = cpy_r_r74;
CPyL72: ;
    cpy_r_r75 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_shield_and_handle_cancelled_error__LRUCacheWrapper_gen", "cache_item", 229, CPyStatic_globals);
        goto CPyL84;
    }
    CPy_INCREF_NO_IMM(cpy_r_r75);
CPyL73: ;
    cpy_r_r76 = ((faster_async_lru____CacheItemObject *)cpy_r_r75)->_waiters;
    if (unlikely(cpy_r_r76 == CPY_INT_TAG)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", "_CacheItem", "waiters", 229, CPyStatic_globals);
        goto CPyL114;
    }
CPyL74: ;
    cpy_r_r77 = CPyTagged_Subtract(cpy_r_r76, 2);
    if (((faster_async_lru____CacheItemObject *)cpy_r_r75)->_waiters != CPY_INT_TAG) {
        CPyTagged_DECREF(((faster_async_lru____CacheItemObject *)cpy_r_r75)->_waiters);
    }
    ((faster_async_lru____CacheItemObject *)cpy_r_r75)->_waiters = cpy_r_r77;
    cpy_r_r78 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r75);
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL84;
    }
    if (cpy_r_r71.f0 == NULL) goto CPyL78;
    CPy_Reraise();
    if (!0) {
        goto CPyL84;
    } else
        goto CPyL115;
CPyL77: ;
    CPy_Unreachable();
CPyL78: ;
    cpy_r_r79 = ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__6;
    if (cpy_r_r79 != NULL) {
        CPy_INCREF(cpy_r_r79);
    }
    if (cpy_r_r79 == NULL) goto CPyL88;
CPyL79: ;
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL83;
    CPyGen_SetStopIterationValue(cpy_r_r79);
    CPy_DECREF(cpy_r_r79);
    if (!0) goto CPyL97;
    CPy_Unreachable();
CPyL83: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r79;
    return 0;
CPyL84: ;
    if (cpy_r_r71.f0 == NULL) goto CPyL86;
    CPy_RestoreExcInfo(cpy_r_r71);
    CPy_XDECREF(cpy_r_r71.f0);
    CPy_XDECREF(cpy_r_r71.f1);
    CPy_XDECREF(cpy_r_r71.f2);
CPyL86: ;
    cpy_r_r81 = CPy_KeepPropagating();
    if (!cpy_r_r81) goto CPyL97;
    CPy_Unreachable();
CPyL88: ;
    cpy_r_r82 = Py_None;
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL92;
    CPyGen_SetStopIterationValue(cpy_r_r82);
    if (!0) goto CPyL97;
    CPy_Unreachable();
CPyL92: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r82;
    return 0;
CPyL93: ;
    cpy_r_r84 = cpy_r_r2 == 0;
    if (cpy_r_r84) goto CPyL116;
    cpy_r_r85 = cpy_r_r2 == 1;
    if (cpy_r_r85) {
        goto CPyL20;
    } else
        goto CPyL117;
CPyL95: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r86 = 0;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL97;
    }
    CPy_Unreachable();
CPyL97: ;
    cpy_r_r87 = NULL;
    return cpy_r_r87;
CPyL98: ;
    CPy_DecRef(cpy_r_r8);
    goto CPyL9;
CPyL99: ;
    CPy_DecRef(cpy_r_r8);
    goto CPyL41;
CPyL100: ;
    CPy_DecRef(cpy_r_r19);
    goto CPyL41;
CPyL101: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL23;
CPyL102: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL22;
CPyL103: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL32;
CPyL104: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL32;
CPyL105: ;
    CPy_DecRef(cpy_r_r19);
    goto CPyL32;
CPyL106: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL41;
CPyL107: ;
    CPy_DecRef(cpy_r_r44);
    goto CPyL66;
CPyL108: ;
    CPy_DecRef(cpy_r_r47);
    goto CPyL66;
CPyL109: ;
    CPy_DecRef(cpy_r_r55);
    goto CPyL66;
CPyL110: ;
    CPy_DecRef(cpy_r_r59);
    goto CPyL57;
CPyL111: ;
    CPy_DecRef(cpy_r_r61);
    goto CPyL66;
CPyL112: ;
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r62);
    goto CPyL66;
CPyL113: ;
    CPy_DecRef(cpy_r_r67);
    goto CPyL61;
CPyL114: ;
    CPy_DecRef(cpy_r_r75);
    goto CPyL84;
CPyL115: ;
    CPy_XDECREF(cpy_r_r71.f0);
    CPy_XDECREF(cpy_r_r71.f1);
    CPy_XDECREF(cpy_r_r71.f2);
    goto CPyL77;
CPyL116: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL1;
CPyL117: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL95;
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
        CPy_TypeError("faster_async_lru._shield_and_handle_cancelled_error__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__next__", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._shield_and_handle_cancelled_error__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "send", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._shield_and_handle_cancelled_error__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__iter__", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._shield_and_handle_cancelled_error__LRUCacheWrapper_gen", obj___mypyc_self__); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "throw", -1, CPyStatic_globals);
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
    PyObject *__tmp16 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp16);
    PyObject *__tmp17 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp17);
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
        CPy_TypeError("faster_async_lru._shield_and_handle_cancelled_error__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "close", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._shield_and_handle_cancelled_error__LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__await__", -1, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL5;
    }
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    CPy_INCREF_NO_IMM(cpy_r_self);
    if (((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self);
    }
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self = cpy_r_self;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF_NO_IMM(cpy_r_cache_item);
    if (((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__cache_item != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__cache_item);
    }
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__cache_item = cpy_r_cache_item;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_key);
    if (((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__key != NULL) {
        CPy_DECREF(((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__key);
    }
    ((faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__key = cpy_r_key;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *arg_cache_item;
    if (likely(Py_TYPE(obj_cache_item) == CPyType__CacheItem))
        arg_cache_item = obj_cache_item;
    else {
        CPy_TypeError("faster_async_lru._CacheItem", obj_cache_item); 
        goto fail;
    }
    PyObject *arg_key = obj_key;
    PyObject *retval = CPyDef__LRUCacheWrapper____shield_and_handle_cancelled_error(arg_self, arg_cache_item, arg_key);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "_shield_and_handle_cancelled_error", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    PyObject *cpy_r_r29;
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    char cpy_r_r32;
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
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    char cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    char cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    CPyTagged cpy_r_r59;
    CPyTagged cpy_r_r60;
    char cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject **cpy_r_r71;
    PyObject *cpy_r_r72;
    char cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    char cpy_r_r76;
    PyObject *cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    char cpy_r_r80;
    tuple_T3OOO cpy_r_r81;
    char cpy_r_r82;
    PyObject **cpy_r_r83;
    PyObject *cpy_r_r84;
    char cpy_r_r85;
    tuple_T3OOO cpy_r_r86;
    tuple_T3OOO cpy_r_r87;
    tuple_T3OOO cpy_r_r88;
    char cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    char cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject **cpy_r_r97;
    PyObject *cpy_r_r98;
    char cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    char cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject **cpy_r_r112;
    PyObject *cpy_r_r113;
    char cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    char cpy_r_r121;
    PyObject **cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject **cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    char cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    int32_t cpy_r_r137;
    char cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    char cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    char cpy_r_r144;
    PyObject *cpy_r_r145;
    int64_t cpy_r_r146;
    CPyTagged cpy_r_r147;
    PyObject *cpy_r_r148;
    CPyTagged cpy_r_r149;
    int64_t cpy_r_r150;
    char cpy_r_r151;
    int64_t cpy_r_r152;
    char cpy_r_r153;
    char cpy_r_r154;
    char cpy_r_r155;
    char cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject **cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    tuple_T2OO cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    char cpy_r_r168;
    PyObject *cpy_r_r169;
    char cpy_r_r170;
    PyObject *cpy_r_r171;
    char cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    char cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    char cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject **cpy_r_r185;
    PyObject *cpy_r_r186;
    char cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    char cpy_r_r190;
    PyObject *cpy_r_r191;
    char cpy_r_r192;
    PyObject *cpy_r_r193;
    char cpy_r_r194;
    tuple_T3OOO cpy_r_r195;
    char cpy_r_r196;
    PyObject **cpy_r_r197;
    PyObject *cpy_r_r198;
    char cpy_r_r199;
    tuple_T3OOO cpy_r_r200;
    tuple_T3OOO cpy_r_r201;
    tuple_T3OOO cpy_r_r202;
    char cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    char cpy_r_r207;
    char cpy_r_r208;
    char cpy_r_r209;
    char cpy_r_r210;
    char cpy_r_r211;
    PyObject *cpy_r_r212;
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
    cpy_r_r8 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__;
    goto CPyL183;
CPyL1: ;
    cpy_r_r9 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r10 = cpy_r_type != cpy_r_r9;
    if (!cpy_r_r10) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r11 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 234, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF_NO_IMM(cpy_r_r11);
CPyL5: ;
    cpy_r_r12 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_r11)->___closed;
    if (unlikely(cpy_r_r12 == 2)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__closed' of '_LRUCacheWrapper' undefined");
    }
    CPy_DECREF_NO_IMM(cpy_r_r11);
    if (unlikely(cpy_r_r12 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
CPyL6: ;
    if (!cpy_r_r12) goto CPyL14;
CPyL7: ;
    cpy_r_r13 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'alru_cache is closed for ' */
    cpy_r_r14 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 235, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF_NO_IMM(cpy_r_r14);
CPyL8: ;
    cpy_r_r15 = PyObject_Str(cpy_r_r14);
    CPy_DECREF_NO_IMM(cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r16 = CPyStr_Build(2, cpy_r_r13, cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'RuntimeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_Unreachable();
CPyL14: ;
    cpy_r_r23 = CPyStatic_get_running_loop;
    if (likely(cpy_r_r23 != NULL)) goto CPyL17;
    PyErr_SetString(PyExc_NameError, "value for final name \"get_running_loop\" was not set");
    cpy_r_r24 = 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_Unreachable();
CPyL17: ;
    cpy_r_r25 = PyObject_Vectorcall(cpy_r_r23, 0, 0, 0);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop = cpy_r_r25;
    cpy_r_r26 = 1;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r27 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_args;
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "fn_args", 239, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r27);
CPyL20: ;
    cpy_r_r28 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_kwargs;
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "fn_kwargs", 239, CPyStatic_globals);
        goto CPyL190;
    }
    CPy_INCREF(cpy_r_r28);
CPyL21: ;
    cpy_r_r29 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 239, CPyStatic_globals);
        goto CPyL191;
    }
    CPy_INCREF_NO_IMM(cpy_r_r29);
CPyL22: ;
    cpy_r_r30 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_r29)->___typed;
    if (unlikely(cpy_r_r30 == 2)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__typed' of '_LRUCacheWrapper' undefined");
    }
    CPy_DECREF_NO_IMM(cpy_r_r29);
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL191;
    }
CPyL23: ;
    cpy_r_r31 = CPyDef__make_key(cpy_r_r27, cpy_r_r28, cpy_r_r30);
    CPy_DECREF(cpy_r_r27);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key = cpy_r_r31;
    cpy_r_r32 = 1;
    if (unlikely(!cpy_r_r32)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r33 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 241, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF_NO_IMM(cpy_r_r33);
CPyL26: ;
    cpy_r_r34 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_r33)->___cache;
    if (unlikely(cpy_r_r34 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__cache' of '_LRUCacheWrapper' undefined");
    } else {
        CPy_INCREF(cpy_r_r34);
    }
    CPy_DECREF_NO_IMM(cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
CPyL27: ;
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache = cpy_r_r34;
    cpy_r_r35 = 1;
    if (unlikely(!cpy_r_r35)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r36 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache;
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache", 243, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r36);
CPyL29: ;
    cpy_r_r37 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 243, CPyStatic_globals);
        goto CPyL192;
    }
    CPy_INCREF(cpy_r_r37);
CPyL30: ;
    cpy_r_r38 = CPyDict_GetWithNone(cpy_r_r36, cpy_r_r37);
    CPy_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    if (Py_TYPE(cpy_r_r38) == CPyType__CacheItem)
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL18;
    if (cpy_r_r38 == Py_None)
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL18;
    CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__call__", 243, CPyStatic_globals, "faster_async_lru._CacheItem or None", cpy_r_r38);
    goto CPyL188;
__LL18: ;
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item = cpy_r_r39;
    cpy_r_r40 = 1;
    if (unlikely(!cpy_r_r40)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r41 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 245, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r41);
CPyL34: ;
    cpy_r_r42 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r43 = cpy_r_r41 != cpy_r_r42;
    CPy_DECREF(cpy_r_r41);
    if (!cpy_r_r43) goto CPyL94;
    cpy_r_r44 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 246, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF_NO_IMM(cpy_r_r44);
CPyL36: ;
    cpy_r_r45 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 246, CPyStatic_globals);
        goto CPyL193;
    }
    CPy_INCREF(cpy_r_r45);
CPyL37: ;
    cpy_r_r46 = CPyDef__LRUCacheWrapper____cache_hit(cpy_r_r44, cpy_r_r45);
    CPy_DECREF(cpy_r_r45);
    CPy_DECREF_NO_IMM(cpy_r_r44);
    if (unlikely(cpy_r_r46 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r47 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 247, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r47);
CPyL39: ;
    if (likely(cpy_r_r47 != Py_None))
        cpy_r_r48 = cpy_r_r47;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__call__", 247, CPyStatic_globals, "faster_async_lru._CacheItem", cpy_r_r47);
        goto CPyL194;
    }
    cpy_r_r49 = ((faster_async_lru____CacheItemObject *)cpy_r_r48)->_task;
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "_CacheItem", "task", 247, CPyStatic_globals);
        goto CPyL194;
    }
    CPy_INCREF(cpy_r_r49);
CPyL41: ;
    CPy_DECREF(cpy_r_r47);
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task = cpy_r_r49;
    cpy_r_r50 = 1;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r51 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "task", 248, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r51);
CPyL43: ;
    cpy_r_r52 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'done' */
    PyObject *cpy_r_r53[1] = {cpy_r_r51};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = PyObject_VectorcallMethod(cpy_r_r52, cpy_r_r54, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL195;
    }
    CPy_DECREF(cpy_r_r51);
    if (unlikely(!PyBool_Check(cpy_r_r55))) {
        CPy_TypeError("bool", cpy_r_r55); cpy_r_r56 = 2;
    } else
        cpy_r_r56 = cpy_r_r55 == Py_True;
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r56 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    if (cpy_r_r56) goto CPyL87;
    cpy_r_r57 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 250, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r57);
CPyL47: ;
    if (likely(cpy_r_r57 != Py_None))
        cpy_r_r58 = cpy_r_r57;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__call__", 250, CPyStatic_globals, "faster_async_lru._CacheItem", cpy_r_r57);
        goto CPyL196;
    }
    cpy_r_r59 = ((faster_async_lru____CacheItemObject *)cpy_r_r58)->_waiters;
    if (unlikely(cpy_r_r59 == CPY_INT_TAG)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "_CacheItem", "waiters", 250, CPyStatic_globals);
        goto CPyL196;
    }
CPyL49: ;
    cpy_r_r60 = CPyTagged_Add(cpy_r_r59, 2);
    if (((faster_async_lru____CacheItemObject *)cpy_r_r58)->_waiters != CPY_INT_TAG) {
        CPyTagged_DECREF(((faster_async_lru____CacheItemObject *)cpy_r_r58)->_waiters);
    }
    ((faster_async_lru____CacheItemObject *)cpy_r_r58)->_waiters = cpy_r_r60;
    cpy_r_r61 = 1;
    if (unlikely(!cpy_r_r61)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL196;
    }
    CPy_DECREF(cpy_r_r57);
    cpy_r_r62 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 251, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF_NO_IMM(cpy_r_r62);
CPyL51: ;
    cpy_r_r63 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 251, CPyStatic_globals);
        goto CPyL197;
    }
    CPy_INCREF(cpy_r_r63);
CPyL52: ;
    if (likely(cpy_r_r63 != Py_None))
        cpy_r_r64 = cpy_r_r63;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__call__", 251, CPyStatic_globals, "faster_async_lru._CacheItem", cpy_r_r63);
        goto CPyL197;
    }
    cpy_r_r65 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 251, CPyStatic_globals);
        goto CPyL198;
    }
    CPy_INCREF(cpy_r_r65);
CPyL54: ;
    cpy_r_r66 = CPyDef__LRUCacheWrapper____shield_and_handle_cancelled_error(cpy_r_r62, cpy_r_r64, cpy_r_r65);
    CPy_DECREF_NO_IMM(cpy_r_r64);
    CPy_DECREF(cpy_r_r65);
    CPy_DECREF_NO_IMM(cpy_r_r62);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8 != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8 = cpy_r_r66;
    cpy_r_r67 = 1;
    if (unlikely(!cpy_r_r67)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r68 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8;
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF_NO_IMM(cpy_r_r68);
CPyL57: ;
    cpy_r_r69 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r70 = NULL;
    cpy_r_r1 = cpy_r_r70;
    cpy_r_r71 = (PyObject **)&cpy_r_r1;
    cpy_r_r72 = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r_r68, cpy_r_r69, cpy_r_r69, cpy_r_r69, cpy_r_r69, cpy_r_r71);
    CPy_DECREF_NO_IMM(cpy_r_r68);
    if (cpy_r_r72 != NULL) goto CPyL199;
    cpy_r_r73 = cpy_r_r1 != 0;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL200;
    }
    cpy_r_r74 = cpy_r_r1;
    cpy_r_r75 = NULL;
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8 != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8 = cpy_r_r75;
    cpy_r_r76 = 1;
    if (unlikely(!cpy_r_r76)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL201;
    } else
        goto CPyL82;
CPyL60: ;
    cpy_r_r77 = cpy_r_r72;
CPyL61: ;
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 1;
    return cpy_r_r77;
CPyL62: ;
    cpy_r_r79 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r80 = cpy_r_type != cpy_r_r79;
    if (!cpy_r_r80) goto CPyL202;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL66;
    } else
        goto CPyL203;
CPyL64: ;
    CPy_Unreachable();
CPyL65: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL77;
CPyL66: ;
    cpy_r_r81 = CPy_CatchError();
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9.f0 != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9.f0);
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9.f1);
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9.f2);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9 = cpy_r_r81;
    cpy_r_r82 = 1;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL204;
    }
    cpy_r_r83 = (PyObject **)&cpy_r_r3;
    cpy_r_r84 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8;
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL204;
    }
    CPy_INCREF_NO_IMM(cpy_r_r84);
CPyL68: ;
    cpy_r_r85 = CPy_YieldFromErrorHandle(cpy_r_r84, cpy_r_r83);
    CPy_DecRef(cpy_r_r84);
    if (unlikely(cpy_r_r85 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL204;
    }
    if (cpy_r_r85) goto CPyL72;
    cpy_r_r77 = cpy_r_r3;
    cpy_r_r86 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9;
    if (unlikely(cpy_r_r86.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL205;
    }
    CPy_INCREF(cpy_r_r86.f0);
    CPy_INCREF(cpy_r_r86.f1);
    CPy_INCREF(cpy_r_r86.f2);
CPyL71: ;
    CPy_RestoreExcInfo(cpy_r_r86);
    CPy_DecRef(cpy_r_r86.f0);
    CPy_DecRef(cpy_r_r86.f1);
    CPy_DecRef(cpy_r_r86.f2);
    goto CPyL61;
CPyL72: ;
    cpy_r_r74 = cpy_r_r3;
    cpy_r_r87 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9;
    if (unlikely(cpy_r_r87.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL206;
    }
    CPy_INCREF(cpy_r_r87.f0);
    CPy_INCREF(cpy_r_r87.f1);
    CPy_INCREF(cpy_r_r87.f2);
CPyL73: ;
    CPy_RestoreExcInfo(cpy_r_r87);
    CPy_DecRef(cpy_r_r87.f0);
    CPy_DecRef(cpy_r_r87.f1);
    CPy_DecRef(cpy_r_r87.f2);
    goto CPyL82;
CPyL74: ;
    cpy_r_r88 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__9;
    if (unlikely(cpy_r_r88.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__9", -1, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r88.f0);
    CPy_INCREF(cpy_r_r88.f1);
    CPy_INCREF(cpy_r_r88.f2);
CPyL75: ;
    CPy_RestoreExcInfo(cpy_r_r88);
    CPy_DecRef(cpy_r_r88.f0);
    CPy_DecRef(cpy_r_r88.f1);
    CPy_DecRef(cpy_r_r88.f2);
    cpy_r_r89 = CPy_KeepPropagating();
    if (!cpy_r_r89) goto CPyL188;
    CPy_Unreachable();
CPyL77: ;
    cpy_r_r90 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__8;
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__8", -1, CPyStatic_globals);
        goto CPyL207;
    }
    CPy_INCREF_NO_IMM(cpy_r_r90);
CPyL78: ;
    cpy_r_r91 = CPyIter_Send(cpy_r_r90, cpy_r_arg);
    CPy_DECREF_NO_IMM(cpy_r_r90);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r91 == NULL) goto CPyL80;
    cpy_r_r77 = cpy_r_r91;
    goto CPyL61;
CPyL80: ;
    cpy_r_r92 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r74 = cpy_r_r92;
CPyL82: ;
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL86;
    CPyGen_SetStopIterationValue(cpy_r_r74);
    CPy_DECREF(cpy_r_r74);
    if (!0) goto CPyL188;
    CPy_Unreachable();
CPyL86: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r74;
    return 0;
CPyL87: ;
    cpy_r_r94 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "task", 254, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r94);
CPyL88: ;
    cpy_r_r95 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'result' */
    PyObject *cpy_r_r96[1] = {cpy_r_r94};
    cpy_r_r97 = (PyObject **)&cpy_r_r96;
    cpy_r_r98 = PyObject_VectorcallMethod(cpy_r_r95, cpy_r_r97, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL208;
    }
    CPy_DECREF(cpy_r_r94);
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL93;
    CPyGen_SetStopIterationValue(cpy_r_r98);
    CPy_DECREF(cpy_r_r98);
    if (!0) goto CPyL188;
    CPy_Unreachable();
CPyL93: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r98;
    return 0;
CPyL94: ;
    cpy_r_r100 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 256, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF_NO_IMM(cpy_r_r100);
CPyL95: ;
    cpy_r_r101 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_args;
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "fn_args", 256, CPyStatic_globals);
        goto CPyL209;
    }
    CPy_INCREF(cpy_r_r101);
CPyL96: ;
    cpy_r_r102 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_kwargs;
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "fn_kwargs", 256, CPyStatic_globals);
        goto CPyL210;
    }
    CPy_INCREF(cpy_r_r102);
CPyL97: ;
    cpy_r_r103 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapped__' */
    cpy_r_r104 = CPyObject_GetAttr(cpy_r_r100, cpy_r_r103);
    CPy_DECREF_NO_IMM(cpy_r_r100);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r105 = PyDict_Copy(cpy_r_r102);
    CPy_DECREF(cpy_r_r102);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL212;
    }
    cpy_r_r106 = PyObject_Call(cpy_r_r104, cpy_r_r101, cpy_r_r105);
    CPy_DECREF(cpy_r_r104);
    CPy_DECREF(cpy_r_r101);
    CPy_DECREF(cpy_r_r105);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__coro != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__coro);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__coro = cpy_r_r106;
    cpy_r_r107 = 1;
    if (unlikely(!cpy_r_r107)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r108 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__loop;
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "loop", 257, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r108);
CPyL102: ;
    cpy_r_r109 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__coro;
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "coro", 257, CPyStatic_globals);
        goto CPyL213;
    }
    CPy_INCREF(cpy_r_r109);
CPyL103: ;
    cpy_r_r110 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'create_task' */
    PyObject *cpy_r_r111[2] = {cpy_r_r108, cpy_r_r109};
    cpy_r_r112 = (PyObject **)&cpy_r_r111;
    cpy_r_r113 = PyObject_VectorcallMethod(cpy_r_r110, cpy_r_r112, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL214;
    }
    CPy_DECREF(cpy_r_r108);
    CPy_DECREF(cpy_r_r109);
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task = cpy_r_r113;
    cpy_r_r114 = 1;
    if (unlikely(!cpy_r_r114)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r115 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "task", 258, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r115);
CPyL106: ;
    cpy_r_r116 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 258, CPyStatic_globals);
        goto CPyL215;
    }
    CPy_INCREF_NO_IMM(cpy_r_r116);
CPyL107: ;
    cpy_r_r117 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_task_done_callback' */
    cpy_r_r118 = CPyObject_GetAttr(cpy_r_r116, cpy_r_r117);
    CPy_DECREF_NO_IMM(cpy_r_r116);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL215;
    }
    cpy_r_r119 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 258, CPyStatic_globals);
        goto CPyL216;
    }
    CPy_INCREF(cpy_r_r119);
CPyL109: ;
    cpy_r_r120 = CPyStatic_partial;
    if (unlikely(cpy_r_r120 == NULL)) {
        goto CPyL217;
    } else
        goto CPyL112;
CPyL110: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"partial\" was not set");
    cpy_r_r121 = 0;
    if (unlikely(!cpy_r_r121)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_Unreachable();
CPyL112: ;
    PyObject *cpy_r_r122[2] = {cpy_r_r118, cpy_r_r119};
    cpy_r_r123 = (PyObject **)&cpy_r_r122;
    cpy_r_r124 = PyObject_Vectorcall(cpy_r_r120, cpy_r_r123, 2, 0);
    if (unlikely(cpy_r_r124 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL218;
    }
    CPy_DECREF(cpy_r_r118);
    CPy_DECREF(cpy_r_r119);
    cpy_r_r125 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'add_done_callback' */
    PyObject *cpy_r_r126[2] = {cpy_r_r115, cpy_r_r124};
    cpy_r_r127 = (PyObject **)&cpy_r_r126;
    cpy_r_r128 = PyObject_VectorcallMethod(cpy_r_r125, cpy_r_r127, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL219;
    } else
        goto CPyL220;
CPyL114: ;
    CPy_DECREF(cpy_r_r115);
    CPy_DECREF(cpy_r_r124);
    cpy_r_r129 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__task;
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "task", 260, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r129);
CPyL115: ;
    cpy_r_r130 = CPyDef__CacheItem(cpy_r_r129);
    CPy_DECREF(cpy_r_r129);
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item = cpy_r_r130;
    cpy_r_r131 = 1;
    if (unlikely(!cpy_r_r131)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r132 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 261, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r132);
CPyL118: ;
    if (likely(cpy_r_r132 != Py_None))
        cpy_r_r133 = cpy_r_r132;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__call__", 261, CPyStatic_globals, "faster_async_lru._CacheItem", cpy_r_r132);
        goto CPyL188;
    }
    cpy_r_r134 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 261, CPyStatic_globals);
        goto CPyL221;
    }
    CPy_INCREF_NO_IMM(cpy_r_r134);
CPyL120: ;
    cpy_r_r135 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_r134)->___cache;
    if (unlikely(cpy_r_r135 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__cache' of '_LRUCacheWrapper' undefined");
    } else {
        CPy_INCREF(cpy_r_r135);
    }
    CPy_DECREF_NO_IMM(cpy_r_r134);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL221;
    }
CPyL121: ;
    cpy_r_r136 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 261, CPyStatic_globals);
        goto CPyL222;
    }
    CPy_INCREF(cpy_r_r136);
CPyL122: ;
    cpy_r_r137 = CPyDict_SetItem(cpy_r_r135, cpy_r_r136, cpy_r_r133);
    CPy_DECREF(cpy_r_r135);
    CPy_DECREF(cpy_r_r136);
    CPy_DECREF_NO_IMM(cpy_r_r133);
    cpy_r_r138 = cpy_r_r137 >= 0;
    if (unlikely(!cpy_r_r138)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r139 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r139 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 263, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF_NO_IMM(cpy_r_r139);
CPyL124: ;
    cpy_r_r140 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_r139)->___maxsize;
    if (unlikely(cpy_r_r140 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__maxsize' of '_LRUCacheWrapper' undefined");
    } else {
        CPy_INCREF(cpy_r_r140);
    }
    CPy_DECREF_NO_IMM(cpy_r_r139);
    if (unlikely(cpy_r_r140 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
CPyL125: ;
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__maxsize != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__maxsize);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__maxsize = cpy_r_r140;
    cpy_r_r141 = 1;
    if (unlikely(!cpy_r_r141)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r142 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__maxsize;
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "maxsize", 265, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r142);
CPyL127: ;
    cpy_r_r143 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r144 = cpy_r_r142 != cpy_r_r143;
    CPy_DECREF(cpy_r_r142);
    if (!cpy_r_r144) goto CPyL143;
    cpy_r_r145 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache;
    if (unlikely(cpy_r_r145 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache", 265, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r145);
CPyL129: ;
    cpy_r_r146 = PyDict_Size(cpy_r_r145);
    CPy_DECREF(cpy_r_r145);
    cpy_r_r147 = cpy_r_r146 << 1;
    cpy_r_r148 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__maxsize;
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "maxsize", 265, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r148);
CPyL130: ;
    if (likely(PyLong_Check(cpy_r_r148)))
        cpy_r_r149 = CPyTagged_FromObject(cpy_r_r148);
    else {
        CPy_TypeError("int", cpy_r_r148); cpy_r_r149 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r148);
    if (unlikely(cpy_r_r149 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r150 = cpy_r_r147 & 1;
    cpy_r_r151 = cpy_r_r150 != 0;
    if (cpy_r_r151) goto CPyL133;
    cpy_r_r152 = cpy_r_r149 & 1;
    cpy_r_r153 = cpy_r_r152 != 0;
    if (!cpy_r_r153) goto CPyL134;
CPyL133: ;
    cpy_r_r154 = CPyTagged_IsLt_(cpy_r_r149, cpy_r_r147);
    cpy_r_r155 = cpy_r_r154;
    goto CPyL135;
CPyL134: ;
    cpy_r_r156 = (Py_ssize_t)cpy_r_r147 > (Py_ssize_t)cpy_r_r149;
    cpy_r_r155 = cpy_r_r156;
CPyL135: ;
    CPyTagged_DECREF(cpy_r_r149);
    if (!cpy_r_r155) goto CPyL143;
    cpy_r_r157 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache;
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache", 266, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r157);
CPyL137: ;
    cpy_r_r158 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'popitem' */
    cpy_r_r159 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r160[2] = {cpy_r_r157, cpy_r_r159};
    cpy_r_r161 = (PyObject **)&cpy_r_r160;
    cpy_r_r162 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('last',) */
    cpy_r_r163 = PyObject_VectorcallMethod(cpy_r_r158, cpy_r_r161, 9223372036854775809ULL, cpy_r_r162);
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL223;
    }
    CPy_DECREF(cpy_r_r157);
    PyObject *__tmp19;
    if (unlikely(!(PyTuple_Check(cpy_r_r163) && PyTuple_GET_SIZE(cpy_r_r163) == 2))) {
        __tmp19 = NULL;
        goto __LL20;
    }
    __tmp19 = PyTuple_GET_ITEM(cpy_r_r163, 0);
    if (__tmp19 == NULL) goto __LL20;
    if (likely(Py_TYPE(PyTuple_GET_ITEM(cpy_r_r163, 1)) == CPyType__CacheItem))
        __tmp19 = PyTuple_GET_ITEM(cpy_r_r163, 1);
    else {
        __tmp19 = NULL;
    }
    if (__tmp19 == NULL) goto __LL20;
    __tmp19 = cpy_r_r163;
__LL20: ;
    if (unlikely(__tmp19 == NULL)) {
        CPy_TypeError("tuple[object, faster_async_lru._CacheItem]", cpy_r_r163); cpy_r_r164 = (tuple_T2OO) { NULL, NULL };
    } else {
        PyObject *__tmp21 = PyTuple_GET_ITEM(cpy_r_r163, 0);
        CPy_INCREF(__tmp21);
        PyObject *__tmp22;
        __tmp22 = __tmp21;
        cpy_r_r164.f0 = __tmp22;
        PyObject *__tmp23 = PyTuple_GET_ITEM(cpy_r_r163, 1);
        CPy_INCREF(__tmp23);
        PyObject *__tmp24;
        if (likely(Py_TYPE(__tmp23) == CPyType__CacheItem))
            __tmp24 = __tmp23;
        else {
            CPy_TypeError("faster_async_lru._CacheItem", __tmp23); 
            __tmp24 = NULL;
        }
        cpy_r_r164.f1 = __tmp24;
    }
    CPy_DECREF(cpy_r_r163);
    if (unlikely(cpy_r_r164.f0 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r165 = cpy_r_r164.f0;
    cpy_r_r166 = cpy_r_r164.f1;
    cpy_r_r167 = cpy_r_r165;
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_key != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_key);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_key = cpy_r_r167;
    cpy_r_r168 = 1;
    if (unlikely(!cpy_r_r168)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r169 = cpy_r_r166;
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_cache_item != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_cache_item);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_cache_item = cpy_r_r169;
    cpy_r_r170 = 1;
    if (unlikely(!cpy_r_r170)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r171 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__dropped_cache_item;
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "dropped_cache_item", 267, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF_NO_IMM(cpy_r_r171);
CPyL142: ;
    cpy_r_r172 = CPyDef__CacheItem___cancel(cpy_r_r171);
    CPy_DECREF_NO_IMM(cpy_r_r171);
    if (unlikely(cpy_r_r172 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
CPyL143: ;
    cpy_r_r173 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r173 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 269, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF_NO_IMM(cpy_r_r173);
CPyL144: ;
    cpy_r_r174 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r174 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 269, CPyStatic_globals);
        goto CPyL224;
    }
    CPy_INCREF(cpy_r_r174);
CPyL145: ;
    cpy_r_r175 = CPyDef__LRUCacheWrapper____cache_miss(cpy_r_r173, cpy_r_r174);
    CPy_DECREF(cpy_r_r174);
    CPy_DECREF_NO_IMM(cpy_r_r173);
    if (unlikely(cpy_r_r175 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r176 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r176 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "self", 271, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF_NO_IMM(cpy_r_r176);
CPyL147: ;
    cpy_r_r177 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__cache_item;
    if (unlikely(cpy_r_r177 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "cache_item", 271, CPyStatic_globals);
        goto CPyL225;
    }
    CPy_INCREF(cpy_r_r177);
CPyL148: ;
    if (likely(cpy_r_r177 != Py_None))
        cpy_r_r178 = cpy_r_r177;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__call__", 271, CPyStatic_globals, "faster_async_lru._CacheItem", cpy_r_r177);
        goto CPyL225;
    }
    cpy_r_r179 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__key;
    if (unlikely(cpy_r_r179 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "key", 271, CPyStatic_globals);
        goto CPyL226;
    }
    CPy_INCREF(cpy_r_r179);
CPyL150: ;
    cpy_r_r180 = CPyDef__LRUCacheWrapper____shield_and_handle_cancelled_error(cpy_r_r176, cpy_r_r178, cpy_r_r179);
    CPy_DECREF_NO_IMM(cpy_r_r178);
    CPy_DECREF(cpy_r_r179);
    CPy_DECREF_NO_IMM(cpy_r_r176);
    if (unlikely(cpy_r_r180 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10 != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10 = cpy_r_r180;
    cpy_r_r181 = 1;
    if (unlikely(!cpy_r_r181)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r182 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10;
    if (unlikely(cpy_r_r182 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF_NO_IMM(cpy_r_r182);
CPyL153: ;
    cpy_r_r183 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r184 = NULL;
    cpy_r_r5 = cpy_r_r184;
    cpy_r_r185 = (PyObject **)&cpy_r_r5;
    cpy_r_r186 = CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen_____mypyc_generator_helper__(cpy_r_r182, cpy_r_r183, cpy_r_r183, cpy_r_r183, cpy_r_r183, cpy_r_r185);
    CPy_DECREF_NO_IMM(cpy_r_r182);
    if (cpy_r_r186 != NULL) goto CPyL227;
    cpy_r_r187 = cpy_r_r5 != 0;
    if (unlikely(!cpy_r_r187)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL228;
    }
    cpy_r_r188 = cpy_r_r5;
    cpy_r_r189 = NULL;
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10 != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10 = cpy_r_r189;
    cpy_r_r190 = 1;
    if (unlikely(!cpy_r_r190)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL229;
    } else
        goto CPyL178;
CPyL156: ;
    cpy_r_r191 = cpy_r_r186;
CPyL157: ;
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 2;
    return cpy_r_r191;
CPyL158: ;
    cpy_r_r193 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r194 = cpy_r_type != cpy_r_r193;
    if (!cpy_r_r194) goto CPyL230;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL162;
    } else
        goto CPyL231;
CPyL160: ;
    CPy_Unreachable();
CPyL161: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL173;
CPyL162: ;
    cpy_r_r195 = CPy_CatchError();
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11.f0 != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11.f0);
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11.f1);
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11.f2);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11 = cpy_r_r195;
    cpy_r_r196 = 1;
    if (unlikely(!cpy_r_r196)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL232;
    }
    cpy_r_r197 = (PyObject **)&cpy_r_r7;
    cpy_r_r198 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10;
    if (unlikely(cpy_r_r198 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL232;
    }
    CPy_INCREF_NO_IMM(cpy_r_r198);
CPyL164: ;
    cpy_r_r199 = CPy_YieldFromErrorHandle(cpy_r_r198, cpy_r_r197);
    CPy_DecRef(cpy_r_r198);
    if (unlikely(cpy_r_r199 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL232;
    }
    if (cpy_r_r199) goto CPyL168;
    cpy_r_r191 = cpy_r_r7;
    cpy_r_r200 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11;
    if (unlikely(cpy_r_r200.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL233;
    }
    CPy_INCREF(cpy_r_r200.f0);
    CPy_INCREF(cpy_r_r200.f1);
    CPy_INCREF(cpy_r_r200.f2);
CPyL167: ;
    CPy_RestoreExcInfo(cpy_r_r200);
    CPy_DecRef(cpy_r_r200.f0);
    CPy_DecRef(cpy_r_r200.f1);
    CPy_DecRef(cpy_r_r200.f2);
    goto CPyL157;
CPyL168: ;
    cpy_r_r188 = cpy_r_r7;
    cpy_r_r201 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11;
    if (unlikely(cpy_r_r201.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL234;
    }
    CPy_INCREF(cpy_r_r201.f0);
    CPy_INCREF(cpy_r_r201.f1);
    CPy_INCREF(cpy_r_r201.f2);
CPyL169: ;
    CPy_RestoreExcInfo(cpy_r_r201);
    CPy_DecRef(cpy_r_r201.f0);
    CPy_DecRef(cpy_r_r201.f1);
    CPy_DecRef(cpy_r_r201.f2);
    goto CPyL178;
CPyL170: ;
    cpy_r_r202 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__11;
    if (unlikely(cpy_r_r202.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__11", -1, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r202.f0);
    CPy_INCREF(cpy_r_r202.f1);
    CPy_INCREF(cpy_r_r202.f2);
CPyL171: ;
    CPy_RestoreExcInfo(cpy_r_r202);
    CPy_DecRef(cpy_r_r202.f0);
    CPy_DecRef(cpy_r_r202.f1);
    CPy_DecRef(cpy_r_r202.f2);
    cpy_r_r203 = CPy_KeepPropagating();
    if (!cpy_r_r203) goto CPyL188;
    CPy_Unreachable();
CPyL173: ;
    cpy_r_r204 = ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__10;
    if (unlikely(cpy_r_r204 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapper_gen", "__mypyc_temp__10", -1, CPyStatic_globals);
        goto CPyL235;
    }
    CPy_INCREF_NO_IMM(cpy_r_r204);
CPyL174: ;
    cpy_r_r205 = CPyIter_Send(cpy_r_r204, cpy_r_arg);
    CPy_DECREF_NO_IMM(cpy_r_r204);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r205 == NULL) goto CPyL176;
    cpy_r_r191 = cpy_r_r205;
    goto CPyL157;
CPyL176: ;
    cpy_r_r206 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r206 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r188 = cpy_r_r206;
CPyL178: ;
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
    if (cpy_r_stop_iter_ptr != NULL) goto CPyL182;
    CPyGen_SetStopIterationValue(cpy_r_r188);
    CPy_DECREF(cpy_r_r188);
    if (!0) goto CPyL188;
    CPy_Unreachable();
CPyL182: ;
    *(PyObject * *)cpy_r_stop_iter_ptr = cpy_r_r188;
    return 0;
CPyL183: ;
    cpy_r_r208 = cpy_r_r8 == 0;
    if (cpy_r_r208) goto CPyL236;
    cpy_r_r209 = cpy_r_r8 == 1;
    if (cpy_r_r209) {
        goto CPyL237;
    } else
        goto CPyL238;
CPyL185: ;
    cpy_r_r210 = cpy_r_r8 == 2;
    if (cpy_r_r210) {
        goto CPyL158;
    } else
        goto CPyL239;
CPyL186: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r211 = 0;
    if (unlikely(!cpy_r_r211)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    CPy_Unreachable();
CPyL188: ;
    cpy_r_r212 = NULL;
    return cpy_r_r212;
CPyL189: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL188;
CPyL190: ;
    CPy_DecRef(cpy_r_r27);
    goto CPyL188;
CPyL191: ;
    CPy_DecRef(cpy_r_r27);
    CPy_DecRef(cpy_r_r28);
    goto CPyL188;
CPyL192: ;
    CPy_DecRef(cpy_r_r36);
    goto CPyL188;
CPyL193: ;
    CPy_DecRef(cpy_r_r44);
    goto CPyL188;
CPyL194: ;
    CPy_DecRef(cpy_r_r47);
    goto CPyL188;
CPyL195: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL188;
CPyL196: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL188;
CPyL197: ;
    CPy_DecRef(cpy_r_r62);
    goto CPyL188;
CPyL198: ;
    CPy_DecRef(cpy_r_r62);
    CPy_DecRef(cpy_r_r64);
    goto CPyL188;
CPyL199: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL60;
CPyL200: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL188;
CPyL201: ;
    CPy_DecRef(cpy_r_r74);
    goto CPyL188;
CPyL202: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL65;
CPyL203: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL64;
CPyL204: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL74;
CPyL205: ;
    CPy_DecRef(cpy_r_r77);
    goto CPyL74;
CPyL206: ;
    CPy_DecRef(cpy_r_r74);
    goto CPyL74;
CPyL207: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL188;
CPyL208: ;
    CPy_DecRef(cpy_r_r94);
    goto CPyL188;
CPyL209: ;
    CPy_DecRef(cpy_r_r100);
    goto CPyL188;
CPyL210: ;
    CPy_DecRef(cpy_r_r100);
    CPy_DecRef(cpy_r_r101);
    goto CPyL188;
CPyL211: ;
    CPy_DecRef(cpy_r_r101);
    CPy_DecRef(cpy_r_r102);
    goto CPyL188;
CPyL212: ;
    CPy_DecRef(cpy_r_r101);
    CPy_DecRef(cpy_r_r104);
    goto CPyL188;
CPyL213: ;
    CPy_DecRef(cpy_r_r108);
    goto CPyL188;
CPyL214: ;
    CPy_DecRef(cpy_r_r108);
    CPy_DecRef(cpy_r_r109);
    goto CPyL188;
CPyL215: ;
    CPy_DecRef(cpy_r_r115);
    goto CPyL188;
CPyL216: ;
    CPy_DecRef(cpy_r_r115);
    CPy_DecRef(cpy_r_r118);
    goto CPyL188;
CPyL217: ;
    CPy_DecRef(cpy_r_r115);
    CPy_DecRef(cpy_r_r118);
    CPy_DecRef(cpy_r_r119);
    goto CPyL110;
CPyL218: ;
    CPy_DecRef(cpy_r_r115);
    CPy_DecRef(cpy_r_r118);
    CPy_DecRef(cpy_r_r119);
    goto CPyL188;
CPyL219: ;
    CPy_DecRef(cpy_r_r115);
    CPy_DecRef(cpy_r_r124);
    goto CPyL188;
CPyL220: ;
    CPy_DECREF(cpy_r_r128);
    goto CPyL114;
CPyL221: ;
    CPy_DecRef(cpy_r_r133);
    goto CPyL188;
CPyL222: ;
    CPy_DecRef(cpy_r_r133);
    CPy_DecRef(cpy_r_r135);
    goto CPyL188;
CPyL223: ;
    CPy_DecRef(cpy_r_r157);
    goto CPyL188;
CPyL224: ;
    CPy_DecRef(cpy_r_r173);
    goto CPyL188;
CPyL225: ;
    CPy_DecRef(cpy_r_r176);
    goto CPyL188;
CPyL226: ;
    CPy_DecRef(cpy_r_r176);
    CPy_DecRef(cpy_r_r178);
    goto CPyL188;
CPyL227: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL156;
CPyL228: ;
    CPy_XDecRef(cpy_r_r5);
    goto CPyL188;
CPyL229: ;
    CPy_DecRef(cpy_r_r188);
    goto CPyL188;
CPyL230: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL161;
CPyL231: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL160;
CPyL232: ;
    CPy_XDecRef(cpy_r_r7);
    goto CPyL170;
CPyL233: ;
    CPy_DecRef(cpy_r_r191);
    goto CPyL170;
CPyL234: ;
    CPy_DecRef(cpy_r_r188);
    goto CPyL170;
CPyL235: ;
    CPy_DecRef(cpy_r_arg);
    goto CPyL188;
CPyL236: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r7);
    goto CPyL1;
CPyL237: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL62;
CPyL238: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL185;
CPyL239: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL186;
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
        CPy_TypeError("faster_async_lru.__call____LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapper_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__next__", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.__call____LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef___call___3__LRUCacheWrapper_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "send", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.__call____LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapper_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__iter__", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.__call____LRUCacheWrapper_gen", obj___mypyc_self__); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "throw", -1, CPyStatic_globals);
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
    PyObject *__tmp25 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp25);
    PyObject *__tmp26 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp26);
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
        CPy_TypeError("faster_async_lru.__call____LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapper_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "close", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.__call____LRUCacheWrapper_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapper_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__await__", -1, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL5;
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    CPy_INCREF_NO_IMM(cpy_r_self);
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self = cpy_r_self;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_fn_args);
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_args != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_args);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_args = cpy_r_fn_args;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_fn_kwargs);
    if (((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_kwargs != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_kwargs);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapper_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_kwargs = cpy_r_fn_kwargs;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "__get__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_self); 
        goto fail;
    }
    PyObject *arg_instance = obj_instance;
    PyObject *arg_owner;
    arg_owner = obj_owner;
    if (arg_owner != NULL) goto __LL27;
    if (obj_owner == Py_None)
        arg_owner = obj_owner;
    else {
        arg_owner = NULL;
    }
    if (arg_owner != NULL) goto __LL27;
    CPy_TypeError("object or None", obj_owner); 
    goto fail;
__LL27: ;
    PyObject *retval = CPyDef__LRUCacheWrapper_____get__(arg_self, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__get__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    PyObject *cpy_r_r45;
    int32_t cpy_r_r46;
    char cpy_r_r47;
    tuple_T3OOO cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    tuple_T2OO cpy_r_r55;
    PyObject *cpy_r_r56;
    char cpy_r_r57;
    char cpy_r_r58;
    char cpy_r_r59;
    char cpy_r_r60;
    char cpy_r_r61;
    PyObject *cpy_r_r62;
    char cpy_r_r63;
    PyObject *cpy_r_r64;
    char cpy_r_r65;
    char cpy_r_r66;
    char cpy_r_r67;
    char cpy_r_r68;
    cpy_r_r0 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___module__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__module__", 290, CPyStatic_globals);
        goto CPyL3;
    }
    CPy_INCREF(cpy_r_r0);
CPyL2: ;
    if (((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___module__ != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___module__);
    }
    ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___module__ = cpy_r_r0;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL10;
CPyL3: ;
    cpy_r_r2 = CPy_CatchError();
    cpy_r_r3 = CPyModule_builtins;
    cpy_r_r4 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r6 = CPy_ExceptionMatches(cpy_r_r5);
    CPy_DecRef(cpy_r_r5);
    if (cpy_r_r6) goto CPyL7;
    CPy_Reraise();
    if (!0) {
        goto CPyL8;
    } else
        goto CPyL71;
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
    if (!cpy_r_r7) goto CPyL70;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r8 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___name__;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__name__", 294, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_INCREF(cpy_r_r8);
CPyL11: ;
    if (((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___name__ != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___name__);
    }
    ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___name__ = cpy_r_r8;
    cpy_r_r9 = 1;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL19;
CPyL12: ;
    cpy_r_r10 = CPy_CatchError();
    cpy_r_r11 = CPyModule_builtins;
    cpy_r_r12 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_r11, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r14 = CPy_ExceptionMatches(cpy_r_r13);
    CPy_DecRef(cpy_r_r13);
    if (cpy_r_r14) goto CPyL16;
    CPy_Reraise();
    if (!0) {
        goto CPyL17;
    } else
        goto CPyL72;
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
    if (!cpy_r_r15) goto CPyL70;
    CPy_Unreachable();
CPyL19: ;
    cpy_r_r16 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___qualname__;
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__qualname__", 298, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_INCREF(cpy_r_r16);
CPyL20: ;
    if (((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___qualname__ != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___qualname__);
    }
    ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___qualname__ = cpy_r_r16;
    cpy_r_r17 = 1;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL28;
CPyL21: ;
    cpy_r_r18 = CPy_CatchError();
    cpy_r_r19 = CPyModule_builtins;
    cpy_r_r20 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r22 = CPy_ExceptionMatches(cpy_r_r21);
    CPy_DecRef(cpy_r_r21);
    if (cpy_r_r22) goto CPyL25;
    CPy_Reraise();
    if (!0) {
        goto CPyL26;
    } else
        goto CPyL73;
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
    if (!cpy_r_r23) goto CPyL70;
    CPy_Unreachable();
CPyL28: ;
    cpy_r_r24 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___doc__;
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__doc__", 302, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_INCREF(cpy_r_r24);
CPyL29: ;
    if (((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___doc__ != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___doc__);
    }
    ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___doc__ = cpy_r_r24;
    cpy_r_r25 = 1;
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL37;
CPyL30: ;
    cpy_r_r26 = CPy_CatchError();
    cpy_r_r27 = CPyModule_builtins;
    cpy_r_r28 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r29 = CPyObject_GetAttr(cpy_r_r27, cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r30 = CPy_ExceptionMatches(cpy_r_r29);
    CPy_DecRef(cpy_r_r29);
    if (cpy_r_r30) goto CPyL34;
    CPy_Reraise();
    if (!0) {
        goto CPyL35;
    } else
        goto CPyL74;
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
    if (!cpy_r_r31) goto CPyL70;
    CPy_Unreachable();
CPyL37: ;
    cpy_r_r32 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___annotations__;
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__annotations__", 306, CPyStatic_globals);
        goto CPyL39;
    }
    CPy_INCREF(cpy_r_r32);
CPyL38: ;
    if (((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___annotations__ != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___annotations__);
    }
    ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___annotations__ = cpy_r_r32;
    cpy_r_r33 = 1;
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL46;
CPyL39: ;
    cpy_r_r34 = CPy_CatchError();
    cpy_r_r35 = CPyModule_builtins;
    cpy_r_r36 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r38 = CPy_ExceptionMatches(cpy_r_r37);
    CPy_DecRef(cpy_r_r37);
    if (cpy_r_r38) goto CPyL43;
    CPy_Reraise();
    if (!0) {
        goto CPyL44;
    } else
        goto CPyL75;
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
    if (!cpy_r_r39) goto CPyL70;
    CPy_Unreachable();
CPyL46: ;
    cpy_r_r40 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r41 = CPyObject_GetAttr(cpy_r_self, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL51;
    }
    if (likely(PyDict_Check(cpy_r_r41)))
        cpy_r_r42 = cpy_r_r41;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__init__", 310, CPyStatic_globals, "dict", cpy_r_r41);
        goto CPyL51;
    }
    cpy_r_r43 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r44 = CPyObject_GetAttr(cpy_r_wrapper, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL76;
    }
    if (likely(PyDict_Check(cpy_r_r44)))
        cpy_r_r45 = cpy_r_r44;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "__init__", 310, CPyStatic_globals, "dict", cpy_r_r44);
        goto CPyL76;
    }
    cpy_r_r46 = CPyDict_Update(cpy_r_r42, cpy_r_r45);
    CPy_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r45);
    cpy_r_r47 = cpy_r_r46 >= 0;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    } else
        goto CPyL59;
CPyL51: ;
    cpy_r_r48 = CPy_CatchError();
    cpy_r_r49 = CPyModule_builtins;
    cpy_r_r50 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'AttributeError' */
    cpy_r_r51 = CPyObject_GetAttr(cpy_r_r49, cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r52 = CPyModule_builtins;
    cpy_r_r53 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'TypeError' */
    cpy_r_r54 = CPyObject_GetAttr(cpy_r_r52, cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r55.f0 = cpy_r_r51;
    cpy_r_r55.f1 = cpy_r_r54;
    cpy_r_r56 = PyTuple_New(2);
    if (unlikely(cpy_r_r56 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp28 = cpy_r_r55.f0;
    PyTuple_SET_ITEM(cpy_r_r56, 0, __tmp28);
    PyObject *__tmp29 = cpy_r_r55.f1;
    PyTuple_SET_ITEM(cpy_r_r56, 1, __tmp29);
    cpy_r_r57 = CPy_ExceptionMatches(cpy_r_r56);
    CPy_DecRef(cpy_r_r56);
    if (cpy_r_r57) goto CPyL56;
    CPy_Reraise();
    if (!0) {
        goto CPyL57;
    } else
        goto CPyL78;
CPyL55: ;
    CPy_Unreachable();
CPyL56: ;
    CPy_RestoreExcInfo(cpy_r_r48);
    CPy_DecRef(cpy_r_r48.f0);
    CPy_DecRef(cpy_r_r48.f1);
    CPy_DecRef(cpy_r_r48.f2);
    goto CPyL59;
CPyL57: ;
    CPy_RestoreExcInfo(cpy_r_r48);
    CPy_DecRef(cpy_r_r48.f0);
    CPy_DecRef(cpy_r_r48.f1);
    CPy_DecRef(cpy_r_r48.f2);
    cpy_r_r58 = CPy_KeepPropagating();
    if (!cpy_r_r58) goto CPyL70;
    CPy_Unreachable();
CPyL59: ;
    cpy_r_r59 = CPyStatic__PYTHON_LT_314;
    if (likely(cpy_r_r59 != 2)) goto CPyL62;
    PyErr_SetString(PyExc_NameError, "value for final name \"_PYTHON_LT_314\" was not set");
    cpy_r_r60 = 0;
    if (unlikely(!cpy_r_r60)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL70;
    }
    CPy_Unreachable();
CPyL62: ;
    if (!cpy_r_r59) goto CPyL65;
    PyErr_SetString(PyExc_NameError, "name \"_is_coroutine\" is not defined");
    cpy_r_r61 = 0;
    if (unlikely(!cpy_r_r61)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL70;
    }
    cpy_r_r62 = Py_None;
    if (((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->__is_coroutine != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->__is_coroutine);
    }
    ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->__is_coroutine = cpy_r_r62;
    cpy_r_r63 = 1;
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL70;
    }
CPyL65: ;
    cpy_r_r64 = ((faster_async_lru____LRUCacheWrapperObject *)cpy_r_wrapper)->___wrapped__;
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__init__", "_LRUCacheWrapper", "__wrapped__", 317, CPyStatic_globals);
        goto CPyL70;
    }
    CPy_INCREF(cpy_r_r64);
CPyL66: ;
    if (((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapped__ != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapped__);
    }
    ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapped__ = cpy_r_r64;
    cpy_r_r65 = 1;
    if (unlikely(!cpy_r_r65)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL70;
    }
    CPy_INCREF(cpy_r_instance);
    if (((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___instance != NULL) {
        CPy_DECREF(((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___instance);
    }
    ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___instance = cpy_r_instance;
    cpy_r_r66 = 1;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL70;
    }
    CPy_INCREF_NO_IMM(cpy_r_wrapper);
    if (((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper);
    }
    ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper = cpy_r_wrapper;
    cpy_r_r67 = 1;
    if (unlikely(!cpy_r_r67)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL70;
    }
    return 1;
CPyL70: ;
    cpy_r_r68 = 2;
    return cpy_r_r68;
CPyL71: ;
    CPy_DecRef(cpy_r_r2.f0);
    CPy_DecRef(cpy_r_r2.f1);
    CPy_DecRef(cpy_r_r2.f2);
    goto CPyL6;
CPyL72: ;
    CPy_DecRef(cpy_r_r10.f0);
    CPy_DecRef(cpy_r_r10.f1);
    CPy_DecRef(cpy_r_r10.f2);
    goto CPyL15;
CPyL73: ;
    CPy_DecRef(cpy_r_r18.f0);
    CPy_DecRef(cpy_r_r18.f1);
    CPy_DecRef(cpy_r_r18.f2);
    goto CPyL24;
CPyL74: ;
    CPy_DecRef(cpy_r_r26.f0);
    CPy_DecRef(cpy_r_r26.f1);
    CPy_DecRef(cpy_r_r26.f2);
    goto CPyL33;
CPyL75: ;
    CPy_DecRef(cpy_r_r34.f0);
    CPy_DecRef(cpy_r_r34.f1);
    CPy_DecRef(cpy_r_r34.f2);
    goto CPyL42;
CPyL76: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL51;
CPyL77: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL57;
CPyL78: ;
    CPy_DecRef(cpy_r_r48.f0);
    CPy_DecRef(cpy_r_r48.f1);
    CPy_DecRef(cpy_r_r48.f2);
    goto CPyL55;
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
        goto fail;
    }
    PyObject *arg_wrapper;
    if (likely(Py_TYPE(obj_wrapper) == CPyType__LRUCacheWrapper))
        arg_wrapper = obj_wrapper;
    else {
        CPy_TypeError("faster_async_lru._LRUCacheWrapper", obj_wrapper); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    cpy_r_r0 = ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_invalidate", "_LRUCacheWrapperInstanceMethod", "__wrapper", 322, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___instance;
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_invalidate", "_LRUCacheWrapperInstanceMethod", "__instance", 322, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'cache_invalidate' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r2);
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r4 = PyList_New(1);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r5 = (CPyPtr)&((PyListObject *)cpy_r_r4)->ob_item;
    cpy_r_r6 = *(CPyPtr *)cpy_r_r5;
    *(PyObject * *)cpy_r_r6 = cpy_r_r1;
    cpy_r_r7 = CPyList_Extend(cpy_r_r4, cpy_r_args);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL15;
    } else
        goto CPyL16;
CPyL5: ;
    cpy_r_r8 = PyDict_New();
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r9 = CPyDict_UpdateInDisplay(cpy_r_r8, cpy_r_kwargs);
    cpy_r_r10 = cpy_r_r9 >= 0;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r11 = PyList_AsTuple(cpy_r_r4);
    CPy_DECREF_NO_IMM(cpy_r_r4);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r12 = PyObject_Call(cpy_r_r3, cpy_r_r11, cpy_r_r8);
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL11;
    }
    if (unlikely(!PyBool_Check(cpy_r_r12))) {
        CPy_TypeError("bool", cpy_r_r12); cpy_r_r13 = 2;
    } else
        cpy_r_r13 = cpy_r_r12 == Py_True;
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r13 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "cache_invalidate", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

char CPyDef__LRUCacheWrapperInstanceMethod___cache_clear(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    cpy_r_r0 = ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_clear", "_LRUCacheWrapperInstanceMethod", "__wrapper", 325, CPyStatic_globals);
        goto CPyL3;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyDef__LRUCacheWrapper___cache_clear(cpy_r_r0);
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r1 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "cache_clear", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    cpy_r_r4 = ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__;
    goto CPyL39;
CPyL1: ;
    cpy_r_r5 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r6 = cpy_r_type != cpy_r_r5;
    if (!cpy_r_r6) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r7 = ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "self", 330, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_INCREF_NO_IMM(cpy_r_r7);
CPyL5: ;
    cpy_r_r8 = ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_r7)->___wrapper;
    if (unlikely(cpy_r_r8 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__wrapper' of '_LRUCacheWrapperInstanceMethod' undefined");
    } else {
        CPy_INCREF_NO_IMM(cpy_r_r8);
    }
    CPy_DECREF_NO_IMM(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
CPyL6: ;
    cpy_r_r9 = 2;
    cpy_r_r10 = CPyDef__LRUCacheWrapper___cache_close(cpy_r_r8, cpy_r_r9);
    CPy_DECREF_NO_IMM(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
    if (((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12 != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12);
    }
    ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12 = cpy_r_r10;
    cpy_r_r11 = 1;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r12 = ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12;
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__12", -1, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r18 = cpy_r_r1;
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = NULL;
    if (((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12 != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12);
    }
    ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12 = cpy_r_r19;
    cpy_r_r20 = 1;
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    } else
        goto CPyL34;
CPyL12: ;
    cpy_r_r21 = cpy_r_r16;
CPyL13: ;
    ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 1;
    return cpy_r_r21;
CPyL14: ;
    cpy_r_r23 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r24 = cpy_r_type != cpy_r_r23;
    if (!cpy_r_r24) goto CPyL46;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    if (((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13.f0 != NULL) {
        CPy_DECREF(((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13.f0);
        CPy_DECREF(((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13.f1);
        CPy_DECREF(((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13.f2);
    }
    ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13 = cpy_r_r25;
    cpy_r_r26 = 1;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", -1, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r27 = (PyObject **)&cpy_r_r3;
    cpy_r_r28 = ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12;
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__12", -1, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_INCREF_NO_IMM(cpy_r_r28);
CPyL20: ;
    cpy_r_r29 = CPy_YieldFromErrorHandle(cpy_r_r28, cpy_r_r27);
    CPy_DecRef(cpy_r_r28);
    if (unlikely(cpy_r_r29 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL48;
    }
    if (cpy_r_r29) goto CPyL24;
    cpy_r_r21 = cpy_r_r3;
    cpy_r_r30 = ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13;
    if (unlikely(cpy_r_r30.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__13", -1, CPyStatic_globals);
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
    cpy_r_r31 = ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13;
    if (unlikely(cpy_r_r31.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__13", -1, CPyStatic_globals);
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
    cpy_r_r32 = ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__13;
    if (unlikely(cpy_r_r32.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__13", -1, CPyStatic_globals);
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
    cpy_r_r34 = ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__12;
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_close", "cache_close__LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__12", -1, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r18 = cpy_r_r36;
    CPy_DECREF(cpy_r_r18);
CPyL34: ;
    cpy_r_r37 = Py_None;
    ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.cache_close__LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__next__", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.cache_close__LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "send", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.cache_close__LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__iter__", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.cache_close__LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "throw", -1, CPyStatic_globals);
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
    PyObject *__tmp30 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp30);
    PyObject *__tmp31 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp31);
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
        CPy_TypeError("faster_async_lru.cache_close__LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "close", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.cache_close__LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__await__", -1, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL9;
    }
    ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    CPy_INCREF_NO_IMM(cpy_r_self);
    if (((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self);
    }
    ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self = cpy_r_self;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__cancel = cpy_r_cancel;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL10;
    }
    ((faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__return_exceptions = cpy_r_return_exceptions;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "cache_close", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapperInstanceMethod___cache_info(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_info", "_LRUCacheWrapperInstanceMethod", "__wrapper", 333, CPyStatic_globals);
        goto CPyL3;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyDef__LRUCacheWrapper___cache_info(cpy_r_r0);
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_info", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef__LRUCacheWrapperInstanceMethod___cache_info(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "cache_info", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__LRUCacheWrapperInstanceMethod___cache_parameters(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_self)->___wrapper;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "cache_parameters", "_LRUCacheWrapperInstanceMethod", "__wrapper", 336, CPyStatic_globals);
        goto CPyL3;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyDef__LRUCacheWrapper___cache_parameters(cpy_r_r0);
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "cache_parameters", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef__LRUCacheWrapperInstanceMethod___cache_parameters(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "cache_parameters", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    cpy_r_r2 = ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__;
    goto CPyL49;
CPyL1: ;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = cpy_r_type != cpy_r_r3;
    if (!cpy_r_r4) goto CPyL4;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r5 = ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "self", 339, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_INCREF_NO_IMM(cpy_r_r5);
CPyL5: ;
    cpy_r_r6 = ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__self;
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "self", 339, CPyStatic_globals);
        goto CPyL54;
    }
    CPy_INCREF_NO_IMM(cpy_r_r6);
CPyL6: ;
    cpy_r_r7 = ((faster_async_lru____LRUCacheWrapperInstanceMethodObject *)cpy_r_r6)->___instance;
    if (unlikely(cpy_r_r7 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__instance' of '_LRUCacheWrapperInstanceMethod' undefined");
    } else {
        CPy_INCREF(cpy_r_r7);
    }
    CPy_DECREF_NO_IMM(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL54;
    }
CPyL7: ;
    cpy_r_r8 = ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_args;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "fn_args", 339, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_INCREF(cpy_r_r8);
CPyL8: ;
    cpy_r_r9 = ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_generator_attribute__fn_kwargs;
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "fn_kwargs", 339, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_INCREF(cpy_r_r9);
CPyL9: ;
    cpy_r_r10 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapper' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r10);
    CPy_DECREF_NO_IMM(cpy_r_r5);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r12 = PyList_New(1);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r7;
    cpy_r_r15 = CPyList_Extend(cpy_r_r12, cpy_r_r8);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL59;
    } else
        goto CPyL60;
CPyL12: ;
    cpy_r_r16 = PyDict_New();
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r17 = CPyDict_UpdateInDisplay(cpy_r_r16, cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r18 = cpy_r_r17 >= 0;
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r19 = PyList_AsTuple(cpy_r_r12);
    CPy_DECREF_NO_IMM(cpy_r_r12);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r20 = PyObject_Call(cpy_r_r11, cpy_r_r19, cpy_r_r16);
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r19);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r21 = CPy_GetCoro(cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    if (((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14 != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14 = cpy_r_r21;
    cpy_r_r22 = 1;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r23 = ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14;
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__14", -1, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_INCREF(cpy_r_r23);
CPyL19: ;
    cpy_r_r24 = CPyIter_Next(cpy_r_r23);
    CPy_DECREF(cpy_r_r23);
    if (cpy_r_r24 != NULL) goto CPyL22;
    cpy_r_r25 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r26 = cpy_r_r25;
    cpy_r_r27 = NULL;
    if (((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14 != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14 = cpy_r_r27;
    cpy_r_r28 = 1;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL63;
    } else
        goto CPyL44;
CPyL22: ;
    cpy_r_r29 = cpy_r_r24;
CPyL23: ;
    ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = 1;
    return cpy_r_r29;
CPyL24: ;
    cpy_r_r31 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r32 = cpy_r_type != cpy_r_r31;
    if (!cpy_r_r32) goto CPyL64;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    if (((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15.f0 != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15.f0);
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15.f1);
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15.f2);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15 = cpy_r_r33;
    cpy_r_r34 = 1;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", -1, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r35 = (PyObject **)&cpy_r_r1;
    cpy_r_r36 = ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14;
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__14", -1, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_INCREF(cpy_r_r36);
CPyL30: ;
    cpy_r_r37 = CPy_YieldFromErrorHandle(cpy_r_r36, cpy_r_r35);
    CPy_DecRef(cpy_r_r36);
    if (unlikely(cpy_r_r37 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL66;
    }
    if (cpy_r_r37) goto CPyL34;
    cpy_r_r29 = cpy_r_r1;
    cpy_r_r38 = ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15;
    if (unlikely(cpy_r_r38.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__15", -1, CPyStatic_globals);
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
    cpy_r_r39 = ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15;
    if (unlikely(cpy_r_r39.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__15", -1, CPyStatic_globals);
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
    cpy_r_r40 = ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__15;
    if (unlikely(cpy_r_r40.f0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__15", -1, CPyStatic_globals);
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
    cpy_r_r42 = ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_temp__14;
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "__call__", "__call____LRUCacheWrapperInstanceMethod_gen", "__mypyc_temp__14", -1, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r26 = cpy_r_r44;
CPyL44: ;
    ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r___mypyc_self__)->___mypyc_next_label__ = -1;
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.__call____LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__next__", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.__call____LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "send", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.__call____LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__iter__", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.__call____LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "throw", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.__call____LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "close", -1, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru.__call____LRUCacheWrapperInstanceMethod_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__await__", -1, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL5;
    }
    ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    CPy_INCREF_NO_IMM(cpy_r_self);
    if (((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__self = cpy_r_self;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_fn_args);
    if (((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_args != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_args);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_args = cpy_r_fn_args;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_fn_kwargs);
    if (((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_kwargs != NULL) {
        CPy_DECREF(((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_kwargs);
    }
    ((faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *)cpy_r_r0)->___mypyc_generator_attribute__fn_kwargs = cpy_r_fn_kwargs;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_TypeError("faster_async_lru._LRUCacheWrapperInstanceMethod", obj_self); 
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "__call__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "__get__", -1, CPyStatic_globals);
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
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject **cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject **cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    CPyPtr cpy_r_r42;
    CPyPtr cpy_r_r43;
    CPyPtr cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject **cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    char cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject **cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_wrapper;
    char cpy_r_r62;
    char cpy_r_r63;
    PyObject *cpy_r_r64;
    char cpy_r_r65;
    PyObject **cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    cpy_r_r0 = ((faster_async_lru___wrapper__make_wrapper_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "wrapper", "wrapper__make_wrapper_obj", "__mypyc_env__", 347, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    CPy_INCREF(cpy_r_fn);
    cpy_r_origin = cpy_r_fn;
CPyL2: ;
    cpy_r_r1 = CPyStatic_partial;
    if (unlikely(cpy_r_r1 == NULL)) {
        goto CPyL49;
    } else
        goto CPyL5;
CPyL3: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"partial\" was not set");
    cpy_r_r2 = 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r3 = CPyStatic_partialmethod;
    if (unlikely(cpy_r_r3 == NULL)) {
        goto CPyL50;
    } else
        goto CPyL8;
CPyL6: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"partialmethod\" was not set");
    cpy_r_r4 = 0;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL48;
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
    PyObject *__tmp34 = cpy_r_r5.f0;
    PyTuple_SET_ITEM(cpy_r_r6, 0, __tmp34);
    PyObject *__tmp35 = cpy_r_r5.f1;
    PyTuple_SET_ITEM(cpy_r_r6, 1, __tmp35);
    cpy_r_r7 = PyObject_IsInstance(cpy_r_origin, cpy_r_r6);
    CPy_DECREF(cpy_r_r6);
    cpy_r_r8 = cpy_r_r7 >= 0;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r9 = cpy_r_r7;
    if (!cpy_r_r9) goto CPyL12;
    cpy_r_r10 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'func' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_origin, cpy_r_r10);
    CPy_DECREF(cpy_r_origin);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_origin = cpy_r_r11;
    goto CPyL2;
CPyL12: ;
    cpy_r_r12 = CPyModule_inspect;
    cpy_r_r13 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'iscoroutinefunction' */
    cpy_r_r14 = CPyObject_GetAttr(cpy_r_r12, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL51;
    }
    PyObject *cpy_r_r15[1] = {cpy_r_origin};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = PyObject_Vectorcall(cpy_r_r14, cpy_r_r16, 1, 0);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL51;
    }
    CPy_DECREF(cpy_r_origin);
    if (unlikely(!PyBool_Check(cpy_r_r17))) {
        CPy_TypeError("bool", cpy_r_r17); cpy_r_r18 = 2;
    } else
        cpy_r_r18 = cpy_r_r17 == Py_True;
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r18 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL52;
    }
    if (cpy_r_r18) goto CPyL30;
    cpy_r_r19 = CPyModule_os;
    cpy_r_r20 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'environ' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r22 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'ASYNC_LRU_ALLOW_SYNC' */
    cpy_r_r23 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'get' */
    PyObject *cpy_r_r24[2] = {cpy_r_r21, cpy_r_r22};
    cpy_r_r25 = (PyObject **)&cpy_r_r24;
    cpy_r_r26 = PyObject_VectorcallMethod(cpy_r_r23, cpy_r_r25, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_DECREF(cpy_r_r21);
    if (PyUnicode_Check(cpy_r_r26))
        cpy_r_r27 = cpy_r_r26;
    else {
        cpy_r_r27 = NULL;
    }
    if (cpy_r_r27 != NULL) goto __LL36;
    if (cpy_r_r26 == Py_None)
        cpy_r_r27 = cpy_r_r26;
    else {
        cpy_r_r27 = NULL;
    }
    if (cpy_r_r27 != NULL) goto __LL36;
    CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "wrapper", 353, CPyStatic_globals, "str or None", cpy_r_r26);
    goto CPyL52;
__LL36: ;
    cpy_r_r28 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r29 = cpy_r_r27 != cpy_r_r28;
    if (!cpy_r_r29) goto CPyL54;
    if (likely(cpy_r_r27 != Py_None))
        cpy_r_r30 = cpy_r_r27;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "wrapper", 353, CPyStatic_globals, "str", cpy_r_r27);
        goto CPyL52;
    }
    cpy_r_r31 = CPyStr_IsTrue(cpy_r_r30);
    CPy_DECREF(cpy_r_r30);
    if (cpy_r_r31) {
        goto CPyL30;
    } else
        goto CPyL55;
CPyL22: ;
    cpy_r_r32 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '' */
    cpy_r_r33 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Coroutine function is required, got ' */
    cpy_r_r34 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '{!r:{}}' */
    cpy_r_r35 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '' */
    cpy_r_r36 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'format' */
    PyObject *cpy_r_r37[3] = {cpy_r_r34, cpy_r_fn, cpy_r_r35};
    cpy_r_r38 = (PyObject **)&cpy_r_r37;
    cpy_r_r39 = PyObject_VectorcallMethod(cpy_r_r36, cpy_r_r38, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL48;
    }
    if (likely(PyUnicode_Check(cpy_r_r39)))
        cpy_r_r40 = cpy_r_r39;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "wrapper", 354, CPyStatic_globals, "str", cpy_r_r39);
        goto CPyL48;
    }
    cpy_r_r41 = PyList_New(2);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r42 = (CPyPtr)&((PyListObject *)cpy_r_r41)->ob_item;
    cpy_r_r43 = *(CPyPtr *)cpy_r_r42;
    CPy_INCREF(cpy_r_r33);
    *(PyObject * *)cpy_r_r43 = cpy_r_r33;
    cpy_r_r44 = cpy_r_r43 + 8;
    *(PyObject * *)cpy_r_r44 = cpy_r_r40;
    cpy_r_r45 = PyUnicode_Join(cpy_r_r32, cpy_r_r41);
    CPy_DECREF_NO_IMM(cpy_r_r41);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r46 = CPyModule_builtins;
    cpy_r_r47 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'RuntimeError' */
    cpy_r_r48 = CPyObject_GetAttr(cpy_r_r46, cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL57;
    }
    PyObject *cpy_r_r49[1] = {cpy_r_r45};
    cpy_r_r50 = (PyObject **)&cpy_r_r49;
    cpy_r_r51 = PyObject_Vectorcall(cpy_r_r48, cpy_r_r50, 1, 0);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_DECREF(cpy_r_r45);
    CPy_Raise(cpy_r_r51);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_Unreachable();
CPyL30: ;
    cpy_r_r52 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_make_unbound_method' */
    cpy_r_r53 = PyObject_HasAttr(cpy_r_fn, cpy_r_r52);
    if (!cpy_r_r53) goto CPyL58;
    cpy_r_r54 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_make_unbound_method' */
    PyObject *cpy_r_r55[1] = {cpy_r_fn};
    cpy_r_r56 = (PyObject **)&cpy_r_r55;
    cpy_r_r57 = PyObject_VectorcallMethod(cpy_r_r54, cpy_r_r56, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_fn = cpy_r_r57;
CPyL33: ;
    cpy_r_r58 = ((faster_async_lru____make_wrapper_envObject *)cpy_r_r0)->_maxsize;
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "wrapper", "_make_wrapper_env", "maxsize", 360, CPyStatic_globals);
        goto CPyL59;
    }
    CPy_INCREF(cpy_r_r58);
CPyL34: ;
    cpy_r_r59 = ((faster_async_lru____make_wrapper_envObject *)cpy_r_r0)->_typed;
    if (unlikely(cpy_r_r59 == 2)) {
        CPy_AttributeError("faster_async_lru/__init__.py", "wrapper", "_make_wrapper_env", "typed", 360, CPyStatic_globals);
        goto CPyL60;
    }
CPyL35: ;
    cpy_r_r60 = ((faster_async_lru____make_wrapper_envObject *)cpy_r_r0)->_ttl;
    if (unlikely(cpy_r_r60 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'ttl' of '_make_wrapper_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r60);
    }
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL61;
    }
CPyL36: ;
    cpy_r_r61 = CPyDef__LRUCacheWrapper(cpy_r_fn, cpy_r_r58, cpy_r_r59, cpy_r_r60);
    CPy_DECREF(cpy_r_fn);
    CPy_DECREF(cpy_r_r58);
    CPy_DECREF(cpy_r_r60);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_wrapper = cpy_r_r61;
    cpy_r_r62 = CPyStatic__PYTHON_GTE_312;
    if (unlikely(cpy_r_r62 == 2)) {
        goto CPyL62;
    } else
        goto CPyL40;
CPyL38: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_PYTHON_GTE_312\" was not set");
    cpy_r_r63 = 0;
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_Unreachable();
CPyL40: ;
    if (!cpy_r_r62) goto CPyL47;
    cpy_r_r64 = CPyStatic_markcoroutinefunction;
    if (unlikely(cpy_r_r64 == NULL)) {
        goto CPyL63;
    } else
        goto CPyL44;
CPyL42: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"markcoroutinefunction\" was not set");
    cpy_r_r65 = 0;
    if (unlikely(!cpy_r_r65)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_Unreachable();
CPyL44: ;
    PyObject *cpy_r_r66[1] = {cpy_r_wrapper};
    cpy_r_r67 = (PyObject **)&cpy_r_r66;
    cpy_r_r68 = PyObject_Vectorcall(cpy_r_r64, cpy_r_r67, 1, 0);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_DECREF_NO_IMM(cpy_r_wrapper);
    if (likely(Py_TYPE(cpy_r_r68) == CPyType__LRUCacheWrapper))
        cpy_r_r69 = cpy_r_r68;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "wrapper", 362, CPyStatic_globals, "faster_async_lru._LRUCacheWrapper", cpy_r_r68);
        goto CPyL48;
    }
    cpy_r_wrapper = cpy_r_r69;
CPyL47: ;
    return cpy_r_wrapper;
CPyL48: ;
    cpy_r_r70 = NULL;
    return cpy_r_r70;
CPyL49: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_origin);
    goto CPyL3;
CPyL50: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_origin);
    goto CPyL6;
CPyL51: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_origin);
    goto CPyL48;
CPyL52: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL48;
CPyL53: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r21);
    goto CPyL48;
CPyL54: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    CPy_DECREF(cpy_r_r27);
    goto CPyL22;
CPyL55: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    goto CPyL22;
CPyL56: ;
    CPy_DecRef(cpy_r_r40);
    goto CPyL48;
CPyL57: ;
    CPy_DecRef(cpy_r_r45);
    goto CPyL48;
CPyL58: ;
    CPy_INCREF(cpy_r_fn);
    goto CPyL33;
CPyL59: ;
    CPy_DecRef(cpy_r_fn);
    CPy_DecRef(cpy_r_r0);
    goto CPyL48;
CPyL60: ;
    CPy_DecRef(cpy_r_fn);
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r58);
    goto CPyL48;
CPyL61: ;
    CPy_DecRef(cpy_r_fn);
    CPy_DecRef(cpy_r_r58);
    goto CPyL48;
CPyL62: ;
    CPy_DecRef(cpy_r_wrapper);
    goto CPyL38;
CPyL63: ;
    CPy_DecRef(cpy_r_wrapper);
    goto CPyL42;
CPyL64: ;
    CPy_DecRef(cpy_r_wrapper);
    goto CPyL48;
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_INCREF(cpy_r_maxsize);
    if (((faster_async_lru____make_wrapper_envObject *)cpy_r_r1)->_maxsize != NULL) {
        CPy_DECREF(((faster_async_lru____make_wrapper_envObject *)cpy_r_r1)->_maxsize);
    }
    ((faster_async_lru____make_wrapper_envObject *)cpy_r_r1)->_maxsize = cpy_r_maxsize;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL12;
    }
    ((faster_async_lru____make_wrapper_envObject *)cpy_r_r1)->_typed = cpy_r_typed;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL12;
    }
    if (((faster_async_lru____make_wrapper_envObject *)cpy_r_r1)->_ttl != NULL) {
        CPy_DECREF(((faster_async_lru____make_wrapper_envObject *)cpy_r_r1)->_ttl);
    }
    ((faster_async_lru____make_wrapper_envObject *)cpy_r_r1)->_ttl = cpy_r_ttl;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r5 = CPyDef_wrapper__make_wrapper_obj();
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL13;
    }
    if (((faster_async_lru___wrapper__make_wrapper_objObject *)cpy_r_r5)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((faster_async_lru___wrapper__make_wrapper_objObject *)cpy_r_r5)->___mypyc_env__);
    }
    ((faster_async_lru___wrapper__make_wrapper_objObject *)cpy_r_r5)->___mypyc_env__ = cpy_r_r1;
    cpy_r_r6 = 1;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "_make_wrapper", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "alru_cache", 393, CPyStatic_globals, "int or None", cpy_r_maxsize);
    goto CPyL31;
__LL39: ;
    cpy_r_r6 = CPyDef__make_wrapper(cpy_r_r5, cpy_r_typed, cpy_r_ttl);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_ttl);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL27;
    }
    return cpy_r_r6;
CPyL11: ;
    cpy_r_fn = cpy_r_maxsize;
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'callable' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    }
    PyObject *cpy_r_r10[1] = {cpy_r_fn};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_Vectorcall(cpy_r_r9, cpy_r_r11, 1, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    }
    if (unlikely(!PyBool_Check(cpy_r_r12))) {
        CPy_TypeError("bool", cpy_r_r12); cpy_r_r13 = 2;
    } else
        cpy_r_r13 = cpy_r_r12 == Py_True;
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r13 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    }
    PyObject *cpy_r_r19[1] = {cpy_r_fn};
    cpy_r_r20 = (PyObject **)&cpy_r_r19;
    cpy_r_r21 = PyObject_Vectorcall(cpy_r_r18, cpy_r_r20, 1, 0);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_DECREF(cpy_r_fn);
    if (likely(Py_TYPE(cpy_r_r21) == CPyType__LRUCacheWrapper))
        cpy_r_r22 = cpy_r_r21;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "alru_cache", 398, CPyStatic_globals, "faster_async_lru._LRUCacheWrapper", cpy_r_r21);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_DECREF(cpy_r_fn);
    cpy_r_r30 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ' decorating is not supported' */
    cpy_r_r31 = PyList_New(2);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
        CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r36 = CPyModule_builtins;
    cpy_r_r37 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'NotImplementedError' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_r36, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL34;
    }
    PyObject *cpy_r_r39[1] = {cpy_r_r35};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = PyObject_Vectorcall(cpy_r_r38, cpy_r_r40, 1, 0);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_DECREF(cpy_r_r35);
    CPy_Raise(cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    CPy_AddTraceback("faster_async_lru/__init__.py", "alru_cache", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___init___3__HashedSeq_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy___init___3__HashedSeq_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef___init___3__HashedSeq_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

char CPyDef___init___3__HashedSeq_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_tup) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    int32_t cpy_r_r4;
    char cpy_r_r5;
    CPyTagged cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    int32_t cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r3 = PySlice_New(cpy_r_r0, cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r4 = PyObject_SetItem(cpy_r_self, cpy_r_r3, cpy_r_tup);
    CPy_DECREF(cpy_r_r3);
    cpy_r_r5 = cpy_r_r4 >= 0;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r6 = CPyObject_Hash(cpy_r_tup);
    if (unlikely(cpy_r_r6 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r7 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'hashvalue' */
    cpy_r_r8 = CPyTagged_StealAsObject(cpy_r_r6);
    cpy_r_r9 = PyObject_SetAttr(cpy_r_self, cpy_r_r7, cpy_r_r8);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r10 = cpy_r_r9 >= 0;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL5;
    }
    return 1;
CPyL5: ;
    cpy_r_r11 = 2;
    return cpy_r_r11;
}

PyObject *CPyPy___init___3__HashedSeq_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"self", "tup", 0};
    static CPyArg_Parser parser = {"OO:__call__", kwlist, 0};
    PyObject *obj_self;
    PyObject *obj_tup;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_self, &obj_tup)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__HashedSeq))
        arg_self = obj_self;
    else {
        CPy_TypeError("faster_async_lru._HashedSeq", obj_self); 
        goto fail;
    }
    PyObject * arg_tup;
    if (likely(PyTuple_Check(obj_tup)))
        arg_tup = obj_tup;
    else {
        CPy_TypeError("tuple", obj_tup); 
        goto fail;
    }
    char retval = CPyDef___init___3__HashedSeq_obj_____call__(arg___mypyc_self__, arg_self, arg_tup);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__init__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___hash___3__HashedSeq_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy___hash___3__HashedSeq_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef___hash___3__HashedSeq_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

CPyTagged CPyDef___hash___3__HashedSeq_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    CPyTagged cpy_r_r2;
    CPyTagged cpy_r_r3;
    cpy_r_r0 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'hashvalue' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_self, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__hash__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL3;
    }
    if (likely(PyLong_Check(cpy_r_r1)))
        cpy_r_r2 = CPyTagged_FromObject(cpy_r_r1);
    else {
        CPy_TypeError("int", cpy_r_r1); cpy_r_r2 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "__hash__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL3;
    }
    return cpy_r_r2;
CPyL3: ;
    cpy_r_r3 = CPY_INT_TAG;
    return cpy_r_r3;
}

PyObject *CPyPy___hash___3__HashedSeq_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"self", 0};
    static CPyArg_Parser parser = {"O:__call__", kwlist, 0};
    PyObject *obj_self;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_self)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__HashedSeq))
        arg_self = obj_self;
    else {
        CPy_TypeError("faster_async_lru._HashedSeq", obj_self); 
        goto fail;
    }
    CPyTagged retval = CPyDef___hash___3__HashedSeq_obj_____call__(arg___mypyc_self__, arg_self);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "__hash__", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__make_key(PyObject *cpy_r_args, PyObject *cpy_r_kwds, char cpy_r_typed) {
    PyObject *cpy_r_key;
    int64_t cpy_r_r0;
    CPyTagged cpy_r_r1;
    char cpy_r_r2;
    tuple_T1O cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    CPyTagged cpy_r_r8;
    int64_t cpy_r_r9;
    PyObject *cpy_r_r10;
    tuple_T4CIOO cpy_r_r11;
    CPyTagged cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    tuple_T2OO cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject **cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    int64_t cpy_r_r32;
    CPyTagged cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject **cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    CPyPtr cpy_r_r46;
    int64_t cpy_r_r47;
    CPyTagged cpy_r_r48;
    char cpy_r_r49;
    tuple_T1O cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
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
    CPy_INCREF(cpy_r_args);
    cpy_r_key = cpy_r_args;
    cpy_r_r0 = PyDict_Size(cpy_r_kwds);
    cpy_r_r1 = cpy_r_r0 << 1;
    cpy_r_r2 = cpy_r_r1 != 0;
    if (!cpy_r_r2) goto CPyL13;
    cpy_r_r3 = CPyStatic__KW_MARK;
    if (unlikely(cpy_r_r3.f0 == NULL)) {
        goto CPyL37;
    } else
        goto CPyL4;
CPyL2: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_KW_MARK\" was not set");
    cpy_r_r4 = 0;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_Unreachable();
CPyL4: ;
    CPy_INCREF(cpy_r_r3.f0);
    cpy_r_r5 = PyTuple_New(1);
    if (unlikely(cpy_r_r5 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp42 = cpy_r_r3.f0;
    PyTuple_SET_ITEM(cpy_r_r5, 0, __tmp42);
    cpy_r_r6 = PyNumber_InPlaceAdd(cpy_r_key, cpy_r_r5);
    CPy_DECREF(cpy_r_key);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
    }
    if (likely(PyTuple_Check(cpy_r_r6)))
        cpy_r_r7 = cpy_r_r6;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "_make_key", 445, CPyStatic_globals, "tuple", cpy_r_r6);
        goto CPyL36;
    }
    cpy_r_key = cpy_r_r7;
    cpy_r_r8 = 0;
    cpy_r_r9 = PyDict_Size(cpy_r_kwds);
    cpy_r_r10 = CPyDict_GetItemsIter(cpy_r_kwds);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL38;
    }
CPyL7: ;
    cpy_r_r11 = CPyDict_NextItem(cpy_r_r10, cpy_r_r8);
    cpy_r_r12 = cpy_r_r11.f1;
    cpy_r_r8 = cpy_r_r12;
    cpy_r_r13 = cpy_r_r11.f0;
    if (!cpy_r_r13) goto CPyL39;
    cpy_r_r14 = cpy_r_r11.f2;
    CPy_INCREF(cpy_r_r14);
    cpy_r_r15 = cpy_r_r11.f3;
    CPy_INCREF(cpy_r_r15);
    CPy_DECREF(cpy_r_r11.f2);
    CPy_DECREF(cpy_r_r11.f3);
    cpy_r_r16.f0 = cpy_r_r14;
    cpy_r_r16.f1 = cpy_r_r15;
    cpy_r_r17 = PyTuple_New(2);
    if (unlikely(cpy_r_r17 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp43 = cpy_r_r16.f0;
    PyTuple_SET_ITEM(cpy_r_r17, 0, __tmp43);
    PyObject *__tmp44 = cpy_r_r16.f1;
    PyTuple_SET_ITEM(cpy_r_r17, 1, __tmp44);
    cpy_r_r18 = PyNumber_InPlaceAdd(cpy_r_key, cpy_r_r17);
    CPy_DECREF(cpy_r_key);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL40;
    }
    if (likely(PyTuple_Check(cpy_r_r18)))
        cpy_r_r19 = cpy_r_r18;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "_make_key", 447, CPyStatic_globals, "tuple", cpy_r_r18);
        goto CPyL40;
    }
    cpy_r_key = cpy_r_r19;
    cpy_r_r20 = CPyDict_CheckSize(cpy_r_kwds, cpy_r_r9);
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL41;
    } else
        goto CPyL7;
CPyL12: ;
    cpy_r_r21 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL38;
    }
CPyL13: ;
    if (!cpy_r_typed) goto CPyL27;
    cpy_r_r22 = (PyObject *)&PyType_Type;
    cpy_r_r23 = CPyModule_builtins;
    cpy_r_r24 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'map' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL38;
    }
    PyObject *cpy_r_r26[2] = {cpy_r_r22, cpy_r_args};
    cpy_r_r27 = (PyObject **)&cpy_r_r26;
    cpy_r_r28 = PyObject_Vectorcall(cpy_r_r25, cpy_r_r27, 2, 0);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL38;
    }
    cpy_r_r29 = PySequence_Tuple(cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL38;
    }
    cpy_r_r30 = PyNumber_InPlaceAdd(cpy_r_key, cpy_r_r29);
    CPy_DECREF(cpy_r_key);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
    }
    if (likely(PyTuple_Check(cpy_r_r30)))
        cpy_r_r31 = cpy_r_r30;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "_make_key", 449, CPyStatic_globals, "tuple", cpy_r_r30);
        goto CPyL36;
    }
    cpy_r_key = cpy_r_r31;
    cpy_r_r32 = PyDict_Size(cpy_r_kwds);
    cpy_r_r33 = cpy_r_r32 << 1;
    cpy_r_r34 = cpy_r_r33 != 0;
    if (!cpy_r_r34) goto CPyL33;
    cpy_r_r35 = (PyObject *)&PyType_Type;
    cpy_r_r36 = CPyDict_ValuesView(cpy_r_kwds);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL38;
    }
    cpy_r_r37 = CPyModule_builtins;
    cpy_r_r38 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'map' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL42;
    }
    PyObject *cpy_r_r40[2] = {cpy_r_r35, cpy_r_r36};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = PyObject_Vectorcall(cpy_r_r39, cpy_r_r41, 2, 0);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_DECREF(cpy_r_r36);
    cpy_r_r43 = PySequence_Tuple(cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL38;
    }
    cpy_r_r44 = PyNumber_InPlaceAdd(cpy_r_key, cpy_r_r43);
    CPy_DECREF(cpy_r_key);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL36;
    }
    if (likely(PyTuple_Check(cpy_r_r44)))
        cpy_r_r45 = cpy_r_r44;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "_make_key", 451, CPyStatic_globals, "tuple", cpy_r_r44);
        goto CPyL36;
    }
    cpy_r_key = cpy_r_r45;
    goto CPyL33;
CPyL27: ;
    cpy_r_r46 = (CPyPtr)&((PyVarObject *)cpy_r_key)->ob_size;
    cpy_r_r47 = *(int64_t *)cpy_r_r46;
    cpy_r_r48 = cpy_r_r47 << 1;
    cpy_r_r49 = cpy_r_r48 == 2;
    if (!cpy_r_r49) goto CPyL33;
    PyObject *__tmp45;
    if (unlikely(!(PyTuple_Check(cpy_r_key) && PyTuple_GET_SIZE(cpy_r_key) == 1))) {
        __tmp45 = NULL;
        goto __LL46;
    }
    __tmp45 = PyTuple_GET_ITEM(cpy_r_key, 0);
    if (__tmp45 == NULL) goto __LL46;
    __tmp45 = cpy_r_key;
__LL46: ;
    if (unlikely(__tmp45 == NULL)) {
        CPy_TypeError("tuple[object]", cpy_r_key); cpy_r_r50 = (tuple_T1O) { NULL };
    } else {
        PyObject *__tmp47 = PyTuple_GET_ITEM(cpy_r_key, 0);
        CPy_INCREF(__tmp47);
        PyObject *__tmp48;
        __tmp48 = __tmp47;
        cpy_r_r50.f0 = __tmp48;
    }
    if (unlikely(cpy_r_r50.f0 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL38;
    }
    cpy_r_r51 = cpy_r_r50.f0;
    CPy_INCREF(cpy_r_r51);
    CPy_DECREF(cpy_r_r50.f0);
    cpy_r_r52 = CPy_TYPE(cpy_r_r51);
    cpy_r_r53 = (PyObject *)&PyLong_Type;
    cpy_r_r54 = cpy_r_r52 == cpy_r_r53;
    if (cpy_r_r54) goto CPyL43;
    cpy_r_r55 = (PyObject *)&PyUnicode_Type;
    cpy_r_r56 = cpy_r_r52 == cpy_r_r55;
    CPy_DECREF(cpy_r_r52);
    if (cpy_r_r56) {
        goto CPyL44;
    } else
        goto CPyL45;
CPyL31: ;
    if (PyUnicode_Check(cpy_r_r51))
        cpy_r_r57 = cpy_r_r51;
    else {
        cpy_r_r57 = NULL;
    }
    if (cpy_r_r57 != NULL) goto __LL49;
    if (PyLong_Check(cpy_r_r51))
        cpy_r_r57 = cpy_r_r51;
    else {
        cpy_r_r57 = NULL;
    }
    if (cpy_r_r57 != NULL) goto __LL49;
    if (Py_TYPE(cpy_r_r51) == CPyType__HashedSeq)
        cpy_r_r57 = cpy_r_r51;
    else {
        cpy_r_r57 = NULL;
    }
    if (cpy_r_r57 != NULL) goto __LL49;
    CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "_make_key", 456, CPyStatic_globals, "union[str, int, faster_async_lru._HashedSeq]", cpy_r_r51);
    goto CPyL36;
__LL49: ;
    return cpy_r_r57;
CPyL33: ;
    cpy_r_r58 = (PyObject *)CPyType__HashedSeq;
    PyObject *cpy_r_r59[1] = {cpy_r_key};
    cpy_r_r60 = (PyObject **)&cpy_r_r59;
    cpy_r_r61 = PyObject_Vectorcall(cpy_r_r58, cpy_r_r60, 1, 0);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_DECREF(cpy_r_key);
    if (likely(Py_TYPE(cpy_r_r61) == CPyType__HashedSeq))
        cpy_r_r62 = cpy_r_r61;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "_make_key", 457, CPyStatic_globals, "faster_async_lru._HashedSeq", cpy_r_r61);
        goto CPyL36;
    }
    return cpy_r_r62;
CPyL36: ;
    cpy_r_r63 = NULL;
    return cpy_r_r63;
CPyL37: ;
    CPy_DecRef(cpy_r_key);
    goto CPyL2;
CPyL38: ;
    CPy_DecRef(cpy_r_key);
    goto CPyL36;
CPyL39: ;
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r11.f2);
    CPy_DECREF(cpy_r_r11.f3);
    goto CPyL12;
CPyL40: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL36;
CPyL41: ;
    CPy_DecRef(cpy_r_key);
    CPy_DecRef(cpy_r_r10);
    goto CPyL36;
CPyL42: ;
    CPy_DecRef(cpy_r_key);
    CPy_DecRef(cpy_r_r36);
    goto CPyL36;
CPyL43: ;
    CPy_DECREF(cpy_r_key);
    CPy_DECREF(cpy_r_r52);
    goto CPyL31;
CPyL44: ;
    CPy_DECREF(cpy_r_key);
    goto CPyL31;
CPyL45: ;
    CPy_DECREF(cpy_r_r51);
    goto CPyL33;
}

PyObject *CPyPy__make_key(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"args", "kwds", "typed", 0};
    static CPyArg_Parser parser = {"OOO:_make_key", kwlist, 0};
    PyObject *obj_args;
    PyObject *obj_kwds;
    PyObject *obj_typed;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_args, &obj_kwds, &obj_typed)) {
        return NULL;
    }
    PyObject * arg_args;
    if (likely(PyTuple_Check(obj_args)))
        arg_args = obj_args;
    else {
        CPy_TypeError("tuple", obj_args); 
        goto fail;
    }
    PyObject *arg_kwds;
    if (likely(PyDict_Check(obj_kwds)))
        arg_kwds = obj_kwds;
    else {
        CPy_TypeError("dict", obj_kwds); 
        goto fail;
    }
    char arg_typed;
    if (unlikely(!PyBool_Check(obj_typed))) {
        CPy_TypeError("bool", obj_typed); goto fail;
    } else
        arg_typed = obj_typed == Py_True;
    PyObject *retval = CPyDef__make_key(arg_args, arg_kwds, arg_typed);
    return retval;
fail: ;
    CPy_AddTraceback("faster_async_lru/__init__.py", "_make_key", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
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
    void *cpy_r_r11;
    void *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
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
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    tuple_T2II cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    tuple_T2II cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    char cpy_r_r55;
    char cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    int32_t cpy_r_r60;
    char cpy_r_r61;
    PyObject *cpy_r_r62;
    tuple_T1O cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    int32_t cpy_r_r67;
    char cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject **cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    int32_t cpy_r_r78;
    char cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject **cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    int32_t cpy_r_r89;
    char cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    tuple_T3OOO cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    int32_t cpy_r_r108;
    char cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    tuple_T2OO cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    int32_t cpy_r_r126;
    char cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    tuple_T3OOO cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    int32_t cpy_r_r145;
    char cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    tuple_T2II cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    char cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    int32_t cpy_r_r158;
    char cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    tuple_T2II cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    char cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    int32_t cpy_r_r171;
    char cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    CPyPtr cpy_r_r179;
    CPyPtr cpy_r_r180;
    CPyPtr cpy_r_r181;
    CPyPtr cpy_r_r182;
    CPyPtr cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject **cpy_r_r188;
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
    char cpy_r_r236;
    char cpy_r_r237;
    PyObject *cpy_r_r238;
    PyObject *cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    int32_t cpy_r_r245;
    char cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject *cpy_r_r248;
    char cpy_r_r249;
    PyObject *cpy_r_r250;
    PyObject *cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_r255;
    PyObject *cpy_r_r256;
    PyObject *cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    char cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject *cpy_r_r262;
    PyObject *cpy_r_r263;
    PyObject *cpy_r_r264;
    PyObject *cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    char cpy_r_r269;
    PyObject *cpy_r_r270;
    PyObject *cpy_r_r271;
    PyObject *cpy_r_r272;
    PyObject **cpy_r_r274;
    PyObject *cpy_r_r275;
    PyObject *cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject *cpy_r_r278;
    PyObject *cpy_r_r279;
    PyObject *cpy_r_r280;
    PyObject *cpy_r_r281;
    int32_t cpy_r_r282;
    char cpy_r_r283;
    PyObject *cpy_r_r284;
    PyObject *cpy_r_r285;
    int32_t cpy_r_r286;
    char cpy_r_r287;
    PyObject *cpy_r_r288;
    PyObject *cpy_r_r289;
    int32_t cpy_r_r290;
    char cpy_r_r291;
    PyObject *cpy_r_r292;
    PyObject *cpy_r_r293;
    int32_t cpy_r_r294;
    char cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject *cpy_r_r297;
    int32_t cpy_r_r298;
    char cpy_r_r299;
    PyObject *cpy_r_r300;
    PyObject *cpy_r_r301;
    int32_t cpy_r_r302;
    char cpy_r_r303;
    PyObject *cpy_r_r304;
    PyObject *cpy_r_r305;
    int32_t cpy_r_r306;
    char cpy_r_r307;
    PyObject **cpy_r_r309;
    PyObject *cpy_r_r310;
    PyObject *cpy_r_r311;
    PyObject *cpy_r_r312;
    PyObject *cpy_r_r313;
    PyObject **cpy_r_r315;
    PyObject *cpy_r_r316;
    PyObject *cpy_r_r317;
    PyObject *cpy_r_r318;
    int32_t cpy_r_r319;
    char cpy_r_r320;
    PyObject *cpy_r_r321;
    PyObject *cpy_r_r322;
    PyObject *cpy_r_r323;
    PyObject *cpy_r_r324;
    PyObject *cpy_r_r325;
    PyObject *cpy_r_r326;
    PyObject *cpy_r_r327;
    PyObject *cpy_r_r328;
    PyObject *cpy_r_r329;
    PyObject *cpy_r_r330;
    PyObject *cpy_r_r331;
    PyObject *cpy_r_r332;
    char cpy_r_r333;
    PyObject *cpy_r_r334;
    PyObject *cpy_r_r335;
    PyObject *cpy_r_r336;
    PyObject *cpy_r_r337;
    PyObject *cpy_r_r338;
    PyObject *cpy_r_r339;
    int32_t cpy_r_r340;
    char cpy_r_r341;
    PyObject *cpy_r_r342;
    PyObject *cpy_r_r343;
    int32_t cpy_r_r344;
    char cpy_r_r345;
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
    PyObject *cpy_r_r364;
    PyObject *cpy_r_r365;
    PyObject *cpy_r_r366;
    PyObject *cpy_r_r367;
    PyObject *cpy_r_r368;
    PyObject *cpy_r_r369;
    PyObject *cpy_r_r370;
    PyObject *cpy_r_r371;
    PyObject *cpy_r_r372;
    PyObject *cpy_r_r373;
    PyObject *cpy_r_r374;
    int32_t cpy_r_r375;
    char cpy_r_r376;
    PyObject *cpy_r_r377;
    PyObject *cpy_r_r378;
    int32_t cpy_r_r379;
    char cpy_r_r380;
    PyObject *cpy_r_r381;
    PyObject *cpy_r_r382;
    PyObject *cpy_r_r383;
    PyObject *cpy_r_r384;
    PyObject *cpy_r_r385;
    PyObject *cpy_r_r386;
    PyObject *cpy_r_r387;
    PyObject *cpy_r_r388;
    PyObject *cpy_r_r389;
    tuple_T2OO cpy_r_r390;
    PyObject *cpy_r_r391;
    PyObject *cpy_r_r392;
    PyObject *cpy_r_r393;
    PyObject *cpy_r_r394;
    PyObject *cpy_r_r395;
    PyObject *cpy_r_r396;
    char cpy_r_r397;
    PyObject *cpy_r_r398;
    PyObject *cpy_r_r399;
    PyObject *cpy_r_r400;
    PyObject *cpy_r_r401;
    PyObject *cpy_r_r402;
    PyObject *cpy_r_r403;
    PyObject *cpy_r_r404;
    PyObject *cpy_r_r405;
    PyObject *cpy_r_r406;
    PyObject *cpy_r_r407;
    PyObject *cpy_r_r408;
    PyObject *cpy_r_r409;
    int32_t cpy_r_r410;
    char cpy_r_r411;
    PyObject *cpy_r_r412;
    PyObject *cpy_r_r413;
    int32_t cpy_r_r414;
    char cpy_r_r415;
    PyObject *cpy_r_r416;
    PyObject *cpy_r_r417;
    PyObject *cpy_r_r418;
    PyObject *cpy_r_r419;
    PyObject *cpy_r_r420;
    PyObject *cpy_r_r421;
    PyObject *cpy_r_r422;
    char cpy_r_r423;
    PyObject *cpy_r_r424;
    PyObject *cpy_r_r425;
    PyObject *cpy_r_r426;
    PyObject **cpy_r_r428;
    PyObject *cpy_r_r429;
    PyObject *cpy_r_r430;
    PyObject *cpy_r_r431;
    PyObject *cpy_r_r432;
    PyObject *cpy_r_r433;
    PyObject *cpy_r_r434;
    PyObject *cpy_r_r435;
    int32_t cpy_r_r436;
    char cpy_r_r437;
    PyObject *cpy_r_r438;
    PyObject *cpy_r_r439;
    int32_t cpy_r_r440;
    char cpy_r_r441;
    PyObject *cpy_r_r442;
    PyObject *cpy_r_r443;
    int32_t cpy_r_r444;
    char cpy_r_r445;
    PyObject *cpy_r_r446;
    PyObject *cpy_r_r447;
    int32_t cpy_r_r448;
    char cpy_r_r449;
    PyObject *cpy_r_r450;
    PyObject *cpy_r_r451;
    int32_t cpy_r_r452;
    char cpy_r_r453;
    PyObject *cpy_r_r454;
    PyObject *cpy_r_r455;
    int32_t cpy_r_r456;
    char cpy_r_r457;
    PyObject *cpy_r_r458;
    PyObject *cpy_r_r459;
    int32_t cpy_r_r460;
    char cpy_r_r461;
    PyObject **cpy_r_r463;
    PyObject *cpy_r_r464;
    PyObject *cpy_r_r465;
    PyObject *cpy_r_r466;
    PyObject *cpy_r_r467;
    PyObject *cpy_r_r468;
    PyObject **cpy_r_r470;
    PyObject *cpy_r_r471;
    PyObject *cpy_r_r472;
    PyObject **cpy_r_r474;
    PyObject *cpy_r_r475;
    PyObject *cpy_r_r476;
    PyObject *cpy_r_r477;
    PyObject *cpy_r_r478;
    PyObject **cpy_r_r480;
    PyObject *cpy_r_r481;
    PyObject *cpy_r_r482;
    PyObject *cpy_r_r483;
    int32_t cpy_r_r484;
    char cpy_r_r485;
    PyObject *cpy_r_r486;
    PyObject *cpy_r_r487;
    PyObject *cpy_r_r488;
    PyObject *cpy_r_r489;
    PyObject *cpy_r_r490;
    tuple_T1O cpy_r_r491;
    PyObject *cpy_r_r492;
    PyObject *cpy_r_r493;
    PyObject *cpy_r_r494;
    int32_t cpy_r_r495;
    char cpy_r_r496;
    char cpy_r_r497;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL173;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_asyncio;
    cpy_r_r6 = (PyObject **)&CPyModule_functools;
    cpy_r_r7 = (PyObject **)&CPyModule_inspect;
    cpy_r_r8 = (PyObject **)&CPyModule_os;
    cpy_r_r9 = (PyObject **)&CPyModule_sys;
    PyObject **cpy_r_r10[5] = {cpy_r_r5, cpy_r_r6, cpy_r_r7, cpy_r_r8, cpy_r_r9};
    cpy_r_r11 = (void *)&cpy_r_r10;
    int64_t cpy_r_r12[5] = {1, 2, 3, 4, 5};
    cpy_r_r13 = (void *)&cpy_r_r12;
    cpy_r_r14 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* (('asyncio', 'asyncio', 'asyncio'),
                                    ('functools', 'functools', 'functools'),
                                    ('inspect', 'inspect', 'inspect'), ('os', 'os', 'os'),
                                    ('sys', 'sys', 'sys')) */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'faster_async_lru/__init__.py' */
    cpy_r_r17 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '<module>' */
    cpy_r_r18 = CPyImport_ImportMany(cpy_r_r14, cpy_r_r11, cpy_r_r15, cpy_r_r16, cpy_r_r17, cpy_r_r13);
    if (!cpy_r_r18) goto CPyL173;
    cpy_r_r19 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('OrderedDict', 'namedtuple') */
    cpy_r_r20 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'collections' */
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyModule_collections = cpy_r_r22;
    CPy_INCREF(CPyModule_collections);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('Callable', 'Coroutine', 'Hashable') */
    cpy_r_r24 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'collections.abc' */
    cpy_r_r25 = CPyStatic_globals;
    cpy_r_r26 = CPyImport_ImportFromMany(cpy_r_r24, cpy_r_r23, cpy_r_r23, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyModule_collections___abc = cpy_r_r26;
    CPy_INCREF(CPyModule_collections___abc);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r27 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('Any', 'Final', 'Generic', 'Optional', 'TypedDict',
                                    'TypeVar', 'Union', 'cast', 'final', 'overload') */
    cpy_r_r28 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r29 = CPyStatic_globals;
    cpy_r_r30 = CPyImport_ImportFromMany(cpy_r_r28, cpy_r_r27, cpy_r_r27, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyModule_typing = cpy_r_r30;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r31 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('mypyc_attr',) */
    cpy_r_r32 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'mypy_extensions' */
    cpy_r_r33 = CPyStatic_globals;
    cpy_r_r34 = CPyImport_ImportFromMany(cpy_r_r32, cpy_r_r31, cpy_r_r31, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyModule_mypy_extensions = cpy_r_r34;
    CPy_INCREF(CPyModule_mypy_extensions);
    CPy_DECREF(cpy_r_r34);
    cpy_r_r35 = CPyModule_sys;
    cpy_r_r36 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    if (likely(PyTuple_Check(cpy_r_r37)))
        cpy_r_r38 = cpy_r_r37;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "<module>", 24, CPyStatic_globals, "tuple", cpy_r_r37);
        goto CPyL173;
    }
    cpy_r_r39.f0 = 6;
    cpy_r_r39.f1 = 22;
    cpy_r_r40 = PyTuple_New(2);
    if (unlikely(cpy_r_r40 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp50 = CPyTagged_StealAsObject(cpy_r_r39.f0);
    PyTuple_SET_ITEM(cpy_r_r40, 0, __tmp50);
    PyObject *__tmp51 = CPyTagged_StealAsObject(cpy_r_r39.f1);
    PyTuple_SET_ITEM(cpy_r_r40, 1, __tmp51);
    cpy_r_r41 = PyObject_RichCompare(cpy_r_r38, cpy_r_r40, 5);
    CPy_DECREF(cpy_r_r38);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    if (unlikely(!PyBool_Check(cpy_r_r41))) {
        CPy_TypeError("bool", cpy_r_r41); cpy_r_r42 = 2;
    } else
        cpy_r_r42 = cpy_r_r41 == Py_True;
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r42 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    if (!cpy_r_r42) goto CPyL15;
    cpy_r_r43 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('Self',) */
    cpy_r_r44 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r45 = CPyStatic_globals;
    cpy_r_r46 = CPyImport_ImportFromMany(cpy_r_r44, cpy_r_r43, cpy_r_r43, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyModule_typing = cpy_r_r46;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r46);
    goto CPyL17;
CPyL15: ;
    PyErr_SetString(PyExc_RuntimeError, "Reached allegedly unreachable code!");
    cpy_r_r47 = 0;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPy_Unreachable();
CPyL17: ;
    cpy_r_r48 = CPyModule_sys;
    cpy_r_r49 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_r48, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    if (likely(PyTuple_Check(cpy_r_r50)))
        cpy_r_r51 = cpy_r_r50;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "<module>", 29, CPyStatic_globals, "tuple", cpy_r_r50);
        goto CPyL173;
    }
    cpy_r_r52.f0 = 6;
    cpy_r_r52.f1 = 28;
    cpy_r_r53 = PyTuple_New(2);
    if (unlikely(cpy_r_r53 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp52 = CPyTagged_StealAsObject(cpy_r_r52.f0);
    PyTuple_SET_ITEM(cpy_r_r53, 0, __tmp52);
    PyObject *__tmp53 = CPyTagged_StealAsObject(cpy_r_r52.f1);
    PyTuple_SET_ITEM(cpy_r_r53, 1, __tmp53);
    cpy_r_r54 = PyObject_RichCompare(cpy_r_r51, cpy_r_r53, 0);
    CPy_DECREF(cpy_r_r51);
    CPy_DECREF(cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    if (unlikely(!PyBool_Check(cpy_r_r54))) {
        CPy_TypeError("bool", cpy_r_r54); cpy_r_r55 = 2;
    } else
        cpy_r_r55 = cpy_r_r54 == Py_True;
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r55 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    if (!cpy_r_r55) goto CPyL24;
    PyErr_SetString(PyExc_RuntimeError, "Reached allegedly unreachable code!");
    cpy_r_r56 = 0;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPy_Unreachable();
CPyL24: ;
    cpy_r_r57 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '2.0.5.3' */
    cpy_r_r58 = CPyStatic_globals;
    cpy_r_r59 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__version__' */
    cpy_r_r60 = CPyDict_SetItem(cpy_r_r58, cpy_r_r59, cpy_r_r57);
    cpy_r_r61 = cpy_r_r60 >= 0;
    if (unlikely(!cpy_r_r61)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r62 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'alru_cache' */
    CPy_INCREF(cpy_r_r62);
    cpy_r_r63.f0 = cpy_r_r62;
    cpy_r_r64 = CPyStatic_globals;
    cpy_r_r65 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__all__' */
    cpy_r_r66 = PyTuple_New(1);
    if (unlikely(cpy_r_r66 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp54 = cpy_r_r63.f0;
    PyTuple_SET_ITEM(cpy_r_r66, 0, __tmp54);
    cpy_r_r67 = CPyDict_SetItem(cpy_r_r64, cpy_r_r65, cpy_r_r66);
    CPy_DECREF(cpy_r_r66);
    cpy_r_r68 = cpy_r_r67 >= 0;
    if (unlikely(!cpy_r_r68)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r69 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_T' */
    cpy_r_r70 = CPyStatic_globals;
    cpy_r_r71 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'TypeVar' */
    cpy_r_r72 = CPyDict_GetItem(cpy_r_r70, cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    PyObject *cpy_r_r73[1] = {cpy_r_r69};
    cpy_r_r74 = (PyObject **)&cpy_r_r73;
    cpy_r_r75 = PyObject_Vectorcall(cpy_r_r72, cpy_r_r74, 1, 0);
    CPy_DECREF(cpy_r_r72);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r76 = CPyStatic_globals;
    cpy_r_r77 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_T' */
    cpy_r_r78 = CPyDict_SetItem(cpy_r_r76, cpy_r_r77, cpy_r_r75);
    CPy_DECREF(cpy_r_r75);
    cpy_r_r79 = cpy_r_r78 >= 0;
    if (unlikely(!cpy_r_r79)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r80 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r81 = CPyStatic_globals;
    cpy_r_r82 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'TypeVar' */
    cpy_r_r83 = CPyDict_GetItem(cpy_r_r81, cpy_r_r82);
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    PyObject *cpy_r_r84[1] = {cpy_r_r80};
    cpy_r_r85 = (PyObject **)&cpy_r_r84;
    cpy_r_r86 = PyObject_Vectorcall(cpy_r_r83, cpy_r_r85, 1, 0);
    CPy_DECREF(cpy_r_r83);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r87 = CPyStatic_globals;
    cpy_r_r88 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r89 = CPyDict_SetItem(cpy_r_r87, cpy_r_r88, cpy_r_r86);
    CPy_DECREF(cpy_r_r86);
    cpy_r_r90 = cpy_r_r89 >= 0;
    if (unlikely(!cpy_r_r90)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r91 = CPyStatic_globals;
    cpy_r_r92 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Coroutine' */
    cpy_r_r93 = CPyDict_GetItem(cpy_r_r91, cpy_r_r92);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r94 = CPyStatic_globals;
    cpy_r_r95 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Any' */
    cpy_r_r96 = CPyDict_GetItem(cpy_r_r94, cpy_r_r95);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL174;
    }
    cpy_r_r97 = CPyStatic_globals;
    cpy_r_r98 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Any' */
    cpy_r_r99 = CPyDict_GetItem(cpy_r_r97, cpy_r_r98);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL175;
    }
    cpy_r_r100 = CPyStatic_globals;
    cpy_r_r101 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r102 = CPyDict_GetItem(cpy_r_r100, cpy_r_r101);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL176;
    }
    cpy_r_r103.f0 = cpy_r_r96;
    cpy_r_r103.f1 = cpy_r_r99;
    cpy_r_r103.f2 = cpy_r_r102;
    cpy_r_r104 = PyTuple_New(3);
    if (unlikely(cpy_r_r104 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp55 = cpy_r_r103.f0;
    PyTuple_SET_ITEM(cpy_r_r104, 0, __tmp55);
    PyObject *__tmp56 = cpy_r_r103.f1;
    PyTuple_SET_ITEM(cpy_r_r104, 1, __tmp56);
    PyObject *__tmp57 = cpy_r_r103.f2;
    PyTuple_SET_ITEM(cpy_r_r104, 2, __tmp57);
    cpy_r_r105 = PyObject_GetItem(cpy_r_r93, cpy_r_r104);
    CPy_DECREF(cpy_r_r93);
    CPy_DECREF(cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r106 = CPyStatic_globals;
    cpy_r_r107 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_Coro' */
    cpy_r_r108 = CPyDict_SetItem(cpy_r_r106, cpy_r_r107, cpy_r_r105);
    CPy_DECREF(cpy_r_r105);
    cpy_r_r109 = cpy_r_r108 >= 0;
    if (unlikely(!cpy_r_r109)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r110 = CPyStatic_globals;
    cpy_r_r111 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Callable' */
    cpy_r_r112 = CPyDict_GetItem(cpy_r_r110, cpy_r_r111);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r113 = (PyObject *)&_Py_EllipsisObject;
    cpy_r_r114 = CPyStatic_globals;
    cpy_r_r115 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_Coro' */
    cpy_r_r116 = CPyDict_GetItem(cpy_r_r114, cpy_r_r115);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r117 = CPyStatic_globals;
    cpy_r_r118 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r119 = CPyDict_GetItem(cpy_r_r117, cpy_r_r118);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL178;
    }
    cpy_r_r120 = PyObject_GetItem(cpy_r_r116, cpy_r_r119);
    CPy_DECREF(cpy_r_r116);
    CPy_DECREF(cpy_r_r119);
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL177;
    }
    CPy_INCREF(cpy_r_r113);
    cpy_r_r121.f0 = cpy_r_r113;
    cpy_r_r121.f1 = cpy_r_r120;
    cpy_r_r122 = PyTuple_New(2);
    if (unlikely(cpy_r_r122 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp58 = cpy_r_r121.f0;
    PyTuple_SET_ITEM(cpy_r_r122, 0, __tmp58);
    PyObject *__tmp59 = cpy_r_r121.f1;
    PyTuple_SET_ITEM(cpy_r_r122, 1, __tmp59);
    cpy_r_r123 = PyObject_GetItem(cpy_r_r112, cpy_r_r122);
    CPy_DECREF(cpy_r_r112);
    CPy_DECREF(cpy_r_r122);
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r124 = CPyStatic_globals;
    cpy_r_r125 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CB' */
    cpy_r_r126 = CPyDict_SetItem(cpy_r_r124, cpy_r_r125, cpy_r_r123);
    CPy_DECREF(cpy_r_r123);
    cpy_r_r127 = cpy_r_r126 >= 0;
    if (unlikely(!cpy_r_r127)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r128 = CPyStatic_globals;
    cpy_r_r129 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Union' */
    cpy_r_r130 = CPyDict_GetItem(cpy_r_r128, cpy_r_r129);
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r131 = CPyStatic_globals;
    cpy_r_r132 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CB' */
    cpy_r_r133 = CPyDict_GetItem(cpy_r_r131, cpy_r_r132);
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL179;
    }
    cpy_r_r134 = CPyStatic_globals;
    cpy_r_r135 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r136 = CPyDict_GetItem(cpy_r_r134, cpy_r_r135);
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL180;
    }
    cpy_r_r137 = PyObject_GetItem(cpy_r_r133, cpy_r_r136);
    CPy_DECREF(cpy_r_r133);
    CPy_DECREF(cpy_r_r136);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL179;
    }
    cpy_r_r138 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'functools.partial[_Coro[_R]]' */
    cpy_r_r139 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'functools.partialmethod[_Coro[_R]]' */
    CPy_INCREF(cpy_r_r138);
    CPy_INCREF(cpy_r_r139);
    cpy_r_r140.f0 = cpy_r_r137;
    cpy_r_r140.f1 = cpy_r_r138;
    cpy_r_r140.f2 = cpy_r_r139;
    cpy_r_r141 = PyTuple_New(3);
    if (unlikely(cpy_r_r141 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp60 = cpy_r_r140.f0;
    PyTuple_SET_ITEM(cpy_r_r141, 0, __tmp60);
    PyObject *__tmp61 = cpy_r_r140.f1;
    PyTuple_SET_ITEM(cpy_r_r141, 1, __tmp61);
    PyObject *__tmp62 = cpy_r_r140.f2;
    PyTuple_SET_ITEM(cpy_r_r141, 2, __tmp62);
    cpy_r_r142 = PyObject_GetItem(cpy_r_r130, cpy_r_r141);
    CPy_DECREF(cpy_r_r130);
    CPy_DECREF(cpy_r_r141);
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r143 = CPyStatic_globals;
    cpy_r_r144 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CBP' */
    cpy_r_r145 = CPyDict_SetItem(cpy_r_r143, cpy_r_r144, cpy_r_r142);
    CPy_DECREF(cpy_r_r142);
    cpy_r_r146 = cpy_r_r145 >= 0;
    if (unlikely(!cpy_r_r146)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r147 = CPyModule_sys;
    cpy_r_r148 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r149 = CPyObject_GetAttr(cpy_r_r147, cpy_r_r148);
    if (unlikely(cpy_r_r149 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    if (likely(PyTuple_Check(cpy_r_r149)))
        cpy_r_r150 = cpy_r_r149;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "<module>", 44, CPyStatic_globals, "tuple", cpy_r_r149);
        goto CPyL173;
    }
    cpy_r_r151.f0 = 6;
    cpy_r_r151.f1 = 24;
    cpy_r_r152 = PyTuple_New(2);
    if (unlikely(cpy_r_r152 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp63 = CPyTagged_StealAsObject(cpy_r_r151.f0);
    PyTuple_SET_ITEM(cpy_r_r152, 0, __tmp63);
    PyObject *__tmp64 = CPyTagged_StealAsObject(cpy_r_r151.f1);
    PyTuple_SET_ITEM(cpy_r_r152, 1, __tmp64);
    cpy_r_r153 = PyObject_RichCompare(cpy_r_r150, cpy_r_r152, 5);
    CPy_DECREF(cpy_r_r150);
    CPy_DECREF(cpy_r_r152);
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    if (unlikely(!PyBool_Check(cpy_r_r153))) {
        CPy_TypeError("bool", cpy_r_r153); cpy_r_r154 = 2;
    } else
        cpy_r_r154 = cpy_r_r153 == Py_True;
    CPy_DECREF(cpy_r_r153);
    if (unlikely(cpy_r_r154 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyStatic__PYTHON_GTE_312 = cpy_r_r154;
    cpy_r_r155 = CPyStatic_globals;
    cpy_r_r156 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_PYTHON_GTE_312' */
    cpy_r_r157 = cpy_r_r154 ? Py_True : Py_False;
    cpy_r_r158 = CPyDict_SetItem(cpy_r_r155, cpy_r_r156, cpy_r_r157);
    cpy_r_r159 = cpy_r_r158 >= 0;
    if (unlikely(!cpy_r_r159)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r160 = CPyModule_sys;
    cpy_r_r161 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'version_info' */
    cpy_r_r162 = CPyObject_GetAttr(cpy_r_r160, cpy_r_r161);
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    if (likely(PyTuple_Check(cpy_r_r162)))
        cpy_r_r163 = cpy_r_r162;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "<module>", 45, CPyStatic_globals, "tuple", cpy_r_r162);
        goto CPyL173;
    }
    cpy_r_r164.f0 = 6;
    cpy_r_r164.f1 = 28;
    cpy_r_r165 = PyTuple_New(2);
    if (unlikely(cpy_r_r165 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp65 = CPyTagged_StealAsObject(cpy_r_r164.f0);
    PyTuple_SET_ITEM(cpy_r_r165, 0, __tmp65);
    PyObject *__tmp66 = CPyTagged_StealAsObject(cpy_r_r164.f1);
    PyTuple_SET_ITEM(cpy_r_r165, 1, __tmp66);
    cpy_r_r166 = PyObject_RichCompare(cpy_r_r163, cpy_r_r165, 0);
    CPy_DECREF(cpy_r_r163);
    CPy_DECREF(cpy_r_r165);
    if (unlikely(cpy_r_r166 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    if (unlikely(!PyBool_Check(cpy_r_r166))) {
        CPy_TypeError("bool", cpy_r_r166); cpy_r_r167 = 2;
    } else
        cpy_r_r167 = cpy_r_r166 == Py_True;
    CPy_DECREF(cpy_r_r166);
    if (unlikely(cpy_r_r167 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyStatic__PYTHON_LT_314 = cpy_r_r167;
    cpy_r_r168 = CPyStatic_globals;
    cpy_r_r169 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_PYTHON_LT_314' */
    cpy_r_r170 = cpy_r_r167 ? Py_True : Py_False;
    cpy_r_r171 = CPyDict_SetItem(cpy_r_r168, cpy_r_r169, cpy_r_r170);
    cpy_r_r172 = cpy_r_r171 >= 0;
    if (unlikely(!cpy_r_r172)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r173 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheInfo' */
    cpy_r_r174 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'hits' */
    cpy_r_r175 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'misses' */
    cpy_r_r176 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'maxsize' */
    cpy_r_r177 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'currsize' */
    cpy_r_r178 = PyList_New(4);
    if (unlikely(cpy_r_r178 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r179 = (CPyPtr)&((PyListObject *)cpy_r_r178)->ob_item;
    cpy_r_r180 = *(CPyPtr *)cpy_r_r179;
    CPy_INCREF(cpy_r_r174);
    *(PyObject * *)cpy_r_r180 = cpy_r_r174;
    CPy_INCREF(cpy_r_r175);
    cpy_r_r181 = cpy_r_r180 + 8;
    *(PyObject * *)cpy_r_r181 = cpy_r_r175;
    CPy_INCREF(cpy_r_r176);
    cpy_r_r182 = cpy_r_r180 + 16;
    *(PyObject * *)cpy_r_r182 = cpy_r_r176;
    CPy_INCREF(cpy_r_r177);
    cpy_r_r183 = cpy_r_r180 + 24;
    *(PyObject * *)cpy_r_r183 = cpy_r_r177;
    cpy_r_r184 = CPyStatic_globals;
    cpy_r_r185 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'namedtuple' */
    cpy_r_r186 = CPyDict_GetItem(cpy_r_r184, cpy_r_r185);
    if (unlikely(cpy_r_r186 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL181;
    }
    PyObject *cpy_r_r187[2] = {cpy_r_r173, cpy_r_r178};
    cpy_r_r188 = (PyObject **)&cpy_r_r187;
    cpy_r_r189 = PyObject_Vectorcall(cpy_r_r186, cpy_r_r188, 2, 0);
    CPy_DECREF(cpy_r_r186);
    if (unlikely(cpy_r_r189 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL181;
    }
    CPy_DECREF_NO_IMM(cpy_r_r178);
    cpy_r_r190 = CPyStatic_globals;
    cpy_r_r191 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheInfo' */
    cpy_r_r192 = CPyDict_SetItem(cpy_r_r190, cpy_r_r191, cpy_r_r189);
    CPy_DECREF(cpy_r_r189);
    cpy_r_r193 = cpy_r_r192 >= 0;
    if (unlikely(!cpy_r_r193)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r194 = CPyModule_asyncio;
    cpy_r_r195 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'CancelledError' */
    cpy_r_r196 = CPyObject_GetAttr(cpy_r_r194, cpy_r_r195);
    if (unlikely(cpy_r_r196 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyStatic_CancelledError = cpy_r_r196;
    CPy_INCREF(CPyStatic_CancelledError);
    cpy_r_r197 = CPyStatic_globals;
    cpy_r_r198 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'CancelledError' */
    cpy_r_r199 = CPyDict_SetItem(cpy_r_r197, cpy_r_r198, cpy_r_r196);
    CPy_DECREF(cpy_r_r196);
    cpy_r_r200 = cpy_r_r199 >= 0;
    if (unlikely(!cpy_r_r200)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r201 = CPyModule_functools;
    cpy_r_r202 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partial' */
    cpy_r_r203 = CPyObject_GetAttr(cpy_r_r201, cpy_r_r202);
    if (unlikely(cpy_r_r203 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyStatic_partial = cpy_r_r203;
    CPy_INCREF(CPyStatic_partial);
    cpy_r_r204 = CPyStatic_globals;
    cpy_r_r205 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partial' */
    cpy_r_r206 = CPyDict_SetItem(cpy_r_r204, cpy_r_r205, cpy_r_r203);
    CPy_DECREF(cpy_r_r203);
    cpy_r_r207 = cpy_r_r206 >= 0;
    if (unlikely(!cpy_r_r207)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r208 = CPyModule_functools;
    cpy_r_r209 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partialmethod' */
    cpy_r_r210 = CPyObject_GetAttr(cpy_r_r208, cpy_r_r209);
    if (unlikely(cpy_r_r210 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyStatic_partialmethod = cpy_r_r210;
    CPy_INCREF(CPyStatic_partialmethod);
    cpy_r_r211 = CPyStatic_globals;
    cpy_r_r212 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'partialmethod' */
    cpy_r_r213 = CPyDict_SetItem(cpy_r_r211, cpy_r_r212, cpy_r_r210);
    CPy_DECREF(cpy_r_r210);
    cpy_r_r214 = cpy_r_r213 >= 0;
    if (unlikely(!cpy_r_r214)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r215 = CPyModule_asyncio;
    cpy_r_r216 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'gather' */
    cpy_r_r217 = CPyObject_GetAttr(cpy_r_r215, cpy_r_r216);
    if (unlikely(cpy_r_r217 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyStatic_gather = cpy_r_r217;
    CPy_INCREF(CPyStatic_gather);
    cpy_r_r218 = CPyStatic_globals;
    cpy_r_r219 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'gather' */
    cpy_r_r220 = CPyDict_SetItem(cpy_r_r218, cpy_r_r219, cpy_r_r217);
    CPy_DECREF(cpy_r_r217);
    cpy_r_r221 = cpy_r_r220 >= 0;
    if (unlikely(!cpy_r_r221)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r222 = CPyModule_asyncio;
    cpy_r_r223 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'get_running_loop' */
    cpy_r_r224 = CPyObject_GetAttr(cpy_r_r222, cpy_r_r223);
    if (unlikely(cpy_r_r224 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyStatic_get_running_loop = cpy_r_r224;
    CPy_INCREF(CPyStatic_get_running_loop);
    cpy_r_r225 = CPyStatic_globals;
    cpy_r_r226 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'get_running_loop' */
    cpy_r_r227 = CPyDict_SetItem(cpy_r_r225, cpy_r_r226, cpy_r_r224);
    CPy_DECREF(cpy_r_r224);
    cpy_r_r228 = cpy_r_r227 >= 0;
    if (unlikely(!cpy_r_r228)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r229 = CPyModule_asyncio;
    cpy_r_r230 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'shield' */
    cpy_r_r231 = CPyObject_GetAttr(cpy_r_r229, cpy_r_r230);
    if (unlikely(cpy_r_r231 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyStatic_shield = cpy_r_r231;
    CPy_INCREF(CPyStatic_shield);
    cpy_r_r232 = CPyStatic_globals;
    cpy_r_r233 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'shield' */
    cpy_r_r234 = CPyDict_SetItem(cpy_r_r232, cpy_r_r233, cpy_r_r231);
    CPy_DECREF(cpy_r_r231);
    cpy_r_r235 = cpy_r_r234 >= 0;
    if (unlikely(!cpy_r_r235)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r236 = CPyStatic__PYTHON_GTE_312;
    if (likely(cpy_r_r236 != 2)) goto CPyL79;
    PyErr_SetString(PyExc_NameError, "value for final name \"_PYTHON_GTE_312\" was not set");
    cpy_r_r237 = 0;
    if (unlikely(!cpy_r_r237)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPy_Unreachable();
CPyL79: ;
    if (!cpy_r_r236) goto CPyL82;
    cpy_r_r238 = CPyModule_inspect;
    cpy_r_r239 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'markcoroutinefunction' */
    cpy_r_r240 = CPyObject_GetAttr(cpy_r_r238, cpy_r_r239);
    if (unlikely(cpy_r_r240 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r241 = cpy_r_r240;
    goto CPyL83;
CPyL82: ;
    cpy_r_r242 = Py_None;
    cpy_r_r241 = cpy_r_r242;
CPyL83: ;
    CPyStatic_markcoroutinefunction = cpy_r_r241;
    CPy_INCREF(CPyStatic_markcoroutinefunction);
    cpy_r_r243 = CPyStatic_globals;
    cpy_r_r244 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'markcoroutinefunction' */
    cpy_r_r245 = CPyDict_SetItem(cpy_r_r243, cpy_r_r244, cpy_r_r241);
    CPy_DECREF(cpy_r_r241);
    cpy_r_r246 = cpy_r_r245 >= 0;
    if (unlikely(!cpy_r_r246)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r247 = CPyModule_typing;
    cpy_r_r248 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r249 = cpy_r_r247 != cpy_r_r248;
    if (cpy_r_r249) goto CPyL87;
    cpy_r_r250 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r251 = PyImport_Import(cpy_r_r250);
    if (unlikely(cpy_r_r251 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    CPyModule_typing = cpy_r_r251;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r251);
CPyL87: ;
    cpy_r_r252 = PyImport_GetModuleDict();
    cpy_r_r253 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r254 = CPyDict_GetItem(cpy_r_r252, cpy_r_r253);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r255 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_TypedDict' */
    cpy_r_r256 = CPyObject_GetAttr(cpy_r_r254, cpy_r_r255);
    CPy_DECREF(cpy_r_r254);
    if (unlikely(cpy_r_r256 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r257 = PyTuple_Pack(1, cpy_r_r256);
    CPy_DECREF(cpy_r_r256);
    if (unlikely(cpy_r_r257 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r258 = CPyModule_typing;
    cpy_r_r259 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r260 = cpy_r_r258 != cpy_r_r259;
    if (cpy_r_r260) goto CPyL93;
    cpy_r_r261 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r262 = PyImport_Import(cpy_r_r261);
    if (unlikely(cpy_r_r262 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL182;
    }
    CPyModule_typing = cpy_r_r262;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r262);
CPyL93: ;
    cpy_r_r263 = PyImport_GetModuleDict();
    cpy_r_r264 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typing' */
    cpy_r_r265 = CPyDict_GetItem(cpy_r_r263, cpy_r_r264);
    if (unlikely(cpy_r_r265 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL182;
    }
    cpy_r_r266 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_TypedDictMeta' */
    cpy_r_r267 = CPyObject_GetAttr(cpy_r_r265, cpy_r_r266);
    CPy_DECREF(cpy_r_r265);
    if (unlikely(cpy_r_r267 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL182;
    }
    cpy_r_r268 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__prepare__' */
    cpy_r_r269 = PyObject_HasAttr(cpy_r_r267, cpy_r_r268);
    if (!cpy_r_r269) goto CPyL100;
    cpy_r_r270 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheParameters' */
    cpy_r_r271 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__prepare__' */
    cpy_r_r272 = CPyObject_GetAttr(cpy_r_r267, cpy_r_r271);
    if (unlikely(cpy_r_r272 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL183;
    }
    PyObject *cpy_r_r273[2] = {cpy_r_r270, cpy_r_r257};
    cpy_r_r274 = (PyObject **)&cpy_r_r273;
    cpy_r_r275 = PyObject_Vectorcall(cpy_r_r272, cpy_r_r274, 2, 0);
    CPy_DECREF(cpy_r_r272);
    if (unlikely(cpy_r_r275 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL183;
    }
    if (likely(PyDict_Check(cpy_r_r275)))
        cpy_r_r276 = cpy_r_r275;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "<module>", 62, CPyStatic_globals, "dict", cpy_r_r275);
        goto CPyL183;
    }
    cpy_r_r277 = cpy_r_r276;
    goto CPyL102;
CPyL100: ;
    cpy_r_r278 = PyDict_New();
    if (unlikely(cpy_r_r278 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL183;
    }
    cpy_r_r277 = cpy_r_r278;
CPyL102: ;
    cpy_r_r279 = PyDict_New();
    if (unlikely(cpy_r_r279 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL184;
    }
    cpy_r_r280 = (PyObject *)&PyBool_Type;
    cpy_r_r281 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'typed' */
    cpy_r_r282 = PyDict_SetItem(cpy_r_r279, cpy_r_r281, cpy_r_r280);
    cpy_r_r283 = cpy_r_r282 >= 0;
    if (unlikely(!cpy_r_r283)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL185;
    }
    cpy_r_r284 = (PyObject *)&PyType_Type;
    cpy_r_r285 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'maxsize' */
    cpy_r_r286 = PyDict_SetItem(cpy_r_r279, cpy_r_r285, cpy_r_r284);
    cpy_r_r287 = cpy_r_r286 >= 0;
    if (unlikely(!cpy_r_r287)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL185;
    }
    cpy_r_r288 = (PyObject *)&PyLong_Type;
    cpy_r_r289 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'tasks' */
    cpy_r_r290 = PyDict_SetItem(cpy_r_r279, cpy_r_r289, cpy_r_r288);
    cpy_r_r291 = cpy_r_r290 >= 0;
    if (unlikely(!cpy_r_r291)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL185;
    }
    cpy_r_r292 = (PyObject *)&PyBool_Type;
    cpy_r_r293 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'closed' */
    cpy_r_r294 = PyDict_SetItem(cpy_r_r279, cpy_r_r293, cpy_r_r292);
    cpy_r_r295 = cpy_r_r294 >= 0;
    if (unlikely(!cpy_r_r295)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL185;
    }
    cpy_r_r296 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheParameters' */
    cpy_r_r297 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r298 = CPyDict_SetItem(cpy_r_r277, cpy_r_r297, cpy_r_r279);
    CPy_DECREF(cpy_r_r279);
    cpy_r_r299 = cpy_r_r298 >= 0;
    if (unlikely(!cpy_r_r299)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL184;
    }
    cpy_r_r300 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'mypyc filler docstring' */
    cpy_r_r301 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r302 = CPyDict_SetItem(cpy_r_r277, cpy_r_r301, cpy_r_r300);
    cpy_r_r303 = cpy_r_r302 >= 0;
    if (unlikely(!cpy_r_r303)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL184;
    }
    cpy_r_r304 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'faster_async_lru' */
    cpy_r_r305 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r306 = CPyDict_SetItem(cpy_r_r277, cpy_r_r305, cpy_r_r304);
    cpy_r_r307 = cpy_r_r306 >= 0;
    if (unlikely(!cpy_r_r307)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL184;
    }
    PyObject *cpy_r_r308[3] = {cpy_r_r296, cpy_r_r257, cpy_r_r277};
    cpy_r_r309 = (PyObject **)&cpy_r_r308;
    cpy_r_r310 = PyObject_Vectorcall(cpy_r_r267, cpy_r_r309, 3, 0);
    CPy_DECREF(cpy_r_r267);
    if (unlikely(cpy_r_r310 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL186;
    }
    CPy_DECREF(cpy_r_r257);
    CPy_DECREF(cpy_r_r277);
    cpy_r_r311 = CPyStatic_globals;
    cpy_r_r312 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'final' */
    cpy_r_r313 = CPyDict_GetItem(cpy_r_r311, cpy_r_r312);
    if (unlikely(cpy_r_r313 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL187;
    }
    PyObject *cpy_r_r314[1] = {cpy_r_r310};
    cpy_r_r315 = (PyObject **)&cpy_r_r314;
    cpy_r_r316 = PyObject_Vectorcall(cpy_r_r313, cpy_r_r315, 1, 0);
    CPy_DECREF(cpy_r_r313);
    if (unlikely(cpy_r_r316 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL187;
    }
    CPy_DECREF(cpy_r_r310);
    CPyType__CacheParameters = (PyTypeObject *)cpy_r_r316;
    CPy_INCREF(CPyType__CacheParameters);
    cpy_r_r317 = CPyStatic_globals;
    cpy_r_r318 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheParameters' */
    cpy_r_r319 = PyDict_SetItem(cpy_r_r317, cpy_r_r318, cpy_r_r316);
    CPy_DECREF(cpy_r_r316);
    cpy_r_r320 = cpy_r_r319 >= 0;
    if (unlikely(!cpy_r_r320)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r321 = (PyObject *)CPyType__CacheParameters;
    cpy_r_r322 = CPyStatic_globals;
    cpy_r_r323 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Generic' */
    cpy_r_r324 = CPyDict_GetItem(cpy_r_r322, cpy_r_r323);
    if (unlikely(cpy_r_r324 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r325 = CPyStatic_globals;
    cpy_r_r326 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r327 = CPyDict_GetItem(cpy_r_r325, cpy_r_r326);
    if (unlikely(cpy_r_r327 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r328 = PyObject_GetItem(cpy_r_r324, cpy_r_r327);
    CPy_DECREF(cpy_r_r324);
    CPy_DECREF(cpy_r_r327);
    if (unlikely(cpy_r_r328 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r329 = PyTuple_Pack(1, cpy_r_r328);
    CPy_DECREF(cpy_r_r328);
    if (unlikely(cpy_r_r329 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r330 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'faster_async_lru' */
    cpy_r_r331 = (PyObject *)CPyType__CacheItem_template;
    cpy_r_r332 = CPyType_FromTemplate(cpy_r_r331, cpy_r_r329, cpy_r_r330);
    CPy_DECREF(cpy_r_r329);
    if (unlikely(cpy_r_r332 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r333 = CPyDef__CacheItem_trait_vtable_setup();
    if (unlikely(cpy_r_r333 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r334 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__mypyc_attrs__' */
    cpy_r_r335 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'task' */
    cpy_r_r336 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'later_call' */
    cpy_r_r337 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'waiters' */
    cpy_r_r338 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r339 = PyTuple_Pack(4, cpy_r_r335, cpy_r_r336, cpy_r_r337, cpy_r_r338);
    if (unlikely(cpy_r_r339 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r340 = PyObject_SetAttr(cpy_r_r332, cpy_r_r334, cpy_r_r339);
    CPy_DECREF(cpy_r_r339);
    cpy_r_r341 = cpy_r_r340 >= 0;
    if (unlikely(!cpy_r_r341)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL189;
    }
    CPyType__CacheItem = (PyTypeObject *)cpy_r_r332;
    CPy_INCREF(CPyType__CacheItem);
    cpy_r_r342 = CPyStatic_globals;
    cpy_r_r343 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_CacheItem' */
    cpy_r_r344 = PyDict_SetItem(cpy_r_r342, cpy_r_r343, cpy_r_r332);
    CPy_DECREF(cpy_r_r332);
    cpy_r_r345 = cpy_r_r344 >= 0;
    if (unlikely(!cpy_r_r345)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r346 = CPyStatic_globals;
    cpy_r_r347 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Generic' */
    cpy_r_r348 = CPyDict_GetItem(cpy_r_r346, cpy_r_r347);
    if (unlikely(cpy_r_r348 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r349 = CPyStatic_globals;
    cpy_r_r350 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r351 = CPyDict_GetItem(cpy_r_r349, cpy_r_r350);
    if (unlikely(cpy_r_r351 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL190;
    }
    cpy_r_r352 = PyObject_GetItem(cpy_r_r348, cpy_r_r351);
    CPy_DECREF(cpy_r_r348);
    CPy_DECREF(cpy_r_r351);
    if (unlikely(cpy_r_r352 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r353 = PyTuple_Pack(1, cpy_r_r352);
    CPy_DECREF(cpy_r_r352);
    if (unlikely(cpy_r_r353 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r354 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'faster_async_lru' */
    cpy_r_r355 = (PyObject *)CPyType__LRUCacheWrapper_template;
    cpy_r_r356 = CPyType_FromTemplate(cpy_r_r355, cpy_r_r353, cpy_r_r354);
    CPy_DECREF(cpy_r_r353);
    if (unlikely(cpy_r_r356 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r357 = CPyDef__LRUCacheWrapper_trait_vtable_setup();
    if (unlikely(cpy_r_r357 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL191;
    }
    cpy_r_r358 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__mypyc_attrs__' */
    cpy_r_r359 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r360 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__name__' */
    cpy_r_r361 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__qualname__' */
    cpy_r_r362 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r363 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r364 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapped__' */
    cpy_r_r365 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__maxsize' */
    cpy_r_r366 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__typed' */
    cpy_r_r367 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__ttl' */
    cpy_r_r368 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__cache' */
    cpy_r_r369 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__closed' */
    cpy_r_r370 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__hits' */
    cpy_r_r371 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__misses' */
    cpy_r_r372 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_is_coroutine' */
    cpy_r_r373 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r374 = PyTuple_Pack(15, cpy_r_r359, cpy_r_r360, cpy_r_r361, cpy_r_r362, cpy_r_r363, cpy_r_r364, cpy_r_r365, cpy_r_r366, cpy_r_r367, cpy_r_r368, cpy_r_r369, cpy_r_r370, cpy_r_r371, cpy_r_r372, cpy_r_r373);
    if (unlikely(cpy_r_r374 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL191;
    }
    cpy_r_r375 = PyObject_SetAttr(cpy_r_r356, cpy_r_r358, cpy_r_r374);
    CPy_DECREF(cpy_r_r374);
    cpy_r_r376 = cpy_r_r375 >= 0;
    if (unlikely(!cpy_r_r376)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL191;
    }
    CPyType__LRUCacheWrapper = (PyTypeObject *)cpy_r_r356;
    CPy_INCREF(CPyType__LRUCacheWrapper);
    cpy_r_r377 = CPyStatic_globals;
    cpy_r_r378 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_LRUCacheWrapper' */
    cpy_r_r379 = PyDict_SetItem(cpy_r_r377, cpy_r_r378, cpy_r_r356);
    CPy_DECREF(cpy_r_r356);
    cpy_r_r380 = cpy_r_r379 >= 0;
    if (unlikely(!cpy_r_r380)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r381 = CPyStatic_globals;
    cpy_r_r382 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'Generic' */
    cpy_r_r383 = CPyDict_GetItem(cpy_r_r381, cpy_r_r382);
    if (unlikely(cpy_r_r383 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r384 = CPyStatic_globals;
    cpy_r_r385 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_R' */
    cpy_r_r386 = CPyDict_GetItem(cpy_r_r384, cpy_r_r385);
    if (unlikely(cpy_r_r386 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL192;
    }
    cpy_r_r387 = CPyStatic_globals;
    cpy_r_r388 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_T' */
    cpy_r_r389 = CPyDict_GetItem(cpy_r_r387, cpy_r_r388);
    if (unlikely(cpy_r_r389 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL193;
    }
    cpy_r_r390.f0 = cpy_r_r386;
    cpy_r_r390.f1 = cpy_r_r389;
    cpy_r_r391 = PyTuple_New(2);
    if (unlikely(cpy_r_r391 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp67 = cpy_r_r390.f0;
    PyTuple_SET_ITEM(cpy_r_r391, 0, __tmp67);
    PyObject *__tmp68 = cpy_r_r390.f1;
    PyTuple_SET_ITEM(cpy_r_r391, 1, __tmp68);
    cpy_r_r392 = PyObject_GetItem(cpy_r_r383, cpy_r_r391);
    CPy_DECREF(cpy_r_r383);
    CPy_DECREF(cpy_r_r391);
    if (unlikely(cpy_r_r392 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r393 = PyTuple_Pack(1, cpy_r_r392);
    CPy_DECREF(cpy_r_r392);
    if (unlikely(cpy_r_r393 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r394 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'faster_async_lru' */
    cpy_r_r395 = (PyObject *)CPyType__LRUCacheWrapperInstanceMethod_template;
    cpy_r_r396 = CPyType_FromTemplate(cpy_r_r395, cpy_r_r393, cpy_r_r394);
    CPy_DECREF(cpy_r_r393);
    if (unlikely(cpy_r_r396 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r397 = CPyDef__LRUCacheWrapperInstanceMethod_trait_vtable_setup();
    if (unlikely(cpy_r_r397 == 2)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", -1, CPyStatic_globals);
        goto CPyL194;
    }
    cpy_r_r398 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__mypyc_attrs__' */
    cpy_r_r399 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r400 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__name__' */
    cpy_r_r401 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__qualname__' */
    cpy_r_r402 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r403 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r404 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapped__' */
    cpy_r_r405 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__instance' */
    cpy_r_r406 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__wrapper' */
    cpy_r_r407 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_is_coroutine' */
    cpy_r_r408 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__dict__' */
    cpy_r_r409 = PyTuple_Pack(10, cpy_r_r399, cpy_r_r400, cpy_r_r401, cpy_r_r402, cpy_r_r403, cpy_r_r404, cpy_r_r405, cpy_r_r406, cpy_r_r407, cpy_r_r408);
    if (unlikely(cpy_r_r409 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL194;
    }
    cpy_r_r410 = PyObject_SetAttr(cpy_r_r396, cpy_r_r398, cpy_r_r409);
    CPy_DECREF(cpy_r_r409);
    cpy_r_r411 = cpy_r_r410 >= 0;
    if (unlikely(!cpy_r_r411)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL194;
    }
    CPyType__LRUCacheWrapperInstanceMethod = (PyTypeObject *)cpy_r_r396;
    CPy_INCREF(CPyType__LRUCacheWrapperInstanceMethod);
    cpy_r_r412 = CPyStatic_globals;
    cpy_r_r413 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_LRUCacheWrapperInstanceMethod' */
    cpy_r_r414 = PyDict_SetItem(cpy_r_r412, cpy_r_r413, cpy_r_r396);
    CPy_DECREF(cpy_r_r396);
    cpy_r_r415 = cpy_r_r414 >= 0;
    if (unlikely(!cpy_r_r415)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r416 = CPyModule_builtins;
    cpy_r_r417 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'list' */
    cpy_r_r418 = CPyObject_GetAttr(cpy_r_r416, cpy_r_r417);
    if (unlikely(cpy_r_r418 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r419 = PyTuple_Pack(1, cpy_r_r418);
    CPy_DECREF(cpy_r_r418);
    if (unlikely(cpy_r_r419 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r420 = (PyObject *)&PyType_Type;
    cpy_r_r421 = CPy_CalculateMetaclass(cpy_r_r420, cpy_r_r419);
    if (unlikely(cpy_r_r421 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL195;
    }
    cpy_r_r422 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__prepare__' */
    cpy_r_r423 = PyObject_HasAttr(cpy_r_r421, cpy_r_r422);
    if (!cpy_r_r423) goto CPyL150;
    cpy_r_r424 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_HashedSeq' */
    cpy_r_r425 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__prepare__' */
    cpy_r_r426 = CPyObject_GetAttr(cpy_r_r421, cpy_r_r425);
    if (unlikely(cpy_r_r426 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL195;
    }
    PyObject *cpy_r_r427[2] = {cpy_r_r424, cpy_r_r419};
    cpy_r_r428 = (PyObject **)&cpy_r_r427;
    cpy_r_r429 = PyObject_Vectorcall(cpy_r_r426, cpy_r_r428, 2, 0);
    CPy_DECREF(cpy_r_r426);
    if (unlikely(cpy_r_r429 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL195;
    }
    if (likely(PyDict_Check(cpy_r_r429)))
        cpy_r_r430 = cpy_r_r429;
    else {
        CPy_TypeErrorTraceback("faster_async_lru/__init__.py", "<module>", 408, CPyStatic_globals, "dict", cpy_r_r429);
        goto CPyL195;
    }
    cpy_r_r431 = cpy_r_r430;
    goto CPyL152;
CPyL150: ;
    cpy_r_r432 = PyDict_New();
    if (unlikely(cpy_r_r432 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL195;
    }
    cpy_r_r431 = cpy_r_r432;
CPyL152: ;
    cpy_r_r433 = PyDict_New();
    if (unlikely(cpy_r_r433 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL196;
    }
    cpy_r_r434 = (PyObject *)&PyUnicode_Type;
    cpy_r_r435 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__slots__' */
    cpy_r_r436 = PyDict_SetItem(cpy_r_r433, cpy_r_r435, cpy_r_r434);
    cpy_r_r437 = cpy_r_r436 >= 0;
    if (unlikely(!cpy_r_r437)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r438 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'hashvalue' */
    cpy_r_r439 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__slots__' */
    cpy_r_r440 = CPyDict_SetItem(cpy_r_r431, cpy_r_r439, cpy_r_r438);
    cpy_r_r441 = cpy_r_r440 >= 0;
    if (unlikely(!cpy_r_r441)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r442 = CPyDef___init___3__HashedSeq_obj();
    if (unlikely(cpy_r_r442 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r443 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__init__' */
    cpy_r_r444 = CPyDict_SetItem(cpy_r_r431, cpy_r_r443, cpy_r_r442);
    CPy_DECREF_NO_IMM(cpy_r_r442);
    cpy_r_r445 = cpy_r_r444 >= 0;
    if (unlikely(!cpy_r_r445)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r446 = CPyDef___hash___3__HashedSeq_obj();
    if (unlikely(cpy_r_r446 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r447 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__hash__' */
    cpy_r_r448 = CPyDict_SetItem(cpy_r_r431, cpy_r_r447, cpy_r_r446);
    CPy_DECREF_NO_IMM(cpy_r_r446);
    cpy_r_r449 = cpy_r_r448 >= 0;
    if (unlikely(!cpy_r_r449)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r450 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_HashedSeq' */
    cpy_r_r451 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__annotations__' */
    cpy_r_r452 = CPyDict_SetItem(cpy_r_r431, cpy_r_r451, cpy_r_r433);
    CPy_DECREF(cpy_r_r433);
    cpy_r_r453 = cpy_r_r452 >= 0;
    if (unlikely(!cpy_r_r453)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL196;
    }
    cpy_r_r454 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'mypyc filler docstring' */
    cpy_r_r455 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__doc__' */
    cpy_r_r456 = CPyDict_SetItem(cpy_r_r431, cpy_r_r455, cpy_r_r454);
    cpy_r_r457 = cpy_r_r456 >= 0;
    if (unlikely(!cpy_r_r457)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL196;
    }
    cpy_r_r458 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'faster_async_lru' */
    cpy_r_r459 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '__module__' */
    cpy_r_r460 = CPyDict_SetItem(cpy_r_r431, cpy_r_r459, cpy_r_r458);
    cpy_r_r461 = cpy_r_r460 >= 0;
    if (unlikely(!cpy_r_r461)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL196;
    }
    PyObject *cpy_r_r462[3] = {cpy_r_r450, cpy_r_r419, cpy_r_r431};
    cpy_r_r463 = (PyObject **)&cpy_r_r462;
    cpy_r_r464 = PyObject_Vectorcall(cpy_r_r421, cpy_r_r463, 3, 0);
    if (unlikely(cpy_r_r464 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL196;
    }
    CPy_DECREF(cpy_r_r419);
    CPy_DECREF(cpy_r_r431);
    cpy_r_r465 = CPyStatic_globals;
    cpy_r_r466 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'mypyc_attr' */
    cpy_r_r467 = CPyDict_GetItem(cpy_r_r465, cpy_r_r466);
    if (unlikely(cpy_r_r467 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r468 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r469[1] = {cpy_r_r468};
    cpy_r_r470 = (PyObject **)&cpy_r_r469;
    cpy_r_r471 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* ('native_class',) */
    cpy_r_r472 = PyObject_Vectorcall(cpy_r_r467, cpy_r_r470, 0, cpy_r_r471);
    CPy_DECREF(cpy_r_r467);
    if (unlikely(cpy_r_r472 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL198;
    }
    PyObject *cpy_r_r473[1] = {cpy_r_r464};
    cpy_r_r474 = (PyObject **)&cpy_r_r473;
    cpy_r_r475 = PyObject_Vectorcall(cpy_r_r472, cpy_r_r474, 1, 0);
    CPy_DECREF(cpy_r_r472);
    if (unlikely(cpy_r_r475 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL198;
    }
    CPy_DECREF(cpy_r_r464);
    cpy_r_r476 = CPyStatic_globals;
    cpy_r_r477 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'final' */
    cpy_r_r478 = CPyDict_GetItem(cpy_r_r476, cpy_r_r477);
    if (unlikely(cpy_r_r478 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL199;
    }
    PyObject *cpy_r_r479[1] = {cpy_r_r475};
    cpy_r_r480 = (PyObject **)&cpy_r_r479;
    cpy_r_r481 = PyObject_Vectorcall(cpy_r_r478, cpy_r_r480, 1, 0);
    CPy_DECREF(cpy_r_r478);
    if (unlikely(cpy_r_r481 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL199;
    }
    CPy_DECREF(cpy_r_r475);
    CPyType__HashedSeq = (PyTypeObject *)cpy_r_r481;
    CPy_INCREF(CPyType__HashedSeq);
    cpy_r_r482 = CPyStatic_globals;
    cpy_r_r483 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_HashedSeq' */
    cpy_r_r484 = PyDict_SetItem(cpy_r_r482, cpy_r_r483, cpy_r_r481);
    CPy_DECREF(cpy_r_r481);
    cpy_r_r485 = cpy_r_r484 >= 0;
    if (unlikely(!cpy_r_r485)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r486 = (PyObject *)CPyType__HashedSeq;
    cpy_r_r487 = CPyModule_builtins;
    cpy_r_r488 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* 'object' */
    cpy_r_r489 = CPyObject_GetAttr(cpy_r_r487, cpy_r_r488);
    if (unlikely(cpy_r_r489 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r490 = PyObject_Vectorcall(cpy_r_r489, 0, 0, 0);
    CPy_DECREF(cpy_r_r489);
    if (unlikely(cpy_r_r490 == NULL)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r491.f0 = cpy_r_r490;
    CPyStatic__KW_MARK = cpy_r_r491;
    CPy_INCREF(CPyStatic__KW_MARK.f0);
    cpy_r_r492 = CPyStatic_globals;
    cpy_r_r493 = CPyStatics[DIFFCHECK_PLACEHOLDER]; /* '_KW_MARK' */
    cpy_r_r494 = PyTuple_New(1);
    if (unlikely(cpy_r_r494 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp69 = cpy_r_r491.f0;
    PyTuple_SET_ITEM(cpy_r_r494, 0, __tmp69);
    cpy_r_r495 = CPyDict_SetItem(cpy_r_r492, cpy_r_r493, cpy_r_r494);
    CPy_DECREF(cpy_r_r494);
    cpy_r_r496 = cpy_r_r495 >= 0;
    if (unlikely(!cpy_r_r496)) {
        CPy_AddTraceback("faster_async_lru/__init__.py", "<module>", DIFFCHECK_PLACEHOLDER, CPyStatic_globals);
        goto CPyL173;
    }
    return 1;
CPyL173: ;
    cpy_r_r497 = 2;
    return cpy_r_r497;
CPyL174: ;
    CPy_DecRef(cpy_r_r93);
    goto CPyL173;
CPyL175: ;
    CPy_DecRef(cpy_r_r93);
    CPy_DecRef(cpy_r_r96);
    goto CPyL173;
CPyL176: ;
    CPy_DecRef(cpy_r_r93);
    CPy_DecRef(cpy_r_r96);
    CPy_DecRef(cpy_r_r99);
    goto CPyL173;
CPyL177: ;
    CPy_DecRef(cpy_r_r112);
    goto CPyL173;
CPyL178: ;
    CPy_DecRef(cpy_r_r112);
    CPy_DecRef(cpy_r_r116);
    goto CPyL173;
CPyL179: ;
    CPy_DecRef(cpy_r_r130);
    goto CPyL173;
CPyL180: ;
    CPy_DecRef(cpy_r_r130);
    CPy_DecRef(cpy_r_r133);
    goto CPyL173;
CPyL181: ;
    CPy_DecRef(cpy_r_r178);
    goto CPyL173;
CPyL182: ;
    CPy_DecRef(cpy_r_r257);
    goto CPyL173;
CPyL183: ;
    CPy_DecRef(cpy_r_r257);
    CPy_DecRef(cpy_r_r267);
    goto CPyL173;
CPyL184: ;
    CPy_DecRef(cpy_r_r257);
    CPy_DecRef(cpy_r_r267);
    CPy_DecRef(cpy_r_r277);
    goto CPyL173;
CPyL185: ;
    CPy_DecRef(cpy_r_r257);
    CPy_DecRef(cpy_r_r267);
    CPy_DecRef(cpy_r_r277);
    CPy_DecRef(cpy_r_r279);
    goto CPyL173;
CPyL186: ;
    CPy_DecRef(cpy_r_r257);
    CPy_DecRef(cpy_r_r277);
    goto CPyL173;
CPyL187: ;
    CPy_DecRef(cpy_r_r310);
    goto CPyL173;
CPyL188: ;
    CPy_DecRef(cpy_r_r324);
    goto CPyL173;
CPyL189: ;
    CPy_DecRef(cpy_r_r332);
    goto CPyL173;
CPyL190: ;
    CPy_DecRef(cpy_r_r348);
    goto CPyL173;
CPyL191: ;
    CPy_DecRef(cpy_r_r356);
    goto CPyL173;
CPyL192: ;
    CPy_DecRef(cpy_r_r383);
    goto CPyL173;
CPyL193: ;
    CPy_DecRef(cpy_r_r383);
    CPy_DecRef(cpy_r_r386);
    goto CPyL173;
CPyL194: ;
    CPy_DecRef(cpy_r_r396);
    goto CPyL173;
CPyL195: ;
    CPy_DecRef(cpy_r_r419);
    goto CPyL173;
CPyL196: ;
    CPy_DecRef(cpy_r_r419);
    CPy_DecRef(cpy_r_r431);
    goto CPyL173;
CPyL197: ;
    CPy_DecRef(cpy_r_r419);
    CPy_DecRef(cpy_r_r431);
    CPy_DecRef(cpy_r_r433);
    goto CPyL173;
CPyL198: ;
    CPy_DecRef(cpy_r_r464);
    goto CPyL173;
CPyL199: ;
    CPy_DecRef(cpy_r_r475);
    goto CPyL173;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_faster_async_lru = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_asyncio = Py_None;
    CPyModule_functools = Py_None;
    CPyModule_inspect = Py_None;
    CPyModule_os = Py_None;
    CPyModule_sys = Py_None;
    CPyModule_collections = Py_None;
    CPyModule_collections___abc = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_mypy_extensions = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[DIFFCHECK_PLACEHOLDER];
const char * const CPyLit_Str[] = {
    "\006\006cancel\n__module__\016AttributeError\f__qualname__\a__doc__\017__annotations__",
    "\006\b__dict__\tTypeError\vOrderedDict\004done\003pop\021return_exceptions",
    "\006\rGeneratorExit\rStopIteration\n_CacheInfo\020_CacheParameters\amaxsize\005typed",
    "\006\005tasks\006closed\vmove_to_end\tcancelled\n_exception\ncall_later",
    "\005\031alru_cache is closed for \fRuntimeError\006result\v__wrapped__\vcreate_task",
    "\005\023_task_done_callback\021add_done_callback\apopitem\004last\020cache_invalidate",
    "\a\t__wrapper\004func\023iscoroutinefunction\aenviron\024ASYNC_LRU_ALLOW_SYNC\003get\000",
    "\003$Coroutine function is required, got \a{!r:{}}\006format",
    "\003\024_make_unbound_method\bcallable\034 decorating is not supported",
    "\a\023NotImplementedError\thashvalue\003map\bbuiltins\aasyncio\tfunctools\ainspect",
    "\006\002os\003sys\034faster_async_lru/__init__.py\b<module>\nnamedtuple\vcollections",
    "\a\bCallable\tCoroutine\bHashable\017collections.abc\003Any\005Final\aGeneric",
    "\b\bOptional\tTypedDict\aTypeVar\005Union\004cast\005final\boverload\006typing",
    "\006\nmypyc_attr\017mypy_extensions\fversion_info\004Self\a2.0.5.3\v__version__",
    "\a\nalru_cache\a__all__\002_T\002_R\005_Coro\003_CB\034functools.partial[_Coro[_R]]",
    "\003\"functools.partialmethod[_Coro[_R]]\004_CBP\017_PYTHON_GTE_312",
    "\006\016_PYTHON_LT_314\004hits\006misses\bcurrsize\016CancelledError\apartial",
    "\005\rpartialmethod\006gather\020get_running_loop\006shield\025markcoroutinefunction",
    "\004\n_TypedDict\016_TypedDictMeta\v__prepare__\026mypyc filler docstring",
    "\006\020faster_async_lru\017__mypyc_attrs__\004task\nlater_call\awaiters\n_CacheItem",
    "\b\b__name__\t__maxsize\a__typed\005__ttl\a__cache\b__closed\006__hits\b__misses",
    "\003\r_is_coroutine\020_LRUCacheWrapper\n__instance",
    "\005\036_LRUCacheWrapperInstanceMethod\004list\n_HashedSeq\t__slots__\b__init__",
    "\004\b__hash__\fnative_class\006object\b_KW_MARK",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\001128",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    14, 4, 19, 20, 21, 22, 1, 35, 3, 54, 54, 54, 3, 55, 55, 55, 3, 56,
    56, 56, 3, 57, 57, 57, 3, 58, 58, 58, 5, 138, 139, 140, 141, 142, 2,
    11, 61, 3, 63, 64, 65, 10, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 1,
    78, 1, 81, 1, 132
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_faster_async_lru__internal = NULL;
CPyModule *CPyModule_faster_async_lru;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_asyncio;
CPyModule *CPyModule_functools;
CPyModule *CPyModule_inspect;
CPyModule *CPyModule_os;
CPyModule *CPyModule_sys;
CPyModule *CPyModule_collections;
CPyModule *CPyModule_collections___abc;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_mypy_extensions;
char CPyStatic__PYTHON_GTE_312 = 2;
char CPyStatic__PYTHON_LT_314 = 2;
PyObject *CPyStatic_CancelledError = NULL;
PyObject *CPyStatic_partial = NULL;
PyObject *CPyStatic_partialmethod = NULL;
PyObject *CPyStatic_gather = NULL;
PyObject *CPyStatic_get_running_loop = NULL;
PyObject *CPyStatic_shield = NULL;
PyObject *CPyStatic_markcoroutinefunction = NULL;
tuple_T1O CPyStatic__KW_MARK = { NULL };
PyTypeObject *CPyType__CacheParameters;
PyTypeObject *CPyType__CacheItem;
PyObject *CPyDef__CacheItem(PyObject *cpy_r_task);
PyTypeObject *CPyType__LRUCacheWrapper;
PyObject *CPyDef__LRUCacheWrapper(PyObject *cpy_r_fn, PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl);
PyTypeObject *CPyType__LRUCacheWrapperInstanceMethod;
PyObject *CPyDef__LRUCacheWrapperInstanceMethod(PyObject *cpy_r_wrapper, PyObject *cpy_r_instance);
PyTypeObject *CPyType__HashedSeq;
PyTypeObject *CPyType_cache_close__LRUCacheWrapper_gen;
PyObject *CPyDef_cache_close__LRUCacheWrapper_gen(void);
CPyThreadLocal faster_async_lru___cache_close__LRUCacheWrapper_genObject *cache_close__LRUCacheWrapper_gen_free_instance;
PyTypeObject *CPyType__shield_and_handle_cancelled_error__LRUCacheWrapper_gen;
PyObject *CPyDef__shield_and_handle_cancelled_error__LRUCacheWrapper_gen(void);
CPyThreadLocal faster_async_lru____shield_and_handle_cancelled_error__LRUCacheWrapper_genObject *_shield_and_handle_cancelled_error__LRUCacheWrapper_gen_free_instance;
PyTypeObject *CPyType___call___3__LRUCacheWrapper_gen;
PyObject *CPyDef___call___3__LRUCacheWrapper_gen(void);
CPyThreadLocal faster_async_lru_____call___3__LRUCacheWrapper_genObject *__call___3__LRUCacheWrapper_gen_free_instance;
PyTypeObject *CPyType_cache_close__LRUCacheWrapperInstanceMethod_gen;
PyObject *CPyDef_cache_close__LRUCacheWrapperInstanceMethod_gen(void);
CPyThreadLocal faster_async_lru___cache_close__LRUCacheWrapperInstanceMethod_genObject *cache_close__LRUCacheWrapperInstanceMethod_gen_free_instance;
PyTypeObject *CPyType___call___3__LRUCacheWrapperInstanceMethod_gen;
PyObject *CPyDef___call___3__LRUCacheWrapperInstanceMethod_gen(void);
CPyThreadLocal faster_async_lru_____call___3__LRUCacheWrapperInstanceMethod_genObject *__call___3__LRUCacheWrapperInstanceMethod_gen_free_instance;
PyTypeObject *CPyType__make_wrapper_env;
PyObject *CPyDef__make_wrapper_env(void);
CPyThreadLocal faster_async_lru____make_wrapper_envObject *_make_wrapper_env_free_instance;
PyTypeObject *CPyType_wrapper__make_wrapper_obj;
PyObject *CPyDef_wrapper__make_wrapper_obj(void);
CPyThreadLocal faster_async_lru___wrapper__make_wrapper_objObject *wrapper__make_wrapper_obj_free_instance;
PyTypeObject *CPyType___init___3__HashedSeq_obj;
PyObject *CPyDef___init___3__HashedSeq_obj(void);
CPyThreadLocal faster_async_lru_____init___3__HashedSeq_objObject *__init___3__HashedSeq_obj_free_instance;
PyTypeObject *CPyType___hash___3__HashedSeq_obj;
PyObject *CPyDef___hash___3__HashedSeq_obj(void);
CPyThreadLocal faster_async_lru_____hash___3__HashedSeq_objObject *__hash___3__HashedSeq_obj_free_instance;
char CPyDef__CacheItem_____init__(PyObject *cpy_r_self, PyObject *cpy_r_task);
PyObject *CPyPy__CacheItem_____init__(PyObject *self, PyObject *args, PyObject *kw);
char CPyDef__CacheItem___cancel(PyObject *cpy_r_self);
PyObject *CPyPy__CacheItem___cancel(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__LRUCacheWrapper_____init__(PyObject *cpy_r_self, PyObject *cpy_r_fn, PyObject *cpy_r_maxsize, char cpy_r_typed, PyObject *cpy_r_ttl);
PyObject *CPyPy__LRUCacheWrapper_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef__LRUCacheWrapper_____tasks(PyObject *cpy_r_self);
PyObject *CPyPy__LRUCacheWrapper_____tasks(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
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
PyObject *CPyDef___init___3__HashedSeq_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___init___3__HashedSeq_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___init___3__HashedSeq_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_tup);
PyObject *CPyPy___init___3__HashedSeq_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___hash___3__HashedSeq_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___hash___3__HashedSeq_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
CPyTagged CPyDef___hash___3__HashedSeq_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self);
PyObject *CPyPy___hash___3__HashedSeq_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__make_key(PyObject *cpy_r_args, PyObject *cpy_r_kwds, char cpy_r_typed);
PyObject *CPyPy__make_key(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
