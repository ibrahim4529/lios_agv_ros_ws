// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from pwm_messages:msg/Pwm.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "pwm_messages/msg/detail/pwm__struct.h"
#include "pwm_messages/msg/detail/pwm__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool pwm_messages__msg__pwm__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[26];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("pwm_messages.msg._pwm.Pwm", full_classname_dest, 25) == 0);
  }
  pwm_messages__msg__Pwm * ros_message = _ros_message;
  {  // pwm1
    PyObject * field = PyObject_GetAttrString(_pymsg, "pwm1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pwm1 = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // pwm2
    PyObject * field = PyObject_GetAttrString(_pymsg, "pwm2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pwm2 = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // pwm3
    PyObject * field = PyObject_GetAttrString(_pymsg, "pwm3");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pwm3 = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // pwm4
    PyObject * field = PyObject_GetAttrString(_pymsg, "pwm4");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pwm4 = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * pwm_messages__msg__pwm__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Pwm */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("pwm_messages.msg._pwm");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Pwm");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  pwm_messages__msg__Pwm * ros_message = (pwm_messages__msg__Pwm *)raw_ros_message;
  {  // pwm1
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->pwm1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pwm1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pwm2
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->pwm2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pwm2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pwm3
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->pwm3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pwm3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pwm4
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->pwm4);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pwm4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
